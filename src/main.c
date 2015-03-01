/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallete <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 00:45:26 by avallete          #+#    #+#             */
/*   Updated: 2015/03/01 12:34:36 by avallete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wong.h>

int	main(void)
{
	t_env	env;
	t_const	win_value;

	env.def = win_value;
	env.infos.echap = 0;
	env.infos.win = 0;
	env.infos.dep = 0;
	env.infos.join = 0;
	if (((win_value & (win_value - 1)) == 0) && win_value >= 2)
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
		ft_printf("Error bad win_value, not 2 pow");
	return (0);
}
