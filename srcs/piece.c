/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piece.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yribeiro <yribeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 14:52:53 by yribeiro          #+#    #+#             */
/*   Updated: 2018/03/01 16:31:10 by yribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		print_piece(t_env *env)
{
	int		i;

	i = 0;
	while (i < env->piece_y)
	{
		dprintf(2, "[i%d][%s]\n", i, env->piece[i]);
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
	//print_piece(env);
}
