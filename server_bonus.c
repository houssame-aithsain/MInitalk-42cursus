/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hait-hsa <hait-hsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 19:33:34 by hait-hsa          #+#    #+#             */
/*   Updated: 2023/01/15 14:45:43 by hait-hsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	handler(int signal, siginfo_t *info, void *newaction)
{
	static unsigned char	c;
	static int				sigcount;
	static int				correntpid;

	if (info->si_pid != correntpid)
	{
		correntpid = info->si_pid;
		sigcount = 0;
	}
	(void)newaction;
	sigcount++;
	c >>= 1;
	if (signal == SIGUSR1)
		c = c | 128;
	if (sigcount == 8)
	{
		write(1, &c, 1);
		if (c == '\0')
			kill(info->si_pid, SIGUSR2);
		c = 0;
		sigcount = 0;
	}
	kill(correntpid, SIGUSR1);
}

int	main(void)
{
	struct sigaction	act;

	write(1, "PID: ", 5);
	ft_putnbr(getpid());
	write(1, "\n", 1);
	act.sa_sigaction = handler;
	act.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR2, &act, 0);
	sigaction(SIGUSR1, &act, 0);
	while (1)
		pause();
	return (0);
}
