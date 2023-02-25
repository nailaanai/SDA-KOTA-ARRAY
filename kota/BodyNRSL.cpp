/* File        : bodyNRSL.c */
/* Deskripsi   : Body prototype ADT Non Restricted Single Linked/Linear list yang hanya dikenali First(L) */
/* Dibuat oleh : Ade Chandra Nugraha */
/* Tanggal     : 24-10-2001 */

#include <limits.h>
#include <malloc.h>
#include "spnrsll.h"
#include <string.h>

/********** BODY SUB PROGRAM ***********/

/**** Konstruktor/Kreator List Kosong ****/
void CreateList (List * L)
/* IS : L sembarang */
/* FS : Terbentuk List Kosong */
{
	 First(*L) = Nil;
}

/**** Manajemen Memory ****/
address Alokasi (infotype X)
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address != Nil, 	   */
/*	dan misalnya menghasilkan P, maka Info(P) = X, Next(P) = Nil */
/* Jika alokasi gagal, mengirimkan Nil */
{
	 /* Kamus Lokal */
	 address P;
	 /* Algoritma */
	 P = (address) malloc (sizeof (ElmtList));
	 if (P != Nil)		/* Alokasi berhasil */
	 {
	Info(P) = X;
	Next(P) = Nil;
	 }
	 return (P);
}

void DeAlokasi (address P)
/* IS : P terdefinisi */
/* FS : P dikembalikan ke sistem */
/* Melakukan dealokasi / pengembalian address P ke system */
{
	 if (P != Nil)
	 {
	free (P);
	 }
}

/**** PRIMITIF BERDASARKAN NILAI ****/
/**** Penambahan Elemen ****/
void InsertKota (List * L, infotype X)
/* IS : L mungkin Kosong */
/* FS : melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */
{
	 /* Kamus Lokal */
	address P;
	 /* Aloritma */
	P = Alokasi (X);
	if (P != Nil)
	{	InsertFirst (&(*L), P);		}
}

void InsertWarga (List * L, infotype X)
/* IS : L mungkin Kosong */
/* FS : melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir (elemen terakhir adalah yang baru) */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal IS = FS */
{
	 /* Kamus Lokal */
	address P;
	 /* Algoritma */
	P = Alokasi (X);
	if (P != Nil)
	{	InsertLast (&(*L), P);		}
}

/**** PRIMITIF BERDASARKAN ALAMAT ****/
/**** Penambahan elemen berdasarkan alamat ****/
void InsertFirst (List * L, address P)
/* IS : L sembarang, P sudah dialokasi */
/* FS : menambahkan elemen ber-address P sebagai elemen pertama */
{
	 Next(P) = First(*L);
	 First(*L) = P;
}

void InsertLast (List * L, address P)
/* IS : L sembarang, P sudah dialokasi */
/* FS : P ditambahkan sebagai elemen terakhir yang baru */
{
	 /* Kamus Lokal */
	address Last;
	 /* Algoritma */
	if (First(*L) != Nil)
	{
		 Last = First(*L);
		while (Next(Last) != Nil){	
		 	Last = Next(Last); 	
		}
		 Next(Last) = P;
	}
		else
	{	First(*L) = P;		}
}

/**** Penghapusan sebuah elemen ****/
void DelFirst (List * L, address * P)
/* IS : L TIDAK kosong */
/* FS : P adalah alamat elemen pertama list sebelum penghapusan */
/*	elemen list berkurang satu (mungkin menjadi kosong) */
/* First elemen yang baru adalah suksessor elemen pertama yang lama */
{
	 *P = First(*L);
	 First(*L) = Next(First(*L));
}


void DelP (List * L, infotype X)
/* IS : L sembarang */
/* FS : Jika ada elemen list beraddress P, dengan Info(P) = X */
/* 	Maka P dihapus dari list dan di dealokasi */
/* Jika tidak ada elemen list dengan Info(P) = X, maka list tetap */
/* List mungkin menjadi kosong karena penghapusan */
{
	 /* Kamus Lokal */
	address P, Prec;
	boolean found=false;
	 /* Algoritma */
		Prec = Nil;
	P = First(*L);
	while ((P != Nil) && (!found))
	{
		 if (strcmp(Info(P),X) == 0)
		 {	found = true;	}
		 else
		 {
		Prec = P;
		P = Next(P);
		 }
	} /* P = Nil Atau Ketemu */

	if (found)
	{
		printf("Warga %s Berhasil Dihapus !",X);
		 if (Prec == Nil && Next(P) == Nil)		/* Hanya 1 elemen */
		 {	First(*L) = Nil;	}
		 else if (Prec == Nil)			/* Ketemu di elemen 1*/
		 {	First(*L) = Next(P);	}
		 else		/* Ketemu di elemen list yang ditengah/akhir */
		 {	Next(Prec) = Next(P);	}
		 Next(P) = Nil;
		 DeAlokasi (P);
	}
}


/**** PROSES SEMUA ELEMEN LIST  ****/
void PrintInfo (List L)
/* IS : L mungkin kosong */
/* FS : Jika List tidak kosong, semua info yang disimpan pada elemen list */
/*	diprint. Jika list kosong, hanya menuliskan "List Kosong" */
{
	 /* Kamus Lokal */
	address P;
	int i = 1;
	 /* Algoritma */
	if (First(L) == Nil)
	{
		 printf ("Kota Tidak Ada\a\n");
	}
	else	/* List memiliki elemen */
	{
		 P = First(L);
		 printf ("Kota %s \n", Info(P));
		 P = Next(P);
		 for (;;)
		 {
		if (P == Nil)
		{
			 printf("\n");
			 break;
		}
		else	/* Belum berada di akhir List */
		{
			 printf ("- Warga %d : %s \n", i,Info(P));
			 P = Next(P);
			 i++;
		}
		 }
	}
}


void DelAll (List * L)
/* Delete semua elemen list dan alamat elemen di dealokasi */
{
	 /* Kamus Lokal */
	address PDel;
	 /* Algoritma */
	PDel = First(*L);
	while (PDel != Nil)
	{
		 DelFirst (&(*L), &PDel);
		 DeAlokasi (PDel);
		 PDel = First(*L);
	}
}



