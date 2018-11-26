/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flhember <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 15:11:47 by flhember          #+#    #+#             */
/*   Updated: 2018/11/26 18:24:48 by flhember         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*readfd(char *str, const int fd)
{
	int		size;
	char	buf[BUFF_SIZE + 1];

	while ((size = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[size] = '\0';
		str = ft_strjoinfree(str, buf, 1);
	}
	return (str);
}

int		get_next_line(const int fd, char **line)
{
	static char	*str;
	static int	flag;
	int			i;

	i = 0;
	if (fd == -1 || line == NULL)
		return (-1);
	if (flag == 0)
	{
		if (!(str = malloc(sizeof(char) * BUFF_SIZE)))
			return (-1);
		str = readfd(str, fd);
		flag++;
	}
	if (str[i])
	{
		while (str[i] != '\n' && str[i])
			i++;
		*line = ft_strsub(str, 0, i);
		str = &str[i + 1];
		return (1);
	}
	return (0);
}

int		main(int argc, char *argv[])
{
	int		fd;
	char	*line;
	int		res;

	res = 1;
	if (argc <= 1 || argc > 2)
		return 0;
	fd = open(argv[1], O_RDONLY);
	while (res == 1)
	{
		res = get_next_line(fd, &line);
		if (res == 1)
		{
			ft_putstr(line);
			ft_putchar('\n');
		}
	}
	close(fd);
	return (0);
}
