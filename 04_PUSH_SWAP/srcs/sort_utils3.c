/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <mhotting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 19:32:09 by mhotting          #+#    #+#             */
/*   Updated: 2024/02/05 16:05:54 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	multiple_rr(t_ps_data *data, size_t nb)
{
	size_t	i;

	if (data == NULL)
		return ;
	i = 0;
	while (i < nb)
	{
		data->rr(data, true);
		i++;
	}
}

void	multiple_rrr(t_ps_data *data, size_t nb)
{
	size_t	i;

	if (data == NULL)
		return ;
	i = 0;
	while (i < nb)
	{
		data->rrr(data, true);
		i++;
	}
}
