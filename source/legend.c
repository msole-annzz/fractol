/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   legend.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msole <msole@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/10 10:53:48 by msole             #+#    #+#             */
/*   Updated: 2020/07/10 10:53:49 by msole            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int		ft_legend(t_fract *fractol)
{
	char *str;

	str = NULL;
	mlx_string_put(fractol->mlx.init, fractol->mlx.win, 20, 20,
	0xaaaaaa, "zoom	+	: KP 8 / mouse skroll up");
	mlx_string_put(fractol->mlx.init, fractol->mlx.win, 20, 40,
	0xaaaaaa, "zoom	-	: KP 2 / mouse skroll down");
	mlx_string_put(fractol->mlx.init, fractol->mlx.win, 20, 60,
	0xaaaaaa, "moveX +/-	: ^/v");
	mlx_string_put(fractol->mlx.init, fractol->mlx.win, 20, 80,
	0xaaaaaa, "moveY +/-	: </>");
	mlx_string_put(fractol->mlx.init, fractol->mlx.win, 20, 100,
	0xaaaaaa, "deep (");
	mlx_string_put(fractol->mlx.init, fractol->mlx.win, 80, 100,
	0xaaaaaa, (str = ft_itoa(fractol->deep)));
	mlx_string_put(fractol->mlx.init, fractol->mlx.win, 110, 100,
	0xaaaaaa, ")+/-	: KP 7 / KP 1");
	mlx_string_put(fractol->mlx.init, fractol->mlx.win, 20, 120,
	0xaaaaaa, "change colour sheme: c");
	mlx_string_put(fractol->mlx.init, fractol->mlx.win, 20, 140,
	0xaaaaaa, "original image: space");
	mlx_string_put(fractol->mlx.init, fractol->mlx.win, 20, 160,
	0xaaaaaa, "change fractal type: tab");
	free(str);
	return (0);
}
