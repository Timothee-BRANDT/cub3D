#include "../cub.h"

int	ft_check_cub(char	*filename)
{
	char	*str;
	size_t	sizelen;
	int		i;

	sizelen = ft_strlen(filename);
	i = 0;
	while (filename[i] && filename[i] != '.')
	{
		i++;
		sizelen--;
	}
	if (filename[i] && sizelen == 4)
		str = filename + i;
	else
		return (1);
	if (!ft_strncmp(str, ".cub", ft_strlen(str)))
		return (0);
	return (1);
}

int ft_check_access(char	*filename)
{
	int	i;

	i = access(filename, R_OK);
	if (i == -1)
	{
		write(2, "access error\n", 13);
		exit(-1);
	}
	return (i);
}

int	ft_check_dir(char	*filename)
{
	int i;
	
	i = open(filename, O_DIRECTORY);
	if (i != -1)
	{
		write(2, "directory is not allowed\n", 25);
		exit(-1);	
	}
	return (i);
}
