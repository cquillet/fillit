/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simplified_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramichia <ramichia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 19:10:13 by ramichia          #+#    #+#             */
/*   Updated: 2016/12/01 18:13:44 by ramichia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		testnombredeligne(char *buf)
{
	int		i;
	int		z;
	int		j;

	i = 0;
	z = 0;
	j = 0;
	if (buf == NULL)
		return (1);
	while (buf[i])
	{
		if (buf[i] != '.' && buf[i] != '#' && buf[i] != '\n')
			return (1);
		if (buf[i] == '#')
			z++;
		if (buf[i] == '\n')
			j++;
		i++;
	}
	if (z % 4 != 0 || z > 104 || z < 4 || (j - 4) % 5 != 0 \
		|| (i - 20) % 21 != 0)
		return (1);
	return (z);
}

int		test_input(char *buf)
{
	int		i;
	int		j;

	i = 4;
	j = 0;
	while (buf[i])
	{
		if (buf[i] != '\n')
			return (1);
		j++;
		if (j == 4 || (j - 4) % 5 == 0)
		{
			i++;
			if (buf[i] != '\n' && buf[i] != '\0' && buf[i + 1] == '\0')
				return (1);
		}
		else
			i = i + 5;
	}
	return (0);
}

int		checkeachblock(char *str, int i)
{
	if (str[i + 1] == '#')
		return (0);
	else if (str[i - 1] == '#')
		return (0);
	else if (str[i + 5] == '#')
		return (0);
	else if (str[i - 5] == '#')
		return (0);
	else if (str[i + 6] == '#')
		return (0);
	else if (str[i - 6] == '#')
		return (0);
	else if (str[i + 4] == '#')
		return (0);
	else if (str[i - 4] == '#')
		return (0);
	else
		return (1);
}

int		simplified_test(char *str)
{
	int		i;
	int		r;
	int		count;

	i = 0;
	while (str[i])
	{
		r = 0;
		count = 0;
		while (r < 21)
		{
			if (str[i] == '#')
			{
				if (checkeachblock(str, i) != 0)
					return (1);
				count++;
			}
			i++;
			r++;
		}
		if (count != 4)
			return (1);
	}
	return (0);
}
