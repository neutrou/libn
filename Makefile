# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: valgrant <valgrant@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/20 11:51:44 by valgrant          #+#    #+#              #
#    Updated: 2024/06/18 16:26:25 by valgrant         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libn.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror -g

OGS = ogs/ft_atoi.c \
	ogs/ft_bzero.c \
	ogs/ft_calloc.c \
	ogs/ft_is.c \
	ogs/ft_itoa.c \
	ogs/ft_mem.c \
	ogs/ft_len.c \
	ogs/ft_tofd.c \
	ogs/ft_split.c  \
	ogs/ft_strchr.c  \
	ogs/ft_strdup.c  \
	ogs/ft_striteri.c \
	ogs/ft_strjoin.c \
	ogs/ft_strlcat.c \
	ogs/ft_strlcpy.c \
	ogs/ft_strmapi.c \
	ogs/ft_strncmp.c \
	ogs/ft_strnstr.c \
	ogs/ft_strrchr.c \
	ogs/ft_strtrim.c \
	ogs/ft_substr.c  \
	ogs/ft_toupper.c \
	ogs/ft_tolower.c

PRINTF = printf/ft_printf.c \
	printf/ft_toput.c \
	printf/ft_printfmem_fd.c \
	printf/ft_tohexa.c

GNL = gnl/get_next_line.c \
	gnl/get_next_line_utils.c \
	gnl/gc_get_next_line.c \
	gnl/gc_get_next_line_utils.c

UTILS = utils/dchars/ft_puttab.c \
	utils/dchars/cpydchar.c \
	utils/dchars/freedchar.c \
	utils/random/istype.c \
	utils/random/ft_atol.c

GC = gc_allocs/gc_malloc.c \
	gc_allocs/gc_calloc.c \
	gc_allocs/gc_strdup.c \
	gc_allocs/gc_itoa.c \
	gc_allocs/gc_split.c \
	gc_allocs/gc_cpydchar.c \
	gc_allocs/gc_strjoin.c

SRCS = ${OGS} ${PRINTF} ${GNL} ${UTILS} ${GC}

OBJS = ${SRCS:.c=.o}

%.o: %.c
	@if [ "$<" = "ogs/ft_atoi.c" ]; then \
		echo "Starting compilation of object files"; echo "Compiling [00%]"; \
	elif [ "$<" = "ogs/ft_itoa.c" ]; then \
		echo "Compiling [10%]"; \
	elif [ "$<" = "ogs/to_fd.c" ]; then \
		echo "Compiling [20%]"; \
	elif [ "$<" = "ogs/ft_strdup.c" ]; then \
		echo "Compiling [30%]"; \
	elif [ "$<" = "ogs/ft_strlcat.c" ]; then \
		echo "Compiling [40%]"; \
	elif [ "$<" = "ogs/ft_strncmp.c" ]; then \
		echo "Compiling [50%]"; \
	elif [ "$<" = "ogs/ft_strtrim.c" ]; then \
		echo "Compiling [60%]"; \
	elif [ "$<" = "printf/ft_tohexa.c" ]; then \
		echo "Compiling [70%]"; \
	elif [ "$<" = "utils/dchars/cpydchar.c" ]; then \
		echo "Compiling [80%]"; \
	elif [ "$<" = "gc_allocs/gc_strdup.c" ]; then \
		echo "Compiling [90%]"; \
	elif [ "$<" = "gc_allocs/gc_strjoin.c" ]; then \
		echo "Compiling [100%] : Complete"; \
	fi
	@${CC} ${CFLAGS} -c $< -o $@

all: checklib

checklib: 
	@if [ -f ${NAME} ]; then \
		echo "fuck u, ${NAME} already exists"; \
	else \
		$(MAKE) --no-print-directory ${NAME}; \
	fi

${NAME}: ${OBJS}
	@ar -rcs ${NAME} ${OBJS}
	@echo "Compilation of [${NAME}] is done"

clean:
	@rm -rf ${OBJS}
	@echo "Objects files removed"

fclean: clean
	@rm -rf ${NAME}
	@echo "Library file removed"

re: fclean all

.PHONY: all clean fclean re
