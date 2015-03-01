/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallete <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 12:20:09 by avallete          #+#    #+#             */
/*   Updated: 2015/03/01 14:33:12 by avallete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wong.h>

void	init_inf(t_env *env)
{
	env->infos.dep = 0;
	env->infos.join = 0;
}

void	play_it(t_env *env)
{
	signal(SIGINT, SIG_IGN);
	keypad(stdscr, TRUE);
	while ((1 && (!(env->infos.echap))))
	{
		expose_term(env);
		grep_window_value(env), expose_term(env);
		init_inf(env);
		key_hook(env, wgetch(stdscr));
	}
	if (env->infos.echap)
		clear(), refresh(), endwin();
}
