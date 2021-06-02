#include <stdio.h>
#include <stdlib.h>

void ShowMenu();
void EncryptingFunction(int SK);
void DecryptionFunction(int SK);


int main()
{

    char Choice;
    int SK=3; //SK=ShiftKey


    printf("-----------------AA1846-----------------");
    printf("\n----------*** Caesar Ciper ***----------\n");
    printf("--Also Can Encrypt & Decrypt Sentences--\n\n");


    printf("Encrypt: E/e \nDecrypt: D/d\n");
    printf("If You Want to Exit Press : 0\n");


    printf("\nEnter Your Choice:");
    scanf("%c",&Choice);


     if (Choice == 'E'|| Choice=='e')
            {
                //printf("\nEnter Your Shift Key:");
                //scanf("%d",&SK);
                EncryptingFunction(SK);
            }
            else if(Choice=='D' || Choice == 'd')
            {
                //printf("\nEnter Your Shift Key:");
                //scanf("%d",&SK);
                DecryptionFunction(SK);
            }
            else if(Choice=='0' || Choice=='0')
            {
                printf("\nYou Successfully Exit\n");
                exit(1);
            }

            else
            {
                printf("\nInvalid Syntax\n");
                return 0;

            }

return main();
}

void EncryptingFunction(int SK)
{
    char PlainText[100000];
    char NewTxt[100000];
    int i;

    printf("\nEnter Your Plain Text:");
    scanf(" %[^\n]%*c",&PlainText);

    for(i=0;PlainText[i]!='\0';i++)
    {
        if(PlainText[i]>=65 && PlainText[i]<=90)
        {
           NewTxt[i]=(PlainText[i]+SK);

           if(NewTxt[i]>90 && NewTxt[i]<97)
           {
                NewTxt[i] = ((NewTxt[i]-90) + 64);
           }

        }
        else if(PlainText[i]>=97 && PlainText[i]<=122)
        {
            NewTxt[i]=(PlainText[i]+SK);

            if(NewTxt[i]>122)
            {
                 NewTxt[i] = ((NewTxt[i]-122) + 96);
            }
        }
        else
            NewTxt[i] = PlainText[i];

    }
    printf("\nEncrypted Text is:%s\n \n \n",NewTxt);
}




void DecryptionFunction(int SK)
{
    char EncryptedText[100000];
    char OrgTxt[10000];
    int Txt;
    int i;

    printf("\nEnter Your Plain Text:");
    scanf(" %[^\n]%*c",&EncryptedText);


    for(i=0;EncryptedText[i]!='\0';i++)
    {

        if(EncryptedText[i]>=65 && EncryptedText[i]<=90)
        {
            Txt=(EncryptedText[i]-SK);

           if(Txt<65)
           {
                OrgTxt[i] = (90-(64-Txt));
           }
           else
                OrgTxt[i] = Txt;

        }
        else if(EncryptedText[i]>=97 && EncryptedText[i]<=122)
        {
            Txt=(EncryptedText[i]-SK);

            if(Txt<97)
            {
                 OrgTxt[i] = (122-(96-Txt));
            }
            else
                OrgTxt[i]=Txt;
        }
        else
            OrgTxt[i] = EncryptedText[i];

    }
    printf("\nOriginal Massage Is:%s \n \n \n",OrgTxt);

}




