/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wong.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallete <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/27 21:04:06 by avallete          #+#    #+#             */
/*   Updated: 2015/02/28 16:28:48 by jabadie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WONG_H
# define WONG_H
# include <libft.h>
# include <get_next_line.h>
# include <ft_printf.h>
# include <time.h>
# include <signal.h>
# include <curses.h>
# define WINX(x) (x->win.win_x)
# define WINY(x) (x->win.win_y)
# define CASEV(x, y) (env->tab[y][x].value)
# define CASEX(x, y) (env->tab[y][x].value)
# define CASEY(x, y) (env->tab[y][x].value)
# define CASEC(x, y) (env->tab[y][x].value)
# define K_ECHAP 27

# define LR(i, f) (f == 1) ? (i - 1) : (i + 1)
# define LEFT 1
# define RIGHT 0
# define UP 0
# define DOWN 1

typedef enum		e_const
{
	WIN_VALUE = 2048
}					t_const;

typedef	struct		s_win
{
	unsigned int	win_x;
	unsigned int 	win_y;
}					t_win;

typedef	struct		s_inf
{
	int				echap;
	int				redraw;
}					t_inf;

typedef struct		s_case
{
	int				value;
	unsigned int	x;
	unsigned int	y;
	int				color;
}					t_case;

typedef	struct		s_env
{
	t_const			def;
	t_win			win;
	t_inf			infos;
	t_case			tab[4][4];
}					t_env;

/*
** WINDOW
*/
void	grep_window_value(t_env *env);
void	new_window(void);
void	expose_term(t_env *env);


/*
** DRAW_TAB
*/
void	draw_tab(t_env *env);
void	draw_cross(unsigned int x, unsigned int y,\
		unsigned maxx, unsigned maxy);

/*
** MOV_TAB
*/

int		tab_mvline(int **tab, int j, int i, int f);
int		tab_mvcol(int **tab, int j, int i, int f);

void	mv_down(int **tab);
void	mv_up(int **tab);
void	mv_right(int **tab);
void	mv_left(int **tab);

#endif
