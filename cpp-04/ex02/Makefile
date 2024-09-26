# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cdomet-d <cdomet-d@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/25 12:46:01 by cdomet-d          #+#    #+#              #
#    Updated: 2024/09/26 16:56:52 by cdomet-d         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME:= aanimal
BDIR:=.bdir/
SUB_DIR:= classes/

CC:=c++
CFLAGS:= -Werror -Wextra -Wall -Wshadow -std=c++98 -g3
CXXFLAGS:=-MMD -MP -I . -I $(SUB_DIR)
MAKEFLAGS:=--no-print-directory

SRC+= $(addprefix $(SUB_DIR), $(SUB_SRC))
SUB_SRC:=	Aanimal.cpp \
			Cat.cpp \
			Dog.cpp \

SRC+=		Brain.cpp \
			main.cpp \

OBJ:=$(addprefix $(BDIR), $(SRC:%.cpp=%.o))
DEPS:=$(OBJ:%.o=%.d)

RM:= rm -rf

all: $(NAME)
new: $(NAME) 

$(NAME): $(OBJ)
	@echo
	@printf '$(B)%.40s\n\n$(R)' "-- Making $(NAME)... ---------------------------------------------------------------------"
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
	@echo
	@printf '$(B)%.40s\n\n$(R)' "-- $(NAME) done ! ---------------------------------------------------------------------"

$(BDIR)%.o: %.cpp
	@mkdir -p $(dir $@)
	@echo "$@"
	$(CC) $(CFLAGS) $(CXXFLAGS) -o $@ -c $<

-include $(DEPS)

clean:
	@echo
	@printf '$(B)%.40s\n$(R)' "-- Cleaning... ---------------------------------------------------------------------"
	$(RM) $(BDIR)

	
fclean: clean
	$(RM) $(NAME) 
	@echo
	
re: fclean all

info:
	@echo $(CXXFLAGS)

.PHONY: all clean info fclean re

# Formatting combinations
# Text
# reset
R=\033[0m
# faint
F=\033[2m
# underlined
U=\033[4m
# bold
BO=\033[1m

# Font color
# red
RE=\033[0;31m 
# green
G=\033[0;32m
# yellow
Y=\033[0;33m
# blue
B=\033[0;34m
# magenta
M=\033[0;35m
# cyan
C=\033[0;36m
# white
W=\033[0;37m
# pink
P=\033[38;5;206m.

# Background
BG_RED=\033[41m
BG_GREEN=\033[42m
BG_YELLOW=\033[43m
BG_B=\033[44m
BG_MAGENTA=\033[45m
BG_C=\033[46m
BG_WHITE=\033[47m
