/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lose.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabadie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 15:50:55 by jabadie           #+#    #+#             */
/*   Updated: 2015/02/28 17:31:30 by avallete         ###   ########.fr       */
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
			if (CASEV(j, i) == 0 || CASEV(j, i) == CASEV(j, (i - 1)))
				return (0);
			i++;
		}
		j++;
	}
	return (1);
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
			if (CASEV(j, i) == CASEV((j - 1), i))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	game_over(t_env *env)
{
	if (check_ln(env) == 0 && check_col(env) == 0)
		exit(0);
}

int		check_win_value(void)
{
	t_const	win;

	win = WIN_VALUE;
	if (win < 2)
		return (0);
	if ((win & (win - 1)) == 0)
		return (1);
	return (0);
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
			if (CASEV(j, i) == win_val)
				return (1);
			i++;
		}
		j++;
	}
	return (0);
}
