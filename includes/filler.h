/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skitoak <skitoak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 11:56:31 by yribeiro          #+#    #+#             */
/*   Updated: 2018/04/18 11:51:20 by skitoak          ###   ########.fr       */
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
	int			real_piece_x;
	int			real_piece_y;
	int			start_x;
	int			end_x;
	int			start_y;
	int			end_y;
	int			pos_x;
	int			pos_y;
	int			my_pos_x;
	int			my_pos_y;
	int			en_pos_x;
	int			en_pos_y;
	char		**board;
	char		**piece;
}				t_env;


void	get_player(t_env *env);
void	get_coord(t_env *env);
void	get_board(t_env *env);
int		print_piece(t_env *env);
void	get_piece(t_env *env);
void	make_piece(t_env *env);
int		place_piece1(t_env *env);
int		place_piece4(t_env *env);
void	get_position(t_env *env);
int		try_place(int row, int col, t_env *env);
int		send_position(t_env *env);
void	resize_piece(t_env *env);


#endif