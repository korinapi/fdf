# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cpuiu <cpuiu@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/08 10:41:36 by cpuiu             #+#    #+#              #
#    Updated: 2024/01/24 20:06:40 by cpuiu            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.SILENT:
NAME	=	fdf
CC		=	CC
CFLAGS	=	-Wall -Wextra -Werror -fsanitize=address -g

SRCSDIR	=	srcs
OBJSDIR	=	objs

OK_COLOR = \x1b[32;01m

SRCS	=	$(SRCSDIR)/main.c $(SRCSDIR)/initialize.c\
			$(SRCSDIR)/axonometric_max_params.c $(SRCSDIR)/axonometric_min_params.c\
			$(SRCSDIR)/parsing.c $(SRCSDIR)/get_next_line.c\
			$(SRCSDIR)/parsing_utils.c $(SRCSDIR)/drawing.c\
			$(SRCSDIR)/b_algorythm.c\
			$(SRCSDIR)/colors.c $(SRCSDIR)/extra.c\
			$(SRCSDIR)/interface.c $(SRCSDIR)/errors.c\
			$(SRCSDIR)/obliq.c $(SRCSDIR)/obliq_parameters.c\
			$(SRCSDIR)/key_actions.c $(SRCSDIR)/new_colors.c\
			$(SRCSDIR)/mouse_actions.c $(SRCSDIR)/move_actions.c\
			$(SRCSDIR)/standard_colors.c

INCLUDES	=	mlx.h $(SRCSDIR)/fdf.h

OBJS	=	$(SRCS:$(SRCSDIR)/%.c=$(OBJSDIR)/%.o)
rm		= rm -f

all: ./$(NAME)

$(OBJS): $(OBJSDIR)/%.o : $(SRCSDIR)/%.c $(INCLUDES)
	$(CC) -c $< -o $@ $(CFLAGS)

./$(NAME):	$(OBJS)
	@make -C libft
	@$(CC) -o $@ $^ $(CFLAGS) -L libft -lft -L minilibx -lmlx -framework OpenGL -framework Appkit
	@echo "$(OK_COLOR)$(NAME) success !"

clean:
	@make clean -C libft
	@rm -f $(OBJS)

fclean : clean
	@make fclean -C libft
	@rm -f ./$(NAME)

re: fclean all

.PHONY: all clean fclean re 
