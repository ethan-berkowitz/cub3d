/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kattimaijanen <kattimaijanen@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 13:42:01 by eberkowi          #+#    #+#             */
/*   Updated: 2025/01/23 19:02:39 by kattimaijan      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void bresenham_line(t_game *game, int x1, int y1, int x2, int y2)
{
    int dx = ft_abs(x2 - x1);
    int dy = ft_abs(y2 - y1);
    int sx = (x1 < x2) ? 1 : -1;
    int sy = (y1 < y2) ? 1 : -1;
    int err = dx - dy;

    while (1) 
	{
		if (x1 > 0 && x1 < WINDOW_WIDTH && y1 > 0 && y1 < WINDOW_HEIGHT)
        	mlx_put_pixel(game->minimap_img, x1, y1, 0xff0000ff);
        if (x1 == x2 && y1 == y2)
			break;
        int e2 = 2 * err;
        if (e2 > -dy) {
            err -= dy;
            x1 += sx;
        }
        if (e2 < dx) {
            err += dx;
            y1 += sy;
        }
    }
}

void clear_line(t_game *game)
{
	int y;
	int x;

	y = 0;
	while (y < (int)game->minimap_img->height)
	{
		x = 0;
		while (x < (int)game->minimap_img->width)
		{
			mlx_put_pixel(game->minimap_img, x, y, 0x00000000);
			x++;
		}
		y++;
	}
}

void draw_line(t_game *game)
{
	//clear_line(game);
	// if ((int)game->ray.x < 0 || (int)game->ray.x > WINDOW_WIDTH ||
	// 	(int)game->ray.y < 0 || (int)game->ray.y > WINDOW_HEIGHT)
	// 	error_exit_and_free(game, "JOEL THIS IS ON YOU!!"); // Ethan is so mean :(
    bresenham_line(game, game->player.x, game->player.y, (int)game->ray.x, (int)game->ray.y);
    //printf("drawing a line at x%f, y%f... player angle is %f, and ray angle is %f\n", game->ray.x, game->ray.y, game->player.angle_radian, game->ray.angle);
}
