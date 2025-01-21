/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlehtone <jlehtone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 16:03:55 by jlehtone          #+#    #+#             */
/*   Updated: 2025/01/21 11:57:19 by jlehtone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

//soh = Sine = Opposite / Hypotenuse
//cah = Cosine = Adjacent / Hypotenuse
//toa = Tangent = Opposite / Adjacent

static void determine_initial_player_direction(t_game *game)
{
	game->player.initial_direction = FORWARD; //for testing, determine later by the symbol on the map. also now points to east
	game->player.angle_radian = game->player.initial_direction;
	game->ray.direction_up = false;
	game->ray.direction_left = false;
	if (game->player.initial_direction == FORWARD)
		game->ray.direction_up = true;
	else if (game->player.initial_direction == LEFT)
		game->ray.direction_left = true;
}

void init_ray(t_game *game)
{
	determine_initial_player_direction(game);
	game->ray.y = 0; //(game->player.y / TILE_SIZE) * TILE_SIZE;
	game->ray.x = 0; //game->player.x + (game->ray.y - game->player.y) / tan(game->ray.angle);
	game->ray.distance = 0;
	game->ray.fov_radian = FOV * (PI / 180);
	game->player.dx = 0;
	game->player.dy = 0;
	
}

static double find_vertical_intersection(t_game *game)
{
	float	point_x;
	float	point_y;
	float	step_x;
	float	step_y;
	double	distance;

	point_x = floor(game->player.x / TILE_SIZE) * TILE_SIZE;
	if (game->ray.direction_left == false)
		point_x += TILE_SIZE;
	if (fabs(tan(game->player.angle_radian)) == 0)
		point_y = game->player.y; 
	else
		point_y = (point_x - game->player.x) / tan(game->player.angle_radian) + game->player.y;
	calculate_vertical_step(game, &step_x, &step_y);
	while (is_wall_float(game, point_x, point_y) == false)
	{
		point_x += step_x;
		point_y += step_y;
	}
	game->ray.vx = point_x;
	game->ray.vy = point_y;
	distance = sqrt(pow(point_x - game->player.x, 2) + pow(point_y - game->player.y, 2));
	return (distance);
}

static double find_horizontal_intersection(t_game *game)
{
	float	point_x;
	float	point_y;
	float	step_x;
	float	step_y;
	double	distance;

	point_y = floor(game->player.y / TILE_SIZE) * TILE_SIZE;
	if (game->ray.direction_up == false)
		point_y += TILE_SIZE;
	if (fabs(tan(game->player.angle_radian)) == 0)
		point_x = game->player.x;
	else
		point_x = (point_y - game->player.y) / tan(game->player.angle_radian) + game->player.x;
	calculate_horizontal_step(game, &step_x, &step_y);
	while (is_wall_float(game, point_x, point_y) == false)
	{
		point_y += step_y;
		point_x += step_x;
	}
	game->ray.hx = point_x;
	game->ray.hy = point_y;
	distance = sqrt(pow(point_x - game->player.x, 2) + pow(point_y - game->player.y, 2));
	return (distance);
}

void raycasting(t_game *game)
{
	double	h_inter;
	double	v_inter;
	int		ray;
	int		degree;

	game->ray.angle = game->player.angle_radian - (FOV / 2);
	degree = game->ray.fov_radian / FOV;
	ray = 0;
	// while (ray < FOV)
	// {
	// 	printf("RAY ANGLE = %f\n", game->ray.angle);
		h_inter = find_horizontal_intersection(game);
		v_inter = find_vertical_intersection(game);
		choose_shorter_distance(game, h_inter, v_inter);
		// render_wall(game); // to do
		// render_ray(game); // for testing/minimap
		//printf("The ray hits wall in: %f\n", game->ray.distance); // CAN BE REMOVED LATER
		// game->ray.angle += degree;
		// ray++;
	// }
}
