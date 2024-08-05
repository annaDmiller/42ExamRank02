#include <stdlib.h>
#include <unistd.h>

static int  is_space_tab(char c);
static void print_string_rot(char *str);
static int  wordlen(char *str);
static char *ft_strncpy(char *dest, char *src, int size);

int main(int argc, char **argv)
{
    if (argc < 2)
          return (write(1, "\n", 1), 1);
    print_string_rot(*(argv + 1));
    return (write(1, "\n", 1), 0);
}

static int  is_space_tab(char c)
{
    if (c == ' ' || c == '\v' || c == '\t')
        return (0);
    return (1);
}

static void print_string_rot(char *str)
{
    int     ind;
    char    *temp;
    int     len_first_word;

    ind = 0;
    while (!is_space_tab(str[ind]))
        ind++;
    len_first_word = wordlen(&(str[ind]));
    temp = (char *) malloc((len_first_word + 1) * sizeof(char));
    if (!temp)
        return ;
    temp = ft_strncpy(temp, &(str[ind]), len_first_word + 1);
    ind += len_first_word;
    while (str[ind])
    {
        if (is_space_tab(str[ind]))
        {
            write(1, &(str[ind]), 1);
            if (!str[ind + 1] || !is_space_tab(str[ind + 1]))
                write(1, " ", 1);
        }
        ind++;
    }
    write(1, temp, len_first_word);
    free(temp);
    return ;
}

static int  wordlen(char *str)
{
    int ind;
    int len;

    ind = 0;
    len = 0;
    while (str[ind] && is_space_tab(str[ind]))
    {
        len++;
        ind++;
    }
    return (len);
}

static char *ft_strncpy(char *dest, char *src, int size)
{
    int ind;

    ind = 0;
    while (ind < size - 1)
    {
        dest[ind] = src[ind];
        ind++;
    }
    dest[ind] = '\0';
    return (dest);
}