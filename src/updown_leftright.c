/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   updown_leftright.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabadie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 14:27:14 by jabadie           #+#    #+#             */
/*   Updated: 2015/02/28 15:42:24 by jabadie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wong.h"

void	mv_left(int **tab)
{
	int	j;

	j = 0;
	while (j < 4)
	{
		tab_mvline(tab, j, 0, LEFT);
		j++;
	}
}

void	mv_right(int **tab)
{
	int	j;

	j = 0;
	while (j < 4)
	{
		tab_mvline(tab, j, 3, RIGHT);
		j++;
	}
}

void	mv_up(int **tab)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		tab_mvcol(tab, 0, i, UP);
		i++;
	}
}

void	mv_down(int **tab)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		tab_mvcol(tab, 3, i, DOWN);
		i++;
	}
}
