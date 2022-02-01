# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ehelmine <ehelmine@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/17 12:59:07 by ehelmine          #+#    #+#              #
#    Updated: 2022/02/01 15:46:30 by ehelmine         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_select

SRCS = main.c raw_mode.c read.c get_info.c error.c cursor_arrow_and_tick.c \
	delete_line.c output.c print_options.c signals.c

OBJS_DIR = objs

INPUT_OBJS_DIR = input_objs

TEST_OBJS_DIR = objs/test_objs

OBJS = $(addprefix $(OBJS_DIR)/$(INPUT_OBJS_DIR)/, $(SRCS:.c=.o))

CFLAGS = -g -Wall -Wextra -Werror

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