/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsibiet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 20:00:50 by rsibiet           #+#    #+#             */
/*   Updated: 2015/11/29 15:56:54 by rsibiet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static const char	*str_find_next(const char *str, char c, int skip)
{
	if (skip)
		while (*str != '\0' && *str == c)
			str++;
	else
		while (*str != '\0' && *str != c)
			str++;
	return (str);
}

static int			str_count_splits(const char *str, char seps)
{
	int i;

	i = 0;
	while (*str != '\0')
	{
		str = str_find_next(str, seps, 1);
		if (*str != '\0')
		{
			i++;
			str = str_find_next(str, seps, 0);
		}
	}
	return (i);
}

static char			**tabledel(char **ret, int len)
{
	int i;

	i = 0;
	while (i < len)
	{
		free(ret[i]);
		i++;
	}
	free(ret);
	return (NULL);
}

char				**ft_strsplit(char const *str, char c)
{
	char		**ret;
	int			i;
	const char	*next;

	i = 0;
	if (str == NULL)
		return (NULL);
	ret = (char**)malloc(sizeof(char*) * (str_count_splits(str, c) + 1));
	if (ret == NULL)
		return (NULL);
	while (*str != '\0')
	{
		str = str_find_next(str, c, 1);
		if (*str != '\0')
		{
			next = str_find_next(str, c, 0);
			ret[i] = ft_strsub(str, 0, next - str);
			if (ret[i] == NULL)
				return (tabledel(ret, i));
			i++;
			str = next;
		}
	}
	ret[i] = 0;
	return (ret);
}
