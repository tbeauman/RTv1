/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srabah <srabah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/25 23:21:15 by schong            #+#    #+#             */
/*   Updated: 2016/03/03 15:51:09 by tbeauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_H
# define RT_H

# include <stdlib.h>
# include <math.h>
# include <mlx.h>
# include "libft.h"
# include <pthread.h>
# include "typedefs.h"
# include "macoskeys.h"
# define ABS(x) x < 0 ? -x : x
# define HEIGHT 480
# define WIDTH 640
# define IS_VECT_NULL(X) (X->x == 0 && X->y == 0 && X->z == 0) ? 1 : 0
# define DEG(x) (180 * (x / M_PI))
# define RAD(x) (x * (M_PI / 180))
# define DELTA(a, b, c) b * b - 4 * a * c

/*
** CORE
*/

void		ft_error(char *msg);
void		ft_putpixel(int x, int y, t_env *e, int color);
void		clear_image(char **addr);
void		init(t_env *e);
void		redraw(t_env *e);

/*
** RAY
*/

int			hit_sphere(t_ray *r, t_sphere s, double *hit);
int			hit_plane(t_ray *r, t_plane p, double *hit);
int			hit_cylinder(t_ray *r, t_cylinder cy, double *hit);
int			hit_cone(t_ray *r, t_cone co, double *hit);
void		ray_tracer(t_env *e);
int			ray_bounce(t_ray ray, t_spot spot, t_env *e, int o);
int			in_shadow(t_ray ray, t_env *e, int o);
int			color_sphere(t_ray ray, t_sphere s, t_env *e, t_spot spot);
int			color_plane(t_ray ray, t_plane p, t_env *e, t_spot spot);
int			color_cylinder(t_ray ray, t_cylinder c, t_env *e, t_spot spot);
int			color_cone(t_ray ray, t_cone c, t_env *e, t_spot spot);
void		get_color_if_sphere(t_ray ray, t_env *e, int i, int j);
void		get_color_if_sphere2(t_ray ray, t_env *e, int i, int j);
void		get_color_if_plane(t_ray ray, t_env *e, int i, int j);
void		get_color_if_cylinder(t_ray ray, t_env *e, int i, int j);
void		get_color_if_cone(t_ray ray, t_env *e, int i, int j);

/*
** COLORS
*/

int			color_mult(int color, double m);
int			colors_mult(int color1, int color2);
int			color_add(int color1, int color2);
double		dclamp(double n, double min, double max);

/*
** HOOKS
*/

int			hooks_key_press(int kc, t_env *e);
int			hooks_mouse_clics(int bt, int x, int y, t_env *e);
int			hooks_expose(t_env *e);
int			sphere_hook(int kc, t_env *e);
int			plane_hook(int kc, t_env *e);
int			cylinder_hook(int kc, t_env *e);
int			cone_hook(int kc, t_env *e);
int			light_hook(int kc, t_env *e);

/*
** VECTOR
*/

t_vector	vector_normalize(t_vector v);
t_vector	vector_add(t_vector v1, t_vector v2);
t_vector	vector_sub(t_vector v1, t_vector v2);
double		vector_dot_product(t_vector v1, t_vector v2);
double		vector_norm(t_vector v);
t_vector	vector_mult_by_scalar(t_vector v, double scalar);
t_vector	vector_mult(t_vector v1, t_vector v2);

/*
** MATRIX
*/

t_matrix	matrix_init(int i, int j);
void		matrix_mult_by_scalar(double scalar, t_matrix *m);
t_matrix	matrix_mult(t_matrix a, t_matrix b);
t_matrix	matrix_add(t_matrix a, t_matrix b);
void		matrix_delete(t_matrix *m);
void		matrix_debug(t_matrix m);

/*
** QUATERNIONS
*/

t_quat		get_cam_quat(t_cam c);
t_vector	rotate_ray(t_vector rd, t_quat rot);
t_quat		quat_add(t_quat q1, t_quat q2);
t_quat		quat_mult(t_quat q1, t_quat q2);
double		quat_norm(t_quat q);
t_quat		quat_normalize(t_quat q);

/*
** GARBAGE NORM SHIT
*/
int			get_eqcyl(t_ray *r, double n[3], t_vector new_o,
				t_lanormemecasselescouilles *q);

#endif
