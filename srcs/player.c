/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yribeiro <yribeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 15:26:16 by yribeiro          #+#    #+#             */
/*   Updated: 2018/02/22 16:26:56 by yribeiro         ###   ########.fr       */
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
			if (env->board[i][y] == env->player)
				return (y + (i * env->map_x));
			y++;
		}
		i++;
	}
	return (-1);
}

int		place_piece(t_env *env)
{
	int		row;
	int		col;
	int		ret;

	row = env->map_y;
	while (row > 0)
	{
		col = env->map_x;
		while (col > 0)
		{
			ret = try_place(row, col, env);
			if (ret == 1)
			{
				send_position(env);
				return (1);
			}
			col--;
		}
		row--;
	}
	return (0);
}


int		try_place(int row, int col, t_env *env)
{
	int		i;
	int		j;
	int		contact;

	i = -1;
	while (++i < env->piece_y)
	{
		j = -1;
		while (j++ < env->piece_x)
		{
			dprintf(2, "\npiece[%d][%d]:[%c]", i, j, env->piece[i][j]);
			dprintf(2, "\nboard[%d][%d]:[%c]", (row + i), (col + j), env->board[row + i][col + j]);
			if (env->piece[i][j] == '*' && (env->board[row + i][col + j] ==
				env->player))
				contact++;
		}
	}
	if (contact == 1)
	{
		env->pos_y = row;
		env->pos_x = col;
		return (1);
	}
	return (0);
}

int		send_position(t_env *env)
{
	printf("%d %d\n", env->pos_y, env->pos_x);
	return (0);
}
