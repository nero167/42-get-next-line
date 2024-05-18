/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namirtha <namirtha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 10:46:40 by namirtha          #+#    #+#             */
/*   Updated: 2024/05/10 12:20:27 by namirtha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_strlen(char *str, char c)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (-1);
	while (str[i] && str[i] != c)
		i++;
	if (str[i] == c)
		return (i);
	return (-1);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		index_s2;
	char	*str;

	if (!s2)
		return (0);
	if (!s1 || s1 == NULL)
	{
		s1 = malloc(sizeof(char) * 1);
		if (!s1)
			return (0);
		s1[0] = 0;
	}
	str = malloc((ft_strlen(s1, '\0')
				+ ft_strlen(s2, '\0') + 1) * sizeof(char));
	if (!str)
		return (free(s1), NULL);
	i = -1;
	while (s1[++i] != '\0')
		str[i] = s1[i];
	index_s2 = 0;
	while (s2[index_s2] != '\0')
		str[i++] = s2[index_s2++];
	str[i] = '\0';
	return (free(s1), str);
}
