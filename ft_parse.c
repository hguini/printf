/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hguini <hguini@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 17:55:51 by hguini            #+#    #+#             */
/*   Updated: 2021/01/20 19:40:38 by hguini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libprintf.h"

void	ft_flags_parse(const char **line, t_variable *variable)
{
	while (**line == '-' || **line == '0')
	{
		if (**line == '-')
			variable->minus = 1;
		else
			variable->zero = 1;
		(*line)++;
	}
}

void	ft_width_parse(const char **line, va_list list, t_variable *variable)
{
	int len;

	if (**line == '*')
	{
		variable->width = va_arg(list, int);
		if (variable->width < 0)
		{
			variable->minus = 1;
			variable->width *= -1;
		}
		(*line)++;
	}
	else if (ft_isdigit(**line))
	{
		variable->width = ft_atoi((char*)(*line));
		len = ft_len_arg(variable->width, variable);
		while (**line == '0')
			++*line;
		(*line) += len;
	}
}

void	ft_precision_aster(const char **line,
			va_list list, t_variable *variable)
{
	variable->precision = va_arg(list, int);
	if (variable->precision < 0)
		variable->precision = -1;
	(*line)++;
}

void	ft_precision_parse(const char **line,
			va_list list, t_variable *variable)
{
	int	len;

	if (**line == '.')
	{
		(*line)++;
		if (**line == '*')
			ft_precision_aster(line, list, variable);
		else if (ft_isdigit(**line))
		{
			variable->precision = ft_atoi((char*)(*line));
			len = ft_len_arg(variable->precision, variable);
			while (**line == '0')
				++*line;
			(*line) += len;
		}
		else if (**line == 'c' || **line == 's' || **line == 'p' ||
		**line == 'd' || **line == 'i' || **line == 'u' ||
		**line == 'x' || **line == 'X' || **line == '%')
		{
			variable->precision = 0;
			variable->type = **line;
		}
		else
			variable->error = 1;
	}
}

void	ft_type_parse(const char **line, t_variable *variable)
{
	if (**line == 'c' || **line == 's' || **line == 'p' || **line == 'd' ||
		**line == 'i' || **line == 'u' || **line == 'x' ||
		**line == 'X' || **line == '%')
	{
		variable->type = **line;
		++*line;
	}
	else
		variable->error = 1;
}
