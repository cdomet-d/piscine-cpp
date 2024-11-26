# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cdomet-d <cdomet-d@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/21 17:07:25 by cdomet-d          #+#    #+#              #
#    Updated: 2024/08/21 17:23:39 by cdomet-d         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

MAKEFILE	= $(shell find . -maxdepth 3 -type f -name Makefile)
MAKEFLAGS:=--no-print-directory
SUBDIRS		= $(filter-out ./,$(dir $(MAKEFILE)))

all:
	@for dir in $(SUBDIRS); do \
		echo $$dir; \
		make -C $$dir all; \
	done

clean:
	@for dir in $(SUBDIRS); do \
		echo $$dir; \
		make -C $$dir clean; \
	done

fclean:
	@for dir in $(SUBDIRS); do \
		echo $$dir; \
		make -C $$dir fclean; \
	done