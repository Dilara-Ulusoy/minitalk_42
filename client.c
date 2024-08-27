/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakcakoc <dakcakoc@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 19:31:50 by dakcakoc          #+#    #+#             */
/*   Updated: 2024/08/27 14:45:50 by dakcakoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_message(char *message, int server_pid)
{
	int	i;

	i = 0;
	while (message[i] != '\0')
	{
		send_char_as_signals(server_pid, message[i]);
		i++;
	}
	send_char_as_signals(server_pid, '\0');
}

void	send_char_as_signals(int pid, char c)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		if ((c >> i) & 1)
		{
			if (kill(pid, SIGUSR2) == -1)
				signal_error();
		}
		else
		{
			if (kill(pid, SIGUSR1) == -1)
				signal_error();
		}
		usleep(100);
		i--;
	}
}

int	main(int argc, char **argv)
{
	char	*message;
	int		server_pid;

	if (argc != 3)
	{
		ft_printf("Usage: ./client [PID] [Message]\n");
		exit(1);
	}
	server_pid = ft_atoi(argv[1]);
	if (server_pid <= 0)
	{
		ft_printf("Invalid PID\n");
		exit(1);
	}
	message = argv[2];
	send_message(message, server_pid);
	return (0);
}
