/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehelmine <ehelmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 19:08:07 by ehelmine          #+#    #+#             */
/*   Updated: 2022/01/24 19:21:54 by ehelmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_select.h"

/*
** TIOCGWINSZ
** Terminal IOCtl (stands for Input/Output Control) Get WINdow SiZe
*/

int	get_window_size(t_select *data, int when)
{
	struct winsize	window;

	if (ioctl(STDOUT_FILENO, TIOCGWINSZ, &window) != -1)
	{
		if (when > 0 && (data->window_rows != window.ws_row
				|| data->window_columns != window.ws_col))
		{
			data->window_rows = window.ws_row;
			data->window_columns = window.ws_col;
			return (-1);
		}
		data->window_rows = window.ws_row;
		data->window_columns = window.ws_col;
		return (1);
		//ft_printf("lines %i columns %i\r\n", window.ws_row, window.ws_col);
	}
	ft_printf("check rows and columns\n");
	data->window_rows = 25;
	data->window_columns = 50;
	return (1);
	// add here the window size checking with the hard way
	// kind of looping through the window with esc sequence commands
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
	data->buff_area = (char *)ft_memalloc(2048);
	data->term_cm_position = tgetstr("cm", &data->buff_area);
//	data->term_kl_left_arrow = tgetstr("kl", &data->buff_area);
//	data->term_kr_right_arrow = tgetstr("kr", &data->buff_area);
//	data->term_ku_up_arrow = tgetstr("ku", &data->buff_area);
//	data->term_kd_down_arrow = tgetstr("kd", &data->buff_area);
	data->term_cl_clear_screen = tgetstr("cl", &data->buff_area);
	data->term_us_start_uline = tgetstr("us", &data->buff_area);
	data->term_ue_stop_uline = tgetstr("ue", &data->buff_area);
	data->term_mr_video = tgetstr("mr", &data->buff_area);
	data->term_me_off_app = tgetstr("me", &data->buff_area);
//	free((void*)data->buff_area);
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

int	get_terminal_info(t_select *data)
{
	int	check;

	if (isatty(ttyslot()))
	{
		data->device_name = ttyname(ttyslot());
		if (data->device_name == NULL)
			output_error(0);
	}
	else
		output_error(0);
	data->terminal_envname = getenv("TERM");
	if (data->terminal_envname == NULL)
		output_error(1);
	check = tgetent(data->terminal_description, data->terminal_envname);
	if (check == -1)
		output_error(2);
	else if (check == 0)
		output_error(3);
	get_terminal_capabilities(data);
	return (1);
}
