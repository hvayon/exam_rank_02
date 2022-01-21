/*
Напишите программу, которая берет две строки и отображает без двойников символы, которые появляются в обеих строках, в том порядке, в котором они появляются в первой строке.

После этого на дисплее появится буква "\n".

Если число аргументов не равно 2, то программа выводит \n.

Examples:

$>./inter "padinton" "paqefwtdjetyiytjneytjoeyjnejeyj" | cat -e
padinto$
$>./inter ddf6vewg64f gtwthgdwthdwfteewhrtag6h4ffdhsd | cat -e
df6ewg4$
$>./inter "nothing" "This sentence hides nothing" | cat -e
nothig$
$>./inter | cat -e
$
*/

#include <unistd.h>

int check_char(char *str, char c, int index)
{
    int i;
    i = 0;
    while (i < index)
    {
        if (str[i] == c)
            return(0);
        i++;
    }
    return (1);
}

void inter(char *s1, char *s2)
{
    int i;
    int j;
    i = 0;
    while(s1[i])
    {
        if (check_char(s1, s1[i], i))
        {
            j = 0;
            while (s2[j])
            {
                if (s1[i] == s2[j])
                {
                    write (1, &s1[i], 1);
                    break;
                }
                j++;
            }
        }
        i++;
    }
}

int main (int argc, char **argv)
{
    if (argc == 3)
        inter(argv[1], argv[2]);
    write(1, "\n", 1);
    return (0);
}


























// #include <unistd.h>

// int check_char(char *str, char c, int index)
// {
//     int i;
//     i = 0;
//     while (i < index)
//     {
//         if (str[i] == c)
//             return (0);
//         i++;
//     }
//     return (1);
// }

// void inter(char *s1, char *s2)
// {
//     int i;
//     int j;

//     i = 0;
//     while (s1[i])
//     {
//         if (check_char(s1, s1[i], i))
//         {
//             j = 0;
//             while (s2[j])
//             {
//                 if (s1[i] == s2[j])
//                 {
//                     write(1, &s1[i], 1);
//                     break;
//                 }
//                 j++;
//             }

//         }
//         i++;
//     }
// }


// int main(int argc, char **argv)
// {
//     if (argc == 3)
//         inter(argv[1], argv[2]);
//     write(1, "\n", 1);
//     return (0);
// }