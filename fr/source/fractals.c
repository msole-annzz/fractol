/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msole <msole@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 19:29:42 by msole             #+#    #+#             */
/*   Updated: 2020/07/10 10:44:50 by msole            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int		ft_julia(t_fract *fractol, double x, double y)
{
	double	x_tmp;
	int		deep;

	x_tmp = x;
	deep = 0;
	x = x * x - y * y + fractol->xmouse;
	y = fractol->ymouse + 2 * y * x_tmp;
	while (x * x + y * y < 4 && deep < fractol->deep)
	{
		x_tmp = x;
		x = x * x - y * y + fractol->xmouse;
		y = fractol->ymouse + 2 * y * x_tmp;
		deep++;
	}
	return (deep);
}

void	ft_cycling_newton5(t_fract *fractol)
{
	double p;

	fractol->x_tmp = fractol->x;
	fractol->x2 = fractol->x * fractol->x;
	fractol->y2 = fractol->y * fractol->y;
	fractol->sum_x2_y2 = fractol->x2 + fractol->y2;
	fractol->pr_sum_x2_y2 = fractol->sum_x2_y2 * fractol->sum_x2_y2;
	p = fractol->pr_sum_x2_y2 * fractol->pr_sum_x2_y2;
	fractol->x = (4 * fractol->x) / 5 - (fractol->x2 * fractol->x2 + \
	fractol->y2 * fractol->y2 - 6 * fractol->x2 * fractol->y2) / (5 * p);
	fractol->y = (4 * fractol->y) / 5 + (4 * fractol->x_tmp * fractol->x_tmp *\
	fractol->x_tmp * fractol->y) / (5 * p) - \
	(4 * fractol->x_tmp * fractol->y * fractol->y2) / (5 * p);
}

int		ft_newton(t_fract *fractol, double x, double y)
{
	int deep;

	deep = 0;
	fractol->x_tmp = x;
	fractol->x = x;
	fractol->y = y;
	ft_cycling_newton5(fractol);
	while (fractol->x * fractol->x + fractol->y * fractol->y < 100000 &&\
			deep < fractol->deep)
	{
		ft_cycling_newton5(fractol);
		deep++;
	}
	return (deep);
}

int		ft_mandelbrot(t_fract *fractol, double x, double y)
{
	double	x_tmp;
	int		deep;

	x_tmp = x;
	deep = 0;
	x = x * x - y * y + fractol->cur_point.re;
	y = fractol->cur_point.im + 2 * y * x_tmp;
	while (x * x + y * y < 4 && deep < fractol->deep)
	{
		x_tmp = x;
		x = x * x - y * y + fractol->cur_point.re;
		y = fractol->cur_point.im + 2 * y * x_tmp;
		deep++;
	}
	return (deep);
}

int		fish(t_fract *fractol, double x, double y)
{
	double	x_tmp;
	int		deep;

	x_tmp = x;
	deep = 0;
	x = fabs(x * x - y * y) + fractol->cur_point.re;
	y = fractol->cur_point.im + 2 * y * x_tmp;
	while (x * x + y * y < 4 && deep < fractol->deep)
	{
		x_tmp = x;
		x = fabs(x * x - y * y) + fractol->cur_point.re;
		y = fractol->cur_point.im + 2 * y * x_tmp;
		deep++;
	}
	return (deep);
}
