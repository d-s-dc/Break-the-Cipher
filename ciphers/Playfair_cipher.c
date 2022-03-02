#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define fo(a, b) for(a = 0; a < b; a++)

char (*m_fun(char *key, int l))[5]
{
    char (*matrix)[5] = (char(*)[5])malloc(25);
    char alphabets[26];
    int itr, i, i1, r = 0, c = 0;
    fo(itr, 25)
    {
        alphabets[itr] = 0;
        matrix[r][c] = '\0';
        c++;
        if(c==5)
        {
            r++;
            c = 0;
        }
    }
    alphabets['i' - 'a'] = 1;
    alphabets[25] = 0;
    i = 0;
    fo(itr, l)
    if (key[itr] == 'i')
        key[itr] = 'j';
    r = 0; c = 0;
    fo(itr, l)
    if (alphabets[key[itr] - 'a'] == 0)
    {
        matrix[r][c] = key[itr];
        alphabets[key[itr] - 'a'] = 1;
        i++;
        c++;
        if(c == 5)
        {
            r++;
            c = 0;
        }
    }
    srand(time(0));
    fo(i, 26)
    if(alphabets[i] == 0)
    {
        while(matrix[r][c] != '\0')
        {
            itr = rand()%25;
            r = itr/5;
            c = itr%5;
        }
        matrix[r][c] = (char)('a' + i);
        alphabets[i] = 1;
    }
    return matrix;
}

void main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    freopen("output.txt","w",stderr);
    printf("Enter length of key - ");
    int l;
    if(!scanf("%d",&l))
    {
        printf("Length not scanned");
        return;
    }
    printf("Enter key\n");
    char key[l+1];
    getchar();
    if(!fgets(key,l+1,stdin))
    {
        printf("Key not scanned");
        return;
    }
    char (*matrix)[5] = m_fun(key, l);
    int i1, i2;
    fo(i1, 5)
    {
        fo(i2, 5)
        printf("%c ",matrix[i1][i2]);
        printf("\n");
    }
    // Plaintext
    char *ptxt = (char*)malloc(2);
    int size = 2;
    printf("Enter plaintext\n");
    scanf(" ");
    while(scanf("%1[^\n]",&ptxt[size-2]))
    {
        if(ptxt[size-2] == 'i')
            ptxt[size-2] = 'j';
        if(size >= 3 && ptxt[size-2] == ptxt[size-3])
        {
            size++;
            if(!(ptxt = (char*)realloc(ptxt, size)))
            {
                free(matrix);
                free(ptxt);
                printf("Realloc failed");
                return;
            }
            ptxt[size-1] = ptxt[size-2];
            ptxt[size-2] = ptxt[size-3];
            ptxt[size-3] = 'x';
        }
        size++;
        if(!(ptxt = (char*)realloc(ptxt, size)))
        {
            free(matrix);
            free(ptxt);
            printf("Realloc failed in main loop");
            return;
        }
    }
    size--;
    if(!(ptxt = (char*)realloc(ptxt, size)))
    {
        printf("Realloc failed");
        free(matrix);
        free(ptxt);
    }
    ptxt[size-1] = '\0';
    size--;
    if(size % 2 != 0)
    {
        size++;
        if(!(ptxt = (char*)realloc(ptxt, size+1)))
        {
            printf("Realloc failed");
            free(matrix);
            free(ptxt);
            return;
        }
        ptxt[size] = '\0';
        ptxt[size-1] = 'x';
    }
    printf("Plaintext - %s\n",ptxt);
    char cipher[size+1], decrypt[size+1];
    int index[26], r = 0, c = 0, r1, c1, r2, c2, itr;
    index['i' - 'a'] = -1;
    fo(i1, 26)
    {
        index[matrix[r][c] - 'a'] = r*5 + c;
        c++;
        if(c%5 == 0)
        {
            r++;
            c = 0;
        }
    }
    for(itr = 0; itr < size; itr+= 2)
    {
        r1 = index[ptxt[itr] - 'a']/5;
        c1 = index[ptxt[itr] - 'a']%5;
        r2 = index[ptxt[itr + 1] - 'a']/5;
        c2 = index[ptxt[itr + 1] - 'a']%5;
        if(r2 == r1)
        {
            cipher[itr] = matrix[r1][(c1+1)%5];
            cipher[itr+1] = matrix[r1][(c2+1)%5];
        }
        else if(c2 == c1)
        {
            cipher[itr] = matrix[(r1 + 1)%5][c1];
            cipher[itr+1] = matrix[(r2 + 1)%5][c2];
        }
        else
        {
            cipher[itr] = matrix[r1][c2];
            cipher[itr + 1] = matrix[r2][c1];
        }
    }
    cipher[size] = '\0';
    for(itr = 0; itr < size; itr += 2)
    {
        r1 = index[cipher[itr] - 'a']/5;
        c1 = index[cipher[itr] - 'a']%5;
        r2 = index[cipher[itr + 1] - 'a']/5;
        c2 = index[cipher[itr + 1] - 'a']%5;
        if(r1 == r2)
        {
            decrypt[itr] = matrix[r1][(c1+4)%5];
            decrypt[itr+1] = matrix[r1][(c2+4)%5];
        }
        else if(c1 == c2)
        {
            decrypt[itr] = matrix[(r1+4)%5][c1];
            decrypt[itr + 1] = matrix[(r2+4)%5][c2];
        }
        else
        {
            decrypt[itr] = matrix[r1][c2];
            decrypt[itr + 1] = matrix[r2][c1];
        }
    }
    decrypt[size] = '\0';
    printf("Encrypted - %s\nDecrypted - %s",cipher, decrypt);
    free(matrix);
    free(ptxt);
}