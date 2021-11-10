#include "debug/debug_utils.h"

void	print_space(int depth)
{
	int	c;

	c = depth * 4;
	while (c--)
		printf(" ");
}

int	print_strings(char **arr, int depth)
{
	int	idx;

	if (!arr)
		return (OK);
	idx = -1;
	print_space(depth);
	printf("[\n");
	while (arr[++idx])
	{
		print_space(depth + 1);
		printf("%s\n", arr[idx]);
	}
	print_space(depth);
	printf("]\n");
	return (OK);
}

int	print_error_type(int errtype)
{
	if (errtype == ERR_PARSE_SYNTAX)
		printf("ERR_PARSE_SYNTAX\n");
	if (errtype == ERR_PARSE_MULTI_LINE)
		printf("ERR_PARSE_MULTI_LINE\n");
	return (OK);
}
