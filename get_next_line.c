/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namirtha <namirtha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 11:44:10 by namirtha          #+#    #+#             */
/*   Updated: 2024/05/18 11:47:45 by namirtha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		buff[BUFFER_SIZE + 1];
	static char	*stash;
	char		*tmp;
	int			read_len;

	tmp = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0))
		return (free(tmp), free(stash), stash = NULL, NULL); // hier muss nur stash gefreet werden, da es eine static char ist
	read_len = 1;
	tmp = stash;
	while (read_len > 0 && ft_strlen(tmp, '\n') == -1)
	{
		read_len = read(fd, buff, BUFFER_SIZE);
		if (read_len == 0 && stash == NULL)
			break ;
		if (read_len < 0)
			return (NULL);
		buff[read_len] = '\0';
		stash = ft_strjoin(stash, buff);
		if (stash == NULL)
			return (NULL);
		tmp = stash;
	}
	stash = new_next_line(stash);
	return (extract_first_line(tmp, &stash));
}
// char	*get_next_line(int fd)
// {
// 	static char buff[BUFFER_SIZE];
// 	char        *temp;
// 	size_t      len_read;
// 	static size_t      pos;
// 	size_t	start_pos;

// 	start_pos = pos;
// 	if (fd < 0 || BUFFER_SIZE <= 0)
// 		return (NULL);
// 	if (buff[0] == '\0')
// 	{
// 		len_read = read(fd, buff, BUFFER_SIZE);
// 		// printf("len_read: %d\n", len_read);
// 	}
// 	while (1)
// 	{
// 		if (buff[pos] == '\n')
// 		{
// 			temp = malloc(sizeof(char) * (pos + 2));
// 			if (!temp)
// 				return (NULL);
// 			temp = ft_strncpy(temp, &buff[start_pos], pos - start_pos + 1);
// 			temp[pos - start_pos + 1] = '\0';
// 			// printf("temp: %s\n", temp);
// 			return (pos++, temp);
// 		}
// 		pos++;
// 	}
// }

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
#include <stdio.h>

int main(void)
{
    int fd;

    // fd = open("testtext.txt", O_RDONLY);
    //get_next_line(fd);
    printf("%s", get_next_line(-1));
    return (0);

}