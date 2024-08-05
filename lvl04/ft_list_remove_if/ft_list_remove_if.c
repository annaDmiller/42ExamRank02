#include "ft_list.h"
#include <stdlib.h>

static void delete_el(t_list *el);

void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
    t_list  *temp;

    if (!begin_list || !(*begin_list) || !data_ref || !(*cmp))
        return ;
    temp = *begin_list;
    if (!cmp(data_ref, temp->data))
    {
        *begin_list = temp->next;
        delete_el(temp);
        ft_list_remove_if(begin_list, data_ref, cmp);
    }
    else
        ft_list_remove_if(&(temp->next), data_ref, cmp);
    return ;
}

static void delete_el(t_list *el)
{
    free(el->data);
    free(el);
}