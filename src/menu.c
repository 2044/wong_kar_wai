/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallete <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 13:15:06 by avallete          #+#    #+#             */
/*   Updated: 2015/03/01 13:39:02 by avallete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wong.h>

void	new_game(t_env *env)
{
	init_tab(env);
	add_nb(env);
	add_nb(env);
	modify_tab(env);
	play_it(env);
}

void	print_invakey(t_env *env)
{
	clear(), mvprintw(WINY(env) / 2, WINX(env) / 2, "Invalid Key\n");
	refresh();
}

void	key_menu(t_env *env, int c)
{
	if (c == 110)
		new_game(env);
	if (c == 113 || c == K_ECHAP)
		clear(), refresh(), env->infos.echap = 1, endwin();
}

void	print_menu(t_env *env)
{
	int c;

	clear();
	while ((!(env->infos.echap)))
	{
		mvprintw(WINY(env) / 2, WINX(env) / 2, "Menu:");
		mvprintw((WINY(env) / 2) + 1, (WINX(env) / 2) - 1, "n : New Game");
		mvprintw((WINY(env) / 2) + 2, (WINX(env) / 2) - 1, "q : Quit Game :'(");
		c = wgetch(stdscr);
		if (c == 110 || c == 113 || c == K_ECHAP)
			key_menu(env, c);
		else
			print_invakey(env), usleep(150000), clear();
		refresh();
	}
}

void	ft_menu(t_env *env)
{
	grep_window_value(env);
	print_menu(env);
}
