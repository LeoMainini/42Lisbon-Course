/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_gens.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leferrei <leferrei@student.42lisboa>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 18:08:29 by leferrei          #+#    #+#             */
/*   Updated: 2022/05/24 18:08:33 by leferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	iterate_mandel(t_atts *atts, double *ax, double *ay)
{
	int		i;
	double	sx;
	double	sy;
	double	temp;

	sy = (((double)atts->y / 1080) * atts->scale) + atts->offset_y;
	sx = (((double)atts->x / 1080) * atts->scale) + atts->offset_x;
	i = -1;
	while (++i < atts->itterations)
	{
		temp = *ax * *ax - *ay * *ay + sx;
		*ay = 2 * *ax * *ay + sy;
		*ax = temp;
		if (*ax * *ax + *ay * *ay >= 4)
			return (i);
	}
	if (i >= atts->itterations)
		return (0);
	return (i);
}

int	mandelbrot(int x, int y, t_atts *atts)
{
	double	ax;
	double	ay;

	atts->x = x;
	atts->y = y;
	ax = 0.0;
	ay = 0.0;
	return (iterate_mandel(atts, &ax, &ay));
}

int	iterate_juilia(t_atts *atts, double *ax, double *ay)
{
	int		i;
	double	sx;
	double	sy;
	double	temp;

	sy = (((double)atts->y / 1080) * atts->scale) + atts->offset_y;
	sx = (((double)atts->x / 1080) * atts->scale) + atts->offset_x;
	i = -1;
	while (++i < atts->itterations)
	{
		temp = sx * sx - sy * sy ;
		sy = 2.0 * sx * sy + *ay;
		sx = temp + *ax;
		if (sx * sx + sy * sy > 4)
			return (i);
	}
	if (i >= atts->itterations)
		return (0);
	return (i);
}

int	juilia(int x, int y, t_atts *atts)
{
	double	ax;
	double	ay;

	atts->x = x;
	atts->y = y;
	ax = 0.28;
	ay = 0.5;
	return (iterate_juilia(atts, &ax, &ay));
}

int	lerp(int c1, int c2, double t)
{
	int	result;

	result = get_color(((c1 >> 24) + ((c2 >> 24) - ((c1 >> 24))) * t),
			((c1 >> 16 & 0xff) + ((c2 >> 16 & 0xff) - ((c1 >> 16 & 0xff))) * t),
			((c1 >> 8 & 0xff) + ((c2 >> 8 & 0xff) - ((c1 >> 8 & 0xff))) * t),
			((c1 & 0xff) + ((c2 & 0xff) - ((c1 & 0xff))) * t)
			);
	return (result);
}
