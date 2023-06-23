# Notes

## MLX

looks like coordinates outside window are allowed (negative & big)

hooks don't have to be thread-safe, they are always called from the main thread

mlx_close_window is safe to call from a hook (and mlx_terminate -> not)

Be careful, don't free all data in key hook, one can queue triggering of several key hooks
by pressing keys while resizing (resizing blocks events, see
[this discussion](https://github.com/codam-coding-college/MLX42/issues/108)).

## Submodules

```shell
git remote add intra [REPO_URL_FROM_THE_INTRANET]
git push intra main:master
```

## Exploring stuff

Compile a singe-file experimental program that uses the libraries
(no warn/err flags used, they are annoying for experimentation)

```shell
cmake lib/MLX42 -B lib/MLX42/build;
make -C lib/MLX42/build -j4;
make -C lib/io;
gcc experimental_main.c \
lib/MLX42/build/libmlx42.a lib/io/build/libcodamio.a \
-ldl -lglfw3 -pthread -lm \
-framework Cocoa \
-framework OpenGL \
-framework IOKit \
-I lib/io/include \
-I lib/MLX42/include
```

## Codegen

To get sources list ready for Makefile, run in the src folder:

```shell
find . | grep .c |  sort | awk '{print substr($0,3) " \\"}'
```

It'll give sorted list, separated by space + escaped newline

## Testing

Build with sanitizer on my personal laptop

```shell
make LIBGLFW_FLAG=-lglfw "CFLAGS=-Wall -Werror -Wextra -fsanitize=address"
```

Compiling with different value of a string macro (note the quotes)

```shell
make soft_re LIBGLFW_FLAG=-lglfw "CFLAGS=-Wall -Werror -Wextra -fsanitize=address -DASSETS_FOLDER='\"./alternative_assets/\"'"
```

Launch so_long on all maps with errors

```shell
find maps/error -name "*.ber" -exec sh -c 'echo "running on $0"; ./so_long "$0"; echo "retcode = $?"; echo' {} \;
```

Launch several so_long instances in the background

```shell
find maps/subject -name "*.ber" -exec sh -c './so_long "$0" &' {} \;
```
