/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   link.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cquillet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 17:16:14 by cquillet          #+#    #+#             */
/*   Updated: 2016/11/30 22:26:34 by cquillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	build_heads_of_column(t_node *n, int nb_col)
{
	int		i;

	i = 0;
	while (i++ < nb_col)
	{
		n[i].l = i - 1;
		n[i - 1].r = i;
		n[i].c = i;
		n[i].nb_elem = 0;
	}
	n[0].l = nb_col;
	n[nb_col].r = 0;
}

int		link_r_and_l(t_node *n, int i, int nb_block)
{
	int		j;

	j = 0;
	while (j < nb_block)
	{
		if (j < nb_block - 1)
			n[i + j].r = i + j + 1;
		if (j > 0)
			n[i + j].l = i + j - 1;
		j++;
	}
	n[i].l = i + nb_block - 1;
	n[i + nb_block - 1].r = i;
	return (nb_block);
}

int		build_r_and_l(t_node *n, char **m, int start, int row)
{
	int		c;
	int		i;
	int		j;

	i = start;
	c = 0;
	j = 0;
	while (j < 5)
	{
		if (m[row][c++] != EMPTY)
		{
			n[i].c = c;
			if (j == 1)
			{
				if (m[row][c - 1] == DOT)
					return (link_r_and_l(n, i - 1, 2));
				else
					link_r_and_l(n, i - 1, 5);
			}
			i++;
			j++;
		}
	}
	return (5);
}

void	link_u_and_d(t_node *n, int i, int j)
{
	n[i].d = j;
	n[j].u = i;
}

void	build_u_and_d(t_node *n, int col, int nb_col, int nb_rows)
{
	int		r;
	int		prev;

	r = nb_col + 1;
	while (r < (5 * nb_rows + nb_col + 1))
	{
		if (n[r].c == col)
		{
			n[col].nb_elem++;
			if (n[col].nb_elem == 1)
			{
				n[col].d = r;
				n[r].u = col;
			}
			else
			{
				n[r].u = prev;
				n[prev].d = r;
			}
			prev = r;
		}
		r++;
	}
	n[prev].d = col;
	n[col].u = prev;
}
