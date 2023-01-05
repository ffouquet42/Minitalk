/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fllanet <fllanet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 06:32:14 by fllanet           #+#    #+#             */
/*   Updated: 2023/01/05 11:59:51 by fllanet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h" // change for Makefile

// manage signal and informations
void	ft_handler(int sig, siginfo_t *info, void *ucontext)
{
	static unsigned char	c = 0;
	static unsigned char	bit = 128; // unsigned car max 127
	
	(void)ucontext;
	if (sig == SIGUSR1)
		c |= bit; // c = c + bit & bit = c
}

int	main(void)
{
	long				server_pid;
	struct sigaction	data;

	server_pid = (long)getpid();
	write(1, "Server PID: ", 12);
	ft_put_longnbr(server_pid);
	write(1, "\n", 1);
	data.sa_sigaction = ft_handler;
}
