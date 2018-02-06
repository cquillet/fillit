/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   createpattern.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramichia <ramichia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 14:32:20 by ramichia          #+#    #+#             */
/*   Updated: 2016/12/01 14:23:18 by ramichia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		**alloc_pieces(void)
{
	int **t;
	int i;
	int k;

	t = (int **)malloc(9 * sizeof(int*));
	i = 0;
	while (i < 9)
	{
		t[i] = (int *)malloc(16 * sizeof(int));
		k = 0;
		while (k++ < 16)
			t[i][k - 1] = 0;
		i++;
	}
	return (t);
}

int		**fill_pieces(int hex, int h, int w)
{
	int **t;
	int i;
	int j;
	int k;
	int l;

	t = alloc_pieces();
	l = 0;
	j = -1;
	while (++j < 4 - h + 1)
	{
		i = -1;
		while (++i < 4 - w + 1)
		{
			k = -1;
			while (++k < 16 && 4 * j + i + k < 16 && l < 9)
			{
				t[l][4 * j + i + k] = ((hex & (1 << (15 - k))) != 0);
			}
			l++;
		}
	}
	return (t);
}

int		***create_patterns(void)
{
	int ***t;

	t = (int***)malloc(sizeof(int**) * 19);
	t[0] = fill_pieces(0xCC00, 2, 2);
	t[1] = fill_pieces(0xF000, 1, 4);
	t[2] = fill_pieces(0x8888, 4, 1);
	t[3] = fill_pieces(0xE400, 2, 3);
	t[4] = fill_pieces(0x8C80, 3, 2);
	t[5] = fill_pieces(0x4E00, 2, 3);
	t[6] = fill_pieces(0x4C40, 3, 2);
	t[7] = fill_pieces(0x44C0, 3, 2);
	t[8] = fill_pieces(0x8E00, 2, 3);
	t[9] = fill_pieces(0xC880, 3, 2);
	t[10] = fill_pieces(0xE200, 2, 3);
	t[11] = fill_pieces(0x88C0, 3, 2);
	t[12] = fill_pieces(0xE800, 2, 3);
	t[13] = fill_pieces(0xC440, 3, 2);
	t[14] = fill_pieces(0x2E00, 2, 3);
	t[15] = fill_pieces(0x6C00, 2, 3);
	t[16] = fill_pieces(0x8C40, 3, 2);
	t[17] = fill_pieces(0xC600, 2, 3);
	t[18] = fill_pieces(0x4C80, 3, 2);
	return (t);
}
