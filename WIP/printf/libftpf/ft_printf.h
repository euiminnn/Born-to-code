/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echung <echung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 19:59:36 by echung            #+#    #+#             */
/*   Updated: 2021/03/19 02:51:50 by echung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIBFT_H

# define FT_LIBFT_H

# include <stdarg.h>
# include <stdio.h>
//# include <strings.h>
# include <unistd.h>

typedef struct		s_flag
{
	char			type;
	int				zero;
	int				minus;
	int				dot;
	int				width;
	int				precision;
	int				precision_zero;
}					t_flag;

typedef struct		s_content
{
	int				prefix;
	int				sign;
	int				zero;
	void			*value;
	int				front_margin;
	int				back_margin;
	int				intlen;
}					t_content;

int retlen;

int					ft_atoi(const char *str);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memset(void *b, int c, size_t len);

size_t				ft_strlen(const char *s);
char				*ft_strchr(const char *s, int c);

void				ft_putchar_fd(char c, int fd);
void				ft_putnbr_fd(int n, int fd);
void				ft_putnbr_fd_u(unsigned int n, int fd);
void				ft_putnbr_fd_p(unsigned int n, int fd);
void				ft_putnbr_fd_sx(unsigned int n, int fd);
void				ft_putnbr_fd_lx(unsigned int n, int fd);

int					intlen(unsigned int num, int base);
void				my_write(int fildes, const void *buf, size_t nbyte);
void				print_result(t_content *content, char type);
int					max(int a, int b);
void				set_content(t_flag *flag, t_content *content, void *value);
void				parse_specifier(va_list *ap, t_flag flag);
void				parse(const char **format, va_list *ap);

void	parse_flag_zero(const char **format, t_flag *flag);
void	parse_flag_minus(const char **format, t_flag *flag);
void	parse_flag_width(const char **format, t_flag *flag);
void	parse_flag_asterisk(const char **format, t_flag *flag, va_list *ap);
void	parse_flag_precision(const char **format, t_flag *flag, va_list *ap);

void parse_spec_c(va_list *ap, t_flag *flag, t_content *content);
void parse_spec_s(va_list *ap, t_flag *flag, t_content *content);
void parse_spec_p(va_list *ap, t_flag *flag, t_content *content);
void parse_spec_d(va_list *ap, t_flag *flag, t_content *content);
void parse_spec_u(va_list *ap, t_flag *flag, t_content *content);

int					ft_printf(const char *format, ...);

#endif
