/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   diffuse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 17:02:44 by tbeauman          #+#    #+#             */
/*   Updated: 2016/03/03 13:44:32 by tbeauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int		color_sphere(t_ray ray, t_sphere s, t_env *e, t_spot spot)
{
	t_vector	hit_point;
	t_vector	normal;
	t_vector	half;
	double		diffuse;
	double		specular;

	hit_point = vector_mult_by_scalar(ray.dir, e->hit);
	hit_point = vector_add(ray.o, hit_point);
	ray.dir = vector_sub(spot.o, ray.o);
	ray.dir = vector_add(ray.o, ray.dir);
	ray.dir = vector_normalize(ray.dir);
	normal = vector_sub(hit_point, s.o);
	normal = vector_normalize(normal);
	diffuse = vector_dot_product(normal, ray.dir);
	half = vector_normalize(vector_add(ray.dir, hit_point));
	specular = vector_dot_product(half, normal);
	if (specular < 0 || diffuse < 0)
		specular = 0;
	else
		specular = ft_power(diffuse, s.exp);
	return (color_add(color_mult(s.color, 0.1),
		color_add(color_mult(e->spot.color, s.ks * specular),
				color_mult(s.color, s.kd * diffuse))));
}

int		color_plane(t_ray ray, t_plane p, t_env *e, t_spot spot)
{
	t_vector	hit_point;
	t_vector	normal;
	t_vector	half;
	double		dp;

	p.n = vector_normalize(p.n);
	hit_point = vector_mult_by_scalar(ray.dir, e->hit);
	hit_point = vector_add(ray.o, hit_point);
	ray.dir = vector_add(spot.o, vector_mult_by_scalar(ray.o, -1));
	ray.dir = vector_add(ray.o, ray.dir);
	ray.dir = vector_normalize(ray.dir);
	normal = vector_add(hit_point, p.n);
	normal = vector_normalize(normal);
	dp = vector_dot_product(normal, ray.dir);
	half = vector_normalize(vector_add(ray.dir, hit_point));
	return (color_add(color_mult(p.color, 0.1),
		color_mult(p.color, p.kd * dp)));
}

int		color_cylinder(t_ray ray, t_cylinder c, t_env *e, t_spot spot)
{
	t_vector	hit_point;
	t_vector	normal;
	t_vector	no;
	t_vector	half;
	double		d_s[2];

	c.dir = vector_normalize(c.dir);
	no = vector_sub(ray.o, c.o);
	d_s[0] = e->hit * vector_dot_product(ray.dir, c.dir) +
		vector_dot_product(no, c.dir);
	hit_point = vector_mult_by_scalar(ray.dir, e->hit);
	hit_point = vector_add(ray.o, hit_point);
	ray.dir = vector_sub(spot.o, ray.o);
	ray.dir = vector_add(ray.o, ray.dir);
	ray.dir = vector_normalize(ray.dir);
	normal = vector_sub(hit_point, c.o);
	normal = vector_sub(normal, vector_mult_by_scalar(c.dir, d_s[0]));
	normal = vector_normalize(normal);
	d_s[0] = vector_dot_product(normal, ray.dir);
	half = vector_normalize(vector_add(ray.dir, hit_point));
	d_s[1] = vector_dot_product(half, normal);
	d_s[1] = d_s[1] < 0 ? 0 : ft_power(d_s[1], c.exp);
	return (color_add(color_mult(c.color, 0.1),
		color_add(color_mult(e->spot.color, c.ks * d_s[1]),
				color_mult(c.color, c.kd * d_s[0]))));
}

int		color_cone(t_ray ray, t_cone c, t_env *e, t_spot spot)
{
	t_vector	hit_point;
	t_vector	normal;
	t_vector	no;
	t_vector	half;
	double		d_s[2];

	c.dir = vector_normalize(c.dir);
	no = vector_sub(ray.o, c.o);
	d_s[0] = e->hit * vector_dot_product(ray.dir, c.dir)
		+ vector_dot_product(no, c.dir);
	hit_point = vector_mult_by_scalar(ray.dir, e->hit);
	hit_point = vector_add(ray.o, hit_point);
	ray.dir = vector_sub(spot.o, ray.o);
	ray.dir = vector_add(ray.o, ray.dir);
	ray.dir = vector_normalize(ray.dir);
	normal = vector_sub(hit_point, c.o);
	normal = vector_sub(normal, vector_mult_by_scalar(c.dir, d_s[0]));
	normal = vector_normalize(normal);
	d_s[0] = vector_dot_product(normal, ray.dir);
	half = vector_normalize(vector_add(ray.dir, hit_point));
	d_s[1] = vector_dot_product(half, normal);
	d_s[1] = d_s[1] < 0 ? 0 : ft_power(d_s[1], c.exp);
	return (color_add(color_mult(c.color, 0.1),
		color_add(color_mult(e->spot.color, c.ks * d_s[1]),
				color_mult(c.color, c.kd * d_s[0]))));
}
