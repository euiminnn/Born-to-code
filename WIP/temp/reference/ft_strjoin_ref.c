#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	l1;
	size_t	l2;
	if (!(s1))
		return (0);
	if (!(s2))
		return (0);
	l1 = ft_strlen(s1);
	l2 = ft_strlen(s2);
	str = malloc(l1 + l2 + 1);
	if (!(str))
		return (0);
	ft_memcpy(str, s1, l1);
	ft_memcpy(str + l1, s2, l2);
	str[l1 + l2] = '\0';
	return (str);
}
