/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_mult.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/20 18:03:33 by tbeauman          #+#    #+#             */
/*   Updated: 2016/02/20 18:06:11 by tbeauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

/*
** Renvoie le produit vectoriel
*/

t_vector	vector_mult(t_vector u, t_vector v)
{
	t_vector	ret;

	ret.x = u.y * v.z - u.z * v.y;
	ret.y = u.z * v.x - u.x * v.z;
	ret.z = u.x * v.y - v.x * u.y;
	return (ret);
}

t_vector	vector_mult_by_scalar(t_vector v, double scalar)
{
	t_vector	ret;

	ret.x = scalar * v.x;
	ret.y = scalar * v.y;
	ret.z = scalar * v.z;
	return (ret);
}
