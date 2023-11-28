/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_spec_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 11:11:03 by mhotting          #+#    #+#             */
/*   Updated: 2023/11/25 15:54:37 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	init_format_spec(t_format_spec format[NB_CONVERSION])
{
	format[0].flag = 'd';
	format[0].f = NULL;
	format[1].flag = 'i';
	format[1].f = NULL;
}
