/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmafueni <jmafueni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 16:42:35 by jmafueni          #+#    #+#             */
/*   Updated: 2024/09/25 20:51:44 by jmafueni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <stdio.h>

int	ft_intlen(int n);
int	ft_parms(int i, char str, va_list args);
int	ft_printf(const char *str, ...);
int	ft_putchar(char c);
int	ft_puthex(unsigned long long n);
int	ft_puthex2(unsigned int n);
int	ft_putnbr(int nb);
int	ft_putptr(unsigned long long n);
int	ft_putstr(char *str);
int	ft_putunsigned(unsigned int n);

#endif
