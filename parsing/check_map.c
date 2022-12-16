#include "../cub.h"

int check_token(char	c)
{
	if (c)
	{
		if (c == 'N')
			return (0);
		else if (c == 'S')
			return (1);
		else if (c == 'W')
			return (2);
		else if (c == 'E')
			return (3);
		else if (c == 'C')
			return (4);
		else if (c == 'F')
			return (5);	
		else
			return(-1);
	}
	else
		return (42);
}

void ft_texture(int	mod, char	*path, int begin, t_pars	*data)
{
	if (mod == 0)
		check_NO(path, data, begin);
	if (mod == 1)
		check_SO(path, data, begin);
	if (mod == 2)
		check_WE(path, data, begin);
	if (mod == 3)
		check_EA(path, data, begin);
	if (mod == 4)
		check_C(path, data, begin);
	if (mod == 5)
		check_F(path, data, begin);
}

int	ft_check_texture(char	*str, t_data	*data)
{
	int i;
	int res;

	i = 0;
	res = 0;
	if (str)
	{
		while (str[i] && ft_isspace(str[i]))
			i++;
		if (str[i])
		{
			res = check_token(str[i]);
			if (res == -1)
				print_and_exit("error: bad texture path -> begin with NO || SO || WE || EA || C || F\n", -1);
			else
				ft_texture(res, str, i, data);
		}
		else
			print_and_exit("empty path for texture\n", -1);
	}
	return (0);
}
