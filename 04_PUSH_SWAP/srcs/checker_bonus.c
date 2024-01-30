/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 19:28:48 by mhotting          #+#    #+#             */
/*   Updated: 2024/01/30 14:40:25 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static void	handle_error(t_ps_data *data)
{
	data->clear(&data);
	ft_dprintf(STDERR_FILENO, ERROR_MESSAGE);
	exit(EXIT_FAILURE);
}

static void	apply_instruction(t_ps_data *data, char *instruction)
{
	if (ft_strcmp(instruction, SA_INSTRUCTION) == 0)
		data->sa(data, false);
	else if (ft_strcmp(instruction, SB_INSTRUCTION) == 0)
		data->sb(data, false);
	else if (ft_strcmp(instruction, SS_INSTRUCTION) == 0)
		data->ss(data, false);
	else if (ft_strcmp(instruction, PA_INSTRUCTION) == 0)
		data->pa(data, false);
	else if (ft_strcmp(instruction, PB_INSTRUCTION) == 0)
		data->pb(data, false);
	else if (ft_strcmp(instruction, RA_INSTRUCTION) == 0)
		data->ra(data, false);
	else if (ft_strcmp(instruction, RB_INSTRUCTION) == 0)
		data->rb(data, false);
	else if (ft_strcmp(instruction, RR_INSTRUCTION) == 0)
		data->rr(data, false);
	else if (ft_strcmp(instruction, RRA_INSTRUCTION) == 0)
		data->rra(data, false);
	else if (ft_strcmp(instruction, RRB_INSTRUCTION) == 0)
		data->rrb(data, false);
	else if (ft_strcmp(instruction, RRR_INSTRUCTION) == 0)
		data->rrr(data, false);
	else
		return (free(instruction), handle_error(data));
}

static void	get_all_inputs_from_stdin(t_ps_data *data)
{
	char	*instruction;

	while (true)
	{
		instruction = get_next_line(STDIN_FILENO);
		if (instruction == NULL)
			break ;
		apply_instruction(data, instruction);
		free(instruction);
	}
}

static void	process_checker(t_ps_data *data)
{
	if (data == NULL)
		return ;
	if (!(data->is_sorted_stack(data, 'a')))
		get_all_inputs_from_stdin(data);
	if (data->is_sorted_stack(data, 'a') && (data->stack_b)->size == 0)
		ft_printf(OK_MESSAGE);
	else
		ft_printf(KO_MESSAGE);
}

int	main(int argc, char **argv)
{
	t_ps_data	*data;
	bool		returned;

	if (argc == 1)
		return (0);
	data = ps_data_init();
	if (data == NULL)
		return (0);
	if (argc == 2)
		returned = parse_one_arg(data, argv[1]);
	else
		returned = parse_args(data, argc - 1, argv + 1);
	if (!returned || data->found_dup_a(data))
	{
		data->clear(&data);
		ft_dprintf(STDERR_FILENO, ERROR_MESSAGE);
		return (1);
	}
	process_checker(data);
	data->clear(&data);
	return (0);
}
