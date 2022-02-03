/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehelmine <ehelmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 19:08:07 by ehelmine          #+#    #+#             */
/*   Updated: 2022/02/03 16:23:57 by ehelmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_select.h"

static void	get_rest_of_col_lengths(t_select *data, int biggest_len_f, int i,
	int x)
{
	int	check;
	int	biggest_len_s;

	check = 1;
	biggest_len_s = 0;
	while (check <= data->output_cols)
	{
		check++;
		while (data->input[i][0] != '\0' && i < data->window_rows * check)
		{
			if (data->input_info[i][1] > biggest_len_s)
				biggest_len_s = data->input_info[i][1];
			i++;
		}
		data->col_lengths[x++] = biggest_len_s;
		if (4 + biggest_len_f + 3 + 4 + biggest_len_s > data->window_columns)
		{
			data->col_lengths[x - 1] = 0;
			data->output_cols--;
			return ;
		}
		else
			biggest_len_f = biggest_len_s;
	}
}

void	check_amount_of_output_cols(t_select *data, int i, int x)
{
	int	check;
	int	biggest_len_f;

	check = 1;
	while (data->amount_of_input - (data->window_rows * check) > 0)
		check++;
	data->output_cols = check;
	check = 1;
	biggest_len_f = 0;
	while (data->input[i][0] != '\0' && i < data->window_rows * check)
	{
		if (data->input_info[i][1] > biggest_len_f)
			biggest_len_f = data->input_info[i][1];
		i++;
	}
	data->col_lengths[x++] = biggest_len_f;
	get_rest_of_col_lengths(data, biggest_len_f, i, x);
}

/*
** TIOCGWINSZ
** Terminal IOCtl (stands for Input/Output Control) Get WINdow SiZe
*/

int	get_window_size(t_select *data, int when)
{
	struct winsize	window;

	if (ioctl(data->fd_out, TIOCGWINSZ, &window) != -1)
	{
		if (when > 0 && (data->window_rows != window.ws_row
				|| data->window_columns != window.ws_col))
		{
			data->window_rows = window.ws_row;
			data->window_columns = window.ws_col;
			check_amount_of_output_cols(data, 0, 0);
			return (-1);
		}
		data->window_rows = window.ws_row;
		data->window_columns = window.ws_col;
		check_amount_of_output_cols(data, 0, 0);
		return (1);
	}
	data->window_rows = 25;
	data->window_columns = 50;
	check_amount_of_output_cols(data, 0, 0);
	return (1);
}

/*
** int tgetnum (char *name);
** int tgetflag (char *name);
** char *tgetstr (char *name, char **area);
** You can provide the space. Provide for the argument area the address of
** a pointer variable of type char *. Before calling tgetstr, initialize
** the variable to point at available space. Then tgetstr will store
** the string value in that space and will increment the pointer variable
** to point after the space that has been used. You can use the same
** pointer variable for many calls to tgetstr. There is no way to determine
** how much space is needed for a single string, and no way for you to prevent
** or handle overflow of the area you have provided. However, you can be sure
** that the total size of all the string values you will obtain from
** the terminal description is no greater than the size of the description
** (unless you get the same capability twice). You can determine that size
** with strlen on the buffer you provided to tgetent. Providing the space
** yourself is the only method supported by the Unix version of termcap.
** ** ** ** ** ** ** ** ** ** ** ** ** ** **
** `cm' = String of commands to position the cursor at line l, column c. 
** Both parameters are origin-zero, and are defined relative to the screen,
** not relative to display memory. All display terminals except a few very
** obsolete ones support `cm', so it is acceptable for an application program
** to refuse to operate on terminals lacking `cm'.
** ** ** ** ** ** ** ** ** ** ** ** ** ** **
** `kl' = String of input characters sent by typing the left-arrow key.
** `kr' = String of input characters sent by typing the right-arrow key.
** `ku' = String of input characters sent by typing the up-arrow key.
** `kd' = String of input characters sent by typing the down-arrow key.
** ** ** ** ** ** ** ** ** ** ** ** ** ** **
*/

int	get_terminal_capabilities(t_select *data)
{
	ft_memdel((void *)&data->buff_area);
	data->buff_area = (char *)malloc(sizeof(char) * 2048);
	data->term_cl_clear_screen = tgetstr("cl", &data->buff_area);
	data->term_us_start_uline = tgetstr("us", &data->buff_area);
	data->term_ue_stop_uline = tgetstr("ue", &data->buff_area);
	data->term_mr_video = tgetstr("mr", &data->buff_area);
	data->term_me_off_app = tgetstr("me", &data->buff_area);
	return (1);
}

/*
** isatty function determines if the file descriptor fd refers to a
** valid terminal type device.
**
** ttyname() function gets the related device name of a file descriptor
** for which isatty() is true.
** The ttyname() function returns the name stored in a static buffer which
** will be overwritten on subsequent calls.
**
** int tgetent (char *buffer, char *termtype);
** This function finds the description and remembers it internally so that
** you can interrogate it about specific terminal capabilities
** The return value of tgetent is -1 if there is some difficulty accessing
** the data base of terminal types, 0 if the data base is accessible but
** the specified type is not defined in it, and some other value otherwise.
*/

void	get_terminal_info(t_select *data, int check)
{
	data->fd_out = 1;
	if (isatty(1) == 0)
	{
		check = open(ttyname(ttyslot()), O_WRONLY);
		if (check >= 0)
			data->fd_out = check;
	}
	data->fd_in = 0;
	if (isatty(0) == 0)
	{
		check = open(ttyname(ttyslot()), O_RDONLY);
		if (check >= 0)
			data->fd_in = check;
	}
	if (data->raw)
		return ;
	data->terminal_envname = getenv("TERM");
	if (data->terminal_envname == NULL)
		output_error(1);
	check = tgetent(data->terminal_description, data->terminal_envname);
	if (check == -1)
		output_error(2);
	else if (check == 0)
		output_error(3);
	return ;
}
