/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_all_setup.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galamy <galamy@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 11:17:15 by glamy             #+#    #+#             */
/*   Updated: 2023/05/16 12:27:07 by galamy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	check_all_setup(t_game *game)
{
	set_orient_player(game);
	game->setup.res_height = game->setup.map_height * TEX_HEIGHT;
	game->setup.res_width = game->setup.map_width * TEX_WIDTH;
	ft_check_size_res(game);
	game->mlx = mlx_init();
	if (!game->mlx)
		exit_game(game, "ERROR\n Initializing mlx fail.\n", 1);
	allocate_buffer(game);
	load_texture(game);
	game->img.img = mlx_new_image(game->mlx, game->setup.res_width,
			game->setup.res_height);
	game->img.data = (int *)mlx_get_data_addr(game->img.img,
			&game->img.bpp, &game->img.size_l, &game->img.endian);
	return (1);
}

void	set_orient_player(t_game *game)
{
	int	degree;

	degree = 0;
	if (game->player.dir == 'N')
		degree = 90;
	else if (game->player.dir == 'S')
		degree = 270;
	else if (game->player.dir == 'E')
		degree = 180;
	else if (game->player.dir == 'W')
		degree = 0;
	rotate_player(&game->player, (double)degree * (PI / 180));
}

void	allocate_buffer(t_game *game)
{
	int	i;

	game->buf = ft_calloc(game->setup.res_height
			* game->setup.res_width, sizeof(int **));
	if (!game->buf)
		exit_game(game, "ERROR:\n Malloc Fail!", 1);
	i = 0;
	while (i < game->setup.res_height)
	{
		game->buf[i] = ft_calloc(game->setup.res_width, sizeof(int *));
		if (!game->buf[i])
			exit_game(game, "ERROR:\n Malloc Fail!", 1);
		i++;
	}
	game->n_buffer = ft_calloc(game->setup.res_width, sizeof(double *));
	if (!game->n_buffer)
		exit_game(game, "ERROR:\n Malloc Fail!", 1);
}

void	load_texture(t_game *game)
{
	t_img	img;

	load_image(game, game->setup.tex.tile[C_WE],
		game->setup.tex.path[C_WE], &img);
	free(game->setup.tex.path[C_WE]);
	load_image(game, game->setup.tex.tile[C_EA],
		game->setup.tex.path[C_EA], &img);
	free(game->setup.tex.path[C_EA]);
	load_image(game, game->setup.tex.tile[C_SO],
		game->setup.tex.path[C_SO], &img);
	free(game->setup.tex.path[C_SO]);
	load_image(game, game->setup.tex.tile[C_NO],
		game->setup.tex.path[C_NO], &img);
	free(game->setup.tex.path[C_NO]);
}

void	load_image(t_game *game, int *texture, char *path, t_img *img)
{
	int		x;
	int		y;

	img->img = mlx_xpm_file_to_image(game->mlx, path,
			&img->width, &img->height);
	if (!img->img || !img->height || !img->width)
		ft_error("ERROR\n Texture path fail");
	img->data = (int *)mlx_get_data_addr(img->img,
			&img->bpp, &img->size_l, &img->endian);
	y = 0;
	img->height = TEX_HEIGHT;
	img->width = TEX_WIDTH;
	while (y < img->height)
	{
		x = 0;
		while (x < img->width)
		{
			texture[img->width * y + x] = img->data[img->width
				* y + (img->width - x - 1)];
			x++;
		}
		y++;
	}
}
