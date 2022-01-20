/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interrogate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehelmine <ehelmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 11:58:19 by ehelmine          #+#    #+#             */
/*   Updated: 2022/01/20 18:44:02 by ehelmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_select.h"

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
**
**
** `cm' = String of commands to position the cursor at line l, column c. 
** Both parameters are origin-zero, and are defined relative to the screen,
** not relative to display memory. All display terminals except a few very
** obsolete ones support `cm', so it is acceptable for an application program
** to refuse to operate on terminals lacking `cm'.
** `cr' = String of commands to move the cursor to the beginning of the line
** it is on. If this capability is not specified, many programs assume they
** can use the ASCII carriage return character for this.
** `le' = String of commands to move the cursor left one column.
** Unless the `bw' flag capability is specified, the effect is undefined if
** the cursor is at the left margin; do not use this command there.
** If `bw' is present, this command may be used at the left margin, and
** it wraps the cursor to the last column of the preceding line.
** `nd' = String of commands to move the cursor right one column.
** The effect is undefined if the cursor is at the right margin; do not use
** this command there, not even if `am' is present.
** `up' = String of commands to move the cursor vertically up one line.
** The effect of sending this string when on the top line is undefined;
** programs should never use it that way.
** `do' = String of commands to move the cursor vertically down one line.
** The effect of sending this string when on the bottom line is undefined;
** programs should never use it that way. Some programs do use `do'
** to scroll up one line if used at the bottom line, if `sf' is not defined
** but `sr' is. This is only to compensate for certain old, incorrect
** terminal descriptions. (In principle this might actually lead to
** incorrect behavior on other terminals, but that seems to happen rarely
** if ever.) But the proper solution is that the terminal description should
** define `sf' as well as `do' if the command is suitable for scrolling.
** The original idea was that this string would not contain a newline character
** and therefore could be used without disabling the kernel's usual habit
** of converting of newline into a carriage-return newline sequence. But many
** terminal descriptions do use newline in the `do' string, so this is not
** possible; a program which sends the `do' string must disable output
** conversion in the kernel (see section Initialization for Use of Termcap).
**
**
** `am' = Flag whose presence means that writing a character in the last column
** causes the cursor to wrap to the beginning of the next line. If `am' is not
** present, writing in the last column leaves the cursor at the place where the
** character was written. Writing in the last column of the last line should
** be avoided on terminals with `am', as it may or may not cause scrolling to
** occur (see section Scrolling). Scrolling is surely not what you would intend.
** If your program needs to check the `am' flag, then it also needs to check
** the `xn' flag which indicates that wrapping happens in a strange way. Many
** common terminals have the `xn' flag.
** `xn' = Flag whose presence means that the cursor wraps in a strange way.
** At least two distinct kinds of strange behavior are known; the termcap data
** base does not contain anything to distinguish the two. On Concept-100
** terminals, output in the last column wraps the cursor almost like an ordinary
** `am' terminal. But if the next thing output is a newline, it is ignored.
** DEC VT-100 terminals (when the wrap switch is on) do a different strange
** thing: the cursor wraps only if the next thing output is another graphic
** character. In fact, the wrap occurs when the following graphic character is
** received by the terminal, before the character is placed on the screen. On
** both of these terminals, after writing in the last column a following graphic
** character will be displayed in the first column of the following line. But
** the effect of relative cursor motion characters such as newline or backspace
** at such a time depends on the terminal. The effect of erase or scrolling
** commands also depends on the terminal. You can't assume anything about what
** they will do on a terminal that has `xn'. So, to be safe, you should never
** do these things at such a time on such a terminal. To be sure of reliable
** results on a terminal which has the `xn' flag, output a `cm' absolute
** positioning command after writing in the last column. Another safe thing to
** do is to output carriage-return newline, which will leave the cursor at the
** beginning of the following line.
** `LP' = Flag whose presence means that it is safe to write in the last
** column of the last line without worrying about undesired scrolling. `LP'
** indicates the DEC flavor of `xn' strangeness.
**
** `dl' = String of commands to delete the line the cursor is on. The
** following lines move up, and a blank line appears at the bottom of the
** screen (or bottom of the scroll region). If the terminal has the `db' flag,
** a nonblank line previously pushed off the screen bottom may reappear at
** the bottom. The cursor must be at the left margin before this command is
** used. This command does not move the cursor.
**
** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** **
** Deletion of characters is less complicated; deleting one column is done by
** outputting the `dc' string. However, there may be a delete mode that must
** be entered with `dm' in order to make `dc' work.
**
** `dc' = String of commands to delete one character position at the cursor.
** If `dc' is not present, the terminal cannot delete characters.
** `DC' = String of commands to delete n characters starting at the cursor.
** It has the same effect as repeating the `dc' string n times. Any terminal
** description that has `DC' also has `dc'.
** `dm' = String of commands to enter delete mode. If not present, there is
** no delete mode, and `dc' can be used at any time (assuming there is a `dc').
** `ed' = String of commands to exit delete mode. This must be present if
** `dm' is.
**
** To delete n character positions, position the cursor and follow these steps:
**
** If the `DC' string is present, output it with parameter n and you are
** finished. Otherwise, follow the remaining steps.
** Output the `dm' string, unless you know the terminal is already in
** delete mode.
** Output the `dc' string n times.
** Output the `ed' string eventually. If the flag capability `mi' is present,
** you can move the cursor and do more deletion without leaving and
** reentering delete mode.
** As with the `IC' string, we have departed from the original termcap
** specifications by assuming that `DC' works without entering delete mode
** even though `dc' would not.
**
** If the `dm' and `im' capabilities are both present and have the same value,
** it means that the terminal has one mode for both insertion and deletion.
** It is useful for a program to know this, because then it can do insertions
** after deletions, or vice versa, without leaving insert/delete mode and
** reentering it.
**
** ** ** ** ** ** ** ** ** ** ** ** ** ** **
** `kl' = String of input characters sent by typing the left-arrow key.
** `kr' = String of input characters sent by typing the right-arrow key.
** `ku' = String of input characters sent by typing the up-arrow key.
** `kd' = String of input characters sent by typing the down-arrow key.
** ** ** ** ** ** ** ** ** ** ** ** ** ** **
** `pc' = String of commands for padding. The first character of this string
** is to be used as the pad character, instead of using null characters for
** padding. If `pc' is not provided, use null characters. Every program
** that uses termcap must look up this capability and use it to set the
** variable PC that is used by tputs. See section Padding.
**
** `ti' = String of commands to put the terminal into whatever special modes
** are needed or appropriate for programs that move the cursor nonsequentially
** around the screen. Programs that use termcap to do full-screen display
** should output this string when they start up.
** `te' = String of commands to undo what is done by the `ti' string.
** Programs that output the `ti' string on entry should output this string
** when they exit.
*/
/*
int	write_char(int c)
{
	write(1, &c, 1);
	return (1);
}*/

