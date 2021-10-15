#include "core/error.h"

int ft_error(int type, char *data)
{
	errno = type;
	if (type == ERR_PARSE_SYNTAX)
		ft_error_msg_syntax();
	if (type == ERR_PARSE_MULTI_LINE)
		ft_error_msg_multi_line();
	if (type == ERR_EXECUTE_NO_FILE)
		ft_error_msg_no_file(data);
	if (type == ERR_EXECTUE_NOT_COMMAND)
		ft_error_msg_not_command(data);
    return (ERROR);
}
