/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaouen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 20:37:07 by jjaouen           #+#    #+#             */
/*   Updated: 2017/06/06 00:53:04 by jjaouen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define VL vari->flag_long
# define VT vari->type
# define VH vari->flag_hash
# define VS vari->flag_space
# define VPL vari->flag_plus
# define VM vari->flag_moins
# define VF vari->flag_field
# define VP vari->flag_preci
# define VZ vari->flag_zero
# define VAP vari->argispos

# include <stdarg.h>
# include <stdio.h>
# include <inttypes.h>
# include "libft.h"
# include <limits.h>
# include <wchar.h>

typedef struct	s_var
{
	va_list		args;
	int			flag_hash;
	int			flag_zero;
	int			flag_space;
	int			flag_plus;
	int			flag_moins;
	int			flag_field;
	int			flag_preci;
	char		flag_long;
	char		type;
	int			added_char;
	int			buff_size;
	char		*dst;
	char		error;
	int			argispos;
	int			backz;
	int			js;
	int			safes;
	int			safes1;
}				t_var;

int				ft_printf(const char *s, ...);
int				ft_dprintf(int fd, const char *s, ...);
int				ft_initialize(t_var *vari);
int				ft_add_args(const char *s, t_var *vari, int i);
void			ft_init(t_var *vari);
void			ft_add_modify_arg(t_var *vari);
void			ft_modify_int(t_var *vari, char **dst);
void			ft_modify_c(t_var *vari, char **dst);
void			ft_modify_s(t_var *vari, char **dst);
void			ft_get_type_int(t_var *vari, uintmax_t *arg2, intmax_t *arg);
char			ft_strchrstr(const char *s, int i, char *convert);
void			ft_find(t_var *vari, const char *s, int start);
void			ft_find_attribut(t_var *vari, const char *s, int start);
void			ft_find_field(t_var *vari, const char *s, int start);
void			ft_find_precision(t_var *vari, const char *s, int start);
void			ft_find_flaglength(t_var *vari, const char *s, int start);
int				ft_addchar(t_var *vari, char c);
void			ft_modify_unsignedarg(t_var *vari, char **dst, uintmax_t arg);
void			ft_modify_signedarg(t_var *vari, char **dst, intmax_t arg);
void			ft_print_struct(t_var *vari);
void			apply_surcharge(t_var *vari);
void			get_size_arg(t_var *vari, char **dst, char **char_arg);
void			place_arg_and_fill(t_var *vari, char **dst, char **char_arg);
void			ft_apply_attribut(t_var *vari, char **dst, char **char_arg);
int				ft_get_index(t_var *vari, char **dst, char **char_arg, int j);
void			ft_apply_flagmin(t_var *vari, char **dst, char **char_arg);
void			preci_zero(t_var *vari, char **dst, int i);
void			ddi_neg(t_var *vari, char **dst, char **char_arg);
void			ft_apply_flagmin(t_var *vari, char **dst, char **char_arg);
void			ft_apply_attributmin(t_var *vari, char **dst, int s_arg);
int				ft_vh_attribut(t_var *vari, char **dst, char **arg, int i);
void			ft_get_type_int_unsigned(t_var *vari, uintmax_t *arg2,
				intmax_t *arg);
void			ft_apply_modif(t_var *vari, char **dst, char **char_arg);
void			get_size_arg_two(t_var *vari, char **char_arg, int size,
		char **dst);
void			ft_flag_without_min(t_var *vari, char **dst, char **char_arg);
void			ft_convert_p(t_var *vari, char **dst, char **char_arg, int i);
void			ft_apply_vsvzvpzero(t_var *vari, char **dst, char **char_arg,
				int i);
void			ft_apply_unicode(char **char_arg, int cu);
int				get_str_arg(t_var *vari, char **dst, char **char_arg);
void			ft_apply_s_uni(t_var *vari, wchar_t *uni_char, char **char_arg);
char			*ft_unicode_s(int c);
void			ft_notunicode(t_var *vari, char **dst, int ch, int size);
void			ft_process_c(t_var *vari, char **char_arg, char **dst,
		int ch);
void			ft_free_schar(t_var *vari, char **char_arg, int f, int safe1);
void			ft_process_uni(char **char_arg, t_var *vari);
void			ft_add_s(char **dst, char **char_arg, int size, t_var *vari);
void			ft_s_null(char **char_arg, t_var *vari, int *f);
void			add_arg_modified(t_var *vari, char **dst);

#endif
