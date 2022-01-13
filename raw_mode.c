/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raw_mode.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehelmine <ehelmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 11:40:48 by ehelmine          #+#    #+#             */
/*   Updated: 2022/01/13 14:02:42 by ehelmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_select.h"

void	stop_raw_mode(struct termios orig_t)
{
	tcsetattr(STDIN_FILENO, TCSAFLUSH, &orig_t);
}

struct termios	enter_raw_mode(void)
{
	struct termios	orig_t;
	struct termios	raw_t;

	tcgetattr(STDIN_FILENO, &orig_t);
	raw_t = orig_t;
	raw_t.c_iflag &= ~(ICRNL | IXON);
	raw_t.c_oflag &= ~(OPOST);
	raw_t.c_lflag &= ~(ECHO | ICANON | IEXTEN | ISIG);
	tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw_t);
	return (orig_t);
}
