# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cdomet-d <cdomet-d@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/08 13:29:02 by cdomet-d          #+#    #+#              #
#    Updated: 2024/09/03 15:50:50 by cdomet-d         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME:= megaphone
BDIR:= .bdir/

CC := c++
CFLAGS := -Werror -Wextra -Wall -Wshadow -std=c++98
CPPFLAGS := -MMD -MP
MAKEFLAGS += --no-print-directory

SRC:= megaphone.cpp \

OBJS := $(addprefix $(BDIR), $(SRC:%.cpp=%.o))
DEPS := $(OBJS:%.o=%.d)

RM := rm -rf

all: $(NAME)

$(NAME): $(OBJS)
	@echo
	@printf '$(PB)%.40s\n\n$(R)' "-- Making $(NAME)... ---------------------------------------------------------------------"
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo
	@printf '$(PB)%.40s\n\n$(R)' "-- $(NAME) done ! ---------------------------------------------------------------------"
	
$(BDIR)%.o: %.cpp
	@mkdir -p $(dir $@)
	@echo "$@"
	@$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ -c $<

 -include $(DEPS)

clean:
	@echo
	@printf '$(PB)%.40s\n$(R)' "-- Cleaning... ---------------------------------------------------------------------"
	$(RM) $(BDIR)

	
fclean: clean
	$(RM) $(NAME)
	@echo
	
re: fclean all

help:
	@echo "make \t\t $(FAINT)creates $(NAME)$(R)"
	@echo "make clean \t $(FAINT)deletes $(BDIR)$(R)"
	@echo "make fclean \t $(FAINT)deletes $(NAME) and $(BDIR)$(R)"
	@echo "make kitty \t $(FAINT)prints a lil kitty on the terminal$(R)"
	@echo "make leaks \t $(FAINT)runs $(NAME) with $(LVPARAM) and a preset of arguments (current : $(PARAM))$(R)"
	@echo "make race \t $(FAINT)runs $(NAME) with $(RVPARAM) and a preset of arguments (current : $(PARAM))$(R)"
	@echo "make re \t $(FAINT)deletes all objects & dependencies and recompiles $(NAME)$(R)"

kitty:
	@echo "   |\__/,|   ( \  "
	@echo " _.|o o  |_   ) ) "
	@echo "-(((---(((--------"


.PHONY : clean fclean all re help run kitty leaks race

# Text
R=\033[0m
F=\033[2m
U=\033[4m
B=\033[1m

# Codes d'échappement ANSI pour les couleurs
PB=$(PINK)$(BOLD)
MB=$(MAGENTA)$(B)
CB=$(CYAN)$(B)

BGA=$(WHITE)$(BG_B)
RED=\033[0;31m
GREEN=\033[0;32m
YELLOW=\033[0;33m
BLUE=\033[0;34m
MAGENTA=\033[0;35m
CYAN=\033[0;36m
WHITE=\033[0;37m
PINK=\033[38;5;206m.

# Codes d'échappement ANSI pour le texte en gras
BOLD=\033[1m

# Codes d'échappement ANSI pour les fonds colorés
BG_RED=\033[41m
BG_GREEN=\033[42m
BG_YELLOW=\033[43m
BG_B=\033[44m
BG_MAGENTA=\033[45m
BG_C=\033[46m
BG_WHITE=\033[47m
