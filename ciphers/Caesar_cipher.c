#include<stdio.h>
#include<stdlib.h>

char* c_fun(char arr[], int size, int key)
{
    int itr;
    char *text = (char*)malloc(sizeof(char)*(size+1));
    for (itr = 0; itr < size; itr++)
        text[itr] = (arr[itr] - 'a' + key) % 26 + 'a';
    return text;
}

char* d_fun(char arr[], int size, int key)
{
    int itr;
    char *text = (char*)malloc(sizeof(char)*(size+1));
    for (itr = 0; itr < size; itr++)
        text[itr] = (arr[itr] - 'a' + 26 - key) % 26 + 'a';
    return text; 
}

void main()
{
    int l, k;
    scanf("%d", &l);
    char arr[l+1], *cipher, *decipher;
    scanf("%s",arr);
    printf("Key - ");
    scanf("%d",&k);
    cipher = c_fun(arr, l, k);
    decipher = d_fun(cipher, l, k);
    printf("%s\n%s",cipher, decipher);
}