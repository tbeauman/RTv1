/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 14:23:10 by tbeauman          #+#    #+#             */
/*   Updated: 2016/04/07 13:45:13 by tbeauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int		sphere_hook(int kc, t_env *e)
{
	if (kc == UP || kc == DOWN)
		e->sphere.o.y += kc == UP ? -5 : 5;
	if (kc == LEFT || kc == RIGHT)
		e->sphere.o.x += kc == LEFT ? -5 : 5;
	if (kc == KEY_Z || kc == KEY_X)
		e->sphere.o.z += kc == KEY_Z ? 5 : -5;
	if (kc == KEY_PLUS || (kc == KEY_MOINS && e->sphere.rayon > 1))
		e->sphere.rayon += kc == KEY_PLUS ? 1 : -1;
	if (kc == KEY_P || kc == KEY_O)
		e->sphere.exp += kc == KEY_P ? 1 : -1;
	return (1);
}

int		plane_hook(int kc, t_env *e)
{
	if (kc == KEY_1 || kc == KEY_4)
		e->plane.n.x += kc == KEY_1 ? -1 : 1;
	if (kc == KEY_2 || kc == KEY_5)
		e->plane.n.y += kc == KEY_2 ? -1 : 1;
	if (kc == KEY_3 || kc == KEY_6)
		e->plane.n.z += kc == KEY_3 ? -1 : 1;
	if (kc == LEFT || kc == RIGHT)
		e->plane.pt.x += kc == LEFT ? -5 : 5;
	if (kc == UP || kc == DOWN)
		e->plane.pt.y += kc == UP ? -5 : 5;
	if (kc == KEY_Z || kc == KEY_X)
		e->plane.pt.z += kc == KEY_Z ? -5 : 5;
	if (kc == KEY_P || kc == KEY_O)
		e->plane.exp += kc == KEY_P ? 1 : -1;
	return (1);
}

int		cylinder_hook(int kc, t_env *e)
{
	if (kc == UP || kc == DOWN)
		e->cylinder.o.y += kc == UP ? -5 : 5;
	if (kc == LEFT || kc == RIGHT)
		e->cylinder.o.x += kc == LEFT ? -5 : 5;
	if (kc == KEY_Z || kc == KEY_X)
		e->cylinder.o.z += kc == KEY_Z ? 5 : -5;
	if (kc == KEY_1 || kc == KEY_4)
		e->cylinder.dir.x += kc == KEY_1 ? -1 : 1;
	if (kc == KEY_2 || kc == KEY_5)
		e->cylinder.dir.y += kc == KEY_2 ? -1 : 1;
	if (kc == KEY_3 || kc == KEY_6)
		e->cylinder.dir.z += kc == KEY_3 ? -1 : 1;
	if (kc == KEY_PLUS || (kc == KEY_MOINS))
		e->cylinder.rayon += kc == KEY_PLUS ? 1 : -1;
	if (kc == KEY_P || kc == KEY_O)
		e->cylinder.exp += kc == KEY_P ? 1 : -1;
	return (1);
}

int		cone_hook(int kc, t_env *e)
{
	if (kc == UP || kc == DOWN)
		e->cone.o.y += kc == UP ? -5 : 5;
	if (kc == LEFT || kc == RIGHT)
		e->cone.o.x += kc == LEFT ? -5 : 5;
	if (kc == KEY_Z || kc == KEY_X)
		e->cone.o.z += kc == KEY_Z ? 5 : -5;
	if (kc == KEY_1 || kc == KEY_4)
		e->cone.dir.x += kc == KEY_1 ? -1 : 1;
	if (kc == KEY_2 || kc == KEY_5)
		e->cone.dir.y += kc == KEY_2 ? -1 : 1;
	if (kc == KEY_3 || kc == KEY_6)
		e->cone.dir.z += kc == KEY_3 ? -1 : 1;
	if (kc == KEY_PLUS || kc == KEY_MOINS)
		e->cone.angle += kc == KEY_PLUS ? M_PI / 64 : -M_PI / 64;
	if (kc == KEY_P || kc == KEY_O)
		e->cone.exp += kc == KEY_P ? 1 : -1;
	e->cone.angle = dclamp(e->cone.angle, 0, M_PI / 4);
	return (1);
}

int		light_hook(int kc, t_env *e)
{
	if (kc == UP || kc == DOWN)
		e->spot.o.y += kc == UP ? -10 : 10;
	if (kc == LEFT || kc == RIGHT)
		e->spot.o.x += kc == LEFT ? -10 : 10;
	if (kc == KEY_Z || kc == KEY_X)
		e->spot.o.z += kc == KEY_Z ? 10 : -10;
	return (1);
}
