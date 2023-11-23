# Compiles ft_printf library and our main in order to use it
make -sC ../
cc -Wall -Werror -Wextra main.c -I../includes -I../libft -L../ -lftprintf -o test
