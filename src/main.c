#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "MLX42/MLX42.h"
#define WIDTH 10000
#define HEIGHT 5120

static void error(void)
{
	puts(mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}

// Print the window width and height.
static void ft_hook(int32_t width, int32_t height, void* param)
{
	(void)(param);
	printf("WIDTH: %d | HEIGHT: %d\n", width, height);
}

int32_t	main(void)
{
	// Start mlx
	mlx_t* mlx = mlx_init(WIDTH, HEIGHT, "Test", true);
	if (!mlx)
        error();

	// Try to load the file
	mlx_texture_t* texture = mlx_load_png("./assets/colored_packed.png");
	if (!texture)
        error();
	
	// Convert texture to a displayable image
	mlx_image_t* img = mlx_texture_to_image(mlx, texture);
	if (!img)
        error();

	// Display the image
	if (mlx_image_to_window(mlx, img, -256, -256) < 0)
        error();
	
	mlx_resize_hook(mlx, ft_hook, mlx);

	mlx_loop(mlx);

	// Optional, terminate will clean up any leftovers, this is just to demonstrate.
	mlx_delete_image(mlx, img);
	mlx_delete_texture(texture);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}