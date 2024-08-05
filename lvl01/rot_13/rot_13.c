#include <unistd.h>

static void print_string(char *str);
static  int is_alpha(char c);
static void rotate_13(char *car);

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
        car = str[ind];
        if (!is_alpha(car))
            rotate_13(&car);
        write(1, &car, 1);
        ind++;
    }
    return ;
}

static  int is_alpha(char c)
{
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
        return (0);
    return (1);
}

static void rotate_13(char *car)
{
    *car += 13;
    if (is_alpha(*car))
        *car -= ('z' - 'a' + 1);
    return ;
}