/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msole <msole@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 19:29:48 by msole             #+#    #+#             */
/*   Updated: 2020/08/06 18:55:16 by msole            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	init_fractol(t_fract *fractol)
{
	//fractol->zoom = 1;
	fractol->xmouse = 0.5;
	fractol->ymouse = 0.5;
	fractol->xmove = 0;
	fractol->ymove = 0;
	fractol->colour_sheme = 1;
	fractol->deep = 50;
	if (fractol->type == 3)
	{
	//	fractol->zoom = 0.1;
		fractol->deep = 10;
	}
	fractol->re_max = 2;
	fractol->re_min = -2;
	fractol->im_max = 2;
	fractol->im_min = -2;
	fractol->len_x = fractol->re_max - fractol->re_min;
	fractol->len_y = fractol->im_max - fractol->im_min;
	fractol->dx = (fractol->len_x / (double)WIN_WIDTH);
	fractol->dy = ((double)WIN_HEIGHT / (double)WIN_WIDTH) * fractol->dx;
}

void	change_colour(t_fract *fractol)
{
	if (fractol->colour_sheme < 3)
		fractol->colour_sheme++;
	else
		fractol->colour_sheme = 1;
}

void	change_type(t_fract *fractol)
{
	if (fractol->type < 9)
	{
		fractol->type += 1;
		if (fractol->type == 3)
		{
		//	fractol->zoom = 0.1;
			fractol->deep = 10;
		}
		else
		{
		//	fractol->zoom = 1;
			fractol->deep = 50;
		}
	}
	else
		fractol->type = 1;
}

void	fractol_keys_move(int keycode, t_fract *fractol)
{
	if (keycode == KEY_ANSI_KEYPAD1)
	{
		if (fractol->deep > 1)
			fractol->deep -= 1;
	}
	if (keycode == KEY_ANSI_KEYPAD7)
		fractol->deep += 1;
	if (keycode == KEY_LEFTARROW)
	{
		fractol->re_min += 0.01;
		fractol->re_max += 0.01;
	}
	if (keycode == KEY_RIGHTARROW)
		fractol->xmove = fractol->xmove + 30;
	if (keycode == KEY_DOWNARROW)
		fractol->ymove = fractol->ymove - 30;
	if (keycode == KEY_UPARROW)
		fractol->ymove = fractol->ymove + 30;



}

int		fractol_keys(int keycode, t_fract *fractol)
{
	if (keycode == KEY_ESCAPE)
		exit(0);
	if (keycode == KEY_SPACE)
		init_fractol(fractol);
	if (keycode == KEY_ANSI_C)
		change_colour(fractol);
	if (keycode == KEY_TAB)
		change_type(fractol);
	//if ((keycode == KEY_ANSI_KEYPAD2) || (keycode == KEY_ANSI_KEYPAD8))
	//	ft_zoom(keycode, fractol);
	if (keycode == KEY_ANSI_KEYPAD1 || keycode == KEY_ANSI_KEYPAD7 ||\
		keycode == KEY_LEFTARROW || keycode == KEY_RIGHTARROW ||\
		keycode == KEY_DOWNARROW || keycode == KEY_UPARROW)
		fractol_keys_move(keycode, fractol);

	//fractol->dx = (4 / (double)WIN_WIDTH) / fractol->zoom;
	//fractol->dy = ((double)WIN_HEIGHT / (double)WIN_WIDTH) * fractol->dx;
	ft_threads(fractol);
	return (0);
}
