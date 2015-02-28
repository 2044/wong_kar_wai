/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabadxe <marvxn@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 13:06:47 by yabadxe           #+#    #+#             */
/*   Updated: 2015/02/28 20:50:16 by avallete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wong.h"

unsigned int	tab_mvline(t_env *env, int y, int x, int f)
{
	if ((f == LEFT && x == 4) || (f == RIGHT && x == -1))
		return (0);
	if (CASEV(x, y) == 0)
	{
		CASEV(x, y) = tab_mvline(env, y, LR(x, f), f);
		if ((f == LEFT && x != 3) || (f == RIGHT && x != 0))
			CASEV(LR(x, f), y) = 0;
	}
	else if (CASEV(x, y) == tab_mvline(env, y, LR(x, f), f))
	{
		CASEV(x, y) *= 2;
		mvprintw(CASEY(x, y), CASEX(x, y), "*/*\\*");
		refresh();
		usleep(100000);
		if ((f == LEFT && x != 3) || (f == RIGHT && x != 0))
			CASEV(LR(x, f), y) = 0;
	}
	return (CASEV(x, y));
}

unsigned int	tab_mvcol(t_env *env, int y, int x, int f)
{
	if ((f == UP && y == 4) || (f == DOWN && y == -1))
		return (0);
	if (CASEV(x, y) == 0)
	{
		CASEV(x, y) = tab_mvcol(env, LR(y, f), x, f);
		if ((f == UP && y != 3) || (f == DOWN && y != 0))
			CASEV(x, LR(y, f)) = 0;
	}
	else if (CASEV(x, y) == tab_mvcol(env, LR(y, f), x, f))
	{
		CASEV(x, y) *= 2;
		mvprintw(CASEY(x, y), CASEX(x, y), "*/*\\*");
		refresh();
		usleep(100000);
		if ((f == UP && y != 3) || (f == DOWN && y != 0))
			CASEV(x, LR(y, f)) = 0;
	}
	return (CASEV(x, y));
}
