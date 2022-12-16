#include "../cub.h"

char	*ft_strdup(char	*str)
{
	int i;
	char	*newline;

	i = ft_strlen_v2(str);
	newline = NULL;
	if (!i)
		return (NULL);
	newline = malloc(sizeof(char) * i + 1);
	if (!newline)
		return (NULL);
	newline[i] = '\0';
	i = 0;
	while (str[i])
	{
		newline[i] = str[i];
		i++;
	}
	return (newline);
}

char	*ft_join_free_ss(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*join;

	if (!s1)
	{
		s1 = ft_calloc(1, 1);
		if (!s1)
			return (NULL);
	}
	if (!s2)
		return (NULL);
	join = malloc(sizeof(char) * ((int)ft_strlen_v2(s1) + (int)ft_strlen_v2(s2) + 1));
	if (!join)
		return (NULL);
	i = -1;
	while (s1[++i])
		join[i] = s1[i];
	j = 0;
	while (s2[j])
		join[i++] = s2[j++];
	join[i] = '\0';
	free(s1);
	free(s2);
	return (join);
}

static int	get_len(int n)
{
	int	res;

	res = 0;
	if (!n)
		return (1);
	if (n < 0)
		res++;
	while (n)
	{
		n /= 10;
		res++;
	}
	return (res);
}

char	*ft_itoa(int n)
{
	char	*res;
	int		len_res;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	len_res = (get_len(n));
	res = malloc(sizeof(char) * len_res + 1);
	if (!res)
		return (NULL);
	if (n == 0 || (!n))
		res[0] = '0';
	if (n < 0)
	{
		res[0] = '-';
		n *= -1;
	}
	res[len_res] = '\0';
	while (n)
	{
		res[--len_res] = (n % 10) + 48;
		n /= 10;
	}
	return (res);
}

void	free_and_replace(t_pars	*data, int mod, int change)
{
	free(data->checker[mod]);
	data->checker[mod] = ft_strdup(ft_itoa(change));
}