/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkulish <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/15 16:42:27 by kkulish           #+#    #+#             */
/*   Updated: 2016/10/16 20:40:30 by kkulish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototypes.h"

char 			g_polish[150];
struct s_stack	*g_opers;
int				g_point;

void	number(char *str, int i)
{
	if (str[i - 1] == '-')
	{
		g_polish[g_point++] = '!';
		str[i - 1] = '0';
	}
	g_polish[g_point++] = str[i];
	if (!(str[i + 1] >= '0' && str[i +1] <= '9'))
		g_polish[g_point++] = ' ';
}

void	operators(char str)
{
	if (g_opers == 0)
		g_opers = push(g_opers, str);
	else
	{
		if (prior(g_opers->c) < prior(str))
			g_opers = push(g_opers, str);
		else
		{
			while ((g_opers != 0) && (prior(g_opers->c) >= prior(str)))
				g_polish[g_point++] = del(&g_opers);
			g_opers = push(g_opers, str);
		}
	}
}

void	cycle(char *str, int i)
{
	while (str[i])
	{
		if (str[i] == ')')
		{
			while (g_opers->c != '(')
				g_polish[g_point++] = del(&g_opers);
			del(&g_opers);
		}
		else if (str[i] >= '0' && str[i] <= '9')
			number(str, i);
		else if (str[i] == '(')
			g_opers = push(g_opers, '(');
		else if (is_operator(str[i]))
		{
			if ((str[i + 1] >= '0' && str[i + 1] <= '9') && str[i] == '-')
			{
				i++;
				continue;
			}
			operators(str[i]);
		}
		i++;
	}
}

int		eval_expr(char *str)
{
	int i;

	i = 0;
	g_opers = 0;
	g_point = 0;
	cycle(str, i);
	while (g_opers != 0)
		g_polish[g_point++] = del(&g_opers);
	g_polish[g_point] = '\0';
	main_calc(g_polish);
	return (ft_atoi(g_polish));
}

int		main(int ac, char **av)
{
	if (ac > 1)
	{
		ft_putnbr(eval_expr(av[1]));
		ft_putchar('\n');
	}
	return (0);
}
