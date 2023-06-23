// Example MLX program, uses my codam-io lib for output
// No error checking performed, emulates API exploration

#include "MLX42/MLX42.h"
#include "codam_io.h"
#define WIDTH 256
#define HEIGHT 256

int32_t	main(void)
{
	mlx_t* mlx = mlx_init(WIDTH, HEIGHT, "exploring for so_long", true);
	mlx_texture_t *texture = mlx_load_png("./assets/player.png");
	mlx_image_t* img = mlx_texture_to_image(mlx, texture);
	mlx_image_to_window(mlx, img, 30, 30);
	io_out("starting mlx\n");
	mlx_loop(mlx);
	mlx_terminate(mlx);
	io_out("mlx loop exited\n");
	return 0;
}
