/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_put.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbosquet <jbosquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 09:58:45 by jbosquet          #+#    #+#             */
/*   Updated: 2022/01/06 15:18:11 by jbosquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (!str)
		i = ft_putstr("(null)");
	else
	{
		while (str[i])
		{
			ft_putchar(str[i]);
			i++;
		}
	}
	return (i);
}

int	ft_putnbr(int nb)
{
	unsigned int	n;
	int				size;

	size = 0;
	n = nb;
	if (nb < 0)
	{
		size += ft_putchar('-');
		n = -nb;
	}
	if (n > 9)
		size += ft_putnbr(n / 10);
	size += ft_putchar(n % 10 + '0');
	return (size);
}

int	ft_putnbr_u(unsigned int nb)
{
	int	size;

	size = 0;
	if (nb > 9)
	{
		size += ft_putnbr_u(nb / 10);
	}
	size += ft_putchar(nb % 10 + '0');
	return (size);
}
