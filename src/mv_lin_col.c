/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabadxe <marvxn@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 13:06:47 by yabadxe           #+#    #+#             */
/*   Updated: 2015/02/28 21:21:26 by avallete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wong.h"

unsigned int	find_next_nb(t_env *env, int y, int x, int f)
{
	int	nb;

	while (LR_0(x, f))
	{
		printf("i: %d\n", x);
		if (CASEV(x, y) != 0)
		{
			nb = CASEV(x, y);
			CASEV(x, y) = 0;
			return (nb);
		}
		x = ML(x, f);
	}
	return (0);
}

void	tab_mvline(t_env *env, int y, int x, int f)
{
	while (LR(x, f))
	{
		if (CASEV(x, y) == 0)
			CASEV(x, y) = find_next_nb(env, y, x, f);
		else
		{
			if (CASEV(ML(x, f), y) == 0)
				CASEV(ML(x, f), y) = find_next_nb(env, y, ML(x, f), f);
			if (CASEV(x, y) == CASEV(ML(x, f), y))
			{
				CASEV(ML(x, f), y) = 0;
				CASEV(x, y) *= 2;
			}
		}
		x = ML(x, f);
	}
}

unsigned int	find_next_nb_col(t_env *env, int y, int x, int f)
{
	int	nb;

	while (LR_0(y, f))
	{
		if (CASEV(x, y) != 0)
		{
			nb = CASEV(x, y);
			CASEV(x, y) = 0;
			return (nb);
		}
		y = ML(y, f);
	}
	return (0);
}

void	tab_mvcol(t_env *env, int y, int x, int f)
{
	while (LR(y, f))
	{
		if (CASEV(x, y) == 0)
			CASEV(x, y) = find_next_nb_col(env, y, x, f);
		else
		{
			if (CASEV(x, ML(y, f)) == 0)
				CASEV(x, ML(y, f)) = find_next_nb_col(env, ML(y, f), x, f);
			if (CASEV(x, y) == CASEV(x, ML(y, f)))
			{
				CASEV(x, ML(y, f)) = 0;
				CASEV(x, y) *= 2;
			}
		}
		y = ML(y, f);
	}
}
