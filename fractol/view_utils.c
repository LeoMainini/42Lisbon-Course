/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leferrei <leferrei@student.42lisboa>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 15:17:44 by leferrei          #+#    #+#             */
/*   Updated: 2022/05/23 15:17:46 by leferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	get_color(unsigned char t, unsigned char r,
		unsigned char g, unsigned char b)
{
	int	color;

	((unsigned char *)&color)[0] = b;
	((unsigned char *)&color)[1] = g;
	((unsigned char *)&color)[2] = r;
	((unsigned char *)&color)[3] = t;
	return (color);
}

void	ft_b_zero(void *ptr, int size)
{
	int	i;

	i = 0;
	while (i++ < size)
		((char *)ptr)[i] = 0;
}

int	render_frame(t_vars *vars)
{
	int	x;
	int	y;

	y = 0;
	while (y++ <= SIZE)
	{
		x = 0;
		while (x++ <= SIZE)
			my_mlx_pixel_put(&vars->img, x - 1, y - 1, lerp(0x00140f00,
					0x00FFE222, (double)vars->fractol_eq(x - 1, y - 1,
						&vars->atts) / vars->atts.itterations));
	}
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, 0, 0);
	return (0);
}

int	close_view(t_vars *vars)
{
	mlx_destroy_image(vars->mlx, vars->img.img);
	mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_display(vars->mlx);
	free(vars->mlx);
	_exit(0);
}
