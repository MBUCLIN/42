#ifndef FILLIT_H
# define FILLIT_H

# include "fillit_incstruc.h"

/*
		FUNCTIONS FROM READ PART
*/
/*
			create list
*/

t_sample	*ft_newtetri(char **tetri, int y);
char		**emptygrid(void);
char		**ft_copy_tetri(char **sample);
char		**ft_gettetri(char **sample, int y);
t_sample	*ft_treat_sample(char **sample);

/*
			check validity
*/

t_pos		ft_get_first_pos(char **sample, int y);
int			ft_check_tetri(char **sample, t_pos pos);
int			ft_check_block(char **sample, int y);
int			ft_check_empty_lines(char *read_result);
int			ft_is_sample_valid(char **sample);

/*
			list edit
*/

void		ft_printlst(t_sample *lst);
int			ft_lstlen(t_sample *lst);
void		ft_change_lst_char(t_sample *lst);
void		ft_lstdestroy(t_sample *lst);

/*
			read
*/

char		**ft_treat_read(char *read_result);
char		**ft_read_sample(char *filename);
/*
		FUNCTIONS FROM SOLVE PART
*/
/* 			Create map
*/
t_pos		ft_get_next_pos(t_pos pos, char **tetri, int match);
size_t		ft_get_pft_sqr(int n);
char		**ft_push_tetri_left(char **tetri);
void		ft_prepare_tetri(t_sample *tetri);
char		**ft_create_map(size_t size);

/*
			solve check
*/

int			ft_check_map(t_sample *tetri, char **map);
int			ft_check_pos(char **map, t_pos pos, t_sample *tetri, int size);

/*
			solve moove
*/

void		ft_place_tetri(char **map, t_sample *toplace, t_pos pos);
t_pos		ft_change_pos(char **map, t_pos pos, size_t size, t_sample *tmp);
t_pos		ft_pos_tetri(char **map);
void		ft_remove_tetri(char **map, t_pos pos);

/*
			solve map
*/

t_pos		ft_get_dif(t_pos next, t_pos pos, char **tetri);
t_sample	*ft_search_tetri(t_sample *tetri, char c);
t_sample	*ft_get_tetri(t_sample *tetri, char **map);
int			ft_solve(t_sample *tetri, char **map, size_t size, t_pos pos);
char		**ft_init_solv(t_sample *tetri);

#endif
