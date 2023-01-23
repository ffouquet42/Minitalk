/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fllanet <fllanet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 05:52:47 by fllanet           #+#    #+#             */
/*   Updated: 2023/01/23 15:19:18 by fllanet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <stdlib.h>
# include <signal.h>
# include <stdio.h>

typedef struct s_bits
{
	int	received_bit;
}	t_bits;

void	ft_handler(int sig, siginfo_t *info, void *ucontext);
void	ft_stock_char(char c, int client_pid);
char	*ft_print_str(char *str);
void	ft_cut_str_to_char(int pid, char *msg);
void	ft_convert_char_to_binary(int pid, char c);
void	ft_received_bit(int sig);
void	ft_received_message(int sig);
void	ft_putchar(char c);
void	ft_put_longnbr(long nb);
void	ft_putstr(char *str);
size_t	ft_strlen(const char *str);
char	*ft_strdup(char *s);
int		ft_atoi(const char *str);

#endif
