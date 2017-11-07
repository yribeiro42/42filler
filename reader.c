/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yribeiro <yribeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 12:24:14 by yribeiro          #+#    #+#             */
/*   Updated: 2017/11/07 14:54:40 by yribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		read_map(void)
{
	char	*line;

	printf(RED "1\n" RESET);
	while (get_next_line(0, &line) == 1)
	{
		printf(RED "%s\n" RESET, line);
	}
	return (0);
}