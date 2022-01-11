/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehelmine <ehelmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 16:35:26 by ehelmine          #+#    #+#             */
/*   Updated: 2022/01/11 13:45:36 by ehelmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H
# include "../libft/ft_printf/includes/ft_printf.h"
# include <termios.h>
# include <sys/ioctl.h>
# include <curses.h>
# include <term.h>
# define MAX_INPUT_LEN 1024

typedef struct s_select
{
	char	*device_name;
	char	*terminal_envname;
	char	terminal_description[2048];
	int		term_co_width;
	int		term_li_height;
	char	buff_area[2048];
	char	*term_cm_position;
	char	*term_cr_move_begin;
	char	*term_le_move_left;
	char	*term_nd_move_right;
	char	*term_up_move_up;
	char	*term_do_move_down;
	int		term_am_wrap_begin;
	int		term_LP_wrap_safe;
	int		term_xn_wrap_weird;
	
}				t_select;

int				output_error(int i);

int				get_terminal_info(t_select *data);

int				get_terminal_capabilites(t_select *data);

int				read_loop(int argc, char **argv, struct termios orig_t);

struct termios	enter_raw_mode(void);
void			stop_raw_mode(struct termios orig_t);

#endif
