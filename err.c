/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboualla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/31 16:24:55 by yboualla          #+#    #+#             */
/*   Updated: 2016/04/07 17:07:36 by yboualla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		errmsg(int err)
{
	if (err == 1)
	{
		ft_putstr("error\n");
		exit(EXIT_SUCCESS);
	}
	else if (err == 2)
	{
		ft_putstr("usage: ./fillit source_file\n");
		exit(EXIT_FAILURE);
	}
	else
	{
		ft_putstr("error\n");
		exit(EXIT_FAILURE);
	}
}
