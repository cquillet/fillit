/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cquillet <cquillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 17:16:22 by cquillet          #+#    #+#             */
/*   Updated: 2016/11/30 22:38:03 by cquillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		counting_rows(t_tetris *input, int nb_input, int side)
{
	int		i;
	int		nb_rows;

	nb_rows = 0;
	i = 0;
	if (nb_input <= 0)
		return (-1);
	while (i < nb_input)
	{
		if (side < input[i].w || side < input[i].h)
			return (-1);
		nb_rows += ((side - input[i].w + 1) * (side - input[i].h + 1));
		i++;
	}
	return (nb_rows);
}

char	**alloc_matrix(int nb_pieces, int side, int nb_rows)
{
	char	**m;
	int		r;
	int		i;

	m = (char **)malloc(nb_rows * sizeof(char *));
	if (m == NULL || nb_rows == 0 || nb_pieces == 0 || side < 2)
		return (NULL);
	r = -1;
	while (++r < nb_rows)
	{
		m[r] = (char *)malloc((nb_pieces + side * side) * sizeof(char));
		if (m[r] == NULL)
		{
			while (r--)
				free(m[r]);
			free(m);
			return (NULL);
		}
		i = 0;
		while (i < nb_pieces + side * side)
			m[r][i++] = EMPTY;
	}
	return (m);
}

int		place_piece(char **m, t_tetris p, int nb_p, int side)
{
	int		i;
	int		j;
	int		k;
	int		r;
	int		pos;

	r = 0;
	j = -1;
	while (++j < side - p.h + 1)
	{
		i = -1;
		while (++i < side - p.w + 1)
		{
			pos = side * j + i;
			k = 0;
			while (k < 16 && pos + k / 4 * side + k % 4 < side * side)
			{
				m[r][nb_p + pos + k / 4 * side + k % 4] = (char)(p.tab[k]);
				k++;
			}
			r++;
		}
	}
	return (r);
}

char	**build_matrix(t_tetris *input, int nb_pieces, int side, int nb_rows)
{
	char	**m;
	char	**m_ptr;
	int		p;
	int		r;
	int		nb_filled_rows;

	if (!(m = alloc_matrix(nb_pieces, side, nb_rows)))
		return (NULL);
	m_ptr = m;
	p = 0;
	while (p < nb_pieces)
	{
		nb_filled_rows = place_piece(m_ptr, input[p], nb_pieces, side);
		r = 0;
		while (r < nb_filled_rows)
		{
			m_ptr[r][p] = FILLED;
			r++;
		}
		m_ptr += (nb_filled_rows);
		p++;
	}
	return (m);
}

void	del_matrix(char **m, int nb_rows)
{
	int		r;

	r = 0;
	while (r < nb_rows)
	{
		free(m[r]);
		r++;
	}
	free(m);
}
