/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galamy <galamy@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 21:29:34 by glamy             #+#    #+#             */
/*   Updated: 2023/05/16 01:49:58 by galamy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	init_ray(t_game *game, t_player *player, t_ray *ray, int x)
{
	ray->camerax = 2 * x / (double)game->setup.res_width - 1;
	ray->dirx = player->dir_x + player->plane_x * ray->camerax * -1;
	ray->diry = player->dir_y + player->plane_y * ray->camerax * -1;
	ray->mapx = (int)player->posx;
	ray->mapy = (int)player->posy;
	ray->deltadistx = fabs(1 / ray->dirx);
	ray->deltadisty = fabs(1 / ray->diry);
	ray->hit = 0;
}

void	calculate_step(t_player *player, t_ray *ray)
{
	if (ray->dirx < 0)
	{
		ray->stepx = -1;
		ray->sidedistx = (player->posx - ray->mapx) * ray->deltadistx;
	}
	else
	{
		ray->stepx = 1;
		ray->sidedistx = (ray->mapx + 1.0 - player->posx) * ray->deltadistx;
	}
	if (ray->diry < 0)
	{
		ray->stepy = -1;
		ray->sidedisty = (player->posy - ray->mapy) * ray->deltadisty;
	}
	else
	{
		ray->stepy = 1;
		ray->sidedisty = (ray->mapy + 1.0 - player->posy) * ray->deltadisty;
	}
}

void	perform_dda(t_setup *setup, t_ray *ray)
{
	while (ray->hit == 0)
	{
		if (ray->sidedistx < ray->sidedisty)
		{
			ray->sidedistx += ray->deltadistx;
			ray->mapx += ray->stepx;
			if (ray->stepx == -1)
				ray->side = WEST;
			else
				ray->side = EAST;
		}
		else
		{
			ray->sidedisty += ray->deltadisty;
			ray->mapy += ray->stepy;
			if (ray->stepy == -1)
				ray->side = SOUTH;
			else
				ray->side = NORTH;
		}
		if ((setup->map[ray->mapy][ray->mapx]) == WALL)
			ray->hit = 1;
	}
}

void	calculate_wall_distance(t_player *player, t_ray *ray)
{
	if (ray->side == WEST || ray->side == EAST)
		ray->perpwalldist = (ray->mapx - player->posx
		+ (1 - ray->stepx) / 2) / ray->dirx;
	else
		ray->perpwalldist = (ray->mapy - player->posy
		+ (1 - ray->stepy) / 2) / ray->diry;
}

void	calculate_wall_height(t_game *game, t_ray *ray)
{
	ray->lineheight = (int)(game->setup.res_height / ray->perpwalldist);
	ray->drawstart = -ray->lineheight / 2 + game->setup.res_height / 2;
	if (ray->drawstart < 0)
		ray->drawstart = 0;
	ray->drawend = ray->lineheight / 2 + game->setup.res_height / 2;
	if (ray->drawend >= game->setup.res_height)
		ray->drawend = game->setup.res_height - 1;
}
