# Notes

## MLX

looks like coordinates outside window are allowed (negative & big)

hooks don't have to be thread-safe, they are always called from the main thread

mlx_close_window is safe to call from a hook (and mlx_terminate -> not)

## Submodules

```shell
git remote add intra [REPO_URL_FROM_THE_INTRANET]
git push intra main:master
```

## Experimental main

```shell
gcc experimental_main.c \
lib/MLX42/build/libmlx42.a lib/io/build/libcodamio.a \
-ldl -lglfw -pthread -lm \
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

## Things to be careful about

be careful, don't free all data in key hook, one can queue several key hooks
