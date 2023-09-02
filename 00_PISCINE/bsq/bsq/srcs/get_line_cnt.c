/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_line_cnt.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbigot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 12:35:25 by pbigot            #+#    #+#             */
/*   Updated: 2023/08/29 17:39:46 by pbigot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	get_line_cnt(char *str)
{
	char	*num;
	int		ans;
	int		count;
	int		i;

	i = 0;
	count = 0;
	while (str[count] != '\n')
		count++;
	num = (char *)malloc((count + 1) * sizeof(char));
	if (!num)
		return (0);
	while (i < count - 3)
	{
		num[i] = str[i];
		i++;
	}
	num[i] = 0;
	ans = ft_atoi(num);
	free(num);
	return (ans);
}
