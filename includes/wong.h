/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wong.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallete <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/27 21:04:06 by avallete          #+#    #+#             */
/*   Updated: 2015/03/01 12:01:33 by avallete         ###   ########.fr       */
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
# define CASEX(x, y) (env->tab[y][x].x)
# define CASEY(x, y) (env->tab[y][x].y)
# define CASEC(x, y) (env->tab[y][x].color)
# define CASESTR(x, y) (env->tab[y][x].str)
# define K_ECHAP 27

# define LR(i, f) (f == 1) ? (i > 0) : (i < 4)
# define LR_0(i, f) (f == 1) ? (i > -1) : (i < 4)
# define ML(i, f) (f == 1) ? (i - 1) : (i + 1)
# define LEFT 0
# define RIGHT 1
# define UP 0
# define DOWN 1

typedef enum		e_const
{
	WIN_VALUE = 2048
}					t_const;

typedef	struct		s_win
{
	unsigned int	win_x;
	unsigned int	win_y;
}					t_win;

typedef	struct		s_inf
{
	int				echap;
	int				win;
	int				dep;
	int				join;
}					t_inf;

typedef struct		s_case
{
	unsigned int	value;
	unsigned int	x;
	unsigned int	y;
	int				color;
	char			*str;
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
void				grep_window_value(t_env *env);
void				new_window(void);
void				expose_term(t_env *env);

/*
** DRAW_TAB
*/
void				draw_tab(t_env *env);
void				draw_cross(unsigned int x, unsigned int y,\
												unsigned maxx, unsigned maxy);
void				init_tab(t_env *env);
void				init_tab_place(t_env *env);
void				init_case(t_env *env, int x, int y);
void				modify_tab(t_env *env);

/*
** MOV_TAB
*/

void				tab_mvline(t_env *env, int j, int i, int f);
void				tab_mvcol(t_env *env, int j, int i, int f);
void				mv_down(t_env *env);
void				mv_up(t_env *env);
void				mv_right(t_env *env);
void				mv_left(t_env *env);
void				add_nb(t_env *env);
int					two_or_four(void);

/*
** CHECK
*/
int					win_or_not(t_env *env);
int					check_ln(t_env *env);
int					check_col(t_env *env);
void				game_over(t_env *env);
int					is_fill(t_env *env);
#endif
