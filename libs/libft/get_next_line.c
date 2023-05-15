/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galamy <galamy@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 11:01:35 by galamy            #+#    #+#             */
/*   Updated: 2023/01/13 14:26:14 by galamy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*before_end_line(char *save)
{
	char	*line;
	int		i;

	i = 0;
	if (!save[i])
		return (NULL);
	while (save[i] && save[i] != '\n')
		i++;
	line = (char *)malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (save[i] && save[i] != '\n')
	{
		line[i] = save[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*after_end_line(char *save)
{
	char	*next_line;
	int		i;
	int		j;

	if (!save)
		return (NULL);
	i = 0;
	while (save[i] && save[i] != '\n')
		i++;
	if (!save[i])
	{
		free(save);
		return (NULL);
	}
	next_line = (char *)malloc(sizeof(char) * (ft_strlen(save) - i + 1));
	if (!next_line)
		return (NULL);
	i++;
	j = 0;
	while (save[i])
		next_line[j++] = save[i++];
	next_line[j] = '\0';
	free(save);
	return (next_line);
}

char	*ft_read_fd(int fd, char *save)
{
	char	*buff;
	ssize_t	ret;

	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	ret = 1;
	while (!ft_strchr(save, '\n') && ret != 0)
	{
		ret = read(fd, buff, BUFFER_SIZE);
		if (ret == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[ret] = '\0';
		save = ft_strjoin_free(save, buff);
	}
	free(buff);
	return (save);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*save;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	save = ft_read_fd(fd, save);
	if (!save)
		return (NULL);
	line = before_end_line(save);
	save = after_end_line(save);
	return (line);
}
