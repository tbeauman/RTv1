/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_key_release.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/22 00:54:54 by tbeauman          #+#    #+#             */
/*   Updated: 2016/03/03 15:51:10 by tbeauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int		hooks_mouse_clics(int bt, int x, int y, t_env *e)
{
	t_ray	ray;
	double	hit;

	if ((hit = -1) && (bt == SCROLL_UP || bt == SCROLL_DOWN))
		e->cam.pos.z += bt == SCROLL_UP ? 5 : -5;
	if (bt == LEFT_CLIC && ((ray.dir.z = e->fcam) || 1))
	{
		ray.o = e->cam.pos;
		ray.dir.x = x - WIDTH / 2;
		ray.dir.y = y - HEIGHT / 2;
		ray.dir = vector_normalize(ray.dir);
		ray.dir = rotate_ray(ray.dir, e->cam.rot);
		if (hit_sphere(&ray, e->sphere, &hit))
			e->selection = 1;
		if (hit_sphere(&ray, e->sphere2, &hit))
			e->selection = 0;
		if (hit_plane(&ray, e->plane, &hit))
			e->selection = 2;
		if (hit_cylinder(&ray, e->cylinder, &hit))
			e->selection = 3;
		if (hit_cone(&ray, e->cone, &hit))
			e->selection = 4;
	}
	redraw(e);
	return (1);
}

void	camera_hook(int kc, t_env *e)
{
	if (kc == LEFT || kc == RIGHT)
		e->cam.pos.x += kc == RIGHT ? 1 : -1;
	if (kc == UP || kc == DOWN)
		e->cam.pos.y += kc == UP ? -1 : 1;
	if (kc == KEY_1 || kc == KEY_4)
		e->cam.rot_axis.x += kc == KEY_1 ? -1 : 1;
	if (kc == KEY_2 || kc == KEY_5)
		e->cam.rot_axis.y += kc == KEY_2 ? -1 : 1;
	if (kc == KEY_3 || kc == KEY_6)
		e->cam.rot_axis.z += kc == KEY_3 ? -1 : 1;
	if (kc == KEY_PLUS || kc == KEY_MOINS)
		e->cam.theta += kc == KEY_PLUS ? M_PI / 64 : -M_PI / 64;
}

int		sphere2_hook(int kc, t_env *e)
{
	if (kc == UP || kc == DOWN)
		e->sphere2.o.y += kc == UP ? -5 : 5;
	if (kc == LEFT || kc == RIGHT)
		e->sphere2.o.x += kc == LEFT ? -5 : 5;
	if (kc == KEY_Z || kc == KEY_X)
		e->sphere2.o.z += kc == KEY_Z ? 5 : -5;
	if (kc == KEY_PLUS || (kc == KEY_MOINS && e->sphere.rayon > 1))
		e->sphere2.rayon += kc == KEY_PLUS ? 1 : -1;
	if (kc == KEY_P || kc == KEY_O)
		e->sphere2.exp += kc == KEY_P ? 1 : -1;
	return (1);
}

int		hooks_key_press(int kc, t_env *e)
{
	if (kc == KEY_ESC)
		exit(1);
	if (kc == KEY_C)
		e->selection = 6;
	if (kc == KEY_L)
		e->selection = 5;
	if (e->selection == 0)
		sphere2_hook(kc, e);
	if (e->selection == 1)
		sphere_hook(kc, e);
	if (e->selection == 2)
		plane_hook(kc, e);
	if (e->selection == 3)
		cylinder_hook(kc, e);
	if (e->selection == 4)
		cone_hook(kc, e);
	if (e->selection == 5)
		light_hook(kc, e);
	if (e->selection == 6)
		camera_hook(kc, e);
	if (kc == KEY_M)
		e->multispot = e->multispot == 0 ? 1 : 0;
	e->cam.rot = get_cam_quat(e->cam);
	redraw(e);
	return (0);
}

int		hooks_expose(t_env *e)
{
	mlx_clear_window(e->mlx, e->win);
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	return (0);
}
