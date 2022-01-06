/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbosquet <jbosquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 09:32:35 by jbosquet          #+#    #+#             */
/*   Updated: 2021/11/24 14:16:29 by jbosquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int	ft_putchar(char c);
int	ft_putstr(char *str);
int	ft_printf(const char *str, ...);
int	ft_putnbr(int nb);
int	ft_putnbr_u(unsigned int nb);
int	ft_putnbr_hex(unsigned int nb, char *hex);
int	ft_putnbr_hex_p(unsigned long long int nb, char *hex);
int	ft_printf(const char *str, ...);

#endif