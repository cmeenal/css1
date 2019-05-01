#include<stdio.h>
#include<math.h>
void main()
{
	int q;
	int xa, xb;
	int i,j,k,a[20][20];
	int count;
	int alpha;
	int ya,yb;
	int ka,kb;
	
	printf("Enter prime number q:\n");
	scanf("%d",&q);
	
	//PRIVATE KEY of user a and b are xa and xb
	printf("Enter the PRIVATE KEYS for user a and b:\n");
	printf("Enter a value for xa which is less than q:\n");
	scanf("%d",&xa);
	printf("Enter a value for xb which is less than q:\n");
	scanf("%d",&xb);
	
	//make matrix for primitive root calculation
	for(i=0;i<q-1;i++)//row from 1-10 for q=11 i.e. array index 0-9 i.e. i=0 to <10 (q-1)
		for(j=0;j<q-1;j++)
			a[i][j]=((int)pow(i+1,j+1))%q;//element=(row^column)%q & row no.=1+array index
			
	//primitive root calculation
	for(i=0;i<q-1;i++)
	{
		count=0;//reset value for next row calculation
		for(j=0;j<q-2;j++)
		{
			for(k=j+1;k<q-1;k++)
				if(a[i][j]==a[i][k])
				{
					count=1;
					break;
				}//if
		
			if(count==1)
				break;
		}//for loop of j
		
		if(count==0)
		{
			alpha=i+1;//primitive root is row no. =1+array index
			break;
		}//if
	}//for loop of i
	printf("alpha value is: %d\n",alpha);
	
	//PUBLIC KEYS of user a & b are ya & yb
	ya=((int)pow(alpha,xa))%q;
	yb=((int)pow(alpha,xb))%q;
	printf("The PUBLIC KEYS for user a and b:\nya=%d\nyb=%d\n",ya,yb);
	
	//KEY GENERATION
	ka=((int)pow(yb,xa))%q;
	kb=((int)pow(ya,xb))%q;
	printf("The KEY GENERATION\nka=%d\nkb=%d\n",ka,kb);
	
	//compare keys
	if(ka==kb)//this should always be true
		printf("The keys are same.\n");
	else 
		printf("The keys are different.\n");
}//main
