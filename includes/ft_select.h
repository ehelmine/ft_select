/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehelmine <ehelmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 16:35:26 by ehelmine          #+#    #+#             */
/*   Updated: 2022/01/07 19:37:56 by ehelmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H
# include "../libft/includes/libft.h"
# include "../libft/ft_printf/includes/ft_printf.h"
# include <termios.h>
# include <sys/ioctl.h>
# include <curses.h>
# include <term.h>
# define MAX_INPUT_LEN 1024

typedef struct s_select
{
	char *terminal_dname;
	char *terminal_envname;
	int	i;
}				t_select;

void			get_terminal_info(t_select *data);

int				read_loop(int argc, char **argv, struct termios orig_t);

struct termios	enter_raw_mode(void);
void			stop_raw_mode(struct termios orig_t);

#endif
