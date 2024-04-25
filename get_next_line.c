/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namirtha <student.42heilbronn.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 16:34:10 by namirtha          #+#    #+#             */
/*   Updated: 2024/04/25 15:01:52 by namirtha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char    *get_next_line(int fd)
{
    static char    buff[BUFFER_SIZE];
    char    *temp;
    size_t  len_read;
    size_t  pos;

    pos = 0;
    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    len_read = read(fd, buff, BUFFER_SIZE);
    printf("len_read: %d\n", len_read);
    while (1)
    {
        if (buff[pos] == '\n')
        {
            temp = malloc(sizeof(char) * (pos + 2));
            if (!temp)
                return (NULL);
            temp = strncpy(temp, buff, pos + 1);
            temp[pos + 1] = '\0';
            printf("temp: %s\n", temp);
            return (temp);
        }
        pos++;
        if (buff == is_empty)
        {
            buff[]
        }
    }
}