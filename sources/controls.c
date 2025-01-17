/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kattimaijanen <kattimaijanen@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 09:41:04 by jlehtone          #+#    #+#             */
/*   Updated: 2025/01/17 21:54:35 by kattimaijan      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static bool	rotate_player(t_game *game, double direction)
{
	if (direction == LEFT)
	{
		game->player.angle_radian -= ROTATE_SPEED;
		if (game->player.angle_radian < 0)
			game->player.angle_radian += (2 * PI);
	}
	else if (direction == RIGHT)
	{
		game->player.angle_radian += ROTATE_SPEED;
		if (game->player.angle_radian >= (2 * PI))
			game->player.angle_radian -= (2 * PI);
	}	
	game->player.dx = cos(game->player.angle_radian);
	game->player.dy = sin(game->player.angle_radian);
	game->ray.angle = game->player.angle_radian - (FOV / 2);
	determine_ray_direction(game);
	return (true);
}

static bool	move_player_up_down(t_game *game, double direction)
{
	double	new_x;
	double	new_y;
	
	if (direction == FORWARD)
	{
		new_x = game->player.x + cos(game->player.angle_radian) * MOVE_SPEED;
		new_y = game->player.y + sin(game->player.angle_radian) * MOVE_SPEED;
	}
	else if (direction == BACK)
	{
		new_x = game->player.x - cos(game->player.angle_radian) * MOVE_SPEED;
		new_y = game->player.y - sin(game->player.angle_radian) * MOVE_SPEED;
	}
	if (is_wall(game, new_x, new_y) == false)
	{
		game->player.x = new_x;
		game->player.y = new_y;
		game->player.player_img->instances[0].x = new_x;
		game->player.player_img->instances[0].y = new_y;
		return (true);
	}
	else
		return (false);
}

static bool	move_player_left_right(t_game *game, double direction)
{
	double	new_x;
	double	new_y;
	
	if (direction == LEFT)
	{
		new_x = game->player.x + sin(game->player.angle_radian) * MOVE_SPEED;
		new_y = game->player.y - cos(game->player.angle_radian) * MOVE_SPEED;
	}
	else if (direction == RIGHT)
	{
		new_x = game->player.x - sin(game->player.angle_radian) * MOVE_SPEED;
		new_y = game->player.y + cos(game->player.angle_radian) * MOVE_SPEED;
	}
	if (is_wall(game, new_x, new_y) == false)
	{
		game->player.x = new_x;
		game->player.y = new_y;
		game->player.player_img->instances[0].x = new_x;
		game->player.player_img->instances[0].y = new_y;
		return (true);
	}
	else
		return (false);
}


bool controls(t_game *game)
{
	bool	movement;
	
	if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE))
	{
		free_all(game);
		exit (EXIT_SUCCESS);
	}
	if (mlx_is_key_down(game->mlx, MLX_KEY_W))
		movement = move_player_up_down(game, FORWARD);
	if (mlx_is_key_down(game->mlx, MLX_KEY_S))
		movement = move_player_up_down(game, BACK);
	if (mlx_is_key_down(game->mlx, MLX_KEY_A))
		movement = move_player_left_right(game, LEFT);
	if (mlx_is_key_down(game->mlx, MLX_KEY_D))
		movement = move_player_left_right(game, RIGHT);
	if (mlx_is_key_down(game->mlx, MLX_KEY_LEFT))
		movement = rotate_player(game, LEFT);
	if (mlx_is_key_down(game->mlx, MLX_KEY_RIGHT))
		movement = rotate_player(game, RIGHT);
	return (movement);
}
