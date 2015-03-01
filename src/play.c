/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallete <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 12:20:09 by avallete          #+#    #+#             */
/*   Updated: 2015/03/01 13:31:25 by avallete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wong.h>

void	play_it(t_env *env)
{
	signal(SIGINT, SIG_IGN);
	keypad(stdscr, TRUE);
	while ((1 && (!(env->infos.echap))))
	{
		expose_term(env);
		grep_window_value(env), expose_term(env);
		key_hook(env, wgetch(stdscr));
	}
	if (env->infos.echap)
		clear(), refresh(), endwin();
}
