/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_nb.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabadie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 15:02:41 by jabadie           #+#    #+#             */
/*   Updated: 2015/02/28 16:15:29 by jabadie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wong.h"

int		two_or_four(void)
{
	if (rand() % 3 == 0)
		return (4);
	else
		return (2);
}

void	add_nb(int **tab)
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
				if (tab[j][i] == 0 && rand() % chance == 0)
				{
					tab[j][i] = two_or_four();
					return ;
				}
				i++;
			}
			j++;
		}
		chance--;
	}
}
