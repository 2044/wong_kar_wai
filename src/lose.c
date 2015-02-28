/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lose.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabadie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 15:50:55 by jabadie           #+#    #+#             */
/*   Updated: 2015/02/28 19:03:32 by avallete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wong.h"

int		check_ln(t_env *env)
{
	int	j;
	int	i;

	j = 0;
	while (j < 4)
	{
		i = 1;
		while (i < 4)
		{
			if (CASEV(i, j) == 0 || CASEV(i, j) == CASEV(i, (j - 1)))
				return (1);
			i++;
		}
		j++;
	}
	return (0);
}

int		check_col(t_env *env)
{
	int	j;
	int	i;

	i = 0;
	while (i < 4)
	{
		j = 1;
		while (j < 4)
		{
			if (CASEV(j, i) == CASEV((i - 1), j))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	game_over(t_env *env)
{
	if (check_ln(env) == 1 && check_col(env) == 1)
	{
		clear();
		mvprintw(WINY(env) / 2, WINX(env) / 2, "YOU LOOSE !!!");
		refresh(), sleep(3);
		env->infos.echap = 1;
	}
}

int		win_or_not(t_env *env)
{
	int	i;
	int	j;
	t_const win_val;

	win_val = WIN_VALUE;
	j = 0;
	while (j < 4)
	{
		i = 0;
		while (i < 4)
		{
			if (CASEV(i, j) == win_val && env->infos.win == 0)
			{
				clear(), mvprintw(WINY(env) / 2, WINX(env) / 2, "YOU WIN !!!");
				refresh(), sleep(3);
				env->infos.win = 1;
				return (1);
			}
			i++;
		}
		j++;
	}
	return (0);
}
