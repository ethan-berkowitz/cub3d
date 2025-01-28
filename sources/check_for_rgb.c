/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_for_rgb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eberkowi <eberkowi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 10:16:19 by eberkowi          #+#    #+#             */
/*   Updated: 2025/01/28 09:55:21 by eberkowi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void add_b(t_game *game, int i, int *j, int *element)
{
	if (!ft_isdigit(game->file[i][*j]))
		error_exit_and_free(game, "RGB contains non-digit or negative");
	*element = ft_atoi(game->file[i] + *j);
	while (game->file[i][*j] && ft_isdigit(game->file[i][*j]))
		(*j)++;
	while (game->file[i][*j] == ' ' || game->file[i][*j] == '\t')
	{
		(*j)++;
	}
}

static void add_r_and_g(t_game *game, int i, int *j, int *element)
{
	if (!ft_isdigit(game->file[i][*j]))
		error_exit_and_free(game, "RGB contains non-digit or negative");
	*element = ft_atoi(game->file[i] + *j);
	while (game->file[i][*j] && ft_isdigit(game->file[i][*j]))
		(*j)++;
	if (!game->file[i][*j] || game->file[i][*j] != ',')
		error_exit_and_free(game, "RGB is formatted incorrectly");
	(*j)++;
}

static void check_for_duplicate_rgb(t_game *game, int element)
{
	if ((element == FLOOR_RGB && game->found_floor_rgb)
		|| (element == CEILING_RGB && game->found_ceiling_rgb))
		error_exit_and_free(game, "Duplicate RGB for floor or ceiling");
	if (element == FLOOR_RGB)
		game->found_floor_rgb = 1;
	else
		game->found_ceiling_rgb = 1;	
}

void check_for_rgb(t_game *game, int i, int *j, int element)
{
	check_for_duplicate_rgb(game, element);
	*j += 2;
	if (element == FLOOR_RGB)
	{
		add_r_and_g(game, i, j, &game->floor_R);
		add_r_and_g(game, i, j, &game->floor_G);
		add_b(game, i, j, &game->floor_B);
	}
	else
	{
		add_r_and_g(game, i, j, &game->ceiling_R);
		add_r_and_g(game, i, j, &game->ceiling_G);
		add_b(game, i, j, &game->ceiling_B);
	}
}
