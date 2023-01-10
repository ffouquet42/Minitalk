/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fllanet <fllanet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 06:32:12 by fllanet           #+#    #+#             */
/*   Updated: 2023/01/10 17:53:43 by fllanet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h" // change for Makefile

t_bits	r_bits; // garder la valeur dans les differentes fonctions

void	ft_received_bit(int sig) // pourquoi prendre un parametre pour le void ?
{
	(void)sig;
	r_bits.received_bit = 1;
}

void	ft_received_message(int sig)
{
	if (sig == SIGUSR1)
	{
		ft_putstr("received ft_received_message\n");
		exit(0); //
	}
}

void	ft_convert_char_to_binary(int pid, char c)
{
	int	i;

	i = 1;
	while (i <= 8)
	{
		if ((c >> i) & 1) // ???
			kill(pid, SIGUSR1); // => 1
		else
			kill(pid, SIGUSR2); // => 0
		sleep(1); // pourquoi attendre 1s ?
		while (!r_bits.received_bit) // ?
		{
			pause(); // ?
			r_bits.received_bit = 0; // ?
		}
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
	r_bits.received_bit = 0;
	signal(SIGUSR1, ft_received_message); // ? envoie 2 signaux de base ? pourquoi
	signal(SIGUSR2, ft_received_bit); // ?
	if (argc == 3 && (ft_atoi(argv[1]) > 0))
		ft_cut_str_to_char(ft_atoi(argv[1]), argv[2]);
	else
		ft_putstr("Need 2 valids arguments (PID / String)");
	return (0);
}

