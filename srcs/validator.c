#include "push_swap.h"

int
	isover_intrange(char *s)
{
	uint64_t	num;
	int			is_minus;

	is_minus = 0;
	while (ft_isspace(*s))
		s++;
	if (*s == '-')
		is_minus = 1;
	if (*s == '+' || *s == '-')
		s++;
	num = 0;
	while (ft_isdigit(*s))
	{
		num = num * 10 + *s - '0';
		if (is_minus && (int64_t)__INT_MAX__ + 1 < num)
			return (-1);
		else if (!is_minus && (uint64_t)__INT_MAX__ < num)
			return (1);
		s++;
	}
	return (0);
}

int
	isnumeric(char *s)
{
	if (!s || *s == '\0')
		return (0);
	if (*s == '+' || *s == '-')
		s++;
	if (!ft_isdigit(*s))
		return (0);
	while (*s)
	{
		if (!ft_isdigit(*s++))
			return (0);
	}
	return (1);
}

bool
	ft_is_valid_args(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (!isnumeric(argv[i]) || isover_intrange(argv[i]))
			return (false);
		i++;
	}
	return (true);
}
