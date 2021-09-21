#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_print_format
{
	int		is_formating;
	int		is_negative;
	int		width;
	int		onleft;
	int		precision;
	int		zero_flag;
	int		size_precision;
	int		size_fill;
	int		total_chars;
	char	fill;
	char	*parameters;
	char	*flags;
}			t_format;

int		ft_printf(const char *str, ...);
int		ft_check_string(const char *str, va_list args);
int		ft_get_format(const char *str, int i, t_format *vars, va_list arg);
int		ft_get_flags(const char *str, int i, t_format *t_vars, va_list args);
void	ft_check_parameters(char c, t_format *t_vars, va_list args);
int		ft_flag_number(const char *str, int i, t_format *t_vars);
int		ft_flag_minus(const char *str, int i, t_format *t_vars);
int		ft_flag_dot(const char *str, int i, t_format *t_vars);
int		ft_flag_star(int i, t_format *t_vars, va_list args);
void	ft_set_width(const char *number_str, t_format *t_vars);
void	ft_set_precision(const char *number_str, t_format *t_vars);
int		ft_get_number(const char *str, int i, t_format *t_vars);
int		ft_check_star_value(t_format *t_vars, va_list args);
int		ft_is_repeat(const char *str, int i, t_format *t_vars);
void	ft_get_char(char c, t_format *t_vars, va_list args);
void	ft_get_hex(char c, t_format *t_vars, va_list args);
size_t	ft_hex_size(unsigned long int i_arg);
void	ft_hex_print_checks(const char *hex, int hex_len, t_format *t_vars);
void	ft_print_hex(const char *hex, int hex_len);
void	ft_get_integer(t_format *t_vars, va_list args);
void	ft_int_print_checks(const char *number, int nb_len, t_format *t_vars);
void	ft_print_int(const char *number, int nb_len, t_format *t_vars);
int		ft_nb_len(int number);
void	ft_get_pointer(t_format *t_vars, va_list args);
size_t	ft_pointer_size(unsigned long int i_arg);
void	ft_pointer_print_checks(const char *hex, int hex_len, t_format *t_vars);
void	ft_print_prefix(t_format *t_vars);
void	ft_pointer_fill_size(int hex_len, t_format *t_vars);
void	ft_get_string(t_format *t_vars, va_list args);
int		ft_strlen_get(char *str_arg, t_format *t_vars);
void	ft_str_print_checks(char *str_arg, int str_len, t_format *t_vars);
void	ft_print_str(const char *str_arg, int str_len);
void	ft_get_uint(t_format *t_vars, va_list args);
int		ft_unb_len(unsigned int number);
int		ft_check_hex_zero(char **hex, int hex_len);
void	ft_check_prec_and_width(int hex_len, t_format *t_vars);
int		ft_hex_is_zero(int hex_len, t_format *t_vars);
void	ft_hex_on_right(const char *hex, int hex_len, t_format *t_vars);
void	ft_hex_on_left(const char *hex, int hex_len, t_format *t_vars);
void	ft_int_print_checks(const char *number, int nb_len, t_format *t_vars);
void	ft_int_left_and_prec(const char *number, int nb_len, t_format *t_vars);
void	ft_int_left_no_prec(const char *number, int nb_len, t_format *t_vars);
void	ft_int_right_and_prec(const char *number, int nb_len, t_format *t_vars);
void	ft_int_right_no_prec(const char *number, int nb_len, t_format *t_vars);
char	*ft_itohex(char c, unsigned long int i_arg, int hex_len);
char	*ft_utoa(unsigned int n, int n_size);
int		ft_atoi(const char *str);
char	*ft_itoa(int n, int n_size);
void	ft_size_fill(int size, int flag_size, t_format *t_vars);
void	ft_print_fill(int size_fill, char fill);
void	ft_zero_struct(t_format *t_vars);
void	ft_reset_struct(t_format *t_vars);
int		ft_isdigit(int c);
size_t	ft_strlcpy(char *dest, const char *src, size_t len);
char	*ft_strdup(const char *str);
void	ft_putchar(char c);
int		ft_strlen(const char *s);
void	*ft_memcpy(void *dest, const void *src, size_t len);
char	*ft_strchr(const char *src, int c);
int		ft_strncmp(const char *str1, const char *str2, size_t len);

#endif
