/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miclandr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 15:23:47 by miclandr          #+#    #+#             */
/*   Updated: 2024/11/30 16:41:40 by miclandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_line(int fd, char **buffer, char **backup)
{
	int		byte;
	char	*last_line;

	byte = read_file(fd, buffer, backup);
	if (!**backup || byte == -1)
	{
		free_ptr(backup);
		return (NULL);
	}
	if (ft_strchr(*backup, '\n'))
		return (separate_line(backup));
	last_line = ft_strdup(*backup);
	free_ptr(backup);
	return (last_line);
}

int	read_file(int fd, char **buffer, char **backup)
{
	int		byte;
	char	*old_backup;

	byte = 1;
	while (!ft_strchr(*backup, '\n') && byte)
	{
		byte = read(fd, *buffer, BUFFER_SIZE);
		if (byte == -1)
			return (byte);
		(*buffer)[byte] = '\0';
		old_backup = *backup;
		*backup = ft_strjoin(old_backup, *buffer);
		free(old_backup);
	}
	return (byte);
}

char	*separate_line(char **backup)
{
	int		idx;
	char	*line;
	char	*old_backup;

	if (!*backup)
		return (NULL);
	idx = 0;
	while ((*backup)[idx] != '\n' && (*backup)[idx] != '\0')
		idx++;
	if ((*backup)[idx] == '\n')
		idx++;
	line = ft_substr(*backup, 0, idx);
	old_backup = *backup;
	if (idx < (int)ft_strlen(*backup))
		*backup = ft_strdup(*backup + idx);
	else
		*backup = NULL;
	free(old_backup);
	return (line);
}

void	free_ptr(char **ptr)
{
	if (*ptr)
	{
		free(*ptr);
		*ptr = NULL;
	}
}

char	*get_next_line(int fd)
{
	static char	*backup[OPEN_MAX];
	char		*buffer;
	char		*res;

	if (fd < 0 || fd > OPEN_MAX || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	if (!backup[fd])
		backup[fd] = ft_strdup("");
	res = get_line(fd, &buffer, &backup[fd]);
	free(buffer);
	return (res);
}
