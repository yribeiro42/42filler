/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yribeiro <yribeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 12:24:14 by yribeiro          #+#    #+#             */
/*   Updated: 2018/02/21 13:15:26 by yribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	print_board(t_env *env)
{
	int		i;

	i = 0;
	dprintf(2, "\n[map_y : %d][map_x : %d]\n\n", env->map_y, env->map_x);
	while (i < env->map_y)
	{
		dprintf(2, "%03d  %s\n", i, env->board[i]);
		i++;
	}
}

void	get_player(t_env *env)
{
	char	*lookup;

	get_next_line(0, &lookup);
	dprintf(2, "[%s]\n", lookup);
	lookup += 10;
	env->player = *lookup - '0';
}

void	get_coord(t_env *env)
{
	char	*lookup;

	get_next_line(0, &lookup);
	dprintf(2, "[%s]\n", lookup);
	lookup += 8;
	env->map_y = ft_atoi(lookup);
	while (ft_isdigit(*lookup))
		lookup++;
	env->map_x = ft_atoi(lookup);
}

void	get_board(t_env *env)
{
	char	*line;
	int		i;

	get_next_line(0, &line);
	dprintf(2, "[%s]\n", line);
	env->board = ft_memalloc(env->map_y);
	i = 0;
	while (i < env->map_y)
	{
		get_next_line(0, &line);
		dprintf(2, "[%s]\n", line);
		line += 4;
		env->board[i] = line;
		i++;
	}
	print_board(env);
}
