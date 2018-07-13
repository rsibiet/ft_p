/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_hex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsibiet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/20 16:13:28 by rsibiet           #+#    #+#             */
/*   Updated: 2017/04/20 16:13:57 by rsibiet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static uint64_t	pow_16(size_t pw)
{
	uint64_t	to_return;
	size_t		i;

	i = 0;
	to_return = 1;
	while (i < pw && to_return <= 1152921504606846976)
	{
		to_return = to_return * 16;
		++i;
	}
	return (to_return);
}

static char		get_char(unsigned char digit, int is_upcase)
{
	if (digit <= 9)
		return (digit + '0');
	digit -= 10;
	if (is_upcase)
		return (digit + 'A');
	else
		return (digit + 'a');
}

static void		print_num(size_t num_digit, uint64_t n,
						char *to_return, int is_upcase)
{
	size_t			i;
	size_t			istr;
	unsigned char	digit;

	i = num_digit;
	istr = 0;
	while (i > 0)
	{
		digit = n / pow_16(i - 1);
		n = n % pow_16(i - 1);
		to_return[istr] = get_char(digit, is_upcase);
		++istr;
		--i;
	}
	to_return[num_digit] = '\0';
}

char			*ft_itoa_hex(uint64_t n)
{
	size_t		digit;
	uint64_t	nb;
	char		*c;

	digit = 1;
	nb = n;
	if ((c = (char *)malloc(sizeof(char) * 20)) == NULL)
		return (NULL);
	if (n > 1152921504606846976)
		digit = 15;
	else
	{
		while (pow_16(digit) <= nb)
			++digit;
	}
	print_num(digit, nb, c, 0);
	return (c);
}
