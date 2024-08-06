const char    *BASE = "0123456789abcdef";

static int  is_valid_car(char c);
static int  is_upper(char c);
static int  digit_of_base(char car, int ind_base);

int	ft_atoi_base(const char *str, int str_base)
{
    int     sign;
    int     ind;
    int     num;
    int     digit;
    char    car;

    if (str_base > 16)
        return (0);
    sign = 1;
    ind = 0;
    num = 0;
    if (str[ind] == '-')
        sign *= -1;
    while (!is_valid_car(str[ind]))
    {
        if (!is_upper(str[ind]))
            car = str[ind] + 'a' - 'A';
        else
            car = str[ind];
        digit = digit_of_base(car, str_base);
        if (digit == -1)
            break ;
        num *= str_base;
        num += digit;
        ind++;
    }
    return (num);
}

static int  is_valid_car(char c)
{
    if ((c >= '0' && c <= '9') || (c >= 'a' && c <= 'f') || (c >= 'A' && c <= 'F'))
        return (0);
    return (1);
}

static int  is_upper(char c)
{
    if (c >= 'A' && c <= 'F')
        return (0);
    return (1);
}

static int  digit_of_base(char car, int ind_base)
{
    int ind;

    ind = 0;
    while (ind < ind_base)
    {
        if (car == BASE[ind])
            return (ind);
        ind++;
    }
    return (-1);
}