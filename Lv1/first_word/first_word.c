#include <unistd.h>

int	main(int ac, char **av)
{
	char *str = av[1];
	int i = 0;

	if (ac == 2)
	{
		while (str[i] == ' ' || str[i] == '\t')
			i++;
		while (str[i] != '\0' && (str[i] != ' ' && str[i] != '\t'))
		{
			write(1, &str[i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
