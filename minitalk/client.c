/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkartasl <tkartasl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 08:11:15 by tkartasl          #+#    #+#             */
/*   Updated: 2024/01/11 15:00:58 by tkartasl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static char	*string_to_binary(char *str)
{
	char	*binary;
	int		i;
	int		pos;

	i = 0;
	pos = 7;
	binary = malloc(ft_strlen(str) * 8 + 1);
	if (binary == NULL)
		return (NULL);
	while (*str != 0)
	{
		while (pos >= 0)
		{
			if(*str & 1 << pos)
				binary[i++] = '1';
			else
				binary[i++] = '0';
			pos--;
		}
		str++;
		pos = 7;
	}
	binary[i] = 0;
	return (binary);
}

static char	*int_to_binary(char *str)
{
	int		len;
	char	bits[33];
	int		i;

	i = 0;
	len = ft_strlen(str);
	
	while (len > 0)
	{
		bits[i] = (len % 2) + '0'	
		len = len / 2;
		i++;
	}
	return (bits);
}

int	main(int argc, char *argv[])
{
	int			i;
	pid_t		pid;
	t_action	sa;
	char		*binary;
	char		*bits;
	
	if (argc != 3 || argv[2][0] == 0)
		return (0);
	binary = string_to_bits(&argv[2]);
	bits = int_to_binary(&argv[2]);
	i = ft_atoi(&argv[1]);
	pid = (pid_t)i;	
	while (binary != 0)
	{
		if (*binary == 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		binary++;	
	}
	free (binary);
	return (0);	
}

