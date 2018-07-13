/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsibiet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 11:52:23 by rsibiet           #+#    #+#             */
/*   Updated: 2015/11/25 12:15:54 by rsibiet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(const char *s1, const char *s2)
{
	int				i;
	unsigned char	*s1cp;
	unsigned char	*s2cp;

	s1cp = (unsigned char *)s1;
	s2cp = (unsigned char *)s2;
	i = 0;
	while (s1cp[i] == s2cp[i])
	{
		if (s1cp[i] == '\0')
			return (0);
		i++;
	}
	return (s1cp[i] - s2cp[i]);
}
