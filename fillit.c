/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboualla <yboualla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 15:29:29 by yboualla          #+#    #+#             */
/*   Updated: 2016/04/03 14:03:45 by yboualla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	delete_tetr(t_tetr *tetr, char **map, int *pos, int map_size)
{
	int		i;
	int		j;

	i = pos[0] + (pos[1] * map_size);
	j = tetr->posx + (tetr->posy * 5);
	while (tetr->data[j] != '\0' && i < map_size * map_size)
	{
		if (tetr->data[j] == '#')
			map[(i / map_size)]
				[(i % map_size)] = '.';
		if (tetr->data[j] == '\n')
			i += map_size - 5;
		i++;
		j++;
	}
	return (1);
}

int			recursive_solver(char **map, t_tetr *tetr, int map_size)
{
	int		*pos;

	pos = (int *)malloc(sizeof(int) * 2);
	if (tetr == NULL)
	{
		printmap(map, map_size);
		exit(1);
	}
	pos[1] = -1;
	while (++pos[1] < map_size)
	{
		pos[0] = -1;
		while (++pos[0] < map_size)
		{
			if (addtomap(tetr, map, pos, map_size))
			{
				recursive_solver(map, tetr->next, map_size);
				delete_tetr(tetr, map, pos, map_size);
			}
		}
	}
	return (0);
}

static int	*get_env(int *env, char *path, char **file)
{
	*file = readfile(path);
	env[0] = checkfile(*file);
	return (env);
}

int			main(int argc, char **argv)
{
	int		*env;
	char	*file;
	t_tetr	*liste_tetr;
	char	**tetr;
	int		i;

	if (argc != 2)
		errmsg(2);
	env = (int *)malloc(sizeof(int) * 2);
	env = get_env(env, argv[1], &file);
	if (env[0] == 0 || env[0] > 26)
		errmsg(0);
	tetr = save_tetr(env[0], file);
	i = -1;
	env[1] = 1;
	while (++i < env[0])
		if (i == 0)
			liste_tetr = create_lsttetr(tetr[i], 0);
		else
			add_lsttetr(liste_tetr, tetr[i]);
	while (++env[1])
		recursive_solver(create_map(env[1]), liste_tetr, env[1]);
	return (0);
}
