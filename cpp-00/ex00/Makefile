# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cdomet-d <cdomet-d@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/08 13:29:02 by cdomet-d          #+#    #+#              #
#    Updated: 2024/12/12 17:37:15 by cdomet-d         ###   ########lyon.fr    #
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
	@printf '$(PB)%.30s\n\n$(R)' "-- Making $(NAME)... ---------------------------------------------------------------------"
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo
	@printf '$(PB)%.30s\n\n$(R)' "-- $(NAME) done ! ---------------------------------------------------------------------"
	
$(BDIR)%.o: %.cpp
	@mkdir -p $(dir $@)
	@echo "$@"
	@$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ -c $<

 -include $(DEPS)

clean:
	@echo
	@printf '$(PB)%.30s\n$(R)' "-- Cleaning... ---------------------------------------------------------------------"
	$(RM) $(BDIR)

	
fclean: clean
	$(RM) $(NAME)
	@echo
	
re: fclean all

.PHONY : clean fclean all re

# Formatting combinations
PIBOLD= $(BO)$(M)
BLBOLD= $(BO)$(B)
CYBOLD= $(BO)$(C)
PIBOLD= $(BO)$(P)

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