
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/22 12:57:20 by wszurkow          #+#    #+#              #
#    Updated: 2021/12/22 16:51:46 by wszurkow         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# VARIABLES ############

SHELL		= /bin/sh

NAME		:= container
FILETYPE	:= cpp

CC			:= c++
FLAGS		:= -Wall -Wextra -Werror -std=c++98
SANITIZER	:=

DIR_INC		:= ./src
DIR_SRC 	:= src
DIR_OBJ		:= obj
DIR_MLX		:= mlx

ECHO		:= printf
RM			:= /bin/rm -rf

HEADERS     := \
	${DIR_SRC}/vector.hpp \

SRCS		:= \
			   main.cpp


OBJS		= \
			  $(addprefix ${DIR_OBJ}/, ${SRCS:.cpp=.o})

# DEBUG ################

ifdef DEBUG
	FLAGS		:=
endif

ifdef VALG
	SANITIZER	:= -g3
endif

ifdef ASAN
	SANITIZER	:= -fsanitize=address -fsanitize=leak
endif

# MACROS ###############

CC_FULL		:= ${CC} ${FLAGS} ${SANITIZER} -I ${DIR_INC}

# RULES #################
all		:	${NAME}

$(DIR_OBJ)	:
	mkdir $(DIR_OBJ)

$(DIR_OBJ)/%.o	:	$(DIR_SRC)/%.cpp | ${DIR_OBJ} ${HEADERS}
	@mkdir -p $(dir $@)
	@${CC_FULL} -o $@ -c $<

$(NAME)		:	 $(OBJS)
	${CC_FULL}  $(OBJS) -o ${NAME}

clean	:
	@${RM} ${DIR_OBJ}

fclean	:	clean
	@${RM} ${NAME}

re		:	fclean all


.PHONY:\
	all fclean clean re

# COLORS ################
R				=	${ECHO} "\033[0;31m"
G				=	${ECHO} "\033[0;32m"
B				=	${ECHO} "\033[0;34m"
Y				=	${ECHO} "\033[1;33m"
BLACK			=	${ECHO} "\033[0;30m"
PURPLE			=	${ECHO} "\033[0;35m"
CYAN			=	${ECHO} "\033[0;36m"
ORANGE			=	${ECHO} "\033[0;33m"
LIGHT_GRAY		=	${ECHO} "\033[0;37m"
DARK_GRAY		=	${ECHO} "\033[1;30m"
LIGHT_RED		=	${ECHO} "\033[1;31m"
LIGHT_GREEN		=	${ECHO} "\033[1;32m"
LIGHT_BLUE		=	${ECHO} "\033[1;34m"
LIGHT_PURPLE	=	${ECHO} "\033[1;35m"
LIGHT_CYAN		=	${ECHO} "\033[1;36m"
WHITE			=	${ECHO} "\033[1;37m"
NO_COLOR		=	${ECHO} "\033[0m"
BOLD			=	${ECHO} "\e[1m"
_R				=	${ECHO} "\e[0m"

# MISC #################
#Auto update
#@printf "\033[2K\r$(BLUE)$(NAME)$(RESET)$(BLUE): $(GREEN)Compiled [√]$(RESET)\n"
# use "\r" on printf to clear current line
