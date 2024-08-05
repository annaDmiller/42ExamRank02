#include <unistd.h>

static  int ft_strlen(char *str);
static void replace_and_print_string(char *str, char car_search, char car_repl);

int main(int argc, char **argv)
{
    if (argc != 4)
        return (write(1, "\n", 1), 1);
    if (ft_strlen(*(argv + 2)) != 1 || ft_strlen(*(argv + 3)) != 1)
        return (write(1, "\n", 1), 1);
    replace_and_print_string(*(argv + 1), **(argv + 2), **(argv + 3));
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

static void replace_and_print_string(char *str, char car_search, char car_repl)
{
    int ind;

    ind = 0;
    while (str[ind])
    {
        if (str[ind] == car_search)
            write(1, &car_repl, 1);
        else
            write(1, &(str[ind]), 1);
        ind++;
    }
    return ;
}