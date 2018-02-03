/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlutsyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 19:45:10 by tlutsyk           #+#    #+#             */
/*   Updated: 2018/01/26 19:45:11 by tlutsyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H

# define LEM_IN_H
# include <stdio.h> // don't forget to delete
# include "get_next_line.h"
# include "libft/libft.h"
# include <fcntl.h>

typedef	struct			s_list_map
{
	char				*content;
	struct s_list_map	*next;
}						t_list_map;

typedef struct			s_ngbor
{
	char				*ngbor;
	struct s_ngbor		*next;
}						t_ngbor;

typedef struct			s_rooms
{
	char				*room;
	char 				*y_cord;
	char 				*x_cord;
	int8_t				position;
	int8_t				empty;
	t_ngbor				*down;
	struct s_rooms		*next;
}						t_rooms;

typedef struct			s_all_data
{
	uint32_t			nb_ants;
	int8_t				fl_ants;
	int8_t				fl_start;
	int8_t				fl_end;
	int8_t				fl_rooms;
	int8_t				fl_lines;
	int8_t				cor_input;
	int8_t				cor_lines;
	uint16_t			nb_rooms;
	t_list_map			*mnext;
	t_rooms				*rnext;
}						t_all_data;


t_ngbor		*ft_lstnb_new(char *name);
void	ft_read_data(t_all_data *main_uk);
void		lstnb_pback(t_ngbor **alst, t_ngbor *new);
t_ngbor		**ft_srch_beg_nb(t_rooms **alst, char *a);
int			check_double_link(t_ngbor **alst, char *name);
int			del_spl(char **res, int s);
int			check_start_end_nb(t_rooms **ast, int8_t position);
void		ft_defolt_struct(t_all_data *main_uk);
int			check_links(t_rooms *alst, char **res);
int			ft_check_cord(char **res);
void		ft_check_nb_ants(t_all_data *main_uk, char **line);
int			check_space(char *line);
int			check_same_r_c(t_rooms **alst, char **res);
void		split_room(t_all_data *main_uk, char *line, int8_t flags);
void		check_start(t_all_data *main_uk, int flag);
void		check_end(t_all_data *main_uk, int flag);
void		check_rooms(t_all_data *main_uk, char *line);
void		check_lines(t_all_data *main_uk, char *line);
void		ft_error(char *s);
void		ft_check_nb_ants(t_all_data *main_uk, char **line);
t_rooms		*ft_lstroom_new(char *content, char *y_cord, char *x_cord, int8_t pos);
void		lstrm_pb(t_rooms **alst, t_rooms *new);
t_list_map	*ft_lstmap_new(char	*content);
void		ft_listmap_push_back(t_list_map **alst, t_list_map *new);

#endif