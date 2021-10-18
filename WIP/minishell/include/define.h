#ifndef SH_DEFINE_H
# define SH_DEFINE_H

# ifndef DEBUG
#  define DEBUG          0
# endif

# define OK				1
# define ERROR			0

# define TRUE			1
# define FALSE			0

#define CHARSET "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ_"
#define CHARSET_WITH_DIGIT \
		"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ_0123456789"
#define CHARSET_WITH_Q \
		"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ_?"

int	g_exit_code;

void	(*sigint_old)();
void	(*sigquit_old)();

#endif

