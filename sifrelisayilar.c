#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include<string.h>

void main() {

	char dizi[10][5]={"SIFIR","BIR","IKI","UC","DORT","BES","ALTI","YEDI","SEKIZ","DOKUZ"};
	char giris[100];
	bool hata;
	int i;
	do
	{ 
		hata =false;
		printf("Sifreli Sayilari Girin: ");
		gets(giris);

		if(giris[0]=='-'||giris[strlen(giris)-1]=='-') 
		{
			hata=true;
		 } 
		
		i =2;
		
		for(i;i<strlen(giris);i+=3)
		{
			
			if(giris[i]!='-')
			{
			 hata= true; 
			 } 
			 
			
		}
		
		i =1;
		
		for(i;i<strlen(giris);i+=3)
		{
			
			if( giris[i] - '0' > 5 || giris[i] - '0' < 1  )
			 { 
			 hata= true; 
			 }
			
		} 
		
		i=0;
		
		for(i;i<(strlen(giris));i+=3)
		{ 
		
			if(strlen(dizi[(giris[i]-'0')])<(giris[i+1]-'0'))
			 { 
			 hata=true;
			 break;
			 }
			
		} 
					
		if(hata)
		{
			printf("\nGecersiz Giris!\n");
		 } 
		
	}
	while(hata); 

 	
	i=0;
	
	for(i;i<(strlen(giris));i+=3)
	{ 
	
		printf("%c",dizi[(giris[i]-'0')][(giris[i+1]-'0')-1]);
		
	} 
}

