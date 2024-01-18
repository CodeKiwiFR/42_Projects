/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <mhotting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 00:50:05 by mhotting          #+#    #+#             */
/*   Updated: 2024/01/18 18:38:41 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include "stack.h"

typedef struct s_ps_data
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	void	(*sa)(struct s_ps_data *data);
	void	(*sb)(struct s_ps_data *data);
	void	(*ss)(struct s_ps_data *data);
	void	(*pa)(struct s_ps_data *data);
	void	(*pb)(struct s_ps_data *data);
	void	(*ra)(struct s_ps_data *data);
	void	(*rb)(struct s_ps_data *data);
	void	(*rr)(struct s_ps_data *data);
	void	(*rra)(struct s_ps_data *data);
	void	(*rrb)(struct s_ps_data *data);
	void	(*rrr)(struct s_ps_data *data);
	bool	(*push_a)(struct s_ps_data * data, int nb);
	void	(*reverse_a)(struct s_ps_data *data);
	bool	(*found_dup_a)(struct s_ps_data * data);
	void	(*clear)(struct s_ps_data **data);
	void	(*display)(struct s_ps_data *data);
	bool	(*is_sorted_stack)(struct s_ps_data * data, char stack_letter);
	bool	(*is_rev_sorted_stack)(struct s_ps_data * data, char stack_letter);
}	t_ps_data;

t_ps_data	*ps_data_init(void);
void		ps_data_set_functions(t_ps_data *data);
void		ps_data_clear(t_ps_data **data);
void		push_swap_display(t_ps_data *data);
void		display_int_stack(t_stack *stack);
bool		push_swap_push_a(t_ps_data *data, int nb);
void		push_swap_reverse_a(t_ps_data *data);
bool		push_swap_is_sorted_stack(t_ps_data *data, char stack_letter);
bool		push_swap_is_rev_sorted_stack(t_ps_data *data, char stack_letter);
bool		push_swap_found_duplicates_a(t_ps_data *data);
void		push_swap_sa(t_ps_data *data);
void		push_swap_sb(t_ps_data *data);
void		push_swap_ss(t_ps_data *data);
void		push_swap_pa(t_ps_data *data);
void		push_swap_pb(t_ps_data *data);
void		push_swap_ra(t_ps_data *data);
void		push_swap_rb(t_ps_data *data);
void		push_swap_rr(t_ps_data *data);
void		push_swap_rra(t_ps_data *data);
void		push_swap_rrb(t_ps_data *data);
void		push_swap_rrr(t_ps_data *data);

bool		parse_args(t_ps_data *data, int argc, char **argv);
bool		parse_one_arg(t_ps_data *data, char *str);

#endif
