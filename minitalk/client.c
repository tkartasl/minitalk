/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkartasl <tkartasl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 08:11:15 by tkartasl          #+#    #+#             */
/*   Updated: 2024/01/12 16:41:33 by tkartasl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_string(char *str, pid_t pid)
{
	int		pos;

	pos = 7;
	while (*str != 0)
	{
		while (pos >= 0)
		{
			if((*str & 1 << pos) == 0)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(100);
			pos--;
		}
		str++;
		pos = 7;
	}
}

void	send_len(int len, pid_t pid)
{
	int	bit_count;
	
	bit_count = 31;
	while (bit_count >= 0)
	{
		if ((len & 1 << bit_count) == 0)
			kill(pid, SIGUSR1);	
		else
			kill(pid, SIGUSR2);
		usleep(100);
		bit_count--;
	}
}

int	main(int argc, char *argv[])
{
	int			i;
	int			len;
	pid_t		pid;
	
	if (argc != 3 || argv[2][0] == 0)
		return (0);
	len = ft_strlen(argv[2]);
	i = ft_atoi(argv[1]);
	pid = (pid_t)i;	
	send_len(len, pid);
	send_string(argv[2], pid);
	return (0);	
}
