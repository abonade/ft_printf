/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_put.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aileen <aileen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 16:17:09 by aileen            #+#    #+#             */
/*   Updated: 2021/10/21 18:52:49 by abonade-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_putchar(char c, t_data *data)
{
	write(1, &c, 1);
	data->nbchar++;
}

void	ft_putstr(char *str, t_data *data)
{
	int	i;

	if (!str)
		ft_putstr("(null)", data);
	i = 0;
	while (str && str[i])
	{
		ft_putchar(str[i], data);
		i++;
	}
}

void	ft_putnbr_base_recu(unsigned long int n, char *b, int b_len, t_data *dt)
{
	if (n == 0)
		return ;
	ft_putnbr_base_recu(n / b_len, b, b_len, dt);
	ft_putchar((b[n % b_len]), dt);
}

void	ft_putnbr_base(long int n, char *base, t_data *data)
{
	if (n == 0)
		ft_putchar('0', data);
	if (n < 0)
	{
		ft_putchar('-', data);
		n = -n;
	}
	ft_putnbr_base_recu((unsigned long int)n, base, ft_strlen(base), data);
}

void	ft_put_address(void *ptr, t_data *data)
{
	ft_putstr("0x", data);
	if ((unsigned long int)ptr == 0)
		ft_putchar('0', data);
	ft_putnbr_base_recu((unsigned long int)ptr, "0123456789abcdef", 16, data);
}
