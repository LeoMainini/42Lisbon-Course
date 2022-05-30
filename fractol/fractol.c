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

//#TODO: add juilia value interation with keys
//#TODO: add menu for fractol selection

int	fractol(t_vars vars)
{
	ft_printf(("---\tCHEAT-SHEET\t---\n -> Use mouse-wheel and +- to zoom"
			", juilia set uses +- to change calculation coordenates\n -> "
			"Use page up and down to change number of iterations to calculate"
			"\n -> Use arrows to move\n -> Esc exits the program\n"));
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, SIZE, SIZE, "fract-ol");
	vars.img.img = mlx_new_image(vars.mlx, SIZE, SIZE);
	vars.img.addr = mlx_get_data_addr(vars.img.img, &vars.img.bits_per_pixel,
			&vars.img.line_length, &vars.img.endian);
	mlx_hook(vars.win, 2, 0, &kb_interaction, &vars);
	mlx_hook(vars.win, 17, 0, close_view, &vars);
	mlx_mouse_hook(vars.win, &mouse_zoom, &vars);
	mlx_loop_hook(vars.mlx, &render_frame, &vars);
	mlx_loop(vars.mlx);
	return (0);
}

void	prompt(int count, char **options, t_vars *vars)
{
	if (count < 2)
		ft_printf("No options selected, available options are:\n\n"
			"\t1. Mandelbrot\n\t2. Juilia\n\t3. Help\n");
	else if (count < 3 && options[1][0] == '1' && options[1][1] == '\0'
		&& ft_printf("Mandelbrot set chosen.\n"))
		vars->fractol_eq = &mandelbrot;
	else if (count < 3 && options[1][0] == '2' && options[1][1] == '\0'
		&& ft_printf("Juilia set chosen.\n"))
		vars->fractol_eq = &juilia;
	else if (count < 3 && options[1][0] == '3' && options[1][1] == '\0'
		&& ft_printf("Help menu:\n"))
		ft_printf(" -> Available options:\n\t-> 1. Mandelbrot set\n\t->"
			" 2. Juilia set\n\t-> 3. Help\n");
	else
		ft_printf("Option not recognized, please see help.\n");
}

int	main(int argc, char **argv)
{
	t_vars	vars;

	vars.fractol_eq = 0;
	vars.atts.itterations = 40;
	vars.atts.scale = 4;
	prompt(argc, argv, &vars);
	if (vars.fractol_eq == &juilia)
	{
		vars.atts.offset_x = -2.0;
		vars.atts.offset_y = -2.0;
		vars.atts.ax = -0.53;
		vars.atts.ay = -0.53;
	}
	else if (vars.fractol_eq == &mandelbrot)
	{
		vars.atts.offset_x = -2.5;
		vars.atts.offset_y = -2.0;
	}
	if (vars.fractol_eq)
		fractol(vars);
	return (0);
}
