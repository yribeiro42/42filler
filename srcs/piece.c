/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piece.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yribeiro <yribeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 14:52:53 by yribeiro          #+#    #+#             */
/*   Updated: 2018/02/13 16:15:01 by yribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	print_piece(t_env *env)
{
	int		i;

	i = 0;
	dprintf(2, "[y : %d][x : %d]\n", env->piece_y, env->piece_x);
	while (i < env->piece_y)
	{
		dprintf(2, "%s\n", env->piece[i]);
		i++;
	}
}

int		get_piece(t_env *env, char *line)
{
	int		i;
	char	*lookup;

	lookup = line;
	while (ft_isalpha(*lookup))
		lookup++;
	lookup++;
	env->piece_x = ft_atoi(lookup);
	lookup++;
	env->piece_y = ft_atoi(lookup);
	return (0);
}

int		make_piece(t_env *env)
{
	char	*line;
	int		i;

	i = 0;
	env->piece = ft_memalloc(env->piece_y + 1);
	while (i < env->piece_y)
	{
		get_next_line(0, &line);
		env->piece[i++] = line;
	}
	print_piece(env);
	return (0);
}

int		place_piece(t_env *env)
{
	write(1, "4 4\n", 4);
	return (0);
}
