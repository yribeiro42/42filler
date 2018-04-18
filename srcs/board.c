/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skitoak <skitoak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 12:24:14 by yribeiro          #+#    #+#             */
/*   Updated: 2018/04/18 11:48:51 by skitoak          ###   ########.fr       */
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
	int		player;

	get_next_line(0, &lookup);
	lookup += 10;
	player = *lookup - '0';
	env->player = (player - 1) ? 'X' : 'O';
	env->enemy = (player - 1) ? 'O' : 'X';
}

void	get_coord(t_env *env)
{
	char	*lookup;

	get_next_line(0, &lookup);
	lookup += 8;
	env->map_y = ft_atoi(lookup);
	while (ft_isdigit(*lookup))
		lookup++;
	env->map_x = ft_atoi(lookup);
	get_board(env);
}

void	get_board(t_env *env)
{
	char	*line;
	int		i;

	if (!(get_next_line(0, &line)))
		return ;
	env->board = ft_memalloc(sizeof(char *) * (env->map_y + 1));
	i = 0;
	while (i < env->map_y)
	{
		get_next_line(0, &line);
		line += 4;
		env->board[i] = line;
		i++;
	}
	get_piece(env);
	print_board(env);
	get_position(env);
}
