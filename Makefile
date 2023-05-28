# --- Boilerplate things for every makefile ---

SHELL=/bin/sh
CC=cc
CFLAGS=-Wall -Wextra -Werror

# --- Main target ---

NAME=so_long
all: ${NAME}

# --- codam-io (my input/output lib) ---

LIBIO_FOLDER=./lib/MLX42
LIBIO_SUBMODULE=${LIBIO_FOLDER}/.git
LIBIO_BUILD_FOLDER=${LIBIO_FOLDER}/build
LIBIO_BINARY=${LIBIO_BUILD_FOLDER}/libcodamio.a

${LIBIO_SUBMODULE}:
	git submodule update --init ${@D}

${LIBIO_BINARY}: ${LIBIO_SUBMODULE}
	make -C ${LIBIO_FOLDER}

LIBIO_INCLUDE_FOLDER=${LIBIO_FOLDER}/include

# --- MLX42 ---

LIBMLX_FOLDER=./lib/MLX42
LIBMLX_SUBMODULE=${LIBMLX_FOLDER}/.git
LIBMLX_BUILD_FOLDER=${LIBMLX_FOLDER}/build
LIBMLX_BINARY=${LIBMLX_BUILD_FOLDER}/libmlx42.a

${LIBMLX_SUBMODULE}:
	git submodule update --init ${@D}

${LIBMLX_BINARY}: ${LIBMLX_SUBMODULE}
	cmake ${LIBMLX_FOLDER} -B ${LIBMLX_BUILD_FOLDER}
	make -C ${LIBMLX_BUILD_FOLDER} -j4

LIBMLX_INCLUDE_FOLDER=${LIBMLX_FOLDER}/include

# on my home computer I set it to -lglfw (without 3)
LIBGLFW_FLAG = -lglfw3

LIBMLX_LINKING_FLAGS= \
-ldl ${LIBGLFW_FLAG} -pthread -lm \
-framework Cocoa \
-framework OpenGL \
-framework IOKit

# --- Objects compilation --

SRCS=main.c

SRC_FOLDER=src
BINARY_FOLDER=bin
OBJS=${addprefix ${BINARY_FOLDER}/,${SRCS:.c=.o}}

${OBJS}: ${BINARY_FOLDER}/%.o: ${SRC_FOLDER}/%.c ${LIBMLX_SUBMODULE}
	mkdir -p $(@D)
	${CC} ${CFLAGS} $< -o $@ -c -I${LIBMLX_INCLUDE_FOLDER} -I${LIBIO_INCLUDE_FOLDER}

# --- Final linking ---

${NAME}: ${OBJS} ${LIBMLX_BINARY} ${LIBIO_BINARY}
	${CC} ${CFLAGS} $^ -o $@ ${LIBMLX_LINKING_FLAGS}

# --- norm ---

norm: ${LIBIO_SUBMODULE}
	norminette src include lib/io

# -- More boilerplate things --

.PHONY: all clean fclean re norm

clean:
	rm -rf ${BINARY_FOLDER} ${LIBMLX_BUILD_FOLDER}

fclean: clean
	rm -f ${NAME}

re: fclean all
