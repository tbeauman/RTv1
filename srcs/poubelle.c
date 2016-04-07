/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   poubelle.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 13:35:49 by tbeauman          #+#    #+#             */
/*   Updated: 2016/03/03 15:08:06 by tbeauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int		get_eqcyl(t_ray *r, double n[3], t_vector new_o,
		t_lanormemecasselescouilles *q)
{
	q->eqc[0] = vector_dot_product(r->dir, r->dir) - n[0] * n[0];
	q->eqc[1] = 2 * (vector_dot_product(r->dir, new_o) - n[0] * n[1]);
	q->eqc[2] = vector_dot_product(new_o, new_o) -
		n[1] * n[1] - n[2] * n[2];
	q->eqc[3] = q->eqc[1] * q->eqc[1] - 4 * q->eqc[0] * q->eqc[2];
	return (1);
}
