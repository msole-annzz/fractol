/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msole <msole@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 19:29:19 by msole             #+#    #+#             */
/*   Updated: 2020/08/06 18:18:28 by msole            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

// double	ft_x2compl(int x, t_fract *fractol)
// {
// 	return (fractol->dx * (x - WIN_WIDTH / 2 - fractol->xmove));
// }

// double	ft_y2compl(int y, t_fract *fractol)
// {
// 	return (fractol->dy * (y - WIN_HEIGHT / 2 - fractol->ymove));
// }

void	ft_conv2compl(int x, int y, t_fract *fractol)
{
	fractol->len_x = fractol->re_max - fractol->re_min;
	fractol->len_y = fractol->im_max - fractol->im_min;

	fractol->dx = fractol->len_x / (double)WIN_WIDTH;
	fractol->dy = fractol->len_y / (double)WIN_HEIGHT;
	//fractol->cur_point.re = fractol->dx * (x - WIN_WIDTH / 2);
	//fractol->cur_point.im = fractol->dy * (WIN_HEIGHT / 2 - y);

	fractol->cur_point.re = fractol->re_min + fractol->dx * x;
	fractol->cur_point.im = fractol->im_max - fractol->dy * y;

	//fractol->cur_point.re = fractol->re_min + fractol->dx * (x - WIN_WIDTH / 2);
	//fractol->cur_point.im = fractol->im_max - fractol->dy * (WIN_HEIGHT / 2 - y);

	//fractol->cur_point.re = (fractol->re_max/(double)WIN_WIDTH) * (x - WIN_WIDTH / 2) - ((fractol->re_min/(double)WIN_WIDTH) * (x - WIN_WIDTH / 2));
	//fractol->cur_point.im = (fractol->im_max/(double)WIN_HEIGHT) * (y - WIN_HEIGHT / 2) - ((fractol->im_min/(double)WIN_HEIGHT) * (y - WIN_HEIGHT / 2));
}
/*
double	ft_x2compl(int x, t_fract *fractol)
{
	return (fractol->dx * (x - WIN_WIDTH / 2 - fractol->xmove));
}

double	ft_y2compl(int y, t_fract *fractol)
{
	return (fractol->dy * (y - WIN_HEIGHT / 2 - fractol->ymove));
}

void	ft_conv2compl(int x, int y, t_fract *fractol)
{
	fractol->cur_point.re = ft_x2compl(x, fractol);
	fractol->cur_point.im = ft_y2compl(y, fractol);
}
*/
