/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msole <msole@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 19:29:19 by msole             #+#    #+#             */
/*   Updated: 2020/07/08 19:29:20 by msole            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

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
