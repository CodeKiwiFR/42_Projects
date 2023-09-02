/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stdin_reader.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 10:33:53 by mhotting          #+#    #+#             */
/*   Updated: 2023/08/30 18:36:25 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	flush_buffer(char buffer[BUFFER_SIZE])
{
	int	i;

	i = 0;
	while (i < BUFFER_SIZE)
	{
		buffer[i] = '\0';
		i++;
	}
}

int	append_content(char **file_content, char buffer[BUFFER_SIZE])
{
	char	*temp;
	int		file_content_len;
	int		buffer_len;

	file_content_len = 0;
	if (*file_content != NULL)
		file_content_len = ft_strlen(*file_content);
	buffer_len = ft_strlen(buffer);
	temp = (char *)malloc((file_content_len + buffer_len + 1) * sizeof(char));
	if (!temp)
		return (0);
	temp[0] = '\0';
	if (*file_content != NULL)
	{
		ft_strcat(temp, *file_content);
		free(*file_content);
	}
	ft_strcat(temp, buffer);
	*file_content = temp;
	return (1);
}

int	get_stdin_file_content(char **file_content)
{
	char	buffer[BUFFER_SIZE];
	int		nb_read;

	nb_read = 1;
	while (nb_read > 0)
	{
		flush_buffer(buffer);
		nb_read = read(0, buffer, BUFFER_SIZE - 1);
		if (nb_read == -1 || !append_content(file_content, buffer))
			return (0);
		if (nb_read == 1 && buffer[0] == -1)
			break ;
	}
	return (1);
}

int	read_from_stdin(t_map *map)
{
	char	*file_content;

	file_content = NULL;
	if (!get_stdin_file_content(&file_content))
	{
		if (file_content != NULL)
			free(file_content);
		return (0);
	}
	fill_struct(map, file_content);
	free(file_content);
	return (1);
}
