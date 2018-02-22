/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yribeiro <yribeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/26 15:25:33 by lcharvol          #+#    #+#             */
/*   Updated: 2018/02/22 15:26:55 by yribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int		ft_is_placable2(t_piece *p, int count, int i, int i2)
{
	if (count == 1)
	{
		p->final_x = i2;
		p->final_y = i;
		return (0);
	}
	return (1);
}

int		ft_algo3_2(int nbr_contact, t_piece *p, t_map *map)
{
	if (nbr_contact == -1)
		return (0);
	p->final_x = p->tmp_x;
	p->final_y = p->tmp_y;
	ft_print_result(p, map);
	return (1);
}

int		ft_algo2(t_map *map, t_piece *p)
{
	int	i;
	int	i2;
	int	ret;

	i = map->map_size_y;
	p->final_x = 0;
	p->final_y = 0;
	ret = 0;
	while (i > 0)
	{
		i2 = map->map_size_x;
		while (i2 > 0)
		{
			ret = ft_is_placable(i, i2, map, p);
			if (ret == 0)
			{
				ft_print_result(p, map);
				return (0);
			}
			i2--;
		}
		i--;
	}
	return (1);
}

int		ft_is_placable(int i, int i2, t_map *map, t_piece *p)
{
	int j;
	int j2;
	int count;

	j = -1;
	count = 0;
	if (i + p->size_y > map->map_size_y || i2 + p->size_x > map->map_size_x)
		return (1);
	while (++j <= (p->size_y - 1))
	{
		j2 = -1;
		while (++j2 <= (p->size_x - 1))
		{
			if (p->piece[j][j2] == '*' && (map->map[i + j][i2 + j2] ==
				map->en[0] || map->map[i + j][i2 + j2] ==
				map->en[0] - 32))
				return (1);
			if (p->piece[j][j2] == '*' && (map->map[i + j][i2 + j2] ==
				map->me[0] || map->map[i + j][i2 + j2] == map->me[0] - 32))
				count++;
		}
	}
	if (ft_is_placable2(p, count, i, i2) == 0)
		return (0);
	return (1);


int		ft_algo2_2(t_map *map, t_piece *p)
{
	int	i;
	int	i2;
	int	ret;

	i = map->map_size_y;
	p->final_x = 0;
	p->final_y = 0;
	ret = 0;
	while (i > 0)
	{
		i2 = -1;
		while (++i2 < map->map_size_x)
		{
			ret = ft_is_placable(i, i2, map, p);
			if (ret == 0)
			{
				ft_print_result(p, map);
				return (0);
			}
		}
		i--;
	}
	return (1);
}
