/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fllanet <fllanet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 05:52:47 by fllanet           #+#    #+#             */
/*   Updated: 2023/01/10 16:28:41 by fllanet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <stdlib.h>
# include <signal.h>
# include <stdio.h> // dev

typedef struct s_bits
{
	int	received_bit;
}	t_bits;

// server.c
void	ft_handler(int sig, siginfo_t *info, void *ucontext);
void	ft_stock_message(char c, int client_pid);
char	*ft_print_message(char *str);

// client.c
void	ft_received_bit(int sig);
void	ft_received_message(int sig);
void	ft_send_char(int pid, char c);
void	ft_send_message(int pid, char *msg);

// utils.c
void	ft_putchar(char c);
void	ft_put_longnbr(long nb);
void	ft_putstr(char *str);
int		ft_atoi(const char *str);
size_t	ft_strlen(const char *str);
char	*ft_strdup(char *s);

#endif
