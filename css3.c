#include<stdio.h>
#include<math.h>
int gcd(int a, int h)
{
	int temp;
	while(1)
	{
		temp=a%h;
		if(temp==0)
			return h;
		a=h;
		h=temp;
	}//while
}//gcd
unsigned long long int power(int x, int y, int n)
{
	unsigned long long int temp;
	if(y==0)
		return 1;
	temp=power(x,y/2,n)%n;
	if(y&1)
		return x*temp*temp;
	else
		return temp*temp;
}//power function
void main()
{
	int p,q;//prime numbers
	
	//accept input prime numbers
	printf("Enter 2 prime numbers:\n");
	scanf("%d\n%d",&p,&q);
	
	//calculate modulus & totient
	int n=p*q;
	int phi=(p-1)*(q-1);
	
	//assume public key e such that e is co-prime, e>1, gcd(e,phi)=1 
	int e=13;
	while(e<phi)
	{
		if(gcd(e,phi)==1)
			break;
		else
			e++;
	}//while
	
	//private key
	int k=8;//k can be any arbitrary value
	int d=(1+(k*phi))/e;//d is private key such that (d*e)=1+(k*phi)
	
	//accept input message
	int msg;
	printf("Enter the message:\n");
	scanf("%d",&msg);
	
	//ENCRYPTION
	double c=pow(msg,e);//cipher text
	c=fmod(c,n);
	
	//print cipher text
	printf("Encrypted data=%lf\n",c);
	
	//DECRYPTION
	int m=power(c,d,n)%n;
	
	//print plain text
	printf("Decrypted data=%d\n",m);

}//main
