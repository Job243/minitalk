/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmafueni <jmafueni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 18:50:21 by jmafueni          #+#    #+#             */
/*   Updated: 2024/10/04 18:58:11 by jmafueni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

void	handle_signal(int sig, siginfo_t *info, void *context)
{
	static int				bit_count = 0;
	static pid_t			client_pid = 0;
	static unsigned char	c = 0;

	(void)context;
	client_pid = info->si_pid;
	c |= (sig == SIGUSR2);
	bit_count++;
	if (bit_count == 8)
	{
		if (c == '\0')
		{
			ft_putchar_fd('\n', 1);
			kill(client_pid, SIGUSR2);
		}
		else
			ft_putchar_fd(c, 1);
		bit_count = 0;
		c = 0;
	}
	else
		c <<= 1;
	kill(client_pid, SIGUSR1);
}

int	main(void)
{
	struct sigaction	s_sigaction;

	ft_memset(&s_sigaction, 0, sizeof(s_sigaction));
	ft_putstr_fd("Server PID: ", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putchar_fd('\n', 1);
	s_sigaction.sa_sigaction = handle_signal;
	s_sigaction.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &s_sigaction, 0);
	sigaction(SIGUSR2, &s_sigaction, 0);
	while (1)
		pause();
	return (0);
}
