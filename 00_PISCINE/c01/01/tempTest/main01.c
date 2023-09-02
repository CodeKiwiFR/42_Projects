/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 14:11:35 by mhotting          #+#    #+#             */
/*   Updated: 2023/08/10 15:56:13 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_ultimate_ft(int *********nbr);

int	main(void)
{
	int	nbr;
	int	*nbrp1;
	int	**nbrp2;
	int	***nbrp3;
	int	****nbrp4;
	int	*****nbrp5;
	int	******nbrp6;
	int	*******nbrp7;
	int	********nbrp8;
	int	*********nbrp9;

	nbr = 0;
	nbrp1 = &nbr;
	nbrp2 = &nbrp1;
	nbrp3 = &nbrp2;
	nbrp4 = &nbrp3;
	nbrp5 = &nbrp4;
	nbrp6 = &nbrp5;
	nbrp7 = &nbrp6;
	nbrp8 = &nbrp7;
	nbrp9 = &nbrp8;
	printf("Before: %d\n", nbr);
	ft_ultimate_ft(nbrp9);
	printf("After: %d\n", nbr);
	return (0);
}
