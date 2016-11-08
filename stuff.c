/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stuff.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkulish <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/16 16:01:24 by kkulish           #+#    #+#             */
/*   Updated: 2016/10/16 20:41:33 by kkulish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototypes.h"

void	reverse(char *s)
{
	int 	i;
   	int 	j;
	char 	c;

	i = 0;
	j = ft_strlen(s)-1;
	while (i < j) 
	{
		c = s[i];
		s[i] = s[j];
		s[j] = c;
		i++;
		j--;
	}
}

int		is_operator(char c)
{
	if (c == '*' || c == '/' || c == '+' || c == '-' || c == '%')
		return (1);
	return (0);
}

void	itoa(int nb, char *a)
{
	int i;
	int sign;

	i = 0;
	sign = 0;
	if (nb < 0)
	{
		sign = 1;
		nb = -nb;
	}
	a[i++] = nb % 10 + '0';
	while ((nb /= 10) > 0)
		a[i++] = nb % 10 + '0';
	if (sign)
		a[i++] = '!';
	a[i] = '\0';
	reverse(a);
}
