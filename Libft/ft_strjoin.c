/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flhember <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 16:22:36 by flhember          #+#    #+#             */
/*   Updated: 2018/11/23 17:00:55 by flhember         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*jo;
	size_t	i;
	size_t	j;

	j = 0;
	i = 0;
	if (!s1 || !s2)
		return (NULL);
	if (!(jo = (char*)malloc(sizeof(char) *
					(ft_strlen(s1) + ft_strlen(s2) + 1))))
		return (NULL);
	while (i < ft_strlen(s1))
	{
		jo[i] = s1[i];
		i++;
	}
	while (j < ft_strlen(s2))
	{
		jo[i] = s2[j];
		i++;
		j++;
	}
	jo[i] = '\0';
	return (jo);
}
