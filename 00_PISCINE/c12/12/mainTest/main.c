/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 10:24:05 by mhotting          #+#    #+#             */
/*   Updated: 2023/08/31 16:39:52 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "ft_list.h"

void	ft_list_push_front(t_list **begin_list, void *data);
int		ft_list_size(t_list *begin_list);
t_list	*ft_list_last(t_list *begin_list);
void	ft_list_push_back(t_list **begin_list, void *data);
t_list	*ft_list_push_strs(int size, char **strs);
void	ft_list_clear(t_list *begin_list, void (*free_fct)(void *));
t_list	*ft_list_at(t_list *begin_list, unsigned int nbr);
void	ft_list_reverse(t_list **begin_list);
void	ft_list_foreach(t_list *begin_list, void (*f)(void *));
void 	ft_list_foreach_if(t_list *begin_list, void (*f)(void *), void *data_ref, int (*cmp)());
t_list	*ft_list_find(t_list *begin_list, void *data_ref, int (*cmp)());
void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)(), void (*free_fct)(void *));
void	ft_list_merge(t_list **begin_list1, t_list *begin_list2);
void	ft_list_sort(t_list **begin_list, int (*cmp)());
void	ft_list_reverse_fun(t_list *begin_list);
void	ft_sorted_list_insert(t_list **begin_list, void *data, int (*cmp)());
void	ft_sorted_list_merge(t_list **begin_list1, t_list *begin_list2, int (*cmp)());

void	ft_disp_list(t_list *ptr)
{
	int	i;

	if (ptr == (t_list *)0)
		return ;
	i = 0;
	while (ptr != (t_list *)0)
	{
		printf("LINK %d: %s\n", i, (char *)ptr->data);
		i++;
		ptr = ptr->next;
	}
}

void	ft_disp_link(t_list *ptr)
{
	if (ptr == NULL)
		printf("The LINK is NULL\n");
	else
		printf("LINK: %s\n", (char *)ptr->data);
}

void	ft_strtoupper(void *ptr)
{
	char	*str;
	int		i;

	str = (char *)ptr;
	i = 0;
	while (str[i])
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] -= 32;
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_list	*ptr;
	t_list	*list1;
	t_list	*list2;
	t_list	*list3;
	t_list	*last;
	char	*str1;
	char	*str2;
	char	*str3;
	char	*strs[4];

	ptr = NULL;
	printf("SIZE: %d\n", ft_list_size(ptr));
	ptr = ft_create_elem(strdup("A"));
	ft_disp_list(ptr);
	printf("SIZE: %d\n", ft_list_size(ptr));

	ft_list_push_front(&ptr, strdup("B"));
	ft_list_push_front(&ptr, strdup("C"));
	ft_list_push_front(&ptr, strdup("G"));
	ft_disp_list(ptr);
	printf("SIZE: %d\n", ft_list_size(ptr));
	last = ft_list_last(ptr);
	ft_disp_link(last);
	ft_list_clear(ptr, &free);

	printf("\n----------\n");
	list2 = NULL;
	ft_list_push_back(&list2, strdup("1"));
	ft_list_push_back(&list2, strdup("2"));
	ft_list_push_back(&list2, strdup("3"));
	ft_disp_list(list2);
	printf("SIZE: %d\n", ft_list_size(list2));
	ft_list_clear(list2, &free);
	
	if (argc > 2)
	{
		str1 = strdup(argv[2]);
		str2 = strdup(argv[3]);
		str3 = strdup(argv[4]);
		strs[0] = str1;
		strs[1] = str2;
		strs[2] = str3;
		printf("\n----------\n");
		list3 = NULL;
		list3 = ft_list_push_strs(atoi(argv[1]), strs);
		ft_disp_list(list3);
		printf("SIZE: %d\n", ft_list_size(list3));
		ptr = ft_list_at(list3, 3);
		ft_disp_link(ptr);
		ft_list_reverse(&list3);
		ft_disp_list(list3);
		//ft_list_foreach(list3, &ft_strtoupper);
		ft_list_foreach_if(list3, &ft_strtoupper, "abc", &strcmp);
		ft_disp_list(list3);
		ptr = ft_list_find(list3, "ABC", &strcmp);
		ft_disp_link(ptr);
		ptr = ft_list_find(list3, "abc", &strcmp);
		ft_disp_link(ptr);
		ft_list_remove_if(&list3, "ABC", &strcmp, &free);
		ft_list_remove_if(&list3, "ghi", &strcmp, &free);
		ft_disp_list(list3);
		ft_list_clear(list3, &free);
	}

	printf("\n----------\n");
	printf("LIST MERGE:\n");
	list1 = NULL;
	list2 = NULL;
	ft_list_push_front(&list1, strdup("B"));
	ft_list_push_front(&list1, strdup("O"));
	ft_list_push_front(&list1, strdup("B"));
	ft_list_push_front(&list2, strdup("P"));
	ft_list_push_front(&list2, strdup("Y"));
	ft_list_push_front(&list2, strdup("P"));
	printf("LIST1:\n");
	ft_disp_list(list1);
	printf("LIST2:\n");
	ft_disp_list(list2);
	printf("MERGE...\n");
	ft_list_merge(&list1, list2);
	ft_disp_list(list1);
	ft_list_clear(list1, &free);

	printf("\n----------\n");
	printf("LIST SORT:\n");
	list1 = NULL;
	ft_list_push_front(&list1, strdup("def"));
	ft_list_push_front(&list1, strdup("abc"));
	ft_list_push_front(&list1, strdup("ghi"));
	ft_list_push_front(&list1, strdup("123"));
	ft_list_push_front(&list1, strdup("056"));
	ft_list_push_front(&list1, strdup("cgl"));
	printf("LIST1:\n");
	ft_disp_list(list1);
	ft_list_sort(&list1, &strcmp);
	printf("LIST1 sorted:\n");
	ft_disp_list(list1);
	ft_list_clear(list1, &free);

	printf("\n----------\n");
	printf("LIST REVERSE:\n");
	list1 = NULL;
	ft_list_push_front(&list1, strdup("9"));
	ft_list_push_front(&list1, strdup("8"));
	ft_list_push_front(&list1, strdup("7"));
	ft_list_push_front(&list1, strdup("6"));
	ft_list_push_front(&list1, strdup("5"));
	printf("LIST1:\n");
	ft_disp_list(list1);
	ft_list_reverse_fun(list1);
	printf("LIST1 reversed:\n");
	ft_disp_list(list1);
	ft_list_clear(list1, &free);

	printf("\n----------\n");
	printf("SORT INSERT:\n");
	list1 = NULL;
	ft_list_push_front(&list1, strdup("1"));
	ft_list_push_front(&list1, strdup("3"));
	ft_list_push_front(&list1, strdup("5"));
	ft_list_push_front(&list1, strdup("7"));
	ft_list_push_front(&list1, strdup("9"));
	printf("LIST1:\n");
	ft_disp_list(list1);
	ft_list_sort(&list1, &strcmp);
	printf("LIST1 sorted:\n");
	ft_sorted_list_insert(&list1, strdup("0"), &strcmp);
	printf("LIST1 after insert:\n");
	ft_disp_list(list1);
	ft_list_clear(list1, &free);

	printf("\n----------\n");
	printf("SORT MERGE:\n");
	list1 = NULL;
	ft_list_push_front(&list1, strdup("1"));
	ft_list_push_front(&list1, strdup("2"));
	ft_list_push_front(&list1, strdup("3"));
	ft_list_push_front(&list1, strdup("4"));
	ft_list_push_front(&list1, strdup("5"));
	list2 = NULL;
	ft_list_push_front(&list2, strdup("6"));
	ft_list_push_front(&list2, strdup("9"));
	ft_list_push_front(&list2, strdup("7"));
	printf("LIST1:\n");
	ft_list_sort(&list1, &strcmp);
	ft_disp_list(list1);
	printf("LIST2:\n");
	ft_list_sort(&list2, &strcmp);
	ft_disp_list(list2);
	ft_sorted_list_merge(&list1, list2, &strcmp);
	printf("LIST1 after merge:\n");
	ft_disp_list(list1);
	ft_list_clear(list1, &free);
	return (0);
}
