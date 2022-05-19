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

#include "mlx/mlx.h"
#include "ft_printf/ft_printf.h"
#include <math.h>

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
	t_data		bimg;
	t_circle	ball;
}	t_vars;

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

void	make_circle(t_data *img, t_circle *ball)
{
	int x2;
	int y2;

	y2 = 0;
	x2 = 0;
	while (y2++ < ball->radius * 2)
	{
		while (x2++ < ball->radius * 2)
			if (pow(y2 - ball->radius, 2) + pow(x2 - 100, 2) < pow(100, 2))
				my_mlx_pixel_put(img, x2 + ball->x , y2 + ball->y, ball->color);
		x2 = 0;
	}
}

int get_codes(int keycode, t_vars *vars)
{
	static int index = 0;
	char *legend[8] = {"up", "down", "left", "right", "enter", "escape", "+", "-"};
	if (index < 8)
	{
		ft_printf("Key: %s	|	", legend[index++]);
		ft_printf("Keycode: %d\n", keycode);
		return (0);
	}
	if (keycode == 530)
		mlx_destroy_window(vars->mlx, vars->win);
	return (0);
}

int render_frame(t_vars *vars)
{
	ft_printf("got here");
	mlx_clear_window(vars->mlx, vars->win);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->bimg.img, 0, 0);
	make_circle(&vars->img, &vars->ball);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, 0, 0);
	return (0);
}

int move_ball(int keycode, t_vars *vars)
{
	if (keycode == 126 && vars->ball.y > 0 && (ft_printf("moved U\n")))
		vars->ball.y -= 25;
	else if (keycode == 125 && vars -> ball.y < 1080 - 2 * vars->ball.radius
		&& (ft_printf("moved D\n")))
		vars->ball.y += 25;
	else if (keycode == 123 && vars->ball.x > 0 && (ft_printf("moved L\n")))
		vars->ball.x -= 25;
	else if (keycode == 124 && vars -> ball.x < 1080 - 2 * vars->ball.radius
	&& (ft_printf("moved R\n")))
		vars->ball.x += 25;
	return (0);
}

int	main(void) {
	t_vars	vars;
	int y;
	int x;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1080, 1080, "fract-ol");
	vars.ball.radius = 100;
	vars.ball.x = 440;
	vars.ball.y = 440;
	vars.ball.color = get_color(0, 255, 255, 255);
	vars.img.img = mlx_new_image(vars.mlx, 1080, 1080);
	vars.img.addr = mlx_get_data_addr(vars.img.img, &vars.img.bits_per_pixel,
									   &vars.img.line_length, &vars.img.endian);
	mlx_key_hook(vars.win, &move_ball, &vars);
	vars.bimg.img = mlx_new_image(vars.mlx, 1080, 1080);
	vars.bimg.addr = mlx_get_data_addr(vars.bimg.img, &vars.bimg.bits_per_pixel,
			&vars.bimg.line_length, &vars.bimg.endian);
	y = 0;
	while (y++ < 1080)
	{
		x = 0;
		while (x++ < 1080)
			my_mlx_pixel_put(vars.bimg.img, x, y, 0x00FFFFFF);
	}


	mlx_loop_hook(vars.mlx, &render_frame, &vars);

	mlx_loop(vars.mlx);
}
