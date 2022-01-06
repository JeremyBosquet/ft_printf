/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_put_hex.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbosquet <jbosquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 10:19:29 by jbosquet          #+#    #+#             */
/*   Updated: 2022/01/06 15:18:14 by jbosquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_hex(unsigned int nb, char *hex)
{
	int	size;

	size = 0;
	if (nb >= 16)
	{
		size += ft_putnbr_hex(nb / 16, hex);
	}
	size += ft_putchar(hex[nb % 16]);
	return (size);
}

int	ft_putnbr_hex_p2(unsigned long long int nb, char *hex)
{
	size_t				size;

	size = 0;
	if (nb >= 16)
	{
		size += ft_putnbr_hex_p2(nb / 16, hex);
	}
	size += ft_putchar(hex[nb % 16]);
	return (size);
}

int	ft_putnbr_hex_p(unsigned long long int nb, char *hex)
{
	size_t	size;

	size = 0;
	size += ft_putstr("0x");
	size += ft_putnbr_hex_p2(nb, hex);
	return (size);
}
