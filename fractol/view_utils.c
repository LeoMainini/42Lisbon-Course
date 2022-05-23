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
	char *dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int get_color(unsigned char t, unsigned char r,
			  unsigned char g, unsigned char b)
{
	int	color;
	((unsigned char *)&color)[0] = b;
	((unsigned char *)&color)[1] = g;
	((unsigned char *)&color)[2] = r;
	((unsigned char *)&color)[3] = t;
	return (color);
}

void ft_b_zero(void *ptr, int size)
{
	int i;

	i = 0;
	while (i++ < size)
		((char *)ptr)[i] = 0;
}

int render_frame(t_vars *vars)
{
	//ft_printf("got here");
	ft_b_zero(vars->img.addr, 1080 * vars->img.line_length + 1080 * (vars->img.bits_per_pixel / 8));
	make_circle(&vars->img, &vars->ball);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, 0, 0);
	return (0);
}

int close_view(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	_exit(0);
}