/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yribeiro <yribeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 12:24:14 by yribeiro          #+#    #+#             */
/*   Updated: 2017/11/09 15:50:48 by yribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		read_map(t_env *env)
{
	char	*line;
	int		ret;

	line = NULL;
	while (get_next_line(STDIN_FILENO, &line) != 0)
	{
		if (!env->player && ft_strstr(line, "./yribeiro.filler"))
		{
			env->player = get_player(env, line);
			dprintf(STDERR_FILENO, YEL "[%d]" RESET, env->player);
		}
		dprintf(2, RED "%s\n" RESET, line);
		if (ft_strncmp(line, "Plateau", 2) == 0)
		{
			dprintf(STDERR_FILENO, RED "%s\n" RESET, line);
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
	while (ft_isdigit(*lookup))
	{
		env->map_x = env->map_x * 10 + (*lookup - '0');
		lookup++;
	}
	dprintf(STDERR_FILENO, YEL "[%d]" RESET, env->map_x);
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
