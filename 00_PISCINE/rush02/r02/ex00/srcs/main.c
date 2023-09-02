/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 10:00:41 by mhotting          #+#    #+#             */
/*   Updated: 2023/08/27 22:58:29 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	make_dict(t_translation **dict, char *file_name)
{
	*dict = NULL;
	if (!parse_file(file_name, dict))
	{
		ft_putstr_error("Dict Error\n");
		if (*dict != NULL)
			clean_memory_dict(*dict);
		return (0);
	}
	return (1);
}

void	init_params(int argc, char **argv, char **file_name, char **number)
{
	if (argc == 2)
	{
		*file_name = "./assets/numbers.dict";
		*number = argv[1];
	}
	else
	{
		*file_name = argv[1];
		*number = argv[2];
	}
}

int	launch_translation(char *number, t_list **translation, t_translation *dict)
{
	int	res;

	*translation = NULL;
	res = translate(number, dict, translation);
	if (res == -1)
	{
		if (*translation != NULL)
			free_link_list(*translation);
		clean_memory_dict(dict);
		ft_putstr_error("Dict Error\n");
		return (0);
	}
	else if (res == 0 || *translation == NULL)
	{
		if (*translation != NULL)
			free_link_list(*translation);
		clean_memory_dict(dict);
		ft_putstr_error("Error\n");
		return (0);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_translation	*dict;
	char			*file_name;
	char			*number;
	t_list			*translation;

	if (argc <= 1 || argc > 3)
		return (0);
	init_params(argc, argv, &file_name, &number);
	if (!make_dict(&dict, file_name) || !get_number_cleaned(&number, dict))
		return (-1);
	if (!launch_translation(number, &translation, dict))
		return (-1);
	ft_print_list(translation);
	free_link_list(translation);
	clean_memory_dict(dict);
	return (0);
}
