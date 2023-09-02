/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 10:06:06 by mhotting          #+#    #+#             */
/*   Updated: 2023/08/27 22:32:09 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H
# define BUFFER_SIZE 1024

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct s_list
{
	struct s_list	*next;
	char			*word;
}		t_list;

typedef struct s_translation
{
	char	*number;
	char	*translation;
	int		number_len;
}	t_translation;

void	ft_free_tab(char **tab);
void	ft_putchar(char c);
void	ft_putstr(char *str);
int		ft_strlen(char *str);
int		ft_strcmp(char *s1, char *s2);
char	*ft_strcat(char *dest, char *src);
char	**ft_split(char *str, char *charset);
char	*ft_strdup(char *str);
int		ft_isspace(char c);
char	*ft_strtrim(char *str);
char	*ft_atoa(char *str);
void	ft_putstr_error(char *str);
void	ft_putchar_error(char c);
int		ft_str_array_len(char **array);
char	*ft_itoa_pos(int nb);
int		ft_atoi_n(char *str, unsigned int n);
int		get_number_cleaned(char **number, t_translation *dict);
char	*ft_strjoin(char **strs);

t_list	*ft_create_elem(char *str);
int		ft_push_front(t_list **head, char *str);
int		ft_push_back(t_list **head, char *str);
void	free_link_list(t_list *head);
void	ft_print_list(t_list *head);

int		parse_file(char *file_name, t_translation **dict);
int		file_to_dict(char *file_content, t_translation **dict);
int		is_valid_key(char *key);
int		dict_contains_duplicates(t_translation *dict);
void	clean_memory_dict(t_translation *dict);
void	dict_swap_elems(t_translation *elem1, t_translation *elem2);
void	dict_sort(t_translation *dict);
int		ft_check_dict(t_translation **dict);
char	*clean_value(char *value);
int		clean_key(char **key);

int		translate(char *number, t_translation *dict, t_list **tr_result);
char	*find_in_dict(int nb, t_translation *dict);
int		get_number_translation(int nb, t_translation *dict, t_list **tr_result);

#endif
