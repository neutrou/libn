# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: neutrou <neutrou@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/20 11:51:44 by valgrant          #+#    #+#              #
#    Updated: 2024/06/08 18:46:53 by neutrou          ###   ########.fr        #
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
	ogs/ft_is.c \
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
	gnl/get_next_line_utils.c

DCHARS = wtv/dchars/ft_puttab.c \
	wtv/dchars/cpydchar.c \
	wtv/dchars/freedchar.c

GC = gc_allocs/gc_malloc.c \
	gc_allocs/gc_calloc.c \
	gc_allocs/gc_strdup.c \
	gc_allocs/gc_itoa.c \
	gc_allocs/gc_split.c \
	gc_allocs/gc_strjoin.c

SRCS = ${OGS} ${PRINTF} ${GNL} ${DCHARS} ${GC}

@OBJS = ${SRCS:.c=.o}

pre_obj:
	@echo "Creating objects"

post_obj:
	@echo "Creation of objects done"

all: ${NAME}

${NAME}: pre_obj ${OBJS} post_obj
	@echo "Creating library"
	@ar -rcs ${NAME} ${OBJS}
	@echo "Compilation of ${NAME} is done"

clean:
	@rm -rf ${OBJS}
	@echo "Objects files removed"

fclean: clean
	@rm -rf ${NAME}
	@echo "Library file removed"

re: fclean all

.PHONY: all clean fclean re
