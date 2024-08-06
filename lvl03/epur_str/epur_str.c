#include <unistd.h>

static void print_str_one_space(char *str);
static int  is_space_tab(char c);
static int  is_last_word(char *str);

int main(int argc, char **argv)
{
    if (argc != 2)
        return (write(1, "\n", 1), 1);
    print_str_one_space(*(argv + 1));
    return (write(1, "\n", 1), 0);
}

static void print_str_one_space(char *str)
{
    int ind;

    ind =  0;
    while (!is_space_tab(str[ind]))
        ind++;
    while (str[ind])
    {
        if (is_space_tab(str[ind]))
        {
            write(1, &(str[ind]), 1);
            if (!is_space_tab(str[ind + 1]) && is_last_word(&(str[ind + 1])))
                write(1, " ", 1);
        }
        ind++;
    }
    return ;
}

static int  is_space_tab(char c)
{
    if (c == ' ' || c == '\v' || c == '\t')
        return (0);
    return (1);
}

static int  is_last_word(char *str)
{
    int ind;

    ind = 0;
    while (str[ind])
    {
        if (is_space_tab(str[ind]))
            return (1);
        ind++;
    }
    return (0);
}