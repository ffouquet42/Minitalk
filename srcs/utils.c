/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fllanet <fllanet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 13:56:42 by fllanet           #+#    #+#             */
/*   Updated: 2023/01/12 16:51:11 by fllanet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

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

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(char *s) // a refaire
{
	int		i;
	char	*dest;

	i = -1;
	if (!s)
		return (NULL);
	dest = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!dest)
		return (NULL);
	while (s[++i])
		dest[i] = s[i];
	dest[i] = 0;
	return (free(s), dest);
}
