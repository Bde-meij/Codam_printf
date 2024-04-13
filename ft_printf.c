/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: bde-meij <bde-meij@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/17 12:19:33 by bde-meij      #+#    #+#                 */
/*   Updated: 2022/02/20 12:21:30 by bde-meij      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_handlepercent(const char *fa, int *i, int *len)
{
	int	mod;

	mod = 1;
	while ((fa[*i] == '%') && (fa[*i + mod] == ' '))
	{
		if (fa[*i + mod] == '%')
			break ;
		if ((fa[*i + mod] != '%') && (fa[*i + mod] != ' '))
		{
			mod = 1;
			break ;
		}
		mod++;
	}
	if ((fa[*i] == '%') && (fa[*i + mod] == '%'))
	{
		*i += mod;
		ft_charcount(fa[*i], len);
		if ((fa[*i + 1] == 'p') || (fa[*i + 1] == 'x') || (fa[*i + 1] == 'i')
			|| (fa[*i + 1] == 'X') || (fa[*i + 1] == 'c') || (fa[*i + 1] == 'd')
			|| (fa[*i + 1] == 's') || (fa[*i + 1] == 'u'))
			*i += ft_charcount(fa[*i + 1], len);
	}
}

static void	handlesigns(const char *fa, va_list arglist, int *i, int *len)
{
	ft_handlepercent(fa, i, len);
	if ((fa[*i + 1] == 'c') && (fa[*i] == '%'))
		*i += ft_charcount(va_arg(arglist, int), len);
	if ((fa[*i + 1] == 's') && (fa[*i] == '%'))
		*i += ft_stringcount(va_arg(arglist, char *), len);
	if ((fa[*i + 1] == 'x' || fa[*i + 1] == 'X') && (fa[*i] == '%'))
	{
		ft_hexnum(va_arg(arglist, unsigned int), fa[*i + 1], len);
		*i += 1;
	}
	if ((fa[*i + 1] == 'p') && (fa[*i] == '%'))
	{
		ft_hexnum(va_arg(arglist, unsigned long int), fa[*i + 1], len);
		*i += 1;
	}
	if ((fa[*i + 1] == 'u') && (fa[*i] == '%'))
	{
		ft_decnum(va_arg(arglist, unsigned int), len);
		*i += 1;
	}
	if ((fa[*i + 1] == 'd' || fa[*i + 1] == 'i') && (fa[*i] == '%'))
	{
		ft_decnum(va_arg(arglist, int), len);
		*i += 1;
	}
}

int	ft_printf(const char *fa, ...)
{
	va_list	arglist;
	int		i;
	int		lengte;

	i = 0;
	lengte = 0;
	va_start(arglist, fa);
	while (fa[i])
	{
		if (fa[i] == '%')
			handlesigns(fa, arglist, &i, &lengte);
		else
			ft_charcount(fa[i], &lengte);
		i++;
	}
	va_end(arglist);
	return (lengte);
}
