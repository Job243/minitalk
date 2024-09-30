/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmafueni <jmafueni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 18:50:21 by jmafueni          #+#    #+#             */
/*   Updated: 2024/09/30 20:37:27 by jmafueni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

// void	handle_signal(int sig, siginfo_t *info, void *context)
// {
// 	static int				bit_count = 0;
// 	static unsigned char	character = 0;

// 	(void)context;
// 	(void)info;
// 	if (sig == SIGUSR1)
// 		character |= (1 << (7 - bit_count)); // Set the bit to 1
// 	else if (sig == SIGUSR2)
// 		character &= ~(1 << (7 - bit_count)); // Set the bit to 0
// 	bit_count++;
// 	if (bit_count == 8)
// 	{
// 		write(1, &character, 1);
// 		if (character == '\0')
// 			write(1, "\n", 1);
// 		bit_count = 0;
// 		character = 0;
// 	}
// }

// int	main(void)
// {
// 	struct sigaction	sa;

// 	// Display the server's PID
// 	ft_printf("Server PID: %d\n", getpid());

// 	// Setup the signal handler for SIGUSR1 and SIGUSR2
// 	sa.sa_sigaction = handle_signal;
// 	sa.sa_flags = SA_SIGINFO;
// 	sigemptyset(&sa.sa_mask);
// 	sigaction(SIGUSR1, &sa, NULL);
// 	sigaction(SIGUSR2, &sa, NULL);

// 	// Endless loop to keep the server running and receiving signals
// 	while (1)
// 		pause(); // Wait for signals

// 	return (0);
// }

char	*char_to_str(char const *s1, char const c)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	str = malloc(sizeof(char) * (ft_strlen(s1) + 2));
	if (!str)
	{
		ft_printf("Memory allocation failed.\n");
		exit(1);
	}
	while (s1[i])
		str[j++] = s1[i++];
	i = 0;
	str[j++] = c;
	str[j] = '\0';
	if (s1)
		free((void *)(s1));
	return (str);
}

void	handle_signal(int sig)
{
	static int	result;
	static int	bit_count = 0;
	static char	*s = NULL;

	if (!s)
		s = ft_strdup("");
	if (sig == SIGUSR1)
		result |= (1 << (7 - bit_count));
	// else if (sig == SIGUSR2)
	// 	result &= ~(1 << (7 - bit_count));
	bit_count++;
	if (bit_count == 8)
	{
		s = char_to_str(s, result);
		if (result == '\0')
		{
			ft_printf("%s\n", s);
			free(s);
			s = NULL;
		}
		bit_count = 0;
		result = 0;
	}
}

int	main(void)
{
	struct sigaction	sa;

	ft_printf("Server PID: %d\n", getpid());
	sa.sa_handler = handle_signal;
	sa.sa_flags = 0;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
