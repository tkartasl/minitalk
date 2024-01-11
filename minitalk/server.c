/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkartasl <tkartasl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 08:11:26 by tkartasl          #+#    #+#             */
/*   Updated: 2024/01/11 14:26:00 by tkartasl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	sig_handler(int sig, siginfo_t *info, void *context)
{
	static	char	*str;
	static	char	*binary;
	static	int		i;
	static	int		len;			

	
}

int	main()
{
	pid_t	pid;
	 
	pid = getpid();
	ft_printf("PID is:%d\n", pid);
	ft_bzero(&act, sizeof(act));
	t_action->sa_flags = SA_SIGINFO;
	t_action->sa_s_sigaction = &sig_handler;
	sigemptyset(t_action->sa_mask);
	sigaddset(t_action->sa_mask, SIGUSR1);
	sigaddset(t_action->sa_mask, SIGUSR2);
	if (sigaction(SIGUSR1, &s_sigaction, NULL) < 0)
		exit (1);
	if (sigaction(SIGUSR2, &s_sigaction, NULL) < 0)
		exit (1);
	pause();
	return (0);
}

