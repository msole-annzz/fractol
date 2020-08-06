/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msole <msole@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 19:30:12 by msole             #+#    #+#             */
/*   Updated: 2020/08/06 16:30:11 by msole            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	ft_init_fractol(t_fract *fractol)
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
		//fractol->zoom = 0.3;
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
	//fractol->dx = (fractol->len_x / (double)WIN_WIDTH) / fractol->zoom;
	//fractol->dy = ((double)WIN_HEIGHT / (double)WIN_WIDTH) * fractol->dx;

}

int		ft_selecttype(t_fract *fractol, char *arg)
{
	fractol->type = 0;
	fractol->type = (ft_strequ(arg, "1")) ? 1 : fractol->type;
	fractol->type = (ft_strequ(arg, "2")) ? 2 : fractol->type;
	fractol->type = (ft_strequ(arg, "3")) ? 3 : fractol->type;
	fractol->type = (ft_strequ(arg, "4")) ? 4 : fractol->type;
	fractol->type = (ft_strequ(arg, "5")) ? 5 : fractol->type;
	fractol->type = (ft_strequ(arg, "6")) ? 6 : fractol->type;
	fractol->type = (ft_strequ(arg, "7")) ? 7 : fractol->type;
	fractol->type = (ft_strequ(arg, "8")) ? 8 : fractol->type;
	fractol->type = (ft_strequ(arg, "9")) ? 9 : fractol->type;
	return (fractol->type);
}

/*
**	mlx_hook (fractol->mlx.win, 4, 0, ft_mouse, fractol);
** 4- mouse scroll & mouse key press
**	mlx_hook (fractol->mlx.win, 5, 0, ft_mouse_release, fractol);
** 5- mouse not clicked
**	mlx_hook (fractol->mlx.win, 6, 0, ft_mouse_move, fractol);
** 6 - movements of the mouse
*/

void	ft_fractol(t_fract *fractol)
{
	fractol->mlx.init = mlx_init();
	fractol->mlx.win = mlx_new_window(fractol->mlx.init,\
							WIN_WIDTH, WIN_HEIGHT, "fractol");
	fractol->mlx.img = mlx_new_image(fractol->mlx.init, WIN_WIDTH, WIN_HEIGHT);
	fractol->image.data = mlx_get_data_addr(fractol->mlx.img,\
			&fractol->image.bpp, &fractol->image.size, &fractol->image.endian);
	ft_init_fractol(fractol);
	ft_threads(fractol);
	ft_legend(fractol);
	mlx_hook(fractol->mlx.win, 2, 0, fractol_keys, fractol);
	mlx_hook(fractol->mlx.win, 4, 0, ft_mouse, fractol);
	mlx_hook(fractol->mlx.win, 5, 0, ft_mouse_release, fractol);
	mlx_hook(fractol->mlx.win, 6, 0, ft_mouse_move, fractol);
	mlx_hook(fractol->mlx.win, 17, 0, close_end, fractol);
	mlx_loop(fractol->mlx.init);
}

void	ft_write(void)
{
	write(1, "Please, select preferred usage:\n\
		Mandelbrot:			./fractol 1;\n\
		Julia:				./fractol 2;\n\
		Newtone:			./fractol 3;\n\
		Fish:				./fractol 4;\n\
		Triangle:			./fractol 5;\n\
		Jellyfish:			./fractol 6;\n\
		Bust:				./fractol 7;\n\
		Goblet_of_fire:			./fractol 8;\n\
		Symmetry:			./fractol 9;\n\
		", 276);
}

int		main(int argc, char **argv)
{
	t_fract *fractol;

	fractol = NULL;
	if (argc == 2)
	{
		if (!(fractol = (t_fract *)malloc(sizeof(t_fract))) ||\
					!(fractol->mouse = (t_mouse *)malloc(sizeof(t_mouse))))
		{
			write(1, "There were some problems with memory allocation\n", 48);
			exit(1);
		}
		else
		{
			if (ft_selecttype(fractol, argv[1]) != 0)
				ft_fractol(fractol);
		}
	}
	else
	{
		ft_write();
		exit(1);
	}
	return (0);
}
