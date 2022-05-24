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

int	kb_interaction(int keycode, t_vars *vars)
{
	if (keycode == 126 && vars->atts.offset_y > -3)
		vars->atts.offset_y -= (double)50 * vars->atts.scale / 1080;
	else if (keycode == 125 && vars->atts.offset_y < 3)
		vars->atts.offset_y += (double)50 * vars->atts.scale / 1080;
	else if (keycode == 123 && vars->atts.offset_x > -3)
		vars->atts.offset_x -= (double)50 * vars->atts.scale / 1080;
	else if (keycode == 124 && vars->atts.offset_x < 3)
		vars->atts.offset_x += (double)50 * vars->atts.scale / 1080;
	else if (keycode == 53)
		close_view(vars);
	else if (keycode == 78 && vars->atts.scale < 6)
		vars->atts.scale *= 1.2;
	else if (keycode == 69)
		vars->atts.scale *= 0.8;
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
	else if (mouse_code == 1 && ft_printf("mouse down\n"))
	{
		vars->m_down = 1;
	}
	return (0);
}
