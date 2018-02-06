/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stockshapes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramichia <ramichia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 11:56:51 by ramichia          #+#    #+#             */
/*   Updated: 2016/11/30 22:59:16 by ramichia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		**test_tetriminos(int numberofpieces)
{
	int		i;
	int		**tab_primary_data;

	i = 0;
	tab_primary_data = NULL;
	if ((tab_primary_data = (int**)malloc(sizeof(int*) * numberofpieces)))
	{
		while (i < numberofpieces)
		{
			tab_primary_data[i] = (int*)malloc(sizeof(int) * 4);
			i++;
		}
	}
	return (tab_primary_data);
}

int		**fill_primary_data(char *buf, int **tab)
{
	int		i;
	int		j;
	int		k;
	int		r;

	i = 0;
	j = 0;
	while (buf[i])
	{
		k = 0;
		r = 0;
		while (r < 21 && buf[i])
		{
			if (buf[i] == '#')
			{
				tab[j][k] = (i + 1) % 21;
				k++;
			}
			r++;
			i++;
		}
		j++;
	}
	return (tab);
}

int		**create_tab_shape(int numberofpieces)
{
	int		i;
	int		j;
	int		**tab_final_shape;

	i = 0;
	tab_final_shape = (int**)malloc(sizeof(int*) * numberofpieces);
	if (tab_final_shape != NULL)
	{
		while (i < numberofpieces)
		{
			tab_final_shape[i] = (int*)malloc(sizeof(int) * 16);
			j = 0;
			while (j < 16)
			{
				tab_final_shape[i][j] = 0;
				j++;
			}
			i++;
		}
	}
	return (tab_final_shape);
}

int		**shape_tetriminos(int **tab_final_shape, int **tab, int nb_pieces)
{
	int		i;
	int		j;

	i = 0;
	while (i < nb_pieces)
	{
		j = 0;
		while (j < 4)
		{
			if (1 <= tab[i][j] && tab[i][j] <= 4)
				tab_final_shape[i][tab[i][j] - 1] = 1;
			else if (6 <= tab[i][j] && tab[i][j] <= 9)
				tab_final_shape[i][tab[i][j] - 2] = 1;
			else if (11 <= tab[i][j] && tab[i][j] <= 14)
				tab_final_shape[i][tab[i][j] - 3] = 1;
			else if (16 <= tab[i][j] && tab[i][j] <= 19)
				tab_final_shape[i][tab[i][j] - 4] = 1;
			j++;
		}
		i++;
	}
	return (tab_final_shape);
}

int		**create_tetriminos(int nb_pieces, char *buf)
{
	int			**tab;
	int			**tab2;

	tab = test_tetriminos(nb_pieces);
	fill_primary_data(buf, tab);
	tab2 = create_tab_shape(nb_pieces);
	tab2 = shape_tetriminos(tab2, tab, nb_pieces);
	return (tab2);
}
