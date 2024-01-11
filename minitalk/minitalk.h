/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkartasl <tkartasl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 10:39:03 by tkartasl          #+#    #+#             */
/*   Updated: 2024/01/11 12:51:40 by tkartasl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H
# include "/libft/libft.h"
# include <signal.h>
# include <sys/types.h>
 
typedef	struct s_sigaction
{
	void       (*sa_handler)(int);
	sigset_t	sa_mask;
	int			sa_flags;		
	void		(*sa_sigaction)(int, siginfo_t *, void *);	
}				t_action;


#endif