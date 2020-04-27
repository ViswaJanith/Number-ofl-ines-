#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAXCHAR 100
#define MAX_FILE 100
int function_loc(char filechar[]){
    FILE *fp;
    char chr,stri;
    int count=0,loc=0,l=0,start=0,comment=0,var=0;
    char str[MAXCHAR];
    char search[]="int";
    char searcha[]="void";
    char searchb[]="short";
    char searchc[]="long";
    char searchd[]="float";
    char searchf[]="char";
    char search1[]="(";
    char search1a[]=")";
    char search1b[]="{";
    char search2[]="=";
    char searche[]="}";
    fp = fopen(filechar, "r");
    if (fp == NULL){
        printf("Could not open file %s",filechar);
        return 1;
    }        
    while (fgets(str, MAXCHAR, fp)!= NULL){
        char *ptr = strstr(str, search);
        char *ptr1 = strstr(str, searcha);
        char *ptr2 = strstr(str, searchb);
        char *ptr3 = strstr(str, searchc);
        char *ptr4 = strstr(str, searchd);
        char *pt=strstr(str,search1);
        char *pt1=strstr(str,search1b);
        char *pt2=strstr(str,search1a);
        char *p=strstr(str,search2);
        char *t=strstr(str,searche);
        char *ptr5=strstr(str,searchf);
        char *pt11=strstr(str,search1b);
        char *t1=strstr(str,searche);
        if(comment<1){
         if(ptr!= NULL  || ptr1!=NULL || ptr2!=NULL || ptr3!=NULL || ptr4!=NULL || ptr5!=NULL){ 
            if(pt!= NULL && p== NULL && pt1!=NULL && pt2!=NULL){
                count=count+1;
                comment=1;
                l=0;
              }  
          }
         }
        if(comment==1){
        l=l+1;
        if(pt11!=NULL){
                     var=var+1;
                    }
        if(t1!=NULL){
            var=var-1;
        }
        if(var==0){
                      printf("%d is no of lines for the function %d\n",l,count);
                        comment=0;    
                    }
        }     
    }
    fclose(fp);
    printf("There are %d number of functions \n", count);
    return 0;
}
int loc(char filechar[]){
    FILE *fp;
    int count = 0;
    char str,chr;
    fp = fopen(filechar, "r");
     if (fp == NULL)
    {
        printf("Could not open file %s", filechar);
        return 0;
    }
    chr = getc(fp);
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
    printf("There are %d lines in %s  in a file\n", count+1, filechar);
    return 0;
}
int main(){
    char filechar[MAX_FILE], chr,str;
    printf("Enter file name: ");
    scanf("%s", filechar);
    loc(filechar);
    function_loc(filechar);
}