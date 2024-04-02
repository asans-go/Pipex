# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asans-go <asans-go@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/27 15:19:28 by asans-go          #+#    #+#              #
#    Updated: 2024/04/02 18:24:20 by asans-go         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        = pipex
CC = cc
CFLAGS = -Wall -Wextra -Werror -I $(INCLUDE_PATH) -g -MMD -MF $(@:.o=.d) -fsanitize=address


SOURCES_PATH    = ./src/
OBJECTS_PATH    = ./obj/
INCLUDE_PATH    = ./inc/
LIBFT_PATH	= ./libft/
PRINTF_PATH	= $(LIBFT_PATH)printf/
FD_PRINTF_PATH = $(LIBFT_PATH)fd_printf/

LIBFT = $(LIBFT_PATH)libft.a
PRINTF = $(PRINTF_PATH)libftprintf.a
FD_PRINTF = $(FD_PRINTF_PATH)libftdprintf.a

HEADER = $(INCLUDE_PATH)/pipex.h
SOURCES =main_pipex.c errors.c check_args.c processes.c utils_pipex.c
# OBJECTS #  

OBJECTS = $(addprefix $(OBJECTS_PATH)/, ${SOURCES:.c=.o})
DEPS = $(addprefix $(OBJECTS_PATH)/, ${SOURCES:.c=.d})


# RULES
all: $(NAME)

-include $(DEPS)
$(NAME): $(OBJECTS) $(LIBFT) $(PRINTF) $(FD_PRINTF)
	$(CC) $(CFLAGS) $^ -o $(NAME)

$(OBJECTS_PATH)/%.o: $(SOURCES_PATH)/%.c $(HEADER) Makefile
		mkdir -p $(dir $@)
		$(CC) $(CFLAGS) -c $< -o $@ 

$(LIBFT) :
	make -C $(LIBFT_PATH) --no-print-directory
$(PRINTF) :
	make -C $(PRINTF_PATH) --no-print-directory

$(FD_PRINTF) :
	make -C $(FD_PRINTF_PATH) --no-print-directory

clean:
	rm -rf $(OBJECTS_PATH) 
	make clean -C $(LIBFT_PATH) 

fclean : clean
	rm -rf $(NAME)
	make fclean -C $(LIBFT_PATH) 

re: fclean all 

.PHONY: all clean fclean re
.SILENT:
