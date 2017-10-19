/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaouen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/02 06:03:05 by jjaouen           #+#    #+#             */
/*   Updated: 2017/10/05 21:44:21 by jjaouen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# include "../../../libft/libft.h"
# include "op.h"

# define PARAM		nav->param
# define PARAMI		nav->param[i]
# define PARAM0		nav->param[0]

extern t_op g_op_tab[17];

int g_ligne;

typedef	struct		s_lab
{
	char			*name_label;
	int				line_label;
	int				vle_label;
	struct s_lab	*next;
}					t_lab;

typedef struct		s_parse
{
	int				line;
	char			*label;
	char			*instruct;
	int				type_param[3];
	char			**param;
	struct s_parse	*next;
}					t_parse;

/*
** DEFINE ERROR
*/

# define INSTRUCT_NOEXIST	1
# define LABEL_CHAR_ERR		2
# define PARAM_UNKNOW		3
# define PARAM_NOT_MATCH	4
# define PARAM_BIG			5

/*
** DEFINE ERROR V2.0
*/

# define WRONG_COUNT_INFO	-3

typedef	struct		s_error
{
	int				error;
	int				line_error;
	int				param_error;
	t_parse			*error_line;
}					t_error;

t_error g_error[0];

typedef struct		s_asm
{
	int				fd_s;
	int				fd_c;
	char			*file_name;
	char			*original_name;
	int				name_count;
	int				comment_count;
	t_lab			*lst_label;
	t_header		*header;
	t_parse			*file;
}					t_asm;

void				ft_write_dir(t_asm *info, t_parse *nav, char *str);
int					ft_get_vle_label(char *str, int line, t_asm *info);
void				ft_write_ind(t_asm *info, t_parse *nav, char *str);
void				ft_write_header(t_asm *info);
void				write_file(t_asm *info);
void				ft_encode_content_s(t_asm *info);
void				ft_print_parser(t_asm *info);
t_asm				*ft_asm_file(char *name, t_asm *info);
int					ft_reverse_memory_int(int vle, int size);
void				ft_init_asm_struct(t_asm *info, int fd_s, char *name);
char				ft_fill_header_content_s(t_asm *info);
char				ft_copy_name(char *line, t_asm *info);
char				ft_copy_comment(char *line, t_asm *info);
char				ft_is_header(char *line, t_asm *info);
char				ft_manage_error_header(char error, t_asm *info, char *line);
void				ft_get_content(char *line, t_asm *info);
void				ft_parser(t_asm *info, char *line);
char				ft_is_empty(char *line);
int					ft_check_validity_parser(t_asm *info);
int					ft_write_error(t_asm *info);
char				ft_is_name(char *line, t_asm *info);
char				ft_is_comment(char *line, t_asm *info);
char				ft_assign_type_value(t_asm *info, t_parse *nav, int i);
char				ft_label_exist(char *label, t_lab *list);
int					ft_check_match_param(t_asm *info, t_parse *nav);
char				ft_matching_param(t_parse *nav, int i, int index);
int					ft_get_size(t_parse *file);
t_asm				*ft_free_all(t_asm *info);
int					ft_set_gerror(int error, int line_error, int param_error,
					t_parse *error_line);
void				add_label_to_lst(t_asm *info, char *label, int line);
int					ft_valid_num(char *str);
char				**ft_apply_trim_tab(char **tab);
char				*ft_encode_line(t_parse *nav);
int					ft_get_encoded_length(t_parse *nav, int index);
int					ft_write_ocp(t_asm *info, t_parse *line);
void				ft_write_param(t_asm *info, t_parse *nav);
void				ft_print_manage_error_header(char error, t_asm *info,
					char *line);
void				ft_print_manage_error_header_2(char error, t_asm *info);
int					ft_check_and_set_params_2(t_asm *info, t_parse *nav,
					int *i);
int					get_lst_label(t_asm *info);
int					check_instructions(t_asm *info);
int					check_and_set_params(t_asm *info);
int					get_op_index(char *instruct);

#endif
