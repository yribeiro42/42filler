/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yribeiro <yribeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 11:56:31 by yribeiro          #+#    #+#             */
/*   Updated: 2018/02/13 16:53:12 by yribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "../libft/libft.h"
# include "colors.h"
#include <stdio.h>

typedef	struct	s_env
{
	int			map_x;
	int			map_y;
	int			player;
	int			piece_x;
	int			piece_y;
	char		**board;
	char		**piece;
}				t_env;


int		read_map(t_env *env);
int		get_player(t_env *env, char *line);
int		get_coord(t_env *env, char *line);
int		get_board(t_env *env);
void	print_piece(t_env *env);
int		get_piece(t_env *env, char *line);
int		make_piece(t_env *env);
int		place_piece(t_env *env);

#endif