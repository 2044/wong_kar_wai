/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallete <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 00:45:26 by avallete          #+#    #+#             */
/*   Updated: 2015/02/28 21:21:56 by avallete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wong.h>

void	init_numbercolor(void)
{
	start_color();
	init_pair(0, COLOR_WHITE, COLOR_BLACK);
	init_pair(1, COLOR_CYAN, COLOR_BLACK);
	init_pair(2, COLOR_YELLOW, COLOR_BLACK);
	init_pair(3, COLOR_RED, COLOR_BLACK);
	init_pair(4, COLOR_GREEN, COLOR_BLACK);
	init_pair(5, COLOR_MAGENTA, COLOR_BLACK);
}

void	key_hook(t_env *env, int c)
{
	if (c == K_ECHAP)
		env->infos.echap = 1;
	if (c == 119 || c == 115)
	{
		c == 119 ? mv_up(env) : mv_down(env);
		add_nb(env);
		modify_tab(env);
		game_over(env);
		win_or_not(env);
	}
	if (c == 97 || c == 100)
	{
		c == 97 ? mv_left(env) : mv_right(env);
		add_nb(env);
		modify_tab(env);
		game_over(env);
		win_or_not(env);
	}
}

void	play_it(t_env *env)
{
	signal(SIGINT, SIG_IGN);
	while ((1 && (!(env->infos.echap))))
	{
		expose_term(env);
		grep_window_value(env), expose_term(env);
		key_hook(env, getch());
	}
	if (env->infos.echap)
		clear(), refresh(), endwin();
}

int	main(void)
{
	t_env	env;
	enum	WIN_VALUE;

	env.def = WIN_VALUE;
	env.infos.echap = 0;
	env.infos.win = 0;
	if (((WIN_VALUE & (WIN_VALUE - 1)) == 0) && WIN_VALUE >= 2)
	{
		new_window();
		clear();
		use_default_colors();
		init_numbercolor();
		grep_window_value(&env);
		init_tab(&env);
		add_nb(&env);
		add_nb(&env);
		modify_tab(&env);
		play_it(&env);
	}
	else
		ft_printf("Error bad WIN_VALUE, not 2 pow");
	return (0);
}
