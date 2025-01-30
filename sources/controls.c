/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlehtone <jlehtone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 09:41:04 by jlehtone          #+#    #+#             */
/*   Updated: 2025/01/30 11:49:46 by jlehtone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static bool	rotate_player(t_game *game, double direction)
{
	if (direction == RIGHT)
	{
		game->player.angle += ROTATE_SPEED;
		game->ray.angle += ROTATE_SPEED;
	}
	else if (direction == LEFT)
	{
		game->player.angle -= ROTATE_SPEED;
		game->ray.angle -= ROTATE_SPEED;
	}
	reset_angles(game);
	determine_ray_direction(game);
	return (true);
}

static bool	move_player(t_game *game, double direction)
{
	float	new_x;
	float	new_y;
	t_box	ghost_box;
	
	new_x = game->player.x + cos(game->player.angle + direction) * MOVE_SPEED;
	new_y = game->player.y + sin(game->player.angle + direction) * MOVE_SPEED;
	ghost_box = (t_box){new_x - 4, new_y - 4, \
		new_x + 4, new_y - 4, \
		new_x - 4, new_y + 4, \
		new_x + 4, new_y + 4};
	// printf("player x: %d, player y:%d\n", game->player.x, game->player.y);
	// printf("box tlx: %d, tly: %d\n", ghost_box.top_left_x, ghost_box.top_left_y);
	// printf("box trx: %d, try: %d\n", ghost_box.top_right_x, ghost_box.top_right_y);
	// printf("box blx: %d, bly: %d\n", ghost_box.bottom_left_x, ghost_box.bottom_left_y);
	// printf("box brx: %d, bry: %d\n", ghost_box.bottom_right_x, ghost_box.bottom_right_y);
	//if (is_wall(game, new_x, new_y) == false)
	if (is_wall(game, ghost_box.top_left_x, ghost_box.top_left_y) == false \
		&& is_wall(game, ghost_box.top_right_x, ghost_box.top_right_y) == false \
		&& is_wall(game, ghost_box.bottom_left_x, ghost_box.bottom_left_y) == false \
		&& is_wall(game, ghost_box.bottom_right_x, ghost_box.bottom_right_y) == false)
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
	
	movement = false;
	if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE))
	{
		free_all(game);
		exit (EXIT_SUCCESS);
	}
	if (mlx_is_key_down(game->mlx, MLX_KEY_W))
		movement = move_player(game, FORWARD);
	if (mlx_is_key_down(game->mlx, MLX_KEY_S))
		movement = move_player(game, BACK);
	if (mlx_is_key_down(game->mlx, MLX_KEY_A))
		movement = move_player(game, LEFT);
	if (mlx_is_key_down(game->mlx, MLX_KEY_D))
		movement = move_player(game, RIGHT);
	if (mlx_is_key_down(game->mlx, MLX_KEY_LEFT))
		movement = rotate_player(game, LEFT);
	if (mlx_is_key_down(game->mlx, MLX_KEY_RIGHT))
		movement = rotate_player(game, RIGHT);
	return (movement);
}
