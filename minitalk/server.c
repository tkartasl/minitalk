/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkartasl <tkartasl@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 09:16:47 by tkartasl          #+#    #+#             */
/*   Updated: 2024/01/19 13:26:02 by tkartasl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	reset_program(int *len, char *str)
{
	*len = 0;
	ft_putstr_fd(str, 1);
	write(1, "\n", 1);
	ft_bzero(str, MAX_LEN + 1);
	*str = 0;
}

void	get_string(int *len, int signum)
{
	static char	str[MAX_LEN + 1];
	static int	bit;
	static char	byte;
	static int	i;

	if (i < *len)
	{
		if (signum == SIGUSR1)
			byte &= ~(128 >> bit++);
		if (signum == SIGUSR2)
			byte |= (128 >> bit++);
		if (bit > 7)
		{
			bit = 0;
			str[i++] = byte;
			byte = 0;
		}
	}
	if (i == *len)
	{
		str[i] = 0;
		i = 0;
		reset_program(len, str);
	}
}

void	get_len(int signum, int bit_count, int *len)
{
	static int	temp;

	if (signum == SIGUSR2)
		temp = temp + ft_recursive_power(2, bit_count);
	if (bit_count == 31)
	{
		*len = temp;
		temp = 0;
	}
}

void	sig_handler(int signum)
{
	static int	bit_count;			
	static int	len;

	if (len != 0)
	{
		get_string(&len, signum);
		bit_count = 0;
	}
	else
	{
		get_len(signum, bit_count, &len);
		bit_count++;
	}
}

int	main(void)
{
	struct sigaction	act;

	ft_printf("Server PID is:%d\n", getpid());
	ft_memset(&act, 0, sizeof(struct sigaction));
	act.sa_handler = &sig_handler;
	act.sa_flags = SA_RESTART;
	if (sigaction(SIGUSR1, &act, NULL) < 0)
		exit (1);
	if (sigaction(SIGUSR2, &act, NULL) < 0)
		exit (1);
	while (1)
		pause();
	return (0);
}
