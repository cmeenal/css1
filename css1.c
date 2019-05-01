#include<stdio.h>
#include<string.h>
int findInverse(int a)
{
	a=a%26;
	for(int x=1;x<26;x++)//all possible alphabet values
	{
		if((a*x)%26==1)
			return x;
	}//for
}//findInverse function
void main()
{
	char pt[20];//plaintext array
	int i;
	int e[20];//e is encypted plain text i.e. cipher text
	int k1,k2;//keys
	int d[20];//decrypted cipher text i.e. plain text
	
	printf("Enter the plain text in CAPS:\n");
	scanf("%s",pt);
	
	printf("Enter the first key:\n");
	scanf("%d",&k1);
	
	printf("Enter the second key:\n");
	scanf("%d",&k2);
	
	printf("ENCRYPTION: ");
	//give positional  values to letters
	for(i=0;i<strlen(pt);i++)
	{
		e[i]=(int)(pt[i]-65);//65 is ASCII for "A"
		//ENCRYPTION
		e[i]=(e[i]*k1)%26;
		e[i]=(e[i]+k2)%26;
		printf("%c",e[i]+65);//print letters
	}//for
	
	//DECRYPTION
	printf("\nDECRYPTION: ");
	for(i=0;i<strlen(pt);i++)
	{
		d[i]=(e[i]-k2)%26;
		d[i]=(((d[i]*findInverse(k1))%26)+26)%26;
		printf("%c",d[i]+65);//print letters
	}//for
}//main
