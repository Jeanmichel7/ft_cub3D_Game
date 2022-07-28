# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jrasser <jrasser@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/01 20:15:09 by jrasser           #+#    #+#              #
#    Updated: 2022/07/19 19:37:00 by jrasser          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
		ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c \
		ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c \
		ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c \
		ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c \
		ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c \
		ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
		ft_printf.c utils_ft_printf.c ft_itoa_printf.c ft_put_ptr.c \
		ft_putunbr_base.c ft_uitoa.c ft_litoa.c ft_flag_bonus.c \
		ft_flag_bonus2.c ft_arg_multi.c ft_flag_dot_bonus.c \
		get_next_line.c get_next_line_utils.c \
		ft_lstsize.c ft_lstadd_back.c ft_lstadd_front.c \
		ft_lstclear.c ft_lstdelone.c ft_lstiter.c ft_lstlast.c \
		ft_lstmap.c ft_lstnew.c

OBJS	= ${SRCS:.c=.o}

OBJS_BONUS	= ${SRCS_BONUS:.c=.o}

NAME	= libft.a

CC		= gcc

RM		= @rm -f

CFLAGS	= -Wall -Wextra -Werror -g

LDFLAGS	= -I./includes/

.c.o:		
			@${CC} ${CFLAGS} -c ${LDFLAGS} $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			@ar rc ${NAME} ${OBJS}

${BONUS}:	${OBJS_BONUS}
			ar rc ${NAME} ${OBJS_BONUS}
			
all:		${NAME}

bonus:		
			${BONUS}

clean:		
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
