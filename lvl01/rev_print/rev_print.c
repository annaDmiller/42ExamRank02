#include <unistd.h>

static  int ft_strlen(char *str);

int main(int argc, char **argv)
{
    int len_str;

    if (argc != 2)
        return (write(1, "\n", 1), 1);
    len_str = ft_strlen(*(argv + 1));
    while (len_str--)
        write(1, &(*(*(argv + 1) + len_str)), 1);
    return (write(1, "\n", 1), 0);
}

static  int ft_strlen(char *str)
{
    int ind;

    ind = 0;
    while (str[ind])
        ind++;
    return (ind);
}