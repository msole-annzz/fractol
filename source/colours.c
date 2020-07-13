/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colours.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msole <msole@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 19:29:12 by msole             #+#    #+#             */
/*   Updated: 2020/07/08 19:29:13 by msole            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	blue_rainbow(t_fract *fractol, int p, double tone)
{
	fractol->image.data[p] = tone * 255 * 2.42;
	fractol->image.data[p + 1] = tone * tone * tone * 255 * 2.42;
	fractol->image.data[p + 2] = tone * tone * 255 * 2.42;
}

void	black_and_white(t_fract *fractol, int deep, int p)
{
	if (deep % 2 == 0)
	{
		fractol->image.data[p] = 0x00;
		fractol->image.data[p + 1] = 0x00;
		fractol->image.data[p + 2] = 0x00;
	}
	else
	{
		fractol->image.data[p] = 0xff;
		fractol->image.data[p + 1] = 0xff;
		fractol->image.data[p + 2] = 0xff;
	}
}

void	logorithmic(t_fract *fractol, int p, double tone)
{
	fractol->image.data[p] = 255 * log(tone * 3);
	fractol->image.data[p + 1] = 255 * log(tone);
	fractol->image.data[p + 2] = 255 * log(tone);
}

void	ft_colours(t_fract *fractol, int p, double tone, int deep)
{
	if (fractol->colour_sheme == 1)
		blue_rainbow(fractol, p, tone);
	else if (fractol->colour_sheme == 2)
		black_and_white(fractol, deep, p);
	else if (fractol->colour_sheme == 3)
		logorithmic(fractol, p, tone);
}
