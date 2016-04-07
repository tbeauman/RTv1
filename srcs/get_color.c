/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 13:44:09 by tbeauman          #+#    #+#             */
/*   Updated: 2016/03/03 15:48:44 by tbeauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	get_color_if_sphere(t_ray ray, t_env *e, int i, int j)
{
	int		ret;

	if (hit_sphere(&ray, e->sphere, &e->hit))
	{
		if (!(ret = in_shadow(ray, e, 1)))
			ft_putpixel(i, j, e,
					e->multispot ?
					color_add(color_sphere(ray, e->sphere, e, e->spot2),
						color_sphere(ray, e->sphere, e, e->spot)) :
					color_sphere(ray, e->sphere, e, e->spot));
		else if (ret == 1)
			ft_putpixel(i, j, e, color_mult(
						color_sphere(ray, e->sphere, e, e->spot2), 0.5));
		else if (ret == 2)
			ft_putpixel(i, j, e, 0);
		else
			ft_putpixel(i, j, e, color_mult(
						color_sphere(ray, e->sphere, e, e->spot), 0.5));
	}
}

void	get_color_if_sphere2(t_ray ray, t_env *e, int i, int j)
{
	int		ret;

	if (hit_sphere(&ray, e->sphere2, &e->hit))
	{
		if (!(ret = in_shadow(ray, e, 0)))
			ft_putpixel(i, j, e,
					e->multispot ?
					color_add(color_sphere(ray, e->sphere2, e, e->spot2),
						color_sphere(ray, e->sphere2, e, e->spot)) :
					color_sphere(ray, e->sphere2, e, e->spot));
		else if (ret == 1)
			ft_putpixel(i, j, e, color_mult(
						color_sphere(ray, e->sphere2, e, e->spot2), 0.5));
		else if (ret == 2)
			ft_putpixel(i, j, e, 0);
		else
			ft_putpixel(i, j, e, color_mult(
						color_sphere(ray, e->sphere2, e, e->spot), 0.5));
	}
}

void	get_color_if_plane(t_ray ray, t_env *e, int i, int j)
{
	int		ret;

	if (hit_plane(&ray, e->plane, &e->hit))
	{
		if (!(ret = in_shadow(ray, e, 2)))
			ft_putpixel(i, j, e,
					e->multispot ?
					color_add(color_plane(ray, e->plane, e, e->spot),
						color_plane(ray, e->plane, e, e->spot2)) :
					color_plane(ray, e->plane, e, e->spot));
		else if (ret == 1)
			ft_putpixel(i, j, e, color_mult(
						color_plane(ray, e->plane, e, e->spot2), 0.5));
		else if (ret == 2)
			ft_putpixel(i, j, e, 0);
		else
			ft_putpixel(i, j, e, color_mult(
						color_plane(ray, e->plane, e, e->spot), 0.5));
	}
}

void	get_color_if_cylinder(t_ray ray, t_env *e, int i, int j)
{
	int		ret;

	if (hit_cylinder(&ray, e->cylinder, &e->hit))
	{
		if (!(ret = in_shadow(ray, e, 3)))
			ft_putpixel(i, j, e,
					e->multispot ?
					color_add(color_cylinder(ray, e->cylinder, e, e->spot2),
						color_cylinder(ray, e->cylinder, e, e->spot)) :
					color_cylinder(ray, e->cylinder, e, e->spot));
		else if (ret == 1)
			ft_putpixel(i, j, e, color_mult(
						color_cylinder(ray, e->cylinder, e, e->spot2), 0.5));
		else if (ret == 2)
			ft_putpixel(i, j, e, 0);
		else
			ft_putpixel(i, j, e, color_mult(
						color_cylinder(ray, e->cylinder, e, e->spot), 0.5));
	}
}

void	get_color_if_cone(t_ray ray, t_env *e, int i, int j)
{
	int		ret;

	if (hit_cone(&ray, e->cone, &e->hit))
	{
		if (!(ret = in_shadow(ray, e, 4)))
			ft_putpixel(i, j, e,
					e->multispot ?
					color_add(color_cone(ray, e->cone, e, e->spot2),
						color_cone(ray, e->cone, e, e->spot)) :
					color_cone(ray, e->cone, e, e->spot));
		else if (ret == 1)
			ft_putpixel(i, j, e, color_mult(
						color_cone(ray, e->cone, e, e->spot2), 0.5));
		else if (ret == 2)
			ft_putpixel(i, j, e, 0);
		else
			ft_putpixel(i, j, e, color_mult(
						color_cone(ray, e->cone, e, e->spot), 0.5));
	}
}
