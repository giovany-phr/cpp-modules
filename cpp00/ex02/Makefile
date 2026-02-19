# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gpaupher <gpaupher@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/28 19:38:13 by gpaupher          #+#    #+#              #
#    Updated: 2025/04/08 16:56:42 by gpaupher         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = account

CPP = c++

FLAGS = -Wall -Wextra -Werror -std=c++98

SRC = tests.cpp Account.cpp

OBJDIR = ./obj/

INC_DIR = ./includes/ 
INCLUDES = -I ${INC_DIR}

OBJ = ${SRC:%.cpp=${OBJDIR}%.o}

RED = \033[0;31m
GREEN = \033[0;32m
YELLOW = \033[0;33m
WHITE = \033[0m


all : ${NAME}

${NAME} : ${OBJ}
	@${CPP} ${FLAGS} ${INCLUDES} ${OBJ} -o ${NAME}
	@echo "${GREEN}>>>> Compilation success <<<<${WHITE}"
	
${OBJDIR}%.o : %.cpp
	@mkdir -p ${dir $@}
	@${CPP} ${FLAGS} ${INCLUDES} -c -o $@ $<

clean :
	@rm -rf ${OBJDIR}
	@echo "${YELLOW}>>>> Light Cleaning <<<<${WHITE}"
	
fclean : clean
	@rm -rf ${NAME}
	@echo "${RED}>>>> Deep Cleaning <<<<${WHITE}"

re : fclean all

.PHONY :
	all clean fclean re