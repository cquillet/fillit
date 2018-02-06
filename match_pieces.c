/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   match_pieces.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramichia <ramichia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 18:59:11 by ramichia          #+#    #+#             */
/*   Updated: 2016/12/01 20:44:01 by ramichia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			strcmp_tab(int *tab, int *tab2)
{
	int		i;

	i = 0;
	while (i < 16)
	{
		if (tab[i] == tab2[i])
			i++;
		else
			return (1);
	}
	return (0);
}

int			find_heigth(t_tetris letter)
{
	int		i;
	int		k;
	int		count;

	count = 0;
	i = 0;
	while (i < 15)
	{
		k = 0;
		while (k < 4)
		{
			if (letter.tab[i] == 0)
			{
				i++;
				k++;
			}
			else
			{
				i = i + 4 - k;
				k = 4;
				count++;
			}
		}
	}
	return (count);
}

int			find_width(t_tetris letter)
{
	int		i;
	int		j;
	int		count;

	count = 0;
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (letter.tab[4 * j + i] == 1)
			{
				count++;
				j = 4;
			}
			else
			{
				j++;
			}
		}
		i++;
	}
	return (count);
}

int			match_letter(t_tetris *letter, int *j, int ***pieces)
{
	int		i;

	i = 0;
	while (i < 16)
	{
		letter->tab[i] = pieces[*j][0][i];
		i++;
	}
	letter->h = find_heigth(*letter);
	letter->w = find_width(*letter);
	*j = -1;
	return (9);
}

t_tetris	*match_pieces(int **tab, int nb_pieces)
{
	int			i;
	int			j;
	int			k;
	t_tetris	*tab_shape;
	int			***pieces;

	pieces = create_patterns();
	if (!(tab_shape = (t_tetris *)malloc(sizeof(t_tetris) * 150)))
		return (NULL);
	i = 0;
	j = 0;
	while (i < nb_pieces && j < 19)
	{
		k = 0;
		while (k++ < 9)
		{
			if (strcmp_tab(tab[i], pieces[j][k - 1]) == 0)
				k = match_letter(&tab_shape[i++], &j, pieces);
		}
		if (j++ == 18)
			return (NULL);
	}
	return (tab_shape);
}
