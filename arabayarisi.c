#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <dos.h>



int main() {
	srand(time(NULL));
	int x,DoganSLX_puan,Ferrari_puan;
	int i;
	
	while((DoganSLX_puan<=100)&&(Ferrari_puan<=100))
	{
		x=rand()%10;
		printf("SAYI:%d\n",x);
		
		if((x>0)&&(x<5))
		{
			DoganSLX_puan+=3;
		}
		else if((x>=6)&&(x<=7))
		{
			DoganSLX_puan-=6;
		}
		else if((x>=8)&&(x<=10))
		{
			DoganSLX_puan+=1;
		}
		if(DoganSLX_puan<0)
		{
		    DoganSLX_puan=0;	
		}
		if((x>=1)&&(x<=2))
		{
			//HAREKET ETMÝYOR
		}
		else if((x>=3)&&(x<=4))
		{
			Ferrari_puan+=9;
		}
		else if((x==5))
		{
			Ferrari_puan-=12;
		}
		else if((x>=6)&&(x<=8))
		{
			Ferrari_puan+=1;
		}
		else if((x>=9)&&(x<=10))
		{
			Ferrari_puan-=2;
		}
		if(Ferrari_puan<0)
		{
			Ferrari_puan=0;
		}
		
		for(i=0;i<=DoganSLX_puan;i++)
		{
			printf(" ");
		}
		printf("X\n");
		
		for(i=0;i<=Ferrari_puan;i++)
		{
			printf(" ");
		}
		
		printf("F\n");
		printf("DoganSLX:%d\n",DoganSLX_puan);
		printf("Ferrari:%d\n",Ferrari_puan);
		
		sleep(1);
		
		if(DoganSLX_puan>=100)
		{
			printf("DoganSLX yarisi kazandi\n");
		}
		else if(Ferrari_puan>=100)
		{
			printf("Ferrari yarisi kazandi\n");
		}
		else
		{
			system("CLS");
		}
		
		
		
	}
	
	
}
