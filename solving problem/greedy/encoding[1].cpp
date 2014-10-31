#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
char a[500];
int count=0,setcount=1,temp=255;
FILE *stream;
clrscr();

printf("\nEnter the input:\n");
scanf("%s",&a);
stream=fopen("g.txt","w");
int len=strlen(a);
printf("Original input :%s\n\nLength:%d\n\nCompressed output:",a,len);

while(count<len)
{
    if(a[count]==a[count+1])
    {
    setcount++;
    count++;
    }

    else
        while(1)
        {
        if(setcount>255)
            {
            printf("%c\\%d",a[count],temp);
            setcount-=temp;
            }
        else
            {
            printf("%c\\%d",a[count],setcount);
               fprintf(stream, " %c\\ %d", a[count],setcount);
            setcount=1;
            count++;
            break;
            }


        }

    }

    printf("\n");


    getch();
    return(0);




}
