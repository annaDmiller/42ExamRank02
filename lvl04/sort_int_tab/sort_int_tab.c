static void ft_swap(int *a, int *b);

void sort_int_tab(int *tab, unsigned int size)
{
    int count;
    int ind_cur;

    count = size;
    while (count > 0)
    {
        ind_cur = 0;
        while (ind_cur < count - 1)
        {
            if (tab[ind_cur] > tab[ind_cur + 1])
                ft_swap(&(tab[ind_cur]), &(tab[ind_cur + 1]));
            ind_cur++;
        }
        count--;
    }    
    return ;
}

static void ft_swap(int *a, int *b)
{
    int temp;

    temp = *a;
    *a = *b;
    *b = temp;
    return ;
}