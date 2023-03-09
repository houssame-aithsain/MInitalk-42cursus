# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hait-hsa <hait-hsa@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/10 19:10:08 by hait-hsa          #+#    #+#              #
#    Updated: 2023/01/15 15:24:05 by hait-hsa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_C = client.c utils.c

SRC_S = server.c utils.c

SRC_CB = client_bonus.c utils_bonus.c

SRC_SB = server_bonus.c utils_bonus.c


OBJS_C = ${SRC_C:.c=.o}

OBJS_S = ${SRC_S:.c=.o}

OBJS_CB = ${SRC_CB:.c=.o}

OBJS_SB = ${SRC_SB:.c=.o}

CC = cc

NAME_C = client

NAME_S = server

NAME_CB = client_bonus

NAME_SB = server_bonus

CFLAGS = -Wall -Wextra -Werror

RM = rm -rf

all: server client

%.o : %.c
	${CC} ${CFLAGS} -c $< -o $@

client :
	${CC} ${CFLAGS} ${SRC_C} -o ${NAME_C}

server :
	${CC} ${CFLAGS} ${SRC_S} -o ${NAME_S}

bonus: client_bonus server_bonus

client_bonus:
	${CC} ${CFLAGS} ${SRC_CB} -o ${NAME_CB}

server_bonus:
	${CC} ${CFLAGS} ${SRC_SB} -o ${NAME_SB}

clean:	
	@${RM} ${OBJS_C} ${OBJS_S} ${OBJS_CB} ${OBJS_SB} 

fclean: clean
	@$(RM) ${NAME_C} ${NAME_S} ${NAME_CB} ${NAME_SB}

re: fclean all

.PHONY: all bonus clean fclean re