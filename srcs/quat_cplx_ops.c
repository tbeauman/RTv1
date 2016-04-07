/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cam_quat.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/28 11:39:20 by tbeauman          #+#    #+#             */
/*   Updated: 2016/03/02 15:50:35 by tbeauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_quat		get_cam_quat(t_cam c)
{
	c.rot_axis = vector_normalize(c.rot_axis);
	return ((t_quat){cos(c.theta),
			sin(c.theta) * c.rot_axis.x, sin(c.theta) * c.rot_axis.y,
			sin(c.theta) * c.rot_axis.z});
}

t_vector	rotate_ray(t_vector rd, t_quat rot)
{
	t_vector	ret;

	ret.x =
		rd.x * (rot.a * rot.a + rot.x * rot.x - rot.y * rot.y - rot.z * rot.z)
		+ rd.y * 2 * (rot.x * rot.y - rot.a * rot.z)
		+ rd.z * 2 * (rot.a * rot.y + rot.x * rot.z);
	ret.y = rd.x * 2 * (rot.x * rot.y + rot.a * rot.z)
		+ rd.y * (rot.a * rot.a - rot.x * rot.x +
			rot.y * rot.y - rot.z * rot.z)
		+ rd.z * 2 * (rot.y * rot.z - rot.a * rot.x);
	ret.z = rd.x * 2 * (rot.x * rot.z - rot.a * rot.y)
		+ rd.y * 2 * (rot.y * rot.z + rot.a * rot.x)
		+ rd.z * (rot.a * rot.a - rot.x * rot.x -
			rot.y * rot.y + rot.z * rot.z);
	return (ret);
}
