/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yribeiro <yribeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 15:26:16 by yribeiro          #+#    #+#             */
/*   Updated: 2018/02/28 20:44:54 by yribeiro         ###   ########.fr       */
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
	while (row-- > 0)
	{
		col = env->map_x;
		while (col-- > 0)
		{
			if (try_place(row, col, env))
			{
				send_position(env);
				return (1);
			}
		} 
	}
	send_position(env);
	return (0);
}


int		try_place(int row, int col, t_env *env)
{
	int		i;
	int		j;
	int		contact;

	i = 0;
	while (i < env->piece_y)
	{
		j = 0;
		while (j < env->piece_x)
		{
			if ((row + i) < env->map_y && (col + j) < env->map_x)
			{
				if (env->piece[i][j] == '*' && (env->board[row + i][col + j] == env->player))
					contact++;
			}
			j++;	
		}
		i++;
	}
	if (contact == 1)
	{
		dprintf(2, "\nrow[%d];col[%d]\n", row, col);
		env->pos_y = row;
		env->pos_x = col;
		return (1);
	}

	return (0);
}

int		send_position(t_env *env)
{
	ft_printf("%d %d\n", env->pos_y, env->pos_x);
	return (0);
}
