/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkartasl <tkartasl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 08:11:26 by tkartasl          #+#    #+#             */
/*   Updated: 2024/01/15 16:18:28 by tkartasl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void    get_string(int len, char c)
{
	static char	binary[4095];
	static int 	bit;
	static char byte;
	static int	i;

    if (i < len)
    {
		if (c == '0')
			byte &= ~(128 >> bit);
		if (c == '1')
			byte |= (128 >> bit);
		bit++;
		if (bit > 7)
		{
			bit = 0;
			binary[i++] = byte;
			byte = 0;
		}
 	}        
	if (i == len)
	{
		binary[i] = 0;
		ft_putstr_fd(binary, 1);
	}
}

/*void    get_string(int len, char *str)
{
	char	binary[512];
	int 	bit;
	char 	byte;
	int		i;

	i = 0;
	bit = 0;
	byte = 0;
    while (i < len)
    {
		if (*str == '0')
			byte &= ~(128 >> bit);
		if (*str == '1')
			byte |= (128 >> bit);
		bit++;
		if (bit > 7)
		{
			bit = 0;
			binary[i++] = byte;
			byte = 0;
		}
		str++;
 	}        
	binary[i] = 0;
	ft_putstr_fd(binary, 1);
}*/

int	ft_recursive_power(int nb, int power)
{
	int	a;

	a = nb;
	if (power < 0)
		return (0);
	if (power == 0 && nb == 0)
		return (1);
	if (power > 1)
		return (nb * ft_recursive_power(a, power - 1));
	else
		return (nb);
}

int get_len (char *binary)
{
    int     len;  
    int     bit_count;
    int     bit;

    bit_count = 31;
    len = 0;
    bit = 0;
    while (*binary != 0)
    {
        bit = *binary - '0';
        len = len + bit * ft_recursive_power(2, bit_count);
        bit = 0;
        bit_count--;
        binary++;
    }
    return (len);
}

void	sig_handler(int signum)
{
	static char	lenbits[33];
	static int	bit_count;			
	static int	len;
	//static int	i;
	//static char	string[4500];
	
	if (bit_count <= 31)
	{
		if (signum == SIGUSR1)
			lenbits[bit_count] = '0';
		if (signum == SIGUSR2)
			lenbits[bit_count] = '1';
		if (bit_count == 31)
		{
			lenbits[bit_count + 1] = 0;
			len = get_len(lenbits);
		}
		bit_count++;
	}
	if (bit_count >= 32)
	{
		if (signum == SIGUSR1)
			get_string(len, '0');
		if (signum == SIGUSR2)
			get_string(len, '1');
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