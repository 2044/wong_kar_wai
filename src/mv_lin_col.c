/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabadie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 13:06:47 by jabadie           #+#    #+#             */
/*   Updated: 2015/02/28 18:10:49 by avallete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wong.h"

unsigned int	tab_mvline(t_env *env, int j, int i, int f)
{
//	ft_printf("call funct %d\n i is %d\n", j, i);
	if ((f == LEFT && i == 4) || (f == RIGHT && i == -1))
		return (0);
	if (CASEV(i, j) == 0)
	{
		ft_printf("adj is 0\n");
		CASEV(i, j) = tab_mvline(env, j, LR(i, f), f);
		if ((f == LEFT && i != 3) || (f == RIGHT && i != 0))
			CASEV(LR(i, f), j) = 0;
	}
	else if (CASEV(i, j) == tab_mvline(env, j, LR(i, f), f))
	{
		CASEV(i, j) *= 2;
		ft_printf("adj isn't 0\n");
		if ((f == LEFT && i != 3) || (f == RIGHT && i != 0))
			CASEV(LR(i, f), j) = 0;
	}
	return (CASEV(i, j));
}

unsigned int	tab_mvcol(t_env *env, int j, int i, int f)
{
	if ((f == UP && j == 4) || (f == DOWN && j == -1))
		return (0);
	if (CASEV(i, j) == 0)
	{
		CASEV(i, j) = tab_mvcol(env, LR(j, f), i, f);
		if ((f == UP && j != 3) || (f == DOWN && j != 0))
			CASEV(i, LR(j, f)) = 0;
	}
	else if (CASEV(i, j) == tab_mvcol(env, LR(j, f), i, f))
	{
		CASEV(i, j) *= 2;
		if ((f == UP && j != 3) || (f == DOWN && j != 0))
			CASEV(i, LR(j, f)) = 0;
	}
	return (CASEV(i, j));
}
