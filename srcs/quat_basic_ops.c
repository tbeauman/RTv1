/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quaternions_basic_ops.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/28 08:21:46 by tbeauman          #+#    #+#             */
/*   Updated: 2016/03/03 14:30:18 by tbeauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_quat	quat_add(t_quat q1, t_quat q2)
{
	return ((t_quat){q1.a + q2.a, q1.x + q2.x,
			q1.y + q2.y, q1.z + q2.z});
}

t_quat	quat_mult(t_quat q1, t_quat q2)
{
	return ((t_quat)
			{q1.a * q2.a - q1.x * q2.x - q1.y * q2.y - q1.z * q2.z,
			q1.a * q2.x + q1.x * q2.a + q1.y * q2.z - q1.z * q2.y,
			q1.a * q2.y + q1.y * q2.a + q1.z * q2.x - q1.x * q2.z,
			q1.a * q2.z + q1.z * q2.a + q1.x * q2.y - q1.y * q2.x});
}

double	quat_norm(t_quat q)
{
	return (sqrt(q.a * q.a + q.x * q.x + q.y * q.y + q.z * q.z));
}

t_quat	quat_normalize(t_quat q)
{
	double	norm;

	norm = quat_norm(q);
	return ((t_quat){q.a / norm, q.x / norm, q.y / norm, q.z / norm});
}
