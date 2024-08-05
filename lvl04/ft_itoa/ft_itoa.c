#include <stdlib.h>

static int  find_len_of_str(int num);

char	*ft_itoa(int nbr)
{
    int     len_str;
    char    *str;

    len_str = find_len_of_str(nbr);
    str = (char *) malloc((len_str + 1) * sizeof(char));
    if (!str)
        return (NULL);
    str[len_str] = '\0';
    if (nbr < 0)
    {
        str[0] = '-';
        nbr *= -1;
    }
    if (nbr == 0)
        str[len_str - 1] = nbr + '0';
    while (nbr > 0)
    {
        str[--len_str] = (nbr % 10) + '0';
        nbr /= 10;
    }
    return (str);
}

static int  find_len_of_str(int num)
{
    int len;

    len = 1;
    if (num < 0)
    {
        num *= -1;
        len++;
    }
    while (num > 9)
    {
        num /= 10;
        len++;
    }
    return (len);
}
