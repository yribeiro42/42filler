/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piece.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yribeiro <yribeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 14:52:53 by yribeiro          #+#    #+#             */
/*   Updated: 2018/02/16 15:46:08 by yribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	print_piece(t_env *env)
{
	int		i;

	i = 0;
	dprintf(2, "\nPiece %d %d:\n", env->piece_y, env->piece_x);
	while (i < env->piece_y)
	{
		dprintf(2, "%s\n", env->piece[i]);
		i++;
	}
}

void	get_piece(t_env *env)
{
	int		i;
	char	*lookup;

	get_next_line(0, &lookup);
	while (ft_isalpha(*lookup))
		lookup++;
	lookup++;
	env->piece_y = ft_atoi(lookup);
	lookup++;
	env->piece_x = ft_atoi(lookup);
}

void	make_piece(t_env *env)
{
	char	*line;
	int		i;

	i = 0;
	env->piece = ft_memalloc(env->piece_y);
	while (i < env->piece_y)
	{
		get_next_line(0, &line);
		env->piece[i] = line;
		i++;
	}
	//print_piece(env);
}

int		place_piece(t_env *env)
{
	int		pos;

	pos = get_position(env);
	printf("%d %d\n", pos / env->map_x, pos % env->map_x);
	dprintf(2, "\nY:%d X:%d\n", pos / env->map_x, pos % env->map_x);
	return (0);
}

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
