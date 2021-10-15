#include "core/execute/proc.h"
#include "utils/utils.h"
#include <unistd.h>

# define STRING_MAX 420000

int get_proc_type(t_proc *proc)
{
	char	**builtin_name;
	int		*builtin_type;
	int		i;

	builtin_name = (char *[7]) {
		"cd",
		"echo",
		"env",
		"exit",
		"export",
		"pwd",
		"unset"
	};
	builtin_type = (int [7]) {
		P_BUILTIN_CD,
		P_BUILTIN_ECHO,
		P_BUILTIN_ENV,
		P_BUILTIN_EXIT,
		P_BUILTIN_EXPORT,
		P_BUILTIN_PWD,
		P_BUILTIN_UNSET
	};
	i = -1;
	while (++i < BUILTIN_NUM)
		if (ft_strncmp(proc->argv[0], builtin_name[i], STRING_MAX) == 0)
			return (builtin_type[i]);
	return (P_EXTERN);
}

void    free_proc(t_proc *proc)
{
	ft_free_strings(proc->argv);
	free(proc);
}
