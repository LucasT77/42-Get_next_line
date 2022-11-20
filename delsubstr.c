char    *delsubstr(char *str, size_t indx1, size_t indx2)
{
    size_t  i;
    char    *result;

    if (indx1 > indx2)
    {
        i = indx1;
        indx1 = indx2;
        indx2 = i;
    }
    result = malloc(sizeof(char) * ((ft_strlen(str) + 1) - (indx2 - indx1 + 1)));
    i = 0;
    while (i < indx1)
    {
        result[i] = str[i];
        i++;
    }
    indx2++;
    while (str[indx2])
    {
        result[i] = str[indx2];
        i++;
        indx2++;
    }
    result[i] = '\0';
    return (result);
}