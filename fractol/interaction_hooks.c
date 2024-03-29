/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interation_hooks.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leferrei <leferrei@student.42lisboa>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 18:11:31 by leferrei          #+#    #+#             */
/*   Updated: 2022/05/24 18:11:32 by leferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	juilia_control(int keycode, t_vars *vars, int *itts)
{
	if (keycode == PLUS && vars->atts.ax < 1 && vars->atts.ay < 1)
	{
		vars->atts.ay += 0.005;
		vars->atts.ax += 0.005;
	}
	if (keycode == MINUS && vars->atts.ax > -1 && vars->atts.ay > -1)
	{
		vars->atts.ay -= 0.005;
		vars->atts.ax -= 0.005;
	}
	else if (keycode == PGUP && ft_printf("Iterations = %d\n", (*itts) + 1))
		*itts += 1;
	else if (keycode == PGDN && ft_printf("Iterations = %d\n", (*itts) - 1))
		*itts -= 1;
}

int	kb_interaction(int keycode, t_vars *vars)
{
	if (keycode == UP_ARROW && vars->atts.offset_y > -3)
		vars->atts.offset_y -= (double)50 * vars->atts.scale / SIZE;
	else if (keycode == DN_ARROW && vars->atts.offset_y < 3)
		vars->atts.offset_y += (double)50 * vars->atts.scale / SIZE;
	else if (keycode == L_ARROW && vars->atts.offset_x > -3)
		vars->atts.offset_x -= (double)50 * vars->atts.scale / SIZE;
	else if (keycode == R_ARROW && vars->atts.offset_x < 3)
		vars->atts.offset_x += (double)50 * vars->atts.scale / SIZE;
	else if (keycode == ESC)
		close_view(vars);
	else if (keycode == MINUS && vars->atts.scale < 6
		&& vars->fractol_eq == &mandelbrot)
		vars->atts.scale *= 1.2;
	else if (keycode == PLUS && vars->fractol_eq == &mandelbrot)
		vars->atts.scale *= 0.8;
	else
		juilia_control(keycode, vars, &vars->atts.itterations);
	return (0);
}

int	mouse_zoom(int mouse_code, int x, int y, t_vars *vars)
{
	while (x || y)
		break ;
	if (mouse_code == 4)
		vars->atts.scale *= 0.95;
	else if (mouse_code == 5 && vars->atts.scale < 6)
		vars->atts.scale *= 1.05;
	else if (mouse_code == 1)
	{
		vars->m_down = 1;
	}
	return (0);
}
