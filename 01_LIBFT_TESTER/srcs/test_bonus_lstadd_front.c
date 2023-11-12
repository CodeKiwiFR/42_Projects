/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_bonus_lstadd_front.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 08:36:04 by mhotting          #+#    #+#             */
/*   Updated: 2023/11/10 13:59:10 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_test.h"

void	test_lstadd_front(void)
{
	int	cpt;
	int	test_val;

	cpt = 1;
	print_test_intro("(B) lstadd_front");

	// Test 1
	test_val = (cpt == 1);
	print_test_infos(cpt++, test_val, 1);
}