void	print_terminal_capabilities(void)
{

//	ft_printf("posit %s\n", data->term_cm_position);
//	ft_printf("arrow r %s\n", data->term_kr_right_arrow);
//	ft_printf("arrow u %s\n", data->term_ku_up_arrow);
//	ft_printf("arrow d %s\n", data->term_kd_down_arrow);
//	ft_printf("padding %s\n", data->term_pc_padding);
//	tputs(data->term_ti_start_up, 1, &write_char);
}

int	get_terminal_capabilities(t_select *data)
{
	data->buff_area = (char *)ft_memalloc(2048);
	data->term_cm_position = tgetstr("cm", &data->buff_area);
	data->term_kl_left_arrow = tgetstr("kl", &data->buff_area);
	data->term_kr_right_arrow = tgetstr("kr", &data->buff_area);
	data->term_ku_up_arrow = tgetstr("ku", &data->buff_area);
	data->term_kd_down_arrow = tgetstr("kd", &data->buff_area);
	data->term_cl_clear_screen = tgetstr("cl", &data->buff_area);
	data->term_us_start_uline = tgetstr("us", &data->buff_area);
	data->term_ue_stop_uline = tgetstr("ue", &data->buff_area);
	data->term_mr_video = tgetstr("mr", &data->buff_area);
	data->term_me_off_app = tgetstr("me", &data->buff_area);
	print_terminal_capabilities();
//	free((void*)data->buff_area);
	return (1);
}
