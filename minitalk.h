/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakcakoc <dakcakoc@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 22:12:46 by dakcakoc          #+#    #+#             */
/*   Updated: 2024/08/27 13:39:08 by dakcakoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"
# include "printf/ft_printf.h"

// Server
void	signal_handler(int signum);
void	signal_to_char(int signum, char *c, int *count);
void	process_message(char *c, int *count, char **message);
void	receive_message(int signum);

// Client
void	send_message(char *message, int server_pid);
void	send_char_as_signals(int pid, char c);
void	signal_error(void);

// Utils
void	ft_putnbr(int n);
void	ft_strcpy(char *dest, char *src);
char	*letter_to_string(char c, char *str);

#endif
