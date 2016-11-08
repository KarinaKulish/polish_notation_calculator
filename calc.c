/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkulish <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/15 04:58:56 by kkulish           #+#    #+#             */
/*   Updated: 2016/10/16 20:39:56 by kkulish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototypes.h"

int	g_i;
int g_start;

int		calc(char *str, int i, char *a, char *b)
{
	int j;
	int k;
	int co;
	int res;

	j = i;
	k = 2;
	co = 0;
	while (--j >= 0)
	{
		if ( str[j] == ' ' && k)
			k--;
		else if ((str[j] == ' ' ) && !k)
			break;
	}
	res = j;
	while (str[++j] != ' ')
		a[co++] = str[j];
	a[co] = '\0';
	co = 0;
	while (str[++j] !=' ')
		b[co++] = str[j];
	b[co] = '\0';
	return (res);
}

int		str_change(char *str, char *a, char *b, int i)
{
	int f;
	int s;
	int res;

	res = 0;
	f = ft_atoi(a);
	s = ft_atoi(b);
	if (str[i] == '+')
		res = ft_add(f, s);
	else if (str[i] == '-')
		res = ft_sub(f, s);
	else if (str[i] == '*')
		res = ft_mul(f, s);
	else if (str[i] == '/')
		res = ft_div(f, s);
	else if (str[i] == '%')
		res = ft_mod(f, s);
	return (res);
}

char	*change(char *str, int start, int end, int res)
{
	int		i;
	int		j;
	char	temp[100];
	char	z[100];

	itoa(res, z);
	i = end;
	j = 0;
	while (++i < ft_strlen(str))
		temp[j++] = str[i];
	temp[j] = '\0';
	j = 0;
	while (z[j])
		str[++start] = z[j++];
	j = 0;
	str[++start] = ' ';
	while (temp[j])
		str[++start] = temp[j++];
	str[++start] = '\0';
	return (str);
}

void	main_calc(char *str)
{
	int		i;
	char	a[100];
	char	b[100];

	i = 0;
	while (str[i])
	{
		if (is_operator(str[i]))
		{
			g_start = calc(str, i, a, b);
			g_i = str_change(str, a, b, i);
			str = change(str, g_start, i, g_i);
			i = 0;
			a[0] = '\0';
			b[0] = '\0';
		}
		i++;
	}
}
