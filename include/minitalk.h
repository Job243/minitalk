/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmafueni <jmafueni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 22:25:18 by jmafueni          #+#    #+#             */
/*   Updated: 2024/10/01 18:56:37 by jmafueni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "../ft_printf/ft_printf.h"
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

int		ft_atoi(const char *nptr);
int		ft_putchar_fd(char c, int fd);
int	ft_isdigit(int c);
int		is_space(char c);
size_t	ft_strlen(const char *str);
void	action(int sig);
void	ft_putstr_fd(char *str, int fd);
void	ft_putnbr_fd(int n, int fd);
void	handle_signal(int sig, siginfo_t *info, void *context);
void	mt_kill(int pid, char *str);
void	send_signal(int pid, char c, int bit_index);
void	*ft_memset(void *s, int c, size_t n);

#endif
