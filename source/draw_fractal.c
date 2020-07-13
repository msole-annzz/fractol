/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_fractal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msole <msole@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 19:29:30 by msole             #+#    #+#             */
/*   Updated: 2020/07/10 10:56:45 by msole            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	ft_put_pixel(t_fract *fractol, int deep, int i, int j)
{
	int		p;
	double	tone;

	tone = (double)deep / fractol->deep;
	p = 4 * (WIN_WIDTH * j + i);
	if (deep == fractol->deep)
	{
		fractol->image.data[p] = 0x00;
		fractol->image.data[p + 1] = 0x00;
		fractol->image.data[p + 2] = 0x00;
	}
	else
	{
		ft_colours(fractol, p, tone, deep);
	}
}

int		fractal_type(t_fract *fractol)
{
	int		deep;

	deep = 0;
	deep = (fractol->type == 1) ? ft_mandelbrot(fractol, 0, 0) : deep;
	deep = (fractol->type == 2) ? ft_julia(fractol,\
			fractol->cur_point.re, fractol->cur_point.im) : deep;
	deep = (fractol->type == 3) ? ft_newton(fractol,\
			fractol->cur_point.re, fractol->cur_point.im) : deep;
	deep = (fractol->type == 4) ? fish(fractol, 0, 0) : deep;
	deep = (fractol->type == 5) ? triangle(fractol, 0, 0) : deep;
	deep = (fractol->type == 6) ? jellyfish(fractol, 0, 0) : deep;
	deep = (fractol->type == 7) ? bust(fractol, 0, 0) : deep;
	deep = (fractol->type == 8) ? goblet_of_fire(fractol, 0, 0) : deep;
	deep = (fractol->type == 9) ? symmetry(fractol,\
			fractol->cur_point.re, fractol->cur_point.im) : deep;
	return (deep);
}

void	*ft_draw_picture(void *thread_data)
{
	int		i;
	int		j;
	int		deep;
	t_fract	*fractol;

	fractol = (t_fract *)(thread_data);
	deep = 0;
	i = fractol->thread_min_width;
	j = 0;
	while (j < WIN_HEIGHT)
	{
		while (i < fractol->thread_max_width)
		{
			ft_conv2compl(i, j, fractol);
			deep = fractal_type(fractol);
			ft_put_pixel(fractol, deep, i, j);
			i++;
		}
		i = fractol->thread_min_width;
		j++;
	}
	return (thread_data);
}

void	ft_threads(t_fract *fractol)
{
	int			i;
	pthread_t	threads[THREAD];
	t_fract		thread_data[THREAD];

	i = 0;
	while (i < THREAD)
	{
		ft_memcpy((void *)&thread_data[i], (void *)fractol, sizeof(t_fract));
		thread_data[i].thread_min_width = ((double)(WIN_WIDTH / THREAD)) * i;
		thread_data[i].thread_max_width = \
		((double)(WIN_WIDTH / THREAD)) * (i + 1);
		i = i + 1;
	}
	i = 0;
	while (i < THREAD)
	{
		pthread_create(&(threads[i]), NULL, ft_draw_picture, &thread_data[i]);
		i = i + 1;
	}
	while (i--)
		pthread_join(threads[i], NULL);
	mlx_put_image_to_window(fractol->mlx.init,\
							fractol->mlx.win, fractol->mlx.img, 0, 0);
	ft_legend(fractol);
}
