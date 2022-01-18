# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ehelmine <ehelmine@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/17 12:59:07 by ehelmine          #+#    #+#              #
#    Updated: 2022/01/18 15:08:16 by ehelmine         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_select

SRCS = main.c raw_mode.c read.c get_terminal_info.c error.c interrogate.c \
get_window_size.c create_output.c cursor_position.c

OBJS_DIR = objs

INPUT_OBJS_DIR = input_objs

TEST_OBJS_DIR = objs/test_objs

OBJS = $(addprefix $(OBJS_DIR)/$(INPUT_OBJS_DIR)/, $(SRCS:.c=.o))

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS_DIR) $(OBJS)
	$(MAKE) -C libft
	@echo "Sources to objects done"
	gcc $(CFLAGS) -o $@ $(OBJS) libft/libft.a -ltermcap
	@echo "Compiling ft_select done"

$(OBJS_DIR)/$(INPUT_OBJS_DIR)/%.o: %.c
	gcc $(CFLAGS) -c $< -o $@

$(OBJS_DIR):
	mkdir objs
	mkdir objs/input_objs
	mkdir objs/test_objs

clean:
	$(MAKE) -C libft clean
	@echo "Removing .o files"
	@rm -rf $(OBJS_DIR)

fclean: clean
	$(MAKE) -C libft fclean
	@echo "Removing .a files"
	@rm -f $(NAME)

re: fclean all