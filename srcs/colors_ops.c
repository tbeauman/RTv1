/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors_mult.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/24 23:02:12 by tbeauman          #+#    #+#             */
/*   Updated: 2016/03/03 14:31:05 by tbeauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int		clamp(int x, int min, int max)
{
	if (x > max)
		x = max;
	if (x < min)
		x = min;
	return (x);
}

double	dclamp(double x, double min, double max)
{
	if (x > max)
		x = max;
	if (x < min)
		x = min;
	return (x);
}

int		color_add(int color1, int color2)
{
	int		comp1[3];
	int		comp2[3];
	int		ret;

	comp1[0] = (color1 & 0x00ff0000) >> 16;
	comp1[1] = (color1 & 0x0000ff00) >> 8;
	comp1[2] = (color1 & 0x000000ff);
	comp2[0] = (color2 & 0x00ff0000) >> 16;
	comp2[1] = (color2 & 0x0000ff00) >> 8;
	comp2[2] = (color2 & 0x000000ff);
	ret = 0;
	ret += clamp(comp1[0] + comp2[0], 0, 0xff) << 16;
	ret += clamp(comp1[1] + comp2[1], 0, 0xff) << 8;
	ret += clamp(comp1[2] + comp2[2], 0, 0xff);
	return (ret);
}

int		colors_mult(int color1, int color2)
{
	int		comp1[3];
	int		comp2[3];
	int		ret;

	comp1[0] = (color1 & 0x00ff0000) >> 16;
	comp1[1] = (color1 & 0x0000ff00) >> 8;
	comp1[2] = (color1 & 0x000000ff);
	comp2[0] = (color2 & 0x00ff0000) >> 16;
	comp2[1] = (color2 & 0x0000ff00) >> 8;
	comp2[2] = (color2 & 0x000000ff);
	ret = clamp(comp1[0] * comp2[0], 0, 0xff) << 16;
	ret += clamp(comp1[1] * comp2[1], 0, 0xff) << 8;
	ret += clamp(comp1[2] * comp2[2], 0, 0x000000ff);
	return (ret);
}

int		color_mult(int color, double m)
{
	int		red;
	int		green;
	int		blue;

	red = (color & 0x00ff0000) >> 16;
	green = (color & 0x0000ff00) >> 8;
	blue = color & 0x000000ff;
	red *= m;
	green *= m;
	blue *= m;
	color = 0;
	color += clamp(red, 0, 0xff) << 16;
	color += clamp(green, 0, 0xff) << 8;
	color += clamp(blue, 0, 0xff);
	return (color);
}
