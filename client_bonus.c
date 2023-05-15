/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaurenc <llaurenc@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 09:59:53 by llaurenc          #+#    #+#             */
/*   Updated: 2023/05/15 11:26:52 by llaurenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	msg_send(int sig)
{
	write(1, "Le signal a été envoyé avec succès\n", 38);
	(void)sig;
}

int	main(int ac, char **av)
{
	int		pid;
	char	*msg;
	int		i;

	i = 0;
	if (ac == 3)
	{
		signal(SIGUSR1, msg_send);
		if (pid_is_good(av[1]))
		{
			pid = ft_atoi(av[1]);
			msg = av[2];
			while (msg[i])
			{
				send_bits(pid, msg[i]);
				i++;
			}
			send_bits(pid, '\0');
		}
		else
			write(2, "PID INCCORECT\n", 14);
	}
	else
		write(2, "ARGS INVALID\n", 13);
	return (0);
}
