/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/08 16:19:32 by tbeauman          #+#    #+#             */
/*   Updated: 2016/03/03 16:01:29 by tbeauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	redraw(t_env *e)
{
	clear_image(&e->img_addr);
	mlx_clear_window(e->mlx, e->win);
	ray_tracer(e);
}

void	ft_error(char *msg)
{
	ft_putstr_fd(msg, 2);
	exit(1);
}

void	ft_putpixel(int x, int y, t_env *e, int color)
{
	int		*keepitreal;

	if (x + y * HEIGHT > WIDTH * HEIGHT || x > WIDTH || y > HEIGHT ||
		x < 0 || y < 0)
		return ;
	keepitreal = (int*)e->img_addr;
	keepitreal[x + y * WIDTH] = color;
	e->img_addr = (char*)keepitreal;
}

void	clear_image(char **address)
{
	int		i;

	i = 0;
	while (i < HEIGHT * WIDTH * 4)
		(*address)[i++] = 0;
}

int		main(void)
{
	t_env		e;

	init(&e);
	if (!(e.mlx = mlx_init()))
		ft_error("Connection to MLX server failed...\n");
	if (!(e.win = mlx_new_window(e.mlx, WIDTH, HEIGHT, "RAY-TRACER")))
		ft_error("Failed to open window\n");
	if (!(e.img = mlx_new_image(e.mlx, WIDTH, HEIGHT)))
		ft_error("Failed to create image\n");
	e.img_addr = mlx_get_data_addr(e.img, &e.bpp, &e.sline, &e.end);
	ray_tracer(&e);
	mlx_mouse_hook(e.win, &hooks_mouse_clics, &e);
	mlx_hook(e.win, 2, 1L << 0, &hooks_key_press, &e);
	mlx_expose_hook(e.win, &hooks_expose, &e);
	mlx_loop(e.mlx);
	return (0);
}
