/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmafueni <jmafueni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 18:49:57 by jmafueni          #+#    #+#             */
/*   Updated: 2024/09/30 20:55:18 by jmafueni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int g_sig = 0;

void	sig_handler_client(int signum)
{
	if (signum == SIGUSR2)
		g_sig = 1;
}

void	send_char(int pid, unsigned char c)
{
	int	bit;

	bit = 7;
	while (bit >= 0)
	{
		g_sig = 0;
		if (c & (1 << bit))
		{
			if (kill(pid, SIGUSR1) == -1)
			{
				ft_printf("Failed to send SIGUSR1 to PID %d.\n", pid);
				exit(1);
			}
		}
		else
		{
			if (kill(pid, SIGUSR2) == -1)
			{
				ft_printf("Failed to send SIGUSR2 to PID %d.\n", pid);
				exit(1);
			}
		}
		while(!g_sig)
			pause();
		bit--;
	}
}

void	send_message(int pid, const char *message)
{
	int	i;

	i = 0;
	if (message == NULL || ft_strlen(message) == 0)
	{
		ft_printf("Error: message is null or empty.\n");
		return ;
	}
	while (message[i] != '\0')
	{
		send_char(pid, message[i]);
		i++;
	}
	send_char(pid, '\0');
}

int	main(int ac, char **av)
{
	int			server_pid;
	const char	*message;

	if (ac != 3)
	{
		ft_printf("Usage: %s <server_pid> <message>\n", av[0]);
		return (EXIT_FAILURE);
	}
	server_pid = ft_atoi(av[1]);
	if (server_pid <= 0)
	{
		ft_printf("Invalid server PID.\n");
		return (EXIT_FAILURE);
	}
	// ft_printf("kmc:%s\n", av[2]);
	message = av[2];
	send_message(server_pid, message);
	return (EXIT_SUCCESS);
}
