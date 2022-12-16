#include "../cub.h"

void	init_checker(t_data	*parsing)
{
	int	i;

	i = 0;
	parsing->checker = malloc(sizeof(char *) * 6 + 1);
	parsing->checker[6] = NULL;
	while(i < 6)
	{
		parsing->checker[i] = ft_strdup("0");
		i++;
	}
}

/*mod is like this  | NO | 0
					| S0 | 1
					| WE | 2
					| EA | 3
					| C  | 4
					| F  | 5
*/

void	insert_text(t_data	*data, int mod, char	*str)
{
	if (mod == 0)
		data->NO = ft_strdup(str);
	if (mod == 1)
		data->SO = ft_strdup(str);
	if (mod == 2)
		data->WE = ft_strdup(str);
	if (mod == 3)
		data->EA = ft_strdup(str);
	if (mod == 4)
		data->C = ft_strdup(str);
	if (mod == 5)
		data->F = ft_strdup(str);
}

int	check_path(char	*str, t_data	*data, int mod)
{
	// here always return -1 what the fuck is going on with this access!!!
	ft_check_access(str);
	ft_check_dir(str);
	insert_text(data, mod, str);
	return (1);
}

int get_path(char	*str, int begin, t_data	*data, int mod)
{
	int i;
	int count;
	char	*line;

	i = 0;
	count = begin;
	line = NULL;
	if (str)
	{
		while (str[begin] && str[begin] != ' ')
		{
			i++;
			begin++;
		}
		line = malloc(sizeof(char) * i + 1);
		if (!line)
			print_and_exit("malloc error\n", -1);
		line[i] = '\0';
		i = 0;
		while (str[count])
			line[i++] = str[count++];
	}
	return (check_path(line, data, mod));
}

void get_texture(char	*str, t_data	*data, int mod)
{
	int i;
	int	j;

	i = 0;
	j = 0;
	if (str && str[i])
	{
		while (str[i] && ft_isspace(str[i]))
			i++;
		if (str[i])
		{
			if (get_path(str, i, data, mod) == 1)
				free_and_replace(data, mod, 1);
		}
		else
			print_and_exit("empty texture's path\n", -1);
	}
}

void check_NO(char	*av, t_data	*data, int index)
{
	int i;

	i = 0;

	if (av && av[index])
	{
		while (av[index] && ft_isspace(av[index]))
			index++;
		if (av[index] && av[index] == 'N')
		{
			index++;
			if (av[index] && av[index] == 'O' && av[index + 1])
			{
				if (av[index] && av[index] == 'O' && ft_isspace(av[index + 1]))
					get_texture(&av[++index], data, 0);
				else
					print_and_exit("please use space for path texture's\n", -1);
			}
			else
				print_and_exit("please use a valid path\n", -1);
		}
	}
}