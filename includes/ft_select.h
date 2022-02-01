/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehelmine <ehelmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 16:35:26 by ehelmine          #+#    #+#             */
/*   Updated: 2022/02/01 14:54:45 by ehelmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H
# include "../libft/ft_printf/includes/ft_printf.h"
# include <termios.h>
# include <sys/ioctl.h>
# include <curses.h>
# include <fcntl.h>
# include <term.h>
# include <signal.h>
# define MAX_INPUT_LEN 1024

typedef struct s_select
{
	int				fd_in;
	int				fd_out;
	char			*device_name;
	char			*terminal_envname;
	int				output_cols;
	char			input[MAX_INPUT_LEN][MAX_INPUT_LEN];
	int				input_info[MAX_INPUT_LEN][MAX_INPUT_LEN];
	int				amount_of_input;
	int				window_rows;
	int				window_columns;
	int				cursor_x;
	int				cursor_y;
	int				col_lengths[MAX_INPUT_LEN];
	char			*cursor_pos;
	char			terminal_description[2048];
	char			*buff_area;
	char			*term_cm_position;
	char			*term_cl_clear_screen;
	char			*term_us_start_uline;
	char			*term_ue_stop_uline;
	char			*term_mr_video;
	char			*term_me_off_app;
	int				output_len;
	char			*output;
	int				i;
	int				stop;
	struct termios	d_orig_t;
}				t_select;

void			output_error(int i);

void			enter_raw_mode(t_select *data);
void			stop_raw_mode(struct termios orig_t, t_select *data);

int				get_window_size(t_select *data, int when);
void			get_terminal_info(t_select *data);
int				get_terminal_capabilities(t_select *data);
void			check_amount_of_output_cols(t_select *data, int i, int x);
void			cursor_position(t_select *data);

int				read_loop(struct termios orig_t, t_select *data);

void			delete_option(t_select *data, struct termios orig_t);
void			move_lines_one_up(t_select *data);
void			arrow_move_or_tick_box(t_select *data, char letter);

int				f_putc(int c);
void			fill_output(t_select *data);
void			write_options(t_select *data, struct termios orig_t);

#endif
