# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ehelmine <ehelmine@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/06/09 13:01:03 by ehelmine          #+#    #+#              #
#    Updated: 2022/01/19 17:11:58 by ehelmine         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS = ft_putchar.c ft_putstr.c ft_atoi.c ft_strlen.c ft_strcmp.c ft_putnbr.c \
	ft_strdup.c ft_strcpy.c ft_strncpy.c ft_strclr.c ft_strcat.c ft_strncmp.c \
	ft_putendl.c ft_strlcat.c ft_bzero.c ft_strncat.c ft_strchr.c ft_strrchr.c \
	ft_isalpha.c ft_isdigit.c ft_isascii.c ft_isprint.c ft_strstr.c ft_strnstr.c \
	ft_tolower.c ft_toupper.c ft_isalnum.c ft_memset.c ft_memcpy.c ft_memccpy.c \
	ft_memchr.c ft_memcmp.c ft_memmove.c ft_strequ.c ft_strnequ.c ft_memalloc.c \
	ft_memdel.c ft_strnew.c ft_strdel.c ft_strtrim.c ft_strjoin.c ft_striter.c \
	ft_striteri.c ft_strsplit.c ft_strsub.c ft_strmap.c ft_strmapi.c ft_itoa.c \
	ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_lstnew.c \
	ft_lstadd.c ft_lstdelone.c ft_lstdel.c ft_lstiter.c ft_lstmap.c \
	ft_check_int_len.c ft_islower.c ft_isupper.c ft_isspace.c ft_strndup.c \
	get_next_line.c major_bit.c minor_bit.c ft_memdel_two.c ft_putarr.c ft_arrdup.c \
	ft_arrnew.c ft_strstr_after.c ft_strjoin_three.c free_arr.c \
	ft_return_char_index.c ft_strdup_before_char.c ft_strdup_before_whitespace.c \
	ft_iscntrl.c

PRINTF_SRCS = $(addprefix ft_printf/srcs/, handle_input.c check_flags_one.c check_flags_second.c \
write_c_and_ints.c help_functions.c write_signed_ints.c write_string.c \
write_p.c write_unsigned_ints.c write_zero.c convert_int.c write_float_1.c \
write_float_2.c write_float_3.c write_no_flags.c)

PRINTF_OBJS = handle_input.o check_flags_one.o check_flags_second.o \
write_c_and_ints.o help_functions.o write_signed_ints.o write_string.o \
write_p.o write_unsigned_ints.o write_zero.o convert_int.o write_float_1.o \
write_float_2.o write_float_3.o write_no_flags.o

OBJS = $(SRCS:%.c=%.o)

PRINT_H = ft_printf/includes/

LIB_H = includes/libft.h

all: $(NAME)

$(NAME): 
		@gcc -Wall -Wextra -Werror -c $(PRINTF_SRCS) -I $(PRINT_H)
		@gcc -Wall -Wextra -Werror -c $(SRCS) -I $(LIB_H)
		@ar rcs libft.a $(OBJS) $(PRINTF_OBJS)

clean:
		@rm -f $(OBJS) $(PRINTF_OBJS)

fclean: clean
		@rm -f $(NAME)

re: fclean all
