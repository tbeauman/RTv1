/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 15:11:38 by tbeauman          #+#    #+#             */
/*   Updated: 2016/03/03 15:48:42 by tbeauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	init_objs(t_env *e)
{
	e->sphere.o.x = 4;
	e->sphere.o.y = -3;
	e->sphere.o.z = -150;
	e->sphere.rayon = 6;
	e->plane.n.x = 0;
	e->plane.n.y = 3;
	e->plane.n.z = 1;
	e->plane.pt.x = 0;
	e->plane.pt.y = -40;
	e->plane.pt.z = 0;
	e->cylinder.o.x = 27;
	e->cylinder.o.y = -13;
	e->cylinder.o.z = -110;
	e->cylinder.dir.x = 0;
	e->cylinder.dir.y = 1;
	e->cylinder.dir.z = 0;
	e->cylinder.rayon = 5;
	e->cone.o.x = 16;
	e->cone.o.y = -9;
	e->cone.o.z = -135;
	e->cone.dir.x = 0;
	e->cone.dir.y = -1;
	e->cone.dir.z = 0;
	e->cone.angle = M_PI / 6;
}

void	init_light_params(t_env *e)
{
	e->sphere2.o.x = 4;
	e->sphere2.o.y = 2;
	e->sphere2.o.z = -150;
	e->sphere2.rayon = 8;
	e->cone.exp = 10;
	e->cone.kd = 1;
	e->cone.ks = 1;
	e->cylinder.exp = 10;
	e->cylinder.ks = 1;
	e->cylinder.kd = 1;
	e->plane.exp = 7;
	e->plane.kd = 1;
	e->plane.ks = 1;
	e->sphere.exp = 5;
	e->sphere.kd = 0.5;
	e->sphere.ks = 1;
	e->sphere.color = 0x003afba2;
	e->sphere2.exp = 5;
	e->sphere2.kd = 0.5;
	e->sphere2.ks = 1;
	e->sphere2.color = 0x00fca36c;
	e->plane.color = 0x00C1f6a3;
	e->cylinder.color = 0x00eacf10;
	e->cone.color = 0x00fe0ca0;
}

void	init(t_env *e)
{
	e->multispot = 0;
	e->hit = -1;
	e->cam.pos.x = 0;
	e->cam.pos.y = -5;
	e->cam.pos.z = -350;
	e->cam.rot_axis.x = 0;
	e->cam.rot_axis.y = 0;
	e->cam.rot_axis.z = 1;
	e->cam.theta = 0;
	e->cam.rot = get_cam_quat(e->cam);
	e->fcam = 2000;
	e->spot.o.x = 500;
	e->spot.o.y = -350;
	e->spot.o.z = -750;
	e->spot.color = 0x00ffffff;
	e->spot2.o.x = -500;
	e->spot2.o.y = -350;
	e->spot2.o.z = -750;
	e->spot2.color = 0x00ffffff;
	e->selection = 1;
	init_objs(e);
	init_light_params(e);
}
