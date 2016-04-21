/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboualla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/05 10:45:40 by yboualla          #+#    #+#             */
/*   Updated: 2016/04/03 14:31:34 by yboualla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char		**create_map(int map_size)
{
	int		i;
	char	**map;

	i = 0;
	if (!(map = (char**)malloc((sizeof(char*) * map_size) + 1)))
		return (NULL);
	while (i < map_size)
		if (!(map[i++] = (char*)malloc((sizeof(char) * map_size) + 1)))
			return (NULL);
	init_map(map, map_size);
	return (map);
}

void		init_map(char **map, int map_size)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < map_size)
	{
		while (j < map_size)
		{
			map[i][j] = '.';
			j++;
		}
		map[i][j] = '\0';
		j = 0;
		i++;
	}
}

int			addtomap(t_tetr *tetr, char **map, int *pos, int map_size)
{
	int		i;
	int		j;

	i = pos[0] + (pos[1] * map_size);
	j = tetr->posx + (tetr->posy * 5);
	if (col_check(tetr, map, pos, map_size))
		return (0);
	while (tetr->data[j] != '\0')
	{
		if ((map_size != 2) && (i == map_size * map_size))
			return (1);
		if (tetr->data[j] == '#')
			map[(i / map_size)]
				[(i % map_size)] = tetr->letter;
		if (tetr->data[j] == '\n')
			i += map_size - 5;
		i++;
		j++;
	}
	return (1);
}

void		printmap(char **map, int map_size)
{
	int		i;

	i = 0;
	while (i < map_size)
	{
		ft_putstr(map[i]);
		ft_putchar('\n');
		i++;
	}
}
