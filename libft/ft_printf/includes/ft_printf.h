/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehelmine <ehelmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 18:31:32 by ehelmine          #+#    #+#             */
/*   Updated: 2021/09/22 15:41:02 by ehelmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "../../includes/libft.h"

typedef struct s_val
{
	char			*type;
	const char		*output;
	int				plus_flag;
	int				minus_flag;
	int				space_flag;
	int				hash_flag;
	int				zero_flag;
	int				no_flags;
	int				asterisk_flag;
	int				width;
	int				minimum_width;
	int				precision;
	char			c;
	int				check;
	char			*str;
	char			*str_cpy;
	char			*new_flags;
	int				h;
	int				hh;
	int				l;
	int				ll;
	int				big_l;
	intmax_t		num;
	uintmax_t		unum;
	int				len;
	int				output_len;
	char			fill_char;
	int				real_len;
	int				i;
	int				zero_num;
	void			*vd_ptr;
	int				base;
	char			conv;
	int				big_x;
	int				zero_x;
	long double		d_num;
	signed long int	begin_i;
	intmax_t		end_i;
	char			*begin_str;
	char			*end_str;
	char			*tmp;
	int				move;
	int				negative_val;
	int				extra_zero;
	double			am_of_decimals;
	double			yy;
	int				orig_precision;
	int				ii;
	int				y;
}					t_val;

int					ft_printf(const char *begin, ...);

void				set_values(t_val *all, char *flags, char c);

int					check_width_and_precision(t_val *all, char *flags, int i);

int					check_num_type(t_val *all);

int					check_flags_percentage(t_val *all, char *flags, int i);

int					check_flags_c(t_val *all, char *flags, char c, int i);

int					check_flags_int(t_val *all, char *flags, int i, char c);

int					check_flags_p_and_s(t_val *all, char *flags, int i);

int					check_flags_float(t_val *all, char *flags, int i);

int					get_arg(t_val *all, va_list args, char c);

int					real_width(int num_len, int input_width, int precision);

char				*convert_num(t_val *all);

int					write_no_flags(t_val *all);

int					write_asterisk(t_val *all, va_list args);

void				write_c(t_val *all);

int					write_s(t_val *all);

int					write_d_and_i(t_val *all);

void				write_d_and_i_left_ad(t_val *all);

int					write_d_and_i_right_ad(t_val *all);

void				write_d_and_i_left_ad_2(t_val *all);

int					write_p(t_val *all);

int					write_unsigned(t_val *all);

void				write_zero(t_val *all);

int					write_float(t_val *all, int i, int x, int out);

int					write_float_5(t_val *all, int out);

void				write_float_7(t_val *all);

int					write_float_8(t_val *all, int x, int i);

void				write_float_8_second(t_val *all);

int					write_float_9(t_val *all);

int					write_float_output(t_val *all);

#endif
