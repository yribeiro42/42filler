/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piece.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yribeiro <yribeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 14:52:53 by yribeiro          #+#    #+#             */
/*   Updated: 2018/02/21 16:44:05 by yribeiro         ###   ########.fr       */
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
	print_piece(env);
}
