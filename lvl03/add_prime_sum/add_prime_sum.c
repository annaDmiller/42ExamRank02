#include <unistd.h>

int prime;

static int  ft_atoi(char *str);
static void print_sum(int num);
static int  is_prime(int num);
static void print_num(int num);

int main(int argc, char **argv)
{
    int num;

    if (argc != 2)
        return (write(1, "0\n", 2), 1);
    num = ft_atoi(*(argv + 1));
    if (num == -1)
        return (write(1, "0\n", 2), 1);
    if (num == 0)
        return (write(1, "0\n", 2), 0);
    if (num == 1)
        return (write(1, "0\n", 2), 0);
    prime = 2;
    print_sum(num);
    return (write(1, "\n", 1), 0);
}

static int  ft_atoi(char *str)
{
    int ind;
    int num;

    if (!(str[0] >= '0' && str[0] <= '9'))
        return (-1);
    num = 0;
    ind = 0;
    while (str[ind] >= '0' && str[ind] <= '9')
    {
        num *= 10;
        num += str[ind] - '0';
        ind++;
    }
    return (num);
}

static void print_sum(int num)
{
    int sum;

    sum = 0;
    while (prime <= num)
    {
        if (!is_prime(prime))
            sum += prime;
        prime++;
    }
    print_num(sum);
    return ;
}

static int  is_prime(int num)
{
    int check;

    if (num == 0 || num == 1)
        return (1);
    if (num == 2)
        return (0);
    check = 2;
    while (check * check <= num)
    {
        if (num % check == 0)
            return (1);
        check++;
    }
    return (0);
}

static void print_num(int num)
{
    int car;

    if (num > 9)
        print_num(num / 10);
    car = num % 10 + '0';
    write(1, &car, 1);
    return ;
}