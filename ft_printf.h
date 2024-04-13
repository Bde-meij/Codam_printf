/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: bde-meij <bde-meij@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/17 13:00:07 by bde-meij      #+#    #+#                 */
/*   Updated: 2022/01/25 17:28:41 by bde-meij      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int		ft_printf(const char *fa, ...);
int		ft_charcount(char c, int *len);
int		ft_stringcount(char *cs, int *len);
void	ft_decnum(long int diu, int *len);
void	ft_hexnum(size_t xp, char sign, int *len);

#endif