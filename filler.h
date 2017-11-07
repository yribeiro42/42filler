/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yribeiro <yribeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 11:56:31 by yribeiro          #+#    #+#             */
/*   Updated: 2017/11/07 14:57:24 by yribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "libft/libft.h"
# include "colors.h"
#include <stdio.h>

typedef	struct	s_env
{
	int			map_x;
	int			map_y;
}				t_env;


int		read_map(void);

#endif

