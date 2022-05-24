/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsused_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leferrei <leferrei@student.42lisboa>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 17:40:37 by leferrei          #+#    #+#             */
/*   Updated: 2022/05/24 17:40:39 by leferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


//void	make_circle(t_data *img, t_atts *ball)
//{
//	int x2;
//	int y2;
//
//	y2 = 0;
//	x2 = 0;
//	while (y2++ < ball->radius * 2)
//	{
//		while (x2++ < ball->radius * 2)
//			if (pow(y2 - ball->radius, 2) + pow(x2 - ball->radius, 2) < pow(ball->radius, 2))
//				my_mlx_pixel_put(img, x2 + ball->x , y2 + ball->y, ball->color);
//		x2 = 0;
//	}
//}

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

//int set_coords(int x, int y, t_vars *vars)
//{
//	x = x - vars->atts.offset_x;
//	y = y - vars->ball.radius;
//	if (vars->m_down && x > 0 && x < 1080 - 2 * vars->ball.radius
//		&& y > 0 && y < 1080 - 2 * vars->ball.radius)
//	{
//		vars->ball.x = x;
//		vars->ball.y = y;
//	}
//	return 0;
//}

//int m_up(int a, int b, int c, t_vars *vars)
//{
//	//ft_printf("a = %d, b = %d, c = %d, d = %d, m_down = %d\n", a, b, c, vars->m_down);
//	while (a || b || c)
//		break ;
//	ft_printf("mouse up\n");
//	vars->m_down = 0;
//	return 0;
//}