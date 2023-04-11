/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hait-hsa <hait-hsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 19:33:37 by hait-hsa          #+#    #+#             */
/*   Updated: 2023/01/15 14:52:50 by hait-hsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

int switcher = 1;

void sighandler()
{
	switcher = 0;
}

void handler()
{
	write(1, "\nYOUR MESSAGE HAS BEEN SUCCESSFULLY RECEIVED!\n", 46);
}

void signalesender(int pid, char c)
{
	int i;

	i = 0;
	while (i < 8)
	{
		if (c & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		i++;
		c = c >> 1;
		while(switcher);
		switcher = 1;
	}
}

int main(int argc, char **argv)
{
	struct sigaction act1;
	struct sigaction act;
	int serverid;
	int i;

	act.sa_handler = handler;
	act1.sa_handler = sighandler;
	sigaction(SIGUSR2, &act, 0);
	sigaction(SIGUSR1, &act1, 0);
	i = 0;
	if (argc == 3)
	{
		serverid = ft_atoi(argv[1]);
		while (argv[2][i])
			signalesender(serverid, argv[2][i++]);
		signalesender(serverid, 0);
	}
	return (0);
}
