#include <unistd.h>

void	ipssi_write_word(const char *s, int *first)
{
	if (!*first)
		write(1, " ", 1);
	else
		*first = 0;
	while (*s)
		write(1, s++, 1);
}
