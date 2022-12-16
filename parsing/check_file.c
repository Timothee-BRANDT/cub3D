#include "../cub.h"

int	ft_check_cub(char	*filename)
{
	char	*str;
	size_t	sizelen;
	int		i;

	sizelen = ft_strlen_v2(filename);
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
	if (!ft_strncmp_v2(str, ".cub", ft_strlen_v2(str)))
		return (0);
	return (1);
}

int ft_check_access(char	*filename)
{
	int	i;

	i = access(filename, R_OK);
	if (i == -1)
		print_and_exit("error : bad access\n", -1);
	return (i);
}

int	ft_check_dir(char	*filename)
{
	int i;
	
	i = open(filename, O_DIRECTORY);
	if (i != -1)
		print_and_exit("error: directory is not allowed\n", -1);
	return (i);
}
