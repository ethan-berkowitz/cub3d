/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resize_images.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eberkowi <eberkowi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 10:42:02 by eberkowi          #+#    #+#             */
/*   Updated: 2025/01/31 13:19:16 by eberkowi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void resize_torch_images(t_game *game)
{
	int i;

	i = 0;
	while (i < 8)
	{
		if (!mlx_resize_image((game->flame_img)[i], FLAME_SIZE, FLAME_SIZE))
			error_exit_and_free(game, "MLX failed to resize an image");
		i++;
	}
}

void	resize_images(t_game *game)
{
	if (!mlx_resize_image(game->minimap_wall_img, game->tile_size, game->tile_size))
		error_exit_and_free(game, "MLX failed to resize an image");
	if (!mlx_resize_image(game->minimap_floor_img, game->tile_size, game->tile_size))
		error_exit_and_free(game, "MLX failed to resize an image");
	if (!mlx_resize_image(game->empty_map_img, game->tile_size, game->tile_size))
		error_exit_and_free(game, "MLX failed to resize an image");
	if (!mlx_resize_image(game->player.minimap_player_img, game->tile_size / 4,
			game->tile_size / 4))
		error_exit_and_free(game, "MLX failed to resize an image");
	if (!mlx_resize_image(game->zippo_img, ZIPPO_SIZE, ZIPPO_SIZE))
		error_exit_and_free(game, "MLX failed to resize an image");
	resize_torch_images(game);
}
