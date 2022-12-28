/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fllanet <fllanet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 13:56:42 by fllanet           #+#    #+#             */
/*   Updated: 2022/12/28 14:25:28 by fllanet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h" // change for Makefile

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_put_longnbr(long nb)
{
	if (nb < 0)
	{
		nb *= -1;
		ft_putchar('-');
	}
	if (nb > 9)
	{
		ft_put_longnbr(nb / 10);
		ft_put_longnbr(nb % 10);
	}
	else
		ft_putchar(nb + 48);
}