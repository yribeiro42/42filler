/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yribeiro <yribeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 12:24:14 by yribeiro          #+#    #+#             */
/*   Updated: 2018/02/16 15:46:20 by yribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	print_board(t_env *env)
{
	int		i;

	i = 0;
	dprintf(2, "[map_y : %d][map_x : %d]\n\n", env->map_y, env->map_x);
	while (i < env->map_y)
	{
		dprintf(2, "%03d %s\n", i, env->board[i]);
		i++;
	}
}

void	get_player(t_env *env)
{
	char	*lookup;

	get_next_line(0, &lookup);
	lookup += 10;
	env->player = *lookup - '0';
}

void	get_coord(t_env *env)
{
	char	*lookup;

	get_next_line(0, &lookup);
	while (ft_isalpha(*lookup))
		lookup++;
	lookup++;
	while (ft_isdigit(*lookup))
	{
		env->map_y = env->map_y * 10 + (*lookup - '0');
		lookup++;
	}
	lookup++;
	while (ft_isdigit(*lookup))
	{
		env->map_x = env->map_x * 10 + (*lookup - '0');
		lookup++;
	}
}

void	get_board(t_env *env)
{
	char	*line;
	int		i;

	get_next_line(0, &line);
	env->board = ft_memalloc(env->map_y);
	i = 0;
	while (i < env->map_y)
	{
		get_next_line(0, &line);
		line += 4;
		env->board[i] = line;
		i++;
	}
	//print_board(env);
}
