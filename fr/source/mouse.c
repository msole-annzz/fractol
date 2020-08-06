/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msole <msole@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 19:30:18 by msole             #+#    #+#             */
/*   Updated: 2020/08/06 19:06:11 by msole            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

/*
**it is very important for the mouse to set x and y, otherwise sigfolt
**((mouse == 4) || (mouse == 5))//scroll up & scroll down
** 1- left key
** 2 - right key
*/

int		ft_mouse(int mouse, int x, int y, t_fract *fractol)
{
	//(void)x;
	//(void)y;
	fractol->mouse->is_press = 0;
	if ((mouse == 4) || (mouse == 5))
		ft_zoom(mouse, fractol, x, y);
	if (mouse == 1)
	{
		fractol->mouse->is_press = 1;
		fractol->mouse->previous_x = fractol->mouse->x;
		fractol->mouse->previous_y = fractol->mouse->y;
	}
	return (0);
}

int		ft_mouse_release(int mouse, int x, int y, t_fract *fractol)
{
	(void)mouse;
	(void)x;
	(void)y;
	mlx_clear_window(fractol->mlx.init, fractol->mlx.win);
	fractol->mouse->is_press = 0;
	fractol->mouse->new_x = fractol->mouse->x;
	fractol->mouse->new_y = fractol->mouse->y;
	fractol->xmove = fractol->xmove + \
			fractol->mouse->new_x - fractol->mouse->previous_x;
	fractol->ymove = fractol->ymove + \
			fractol->mouse->new_y - fractol->mouse->previous_y;
	ft_threads(fractol);
	return (0);
}
/*
double interpolate(double start, double end, double interpolation)
{
    return start + ((end - start) * interpolation);
}

void	ft_zoom(int keycode, t_fract *fractol, int x, int y)
{

	///double delta_x;
	//double delta_y;
	//double k_zoom_x;
	//double k_zoom_y;


double mouseRe = (double)x / (WIN_WIDTH / (fractol->re_max - fractol->re_min)) + fractol->re_min;
double mouseIm = (double)y / (WIN_HEIGHT / (fractol->im_max - fractol->im_min)) + fractol->im_min;

	//delta_x = fractol->len_x * 0.1;

	//delta_y = fractol->len_y * 0.1;

	//k_zoom_x = (double)x / (WIN_WIDTH - 1);
	//printf("k_zoom_x = %f\n", k_zoom_x);
	//k_zoom_y = (double)y / (WIN_HEIGHT - 1);

	if ((keycode == 4) || (keycode == KEY_ANSI_KEYPAD8))
	{
		double interpolation = 1.0 / ZOOM;
     	fractol->re_min = interpolate(mouseRe, fractol->re_min, interpolation);
     	fractol->im_min = interpolate(mouseIm, fractol->im_min, interpolation);
     	fractol->re_max = interpolate(mouseRe, fractol->re_max, interpolation);
     	fractol->im_max = interpolate(mouseIm, fractol->im_max, interpolation);
		// printf("x = %d\n", x);
		// fractol->re_min = fractol->re_min + (delta_x * k_zoom_x);
		// printf("re_min = %f\n", fractol->re_min);
		// fractol->re_max = fractol->re_min + fractol->len_x * 0.9;
		// // fractol->re_max = fractol->re_max - (delta_x * (1 - k_zoom_x));
		// printf("re_max= %f\n", fractol->re_max);
		// fractol->im_min += (delta_y * k_zoom_y);
		// fractol->im_max -= (delta_y * (1 - k_zoom_y));
		// fractol->len_x = fractol->re_max - fractol->re_min;
		// fractol->len_y = fractol->im_max - fractol->im_min;
	}
		// fractol->zoom = fractol->zoom * ZOOM;

	// if ((keycode == 5) || (keycode == KEY_ANSI_KEYPAD2))
	// 	fractol->zoom = fractol->zoom / ZOOM;
	//fractol->dx = (4 / (double)WIN_WIDTH) / fractol->zoom;
	//fractol->dy = ((double)WIN_HEIGHT / (double)WIN_WIDTH) * fractol->dx;
	ft_threads(fractol);
}

*/
//Misha

void	ft_zoom(int keycode, t_fract *fractol, int x, int y)
{

	double delta_x;
	double delta_y;
	double k_zoom_x;
	double k_zoom_y;

	k_zoom_x = (double)x / (WIN_WIDTH - 1);
	k_zoom_y = (double)y / (WIN_HEIGHT - 1);

	delta_x = fractol->len_x * 0.1;
	delta_y = fractol->len_y * 0.1;


	if (keycode == 5 && (fractol->len_x < 50 || fractol->len_y < 50))
	{
		delta_x *= -1;
		delta_y *= -1;
	}
		fractol->re_min += (delta_x * k_zoom_x);
		fractol->re_max -= delta_x * (1 - k_zoom_x);

		fractol->im_min += (delta_y * (1 - k_zoom_y));
		fractol->im_max -= (delta_y * k_zoom_y);

		fractol->len_x = fractol->re_max - fractol->re_min;
		fractol->len_y = fractol->im_max - fractol->im_min;

		// fractol->zoom = fractol->zoom * ZOOM;

	// if ((keycode == 5) || (keycode == KEY_ANSI_KEYPAD2))
	// 	fractol->zoom = fractol->zoom / ZOOM;
	//fractol->dx = (4 / (double)WIN_WIDTH) / fractol->zoom;
	//fractol->dy = ((double)WIN_HEIGHT / (double)WIN_WIDTH) * fractol->dx;
	ft_threads(fractol);
}


int		ft_mouse_move(int x, int y, t_fract *fractol)
{
	fractol->mouse->x = x;
	fractol->mouse->y = y;
	if ((x > 0 && y > 0) && (x < WIN_WIDTH && y < WIN_HEIGHT))
	{
		// ft_conv2compl(x, y, fractol);
		fractol->xmouse = fractol->dx * (x - WIN_WIDTH / 2);
		fractol->ymouse = fractol->dy * (WIN_HEIGHT / 2 - y);
		if (fractol->type == 2)
			ft_threads(fractol);
	}
	return (0);
}

int		close_end(void *param)
{
	(void)param;
	exit(0);
}
