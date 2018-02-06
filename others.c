/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   others.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cquillet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 22:38:18 by cquillet          #+#    #+#             */
/*   Updated: 2016/11/30 22:38:29 by cquillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		sqrt_or_more(int n)
{
	int		root;
	int		sum;
	int		odd;

	root = 1;
	odd = 1;
	sum = 1;
	while (sum < n)
	{
		odd += 2;
		sum += odd;
		root++;
	}
	return (root);
}

int		add_blocks(t_tetris **input, int nb_pieces, int nb)
{
	int		i;

	if (nb < 0)
		return (-1);
	while (nb--)
	{
		(*input)[nb_pieces].h = 1;
		(*input)[nb_pieces].w = 1;
		(*input)[nb_pieces].tab[0] = DOT;
		i = 1;
		while (i < 16)
		{
			(*input)[nb_pieces].tab[i] = EMPTY;
			i++;
		}
		nb_pieces++;
	}
	return (nb_pieces);
}

int		side_straight(int nb_straight)
{
	if (nb_straight == 0)
		return (0);
	if (nb_straight < 4)
		return (4);
	if (nb_straight < 8)
		return (nb_straight);
	if (nb_straight < 17)
		return (8);
	if (nb_straight < 23)
		return ((nb_straight + 1) / 2);
	return (12);
}

int		side_min(t_tetris *t, int nb_pieces)
{
	int		i;
	int		min_straight;
	int		nb_straight;
	int		min;

	nb_straight = 0;
	i = -1;
	while (++i < nb_pieces)
	{
		if (t[i].w == 4 || t[i].h == 4)
			nb_straight++;
	}
	min_straight = side_straight(nb_straight);
	min = sqrt_or_more(4 * nb_pieces);
	if (min_straight > min)
		return (min_straight);
	return (min);
}
