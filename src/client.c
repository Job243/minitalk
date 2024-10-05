/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmafueni <jmafueni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 18:49:57 by jmafueni          #+#    #+#             */
/*   Updated: 2024/10/01 18:44:45 by jmafueni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

volatile sig_atomic_t	g_recu = 0;

void	message_received(int sig)
{
	if (sig == SIGUSR2)
		ft_printf("Message reçu entièrement par le serveur.\n");
}

void	action(int sig)
{
	(void)sig;
	g_recu = 1;
}

void	send_signal(int pid, char c, int bit_index)
{
	if (bit_index < 0)
		return ;
	if ((c >> bit_index) & 1)
		kill(pid, SIGUSR2);
	else
		kill(pid, SIGUSR1);
	while (!g_recu)
		;
		g_recu = 0;
	send_signal(pid, c, bit_index - 1);
}

void	mt_kill(int pid, char *str)
{
	while (*str)
		send_signal(pid, *str++, 7);
	send_signal(pid, 0, 7);
}

int	main(int argc, char **argv)
{
	if (argc != 3 || !ft_strlen(argv[2]))
		return (1);
	ft_printf("client pid %d\n", getpid());
	ft_putstr_fd("Sent    : ", 1);
	ft_putnbr_fd(ft_strlen(argv[2]), 1);
	ft_putchar_fd('\n', 1);
	ft_putstr_fd("Received: ", 1);
	signal(SIGUSR1, action);
	signal(SIGUSR2, message_received);
	mt_kill(ft_atoi(argv[1]), argv[2]);
	return (0);
}
