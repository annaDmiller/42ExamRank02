#include <stdlib.h>

static int  is_separator(char c);
static int  count_num_words(char *str);
static int  wordlen(char *str);
static void free_arr(char **arr);
static char *ft_strncpy(char *dest, char *src, int size);

char    **ft_split(char *str)
{
    int     ind_str;
    char    **ret_arr;
    int     num_words;
    int     ind_arr;
    int     len_word;


    ind_str = 0;
    while (!is_separator(str[ind_str]))
        ind_str++;
    num_words = count_num_words(&(str[ind_str]));
    ret_arr = (char **) malloc((num_words + 1) * sizeof(char *));
    if (!ret_arr)
        return (NULL);
    ind_arr = 0;
    while (ind_arr < num_words)
    {
        while (!is_separator(str[ind_str]))
            ind_str++;
        len_word = wordlen(&(str[ind_str]));
        ret_arr[ind_arr] = (char *) malloc((len_word + 1) * sizeof(char));
        if (!ret_arr[ind_arr])
            return (free_arr(ret_arr), NULL);
        ft_strncpy(ret_arr[ind_arr], &(str[ind_str]), len_word + 1);
        ind_str += len_word;
        ind_arr++;
    }
    ret_arr[ind_arr] = NULL;
    return (ret_arr);
}

static int  is_separator(char c)
{
    if (c == ' ' || c == '\v' || c == '\t' || c == '\n')
        return (0);
    return (1);
}

static int  count_num_words(char *str)
{
    int ind;
    int num_words;

    ind = 0;
    num_words = 0;
    while (str[ind])
    {
        if (is_separator(str[ind]) && (!is_separator(str[ind + 1])
            || !str[ind + 1]))
            num_words++;
        ind++;
    }
    return (num_words);
}

static int  wordlen(char *str)
{
    int ind;

    ind = 0;
    while (str[ind] && is_separator(str[ind]))
        ind++;
    return (ind);
}

static void free_arr(char **arr)
{
    int ind_str;

    ind_str = 0;
    while (arr[ind_str])
        free(arr[ind_str++]);
    free(arr);
}

static char *ft_strncpy(char *dest, char *src, int size)
{
    int ind;

    ind = 0;
    while (ind < size - 1 && src[ind])
    {
        dest[ind] = src[ind];
        ind++;
    }
    dest[ind] = '\0';
    return (dest);
}