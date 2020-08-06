/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msole <msole@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 19:28:38 by msole             #+#    #+#             */
/*   Updated: 2020/08/06 16:51:58 by msole            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define WIN_WIDTH	1500
# define WIN_HEIGHT	1500
# define ZOOM		1.1
# define THREAD		8

# include <stdio.h>
# include <errno.h>
# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include "../libft/libft.h"
# include "mlx.h"
# include "keys.h"
# include <pthread.h>

/*
** Image
*/
/*
** data		— image
** size		— number of bytes used to store one line of image
** endian	— little or big endian (у нас little)
** bpp		- bits_per_pixel — depth of image (У нас 32, 4*int)
*/

typedef	struct	s_img
{
	char		*data;
	int			size;
	int			endian;
	int			bpp;
}				t_img;

/*
** Library initialization
*/

/*
** *init	- appeal to library mlx, connection identifier
** win		— window identifier
** img		— information about image
*/

typedef	struct	s_mlx
{
	void		*init;
	void		*win;
	void		*img;
}				t_mlx;

/*
**  Complex number
*/

/*
** re — real part
** im — imaginary part
*/

typedef	struct	s_cmplx
{
	double		re;
	double		im;
}				t_cmplx;

/*
** Mouse movements
*/

/*
**x - mouse movements
**y - mouse movements
**previous_x - key is pressed
**previous_y
**new_x - key is not pressed
**new_y
**is_press - 0/1 - key is/is not pressed
*/

typedef	struct	s_mouse
{
	int			x;
	int			y;
	int			previous_x;
	int			previous_y;
	int			new_x;
	int			new_y;

	int			is_press;
}				t_mouse;

/*
** Fract'ol
*/
/*
** mlx - Library initialization
** image - Image
** *mouse - Mouse movements
**cur_point;
** type - fractal type
** dx - single cut x
** dy - single cut y
** zoom - scale
** deep -  number of iterations
** colour_sheme - 1 - blue_rainbow; 2 - black_and_white; 3 - logorithmic;
** ymove - window shift of image
** xmove - window shift of image
** xmouse - mouse tracking x
** ymouse - mouse tracking y
** thread_min_width - the beginning of the strip drawn by the thread
** thread_max_width - the end of strip drawn by thread
*/

typedef	struct	s_fract
{
	t_mlx		mlx;
	t_img		image;
	int			type;
	t_cmplx		cur_point;
	t_mouse		*mouse;
	double		dx;
	double		dy;
	//float		zoom;
	int			deep;
	int			colour_sheme;
	double		ymove;
	double		xmove;
	double		xmouse;
	double		ymouse;
	int			thread_min_width;
	int			thread_max_width;
	double		x2;
	double		y2;
	double		sum_x2_y2;
	double		pr_sum_x2_y2;
	double		x_tmp;
	double		x;
	double		y;
	double		len_x;
	double		len_y;
	double		re_max;
	double		re_min;
	double		im_max;
	double		im_min;
}				t_fract;

/*
** main.c
*/
void			ft_init_fractol		(t_fract *fractol);
void			ft_fractol			(t_fract *fractol);

/*
** draw_fractal.c
*/
void			ft_put_pixel		(t_fract *fractol, int deep, int i, int j);
void			*ft_draw_picture	(void *thread_data);
void			ft_threads			(t_fract *fractol);
/*
** complex.c
*/
double			ft_x2compl			(int x, t_fract *fractol);
double			ft_y2compl			(int y, t_fract *fractol);
void			ft_conv2compl		(int x, int y, t_fract *fractol);
/*
** fractals.c
*/
int				ft_mandelbrot		(t_fract *fractol, double x, double y);
int				ft_julia			(t_fract *fractol, double x, double y);
int				ft_newton			(t_fract *fractol, double x, double y);
int				fish				(t_fract *fractol, double x, double y);
/*
** additionals_fractals.c
*/
int				triangle			(t_fract *fractol, double x, double y);
int				jellyfish			(t_fract *fractol, double x, double y);
int				bust				(t_fract *fractol, double x, double y);
int				goblet_of_fire		(t_fract *fractol, double x, double y);
int				symmetry			(t_fract *fractol, double x, double y);
/*
** mouse.c
*/
int				ft_mouse			(int mouse, int x, int y, t_fract *fractol);
//void			ft_zoom				(int mouse, t_fract *fractol);
void	ft_zoom(int keycode, t_fract *fractol, int x, int y);
int				ft_mouse_move		(int x, int y, t_fract *fractol);
int				ft_mouse_release	(int mouse, int x, int y, t_fract *fractol);
int				close_end			(void *param);
/*
** keys.c
*/
int				fractol_keys		(int keycode, t_fract *fractol);

/*
** legend.c
*/
int				ft_legend			(t_fract *fractol);
/*
** colours.c
*/
void			ft_colours			(t_fract *fractol, int p, double tone,\
									int deep);

#endif
