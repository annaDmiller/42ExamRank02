#include <unistd.h>

void	ft_putstr(char *str)
{
    int ind_str;

    ind_str = 0;
    while (str[ind_str])
    {
        write(1, &(str[ind_str]), 1);
        ind_str++;
    }
    return ;
}

/*int main(int argc, char ** argv)
{
    if (argc != 2)
        return (write(1, "\n", 1), 1);
    ft_putstr(*(argv + 1));
    return (write(1, "\n", 1), 0);
}*/