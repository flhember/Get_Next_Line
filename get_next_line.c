/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flhember <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 19:24:05 by flhember          #+#    #+#             */
/*   Updated: 2018/11/27 21:31:03 by flhember         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*readfd(const int fd)
{
	int		size;
	char	buf[BUFF_SIZE + 1];
	char	*str;

	if (!(str = malloc(sizeof(char) * BUFF_SIZE)))
		return (0);
	while ((size = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[size] = '\0';
		str = ft_strjoinfree(str, buf, 1);
	}
	if (size < 0)
		return (0);
	return (str);
}

t_list	*checkfd(t_list **list, const int fd)
{
	t_list *tmp;

	tmp = *list;
	while (tmp)
	{
		if (fd == ((int)tmp->content_size))
			return (tmp);
		tmp = tmp->next;
	}
	tmp = ft_lstnew("\0", fd);
	ft_lstadd(list, tmp);
	if (!(tmp->content = readfd(fd)))
		return (0);
	return (tmp);
}

int		get_next_line(const int fd, char **line)
{
	static t_list	*list;
	int				i;
	t_list			*new;

	i = 0;
	if (fd < 0 || line == NULL)
		return (-1);
	if (!(new = checkfd(&list, fd)))
		return (-1);
	if (((char*)(new->content))[i])
	{
		while (((char *)new->content)[i] != '\n' && new->content)
			i++;
		*line = ft_strsub(new->content, 0, i);
		new->content = &new->content[i + 1];
		return (1);
	}
	else
		*line = ft_strdup("");
	return (0);
}

int		main(int argc, char *argv[])
{
	int		fd;
	int		fd2;
	char	*line;
	int		res;

	res = 1;
	if (argc <= 1 || argc > 3)
		return 0;
	fd = open(argv[1], O_RDONLY);
	fd2 = open(argv[2], O_RDONLY);
		res = get_next_line(fd, &line);
		ft_putstr(line);
		ft_putchar('\n');
		res = get_next_line(fd2, &line);
		ft_putstr(line);
		ft_putchar('\n');
		res = get_next_line(fd, &line);
		ft_putstr(line);
		ft_putchar('\n');
		res = get_next_line(fd2, &line);
		ft_putstr(line);
		ft_putchar('\n');
		res = get_next_line(fd, &line);
		ft_putstr(line);
		ft_putchar('\n');
		res = get_next_line(fd2, &line);
		ft_putstr(line);
		ft_putchar('\n');
		
	close(fd);
	return (0);
}
