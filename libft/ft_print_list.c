/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flhember <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 20:22:24 by flhember          #+#    #+#             */
/*   Updated: 2018/11/23 17:57:19 by flhember         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_list(t_list *list)
{
	while (list)
	{
		ft_putchar('[');
		ft_putstr((char*)(list->content));
		ft_putchar(']');
		ft_putstr(" size: ");
		ft_putnbr((int)(list->content_size));
		ft_putstr("  -->  ");
		list = list->next;
	}
	ft_putstr("NULL");
}
