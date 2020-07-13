/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msole <msole@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 19:30:18 by msole             #+#    #+#             */
/*   Updated: 2020/07/09 17:58:28 by msole            ###   ########.fr       */
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
	(void)x;
	(void)y;
	fractol->mouse->is_press = 0;
	if ((mouse == 4) || (mouse == 5))
		ft_zoom(mouse, fractol);
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

void	ft_zoom(int keycode, t_fract *fractol)
{
	if ((keycode == 4) || (keycode == KEY_ANSI_KEYPAD8))
		fractol->zoom = fractol->zoom * ZOOM;
	if ((keycode == 5) || (keycode == KEY_ANSI_KEYPAD2))
		fractol->zoom = fractol->zoom / ZOOM;
	fractol->dx = (4 / (double)WIN_WIDTH) / fractol->zoom;
	fractol->dy = ((double)WIN_HEIGHT / (double)WIN_WIDTH) * fractol->dx;
	ft_threads(fractol);
}

int		ft_mouse_move(int x, int y, t_fract *fractol)
{
	fractol->mouse->x = x;
	fractol->mouse->y = y;
	if ((x > 0 && y > 0) && (x < WIN_WIDTH && y < WIN_HEIGHT))
	{
		fractol->xmouse = ft_x2compl(x, fractol);
		fractol->ymouse = ft_y2compl(y, fractol);
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
