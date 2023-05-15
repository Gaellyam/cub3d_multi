/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glamy <glamy@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 22:29:34 by glamy             #+#    #+#             */
/*   Updated: 2020/11/28 13:16:08 by glamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	set_ceiling_floor(t_game *game)
{
	int i;
	int j;

	j = 0;
	while (j < game->setup.res_height)
	{
		i = 0;
		while (i < game->setup.res_width)
		{
			if (j > game->setup.res_height / 2)
				game->buf[j][i] = game->setup.tex.floor;
			else
				game->buf[j][i] = game->setup.tex.ceiling;
			i++;
		}
		j++;
	}
}

void	set_wall_tex(t_player *player, t_ray *ray)
{
	if (ray->side == WEST || ray->side == EAST)
		ray->wallx = player->posy + ray->perpwalldist * ray->diry;
	else
		ray->wallx = player->posx + ray->perpwalldist * ray->dirx;
	ray->wallx -= floor(ray->wallx);
	ray->texx = (int)(ray->wallx * (double)TEX_WIDTH);
	if ((ray->side == EAST && ray->dirx > 0) ||
	(ray->side == SOUTH && ray->diry < 0))
		ray->texx = TEX_WIDTH - ray->texx - 1;
}

void	set_wall_color(t_game *game, t_ray *ray, int i)
{
	int color;
	int j;

	ray->step = 1.0 * TEX_HEIGHT / ray->lineheight;
	ray->texpos = (ray->drawstart - game->setup.res_height /
	2 + ray->lineheight / 2) * ray->step;
	j = ray->drawstart;
	while (j < ray->drawend)
	{
		ray->texy = (int)ray->texpos & (TEX_HEIGHT - 1);
		ray->texpos += ray->step;
		color = game->setup.tex.tile[ray->side][TEX_HEIGHT *
		ray->texy + ray->texx];
		game->buf[j][i] = color;
		j++;
	}
}
