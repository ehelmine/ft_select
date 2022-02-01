/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehelmine <ehelmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 15:45:12 by ehelmine          #+#    #+#             */
/*   Updated: 2022/02/01 15:46:01 by ehelmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_select.h"

extern t_select	*g_plus;

void	handle_signals(int signal_num)
{
	if (signal_num == SIGTSTP)
	{
		stop_raw_mode(g_plus->d_orig_t, g_plus);
		g_plus->stop = 1;
	}
	if (signal_num == SIGCONT)
	{
		if (g_plus->stop == 1)
		{
			enter_raw_mode(g_plus);
		}
	}
}
