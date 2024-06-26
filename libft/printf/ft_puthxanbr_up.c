/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthxanbr_up.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asans-go <asans-go@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 18:29:46 by asans-go          #+#    #+#             */
/*   Updated: 2024/03/27 19:21:59 by asans-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_printf.h"

int	ft_puthxanbr_up(unsigned int nb)
{
	char	*hex_val;
	int		count;

	count = 0;
	hex_val = "0123456789ABCDEF";
	if (nb > 15)
	{
		count = ft_puthxanbr_up(nb / 16);
		if (count == -1)
			return (-1);
	}
	if (ft_putchar(hex_val[nb % 16]) == -1)
		return (-1);
	count++;
	return (count);
}
