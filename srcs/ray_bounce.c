/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_bounce.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/22 20:34:00 by tbeauman          #+#    #+#             */
/*   Updated: 2016/03/03 15:47:26 by tbeauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int		in_shadow(t_ray r, t_env *e, int o)
{
	int		ret;
	t_ray	ray;

	ret = 0;
	ray = r;
	if (!e->multispot)
		return (ray_bounce(ray, e->spot, e, o));
	if (ray_bounce(r, e->spot, e, o))
		ret = 1;
	if (ray_bounce(ray, e->spot2, e, o))
		ret = (ret == 1) ? 2 : 3;
	return (ret);
}

int		ray_bounce(t_ray ray, t_spot spot, t_env *e, int o)
{
	t_vector	hit_point;
	double		hit;

	hit = e->hit;
	hit_point = vector_mult_by_scalar(ray.dir, hit);
	ray.o = vector_add(ray.o, hit_point);
	ray.dir = vector_normalize(vector_add(spot.o, ray.o));
	hit = -1;
	if (o != 0 && hit_sphere(&ray, e->sphere2, &hit) && hit > 0)
		return (2);
	if (o != 1 && hit_sphere(&ray, e->sphere, &hit) && hit > 0)
		return (2);
	if (o != 2 && hit_plane(&ray, e->plane, &hit) && hit > 0)
		return (2);
	if (o != 3 && hit_cylinder(&ray, e->cylinder, &hit) && hit > 0)
		return (2);
	if (o != 4 && hit_cone(&ray, e->cone, &hit) && hit > 0)
		return (2);
	return (0);
}
