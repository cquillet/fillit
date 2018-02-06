/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_x.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cquillet <cquillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 17:16:01 by cquillet          #+#    #+#             */
/*   Updated: 2016/12/01 19:18:19 by cquillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		choose_start_col(t_node *n)
{
	int		c;
	int		j;
	int		min;

	c = n[0].r;
	min = 2147483647;
	j = n[0].r;
	while (j != 0)
	{
		if (0 < n[j].nb_elem && n[j].nb_elem < min)
		{
			min = n[j].nb_elem;
			c = j;
		}
		j = n[j].r;
	}
	return (c);
}

int		search(t_node *n, int *soluce, int k)
{
	int			r;
	int			c;

	if (k == 0 || n[0].r == 0)
		return (k);
	c = n[0].r;
	cover_col(n, c);
	r = n[c].d;
	while (r != c)
	{
		soluce[k - 1] = r;
		cover_row(n, r);
		if (search(n, soluce, k - 1) == 0)
			return (0);
		r = soluce[k - 1];
		c = n[r].c;
		unvover_row(n, r);
		r = n[r].d;
	}
	uncover_col(n, c);
	return (k);
}

void	print_solution(char *s, int side)
{
	int		l;

	l = 0;
	while (l++ < side)
	{
		write(1, s, side);
		write(1, "\n", 1);
		s += side;
	}
}

void	build_solution(t_node *n, int *solution, int nb_pieces, int side)
{
	char	*print;
	int		l;
	int		p;
	int		s;

	if (!(print = (char *)malloc(side * side * sizeof(char))))
		return ;
	p = 0;
	while (p < nb_pieces)
	{
		l = solution[p++];
		while (n[l].c > nb_pieces)
			l = n[l].r;
		s = n[l].r;
		while (s != l)
		{
			print[(n[s].c - nb_pieces - 1)] = n[n[l].c].letter;
			s = n[s].r;
		}
	}
	print_solution(print, side);
}

void	dlx(t_tetris *t, int nb_input, int side)
{
	int		nb_pieces;
	char	**matrix;
	t_node	*nodes;
	int		nb_possible;
	int		*result;

	while (1)
	{
		nb_pieces = nb_input;
		if (counting_rows(t, nb_pieces, side) > 0)
		{
			nb_pieces = add_blocks(&t, nb_pieces, side * side - 4 * nb_pieces);
			nb_possible = counting_rows(t, nb_pieces, side);
			matrix = build_matrix(t, nb_pieces, side, nb_possible);
			nodes = convert_matrix(matrix, nb_pieces, side, nb_possible);
			give_letters(&nodes, nb_input);
			result = (int *)malloc(nb_pieces * sizeof(int));
			if (nodes != NULL && search(nodes, result, nb_pieces) == 0)
				return (build_solution(nodes, result, nb_pieces, side));
			free(result);
			free(nodes);
			del_matrix(matrix, nb_possible);
		}
		side++;
	}
}
