/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fllanet <fllanet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 05:52:47 by fllanet           #+#    #+#             */
/*   Updated: 2023/01/08 11:47:56 by fllanet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <stdlib.h>
# include <signal.h>

typedef struct s_bits
{
	int	received_bit;
}	t_bits;

// server.c
void	ft_handler(int sig, siginfo_t *info, void *ucontext);

// client.c

// utils.c
void	ft_putchar(char c);
void	ft_put_longnbr(long nb);
void	ft_putstr(char *str);
int		ft_atoi(const char *str);


// dev
# include <stdio.h>

#endif