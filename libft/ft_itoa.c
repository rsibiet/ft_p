/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsibiet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 11:44:46 by rsibiet           #+#    #+#             */
/*   Updated: 2015/11/29 15:27:16 by rsibiet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int		ft_i_compt(int i, long nb)
{
	while (nb > 9)
	{
		nb = nb / 10;
		i++;
	}
	return (i);
}

char			*ft_itoa(int n)
{
	char	*conv;
	int		i;
	long	nb;

	i = 1;
	nb = n;
	if (nb < 0)
		i++;
	if (nb < 0)
		nb *= -1;
	i = ft_i_compt(i, nb);
	conv = (char *)malloc(sizeof(char) * (i + 1));
	if (conv == NULL)
		return (NULL);
	conv[i--] = '\0';
	while (nb > 0)
	{
		conv[i--] = nb % 10 + '0';
		nb = nb / 10;
	}
	if (i == 0 && conv[1] != '\0')
		conv[i] = '-';
	else if (i == 0)
		conv[0] = '0';
	return (conv);
}
