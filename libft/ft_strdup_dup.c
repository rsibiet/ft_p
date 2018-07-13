/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup_dup.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsibiet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/04 17:20:15 by rsibiet           #+#    #+#             */
/*   Updated: 2016/03/07 13:44:01 by rsibiet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strdup_dup(char **c)
{
	static int	i;
	char		**s;

	i = 0;
	while (c[i] != NULL)
		i++;
	s = (char **)malloc(sizeof(char *) * (i + 1));
	i = 0;
	while (c[i] != NULL)
	{
		s[i] = ft_strdup(c[i]);
		i++;
	}
	s[i] = NULL;
	return (s);
}
