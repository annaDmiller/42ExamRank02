#include <stdio.h>
#include <stdlib.h>

int num;

static void print_mult_of_prime(int num_to_print);
static int check_is_num_prime(int num_to_div);

int main(int argc, char **argv)
{
    if (argc != 2)
        return (printf("\n"), 1);
    num = 2;
    print_mult_of_prime(atoi(*(argv + 1)));
    return (printf("\n"), 0);
}

static void print_mult_of_prime(int num_to_print)
{
    int check_num;

    if (num_to_print == 1 || num_to_print == 0)
    {
        printf("%i", num_to_print);
        return ;
    }
    check_num = check_is_num_prime(2);
    while (check_num)
    {
        num++;
        check_num = check_is_num_prime(2);
    }
    if (num_to_print % num)
    {
        num++;
        return (print_mult_of_prime(num_to_print));
    }
    printf("%i", num);
    num_to_print /= num;
    if (num_to_print > 1)
    {
        printf("*");
        print_mult_of_prime(num_to_print);
    }
    return ;
}

static int check_is_num_prime(int num_to_div)
{
    if (num == 2)
        return (0);
    if (!(num % num_to_div))
        return (1);
    if (num_to_div * num_to_div > num)
        return (0);
    return (check_is_num_prime(num_to_div + 1));
}