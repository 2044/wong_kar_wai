/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_nb.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabadie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 15:02:41 by jabadie           #+#    #+#             */
/*   Updated: 2015/02/28 17:36:30 by avallete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wong.h"

int		two_or_four(void)
{
	if (rand() % 9 == 0)
		return (4);
	else
		return (2);
}

void	add_nb(t_env *env)
{
	int	i;
	int	j;
	int	chance;

	srand(time(NULL));
	chance = 4;
	while (1)
	{
		j = 0;
		while (j < 4)
		{
			i = 0;
			while (i < 4)
			{
				if (CASEV(j, i) == 0 && rand() % chance == 0)
				{
					CASEV(j, i) = two_or_four();
					return ;
				}
				i++;
			}
			j++;
		}
		chance--;
	}
}
