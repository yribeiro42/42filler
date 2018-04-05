/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yribeiro <yribeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 15:26:16 by yribeiro          #+#    #+#             */
/*   Updated: 2018/04/05 11:53:51 by yribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

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
				ft_printf("%d %d\n", env->pos_y, env->pos_x);
				return (1);
			}
		} 
	}
	ft_printf("%d %d\n", 0, 0);
	return (0);
}


int		try_place(int row, int col, t_env *env)
{
	int		i;
	int		j;
	int		contact;

	i = 0;
	contact = 0;
	if ((env->piece_y + row) > env->map_y || (env->piece_x + col) > env->map_x)	
		return (0);
	while (i < env->piece_y)
	{
		j = 0;
		while (j < env->piece_x)
		{
			if ((row + i) >= env->map_y || (col + j) >= env->map_x)
				break ;
			if (env->piece[i][j] == '*' && (env->board[row + i][col + j] == env->enemy))
				return (0);
			if (env->piece[i][j] == '*' && (env->board[row + i][col + j] == env->player))
				contact++;
			j++;	
		}
		i++;
	}
	if (contact == 1)
	{
		env->pos_y = row;
		env->pos_x = col;
		return (1);
	}
	return (0);
}
