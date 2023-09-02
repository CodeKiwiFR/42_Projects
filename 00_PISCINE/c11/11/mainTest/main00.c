/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 18:13:27 by mhotting          #+#    #+#             */
/*   Updated: 2023/08/24 23:11:10 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>            

void	ft_foreach(int *tab, int length, void(*f)(int));
    
void    ft_putchar(char c)     
{
    write(1, &c, 1);    
}       

void    ft_putnbr(int nb)
{
    long    nb_size;           
    long    reminder;          

    reminder = nb;             
    if (reminder < 0)          
    {
        write(1, "-", 1);      
        reminder *= -1;        
    }
    nb_size = 10;              
    while (reminder / nb_size != 0) 
        nb_size *= 10;         
    while (nb_size != 1)       
    {
        nb_size /= 10;         
        ft_putchar((char)(reminder / nb_size) + '0');
        reminder %= nb_size;   
    }
    return ;
}


int	main(void)
{
	int	tab[] = {1, 2, 3, 4, 5, 6};
	ft_foreach(tab, 6, ft_putnbr);
	return (0);
}
