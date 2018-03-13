#include <errno.h>
#include <stdio.h>
#include <string.h>
#define MAX 256

void CheckBuffer (char *Buffer,char *wBuffer);
int ReplaceWord (char *word, char *wBuffer, int n, int j, char letter);

int main(int argc, char* argv[])
{
    FILE * rPointer;
    FILE * wPointer;

    char Buffer[MAX];
    char wBuffer[MAX];

    rPointer = fopen("duom.txt", "r");
    wPointer = fopen("rez.txt", "w");

    if(rPointer!=NULL&&rPointer!=NULL)
    {
        while(!feof(rPointer))
        {
            fgets(Buffer,255,rPointer);
            CheckBuffer (Buffer,wBuffer);
            fputs(wBuffer,wPointer);
            fprintf(wPointer,"\n");
        }

        fclose(rPointer);
        fclose(wPointer);
    }
    else
    {
        perror("");
    }

    return 0;
}
void CheckBuffer (char *Buffer,char *wBuffer)
{   int i;
    int j=0;
    char letter='0';
    char word[MAX];
    int Length=strlen(Buffer);
    int n=0;
    for(i=0;i<=Length;i++)
   {
        if(Buffer[i]!=' '&&Buffer[i]!='\n'&&i!= Length)
        {
            word[j]=Buffer[i];
            if (letter=='0'&&((Buffer[i]>64&&Buffer[i]<91)||(Buffer[i]>96&&Buffer[i]<123)))
            {
                letter=Buffer[i];
            }
            j++;
        }
        else
        {
          n=ReplaceWord (word,wBuffer,n,j,letter);
          j=0;
          letter='0';
        }
    }
    wBuffer[n]='\0';
    n++;
}
int ReplaceWord (char *word, char *wBuffer, int n, int j, char letter)
{   int k;
    for(k=0;k<j;k++)
    {
        if((word[k]<65)||(word[k]>90&&word[k]<97)||(word[k]>122))
        {
            wBuffer[n]=letter;
        }
        else
        {
            wBuffer[n]=word[k];
        }
        n++;
    }
    wBuffer[n]=' ';
    n++;
    return n;
}
