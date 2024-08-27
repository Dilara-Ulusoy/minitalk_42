/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakcakoc <dakcakoc@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 23:11:08 by dakcakoc          #+#    #+#             */
/*   Updated: 2024/08/27 14:44:33 by dakcakoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	signal_handler(int signum)
{
	if (signum == SIGUSR1 || signum == SIGUSR2)
	{
		receive_message(signum);
	}
	else
	{
		ft_printf("Unknown signal\n");
	}
}

void	signal_to_char(int signum, char *c, int *count)
{
	*c <<= 1;
	if (signum == SIGUSR2)
		*c |= 1;
	(*count)++;
}

void	process_message(char *c, int *count, char **message)
{
	if (*count == 8)
	{
		*message = letter_to_string(*c, *message);
		if (!*message)
			exit(1);
		if (*c == '\0')
		{
			ft_printf("Message: %s\n", *message);
			free(*message);
			*message = NULL;
		}
		*count = 0;
		*c = 0;
	}
}

void	receive_message(int signum)
{
	static int		count = 0;
	static char		c = 0;
	static char		*message = NULL;

	if (message == NULL)
	{
		message = ft_strdup("");
		if (!message)
		{
			exit(1);
		}
	}
	signal_to_char(signum, &c, &count);
	process_message(&c, &count, &message);
}

int	main(void)
{
	struct sigaction	sa;

	ft_putstr_fd("Server PID: ", 1);
	ft_putnbr(getpid());
	ft_putstr_fd("\n", 1);
	sa.sa_handler = signal_handler;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
	{
		ft_printf("Error setting up SIGUSR1 handler");
		exit(1);
	}
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
	{
		ft_printf("Error setting up SIGUSR2 handler");
		exit(1);
	}
	while (1)
	{
		pause();
	}
	return (0);
}
/*
struct sigaction {
    void (*sa_handler)(int);
	// Pointer to a signal handling function or SIG_IGN/SIG_DFL
    void (*sa_sigaction)(int, siginfo_t *, void *);
	// Pointer to a signal handling function with extra information
    sigset_t sa_mask;
	// Set of signals to be blocked during the execution of the signal handler
    int sa_flags;
	// Flags to modify the behavior of the signal
};

// Specify the signal handler function
    sa.sa_handler = signal_handler;

    // Clear the sa_mask, so no signals are blocked during handling
    sigemptyset(&sa.sa_mask);

    // No special flags
    sa.sa_flags = 0;

*/
