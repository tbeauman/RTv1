/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hits.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/28 06:40:28 by tbeauman          #+#    #+#             */
/*   Updated: 2016/03/03 13:38:25 by tbeauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int		hit_sphere(t_ray *r, t_sphere s, double *hit)
{
	double	eqc[4];
	double	tmp;

	eqc[0] = vector_dot_product(r->dir, r->dir);
	eqc[1] = 2 * (r->dir.x * (r->o.x - s.o.x) + r->dir.y * (r->o.y - s.o.y) +
			r->dir.z * (r->o.z - s.o.z));
	eqc[2] = (r->o.x - s.o.x) * (r->o.x - s.o.x) + (r->o.y - s.o.y) *
		(r->o.y - s.o.y) + (r->o.z - s.o.z) * (r->o.z - s.o.z) -
		s.rayon * s.rayon;
	eqc[3] = eqc[1] * eqc[1] - 4 * eqc[0] * eqc[2];
	if (eqc[3] < 0)
		return (0);
	else
	{
		tmp = (-eqc[1] - sqrt(eqc[3])) / (2 * eqc[0]);
		if (tmp < 0 && ((tmp += sqrt(eqc[3]) / eqc[0]) || 1))
			if (tmp < 0)
				return (0);
		if (*hit > 0 && tmp > *hit)
			return (0);
		*hit = tmp;
		return (1);
	}
}

int		hit_plane(t_ray *r, t_plane p, double *hit)
{
	double	a;
	double	b;

	p.n = vector_normalize(p.n);
	a = vector_dot_product(r->dir, p.n);
	b = vector_dot_product(p.n, vector_sub(r->o, p.pt));
	if (a == 0)
		return (0);
	if (*hit > 0 && -b / a > *hit)
		return (0);
	else if (-b / a > 0)
	{
		*hit = -b / a;
		return (1);
	}
	else
		return (0);
}

int		get_eqcone(t_ray *r, double n[3], t_vector new_o,
		t_lanormemecasselescouilles *q)
{
	q->eqc[0] = vector_dot_product(r->dir, r->dir) - n[2] * n[0] * n[0];
	q->eqc[1] = 2 * (vector_dot_product(r->dir, new_o) - n[2] * n[0] * n[1]);
	q->eqc[2] = vector_dot_product(new_o, new_o) - n[2] * n[1] * n[1];
	q->eqc[3] = q->eqc[1] * q->eqc[1] - 4 * q->eqc[0] * q->eqc[2];
	return (1);
}

int		hit_cylinder(t_ray *r, t_cylinder cy, double *hit)
{
	t_lanormemecasselescouilles	q;
	double						tmp;
	t_vector					new_o;
	double						sucemanorme[3];

	if (cy.dir.x == 0 && cy.dir.y == 0 && cy.dir.z == 0)
		return (0);
	cy.dir = vector_normalize(cy.dir);
	new_o = vector_sub(r->o, cy.o);
	sucemanorme[0] = vector_dot_product(r->dir, cy.dir);
	sucemanorme[1] = vector_dot_product(new_o, cy.dir);
	sucemanorme[2] = cy.rayon;
	if (get_eqcyl(r, sucemanorme, new_o, &q) && q.eqc[3] < 0)
		return (0);
	else if ((tmp = (-q.eqc[1] - sqrt(q.eqc[3])) / (2 * q.eqc[0])) || 1)
	{
		if (tmp < 0 &&
				((tmp = (-q.eqc[1] + sqrt(q.eqc[3])) / (2 * q.eqc[0])) || 1))
			if (tmp < 0)
				return (0);
		if (*hit > 0 && tmp > *hit)
			return (0);
		*hit = tmp;
		return (1);
	}
}

int		hit_cone(t_ray *r, t_cone co, double *hit)
{
	t_lanormemecasselescouilles	q;
	double						tmp;
	t_vector					new_o;
	double						norm_sucks[3];

	co.dir = vector_normalize(co.dir);
	new_o = vector_sub(r->o, co.o);
	norm_sucks[2] = 1 + tan(co.angle) * tan(co.angle);
	norm_sucks[0] = vector_dot_product(r->dir, co.dir);
	norm_sucks[1] = vector_dot_product(new_o, co.dir);
	get_eqcone(r, norm_sucks, new_o, &q);
	if (q.eqc[3] < 0)
		return (0);
	else if ((tmp = (-q.eqc[1] - sqrt(q.eqc[3])) / (2 * q.eqc[0])) || 1)
	{
		if (tmp < 0 &&
				((tmp = (-q.eqc[1] + sqrt(q.eqc[3]) / (2 * q.eqc[0]))) || 1))
			if (tmp < 0)
				return (0);
		if (*hit > 0 && tmp > *hit)
			return (0);
		*hit = tmp;
		return (1);
	}
}
