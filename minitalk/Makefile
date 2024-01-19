# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tkartasl <tkartasl@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/19 09:14:40 by tkartasl          #+#    #+#              #
#    Updated: 2024/01/19 13:54:50 by tkartasl         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = client

NAME_SERVER = server

NAME_BONUS_SERVER = server_bonus

NAME_BONUS_CLIENT = client_bonus

SRCS = client.c

BONUS_SRCS_SERVER = bonus/server_bonus.c

BONUS_SRCS_CLIENT = bonus/client_bonus.c

SRCS_SERVER = server.c

LIBFT = libft/

LIBFT_A = libft/libft.a

MAKE = make

FLAGS = -Wall -Wextra -Werror -I includes

CC = cc

all: ${NAME} ${NAME_SERVER}

${NAME}: ${SRCS}
	${MAKE} all -C ${LIBFT}
	${CC} ${FLAGS} ${SRCS} ${LIBFT_A} -o ${NAME}

${NAME_SERVER}: ${SRCS_SERVER}
	${MAKE} all -C ${LIBFT}
	${CC} ${FLAGS} ${SRCS_SERVER} ${LIBFT_A} -o ${NAME_SERVER}

bonus: ${NAME_BONUS_CLIENT} ${NAME_BONUS_SERVER}

${NAME_BONUS_CLIENT}: ${BONUS_SRCS_CLIENT}
	${MAKE} all -C ${LIBFT}
	${CC} ${FLAGS} ${BONUS_SRCS_CLIENT} ${LIBFT_A} -o ${NAME_BONUS_CLIENT}

${NAME_BONUS_SERVER}: ${BONUS_SRCS_SERVER}
	${MAKE} all -C ${LIBFT}
	${CC} ${FLAGS} ${BONUS_SRCS_SERVER} ${LIBFT_A} -o ${NAME_BONUS_SERVER}

clean:
	${MAKE} clean -C ${LIBFT}

fclean: clean
	rm -f ${NAME} ${NAME_SERVER} ${NAME_BONUS_CLIENT} ${NAME_BONUS_SERVER}
	${MAKE} fclean -C ${LIBFT}

re: fclean all