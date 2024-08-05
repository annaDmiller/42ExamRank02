#include "flood_fill.h"

char    car;

static void    fill_with_f(char **arr, t_point size, int x, int y);

void    flood_fill(char **tab, t_point size, t_point begin)
{
    car = *(*(tab + begin.y) + begin.x);
    fill_with_f(tab, size, begin.x, begin.y);
    return ;
}

static void    fill_with_f(char **arr, t_point size, int x, int y)
{
    if (x < 0 || x >= size.x || y < 0 || y >=size.y)
        return ;
    if (*(*(arr + y) + x) != car)
        return ;
    *(*(arr + y) + x) = 'F';
    fill_with_f(arr, size, x + 1, y);
    fill_with_f(arr, size, x - 1, y);
    fill_with_f(arr, size, x, y + 1);
    fill_with_f(arr, size, x, y - 1);
    return ;
}