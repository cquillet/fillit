/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cquillet <cquillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 21:47:27 by cquillet          #+#    #+#             */
/*   Updated: 2016/12/01 20:44:36 by ramichia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		display_usage(void)
{
	write(2, "usage: fillit source_file", 25);
	return (1);
}

int		main(int argc, char **argv)
{
	int			fd;
	char		buf[BUF_SIZE + 1];
	int			**tab2;
	int			nb_sharp;
	t_tetris	*tetriminos;

	if (argc != 2)
		return (display_usage());
	if ((fd = open(argv[1], O_RDONLY)) == -1)
		return (write(1, "error\n", 6));
	buf[read(fd, buf, BUF_SIZE)] = '\0';
	close(fd);
	nb_sharp = testnombredeligne(buf);
	if (nb_sharp % 4 || simplified_test(buf) == 1)
		return (write(1, "error\n", 6));
	if (test_input(buf) == 1)
		return (write(1, "error\n", 6));
	tab2 = create_tetriminos(nb_sharp / 4, buf);
	tetriminos = match_pieces(tab2, nb_sharp / 4);
	if (tetriminos == NULL)
		return (write(1, "error\n", 6));
	dlx(tetriminos, nb_sharp / 4, side_min(tetriminos, nb_sharp / 4));
	return (0);
}
