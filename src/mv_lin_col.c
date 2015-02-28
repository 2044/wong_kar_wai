/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabadie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 13:06:47 by jabadie           #+#    #+#             */
/*   Updated: 2015/02/28 15:55:44 by jabadie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wong.h"

int	tab_mvline(int **tab, int j, int i, int f)
{
	if ((f == LEFT && i == 4) || (f == RIGHT && i == -1))
		return (0);
	if (tab[j][i] == 0)
	{
		tab[j][i] = tab_mvline(tab, j, LR(i, f), f);
		if ((f == LEFT && i != 3) || (f == RIGHT && i != 0))
			tab[j][LR(i, f)] = 0;
	}
	else if (tab[j][i] == tab_mvline(tab, j, LR(i, f), f))
	{
		tab[j][i] *= 2;
		if ((f == LEFT && i != 3) || (f == RIGHT && i != 0))
			tab[j][LR(i ,f)] = 0;
	}
	return (tab[j][i]);
}

int	tab_mvcol(int **tab, int j, int i, int f)
{
	if ((f == UP && j == 4) || (f == DOWN && j == -1))
		return (0);
	if (tab[j][i] == 0)
	{
		tab[j][i] = tab_mvcol(tab, LR(j, f), i, f);
		if ((f == UP && j != 3) || (f == DOWN && j != 0))
			tab[LR(j, f)] = 0;
	}
	else if (tab[j][i] == tab_mvcol(tab, LR(j, f), i, f))
	{
		tab[j][i] *= 2;
		if ((f == UP && j != 3) || (f == DOWN && j != 0))
			tab[LR(j, f)][i] = 0;
	}
	return (tab[j][i]);
}
