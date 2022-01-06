/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbosquet <jbosquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 09:31:31 by jbosquet          #+#    #+#             */
/*   Updated: 2022/01/06 15:18:08 by jbosquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_switch(const char *str, va_list pinfos, int i)
{
	int	count;

	count = 0;
	if (str[i] && str[i] == 'c')
		count = ft_putchar((char)va_arg(pinfos, int));
	else if (str[i] && str[i] == 's')
		count = ft_putstr(va_arg(pinfos, char *));
	else if (str[i] && str[i] == 'p')
		count = ft_putnbr_hex_p(
				(unsigned long long int)va_arg(pinfos, void *),
				"0123456789abcdef");
	else if (str[i] && (str[i] == 'd' || str[i] == 'i'))
		count = ft_putnbr(va_arg(pinfos, int));
	else if (str[i] && str[i] == 'u')
		count = ft_putnbr_u(va_arg(pinfos, unsigned int));
	else if (str[i] && str[i] == 'x')
		count = ft_putnbr_hex(va_arg(pinfos, int), "0123456789abcdef");
	else if (str[i] && str[i] == 'X')
		count = ft_putnbr_hex((unsigned int)va_arg(pinfos, int),
				"0123456789ABCDEF");
	else if (str[i] && str[i] == '%')
		count = ft_putchar('%');
	return (count);
}

int	ft_printf(const char *str, ...)
{
	int			i;
	va_list		pinfos;
	size_t		size;
	size_t		result;

	size = 0;
	va_start(pinfos, str);
	i = -1;
	while ((str[++i]) != '\0')
	{
		if (str[i] == '%')
		{
			i++;
			if (!str[i])
				return (size);
			result = ft_printf_switch(str, pinfos, i);
			if (result == 0 && str[i] && str[i] != 's')
				result = ft_putchar(str[i]);
			size += result;
		}
		else if (str[i])
			size += ft_putchar(str[i]);
	}
	va_end(pinfos);
	return (size);
}
