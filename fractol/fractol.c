/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leferrei <leferrei@student.42lisboa>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 15:13:07 by leferrei          #+#    #+#             */
/*   Updated: 2022/05/17 18:12:42 by leferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(void)
{
	t_vars	vars;

	ft_printf("test\n");
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1080, 1080, "fract-ol");
	vars.img.img = mlx_new_image(vars.mlx, 1080, 1080);
	vars.img.addr = mlx_get_data_addr(vars.img.img, &vars.img.bits_per_pixel,
			&vars.img.line_length, &vars.img.endian);
	vars.atts.itterations = 100;
	vars.atts.offset_x = -2.5;
	vars.atts.offset_y = -2;
	vars.atts.scale = 4;
	mlx_hook(vars.win, 2, 0, &kb_interaction, &vars);
	mlx_hook(vars.win, 17, 0, close_view, &vars);
	mlx_mouse_hook(vars.win, &mouse_zoom, &vars);
	mlx_loop_hook(vars.mlx, &render_frame, &vars);
	mlx_loop(vars.mlx);
}
