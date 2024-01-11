/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkartasl <tkartasl@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 15:08:07 by tkartasl          #+#    #+#             */
/*   Updated: 2023/11/10 10:58:33 by tkartasl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <limits.h>

int	ft_atoi(const char *str)
{
	int		res;
	int		neg;
	long	temp;

	temp = 0;
	res = 0;
	neg = 1;
	while (*str != 0 && (*str == ' ' || *str == '\n' || *str == '\t'
			|| *str == '\v' || *str == '\f' || *str == '\r'))
		str++;
	if (*str == '-')
		neg = -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str != 0 && *str >= '0' && *str <= '9')
	{
		if (temp + (*str - 48) > (LONG_MAX / 10) && neg == -1)
			return (0);
		temp = temp * 10 + (*str - 48);
		str++;
	}
	if (temp == (LONG_MIN + 1))
		return (-1);
	res = temp;
	return (res * neg);
}
