/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kattimaijanen <kattimaijanen@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 17:07:57 by eberkowi          #+#    #+#             */
/*   Updated: 2025/01/16 18:40:38 by kattimaijan      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef cub3d_H
# define cub3d_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <math.h>
# include "../libft/libft.h"
# include "../MLX42/include/MLX42/MLX42.h"

# define TILE_SIZE 64
# define MOVE_SIZE 14
# define MOVE_SPEED 4
# define PI 3.1415926535 //replace with M_PI?
# define FOV 60
# define ROTATE_SPEED 1 // a random value for testing
# define WIDTH 1920 // can be changed
# define HEIGHT 1080 // can be changed

typedef struct s_ray
{
    int		x;
    int		y;
    int		angle; // += turn_direction * rotation_speed;
    //int rotation_speed; // already defined in header
    //int turn_direction;
	double	distance;
	bool	direction_left;
	bool	direction_up;
} t_ray;

typedef struct s_box
{	
	int	x;
	int	y;
	int	width;
	int	height;
}	t_box;

typedef struct s_player
{
	int				x;
	int				y;
	int 			dx;
    int 			dy;
    double 			angle_degree;
    float 			angle_radian; // = angle_degree * (PI / 180);
	mlx_image_t		*player_img;
}	t_player;

typedef struct s_game
{
    char	**map;
	char	**file;
    char	*path_to_north_texture;
    char	*path_to_south_texture;
    char	*path_to_west_texture;
    char	*path_to_east_texture;
    int		*floor_rgb;
    int		*ceiling_rgb;
	mlx_t				*mlx;
	mlx_texture_t		*wall_texture;
	mlx_image_t			*wall_img;
	mlx_texture_t		*floor_texture;
	mlx_image_t			*floor_img;
	mlx_texture_t		*player_texture;
	struct s_player		player;
	struct s_ray		ray;
	int width;
	int height;
	int image_size;
} t_game;

void	error_exit(char *error);
void	error_exit_and_free(t_game *game, char *error);
void	validate_filetype(char *filename);
void	create_copy_of_file(t_game *game, char *filename);
void    parse_file(t_game *game);
void	free_all(t_game *game);
void	check_for_path(t_game *game, int i, int *j, char **path);
void	create_textures(t_game *game);
void	create_images(t_game *game);
void	resize_images(t_game *game);
void	display_map(t_game *game);
void	controls(t_game *game);

void	raycasting(t_game *game);
void	init_ray(t_game *game);
void	determine_ray_direction(t_game *game);
void	rendering(void *content);

#endif