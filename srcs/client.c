/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fllanet <fllanet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 06:32:12 by fllanet           #+#    #+#             */
/*   Updated: 2023/01/08 11:55:50 by fllanet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h" // change for Makefile

t_bits	r_bits; // garder la valeur dans les differentes fonctions

void	ft_received_bit(int sig)
{
	(void)sig;
	r_bits.received_bit = 1; //
}

void	ft_received_message(int sig)
{
	if (sig == SIGUSR1)
	{
		ft_putstr("received ft_received_message\n");
		exit(0); //
	}
}

int	main(int argc, char **argv)
{
	r_bits.received_bit = 0;
	signal(SIGUSR1, ft_received_message); // envoie 2 signaux de base ?
	signal(SIGUSR2, ft_received_bit);
	if (argc == 3 && (ft_atoi(argv[1]) > 0))
		ft_send_message(ft_atoi(argv[1]), argv[2]); //
	else
		ft_putstr("Incorrect number of arguments");
	return (0);
}
