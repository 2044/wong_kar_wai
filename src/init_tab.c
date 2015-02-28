#include <wong.h>

void	init_tab_place(t_env *env)
{
	int x;
	int y;

	y = 0;
	while (y < 4)
	{
		x = 0;
		while (x < 4)
		{
			CASEX(x, y) = ((WINX(env) / 8) * (x + 1)) + ((WINX(env) / 8) * x);
			CASEY(x, y) = ((WINY(env) / 8) * (y + 1)) + ((WINY(env) / 8) * y);
			x++;
		}
		y++;
	}
}

void	init_case(t_env *env, int x, int y)
{
	free(CASESTR(x, y));
	CASESTR(x, y) = ft_itoa(CASEV(x, y));
}

void	modify_tab(t_env *env)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (y < 4)
	{
		x = 0;
		while (x < 4)
		{
			init_case(env, x, y);
			x++;
		}
		y++;
	}
}


void	init_tab(t_env *env)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (y < 4)
	{
		x = 0;
		while (x < 4)
		{
			CASEV(x, y) = 0;
			CASEC(x, y) = 0;
			CASESTR(x, y) = ft_itoa(0);
			x++;
		}
		y++;
	}
	init_tab_place(env);
}
