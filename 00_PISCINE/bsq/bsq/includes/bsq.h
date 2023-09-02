/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 21:45:17 by mhotting          #+#    #+#             */
/*   Updated: 2023/08/30 20:14:43 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

# define BUFFER_SIZE 10000

typedef struct s_matrix
{
	int	**matrix;
	int	x;
	int	y;
	int	size;
	int	line_cnt;
	int	col_cnt;
}	t_matrix;

typedef struct s_map
{
	char	**map;
	char	obs;
	char	free;
	char	square;
	int		line_cnt;
	int		col_cnt;
	char	error;
}	t_map;

void	ft_putchar(char c);
void	ft_putstr(char *str);
void	ft_putstr_len(char *str, int len);
int		ft_strlen(char *str);
int		ft_atoi(char *str);
char	*ft_strcat(char *dest, char *src);
int		is_valid_char(char *charset);

int		check_characters(char *charset);
int		check_lines(char *charset, char *string_file, int lines);
char	*get_charset(char *str);
char	*get_file_data(char *name);
int		get_line_cnt(char *str);
t_map	*get_map_struct(int argc, char **argv);
int		is_in_charset(char c, char *charset);
int		fill_map(t_map *s_map, char *str);
void	fill_struct(t_map *s_map, char *str);
char	*get_charset(char *str);
void	write_map(t_map s_map);
char	*rmv_nl(char *str);
int		read_from_stdin(t_map *map);
int		check_line_nbr(int lines, int cols, char *str);

int		generate_matrix(t_map *map, t_matrix *matrix);
void	solve(t_matrix *matrix);
void	apply_solution_to_map(t_map *map, t_matrix *matrix);

void	display_map(t_map *map);
void	display_all_maps(t_map *maps);
int		init_map_array(t_map **maps, int array_size);

void	free_maps(t_map *maps);
void	clean_str_array(char **strs, int line);
void	clean_int_array(int	**array, int line_cnt);

#endif
