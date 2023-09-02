/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   link_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gurousta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 14:25:41 by gurousta          #+#    #+#             */
/*   Updated: 2023/08/27 15:38:32 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

t_list	*ft_create_elem(char *str)
{
	t_list	*new_node;

	new_node = (t_list *)malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	new_node->word = str;
	new_node->next = NULL;
	return (new_node);
}

int	ft_push_back(t_list **head, char *str)
{
	t_list	*new_node;
	t_list	*last;

	new_node = ft_create_elem(str);
	if (!new_node)
		return (0);
	if (*head != NULL)
	{
		last = *head;
		while (last->next)
			last = last->next;
		last->next = new_node;
	}
	else
		*head = new_node;
	return (1);
}

int	ft_push_front(t_list **head, char *str)
{
	t_list	*new_node;
	t_list	*last;

	last = *head;
	new_node = ft_create_elem(str);
	if (!new_node)
		return (0);
	new_node->next = last;
	last = new_node;
	return (1);
}

void	free_link_list(t_list *head)
{
	t_list	*temp;

	while (head)
	{
		temp = head;
		head = head->next;
		free(temp);
	}
}

void	ft_print_list(t_list *head)
{
	t_list	*last;

	last = head;
	while (last)
	{
		ft_putstr(last->word);
		if (last->next != NULL)
			ft_putchar(' ');
		else
			ft_putchar('\n');
		last = last->next;
	}
}
