/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaurenc <llaurenc@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 09:38:49 by llaurenc          #+#    #+#             */
/*   Updated: 2023/05/23 14:02:00 by llaurenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	g_g = 0;

void	check_client(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc != 3)
		exit(-1);
	while (argv[1][i])
	{
		if (argv[1][i] >= '0' && argv[1][i] <= '9')
			i++;
		else
			exit(-1);
	}
	return ;
}

void	add_global(int sig)
{
	(void)sig;
	g_g++;
}

void	send_bits(int pid, char c)
{
	int		i;

	i = 7;
	while (i >= 0)
	{
		g_g = 0;
		if ((c >> i) & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		while (g_g == 0)
			;
		usleep(100);
		i--;
	}
}

int	main(int ac, char **av)
{
	int		pid;
	char	*msg;
	int		i;

	check_client(ac, av);
	i = 0;
	pid = ft_atoi(av[1]);
	msg = av[2];
	signal(SIGUSR2, &add_global);
	while (msg[i])
	{
		send_bits(pid, msg[i]);
		i++;
	}
	send_bits(pid, '\0');
	return (0);
}
