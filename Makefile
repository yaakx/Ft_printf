# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jcorral- <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/20 09:24:52 by jcorral-          #+#    #+#              #
#    Updated: 2020/01/24 13:40:48 by jcorral-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		= ft_printf.c parse_flags.c write_flag.c ft_itoa_base.c print_it.c write_numbers.c

OBJS		= ${SRCS:.c=.o}

NAME		= libftprintf.a

CC			= cc

RM			= rm -f

CFLAGS		= -Wall -Werror -Wextra

.c.o:
			${CC} ${FLAGS} -c $< -o ${<:.c=.o}

$(NAME):	${OBJS}
			cd libft && ${MAKE}
			cp libft/libft.a ${NAME}
			ar rc ${NAME} ${OBJS}
			ranlib ${NAME}

all:		${NAME}

clean:
			${RM} ${OBJS} ${OBJ_BONUS}
			${MAKE} clean -C ./libft

fclean : 	clean
			${RM} ${NAME}
			${RM} libft.a
			${MAKE} fclean -C ./libft

re:			fclean all

.PHONY:		re all clean fclean
