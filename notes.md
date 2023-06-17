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

Launch so_long on all maps with errors

```shell
find maps/error -name "*.ber" -exec echo {} \;  \( -exec ./so_long {} \; -o -true \) -exec echo  \;
```

## Things to be careful about

be careful, don't free all data in key hook, one can queue several key hooks
