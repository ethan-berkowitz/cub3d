/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlehtone <jlehtone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 17:07:57 by eberkowi          #+#    #+#             */
/*   Updated: 2025/01/24 09:41:04 by jlehtone         ###   ########.fr       */
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
# define WINDOW_WIDTH 1920
# define WINDOW_HEIGHT 1080
# define MAX_WIDTH_IN_TILES 30
# define MAX_HEIGHT_IN_TILES 16
# define MOVE_SIZE 14
# define MOVE_SPEED 4
# define PI 3.14159265358979323846
# define FOV (60 * (PI / 180))
# define ROTATE_SPEED 0.02 // a random value for testing
// # define MAP_WIDTH 720 // can be changed
// # define MAP_HEIGHT 480 // can be changed

# define FORWARD 0
# define RIGHT (PI / 2)
# define BACK PI
# define LEFT (3 * PI / 2)

# define NORTH LEFT
# define EAST FORWARD
# define SOUTH RIGHT
# define WEST BACK

# define FLOOR_RGB 100
# define CEILING_RGB 101

typedef struct s_ray
{
    float	x;
	float	y;
	float	hx;
	float	hy;
	float	vx;
	float	vy;
    float	angle;
	double	length;
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
    float 			angle;
	float			initial_direction;
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
    int		floor_R;
	int		floor_G;
	int		floor_B;
    int		ceiling_R;
	int		ceiling_G;
	int		ceiling_B;
	int		found_floor_rgb;
	int		found_ceiling_rgb;
	float	starting_direction;
	mlx_t				*mlx;
	mlx_texture_t		*wall_texture;
	mlx_image_t			*wall_img;
	mlx_texture_t		*floor_texture;
	mlx_image_t			*floor_img;
	mlx_texture_t		*player_texture;
	mlx_image_t			*minimap_img;
	struct s_player		player;
	int window_width;
	int window_height;
	int width_in_tiles;
	int height_in_tiles;
	struct s_ray		ray;
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
bool	controls(t_game *game);
void 	draw_line(t_game *game);
void 	clear_line(t_game *game);
// raycasting functions
void	raycasting(t_game *game);
void	determine_ray_direction(t_game *game);
void	determine_player_direction(t_game *game);
void	reset_angles(t_game *game);
void	choose_shorter_distance(t_game *game, double h_inter, double v_inter);
// main loops
void	rendering(void *content);
// checks
bool	is_wall(t_game *game, int x, int y);
bool	is_wall_float(t_game *game, float x, float y);

void 	check_for_rgb(t_game *game, int i, int *j, int element);
void	copy_map(t_game *game, char **file);
void	validate_map(t_game *game);

#endif