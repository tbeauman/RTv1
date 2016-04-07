/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   typedefs.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/20 14:37:23 by tbeauman          #+#    #+#             */
/*   Updated: 2016/03/03 15:44:54 by tbeauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPEDEFS_H
# define TYPEDEFS_H

# include <pthread.h>

typedef struct	s_vector
{
	double		x;
	double		y;
	double		z;
}				t_vector;

typedef struct	s_quat
{
	double		a;
	double		x;
	double		y;
	double		z;
}				t_quat;

typedef struct	s_matrix
{
	double		**m;
	int			i;
	int			j;
}				t_matrix;

typedef struct	s_sphere
{
	t_vector	o;
	int			rayon;
	int			color;
	double		kd;
	double		ks;
	int			exp;
}				t_sphere;

typedef struct	s_plane
{
	t_vector	n;
	t_vector	pt;
	int			exp;
	int			color;
	double		kd;
	double		ks;
}				t_plane;

typedef struct	s_cylinder
{
	t_vector	o;
	t_vector	dir;
	int			exp;
	int			rayon;
	int			color;
	double		kd;
	double		ks;
}				t_cylinder;

typedef struct	s_cone
{
	t_vector	dir;
	t_vector	o;
	double		angle;
	int			exp;
	int			color;
	double		kd;
	double		ks;
}				t_cone;

typedef struct	s_ray
{
	t_vector	dir;
	t_vector	o;
	double		lambda;
}				t_ray;

typedef struct	s_spot
{
	t_vector	o;
	int			color;
}				t_spot;

typedef struct	s_cam
{
	t_vector	pos;
	t_vector	rot_axis;
	t_quat		rot;
	double		theta;
}				t_cam;

typedef struct	s_env
{
	void		*win;
	void		*mlx;
	void		*img;
	char		*img_addr;
	t_cam		cam;
	int			fcam;
	int			boo;
	int			bpp;
	int			sline;
	int			end;
	double		hit;
	t_sphere	sphere;
	t_sphere	sphere2;
	t_plane		plane;
	t_cylinder	cylinder;
	t_cone		cone;
	t_spot		spot;
	t_spot		spot2;
	int			selection;
	int			multispot;
	pthread_t	t1;
	pthread_t	t2;
	pthread_t	t3;
	pthread_t	t4;
}				t_env;

typedef struct	s_lanormemecasselescouilles
{
	double		eqc[4];
}				t_lanormemecasselescouilles;

#endif
