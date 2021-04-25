/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libprintf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hguini <hguini@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 16:58:03 by hguini            #+#    #+#             */
/*   Updated: 2021/01/20 19:46:53 by hguini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBPRINTF_H
# define LIBPRINTF_H

# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>
# include "libft/libft.h"

typedef struct			s_variable
{
	int					result;
	int					type;
	int					width;
	int					precision;
	int					zero;
	int					minus;
	int					sign;
	int					percent;
	int					error;
}						t_variable;

int						ft_printf(const char *line, ...);
void					ft_flags_parse(const char **line, t_variable *variable);
void					ft_width_parse(const char **line, va_list list,
t_variable *variable);
void					ft_precision_aster(const char **line, va_list list,
t_variable *variable);
void					ft_precision_parse(const char **line, va_list list,
t_variable *variable);
void					ft_type_parse(const char **line, t_variable *variable);
void					ft_print_width(t_variable *variable, int len);
void					ft_pf_putnbr(long long int n, t_variable *variable);
void					ft_pf_putchar(const char symbol, t_variable *result);
int						ft_len_arg(long long int arg, t_variable *variable);
void					ft_if_c(va_list list, t_variable *variable);
void					ft_if_s(va_list list, t_variable *variable);
void					ft_if_d(va_list list, t_variable *variable);
void					ft_if_u(va_list list, t_variable *variable);
void					ft_if_x(va_list list, t_variable *variable);
void					ft_if_p(va_list list, t_variable *variable);
void					ft_if_percent(t_variable *variable);

#endif
