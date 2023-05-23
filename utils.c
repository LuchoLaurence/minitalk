/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaurenc <llaurenc@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 09:45:25 by llaurenc          #+#    #+#             */
/*   Updated: 2023/05/23 13:52:34 by llaurenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	pid_is_good(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	ft_atoi(char *str)
{
	unsigned int	num;
	int				i;

	num = 0;
	i = 0;
	while (str[i])
	{
		num = ((num * 10) + (str[i] - '0'));
		i++;
	}
	return (num);
}

void	ft_putnbr(int num)
{
	char	c;

	if (num >= 10)
		ft_putnbr(num / 10);
	c = 48 + (num % 10);
	write(1, &c, 1);
}
