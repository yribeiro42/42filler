/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yribeiro <yribeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 12:39:52 by yribeiro          #+#    #+#             */
/*   Updated: 2018/02/16 15:44:54 by yribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		main(void)
{
	t_env	*env;

	env = ft_memalloc(sizeof(t_env));

	get_player(env);
	get_coord(env);
	get_board(env);
	get_piece(env);
	make_piece(env);
	place_piece(env);
	return (0);
}