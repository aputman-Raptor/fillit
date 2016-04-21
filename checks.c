/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboualla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 14:46:54 by yboualla          #+#    #+#             */
/*   Updated: 2016/04/07 17:45:54 by yboualla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	coldata_check(int *sharp, char map, char data, int type)
{
	if (type == 1)
	{
		if (*sharp == 4)
			return (0);
		return (1);
	}
	if (type == 2)
	{
		if (data == '#')
		{
			if (map != '.')
				return (1);
			*sharp = *sharp + 1;
		}
		return (0);
	}
	return (0);
}

static int	checkcharfile(int *c, int *i, int *line, char *file)
{
	if (*c < 4)
	{
		if (file[*i] == '.' || file[*i] == '#')
			*i = *i + 1;
		else
			return (0);
		*c = *c + 1;
	}
	if (*c == 4)
	{
		if (file[*i] != '\n')
			return (0);
		*i = *i + 1;
		*line = *line + 1;
		*c = 0;
	}
	return (1);
}

int			checktetr(t_tetr *tetr, int *sharp)
{
	int		liaison;
	int		i;
	int		cont;

	liaison = 0;
	i = -1;
	while (tetr->data[++i] != '\0')
		if (tetr->data[i] == '#')
		{
			if (tetr->data[i + 1] == '#')
				cont = ++liaison;
			if ((i - 1) >= 0 && tetr->data[i - 1] == '#')
				cont = ++liaison;
			if ((i + 5) < 20 && tetr->data[i + 5] == '#')
				cont = ++liaison;
			if ((i - 5) >= 0 && tetr->data[i - 5] == '#')
				cont = ++liaison;
			if (cont == 0)
				return (0);
			cont = 0;
			*sharp += 1;
		}
	if ((liaison != 8 && liaison != 6) || *sharp != 4)
		return (0);
	return (1);
}

int			checkfile(char *file)
{
	int		i;
	int		nbtetr;
	int		line;
	int		c;

	c = 0;
	i = 0;
	line = 0;
	nbtetr = 0;
	while (file[i] != '\0')
	{
		if (!(checkcharfile(&c, &i, &line, file)))
			return (0);
		if (line == 4)
		{
			nbtetr++;
			if (file[i] == '\0')
				return (nbtetr);
			else if (file[i++] == '\n')
				line = 0;
			else
				return (0);
		}
	}
	return (0);
}

int			col_check(t_tetr *tetr, char **map, int *pos, int map_size)
{
	int		x;
	int		y;
	int		data;
	int		sharp;

	x = pos[0] - 1;
	y = pos[1];
	sharp = 0;
	data = tetr->posx + (tetr->posy * 5);
	while (tetr->data[data] != '\0' && sharp < 4 && y < map_size)
	{
		++x;
		if (tetr->data[data] == '\n')
		{
			y++;
			x = pos[0];
			data += 1 + tetr->posx;
		}
		if (y == map_size || tetr->data[data] == '\0')
			return (coldata_check(&sharp, 'a', 'a', 1) ? 1 : 0);
		if (coldata_check(&sharp, map[y][x], tetr->data[data], 2) == 1)
			return (1);
		++data;
	}
	return (coldata_check(&sharp, 'a', 'a', 1) ? 1 : 0);
}
