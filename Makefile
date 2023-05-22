# --- Boilerplate things for every makefile ---

SHELL=/bin/sh
CC=cc
CFLAGS=-Wall -Wextra -Werror

# --- Main target ---

NAME=so_long
all: ${NAME}

# --- MLX42 ---

LIBMLX_FOLDER=./lib/MLX42
LIBMLX_BUILD_FOLDER=${LIBMLX_FOLDER}/build
LIBMLX_BINARY=${LIBMLX_BUILD_FOLDER}/libmlx42.a

${LIBMLX_BINARY}:
	git submodule update --init ${@D}
	cmake ${LIBMLX_FOLDER} -B ${LIBMLX_BUILD_FOLDER}
	make -C ${LIBMLX_BUILD_FOLDER} -j4

LIBMLX_INCLUDE_FOLDER=${LIBMLX_FOLDER}/include

LIBMLX_LINKING_FLAGS= \
-ldl -lglfw3 -pthread -lm \
-framework Cocoa \
-framework OpenGL \
-framework IOKit

# --- Objects compilation --

SRCS=main.c

SRC_FOLDER=src
BINARY_FOLDER=bin
OBJS=${addprefix ${BINARY_FOLDER}/,${SRCS:.c=.o}}

CFLAGS = -Wextra -Wall -Werror

${OBJS}: ${BINARY_FOLDER}/%.o: ${SRC_FOLDER}/%.c
	mkdir -p $(@D)
	${CC} ${CFLAGS} $< -o $@ -c -I${LIBMLX_INCLUDE_FOLDER}

# --- Final linking ---

${NAME}: ${OBJS} ${LIBMLX_BINARY}
	${CC} $^ -o $@ ${LIBMLX_LINKING_FLAGS}

# -- More boilerplate things --

.PHONY: all clean fclean re

clean:
	rm -rf ${BINARY_FOLDER} ${LIBMLX_BUILD_FOLDER}

fclean: clean
	rm -f ${NAME}

re: fclean all
