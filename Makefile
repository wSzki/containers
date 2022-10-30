
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

FT_NAME		:= containers_tests_ft
STD_NAME	:= containers_tests_std

FILETYPE	:= cpp

CC			:= c++
FLAGS		:= -Wall -Wextra -Werror -std=c++98
SANITIZER	:=

DIR_INC		:= inc
DIR_SRC 	:= src
DIR_OBJ		:= obj

ECHO		:= printf
RM			:= /bin/rm -rf

HEADERS     := \
			   ${DIR_INC}/vector.hpp \
			   ${DIR_INC}/map.hpp    \
			   ${DIR_INC}/stack.hpp  \

SRCS		:= \
			   main.cpp   \
			   vector.cpp \
			   #stack.cpp  \

DIR_OBJ_FT	:= obj_ft
DIR_OBJ_STD	:= obj_std
OBJS_FT		:= $(addprefix ${DIR_OBJ_FT}/,  ${SRCS:.cpp=.o})
OBJS_STD	:= $(addprefix ${DIR_OBJ_STD}/, ${SRCS:.cpp=.o})

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

ifdef COLOR
	COLORS      := -DCOLOR=1
endif

# MACROS ###############

CC_FULL		:= ${CC} ${FLAGS} ${SANITIZER} -I ${DIR_INC} ${COLORS}

# RULES #################
all		:	${FT_NAME} ${STD_NAME}
	@mkdir -p log

$(DIR_OBJ_FT)/%.o: $(DIR_SRC)/%.cpp
	@mkdir -p $(dir $@)
	${CC_FULL} -o $@ -c $<

$(DIR_OBJ_STD)/%.o: $(DIR_SRC)/%.cpp
	@mkdir -p $(dir $@)
	${CC_FULL} -DSTD=1 -o $@ -c $<

$(FT_NAME): $(OBJS_FT)
	${CC_FULL} $(OBJS_FT) -o $(FT_NAME)

$(STD_NAME): $(OBJS_STD)
	$(CC_FULL) $(OBJS_STD) -o $(STD_NAME)

clean	:
	${RM} ${DIR_OBJ_FT}
	${RM} ${DIR_OBJ_STD}
	${RM} log/ft.log log/std.log log/diff.log

fclean	:	clean
	${RM} ${FT_NAME}
	${RM} ${STD_NAME}
	${RM} log

re		:	fclean all

test : all
	@./containers_tests_ft  > log/ft.log
	@./containers_tests_std > log/std.log
	@-diff ./log/ft.log ./log/std.log > ./log/diff.log || exit 0
	@cat log/diff.log

time : all
	@echo "================================="
	@echo "FT TIMER :"
	@-time ./containers_tests_ft | tail --lines 1
	@echo "          "
	@echo "================================="
	@echo "STD TIMER :"
	@-time ./containers_tests_std | tail --lines 1

interactive : all
	./containers_tests_ft -i

.PHONY:\
	all fclean clean re test interactive time

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
