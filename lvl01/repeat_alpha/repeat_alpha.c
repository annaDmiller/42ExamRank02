#include <unistd.h>

static void    print_string(char *str);
static int  is_alpha(char c);
static int  is_uppercase(char c);
static void print_letter(char c);

int main(int argc, char **argv)
{
    if (argc != 2)
        return (write(1, "\n", 1), 1);
    print_string(*(argv + 1));
    return (write(1, "\n", 1), 0);
}

static void    print_string(char *str)
{
    int ind;

    ind = 0;
    while (str[ind])
    {
        if (!is_alpha(str[ind]))
            print_letter(str[ind]);
        else
            write(1, &(str[ind]), 1);
        ind++;
    }
    return ;
}

static int  is_alpha(char c)
{
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
        return (0);
    return (1);
}

static int  is_uppercase(char c)
{
    if (c >= 'A' && c <= 'Z')
        return (0);
    return (1);
}

static void print_letter(char c)
{
    int repeat;

    repeat = 0;
    if (!is_uppercase(c))
        repeat = c - 'A' + 1;
    else
        repeat = c - 'a' + 1;
    while (repeat)
    {
        write(1, &c, 1);
        repeat--;
    }
    return ;
}