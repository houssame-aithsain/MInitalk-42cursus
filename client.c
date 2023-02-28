/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hait-hsa <hait-hsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 19:33:37 by hait-hsa          #+#    #+#             */
/*   Updated: 2023/01/15 14:52:40 by hait-hsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	signalesender(int pid, char c)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if (c & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		i++;
		c = c >> 1;
		usleep(450);
	}
}

int	main(int argc, char **argv)
{
	int					i;
	int					serverid;

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
