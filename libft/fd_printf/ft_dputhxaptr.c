/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dputhxaptr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asans-go <asans-go@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 16:09:40 by asans-go          #+#    #+#             */
/*   Updated: 2024/03/27 19:17:36 by asans-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_dprintf.h"

int	ft_dputhxaptr(int fd, unsigned long nb)
{
	char	*pointer_val;
	int		count;

	count = 0;
	pointer_val = "0123456789abcdef";
	if (!nb)
		return (ft_dputchar(fd, '0'));
	if (nb > 15)
	{
		count = ft_dputhxaptr(fd, nb / 16);
		if (count == -1)
			return (-1);
	}
	if (ft_dputchar(fd, pointer_val[nb % 16]) == -1)
		return (-1);
	count++;
	return (count);
}
