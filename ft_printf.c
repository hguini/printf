/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hguini <hguini@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 16:55:14 by hguini            #+#    #+#             */
/*   Updated: 2021/01/20 18:17:22 by hguini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libprintf.h"

void	ft_init_flags(t_variable *variable, int result)
{
	variable->result = result;
	variable->type = 0;
	variable->width = 0;
	variable->precision = -1;
	variable->zero = 0;
	variable->minus = 0;
	variable->sign = 0;
	variable->error = 0;
}

void	ft_specifier(va_list list, t_variable *variable)
{
	if (variable->type == 'c')
		ft_if_c(list, variable);
	else if (variable->type == 's')
		ft_if_s(list, variable);
	else if (variable->type == 'p')
		ft_if_p(list, variable);
	else if (variable->type == 'd' || variable->type == 'i')
		ft_if_d(list, variable);
	else if (variable->type == 'u')
		ft_if_u(list, variable);
	else if (variable->type == 'x' || variable->type == 'X')
		ft_if_x(list, variable);
	else if (variable->type == '%')
		ft_if_percent(variable);
}

void	ft_parse_line(const char **line, va_list list, t_variable *variable)
{
	ft_flags_parse(line, variable);
	ft_width_parse(line, list, variable);
	ft_precision_parse(line, list, variable);
	ft_type_parse(line, variable);
}

int		ft_printf(const char *line, ...)
{
	va_list		list;
	t_variable	variable;

	ft_init_flags(&variable, 0);
	va_start(list, line);
	while (*line != '\0')
	{
		if (*line == '%' && !variable.error)
		{
			++line;
			ft_parse_line(&line, list, &variable);
			ft_specifier(list, &variable);
			ft_init_flags(&variable, variable.result);
		}
		else
			ft_pf_putchar(*(line++), &variable);
	}
	va_end(list);
	return (variable.result);
}
