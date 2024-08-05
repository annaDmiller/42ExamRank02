char    *ft_strcpy(char *s1, char *s2)
{
    int ind;

    ind = 0;
    while (s2[ind])
    {
        s1[ind] = s2[ind];
        ind++;
    }
    s1[ind] = '\0';
    return (s1);
}