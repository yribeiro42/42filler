/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yribeiro <yribeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 12:39:52 by yribeiro          #+#    #+#             */
/*   Updated: 2018/02/28 21:26:41 by yribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		main(void)
{
	t_env	*env;

	if (!(env = ft_memalloc(sizeof(t_env))))
		return (0);
	get_player(env);
	while (1)
	{
		get_coord(env);
		get_board(env);
		get_piece(env);
		make_piece(env);
		place_piece(env);
	}
	return (0);
}
