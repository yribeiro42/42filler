/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yribeiro <yribeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 11:56:31 by yribeiro          #+#    #+#             */
/*   Updated: 2018/02/22 15:59:13 by yribeiro         ###   ########.fr       */
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
	char		player;
	char		enemy;
	int			piece_x;
	int			piece_y;
	int			pos_x;
	int			pos_y;
	char		**board;
	char		**piece;
}				t_env;


void	get_player(t_env *env);
void	get_coord(t_env *env);
void	get_board(t_env *env);
void	print_piece(t_env *env);
void	get_piece(t_env *env);
void	make_piece(t_env *env);
int		place_piece(t_env *env);
int		get_position(t_env *env);

#endif