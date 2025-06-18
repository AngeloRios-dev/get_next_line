/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angrios <angrios@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 15:35:47 by angrios           #+#    #+#             */
/*   Updated: 2025/06/18 22:11:41 by angrios          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#define BUFFER_SIZE 1024

static char	*append_buffer(char *stash, char *buffer, size_t bytes_read)
{
	char	*old_stash;

	old_stash = stash;
	buffer[bytes_read] = '\0';
	stash = ft_strjoin(old_stash, buffer);
	if (!stash)
	{
		free(old_stash);
		return (NULL);
	}
	free(old_stash);
	return (stash);
}

char	*read_until_newline(int fd, char *stash)
{
	char	*buffer;
	size_t	bytes_read;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	while (!ft_strchr(stash, '\n'))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(buffer);
			return (NULL);
		}
		if (bytes_read == 0)
			break;
		stash = ft_append_buffer(stash, buffer, bytes_read);
		if (!stash)
		{
			free(buffer);
			return (NULL);
		}
	}
	free(buffer);
	return (stash);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	return (NULL);
}


