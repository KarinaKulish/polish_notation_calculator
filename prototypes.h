/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prototypes.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkulish <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/15 05:37:28 by kkulish           #+#    #+#             */
/*   Updated: 2016/10/16 16:34:19 by kkulish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __PROTOTYPES_H
# define __PROTOTYPES_H

#include <stdlib.h>
#include <unistd.h>
#include "stack.h"

int		ft_atoi(char *str);
int		ft_strlen(char *str);
void	main_calc(char *str);
void	ft_putchar(char c);
void	ft_putstr(char *str);
int		ft_add(int x, int y);
int		ft_sub(int x, int y);
int		ft_mul(int x, int y);
int		ft_div(int x, int y);
int		ft_mod(int x, int y);
char	del(struct s_stack **head);
int		prior(char a);
int		is_unary(char s);
void	itoa(int nb, char *a);
void	ft_putnbr(int nb);
int		is_operator(char c);
void	reverse(char *s);
int		is_operator(char c);
void	itoa(int nb, char *a);
struct 	s_stack	*push(struct s_stack *head, char a);
#endif
