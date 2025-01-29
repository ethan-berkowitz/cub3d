/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resize_images.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eberkowi <eberkowi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 10:42:02 by eberkowi          #+#    #+#             */
/*   Updated: 2025/01/28 17:00:49 by eberkowi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void resize_torch_images(t_game *game)
{
	int i;

	i = 0;
	while (i < 8)
	{
		if (!mlx_resize_image((game->torch_animation_images)[i], 200, 200))
			error_exit_and_free(game, "MLX failed to resize an image");
		i++;
	}
}

void	resize_images(t_game *game)
{
	if (!mlx_resize_image(game->minimap_wall_img, TILE_SIZE, TILE_SIZE))
		error_exit_and_free(game, "MLX failed to resize an image");
	if (!mlx_resize_image(game->minimap_floor_img, TILE_SIZE, TILE_SIZE))
		error_exit_and_free(game, "MLX failed to resize an image");
	if (!mlx_resize_image(game->player.player_img, TILE_SIZE / 4,
			TILE_SIZE / 4))
		error_exit_and_free(game, "MLX failed to resize an image");
	resize_torch_images(game);
}
