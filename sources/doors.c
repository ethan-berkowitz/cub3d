/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doors.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlehtone <jlehtone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 12:58:27 by jlehtone          #+#    #+#             */
/*   Updated: 2025/02/03 10:36:57 by jlehtone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	open_close_doors(t_game *game)
{
	char		*string;

	if (game->door_text)
		mlx_delete_image(game->mlx, game->door_text);
	if (game->map[(int)game->player.y / TILE_SIZE][(int)game->player.x / TILE_SIZE] == 'D')
	{
		string = "Cannot close the door. You are too close!";
		game->door_text = mlx_put_string(game->mlx, string, \
			WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2);
		if (game->door_text)
			mlx_resize_image(game->door_text, 500, 50);
		return ;
	}
	if (game->animation.frame_counter % 9 == 0)
		game->can_close_doors = true;
	if (game->can_close_doors == true)
		game->doors_closed = !game->doors_closed;
	game->can_close_doors = false;
}

void check_for_valid_door(t_game *game, int x, int y)
{
	if (game->map[y][x] != 'D')
		return ;
	else if (game->map[y][x] == 'D')
	{
		if (!(game->map[y + 1][x] == '1' && game->map[y - 1][x] == '1' && game->map[y][x + 1] == '0' && game->map[y][x - 1] == '0') 
			&& !(game->map[y + 1][x] == '0' && game->map[y - 1][x] == '0' && game->map[y][x + 1] == '1' && game->map[y][x - 1] == '1'))
		{
			printf("Door position not valid at x:%d, y:%d\n", x, y);
			error_exit_and_free(game, "A door needs to be next to both walls and open spaces");
		}
	}
	return ;
}
