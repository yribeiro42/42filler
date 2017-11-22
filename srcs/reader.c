/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yribeiro <yribeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 12:24:14 by yribeiro          #+#    #+#             */
/*   Updated: 2017/11/22 23:19:17 by yribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

// int		read_map(t_env *env)
// {
// 	char	*line;
// 	int		ret;

// 	while (get_next_line(0, &line) != 0)
// 	{
// 		if (!env->player && ft_strstr(line, "./yribeiro.filler"))
// 		{
// 			env->player = get_player(env, line);
// 		}
// 		if (ft_strncmp(line, "Plateau", 7) == 0)
// 		{
// 			get_coord(env, line);
// 		}
// 		dprintf(2, GRN "%s\n" RESET, line);
// 		get_board(env, line);
// 		ft_strdel(&line);
// 	}
// 	return (0);
// }

int		read_map(t_env *env)
{
	char	*line;
	int		ret;

	get_next_line(0, &line);
	if (!env->player && ft_strstr(line, "./yribeiro.filler"))
		env->player = get_player(env, line);
	get_next_line(0, &line);
	if (ft_strncmp(line, "Plateau", 7) == 0)
		get_coord(env, line);
	get_next_line(0, &line);
	get_board(env);
	return (0);
}

// int		get_board(t_env *env, char *line)
// {
// 	int		i;
// 	int		j;

// 	i = 0;
// 	env->board = malloc(sizeof(char) * env->map_y);
// 	while (i++ < env->map_y)
// 	{
// 		env->board[i] = malloc(sizeof(char) * env->map_x);
// 		while (j < env->map_x)
// 		{
// 			env->board[i][j] = 'x';
// 			dprintf(2, RED "%c" RESET, env->board[i][j]);
// 			j++;
// 		}
// 		dprintf(2, RED "\n" RESET);
// 	}
// 	return (0);
// }

void	print_board(t_env *env)
{
	int	i;

	i = 0;
	dprintf(2, "[y : %d][x : %d]\n", env->map_y, env->map_x);
	while (i < env->map_y)
	{
		dprintf(2,"%03d : [%s]\n",i, env->board[i]);
		i++;
	}
}
void	init_board(t_env *env)
{
	int		i;
	
	i = 0;
	env->board = ft_memalloc(env->map_y + 1);
}

int		get_board(t_env *env)
{
	char	*line;
	int		i;
	int		y;

	init_board(env);
	i = 0;
	while (i < env->map_y)
	{
		get_next_line(0, &line);
		line += 4;
		env->board[i++] = line;
	}
	print_board(env);
	return (0);
}

int		get_coord(t_env *env, char *line)   // board size
{
	char *lookup;

	lookup = line;
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
	return (0);
}

int		get_player(t_env *env, char *line)
{
	char	*lookup;

	lookup = line;
	while (*lookup != 'p')
		lookup++;
	lookup++;
	return (*lookup - '0');
}
