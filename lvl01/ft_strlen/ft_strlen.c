int	ft_strlen(char *str)
{
    int ind;

    ind = 0;
    while (str[ind])
        ind++;
    return (ind);
}