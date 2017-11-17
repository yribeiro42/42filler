/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yribeiro <yribeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 12:24:14 by yribeiro          #+#    #+#             */
/*   Updated: 2017/11/17 15:03:22 by yribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		read_map(t_env *env)
{
	char	*line;
	int		ret;

	//line = NULL;
	while (get_next_line(0, &line) != 0)
	{
		if (!env->player && ft_strstr(line, "./yribeiro.filler"))
		{
			env->player = get_player(env, line);
		}
		//dprintf(2, YEL "%s\n" RESET, line);
		if (ft_strstr(line, "Plateau"))
		{
			dprintf(2, RED "%s\n" RESET, line);
			get_coord(env, line);
		}
		ft_strdel(&line);
	}
	return (0);
}

int		get_coord(t_env *env, char *line)
{
	char *lookup;

	lookup = line;
	while (ft_isalpha(*lookup))
		lookup++;
	lookup++;
	while (ft_isdigit(*(lookup++)))
	{
		env->map_x = env->map_x * 10 + (*lookup - '0');
		//lookup++;
	}
	lookup++;
	while (ft_isdigit(*lookup))
	{
		env->map_y = env->map_y * 10 + (*lookup - '0');
		lookup++;
	}
	dprintf(2, YEL "[%d]" RESET, env->map_x);
	dprintf(2, BLU "[%d]" RESET, env->map_y);
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
