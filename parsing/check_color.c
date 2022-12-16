#include "../cub.h"

// RGB color function take 3 int between 0 > 255

/*int	*get_rgb(char	**tab)
{

}*/

void check_tab_content(char	**tab)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (tab)
	{
		while (tab[i])
		{
			j = 0;
			while (tab[i][j])
			{
				if (tab[i][j] && ft_isdigit(tab[i][j]))
					print_and_exit("need only positive number's on color's\n", -1);
				j++;
			}
			i++;
		}
	}
}

void check_tab(char	**tab, char	*str, t_data	*data, int mod)
{
	int a;
	int b;
	int c;

	check_tab_content(tab);
	a = ft_atoi(tab[0]);
	b = ft_atoi(tab[1]);
	c = ft_atoi(tab[2]);
	if ((a < 0 || a > 255) || (b < 0 || b > 255) || (c < 0 || c > 255))
		print_and_exit("only use int from 0 to 255 for color's\n", -1);
	if (mod == 1)
	{
		data->C = ft_strdup(str);
		//data->C = get_rgb(tab);
		free_and_replace(data, 4, 1);
	}
	else if (mod == 2)
	{
		//data->F = get_rgb(tab);
		data->F = ft_strdup(str);
		free_and_replace(data, 5, 1);
	}
}

void	check_C(char	*str, t_data	*data, int begin)
{
	char	**tab;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (str[begin] && str[begin] == 'C')
		begin++;
	while (str[begin] && ft_isspace(str[begin]))
		begin++;
	if (str[begin])
	{
		tab = ft_split(&str[begin], ',');
		if (!tab)
			print_and_exit("split error\n", -1);
		if (ft_strlen2tab(tab) < 4)
			check_tab(tab, str, data, 1);
	}
	else
		print_and_exit("color cannot be empty\n", -1);
}


void	check_F(char	*str, t_data	*data, int begin)
{
	char	**tab;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (str[begin] && str[begin] == 'F')
		begin++;
	while (str[begin] && ft_isspace(str[begin]))
		begin++;
	if (str[begin])
	{
		tab = ft_split(&str[begin], ',');
		if (!tab)
			print_and_exit("split error\n", -1);
		if (ft_strlen2tab(tab) < 4)
			check_tab(tab, str, data, 2);
	}
	else
		print_and_exit("color cannot be empty\n", -1);
}
