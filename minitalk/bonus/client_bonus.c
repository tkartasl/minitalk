/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkartasl <tkartasl@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 09:59:48 by tkartasl          #+#    #+#             */
/*   Updated: 2024/01/19 13:38:56 by tkartasl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	send_string(char *str, pid_t pid)
{
	int		pos;

	pos = 7;
	while (*str != 0)
	{
		while (pos >= 0)
		{
			if ((*str & 1 << pos) == 0)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(50);
			pos--;
		}
		str++;
		pos = 7;
	}
}

void	send_len(int len, pid_t pid)
{
	int	bit_count;

	bit_count = 0;
	while (bit_count < 32)
	{
		if (((len >> bit_count) & 1) == 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(50);
		bit_count++;
	}
}

void	sig_handler(int signum)
{
	if (signum == SIGUSR1)
	{
		write(1, "bit received by server", 22);
		write(1, "\n", 1);
	}
	if (signum == SIGUSR2)
	{
		write(1, "String received by server", 25);
		write(1, "\n", 1);
		exit (0);
	}
}

int	main(int argc, char *argv[])
{
	int					i;
	int					len;
	pid_t				pid;
	struct sigaction	act;

	if (argc != 3 || argv[2][0] == 0)
		return (0);
	len = ft_strlen(argv[2]);
	i = ft_atoi(argv[1]);
	if (i <= 0 || len > MAX_LEN)
		return (0);
	ft_memset(&act, 0, sizeof(struct sigaction));
	act.sa_handler = &sig_handler;
	act.sa_flags = SA_RESTART;
	if (sigaction(SIGUSR1, &act, NULL) < 0)
		exit (1);
	if (sigaction(SIGUSR2, &act, NULL) < 0)
		exit (1);
	pid = (pid_t)i;
	send_len(len, pid);
	send_string(argv[2], pid);
	while (1)
		pause();
	return (0);
}
