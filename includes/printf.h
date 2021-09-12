/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aileen <aileen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 14:55:31 by aileen            #+#    #+#             */
/*   Updated: 2021/09/12 16:30:54 by aileen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

typedef struct s_data
{
	int			nbchar;
	va_list		ag;
}				t_data;

int		ft_printf(const char *str, ...);
int		ft_malloc(void **ptr, int size);
void	ft_node(char c, t_data *data);
int		ft_strlen(char *str);
void	ft_putchar(char c, t_data *data);
void	ft_put_address(void *ptr, t_data *data);
void	ft_putnbr_base(long int n, char *base, t_data *data);
void	ft_putstr(char *str, t_data *data);

#endif