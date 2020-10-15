#include <stdio.h>
#include <stdlib.h>
#define esc 27 
#define enter 13 

//Öðrenci menüsü oluþturma


struct ogrenci
{ 
	int ogrenci_numarasi;
	char ad[30];
	char soyad[30];
	float vize_sonucu;
	float final_sonucu;
	float odev1sonuc;
	float odev2sonuc;
	float donem_sonu_notu;
};

int main(int argc, char *argv[])
 {
	
	struct ogrenci Liste[100];	
	FILE *fptr;           
	char tus;
	int sira=0;
	int i;
	char anamenu;

	
	if(argc == 2)
	{ 

		fptr = fopen(argv[1],"r");
		
		if(fptr == NULL)
			puts("Dosya acilamiyor. !\n"), exit(1);
			
		while(!feof(fptr))
		{
			fscanf(fptr,"%d %s %s",&Liste[sira].ogrenci_numarasi,Liste[sira].ad,Liste[sira].soyad);
			fscanf(fptr,"%f %f %f %f",&Liste[sira].vize_sonucu,&Liste[sira].final_sonucu,&Liste[sira].odev1sonuc,&Liste[sira].odev2sonuc);
			
			
			Liste[sira].donem_sonu_notu = (Liste[sira].vize_sonucu * 0.25) + (Liste[sira].final_sonucu * 0.40) + (Liste[sira].odev1sonuc * 0.15) + (Liste[sira].odev2sonuc * 0.20);
			sira++;
		}
		
		fclose(fptr);
	
	}
	
	
	while(1)
	{
		
		do{ 
		
		
			system("cls");
			printf("\t\t\t\tMENU\n\n");
			printf("--------------------------------------------------------------\n");
			printf("1) YENI OGRENCI EKLE\n");
			printf("2) OGRENCI ARAMA (OGRENCI NUMARASI ILE)\n");
			printf("3) RAPOR YAZDIR\n");
			tus=getch();
			
			if(tus == enter || tus == esc) exit(1); 
			
		}
		
		while(tus!='1' && tus != '2' &&  tus!='3');	
		
		
		switch(tus)
		{
			
			case '1': 
			 	
			i= sira;
			for(i; i < 100; i ++)
			{
				system("cls");
				printf("LUTFEN OGRENCI BILGILERINI GIRINIZ\n");
				printf("%d. OGRENCI NUMARASI: ",i+1);
				scanf("%d", &Liste[i].ogrenci_numarasi);	
				printf("AD: ");
				scanf("%s", Liste[i].ad);		
				printf("SOYAD: ");
				scanf("%s", Liste[i].soyad);							
				printf("VIZE SONUCU: ");
				scanf("%f", &Liste[i].vize_sonucu);	
				printf("FINAL SONUCU: ");
				scanf("%f", &Liste[i].final_sonucu);	
				printf("ODEV1 SONUCU: ");
				scanf("%f", &Liste[i].odev1sonuc);	
				printf("ODEV2 SONUCU: ");
				scanf("%f", &Liste[i].odev2sonuc);							
				Liste[i].donem_sonu_notu = (Liste[i].vize_sonucu * 0.25) + (Liste[i].final_sonucu * 0.40) + (Liste[i].odev1sonuc * 0.15) + (Liste[i].odev2sonuc * 0.20);
				
				int j=0;
				for(j; j <sira; j++)
				{
					if(Liste[j].ogrenci_numarasi == Liste[i].ogrenci_numarasi)
					{
						printf("\nAyni ogrenci numarasi ile yapilmis baska bir kayit bulunmaktadir!");
						i--;
						break;
					} 
				}
				
				sira=i+1;
				
				printf("\n\nAna menuye donmek icin 'M' tusuna basiniz. Verileri kaydetmek icin herhangi bir tusa basiniz.");
				
				anamenu = getch();
				
				if(anamenu=='M' || anamenu =='m') break;
				
			}
					

			
			break;
			
			case '2': 
				
				while(1)
				{
					int ogrenciNo;
					system("cls");
					printf("ARANACAK OGRENCININ NUMARASINI GIRINIZ: ");
					scanf("%d",&ogrenciNo);
					
					i=0;
					int bulunanSira =-1;
					
					for(i;i<sira;i++)
					{
						if(Liste[i].ogrenci_numarasi==ogrenciNo)
						{
							bulunanSira=i; 
							break;
						}
					}					
					
					if (bulunanSira!=-1)
					{
						system("cls");						
						printf("OGRENCI NUMARASI: %d",Liste[bulunanSira].ogrenci_numarasi);
						printf("\nAD: %s",Liste[bulunanSira].ad);
						printf("\nSOYAD: %s",Liste[bulunanSira].soyad);
						printf("\nVIZE SONUCU: %.2f",Liste[bulunanSira].vize_sonucu);
						printf("\nFINAL SONUCU: %.2f",Liste[bulunanSira].final_sonucu);
						printf("\nODEV1 SONUCU: %.2f",Liste[bulunanSira].odev1sonuc);
						printf("\nODEV2 SONUCU: %.2f",Liste[bulunanSira].odev2sonuc);
						printf("\nDONEM SONU NOTU: %.2f",Liste[bulunanSira].donem_sonu_notu);						
					}
					else
					{
						system("cls");
						printf("KAYIT BULUNAMADI");
					}		
					
					printf("\nAna menuye donmek icin 'M' tusuna basiniz. Yeniden arama yapmak icin herhangi bir tusa basiniz.");
					
					anamenu = getch();
					
					if(anamenu=='M' || anamenu =='m') break;

				}
			
			break;
			
			case '3':  
			
				system("cls");									
    			
				fptr = fopen("ders_raporu.txt","w");
				
				if(fptr == NULL)
			      puts("Dosya acilamiyor. !\n"), exit(1);
			      
			    float vizeOrt=0,finalOrt=0,odev1Ort=0,odev2Ort=0,donemSonuOrt=0;
			    i=0;
			    
			    for(i;i<sira;i++)
				{
			    	
			    	vizeOrt+=Liste[i].vize_sonucu;
			    	finalOrt+=Liste[i].final_sonucu;
			    	odev1Ort+=Liste[i].odev1sonuc;
			    	odev2Ort+=Liste[i].odev2sonuc;
			    	donemSonuOrt+=Liste[i].donem_sonu_notu;

				}
				vizeOrt = vizeOrt / sira;
				finalOrt = finalOrt / sira;
				odev1Ort = odev1Ort / sira;
				odev2Ort = odev2Ort / sira;
				donemSonuOrt = donemSonuOrt / sira;
				
		        fprintf(fptr,"Toplam Ogrenci Sayisi: %d \n\nVize Ortalamasi: %.2f\n",sira,vizeOrt); 
				fprintf(fptr,"Final Ortalamasi: %.2f\nOdev1 Ortalamasi: %.2f\n",finalOrt,odev1Ort);
				fprintf(fptr,"Odev2 Ortalamasi: %.2f\nDonem Sonu Not Ortalamasi: %.2f",odev2Ort,donemSonuOrt);
				fclose(fptr);
				
				printf("Raporunuz Olusturuldu!\n Lutfen bir Tusa Basiniz.");
				getch();

			break;
			
		}
		
	}
	
	
	return 0;
}
