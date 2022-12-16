#include "../cub.h"

char	*ft_read_file(int fd)
{
	int		byte_read;
	char	buf[100];
	char	*str;

	str = NULL;
	byte_read = 1;
	while (byte_read)
	{
		byte_read = read(fd, buf, 100);
		if (byte_read == -1)
		{
			write(2, "read error\n", 11);
			exit (-1);
		}
		buf[byte_read] = '\0';
		str = ft_strjoin_v2(str, buf);
		if (!str)
			return (NULL);
	}
	return (str);
}

char	**parse(char *filename)
{
	int		fd;
	char	*str;
	char	**map;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		write(2, "error in fd\n", 12);
		exit (-1);
	}
	str = ft_read_file(fd);
	close(fd);
	if (!str)
		return (NULL);
	map = ft_split(str, '\n');
	if (!map)
		return (NULL);
	free (str);
	return (map);
}

void	*ft_calloc( size_t	count, size_t	size)
{
	void	*ptr;
	size_t	i;

	i = 0;
	ptr = malloc(count * size);
	if (!(ptr))
		return (NULL);
	while (i < count * size)
		*(char *)(ptr + i++) = 0;
	return (ptr);
}

char	*ft_strjoin_v2(char	*s1, char	*s2)
{
	int		i;
	int		j;
	char	*str;

	i = -1;
	j = 0;
	if (!s1)
		s1 = ft_calloc(1, 1);
	if (!s1 || !s2)
		return (NULL);
	str = malloc(sizeof(char) * ft_strlen_v2(s1) + ft_strlen_v2(s2) + 1);
	if (!str)
		return (NULL);
	while (s1[++i])
		str[i] = s1[i];
	while (s2[j])
		str[i++] = s2[j++];
	str[i] = 0;
	free (s1);
	return (str);
}