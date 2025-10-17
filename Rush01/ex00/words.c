#include <unistd.h>

void			ipssi_write_word(const char *s, int *first);
void			ipssi_write_number_words(unsigned long n);

static void	ipssi_write_0_19(unsigned long n, int *first)
{
	static const char	*tab[] = {
		"zero", "one", "two", "three", "four",
		"five", "six", "seven", "eight", "nine",
		"ten", "eleven", "twelve", "thirteen", "fourteen",
		"fifteen", "sixteen", "seventeen", "eighteen", "nineteen"
	};

	ipssi_write_word(tab[n], first);
}

static void	ipssi_write_tens(unsigned long n, int *first)
{
	static const char	*ten[] = {
		"", "", "twenty", "thirty", "forty",
		"fifty", "sixty", "seventy", "eighty", "ninety"
	};

	if (n < 20)
	{
		ipssi_write_0_19(n, first);
		return ;
	}
	ipssi_write_word(ten[n / 10], first);
	if (n % 10)
		ipssi_write_0_19(n % 10, first);
}

static void	ipssi_write_0_999(unsigned long n, int *first)
{
	if (n >= 100)
	{
		ipssi_write_0_19(n / 100, first);
		ipssi_write_word("hundred", first);
		if (n % 100)
			ipssi_write_tens(n % 100, first);
	}
	else
		ipssi_write_tens(n, first);
}

static void	ipssi_write_scale(unsigned long *n, unsigned long scale,
				const char *word, int *first)
{
	unsigned long	part;

	if (*n >= scale)
	{
		part = *n / scale;
		ipssi_write_0_999(part, first);
		ipssi_write_word(word, first);
		*n %= scale;
	}
}

void	ipssi_write_number_words(unsigned long n)
{
	int		first;

	first = 1;
	if (n == 0)
	{
		ipssi_write_0_19(0, &first);
		return ;
	}
	ipssi_write_scale(&n, 1000000000UL, "billion", &first);
	ipssi_write_scale(&n, 1000000UL, "million", &first);
	ipssi_write_scale(&n, 1000UL, "thousand", &first);
	if (n)
		ipssi_write_0_999(n, &first);
}
