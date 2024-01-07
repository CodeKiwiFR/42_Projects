/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <mhotting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 13:41:14 by mhotting          #+#    #+#             */
/*   Updated: 2024/01/07 17:08:47 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

# include "libft.h"

typedef struct s_stack
{
	t_list	*list;
	bool	(*push)(struct s_stack * stack, void *data);
	void	*(*pop)(struct s_stack *stack);
	void	(*rotate)(struct s_stack *stack);
	void	(*rev_rotate)(struct s_stack *stack);
	void	(*clear)(struct s_stack **stack, void (*del)(void *));
}	t_stack;

t_stack	*stack_init(void);
bool	stack_push(t_stack *stack, void *data);
void	*stack_pop(t_stack *stack);
void	stack_rotate(t_stack *stack);
void	stack_rev_rotate(t_stack *stack);
void	stack_clear(t_stack **stack, void (*del)(void *));

#endif
