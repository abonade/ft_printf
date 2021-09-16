/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aileen <aileen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 15:14:02 by aileen            #+#    #+#             */
/*   Updated: 2021/09/16 15:51:38 by abonade-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_malloc(void **ptr, int size)
{
	*ptr = malloc(size);
	if (*ptr == NULL)
		return (1);
	return (0);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_node(char c, t_data *data)
{
	if (c == 'c')
		ft_putchar((char)va_arg(data->ag, int), data);
	if (c == 's')
		ft_putstr(va_arg(data->ag, char *), data);
	if (c == 'p')
		ft_put_address(va_arg(data->ag, void *), data);
	if (c == 'd' || c == 'i')
		ft_putnbr_base(va_arg(data->ag, int), "0123456789", data);
	if (c == 'u')
		ft_putnbr_base(va_arg(data->ag, unsigned int), "0123456789", data);
	if (c == 'x')
		ft_putnbr_base(va_arg(data->ag, unsigned int),
			"0123456789abcdef", data);
	if (c == 'X')
		ft_putnbr_base(va_arg(data->ag, unsigned int),
			"0123456789ABCDEF", data);
	if (c == '%')
		ft_putchar('%', data);
}
