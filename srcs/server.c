/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fllanet <fllanet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 06:32:14 by fllanet           #+#    #+#             */
/*   Updated: 2022/12/28 15:03:52 by fllanet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h" // change for Makefile

int	main(void)
{
	long				server_pid;
	struct sigaction	data; // rename 'data'

	server_pid = (long)getpid();
	write(1, "Server PID: ", 12);
	ft_put_longnbr(server_pid);
	write(1, "\n", 1);
}
