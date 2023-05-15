/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaurenc <llaurenc@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 09:11:11 by llaurenc          #+#    #+#             */
/*   Updated: 2023/05/15 10:48:59 by llaurenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <signal.h>

int		pid_is_good(char *str);
int		ft_atoi(char *str);
void	ft_putnbr(int num);
void	send_bits(int pid, char c);
void	get_bits(int sig);

#endif