#include <unistd.h>

void    print_first_word(char *str);

int is_space_or_tabs(char let);

int main(int argc, char **argv)
{
    if (argc == 2)
        print_first_word(*(argv + 1));
    write(1, "\n", 1);
    return (0);
}

void    print_first_word(char *str)
{
    int ind_str;

    ind_str = 0;
    while (str[ind_str])
    {
        if (is_space_or_tabs(str[ind_str]))
            break ;
        ind_str++;
    }
    while (str[ind_str])
    {
        if (!is_space_or_tabs(str[ind_str]))
            break ;
        write(1, &(str[ind_str]), 1);
        ind_str++;
    }
    return ;
}

int is_space_or_tabs(char let)
{
    if (let == ' ' || let == '\v' || let == '\t')
        return (0);
    return (1);
}