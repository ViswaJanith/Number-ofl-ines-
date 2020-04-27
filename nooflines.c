#include<stdio.h>
#include<stdlib.h>
#define MAX_FILE 100
int main(){
    FILE *fp;
    int count = 0;
    char filechar[MAX_FILE], chr,str;
    printf("Enter file name: ");
    scanf("%s", filechar);
    fp = fopen(filechar, "r");
     if (fp == NULL)
    {
        printf("Could not open file %s", filechar);
        return 0;
    }
    chr = getc(fp);
    str='\n';
    while (chr != EOF)
    {
        if(chr!=' ' && chr!='\t'){     
        if (chr == '\n' && str!= '\n')
        {
            count = count + 1;
        }
         str=chr;
        }
        chr = getc(fp);
    }
    fclose(fp); 
    printf("There are %d lines in %s  in a file\n", count, filechar);
    return 0;
}