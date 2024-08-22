# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cdomet-d <cdomet-d@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/25 12:46:01 by cdomet-d          #+#    #+#              #
#    Updated: 2024/08/22 15:02:53 by cdomet-d         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME:=fixed
BDIR:=.bdir/

CC:=c++
CFLAGS:=-Werror -Wextra -Wall -std=c++98 -g3
CPPFLAGS:=-MMD -MP
MAKEFLAGS:=--no-print-directory

SRC:=	main.cpp \

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
	$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ -c $<

-include $(DEPS)

clean:
	@echo
	@printf '$(B)%.40s\n$(R)' "-- Cleaning... ---------------------------------------------------------------------"
	$(RM) $(BDIR)
	$(RM) *.log

	
fclean: clean
	$(RM) $(NAME) 
	@$(RM) *.replace test.log
	@echo
	
re: fclean all

LOG:= test.log
test: all
	./$(NAME) elden_ring "Elden" "Baguette"
	@echo "PARAM : elden_ring "Elden" "Baguette"" > $(LOG)
	@echo "-----------------------------------" >> $(LOG)
	@cat elden_ring.replace >> $(LOG)
	./$(NAME) elden_ring "a" "aaa"
	@echo "PARAM : elden_ring "a" "aaa"" >> $(LOG)
	@echo "-----------------------------------" >> $(LOG)
	@cat elden_ring.replace >> $(LOG)
	./$(NAME) elden_ring " " ""
	@echo 'elden_ring " " ""' >> $(LOG)
	@echo "-----------------------------------" >> $(LOG)
	@cat elden_ring.replace >> $(LOG)

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
