/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallete <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 00:37:51 by avallete          #+#    #+#             */
/*   Updated: 2015/02/28 17:00:14 by avallete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wong.h>

void	grep_window_value(t_env *env)
{
	getmaxyx(stdscr, env->win.win_y, env->win.win_x);
	env->win.win_y--;
	env->win.win_x--;
	while (((WINY(env) - 1) % 4))
		WINY(env)--;
	while ((WINY(env) % 2) != 0)
		WINY(env)--;
	if (WINX(env) < 24 || WINY(env) < 11)
	{
		clear();
		refresh();
		endwin();
		ft_putsterr("\nWindow size too small\n");
		env->infos.echap = 1;
	}
}

void	youlose(void)
{
	clear();
	refresh();
	ft_printf("\n\n YOU LOSE !!! AHAHAH LOSER !\n");
}

void	add_numbers(t_env *env)
{
	int x;
	int y;

	y = 0;
	while (y < 4)
	{
		x = 0;
		while (x < 4)
		{
			if (CASEV(x, y) != 0)
				mvprintw(CASEY(x, y), CASEX(x, y), CASESTR(x, y));
			x++;
		}
		y++;
	}
}

void	expose_term(t_env *env)
{
	clear();
	init_tab_place(env);
	draw_tab(env);
	add_numbers(env);
	refresh();
}

void	new_window(void)
{
	initscr();
	noecho();
	curs_set(FALSE);
}