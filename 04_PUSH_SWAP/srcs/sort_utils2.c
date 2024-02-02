/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <mhotting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 19:32:09 by mhotting          #+#    #+#             */
/*   Updated: 2024/02/02 14:38:20 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	multiple_ra(t_ps_data *data, size_t nb)
{
	size_t	i;

	i = 0;
	while (i < nb)
	{
		data->ra(data, true);
		i++;
	}
}

void	multiple_rra(t_ps_data *data, size_t nb)
{
	size_t	i;

	i = 0;
	while (i < nb)
	{
		data->rra(data, true);
		i++;
	}
}
