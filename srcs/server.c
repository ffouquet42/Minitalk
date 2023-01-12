/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fllanet <fllanet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 06:32:14 by fllanet           #+#    #+#             */
/*   Updated: 2023/01/12 17:29:53 by fllanet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

void	ft_handler(int sig, siginfo_t *info, void *ucontext) // !!!
{
	static unsigned char	c = 0;
	static unsigned char	bit = 128;
	
	(void)ucontext;
	if (sig == SIGUSR1)
		c |= bit; // c = c + bit & bit = c (additionner 2 octets)
	if (bit == 1) // si recu 8 bit
	{
		ft_stock_message(c, info->si_pid); // info->si_pid = client pid
		c = 0;
		bit = 128;
	}
	else // divise 8 fois (128 -> 1)
		bit /= 2; // passer au bit a coter vers la droite
	kill(info->si_pid, SIGUSR2); // ping client bit recu
}

void	ft_stock_message(char c, int client_pid) // !!!
{
	static char	*str = NULL;
	char		*dest;
	int			i;

	i = 0;
	dest = malloc(sizeof(char) * (ft_strlen(str) + 2)); // 1/2
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
	dest[i++] = c; // dest[i] = c -> i++
	dest[i] = 0; // dest[i] = '\0'
	str = ft_strdup(dest);
	if (!c) // si fin de str
	{
		str = ft_print_str(str); // print
		kill(client_pid, SIGUSR1); // kill pour signal client msg receveid
	}
}

char	*ft_print_str(char *str) // OK
{
	if (str != NULL)
	{
		ft_putstr(str);
		ft_putchar('\n');
		free(str);
	}
	return (NULL);
}

int	main(void) // !!!
{
	long				server_pid;
	struct sigaction	data;

	server_pid = (long)getpid();
	write(1, "Server PID: ", 12);
	ft_put_longnbr(server_pid);
	write(1, "\n", 1);
	data.sa_sigaction = ft_handler;
	data.sa_flags = SA_SIGINFO; // ?
	sigemptyset(&data.sa_mask); // ?
	sigaction(SIGUSR1, &data, NULL); // ?
	sigaction(SIGUSR2, &data, NULL); // ?
	while (1)
		pause();
}
