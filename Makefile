# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ehelmine <ehelmine@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/17 12:59:07 by ehelmine          #+#    #+#              #
#    Updated: 2022/02/10 14:32:27 by ehelmine         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_select

SRCS = ft_select.c raw_mode.c read.c get_info.c error.c signals.c output.c \
		cursor_arrow_and_tick.c delete_line.c print_options.c 

OBJS_DIR = objs

OBJS = $(addprefix $(OBJS_DIR)/, $(SRCS:.c=.o))

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS_DIR) $(OBJS)
	$(MAKE) -C libft
	@echo "Sources to objects done"
	gcc $(CFLAGS) -o $@ $(OBJS) libft/libft.a -ltermcap
	@echo "Compiling ft_select done"

$(OBJS_DIR)/%.o: %.c
	gcc $(CFLAGS) -c $< -o $@

$(OBJS_DIR):
	mkdir objs

clean:
	$(MAKE) -C libft clean
	@echo "Removing .o files"
	@rm -rf $(OBJS_DIR)

fclean: clean
	$(MAKE) -C libft fclean
	@echo "Removing .a files"
	@rm -f $(NAME)

re: fclean all