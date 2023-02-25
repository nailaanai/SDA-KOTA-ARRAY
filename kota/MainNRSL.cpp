	/* File        : mainNRSL.cpp */
/* Deskripsi   : Driver / main program untuk ADT Non Restricted Single Linked/Linear List */
/* Dibuat oleh : Ade Chandra Nugraha*/
/* Tanggal     : 25-10-2001 */
/* Diupdate oleh : Santi Sundari, 6-4-2011, hanya tdd operasi2 dasar */

#include "spnrsll.h"
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define NAMA 50

void Menu();

int main(){
	/* Kamus Lokal */
		List Kota[5];
		
		int i;
		int pilihMenu;
		int pilihanList;
		infotype X;

	/* Program */
	CreateList (&Kota[0]);
	CreateList (&Kota[1]);
	CreateList (&Kota[2]);
	CreateList (&Kota[3]);
	CreateList (&Kota[4]);
	
	do{
		system("cls");
		printf("=======================\n");
		i = 0;
		for(i;i<5;i++){
			if(First(Kota[i]) != Nil){
				printf("%d. %s\n",i+1,Info(First(Kota[i])));
			}
			else{
				printf("%d. Kota Tidak Ada\n",i+1);
			}
		}
		printf("\n=======================\n");
		Menu();
		scanf("%d",&pilihMenu);

		switch(pilihMenu){
			case 1 : 
				printf("Pilih Nomor Kota : ");
				scanf("%d",&pilihanList);
				X = (infotype) malloc (NAMA);
				printf("Masukan Nama Kota : ");
				scanf("%s",X);
				
				if(pilihanList >= 1 && pilihanList <= 5){	
					if(First(Kota[pilihanList-1]) == Nil){
						InsVFirst(&Kota[pilihanList-1],X);		
					}
					else{		
						printf("Sudah Terdapat Kota Pada Nomor Tersebut !");		
					}
				}
				else{
					printf("Masukan Nomor Kota Yang Valid !");
				}
				getch();
				system("cls");			
				break;
				
			case 2 :
				printf("Pilih Nomor Kota : ");
				scanf("%d",&pilihanList);
				X = (infotype) malloc (NAMA);
				printf("Masukan Nama Warga : ");
				scanf("%s",X);
				
				if(pilihanList >= 1 && pilihanList <= 5){	
					if(First(Kota[pilihanList-1]) != Nil){
						InsVLast(&Kota[pilihanList-1],X);		
					}
					else{		
						printf("Kota Tidak Ada !");		
					}
				}
				else{
					printf("Masukan Nomor Kota Yang Valid !");
				}
				getch();		
				break;
				
			case 3 :
				printf("Pilih Nomor Kota Yang Akan Di Hapus : ");
				scanf("%d",&pilihanList);
				
				if(pilihanList >= 1 && pilihanList <= 5){
					if(First(Kota[pilihanList-1]) != Nil){
						printf("Kota %s Berhasil Dihapus !",Info(First(Kota[pilihanList-1])));
						DelAll (&Kota[pilihanList-1]);
					}
					else{
						printf("Kota Tidak Ada, Tidak Perlu Dihapus !");
					}
				}
				
				getch();		
				break;
				
			case 4 :
				printf("Pilih Nomor Kota Dari Warga Yang Akan Di Hapus : ");
				scanf("%d",&pilihanList);
				
				X = (infotype) malloc (NAMA);
				printf("Masukan Nama Warga Yang Akan Dihapus : ");
				scanf("%s",X);
				
				if(pilihanList >= 1 && pilihanList <= 5){
					DelP (&Kota[pilihanList-1], X);
				}
				else{
						printf("Kota Tidak Ada, Tidak Perlu Dihapus !");
				}
				
				getch();		
				break;
					
			case 5 : 
				i = 0;
				for(i;i<5;i++){
					printf("==============\n");
					printf("%d. ",i+1);
					PrintInfo(Kota[i]);
					printf("==============\n\n");
				}
				getch();
				break;
				
			case 6 :
				printf("Program dihentikan!");
				break;
			default : printf("Masukan insert yang valid!");break;
			}

		}while(pilihMenu != 6);
}


void Menu(){
	printf("Pilih Menu Di bawah ini :\n\n");
	printf("1. Tambah Kota\n");
	printf("2. Tambah Warga Baru\n");
	printf("3. Hapus Kota\n");
	printf("4. Hapus Warga\n");
	printf("5. Tampilkan Seluruh Informasi Kota\n");
	printf("6. Keluar Program");

	printf("\n\nPilihan : ");
}

