#include <unistd.h>

unsigned long	ipssi_parse_unsigned(char *s, int *ok);
void		ipssi_write_number_words(unsigned long n);

static void	ipssi_puts(char *s)
{
	while (*s)
		write(1, s++, 1);
}

int	main(int ac, char **av)
{
	unsigned long	n;
	int		ok;

	if (ac != 2)
	{
		ipssi_puts("error\n");
		return (1);
	}
	n = ipssi_parse_unsigned(av[1], &ok);
	if (!ok)
	{
		ipssi_puts("error\n");
		return (1);
	}
	ipssi_write_number_words(n);
	write(1, "\n", 1);
	return (0);
}
