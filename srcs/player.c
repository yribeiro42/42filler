/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skitoak <skitoak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 15:26:16 by yribeiro          #+#    #+#             */
/*   Updated: 2018/04/17 17:25:38 by skitoak          ###   ########.fr       */
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
				{
					env->my_pos_x = y;
					env->my_pos_y = i;
					//dprintf(2, "my_pos = %d %d\n", env->my_pos_y, env->my_pos_x);
				}
			if (env->board[i][y] == env->enemy)
				{
					env->en_pos_x = y;
					env->en_pos_y = i;
				}
			y++;
		}
		i++;
	}
	return (-1);
}

int		place_piece4(t_env *env)
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

int		place_piece3(t_env *env)
{
	int		row;
	int		col;
	int		ret;

	row = env->map_y;
	while (row-- > 0)
	{
		col = 0;
		while (col++ < env->map_x)
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

int		place_piece2(t_env *env)
{
	int		row;
	int		col;
	int		ret;

	row = 0;
	while (row++ < env->map_y)
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

int		place_piece1(t_env *env)
{
	int		row;
	int		col;
	int		ret;

	row = 0;
	while (row++ < env->map_y)
	{
		col = 0;
		while (col++ < env->map_x)
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

	i = env->start_y;
	contact = 0;
	if ((env->real_piece_y + row) > env->map_y || (env->real_piece_x + col) > env->map_x)	
		return (0);
	while (i <= env->end_y)
	{
		j = env->start_x;
		while (j <= env->end_x)
		{
			if ((row + i - env->start_y) >= env->map_y || (col + j - env->start_x) >= env->map_x)
				break ;
			if (env->piece[i][j] == '*' && (env->board[row + i - env->start_y][col + j - env->start_x] == env->enemy))
				return (0);
			if (env->piece[i][j] == '*' && (env->board[row + i - env->start_y][col + j - env->start_x] == env->player))
				contact++;
			j++;	
		}
		i++;
	}
	if (contact == 1)
	{
		env->pos_y = row - env->start_y;
		env->pos_x = col - env->start_x;
		return (1);
	}
	return (0);
}
