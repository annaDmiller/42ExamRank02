#include <unistd.h>

static void print_string(char *str);
static int  is_alpha(char c);
static int  is_upper(char c);
static void rev_case(char *c);

int main(int argc, char **argv)
{
    if (argc != 2)
        return (write(1, "\n", 1), 1);
    print_string(*(argv + 1));
    return (write(1, "\n", 1), 0);
}

static void print_string(char *str)
{
    int     ind;
    char    car;

    ind = 0;
    while (str[ind])
    {
        car =  str[ind];
        if (!is_alpha(car))
            rev_case(&car);
        write(1, &car, 1);
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

static int  is_upper(char c)
{
    if (c >= 'A' && c <= 'Z')
        return (0);
    return (1);
}

static void rev_case(char *c)
{
    if (!is_upper(*c))
        *c += ('a' - 'A');
    else
        *c -= ('a' - 'A');
    return ;
}