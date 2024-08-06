#include "ft_list.h"

t_list	*sort_list(t_list* lst, int (*cmp)(int, int))
{
    t_list  *temp;
    t_list  *temp_an;
    int     tmp_int;

    temp = lst;
    while (temp->next)
    {
        temp_an = lst;
        while (temp_an->next)
        {
            if (!cmp(temp_an->data, temp_an->next->data))
            {
                tmp_int = temp_an->data;
                temp_an->data = temp_an->next->data;
                temp_an->next->data = tmp_int;
            }
            temp_an = temp_an->next;
        }
        temp = temp->next;
    }
    return (lst);
}