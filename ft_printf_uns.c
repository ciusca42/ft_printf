/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_uns.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciusca <cristianiusca13@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 16:45:44 by ciusca            #+#    #+#             */
/*   Updated: 2023/11/10 16:09:50 by ciusca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	n_len(unsigned int n)
{
	int	i;

	i = 0;
	if (n < 0)
	{
		n *= -1;
		i ++;
	}
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n /= 10;
		i ++;
	}
	return (i);
}

int	ft_printf_uns(unsigned int cifra)
{
	char				*str;
	unsigned int		len;
	unsigned int		count;

	count = 0;
	len = n_len(cifra) - 1;
	str = (char *) malloc(sizeof(char) * len + 2);
	if (!str)
		return (0);
	if (cifra < 0)
	{
		cifra *= -1;
		str[0] = '-';
	}
	if (cifra == 0)
		str[0] = '0';
	str[len + 1] = 0;
	while (cifra > 0)
	{
		str[len--] = cifra % 10 + 48;
		cifra /= 10;
	}
	count += ft_putstr(str);
	free(str);
	return (count);
}
