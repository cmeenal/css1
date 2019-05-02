#include <stdio.h>
#include <string.h>

int main()
{
    char hex[16], bin[64]="",y,op[100]="";
    int i = 0,j,x=0,IP[8][8],p,q;
    int P[8][8] =
    {58 ,50 ,42 ,34 ,26 ,18 ,10 ,2,
    60 ,52 ,44 ,36 ,28 ,20 ,12 ,4,
    62 ,54 ,46 ,38 ,30 ,22 ,14 ,6,
    64 ,56 ,48 ,40 ,32 ,24 ,16 ,8,
    57 ,49 ,41 ,33 ,25 ,17 ,9 ,1,
    59 ,51 ,43 ,35 ,27 ,19 ,11 ,3,
    61 ,53 ,45 ,37 ,29 ,21 ,13 ,5,
    63 ,55 ,47 ,39 ,31 ,23 ,15 ,7,
    };
    printf("Enter 16 digit hexadecimal number (Plain Text): ");
    gets(hex);

    for(i=0; hex[i]!='\0'; i++)
    {
        switch(hex[i])
        {
            case '0':
                strcat(bin, "0000");
                break;
            case '1':
                strcat(bin, "0001");
                break;
            case '2':
                strcat(bin, "0010");
                break;
            case '3':
                strcat(bin, "0011");
                break;
            case '4':
                strcat(bin, "0100");
                break;
            case '5':
                strcat(bin, "0101");
                break;
            case '6':
                strcat(bin, "0110");
                break;
            case '7':
                strcat(bin, "0111");
                break;
            case '8':
                strcat(bin, "1000");
                break;
            case '9':
                strcat(bin, "1001");
                break;
            case 'A':
                strcat(bin, "1010");
                break;
            case 'B':
                strcat(bin, "1011");
                break;
            case 'C':
                strcat(bin, "1100");
                break;
            case 'D':
                strcat(bin, "1101");
                break;
            case 'E':
                strcat(bin, "1110");
                break;
            case 'F':
                strcat(bin, "1111");
                break;
            default:
                printf("Invalid hexadecimal input.");
        }
    }
    printf("\n");
    printf("Binary form of Plain Text: %s\n",bin);
    printf("\n");
    for(i=0;i<8;i++)
    {
        for(j=0;j<8;j++)
        {
            x=P[i][j];
            y=bin[x-1];
            if(y=='1')
                IP[i][j]=1;
            if(y=='0')
                IP[i][j]=0;
        }
    }
    printf("Mapping of Plain Text with the initial permutation table \n");
   for(i=0;i<8;i++)
    {
        for(j=0;j<8;j++)
        {
            printf("  %d",IP[i][j]);
        }
        printf("\n");
    }
     printf("\n");

     for(i=0;i<8;i++)
    {   char bin1[100]="",bin2[100]="";
        for(j=0;j<4;j++)
        {
            p=IP[i][j];
            if(p==0)
            {
                strcat(bin1,"0");
            }
            if(p==1)
            {
                strcat(bin1,"1");
            }
        }
         for(j=4;j<8;j++)
        {
            p=IP[i][j];
            if(p==0)
            {
                strcat(bin2,"0");
            }
            if(p==1)
            {
                strcat(bin2,"1");
            }
        }

        if(strcmp(bin1,"0000")==0)
            strcat(op,"0");
        if(strcmp(bin1,"0001")==0)
            strcat(op,"1");
        if(strcmp(bin1,"0010")==0)
            strcat(op,"2");
        if(strcmp(bin1,"0011")==0)
            strcat(op,"3");
        if(strcmp(bin1,"0100")==0)
            strcat(op,"4");
        if(strcmp(bin1,"0101")==0)
            strcat(op,"5");
        if(strcmp(bin1,"0110")==0)
            strcat(op,"6");
        if(strcmp(bin1,"0111")==0)
            strcat(op,"7");
        if(strcmp(bin1,"1000")==0)
            strcat(op,"8");
        if(strcmp(bin1,"1001")==0)
            strcat(op,"9");
        if(strcmp(bin1,"1010")==0)
            strcat(op,"A");
        if(strcmp(bin1,"1011")==0)
            strcat(op,"B");
        if(strcmp(bin1,"1100")==0)
            strcat(op,"C");
        if(strcmp(bin1,"1101")==0)
            strcat(op,"D");
        if(strcmp(bin1,"1110")==0)
            strcat(op,"E");
        if(strcmp(bin1,"1111")==0)
            strcat(op,"F");

        if(strcmp(bin2,"0000")==0)
            strcat(op,"0");
        if(strcmp(bin2,"0001")==0)
            strcat(op,"1");
        if(strcmp(bin2,"0010")==0)
            strcat(op,"2");
        if(strcmp(bin2,"0011")==0)
            strcat(op,"3");
        if(strcmp(bin2,"0100")==0)
            strcat(op,"4");
        if(strcmp(bin2,"0101")==0)
            strcat(op,"5");
        if(strcmp(bin2,"0110")==0)
            strcat(op,"6");
        if(strcmp(bin2,"0111")==0)
            strcat(op,"7");
        if(strcmp(bin2,"1000")==0)
            strcat(op,"8");
        if(strcmp(bin2,"1001")==0)
            strcat(op,"9");
        if(strcmp(bin2,"1010")==0)
            strcat(op,"A");
        if(strcmp(bin2,"1011")==0)
            strcat(op,"B");
        if(strcmp(bin2,"1100")==0)
            strcat(op,"C");
        if(strcmp(bin2,"1101")==0)
            strcat(op,"D");
        if(strcmp(bin2,"1110")==0)
            strcat(op,"E");
        if(strcmp(bin2,"1111")==0)
            strcat(op,"F");
    }
     printf("Output after passing through P-Box: %s\n",op);
}
/* I/P=123456ABCD132536
   O/P=14A7D67818CA18AD  */



