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
# include <math.h>

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef	struct 	s_circle {
	int		x;
	int 	y;
	int 	radius;
	int 	color;
}	t_circle;

typedef	struct	s_vars {
	void 		*mlx;
	void 		*win;
	t_data		img;
	t_circle	ball;
	int 		m_down;
}	t_vars;

void ft_b_zero(void *ptr, int size);
int		render_frame(t_vars *vars);
int		close_view(t_vars *vars);
int		get_color(unsigned char t, unsigned char r,
	unsigned char g, unsigned char b);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	make_circle(t_data *img, t_circle *ball);
int		move_ball(int keycode, t_vars *vars);
int		mouse_zoom(int mouse_code, int x, int y, t_vars *vars);

#endif
