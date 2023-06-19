# --- Boilerplate things for every makefile ---

SHELL=/bin/sh
CC=cc
CFLAGS=-Wall -Wextra -Werror

# --- Main target ---

NAME=so_long
all: libio libmlx ${NAME}

# --- codam-io (my input/output lib) ---

LIBIO_FOLDER=./lib/io
LIBIO_SUBMODULE=${LIBIO_FOLDER}/.git
LIBIO_BUILD_FOLDER=${LIBIO_FOLDER}/build
LIBIO_BINARY=${LIBIO_BUILD_FOLDER}/libcodamio.a
LIBIO_NO_FAILFAST_FLAGS=\
-DIO_FAILFAST_ON_ALLOCATION_ERROR=0 \
-DIO_FAILFAST_ON_CLOSE_ERROR=0 \
-IO_FAILFAST_ON_OPEN_ERROR=0 \
-DIO_FAILFAST_ON_READ_ERROR=0 \
-DIO_FAILFAST_ON_WRITE_ERROR=0

libio: ${LIBIO_SUBMODULE}
	make -C ${LIBIO_FOLDER} CFLAGS="${CFLAGS} ${LIBIO_NO_FAILFAST_FLAGS}"

${LIBIO_SUBMODULE}:
	git submodule update --init ${@D}

LIBIO_INCLUDE_FOLDER=${LIBIO_FOLDER}/include

# --- MLX42 ---

LIBMLX_FOLDER=./lib/MLX42
LIBMLX_SUBMODULE=${LIBMLX_FOLDER}/.git
LIBMLX_BUILD_FOLDER=${LIBMLX_FOLDER}/build
LIBMLX_BINARY=${LIBMLX_BUILD_FOLDER}/libmlx42.a

libmlx: ${LIBMLX_SUBMODULE}
	cmake ${LIBMLX_FOLDER} -B ${LIBMLX_BUILD_FOLDER}
	make -C ${LIBMLX_BUILD_FOLDER} -j4

${LIBMLX_SUBMODULE}:
	git submodule update --init ${@D}

LIBMLX_INCLUDE_FOLDER=${LIBMLX_FOLDER}/include

# on my home computer I set it to -lglfw (without 3)
# i. e. make LIBGLFW_FLAG=-lglfw
LIBGLFW_FLAG = -lglfw3

LIBMLX_LINKING_FLAGS= \
-ldl ${LIBGLFW_FLAG} -pthread -lm \
-framework Cocoa \
-framework OpenGL \
-framework IOKit

# --- Objects compilation --

SO_LONG_INCLUDE_FOLDER=include

HEADER_SRCS=\
so_long.h

HEADERS=${addprefix ${SO_LONG_INCLUDE_FOLDER}/,${HEADER_SRCS}}

SRCS=\
flow/sl_01a_get_filename_from_argc_argv.c \
flow/sl_01b_check_file_extention.c \
flow/sl_02a_read_map_data.c \
flow/sl_02b_check_data_not_empty.c \
flow/sl_02c_check_data_is_print.c \
flow/sl_02d_check_data_symbols.c \
flow/sl_02e_check_trailing_newline.c \
flow/sl_02f_check_no_empty_lines.c \
flow/sl_02g_find_map_dimensions.c \
flow/sl_02h_reject_small_map.c \
flow/sl_02i_allocate_map_data.c \
flow/sl_02j_fill_map_data.c \
flow/sl_02k_check_borders.c \
flow/sl_02l_fill_player_coordinates.c \
flow/sl_02m_check_exit.c \
flow/sl_02n_count_collectibles.c \
flow/sl_02o_check_reachability.c \
flow/sl_03_read_assets.c \
flow/sl_04a_find_tile_size.c \
flow/sl_06_init_mlx.c \
flow/sl_07_instantiate_images.c \
flow/sl_08_init_draw_utils.c \
flow/sl_09_add_hooks.c \
flow/sl_10_start_mlx_loop.c \
flow/sl_11_print_summary.c \
main.c \
sl_apply.c \
sl_calloc.c \
sl_cleanup.c \
sl_err.c \
sl_init.c \
so_long.c

SRC_FOLDER=src
BINARY_FOLDER=bin
OBJS=${addprefix ${BINARY_FOLDER}/,${SRCS:.c=.o}}

${OBJS}: ${BINARY_FOLDER}/%.o: ${SRC_FOLDER}/%.c ${LIBMLX_BINARY} ${LIBIO_BINARY} ${HEADERS}
	mkdir -p $(@D)
	${CC} ${CFLAGS} $< -o $@ -c \
-I${LIBMLX_INCLUDE_FOLDER} -I${LIBIO_INCLUDE_FOLDER} -I${SO_LONG_INCLUDE_FOLDER}

# --- Final linking ---

${NAME}: ${OBJS} ${LIBMLX_BINARY} ${LIBIO_BINARY}
	${CC} ${CFLAGS} $^ -o $@ ${LIBMLX_LINKING_FLAGS}

# --- norm ---

norm: ${LIBIO_SUBMODULE}
	norminette src include lib/io

# -- More boilerplate things --

.PHONY: all norm libio libmlx clean fclean re soft_clean soft_re

clean:
	rm -rf ${BINARY_FOLDER} ${LIBMLX_BUILD_FOLDER} ${LIBIO_BUILD_FOLDER}

fclean: clean
	rm -f ${NAME}

re: fclean all

soft_clean:
	rm -rf ${BINARY_FOLDER} ${NAME}

soft_re: soft_clean ${NAME}
