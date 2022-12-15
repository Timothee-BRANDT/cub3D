#include "../cub.h"

int	ft_strncmp(char	*s1, char	*s2, size_t	n)
{
	size_t			i;
	unsigned char	str1;
	unsigned char	str2;

	i = 0;
	while (i < n && (s1[i] || s2[i]))
	{
		str1 = (unsigned char)s1[i];
		str2 = (unsigned char)s2[i];
		if (str1 != str2)
			return (1);
		i++;
	}
	return (0);
}

size_t	ft_strlen(char	*str)
{
	int	i;

	i = 0;
	while (str && str[i])
		i++;
	return (i);
}

void	ft_print_split(char	**map)
{
	size_t	i;

	i = 0;
	if (map)
	{
		while (map[i])
		{
			printf("%s\n", map[i]);
			i++;
		}
	}
	else
		printf("Map is empty.\n");
}
