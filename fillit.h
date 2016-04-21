/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboualla <yboualla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 17:08:49 by yboualla          #+#    #+#             */
/*   Updated: 2016/04/07 17:36:34 by yboualla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft.h"
# include "fcntl.h"
# define BUFF_SIZE 20

typedef struct		s_tetr
{
	char			*data;
	char			letter;
	int				posx;
	int				posy;
	struct s_tetr	*next;
}					t_tetr;

char				*readfile(char *path);

int					checkfile(char *file);
int					checktetr(t_tetr *tetr, int *sharp);
int					col_check(t_tetr *tetr, char **map, int *pos, int map_size);

char				**save_tetr(int nb_tetr, char *file);

t_tetr				*create_lsttetr(char *tetr, int nb);
void				add_lsttetr(t_tetr *liste_tetr, char *tetr);

void				init_map(char **map, int map_size);
char				**create_map(int map_size);
int					addtomap(t_tetr *tetr, char **map, int *pos, int map_size);
void				printmap(char **map, int map_size);

void				errmsg(int err);
int					recursive_solver(char **map, t_tetr *tetr, int map_size);

#endif
