#include <unistd.h>

static int is_print_fizzbuss(int num);
static int is_div_by_3(int num);
static int is_div_by_5(int num);
static void    print_num(int num);

int main(void)
{
    int num;

    num = 1;
    while (num <= 100)
    {
        if (is_print_fizzbuss(num))
            print_num(num);        
        write(1, "\n", 1);
        num++;
    }
    return (0);
}

static int is_print_fizzbuss(int num)
{
    if (is_div_by_3(num) && is_div_by_5(num))
        return (1);
    if (!is_div_by_3(num) && !is_div_by_5(num))
        return (write(1, "fizzbuzz", 8), 0);
    if (!is_div_by_3(num))
        return (write(1, "fizz", 4), 0);
    if (!is_div_by_5(num))
        return (write(1, "buzz", 4), 0);
    return (1);    
}

static int is_div_by_3(int num)
{
    if (num % 3 == 0)
        return (0);
    return (1);
}

static int is_div_by_5(int num)
{
    if (num % 5 == 0)
        return (0);
    return (1);
}

static void    print_num(int num)
{
    char    c;

    if (num >= 10)
        print_num(num / 10);
    c = num % 10 + '0';
    write(1, &c, 1);
    return ;    
}