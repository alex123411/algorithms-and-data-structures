#include <stdio.h>
#include <string.h>
#include <ctype.h>

char radixsort(int N, char strings[N][9]){
    char buf[9] = {0};
    
    for (int j = 7; j >= 0; j--)
    {
        for (int i = 1; i < N; i++)
        {
            strcpy(buf, strings[i]);
            
            int k = i-1;
            while (k>= 0 && strings[k][j] > buf[j])
            {
                strcpy(strings[k+1], strings[k]);
                k--;
            }
            strcpy(strings[k+1], buf);
        }
    } 
}

int main(){
    puts("-------------------------------------------------------------------------------------------");
    printf("Контрольний приклад \n Рядки до сортування: \n");
    char strings1[9][9] = {"aw52345h","ba12345q","kw1999a","kw16345a","kw12245c","kw12245a","kw02345q","kw12344q","aa12345q"};
    for (size_t i = 0; i < 9; i++)
    {
       printf("%s \n", strings1[i]);
    }
    radixsort(9,strings1);
    puts("Рядки після сортування:");
    for (size_t i = 0; i < 9; i++)
    {
       printf("%s \n", strings1[i]);
    }
    puts("-------------------------------------------------------------------------------------------");

    int N , len, ch;
    int x = 1;
    printf("Введіть кількість рядків: ");
    scanf("%i", &N);
    char strings[N][9];
    char string[9] = {0};
    for (size_t i = 0; i < N; i++)
    {
        printf("Введіть рядок №%i \n", x);
        x++;
        scanf("%s",string);
        if (strlen(string)!= 8 || isalpha(string[0]) == 0 || isalpha(string[1])== 0 || isdigit(string[2])== 0|| isdigit(string[3])== 0|| isdigit(string[4])== 0|| isdigit(string[5])== 0 || isdigit(string[6])== 0|| isalpha(string[7])== 0)
        {
            printf("Рядок введено не правильно!\n");
            x--;
            i--;
        }
        else
        {
            strcpy(strings[i], string);
        }
    }
    puts("Невідсортований масив рядків");
    for (size_t i = 0; i < N; i++)
    {
       printf("%s\n", strings[i]);
    }
    radixsort(N, strings);
    puts("Відсортований масив рядків");
    for (size_t i = 0; i < N; i++)
    {
       printf("%s \n", strings[i]);
    }
}