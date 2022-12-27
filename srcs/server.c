/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fllanet <fllanet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 06:32:14 by fllanet           #+#    #+#             */
/*   Updated: 2022/12/27 12:08:04 by fllanet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h" // changer pour le Makefile


void	ft_get_message(int signum, siginfo_t *info, void *context)
{
	static unsigned char	c = 0;
	static unsigned char	bit = 128;

	(void)context; // the handler function doesn't make any use of the third argument.
}

int	main(void)
{
	struct sigaction	sa;
	
	sa.sa_sigaction = ft_get_message;
}