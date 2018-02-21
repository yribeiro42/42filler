/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yribeiro <yribeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 15:26:16 by yribeiro          #+#    #+#             */
/*   Updated: 2018/02/21 16:44:26 by yribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		get_position(t_env *env)
{
	int	i;
	int	y;

	i = 0;
	while (i < env->map_y)
	{
		y = 0;
		while (y < env->map_x)
		{
			if (env->board[i][y] == 'X')
				return (y + (i * env->map_x));
			y++;
		}
		i++;
	}
	return (-1);
}

int		place_piece(t_env *env)
{
	int		pos;
	int		pos_x;
	int		pos_y;

	pos = get_position(env);
	pos_y = pos / env->map_x;
	pos_x = pos % env->map_x;

	dprintf(2, "\npos X:[%d]\n", pos_x);
	dprintf(2, "piece_x:[%d]", env->piece_x);
	while ((pos_x + env->piece_x + 1) > env->map_x)
	{
		pos_x--;
		dprintf(2, "\nY:%d X:%d\n", pos_y, pos_x);
	}
	printf("%d %d\n", pos_y, pos_x);


	//dprintf(2, "\nY:%d X:%d\n", pos / env->map_x, pos % env->map_x);
	return (0);
}
