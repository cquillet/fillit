/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cover.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cquillet <cquillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 17:15:49 by cquillet          #+#    #+#             */
/*   Updated: 2016/11/30 22:22:16 by cquillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	cover_col(t_node *n, int col)
{
	int		i;
	int		j;

	n[n[col].r].l = n[col].l;
	n[n[col].l].r = n[col].r;
	i = n[col].d;
	while (i != col)
	{
		j = n[i].r;
		while (j != i)
		{
			n[n[j].d].u = n[j].u;
			n[n[j].u].d = n[j].d;
			n[n[j].c].nb_elem--;
			j = n[j].r;
		}
		i = n[i].d;
	}
}

void	uncover_col(t_node *n, int col)
{
	int		i;
	int		j;

	i = n[col].u;
	while (i != col)
	{
		j = n[i].l;
		while (j != i)
		{
			n[n[j].c].nb_elem++;
			n[n[j].d].u = j;
			n[n[j].u].d = j;
			j = n[j].l;
		}
		i = n[i].u;
	}
	n[n[col].r].l = col;
	n[n[col].l].r = col;
}

void	cover_row(t_node *n, int row)
{
	int		j;

	j = n[row].r;
	while (j != row)
	{
		cover_col(n, n[j].c);
		j = n[j].r;
	}
}

void	unvover_row(t_node *n, int row)
{
	int		j;

	j = n[row].l;
	while (j != row)
	{
		uncover_col(n, n[j].c);
		j = n[j].l;
	}
}
