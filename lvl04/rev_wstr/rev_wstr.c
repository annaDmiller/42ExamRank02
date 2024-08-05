#include <unistd.h>
#include <stdlib.h>

static void print_wstr_rev(char *str);
static int  find_num_words(char *str);
static char *find_word_of_num(char *str, int num_of_word);

int main(int argc, char **argv)
{
    if (argc != 2)
        return (write(1, "\n", 1), 1);
    print_wstr_rev(*(argv + 1));
    return (write(1, "\n", 1), 0);
}

static void print_wstr_rev(char *str)
{
    int     ind;
    int     num_words;
    char    *addr_word;

    ind = 0;
    num_words = find_num_words(str);
    while (num_words)
    {
        addr_word = find_word_of_num(str, num_words);
        while (*addr_word && *addr_word != ' ')
        {
            write(1, addr_word, 1);
            addr_word++;
        }
        num_words--;
        if (num_words)
            write(1, " ", 1);
    }
    return ;
}

static int  find_num_words(char *str)
{
    int ind;
    int num_words;

    ind = 0;
    num_words = 1;
    while (str[ind])
    {
        if (str[ind] == ' ')
            num_words++;
        ind++;
    }
    return (num_words);
}

static char *find_word_of_num(char *str, int num_of_word)
{
    int num_of_space;
    int ind;

    num_of_space = 0;
    ind = 0;
    while (num_of_space < num_of_word -  1 && str[ind])
    {
        if (str[ind] == ' ')
            num_of_space++;
        ind++;
    }
    return (&(str[ind]));
}