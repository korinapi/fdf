/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpuiu <cpuiu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 10:53:10 by cpuiu             #+#    #+#             */
/*   Updated: 2024/01/25 20:56:50 by cpuiu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <math.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "../Libft/libft.h"
# include "../mlx.h"

# define WINDOW_WIDTH 2600
# define WINDOW_HEIGHT 1800
# define PROJ_AXO 1
# define PROJ_OBLIQUE 2
# define MAXDOUBLE 100000
# define MINDOUBLE -100000
# define BUFFER_SIZE 1000

typedef struct s_mesh
{
	int		**mesh;
	double	mesh_height;
	double	mesh_width;
	int		max_point;
	int		min_point;
	double	altitude;
}t_mesh;

typedef struct s_projection
{
	double	pitch;
	double	roll;
	double	yaw;
	double	obliq;
}t_projection;

typedef struct s_margins
{
	int	x_margin;
	int	y_margin;
}t_margins;

typedef struct s_image_info
{
	void	*img;
	int		line_size;
	int		bytes_order;
	int		bytes_per_pixel;
	int		image_width;
	int		image_height;
	int		x_position;
	int		y_position;
}t_image_info;

typedef struct s_grab_info
{
	int	is_active;
	int	*grabbed_values;
	int	is_figure_grabbed;
	int	grabbed_figure_x;
	int	grabbed_figure_y;
	int	is_alternate_figure;
}t_grab_info;

typedef struct s_draw_info
{
	int	delta_x;
	int	delta_y;
	int	increment_x;
	int	increment_y;
	int	error;
	int	increment_1;
	int	increment_2;
}t_draw_info;

typedef struct s_graphics_scene
{
	t_grab_info			grab_info;
	t_mesh				*data_mesh;
	t_draw_info			drawing_info;
	int					top_color[3];
	int					bottom_color[3];
	t_image_info		image_info;
	t_projection		projection_info;
	t_margins			margins_info;
	void				*mlx;
	void				*window;
	int					start_x;
	int					end_x;
	int					start_y;
	int					end_y;
	int					start_z;
	int					end_z;
	int					projection_type;
	int					fill_mode;
	double				scaling_factor;
	double				additional_altitude;
	int					window_width;
	int					window_height;
	void				*figure_image;
}t_graphics_scene;

//errors

void	put_error(int error);
int		errors(int argc, char **argv, t_mesh **mesh);

//find minimum and maximum points 
double	min_x_axonometric(t_graphics_scene *fdf);
double	min_y_axonometric(t_graphics_scene *fdf);
double	max_x_axonometric(t_graphics_scene *fdf);
double	max_y_axonometric(t_graphics_scene *fdf);
int		max_x_obliq(t_graphics_scene *fdf);
int		min_x_obliq(t_graphics_scene *fdf);
int		max_y_obliq(t_graphics_scene *fdf);
int		min_y_obliq(t_graphics_scene *fdf);
//Bresenheim algorythm

int		draw_line_tierce(t_graphics_scene *fdf, int *data);

//colors

int		color(int red, int green, int blue);
int		gradient_color(double gradient_factor,
			int top_color, int bottom_color);
int		interpolate_color(double current_height,
			int average, t_graphics_scene *fdf);
int		standard_color_x(int x, t_graphics_scene *fdf);
int		standard_color_y(int y, t_graphics_scene *fdf);
void	color_fig_image(t_graphics_scene *fdf);
void	action_color_image(t_graphics_scene *fdf);

// drawing

void	draw_lines_axonometric(int x_index, int y_index,
			t_graphics_scene *fdf, int *data);
int		draw_line_image(t_graphics_scene *fdf, int *data);

//initialize
void	initialize_scene(t_graphics_scene *fdf);
void	initialize_params(t_graphics_scene *fdf);

//processing/ verifying/ checking map
t_mesh	*new_mesh(char *mesh_name, int *error);

//used in parsing the map
int		*ft_sub_tab(t_mesh *mesh, char **split);
int		nb_words(char *line);
void	ft_free_split(char **split);
int		get_next_line(int const fd, char **line);
//extras
int		abs(int a);
int		max(int a, int b);
int		min(int a, int b);

//interface
void	str_interface(t_graphics_scene *fdf);

void	lines_obliq_image(int x_index, int y_index,
			t_graphics_scene *fdf, int *data);

//mouse and key hooks
int		key_hook(int keycode, t_graphics_scene *fdf);
int		key(int keycode, t_graphics_scene *fdf);
int		mouse_released(int key, int x, int y, t_graphics_scene *fdf);
int		motion(int x, int y, t_graphics_scene *fdf);
int		mouse_event(int key, int x, int y, t_graphics_scene *fdf);

#endif