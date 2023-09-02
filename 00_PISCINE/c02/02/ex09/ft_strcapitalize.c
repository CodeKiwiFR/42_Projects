/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 18:12:36 by mhotting          #+#    #+#             */
/*   Updated: 2023/08/13 21:56:14 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_alphanum(char c)
{
	if (
		(c >= 'a' && c <= 'z')
		|| (c >= 'A' && c <= 'Z')
		|| (c >= '0' && c <= '9')
	)
		return (1);
	return (0);
}

int	ft_is_lower(char c)
{
	if (c >= 'a' && c <= 'z')
		return (1);
	return (0);
}

int	ft_is_upper(char c)
{
	if (c < 'A' || c > 'Z')
		return (0);
	return (1);
}

char	*ft_strcapitalize(char *str)
{
	char	in_word;
	char	*browser;

	in_word = 0;
	browser = str;
	while (*browser)
	{
		if (!in_word && ft_is_alphanum(*browser))
		{
			in_word = 1;
			if (ft_is_lower(*browser))
				*browser -= 32;
		}
		else if (in_word && ft_is_upper(*browser))
			*browser += 32;
		else if (in_word && !ft_is_alphanum(*browser))
			in_word = 0;
		browser++;
	}
	return (str);
}
