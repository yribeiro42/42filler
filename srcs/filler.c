/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skitoak <skitoak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 12:39:52 by yribeiro          #+#    #+#             */
/*   Updated: 2018/04/18 11:56:02 by skitoak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		algo(t_env *env)
{
	dprintf(2, "my_pos = %d %d\n", env->my_pos_y, env->my_pos_x);
	dprintf(2, "en_pos = %d %d\n", env->en_pos_y, env->en_pos_x);
	if (env->my_pos_y > env->en_pos_y)
	{
		if (env->my_pos_x <= env->en_pos_x)
		{
			dprintf(2, "top right");
			return (place_piece2(env));
		}
		dprintf(2, "top left");
		return (place_piece1(env));
	}
	if (env->my_pos_y <= env->en_pos_y)
	{
		if (env->my_pos_x <= env->en_pos_x)
		{
			dprintf(2, "bottom right");
			return (place_piece4(env));
		}
		dprintf(2, "bottom left");
		return (place_piece3(env));
	}
}

int		main(void)
{
	t_env	*env;

	if (!(env = ft_memalloc(sizeof(t_env))))
		return (0);
	get_player(env);
	while (1)
	{
		get_coord(env);
		make_piece(env);
		if (!(algo(env)))
			return (0);
	}
	return (0);
}
