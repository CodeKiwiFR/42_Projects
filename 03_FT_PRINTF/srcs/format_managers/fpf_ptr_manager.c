/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fpf_ptr_manager.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 17:19:25 by mhotting          #+#    #+#             */
/*   Updated: 2023/12/14 16:41:12 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*fpf_ptr_manager(va_list args, t_input_format *input)
{
	void	*ptr;
	char	*res;
	char	*temp;

	if (input && 0)
		return (NULL);
	ptr = va_arg(args, void *);
	if (ptr == NULL)
		res = ft_strdup("(nil)");
	else
	{
		temp = ft_ultoa_base((unsigned long) ptr, "0123456789abcdef");
		if (temp == NULL)
			return (NULL);
		res = ft_strjoin("0x", temp);
		free(temp);
	}
	return (res);
}
