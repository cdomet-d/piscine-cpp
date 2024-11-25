# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cdomet-d <cdomet-d@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/25 12:46:01 by cdomet-d          #+#    #+#              #
#    Updated: 2024/11/25 11:10:11 by cdomet-d         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME:= AForm
BDIR:=.bdir/
SRC_DIR:= src/
H:= headers/

CC:=c++
CFLAGS:= -Werror -Wextra -Wall -Wshadow -std=c++98 -g3
CXXFLAGS:=-MMD -MP -I $(H)
MAKEFLAGS:=--no-print-directory


SRC_PATH+= $(addprefix $(SRC_DIR), $(SRC))
SRC+=	main.cpp \
		unitTests.cpp \
		Bureaucrat.cpp \
		Intern.cpp \
		AForm.cpp \

SRC+= $(addprefix $(CCLASS), $(CCLASS_SRC))
CCLASS:=ConcreteClasses/
CCLASS_SRC:=PresidentialPardonForm.cpp \
			RobotomyRequestForm.cpp \
			ShrubberyCreationForm.cpp \



OBJ:=$(addprefix $(BDIR), $(SRC_PATH:%.cpp=%.o))

DEPS:=$(OBJ:%.o=%.d)

RM:= rm -rf

all: $(NAME)

$(NAME): $(OBJ)
	@echo
	@printf '$(MABOLD)%.40s\n\n$(R)' "-- Making $(NAME)... ---------------------------------------------------------------------"
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
	@echo
	@printf '$(MABOLD)%.40s\n\n$(R)' "-- $(NAME) done ! ---------------------------------------------------------------------"

$(BDIR)%.o: %.cpp
	@mkdir -p $(dir $@)
	@echo "$@"
	$(CC) $(CFLAGS) $(CXXFLAGS) -o $@ -c $<

-include $(DEPS)

clean:
	@echo
	@printf '$(MABOLD)%.40s\n$(R)' "-- Cleaning... ---------------------------------------------------------------------"
	$(RM) $(BDIR)

	
fclean: clean
	$(RM) $(NAME) 
	@echo
	
re: fclean all

info:
	@echo $(CXXFLAGS)
	@echo
	@echo $(SRC_PATH)
	@echo
	@echo $(SRC)

.PHONY: all clean info fclean re

# Formatting combinations
MABOLD= $(BO)$(M)

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
