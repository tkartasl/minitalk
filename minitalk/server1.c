/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkartasl <tkartasl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 09:16:47 by tkartasl          #+#    #+#             */
/*   Updated: 2024/01/16 11:49:21 by tkartasl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	get_len(int len, int bit_count, int signum)
{
	static char	binary[33];
	static int 	bit;
	static char	byte;
	static int	i;

	if (signum == SIGUSR1)
		byte &= ~(128 >> bit);
	if (signum == SIGUSR2)
		byte |= (128 >> bit);
	bit++;
	if (bit > 7)
	{
		bit = 0;
		binary[i] = byte;
		byte = 0;
		i++;
	}
	if (bit_count == 31)
	{
		binary [i + 1] = 0;
		len = ft_atoi(binary);
		i = 0;
		ft_bzero(binary, 33);
	}
}

int	get_string(int len, int signum)
{
	static char	binary[5512];
	static int 	bit;
	static char	byte;
	static int	i;
;
    if (i < len)
    {
		if (signum == SIGUSR1)
			byte &= ~(128 >> bit);
		if (signum == SIGUSR2)
			byte |= (128 >> bit);
		bit++;
		if (bit > 7)
		{
			bit = 0;
			binary[i] = byte;
			byte = 0;
			i++;
		}
 	}
	if (i == len)        
	{
		binary[i] = 0;
		i = 0;
		ft_putstr_fd(binary, 1);
		ft_bzero(binary, 5512);
		return (1);
	}
	return (-1);
}

void	sig_handler(int signum)
{
	static char	lenbits[33];
	static int	bit_count;			
	static int	len;
	int			ret;
	
	ret = 0;
	if (bit_count < 32)
		get_len(len , bit_count, signum);
	else
		ret = get_string(len, signum);
	bit_count++;
	if (ret == 1)
	{
		bit_count = 0;
		len = 0;
		ft_bzero(lenbits, 33);
	}	
}

int	main()
{		
	struct sigaction	act;
	
	ft_printf("Server PID is:%d\n", getpid());
	ft_memset(&act, 0 , sizeof(struct sigaction));
	act.sa_handler = &sig_handler;
	if (sigaction(SIGUSR1, &act, NULL) < 0)
		exit (1);
	if (sigaction(SIGUSR2, &act, NULL) < 0)
		exit (1);
	while(1)
		pause();
	return (0);
}
