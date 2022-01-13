/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehelmine <ehelmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 16:35:26 by ehelmine          #+#    #+#             */
/*   Updated: 2022/01/13 17:07:16 by ehelmine         ###   ########.fr       */
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
	int		window_rows;
	int		window_columns;
	char	terminal_description[2048];
	char	*buff_area;
	char	*term_cm_position;
	char	*term_cr_move_begin;
	char	*term_le_move_left;
	char	*term_nd_move_right;
	char	*term_up_move_up;
	char	*term_do_move_down;
	int		term_am_wrap_begin;
	int		term_LP_wrap_safe;
	int		term_xn_wrap_weird;
	char	*term_dl_delete_line;
	char	*term_dc_delete_char;
	char	*term_DC_delete_nchar;
	char	*term_dm_enter_delmode;
	char	*term_ed_exit_delmode;
	char	*term_kl_left_arrow;
	char	*term_kr_right_arrow;
	char	*term_ku_up_arrow;
	char	*term_kd_down_arrow;
	char	*term_pc_padding;
	char	*term_ti_start_up;
	char	*term_te_finish;
	
}				t_select;

int				output_error(int i);

void			get_window_size(t_select *data);

int				get_terminal_info(t_select *data);

int				get_terminal_capabilities(t_select *data);

int				read_loop(int argc, char **argv, struct termios orig_t, t_select *data);

struct termios	enter_raw_mode(void);
void			stop_raw_mode(struct termios orig_t);

#endif
