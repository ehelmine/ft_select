/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehelmine <ehelmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 16:35:26 by ehelmine          #+#    #+#             */
/*   Updated: 2022/01/20 18:59:27 by ehelmine         ###   ########.fr       */
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
	int		down;
	char	input[MAX_INPUT_LEN][MAX_INPUT_LEN];
	int		input_info[MAX_INPUT_LEN][MAX_INPUT_LEN];
	int		amount_of_input;
	int		window_rows;
	int		window_columns;
	int		cursor_x;
	int		cursor_y;
	char	*cursor_pos;
	char	terminal_description[2048];
	char	*buff_area;
	char	*term_cm_position;
	char	*term_kl_left_arrow;
	char	*term_kr_right_arrow;
	char	*term_ku_up_arrow;
	char	*term_kd_down_arrow;
	char	*term_cl_clear_screen;
	char	*term_us_start_uline;
	char	*term_ue_stop_uline;
	char	*term_mr_video;
	char	*term_me_off_app;
	int		output_len;
	char	*output;
	int		i;
}				t_select;

int				output_error(int i);

void			fill_output(t_select *data, struct termios orig_t);

int				get_window_size(t_select *data, int when);

int				get_terminal_info(t_select *data);

int				get_terminal_capabilities(t_select *data);

void			cursor_position(t_select *data);

int				read_loop(struct termios orig_t, t_select *data);

struct termios	enter_raw_mode(void);
void			stop_raw_mode(struct termios orig_t);

#endif
