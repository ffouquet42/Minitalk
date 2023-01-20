/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fllanet <fllanet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 06:32:12 by fllanet           #+#    #+#             */
/*   Updated: 2023/01/20 10:19:46 by fllanet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

t_bits	g_bits;

void	ft_received_bit(int signum)
{
	if (signum == SIGUSR2)
		g_bits.received_bit = 1;
}

void	ft_received_message(int signum)
{
	if (signum == SIGUSR1)
	{
		ft_putstr("Message received\n");
		exit(0);
	}
}

void	ft_convert_char_to_binary(int pid, char c)
{
	int	shift;
	int	i;

	shift = 7;
	i = 0;
	while (i <= 7)
	{
		if ((c >> shift) & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		sleep(1);
		while (g_bits.received_bit == 0)
		{
			pause();
			g_bits.received_bit = 0;
		}
		shift--;
		i++;
	}
}

void	ft_cut_str_to_char(int pid, char *str)
{
	size_t	i;
	size_t	str_length;

	i = 0;
	str_length = ft_strlen(str);
	while (i <= str_length)
	{
		ft_convert_char_to_binary(pid, str[i]);
		i++;
	}
}

int	main(int argc, char **argv)
{
	g_bits.received_bit = 0;
	signal(SIGUSR1, ft_received_message);
	signal(SIGUSR2, ft_received_bit);
	if (argc == 3 && (ft_atoi(argv[1]) > 0))
		ft_cut_str_to_char(ft_atoi(argv[1]), argv[2]);
	else
		ft_putstr("2 valid arguments required\n");
	return (0);
}
