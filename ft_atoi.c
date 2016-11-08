/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkulish <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/03 13:44:29 by kkulish           #+#    #+#             */
/*   Updated: 2016/10/16 16:22:31 by kkulish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check_whitespaces(char *str)
{
	int i;

	i = 0;
	while ((str[i] == ' ') || (str[i] == '\t') || (str[i] == '\n')
			|| (str[i] == '\v') || (str[i] == '\f') || (str[i] == '\r'))
	{
		i++;
	}
	return (i);
}

int	ft_atoi(char *str)
{
	int n;
	int i;
	int negative;

	n = 0;
	i = 0;
	negative = 1;
	i = check_whitespaces(str);
	if (str[i] == '!')
	{
		negative = -1;
		i++;
	}
	if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		n = n * 10;
		n = n + str[i];
		i++;
		n = n - '0';
	}
	return (n * negative);
}
