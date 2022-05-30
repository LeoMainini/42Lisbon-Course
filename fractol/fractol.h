/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leferrei <leferrei@student.42lisboa>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 15:18:52 by leferrei          #+#    #+#             */
/*   Updated: 2022/05/23 15:24:12 by leferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "mlx/mlx.h"
# include "ft_printf/ft_printf.h"
# include <unistd.h>
# include <stdlib.h>
# include <math.h>

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_attributes {
	double		scale;
	double		offset_x;
	double		offset_y;
	int			itterations;
	int			x;
	int			y;
	double		ax;
	double		ay;
}	t_atts;

typedef struct s_vars {
	void		*mlx;
	void		*win;
	t_data		img;
	t_atts		atts;
	int			m_down;
	int			(*fractol_eq)(int, int, t_atts *);
}	t_vars;

# ifndef SIZE
#  define SIZE 800
# endif

void	ft_b_zero(void *ptr, int size);
int		render_frame(t_vars *vars);
int		close_view(t_vars *vars);
int		get_color(unsigned char t, unsigned char r,
			unsigned char g, unsigned char b);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	make_circle(t_data *img, t_atts *ball);
int		move_ball(int keycode, t_vars *vars);
int		mouse_zoom(int mouse_code, int x, int y, t_vars *vars);
int		iterate_mandel(t_atts *atts, double *ax, double *ay);
int		lerp(int c1, int color2, double t);
int		mandelbrot(int x, int y, t_atts *atts);
int		kb_interaction(int keycode, t_vars *vars);
int		mouse_zoom(int mouse_code, int x, int y, t_vars *vars);
int		juilia(int x, int y, t_atts *atts);

#endif
