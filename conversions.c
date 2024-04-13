/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_hexdecstrchr.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: bde-meij <bde-meij@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/17 12:44:32 by bde-meij      #+#    #+#                 */
/*   Updated: 2022/01/25 17:28:58 by bde-meij      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_charcount(char c, int *len)
{
	*len += write(1, &c, 1);
	return (1);
}

int	ft_stringcount(char *cs, int *len)
{
	if (!cs)
	{
		*len += 6;
		write(1, "(null)", 6);
		return (1);
	}
	while (*cs)
	{
		*len += write(1, cs, 1);
		cs++;
	}
	return (1);
}

void	ft_decnum(long int diu, int *len)
{
	char	c;

	if (diu < 0)
	{
		*len += write(1, "-", 1);
		diu *= -1;
	}
	c = (diu % 10) + 48;
	if (diu >= 10)
	{
		ft_decnum(diu / 10, len);
		*len += write(1, &c, 1);
	}
	if (diu < 10)
		*len += write(1, &c, 1);
}

void	ft_hexnum(size_t xp, char sign, int *len)
{
	char	c;
	int		z;

	z = 0;
	if (((xp % 16) + 48) > '9')
		z = 39;
	if ((z == 39) && (sign == 'X'))
		z = 7;
	c = (xp % 16) + 48 + z;
	if (xp >= 16)
	{
		ft_hexnum(xp / 16, sign, len);
		*len += write(1, &c, 1);
	}
	if (xp < 16)
	{
		if (sign == 'p')
			*len += write(1, "0x", 2);
		*len += write(1, &c, 1);
	}
}
