/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouahman <mouahman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 09:19:54 by mouahman          #+#    #+#             */
/*   Updated: 2025/05/08 15:08:28 by mouahman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>

static int	is_digit(int c)
{
	return (c >= '0' && c <= '9');
}

long	parse_args(char *s)
{
	int		i;
	long	res;

	i = 0;
	res = 0;
	while (' ' == s[i])
		i++;
	if (!s[i])
		return (-1);
	if ('+' == s[i])
		i++;
	if (!is_digit(s[i]))
		return (-1);
	while (is_digit(s[i]))
	{
		res = res * 10 + s[i] - 48;
		if (INT_MAX < res)
			return (-1);
		i++;
	}
	if (s[i] && s[i] != ' ')
		return (-1);
	return (res);
}
