/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piece.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yribeiro <yribeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 14:52:53 by yribeiro          #+#    #+#             */
/*   Updated: 2018/03/29 14:24:49 by yribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		print_piece(t_env *env)
{
	int		i;

	i = 0;
	dprintf(2, "Piece %d %d:\n", env->piece_y, env->piece_x);
	while (i < env->piece_y)
	{
		dprintf(2, "[%s]\n", env->piece[i]);
		i++;
	}
	return (0);
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
	env->piece = ft_memalloc(sizeof(char*) * (env->piece_y + 1));
	while (i < env->piece_y)
	{
		get_next_line(0, &line);
		env->piece[i] = line;
		i++;
	}
	print_piece(env);
}

void	resize_piece(t_env *env)
{
	int		i;
	int		y;

	y = 0;
	env->start_x = env->piece_x;
	env->start_y = env->piece_y;
	env->end_x = 0;
	env->end_y = 0;
	while (y < env->piece_y)
	{
		i = 0;
		while (i < env->piece_x)
		{
			if (env->piece[y][i] == '*')
			{
				if (i < env->start_x)
					env->start_x = i;
				if (i > env->end_x)
					env->end_x = i;
				if (y < env->start_y)
					env->start_y = y;
				if (y > env->end_y)
					env->end_y = y;
			}
			i++;
		}
		y++;
	}
	env->real_piece_x = env->end_x - env->start_x;
	env->real_piece_y = env->end_y - env->start_y;
	dprintf(2, "real size: %d %d\n", env->real_piece_y, env->real_piece_x);
	dprintf(2, "start_x = [%d] end_x = [%d]\n", env->start_x, env->end_x);
	dprintf(2, "start_y = [%d] end_y = [%d]\n\n", env->start_y, env->end_y);
}
