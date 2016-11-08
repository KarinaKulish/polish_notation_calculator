/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_oper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkulish <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/16 14:26:14 by kkulish           #+#    #+#             */
/*   Updated: 2016/10/16 20:41:14 by kkulish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototypes.h"

struct	s_stack	*push(struct s_stack *head, char a)
{
	struct s_stack *new;

	if ((new = malloc(sizeof(struct s_stack))) == 0)
		return (0);
	new->c = a;
	new->next = head;
	return (new);
}

char	del(struct s_stack **head)
{
	struct s_stack	*new;
	char 			a;

	if (*head == 0)
		return '\0';
	new = *head;
	a = new->c;
	*head = new->next;
	free(new);
	return (a);
}

int		prior(char a)
{
	if (a < 0)
		return (4);
	else if (a == '*' || a == '/' || a == '%')
		return (3);
	else if (a == '-' || a == '+')
		return (2);
	else if (a == '(')
		return (1);
	return (0);
}

int		is_unary(char s)
{
	if (s == '-')
		return (1);
	return (0);
}
