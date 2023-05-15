/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaurenc <llaurenc@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 09:49:58 by llaurenc          #+#    #+#             */
/*   Updated: 2023/05/15 12:03:17 by llaurenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	get_bits_bonus(int sig, siginfo_t *info, void *oldact)
{
	static int		bit = 7;
	static int		c = 0;

	if (sig == SIGUSR1)
		c += 1 << bit;
	bit--;
	if (bit == -1)
	{
		if (c == 0)
			kill(info->si_pid, SIGUSR1);
		else
			write(1, &c, 1);
		bit = 7;
		c = 0;
	}
	(void)oldact;
}

int	main(void)
{
	struct sigaction	sig;

	sig.sa_sigaction = get_bits_bonus;
	sig.sa_flags = SA_SIGINFO;
	write(1, "Server PID : \n", 13);
	ft_putnbr(getpid());
	write(1, "\n", 1);
	while (1)
	{
		sigaction(SIGUSR1, &sig, NULL);
		sigaction(SIGUSR2, &sig, NULL);
		pause();
	}
}
