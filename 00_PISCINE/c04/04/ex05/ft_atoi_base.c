/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 18:14:12 by mhotting          #+#    #+#             */
/*   Updated: 2023/08/16 09:50:07 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_base_valid(char c)
{
	if (c > ' ' && c <= '~' && c != '+' && c != '-')
		return (1);
	return (0);
}

long	ft_check_base(char *base)
{
	long	i;
	long	j;

	i = 0;
	while (base[i] != '\0')
	{
		if (!ft_is_base_valid(base[i]))
			return (-1);
		j = i + 1;
		while (base[j] != '\0')
		{
			if (!ft_is_base_valid(base[j]) || base[i] == base[j])
				return (-1);
			j++;
		}
		i++;
	}
	if (i < 2)
		return (-1);
	return (i);
}

int	ft_index_of(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i] != '\0')
	{
		if (c == base[i])
			return (i);
		i++;
	}
	return (-1);
}

long	ft_eval_number(char *nb, char *base, long base_len)
{
	long	num;
	long	char_index;

	num = 0;
	while (*nb)
	{
		char_index = ft_index_of(*nb, base);
		if (char_index == -1)
			return (num);
		num *= base_len;
		num += char_index;
		nb++;
	}
	return (num);
}

int	ft_atoi_base(char *str, char *base)
{
	long	base_len;
	int		sign;

	base_len = ft_check_base(base);
	if (base_len == -1)
		return (0);
	while (
		*str && 
		(
			*str == ' ' || *str == '\f' || *str == '\n'
			|| *str == '\r' || *str == '\t' || *str == '\v'
		)
	)
		str++;
	sign = 1;
	while (*str && (*str == '+' || *str == '-'))
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	return ((int)(sign * ft_eval_number(str, base, base_len)));
}
