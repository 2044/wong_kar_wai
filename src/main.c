/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallete <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 00:45:26 by avallete          #+#    #+#             */
/*   Updated: 2015/03/01 19:08:28 by avallete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wong.h>

int	main(void)
{
	t_env	env;
	t_const	win_value;

	win_value = WIN_VALUE;
	env.def = win_value;
	env.infos.echap = 0;
	env.infos.win = 0;
	env.infos.dep = 0;
	env.infos.join = 0;
	if (((win_value & (win_value - 1)) == 0) && win_value >= 2)
	{
		new_window();
		clear();
		keypad(stdscr, TRUE);
		use_default_colors();
		init_numbercolor();
		init_tab(&env);
		high_score(&env);
		ft_menu(&env);
	}
	else
		ft_printf("Error bad win_value, not 2 pow");
	return (0);
}
