#include<stdio.h>
void main()
{
	//P BOX
	int p[8][8]={
					1,0,1,0,1,0,1,0,
					0,1,0,1,0,1,0,1,
					1,1,1,1,1,1,1,1,
					0,0,0,0,0,0,0,0,
					1,0,1,1,0,0,1,0,
					0,1,0,0,1,0,0,1,
					0,0,1,0,1,0,0,1,
					1,0,0,0,1,1,0,0
				};//input matrix
	int q[8][8];//output matrix
	int i,j;
	for(i=0;i<8;i++)//8 is size of matrix
		for(j=0;j<8;j++)
			q[i][j]=p[7-i][j];//store rows in reverse order
	
	printf("Output of P-box is:\n");
	
	for(j=0;j<8;j++)//column
	{
		if(j%2==1)
		{
			for(i=0;i<8;i++)//rows
				printf("%d",q[i][j]);
			printf("\n");//next line after printing one row
		}//if
	}//for
	
	for(j=0;j<8;j++)//column
	{
		if(j%2==0)
		{
			for(i=0;i<8;i++)//rows
				printf("%d",q[i][j]);
			printf("\n");//next line after printing one row
		}//if
	}//for
	
	//S BOX
	printf("\n\n**** S-box ****\n");
	
	int sip[6],rno[2],colno[4];
	printf("Enter the 6-bit input binary number:\n");
	for(i=0;i<6;i++)
		scanf("%d",&sip[i]);
		
	//get row no. & column no. for mapping from S-box matrix	
	rno[0]=sip[0];
	rno[1]=sip[5];
	colno[0]=sip[1];
	colno[1]=sip[2];
	colno[2]=sip[3];
	colno[3]=sip[4];
	
	//Convert binary no. to decimal no.
	int output=0,output2=0,power=1,power2=1;
	for(i=0;i<2;i++,power*=2)//for row no.
	{
		output+=rno[1-i]*power;//in reverse order, multiply binary to get decimal
	}//for
	int rowno=output;
	
	for(i=0;i<4;i++,power2*=2)//for column no.
	{
		output2+=colno[3-i]*power2;////in reverse order, multiply binary to get decimal
	}//for
	int columnno=output2;
	
	printf("Row number=%d\nColumn number=%d\n",rowno,columnno);
	
	//S-box matrix
	int S1[4][16] = 
	{
		14,  4, 13,  1,  2, 15, 11,  8,  3, 10,  6, 12,  5,  9,  0,  7,
		0, 15,  7,  4, 14,  2, 13,  1, 10,  6, 12, 11,  9,  5,  3,  8,
		4,  1, 14,  8, 13,  6,  2, 11, 15, 12,  9,  7,  3, 10,  5,  0,
		15, 12,  8,  2,  4,  9,  1,  7,  5, 11,  3, 14, 10,  0,  6, 13
	};
	
	//do mapping for output
	int soutput=S1[rowno-1][columnno-1];//"-1" because array index starts from 0
	printf("Output value=%d\n",soutput);
	
	//print binary output value
	printf("Output in binary:\n");
	int c,k;
	for(c=3;c>=0;c--)//4 bit output so, from 3 and >=0
	{
		k=soutput>>c;
		if(k&1)
			printf("1");
		else
			printf("0");
	}//for
}//main
