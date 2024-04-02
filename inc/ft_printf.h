/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asans-go <asans-go@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 17:34:30 by asans-go          #+#    #+#             */
/*   Updated: 2024/03/27 18:52:14 by asans-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../inc/libft.h"
# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>

int		ft_printf(const char *str, ...);
int		ft_putchar(int c);
int		ft_putstr(const char *str);
int		ft_putnbr(int nb);
int		ft_putunsnbr(unsigned int nb);
int		ft_puthxanbr(unsigned int n);
int		ft_puthxanbr_up(unsigned int n);
int		ft_puthxaptr(unsigned long n);

#endif
