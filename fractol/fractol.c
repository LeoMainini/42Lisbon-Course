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

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char *dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

unsigned int get_color(unsigned char t, unsigned char r,
		unsigned char g, unsigned char b)
{
	unsigned int	color;
	((unsigned char *)&color)[0] = b;
	((unsigned char *)&color)[1] = g;
	((unsigned char *)&color)[2] = r;
	((unsigned char *)&color)[3] = t;
	ft_printf("color = %u", color);
	return (color);
}

void	make_circle(t_data *img, int radius, int y, int x)
{
	int x2;
	int y2;
	
	y2 = 0;
	x2 = 0;
	while (y2++ < radius * 2)
	{
		while (x2++ < radius * 2)
			if (pow(y2 - 100, 2) + pow(x2 - 100, 2) < pow(100, 2))
				my_mlx_pixel_put(img, x2 + x , y2 + y, get_color(0, 0, 255, 0));
		x2 = 0;
	}

}
int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1080, 1080, "fract-ol");
	img.img = mlx_new_image(mlx, 1080, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel,
		&img.line_length, &img.endian);
	make_circle(&img, 100, 440, 440);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	
	mlx_loop(mlx);

}
