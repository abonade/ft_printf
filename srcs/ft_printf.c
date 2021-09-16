/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aileen <aileen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 14:51:06 by aileen            #+#    #+#             */
/*   Updated: 2021/09/16 15:17:05 by abonade-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	t_data	*pouet;
	int		i;

	if (ft_malloc((void **)(&pouet), sizeof(t_data)))
		return (0);
	pouet->nbchar = 0;
	va_start(pouet->ag, str);
	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			ft_node(str[i], pouet);
		}
		else
			ft_putchar(str[i], pouet);
		i++;
	}
	va_end(pouet->ag);
	return (pouet->nbchar);
}
