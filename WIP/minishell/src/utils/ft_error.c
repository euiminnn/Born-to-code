#include "utils/utils.h"

int ft_error(int errtype)
{
    errno = errtype;
    return (ERROR);
}