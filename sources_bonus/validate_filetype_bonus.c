/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_filetype_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eberkowi <eberkowi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 12:15:06 by eberkowi          #+#    #+#             */
/*   Updated: 2025/02/11 14:49:24 by eberkowi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

void	validate_filetype(char *filename)
{
	while (*filename)
	{
		if (!ft_strncmp(filename, ".cub", 5))
			return ;
		filename++;
	}
	error_exit("Invalid File: Invalid filetype");
}
