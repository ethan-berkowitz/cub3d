/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlehtone <jlehtone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 09:19:38 by jlehtone          #+#    #+#             */
/*   Updated: 2025/02/04 16:26:08 by jlehtone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/*
	@brief Our main loop, raycasting and rendering whenever a movement occurs.
    @param content Our game struct as a void pointer
*/
void	rendering(void *data)
{
	t_game	*game;
	bool	movement;

	game = (t_game *)data;
	raycasting(game);
	movement = controls(game);
	if (movement == true)
	{
		raycasting(game);
	}
}
