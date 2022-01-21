
/*
Напишите программу, которая берет две строки и отображает без двойников символы, которые появляются в любой из строк.
Отображение будет происходить в том порядке, в каком символы появляются в командной строке, и
за ним последует a \n.
Если число аргументов не равно 2, то программа выводит \n.

Example:

$>./union zpadinton "paqefwtdjetyiytjneytjoeyjnejeyj" | cat -e
zpadintoqefwjy$
$>./union ddf6vewg64f gtwthgdwthdwfteewhrtag6h4ffdhsd | cat -e
df6vewg4thras$
$>./union "rien" "cette phrase ne cache rien" | cat -e
rienct phas$
$>./union | cat -e
$
$>
$>./union "rien" | cat -e
$
$>
*/

#include <unistd.h>

void unity(char *s1, char *s2)
{
    int i;
    int j;

    i = 0;
    while(s1[i])
    {
        j = 0;
        while (j < i)
        {
            if (s1[i] == s1[j])
                break;
            j++;
        }
        if (j == i)
            write(1, &s1[i], 1);
        i++;
    }
    i = 0;
    while (s2[i])
    {
        j = 0;
        while (s1[j])
        {
            if (s1[j] == s2[i])
                break;
            j++;
        }
        if (s1[j] != '\0')
        {
            i++;
            continue;
        }
        j = 0;
        while (j < i)
        {
            if (s2[j] == s2[i])
                break;
            j++;
        }
        if (j == i)
            write(1, &s2[i], 1);
        i++;
    }
}

int main(int argc, char **argv)
{
    if (argc == 3)
        unity(argv[1], argv[2]);
    write(1, "\n", 1);
    return (0);
}


























// void unity(char *s1, char *s2)
// {
//     int i;
//     int j;

//     i = 0;
//     while (s1[i])
//     {
//         j = 0;
//         while (j < i)
//         {
//             if (s1[i] == s1[j]) // проверяем одну строку
//                 break;
//             j++;
//         }
//         if (i == j)
//             write(1, &s1[i], 1);
//         i++;
//     }
//     i = 0;
//     while (s2[i])
//     {
//         j = 0;
//         while(s1[j])
//         {
//             if (s1[j] == s2[i])
//                 break;
//             j++;
//         }
//         if (s1[j] != '\0') // нет смысла идти до конца, начинаем с начала
//         {
//             i++;
//             continue;
//         }
//         j = 0;
//         while (j < i)
//         {
//             if (s2[i] == s2[j])
//                 break;
//             j++;
//         }
//         if (j == i)
//             write(1, &s2[i], 1);
//         i++;
//     }


// }

// int main(int argc, char **argv)
// {
//     if (argc == 3)
//         unity(argv[1], argv[2]);
//     write(1, "\n", 1);
//     return(0);
// }