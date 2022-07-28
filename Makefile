# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jrasser <jrasser@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/17 05:26:46 by jrasser           #+#    #+#              #
#    Updated: 2022/07/21 20:27:52 by jrasser          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS 		= $(wildcard srcs/*/*.c)
SRCS_BONUS	= $(wildcard srcs_bonus/*/*.c)
OBJS		:= $(addprefix objs/, $(notdir $(SRCS:.c=.o)))
OBJS_BONUS	:= $(addprefix objs/, $(notdir $(SRCS_BONUS:.c=.o)))
OS			= ${shell uname}
LIBMLXMAC	= make -C minilibx/
NAME 		= cub3D
NAME_BONUS	= cub3D_bonus
CC			= gcc
RM			= @rm -f
CFLAGS		= -Wall -Wextra
CPPFLAGS	= -I./include/ -I./libft/
DEBEUG		= -g -fsanitize=address

objs/%.o: srcs/*/%.c
			@${CC} -o $@ -c $< ${CFLAGS} ${DEBEUG}

objs/%.o: srcs_bonus/*/%.c
			@${CC} -o $@ -c $< ${CFLAGS} ${DEBEUG}

ifeq ($(OS),Linux)
LDFLAGS			= -Lmlx_linux -lmlx_Linux -L/usr/lib -lXext -lX11 -lm -lz 
CPPFLAGS 		+= -Imlx_linux -I/usr/include -Imlx_linux
endif

ifeq ($(OS),Darwin)
LDFLAGS			= -L./minilibx -lmlx -framework OpenGL -framework AppKit -lm -lz
CPPFLAGS 		+= -Imlx_mac -I./minilibx/
endif

$(NAME): 	$(OBJS)
ifeq ($(OS),Darwin)
				$(LIBMLXMAC)
endif
			@$(MAKE) --no-print-directory -C ./libft
			@${CC} -o ${NAME} ${OBJS} -L./libft -lft $(LDFLAGS) ${DEBEUG}

$(NAME_BONUS): 	$(OBJS_BONUS)
ifeq ($(OS),Darwin)
				$(LIBMLXMAC)
endif
			@$(MAKE) --no-print-directory -C ./libft
			@${CC} -o ${NAME_BONUS} ${OBJS_BONUS} -L./libft -lft $(LDFLAGS) ${DEBEUG}

all :		${NAME}
bonus :		${NAME_BONUS}
clean :
			${RM} ${OBJS} ${OBJS_BONUS}

fclean :	clean
			${RM} ${NAME} ${NAME_BONUS}
			@make --no-print-directory fclean -C libft/

re : 		fclean all
reb :		fclean bonus
.PHONY:		all clean fclean re bonus reb
