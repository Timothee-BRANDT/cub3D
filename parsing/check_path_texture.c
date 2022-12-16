#include "../cub.h"

void check_SO(char	*av, t_pars	*data, int index)
{
	int i;

	i = 0;

	if (av && av[index])
	{
		while (av[index] && ft_isspace(av[index]))
			index++;
		if (av[index] && av[index] == 'S')
		{
			index++;
			if (av[index] && av[index] == 'O' && av[index + 1])
			{
				if (av[index] && av[index] == 'O' && ft_isspace(av[index + 1]))
					get_texture(&av[++index], data, 1);
				else
					print_and_exit("please use space for path texture's\n", -1);
			}
			else
				print_and_exit("please use a valid path\n", -1);
		}
	}
}

void check_WE(char	*av, t_pars	*data, int index)
{
	int i;

	i = 0;

	if (av && av[index])
	{
		while (av[index] && ft_isspace(av[index]))
			index++;
		if (av[index] && av[index] == 'W')
		{
			index++;
			if (av[index] && av[index] == 'E' && av[index + 1])
			{
				if (av[index] && av[index] == 'E' && ft_isspace(av[index + 1]))
					get_texture(&av[++index], data, 2);
				else
					print_and_exit("please use space for path texture's\n", -1);
			}
			else
				print_and_exit("please use a valid path\n", -1);
		}
	}
}

void check_EA(char	*av, t_data	*data, int index)
{
	int i;

	i = 0;

	if (av && av[index])
	{
		while (av[index] && ft_isspace(av[index]))
			index++;
		if (av[index] && av[index] == 'E')
		{
			index++;
			if (av[index] && av[index] == 'A' && av[index + 1])
			{
				if (av[index] && av[index] == 'A' && ft_isspace(av[index + 1]))
					get_texture(&av[++index], data, 3);
				else
					print_and_exit("please use space for path texture's\n", -1);
			}
			else
				print_and_exit("please use a valid path\n", -1);
		}
	}
}