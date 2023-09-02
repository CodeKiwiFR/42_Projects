/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 21:53:49 by mhotting          #+#    #+#             */
/*   Updated: 2023/08/18 22:17:54 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str);

int	ft_check_input(char *input)
{
	int	input_len;
	int	i;

	input_len = ft_strlen(input);
	if (input_len != 31)
		return (0);
	i = 0;
	while (i < input_len)
	{
		if (i % 2 == 0 && !(input[i] >= '1' && input[i] <= '4'))
			return (0);
		else if (i % 2 == 1 && input[i] != ' ')
			return (0);
		i++;
	}
	return (1);
}
