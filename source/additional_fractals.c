/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additional_fractals.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msole <msole@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 19:34:17 by msole             #+#    #+#             */
/*   Updated: 2020/07/08 19:34:18 by msole            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int		symmetry(t_fract *fractol, double x, double y)
{
	double	x_tmp;
	int		deep;

	x_tmp = x;
	deep = 0;
	x = x * x - y * y + fractol->xmouse;
	y = fractol->ymouse + 2 * fabs(y) * x_tmp;
	while (x * x - y * y < 4 && deep < fractol->deep)
	{
		x_tmp = x;
		x = x * x - y * y + fractol->xmouse;
		y = fractol->ymouse + 2 * fabs(y) * x_tmp;
		deep++;
	}
	return (deep);
}

int		goblet_of_fire(t_fract *fractol, double x, double y)
{
	double	x_tmp;
	int		deep;
	double	x10;
	double	y10;

	x10 = x * x * x * x * x * x * x * x * x * x;
	y10 = y * y * y * y * y * y * y * y * y * y;
	x_tmp = x;
	deep = 0;
	x = x10 - y10 + fractol->cur_point.re;
	y = fractol->cur_point.im - 2 * y * x_tmp;
	while (x10 + y10 < 100 && deep < fractol->deep)
	{
		x_tmp = x;
		x10 = x * x * x * x * x * x * x * x * x * x;
		y10 = y * y * y * y * y * y * y * y * y * y;
		x = x10 - y10 + fractol->cur_point.re;
		y = fractol->cur_point.im - 2 * y * x_tmp;
		deep++;
	}
	return (deep);
}

int		bust(t_fract *fractol, double x, double y)
{
	double	x_tmp;
	int		deep;

	x_tmp = x;
	deep = 0;
	x = x * x * x * x - y * y * y * y + fractol->cur_point.re;
	y = fractol->cur_point.im + 2 * y * x_tmp;
	while (x * x + y * y < 4 && deep < fractol->deep)
	{
		x_tmp = x;
		x = x * x * x * x - y * y * y * y + fractol->cur_point.re;
		y = fractol->cur_point.im + 2 * y * x_tmp;
		deep++;
	}
	return (deep);
}

int		jellyfish(t_fract *fractol, double x, double y)
{
	double	x_tmp;
	int		deep;

	x_tmp = x;
	deep = 0;
	x = fabs(x * x - y * y) + fractol->cur_point.re;
	y = fractol->cur_point.im - 2 * y * x_tmp;
	while (x * x + y * y < 4 && deep < fractol->deep)
	{
		x_tmp = x;
		x = fabs(x * x - y * y) + fractol->cur_point.re;
		y = fractol->cur_point.im - 2 * y * x_tmp;
		deep++;
	}
	return (deep);
}

int		triangle(t_fract *fractol, double x, double y)
{
	double	x_tmp;
	int		deep;

	x_tmp = x;
	deep = 0;
	x = x * x - y * y + fractol->cur_point.re;
	y = fractol->cur_point.im - 2 * y * x_tmp;
	while (x * x + y * y < 4 && deep < fractol->deep)
	{
		x_tmp = x;
		x = x * x - y * y + fractol->cur_point.re;
		y = fractol->cur_point.im - 2 * y * x_tmp;
		deep++;
	}
	return (deep);
}
