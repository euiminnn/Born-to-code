#ifndef SH_DEFINE_H
# define SH_DEFINE_H

# include <errno.h>

# ifndef DEBUG
#  define DEBUG          0
# endif

# define OK				1
# define ERROR			0

# define TRUE			1
# define FALSE			0

# define ERR_PARSE_SYNTAX	    201
# define ERR_PARSE_MULTI_LINE   203
# define ERR_EXE_NO_FILE        202

#endif

