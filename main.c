#include "so_long.h"

int	main(void)
{
	void	*mlx;
	void	*img;
	char	*relative_path = "./wall.xpm";
	int		img_width;
	int		img_height;
	void	*win;

	mlx = mlx_init();
	img = mlx_xpm_file_to_image(mlx, relative_path, &img_width, &img_height);
	win = mlx_new_window(mlx, 32 * 35, 6 * 32, "Hello world!");
	mlx_put_image_to_window(mlx, win, img, 0, 0);
	mlx_put_image_to_window(mlx, win, img, 0, 32);
	mlx_put_image_to_window(mlx, win, img, 68, 70);
	mlx_loop(mlx);
}


void otrisovka(t_mapa *mapa_main)
{
	char **map;
	map = mapa_main->map_data;

	void	*mlx;
	void	*img;
	char	*relative_path = "./wall.xpm";
	int		img_width;
	int		img_height;
	void	*win;

	mlx = mlx_init();
	img = mlx_xpm_file_to_image(mlx, relative_path, &img_width, &img_height);
	win = mlx_new_window(mlx, 32 * 35, 6 * 32, "Hello world!");

	int x = 0;
	int len = ((mapa_main->length) - 1);
	while (map[0][len])
	{
		mlx_put_image_to_window(mlx, win, img, x, 0);
		x += 32;
	}
}