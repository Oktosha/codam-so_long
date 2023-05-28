#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "MLX42/MLX42.h"
#include "MLX42/MLX42_Int.h"
#define WIDTH 512
#define HEIGHT 512

mlx_image_t* img;
int resize_cnt = 0;
int key_cnt = 0;
int loop_cnt = 0;

static void error(void)
{
	puts(mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}

// Print the window width and height.
static void resize_hook(int32_t width, int32_t height, void* param)
{
	(void) param;
	++resize_cnt;
	printf("resize hook %d: WIDTH: %d | HEIGHT: %d\n", resize_cnt, width, height);
}

static void loop_hook(void* param)
{
	++loop_cnt;
	const mlx_t* mlx = param;
	printf("loop hook %d: WIDTH: %d | HEIGHT: %d\n", loop_cnt, mlx->width, mlx->height);
}

static void key_hook(mlx_key_data_t keydata, void* param)
{
	(void) keydata;
	mlx_t* mlx = param;
	++key_cnt;
	printf("key hook %d\n", key_cnt);
	mlx_close_window(mlx);
}

int32_t	main(void)
{
	mlx_set_setting(MLX_STRETCH_IMAGE, false);
	// Start mlx
	mlx_t* mlx = mlx_init(WIDTH, HEIGHT, "Test", true);
	if (!mlx)
        error();

	// Try to load the file
	mlx_texture_t* texture = mlx_load_png("./assets/wall.png");
	if (!texture)
        error();

	// Convert texture to a displayable image
	img = mlx_texture_to_image(mlx, texture);
	if (!img)
        error();

	// Display the image
	if (mlx_image_to_window(mlx, img, 0, 0) < 0)
        error();

	mlx_resize_hook(mlx,resize_hook, mlx);
	mlx_loop_hook(mlx, loop_hook, mlx);
	mlx_key_hook(mlx, key_hook, mlx);
	mlx_set_window_limit(mlx, 100, 100, -1, -1);
	mlx_loop(mlx);

	// Optional, terminate will clean up any leftovers, this is just to demonstrate.
	//mlx_delete_image(mlx, img);
	mlx_delete_texture(texture);
	mlx_terminate(mlx);
	texture = NULL;
	img = NULL;
	getchar();
	return (EXIT_SUCCESS);
}
