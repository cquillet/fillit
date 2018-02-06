/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nodes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cquillet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 17:16:29 by cquillet          #+#    #+#             */
/*   Updated: 2016/11/30 22:38:58 by cquillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_node	*convert_matrix(char **m, int nb_pieces, int side, int nb_rows)
{
	t_node	*n;
	int		r;
	int		c;
	int		start_node;
	int		nb_col;

	nb_col = nb_pieces + side * side;
	n = (t_node *)malloc((nb_col + 1 + (5 * nb_rows)) * sizeof(t_node));
	if (n == NULL || m == NULL || nb_pieces < 1 || nb_rows < 1 || nb_col < 5)
		return (NULL);
	build_heads_of_column(n, nb_col);
	r = 0;
	start_node = nb_col + 1;
	while (r < nb_rows)
	{
		start_node += build_r_and_l(n, m, start_node, r);
		r++;
	}
	c = 0;
	while (c++ < nb_col)
	{
		build_u_and_d(n, c, nb_col, nb_rows);
	}
	return (n);
}

void	give_letters(t_node **n, int nb_input)
{
	int		c;

	if (n != NULL && *n != NULL)
	{
		c = ((*n)[0]).r;
		while (c != 0)
		{
			if (c <= nb_input)
				(*n)[c].letter = 'A' + c - 1;
			else
				(*n)[c].letter = '.';
			c = (*n)[c].r;
		}
	}
}
