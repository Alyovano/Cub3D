/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yocapell <yocapell@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 15:03:53 by yocapell          #+#    #+#             */
/*   Updated: 2020/01/20 09:46:30 by yocapell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "../../libft.h"
# include <stdarg.h>
# include <stdio.h>

typedef struct	s_struct
{
	char			flags;
	int				width;
	int				precision;
	int				i;
}				t_struct;

int				ft_printf(const char *format, ...);
t_struct		*ft_init_struct(t_struct *u);
int				ft_manager(char **format, t_struct *u, va_list ap);
int				ft_is_printf_specifier(char c);
int				ft_d_func(int i, t_struct *u);
int				ft_u_func(unsigned int i, t_struct *u);
int				ft_x_func(unsigned int i, char c, t_struct *u);
int				ft_p_func(size_t i, t_struct *u);
void			ft_pc_func(char c, t_struct *u);
void			ft_c_func(char c, t_struct *u);
void			ft_s_func(char *s, t_struct *u);
void			ft_width_zero(t_struct *u, unsigned int i, int k);
void			ft_width_space(t_struct *u, unsigned int i, int k);
void			ft_width_x_space(t_struct *u);
void			ft_width_i_space(long long i, t_struct *u, int k);
void			ft_width_p_space(char *hex, t_struct *u);
void			ft_width_c_manager(char c, t_struct *u);
void			ft_width_s_manager(char *s, t_struct *u);
int				ft_width_i_manager(int i, t_struct *u);
int				ft_width_i_manager2(int i, t_struct *u, char *result, int k);
int				ft_width_u_manager(unsigned int i, t_struct *u);
void			ft_width_x_manager(t_struct *u, char c, char *hex_min,
					char *hex_max);
void			ft_width_p_manager(t_struct *u, char *hex);
int				ft_treat_neg(int *i);
void			ft_print_p(char *hex, t_struct *u);
void			ft_precision_space(t_struct *u, int k);
int				ft_precision_zero(t_struct *u, unsigned int i, char o);
void			ft_prec_x_zero(t_struct *u, char *hex);
void			ft_prec_p_zero(t_struct *u, char *hex);
void			ft_s_precision(char *s, t_struct *u);
void			ft_s_precision2(char *s, t_struct *u, int k);
void			ft_precision_x_zero(t_struct *u, int k);
void			ft_i_precision(int i, t_struct *u);
void			ft_u_precision(unsigned int i, t_struct *u);
void			ft_p_precision(t_struct *u, char *hex);
void			ft_x_precision(t_struct *u, char c, char *x_min,
					char *x_max);
void			ft_s_null_manager(t_struct *u);
void			ft_s_null_manager2(t_struct *u, int i);
#endif
