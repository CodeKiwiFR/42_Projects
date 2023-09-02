/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 15:19:31 by mhotting          #+#    #+#             */
/*   Updated: 2023/08/16 19:50:19 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_approx_sqrt(int nb)
{
	long	i;

	if (nb <= 0)
		return (0);
	i = 1;
	while (i * i < nb)
		i += 1;
	return ((int)i);
}

int	ft_is_prime(int nb)
{
	int	i;
	int	nb_sqrt;

	if (nb <= 1)
		return (0);
	if (nb == 2)
		return (1);
	if (nb % 2 == 0)
		return (0);
	i = 3;
	nb_sqrt = ft_approx_sqrt(nb);
	while (i <= nb_sqrt && i < nb / 2)
	{
		if (nb % i == 0)
			return (0);
		i += 2;
	}
	return (1);
}

int	ft_find_next_prime(int nb)
{
	if (nb <= 2)
		return (2);
	else if (ft_is_prime(nb))
		return (nb);
	else if (nb % 2 == 0)
		return (ft_find_next_prime(nb + 1));
	else
		return (ft_find_next_prime(nb + 2));
}
