#include <unistd.h>

static int	ipssi_isspace(int c)
{
	return (c == ' ' || (c >= 9 && c <= 13));
}

unsigned long	ipssi_parse_unsigned(char *s, int *ok)
{
	unsigned long	n;
	int		i;	

	*ok = 0;
	i = 0;
	while (ipssi_isspace((unsigned char)s[i]))
		i++;
	if (s[i] == '+' || s[i] == '-')
		return (0);
	if (s[i] < '0' || s[i] > '9')
		return (0);
	n = 0;
	while (s[i] >= '0' && s[i] <= '9')
	{
		n = n * 10 + (unsigned long)(s[i] - '0');
		i++;
	}
	while (ipssi_isspace((unsigned char)s[i]))
		i++;
	if (s[i] != '\0')
		return (0);
	*ok = 1;
	return (n);
}
