/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namirtha <namirtha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 10:41:01 by namirtha          #+#    #+#             */
/*   Updated: 2024/05/06 10:51:36 by namirtha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	char		buff[BUFFER_SIZE + 1];
	static char	*stash[OPEN_MAX];
	char		*tmp;
	int			read_len;

	tmp = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) || fd > OPEN_MAX)
		return (free(tmp), free(stash[fd]), stash[fd] = NULL, NULL);
	read_len = 1;
	tmp = stash[fd];
	while (read_len > 0 && ft_strlen(tmp, '\n') == -1)
	{
		read_len = read(fd, buff, BUFFER_SIZE);
		if (read_len == 0 && stash[fd] == NULL)
			break ;
		if (read_len < 0)
			return (NULL);
		buff[read_len] = '\0';
		stash[fd] = ft_strjoin(stash[fd], buff);
		if (stash[fd] == NULL)
			return (NULL);
		tmp = stash[fd];
	}
	stash[fd] = new_next_line(stash[fd]);
	return (extract_first_line(tmp, &stash[fd]));
}

char	*new_next_line(char *tmp)
{
	char	*newline;
	int		i;
	int		x;

	i = 0;
	if (tmp == NULL)
		return (NULL);
	while (tmp[i] && tmp[i] != '\n')
		i++;
	if (!tmp[i])
		return (NULL);
	newline = malloc((ft_strlen(tmp, '\0') - i + 1));
	if (!newline)
		return (NULL);
	x = 0;
	while (tmp[++i])
		newline[x++] = tmp[i];
	newline[x++] = '\0';
	return (newline);
}

char	*extract_first_line(char *tmp, char **stash)
{
	int		newline;
	int		index;
	char	*res;

	res = NULL;
	if (tmp == NULL || ft_strlen(tmp, '\0') == 0)
		return (free(tmp), NULL);
	newline = ft_strlen(tmp, '\n');
	if (newline == -1)
		return (tmp);
	res = malloc(sizeof(char) * (newline + 2));
	if (!res)
		return (free(*stash), *stash = NULL, free(tmp), tmp = NULL, NULL);
	index = -1;
	while (++index < newline + 1)
		res[index] = tmp[index];
	res[index] = 0;
	free (tmp);
	return (res);
}
