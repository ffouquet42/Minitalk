/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fllanet <fllanet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 06:32:14 by fllanet           #+#    #+#             */
/*   Updated: 2023/01/21 15:10:44 by fllanet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

void	ft_handler(int sig, siginfo_t *info, void *ucontext) // !!!
{
	static unsigned char	c = 0;
	static unsigned char	bit = 128;
	
	(void)ucontext;
	if (sig == SIGUSR1)
		c |= bit; // c = c + bit & bit = c (additionner 2 octets) / place les 1001010
	if (bit == 1)
	{
		ft_stock_char(c, info->si_pid);
		c = 0;
		bit = 128;
	}
	else
		bit /= 2;
	kill(info->si_pid, SIGUSR2);
}

void	ft_stock_char(char c, int client_pid)
{
	static char	*str = NULL;
	char		*dest;
	int			i;

	i = 0;
	dest = malloc(sizeof(char) * (ft_strlen(str) + 2));
	if (!dest)
		return ;
	if (str)
	{
		while (str[i])
		{
			dest[i] = str[i];
			i++;
		}
		free(str);
	}
	dest[i++] = c;
	dest[i] = '\0';
	str = ft_strdup(dest);
	if (!c)
	{
		str = ft_print_str(str);
		kill(client_pid, SIGUSR1);
	}
}

char	*ft_print_str(char *str)
{
	if (str != NULL)
	{
		ft_putstr(str);
		ft_putchar('\n');
		free(str);
	}
	return (NULL);
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
	data.sa_flags = SA_SIGINFO;
	sigemptyset(&data.sa_mask);
	sigaction(SIGUSR1, &data, NULL);
	sigaction(SIGUSR2, &data, NULL);
	while (1)
		pause();
}
