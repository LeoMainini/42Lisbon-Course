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

void	make_circle(t_data *img, t_circle *ball)
{
	int x2;
	int y2;

	y2 = 0;
	x2 = 0;
	while (y2++ < ball->radius * 2)
	{
		while (x2++ < ball->radius * 2)
			if (pow(y2 - ball->radius, 2) + pow(x2 - ball->radius, 2) < pow(ball->radius, 2))
				my_mlx_pixel_put(img, x2 + ball->x , y2 + ball->y, ball->color);
		x2 = 0;
	}
}

//int get_codes(int keycode, t_vars *vars)
//{
//	static int index = 0;
//	char *legend[8] = {"up", "down", "left", "right", "enter", "escape", "+", "-"};
//	if (index < 8)
//	{
//		ft_printf("Key: %s	|	", legend[index++]);
//		ft_printf("Keycode: %d\n", keycode);
//		return (0);
//	}
//	if (keycode == 530)
//		mlx_destroy_window(vars->mlx, vars->win);
//	return (0);
//}



int move_ball(int keycode, t_vars *vars)
{
	if (keycode == 126 && vars->ball.y > 0 && (ft_printf("moved U\n")))
		vars->ball.y -= 20;
	else if (keycode == 125 && vars -> ball.y < 1080 - 2 * vars->ball.radius
			 && (ft_printf("moved D\n")))
		vars->ball.y += 20;
	else if (keycode == 123 && vars->ball.x > 0 && (ft_printf("moved L\n")))
		vars->ball.x -= 20;
	else if (keycode == 124 && vars->ball.x < 1080 - 2 * vars->ball.radius
			 && (ft_printf("moved R\n")))
		vars->ball.x += 20;
	else if (keycode == 53)
		close_view(vars);
	else if (keycode == 69 && vars->ball.radius < 200)
		vars->ball.radius += 20;
	else if (keycode == 78 && vars->ball.radius > 20)
		vars->ball.radius -= 20;
	return (0);
}

int set_coords(int x, int y, t_vars *vars)
{
	//ft_printf("x = %d, y = %d\n, ball_x = %d, ball_y = %d",
		//   x, y, vars->ball.x, vars->ball.y);
	x = x - vars->ball.radius;
	y = y - vars->ball.radius;
	if (vars->m_down && x > 0 && x < 1080 - 2 * vars->ball.radius
		&& y > 0 && y < 1080 -2 * vars->ball.radius)
	{

		vars->ball.x = x;
		vars->ball.y = y;
	}
	return 0;
}

int mouse_zoom(int mouse_code, int x, int y, t_vars *vars)
{
	//ft_printf("x = %d, y = %d\n", x, y);

	if (mouse_code == 4 && vars->ball.radius < 200
		&& vars->ball.x + ((vars->ball.radius + 20) * 2) <= 1080
		&& vars->ball.y + ((vars->ball.radius + 20) * 2) <= 1080)
		vars->ball.radius += 20;
	else if (mouse_code == 5 && vars->ball.radius > 20)
		vars->ball.radius -= 20;
	else if (mouse_code == 1 && ft_printf("mouse down\n"))
	{
		vars->m_down = 1;
		set_coords(x, y, vars);
	}
	return (0);
}

int m_up(int a, int b, int c, t_vars *vars)
{
	//ft_printf("a = %d, b = %d, c = %d, d = %d, m_down = %d\n", a, b, c, vars->m_down);
	while (a || b || c)
		break ;
	ft_printf("mouse up\n");
	vars->m_down = 0;
	return 0;
}

int	main(void) {
	t_vars	vars;


	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1080, 1080, "fract-ol");
	vars.ball.radius = 100;
	vars.ball.x = 440;
	vars.ball.y = 440;
	vars.ball.color = get_color(0, 255, 255, 255);
	vars.img.img = mlx_new_image(vars.mlx, 1080, 1080);
	vars.img.addr = mlx_get_data_addr(vars.img.img, &vars.img.bits_per_pixel,
									   &vars.img.line_length, &vars.img.endian);
	vars.m_down = 0;
	mlx_hook(vars.win, 2, 0, &move_ball, &vars);
	mlx_hook(vars.win, 6, 0, &set_coords, &vars);
	mlx_hook(vars.win, 5, 0, &m_up, &vars);
	mlx_hook(vars.win, 17, 0, close_view, &vars);
	mlx_mouse_hook(vars.win, &mouse_zoom, &vars);
	mlx_loop_hook(vars.mlx, &render_frame, &vars);

	mlx_loop(vars.mlx);
}
