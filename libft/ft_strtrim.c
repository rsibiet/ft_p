/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsibiet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 11:57:46 by rsibiet           #+#    #+#             */
/*   Updated: 2015/11/29 15:48:36 by rsibiet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>

static int		ft_iswhite_end(char const *s)
{
	int		j;

	j = 0;
	while (s[j] != '\0')
		j++;
	while ((s[j] == '\0' || s[j] == ' ' || s[j] == '\n' ||
				s[j] == '\t') && j > 0)
		j--;
	return (j);
}

static int		ft_iswhite_bg(char const *s, int *k)
{
	int		i;

	i = 0;
	while ((s[i] == ' ' || s[i] == '\n' || s[i] == '\t') && s[i] != '\0')
		i++;
	*k = 0;
	if (s[i] == '\0')
		*k = -1;
	if (s[i] == '\0')
		i = 0;
	return (i);
}

char			*ft_strtrim(char const *s)
{
	int		i;
	int		j;
	int		k;
	char	*cp;

	i = ft_iswhite_bg(s, &k);
	j = ft_iswhite_end(s);
	cp = (char *)malloc(sizeof(char) * (j - i + 1));
	if (cp == NULL)
		return (NULL);
	j = j - i + 1;
	while (s[i] != '\0' && k < j && k != -1)
	{
		cp[k] = s[i];
		i++;
		k++;
	}
	if (k == -1)
		cp[0] = '\0';
	else
		cp[k] = '\0';
	return (cp);
}
