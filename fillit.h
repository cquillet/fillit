/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cquillet <cquillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 15:42:56 by cquillet          #+#    #+#             */
/*   Updated: 2016/12/01 19:24:38 by cquillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

# define BUF_SIZE 550

# define EMPTY 0
# define FILLED 1
# define DOT 2

typedef struct	s_tetris
{
	int			h;
	int			w;
	int			tab[16];
}				t_tetris;

typedef struct	s_node
{
	int			l;
	int			r;
	int			u;
	int			d;
	int			c;
	int			nb_elem;
	char		letter;
}				t_node;

/*
** Testing map
*/
int				testnombredeligne(char *buf);
int				test_input(char *buf);
int				checkeachblock(char *str, int i);
int				simplified_test(char *str);

/*
** Create a tab to stock the data for each tetriminos
*/
int				**test_tetriminos(int nb_pieces);
int				**fill_primary_data(char *buf, int **tab);
int				**create_tab_shape(int nb_pieces);
int				**shape_tetriminos(int **tab_shape, int **tab, int nb_pieces);
int				**create_tetriminos(int nb_pieces, char *buf);

/*
** Create Patterns
*/
int				***create_patterns();
int				**alloc_pieces(void);

/*
** Create struct tab
*/
int				strcmp_tab(int *tab, int *tab2);
int				find_heigth(t_tetris letter);
int				find_width(t_tetris letter);
int				match_letter(t_tetris *letter, int *j, int ***pieces);
t_tetris		*match_pieces(int **tab, int nb_pieces);

/*
** Creating Matrix part
*/
int				counting_rows(t_tetris *input, int nb_input, int side);
char			**alloc_matrix(int nb_pieces, int side, int nb_rows);
int				place_piece(char **m, t_tetris p, int nb_pieces, int side);
char			**build_matrix(t_tetris *t, int nb_p, int side, int nb_r);
void			del_matrix(char **m, int nb_rows);

/*
** Creating Nodes Part
*/
t_node			*convert_matrix(char **m, int nb_pieces, int side, int nb_rows);
void			give_letters(t_node **n, int nb_input);

/*
** Linking Part
*/
void			build_heads_of_column(t_node *n, int nb_col);
int				build_r_and_l(t_node *n, char **m, int start, int row);
void			build_u_and_d(t_node *n, int col, int nb_col, int nb_rows);
int				link_r_and_l(t_node *n, int i, int j);
void			link_u_and_d(t_node *n, int i, int j);

/*
** Covering Part
*/
void			cover_col(t_node *n, int col);
void			uncover_col(t_node *n, int col);
void			cover_row(t_node *n, int row);
void			unvover_row(t_node *n, int row);

/*
** Algo X Part
*/
void			dlx(t_tetris *t, int nb_input, int side);
int				choose_start_col(t_node *n);
int				search(t_node *n, int *soluce, int k);
void			build_solution(t_node *n, int *solution, int nb_p, int side);
void			print_solution(char *s, int side);

/*
** Others
*/
int				sqrt_or_more(int n);
int				add_blocks(t_tetris **input, int nb_pieces, int nb);
int				side_min(t_tetris *t, int nb_pieces);
int				side_straight(int nb_straight);

int				display_usage(void);

#endif
