/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 16:32:06 by mhotting          #+#    #+#             */
/*   Updated: 2023/11/10 16:32:27 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_test.h"
#include <stdio.h>

int	main(void)
{
	system("clear");
	printf("***************************\n");
	printf("**  LIBFT TESTS (BONUS)  **\n");
	printf("***************************\n\n");

    test_lstnew();
    test_lstadd_front();
    test_lstsize();
    test_lstlast();
    test_lstadd_back();
    test_lstdelone();
    test_lstclear();
    test_lstiter();
    test_lstmap();
	printf("\n");

	return (0);
}
