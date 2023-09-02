/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 11:17:25 by mhotting          #+#    #+#             */
/*   Updated: 2023/08/26 22:34:30 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	reset_buffer(char buffer[BUFFER_SIZE])
{
	int	i;

	i = 0;
	while (i < BUFFER_SIZE)
	{
		buffer[i] = '\0';
		i++;
	}
}

char	*append_content(char *file_content, char buffer[BUFFER_SIZE])
{
	char	*temp;
	int		file_content_len;
	int		buffer_len;

	file_content_len = 0;
	if (file_content != NULL)
		file_content_len = ft_strlen(file_content);
	buffer_len = ft_strlen(buffer);
	temp = (char *)malloc((file_content_len + buffer_len + 1) * sizeof(char));
	if (!temp)
	{
		if (file_content != NULL)
			free(file_content);
		return (NULL);
	}
	temp[0] = '\0';
	if (file_content != NULL)
	{
		ft_strcat(temp, file_content);
		free(file_content);
	}
	ft_strcat(temp, buffer);
	return (temp);
}

char	*get_file_content(int fd)
{
	char	buffer[BUFFER_SIZE];
	int		nb_read;
	char	*file_content;

	file_content = NULL;
	nb_read = 1;
	while (nb_read > 0)
	{
		reset_buffer(buffer);
		nb_read = read(fd, buffer, BUFFER_SIZE - 1);
		if (nb_read == -1)
			break ;
		if (nb_read > 0)
		{
			file_content = append_content(file_content, buffer);
			if (file_content == NULL)
				return (NULL);
		}
	}
	if (nb_read == -1 && file_content != NULL)
	{
		free(file_content);
		return (NULL);
	}
	return (file_content);
}

int	parse_file(char *file_name, t_translation **dict)
{
	char	*file_content;
	int		fd;
	int		res;

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		return (0);
	file_content = get_file_content(fd);
	if (file_content == NULL)
		return (0);
	res = close(fd);
	if (res == -1)
	{
		free(file_content);
		return (0);
	}
	res = file_to_dict(file_content, dict);
	free(file_content);
	if (!res)
		return (0);
	return (1);
}
