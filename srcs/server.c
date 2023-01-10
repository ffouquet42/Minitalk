/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fllanet <fllanet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 06:32:14 by fllanet           #+#    #+#             */
/*   Updated: 2023/01/10 17:33:03 by fllanet          ###   ########.fr       */
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
		c |= bit; // c = c + bit & bit = c (additionner 2 octets)
	if (bit == 1) // si recu 8 bit
	{
		ft_stock_message(c, info->si_pid);
		c = 0;
		bit = 128;
	}
	else // divise 8 fois (128 -> 1)
		bit /= 2; // passer au bit a coter vers la droite
	kill(info->si_pid, SIGUSR2);
}

// ajoute le char a la str ?
void	ft_stock_message(char c, int client_pid)
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
	dest[i] = 0;
	str = ft_strdup(dest);
	if (!c)
	{
		str = ft_print_message(str);
		kill(client_pid, SIGUSR1);
	}
}

// affiche la str
char	*ft_print_message(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		ft_putchar(str[i]);
	ft_putchar('\n');
	free(str);
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
	data.sa_flags = SA_SIGINFO; // ?
	sigemptyset(&data.sa_mask); // ?
	sigaction(SIGUSR1, &data, NULL); // ?
	sigaction(SIGUSR2, &data, NULL); // ?
	while (1)
		pause();
}
