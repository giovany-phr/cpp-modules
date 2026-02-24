# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gpaupher <gpaupher@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/28 17:18:54 by gpaupher          #+#    #+#              #
#    Updated: 2025/04/09 17:44:53 by gpaupher         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = zombie

CPP = c++

FLAGS = -Wall -Wextra -Werror -std=c++98

SRC = main.cpp Zombie.cpp newZombie.cpp randomChump.cpp

OBJDIR = ./obj/

OBJ = ${SRC:%.cpp=${OBJDIR}%.o}

RED = \033[0;31m
GREEN = \033[0;32m
YELLOW = \033[0;33m
WHITE = \033[0m


all : ${NAME}

${NAME} : ${OBJ}
	@${CPP} ${FLAGS} ${OBJ} -o ${NAME}
	@echo "${GREEN}>>>> Compilation success <<<<${WHITE}"
	
${OBJDIR}%.o : %.cpp
	@mkdir -p ${dir $@}
	@${CPP} ${FLAGS} -c -o $@ $<

clean :
	@rm -rf ${OBJDIR}
	@echo "${YELLOW}>>>> Light Cleaning <<<<${WHITE}"
	
fclean : clean
	@rm -rf ${NAME}
	@echo "${RED}>>>> Deep Cleaning <<<<${WHITE}"

re : fclean all

.PHONY :
	all clean fclean re