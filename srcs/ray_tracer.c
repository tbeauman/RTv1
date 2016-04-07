/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_tracer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/21 17:21:35 by tbeauman          #+#    #+#             */
/*   Updated: 2016/03/03 15:45:28 by tbeauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	ray_tracer1(void *e)
{
	t_ray		ray;
	int			i;
	int			j;

	j = 0;
	ray.o = ((t_env*)e)->cam.pos;
	while (j < HEIGHT)
	{
		i = -1;
		while (++i < WIDTH)
		{
			ray.dir.x = (i - WIDTH / 2);
			ray.dir.y = (j - HEIGHT / 2);
			ray.dir.z = ((t_env*)e)->fcam;
			ray.dir = vector_normalize(ray.dir);
			ray.dir = rotate_ray(ray.dir, ((t_env*)e)->cam.rot);
			((t_env*)e)->hit = 0;
			get_color_if_sphere(ray, (t_env*)e, i, j);
			get_color_if_sphere2(ray, (t_env*)e, i, j);
			get_color_if_plane(ray, (t_env*)e, i, j);
			get_color_if_cylinder(ray, (t_env*)e, i, j);
			get_color_if_cone(ray, (t_env*)e, i, j);
		}
		j += 4;
	}
}

void	ray_tracer2(void *e)
{
	t_ray		ray;
	int			i;
	int			j;

	j = 1;
	ray.o = ((t_env*)e)->cam.pos;
	while (j < HEIGHT)
	{
		i = -1;
		while (++i < WIDTH)
		{
			ray.dir.x = (i - WIDTH / 2);
			ray.dir.y = (j - HEIGHT / 2);
			ray.dir.z = ((t_env*)e)->fcam;
			ray.dir = vector_normalize(ray.dir);
			ray.dir = rotate_ray(ray.dir, ((t_env*)e)->cam.rot);
			((t_env*)e)->hit = 0;
			get_color_if_sphere(ray, (t_env*)e, i, j);
			get_color_if_sphere2(ray, (t_env*)e, i, j);
			get_color_if_plane(ray, (t_env*)e, i, j);
			get_color_if_cylinder(ray, (t_env*)e, i, j);
			get_color_if_cone(ray, (t_env*)e, i, j);
		}
		j += 4;
	}
}

void	ray_tracer3(void *e)
{
	t_ray		ray;
	int			i;
	int			j;

	j = 2;
	ray.o = ((t_env*)e)->cam.pos;
	while (j < HEIGHT)
	{
		i = -1;
		while (++i < WIDTH)
		{
			ray.dir.x = (i - WIDTH / 2);
			ray.dir.y = (j - HEIGHT / 2);
			ray.dir.z = ((t_env*)e)->fcam;
			ray.dir = vector_normalize(ray.dir);
			ray.dir = rotate_ray(ray.dir, ((t_env*)e)->cam.rot);
			((t_env*)e)->hit = 0;
			get_color_if_sphere(ray, (t_env*)e, i, j);
			get_color_if_sphere2(ray, (t_env*)e, i, j);
			get_color_if_plane(ray, (t_env*)e, i, j);
			get_color_if_cylinder(ray, (t_env*)e, i, j);
			get_color_if_cone(ray, (t_env*)e, i, j);
		}
		j += 4;
	}
}

void	ray_tracer4(void *e)
{
	t_ray		ray;
	int			i;
	int			j;

	j = 3;
	ray.o = ((t_env*)e)->cam.pos;
	while (j < HEIGHT)
	{
		i = -1;
		while (++i < WIDTH)
		{
			ray.dir.x = (i - WIDTH / 2);
			ray.dir.y = (j - HEIGHT / 2);
			ray.dir.z = ((t_env*)e)->fcam;
			ray.dir = vector_normalize(ray.dir);
			ray.dir = rotate_ray(ray.dir, ((t_env*)e)->cam.rot);
			((t_env*)e)->hit = 0;
			get_color_if_sphere(ray, (t_env*)e, i, j);
			get_color_if_sphere2(ray, (t_env*)e, i, j);
			get_color_if_plane(ray, (t_env*)e, i, j);
			get_color_if_cylinder(ray, (t_env*)e, i, j);
			get_color_if_cone(ray, (t_env*)e, i, j);
		}
		j += 4;
	}
}

void	ray_tracer(t_env *e)
{
	pthread_create(&e->t1, NULL, (void*)ray_tracer1, (void*)e);
	pthread_join(e->t1, NULL);
	pthread_create(&e->t2, NULL, (void*)ray_tracer2, (void*)e);
	pthread_join(e->t2, NULL);
	pthread_create(&e->t3, NULL, (void*)ray_tracer3, (void*)e);
	pthread_join(e->t3, NULL);
	pthread_create(&e->t4, NULL, (void*)ray_tracer4, (void*)e);
	pthread_join(e->t4, NULL);
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
}
