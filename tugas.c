/*EL2008 Pemecahan Masalah dengan C 2021/2022
*Kelas            : 1
*Tugas            : 5
*Kelompok         : 2
*Hari dan Tanggal : Kamis, 17 Maret 2022
*Nama (NIM)       : Eraraya Morenzo Muten (18320003)
                    Michelle Angelina (18320007)
                    Shadrina Syahla Vidyana (18320031)
*Nama File        : tugas.c
*Deskripsi        : Program perkalian dua matriks.
*/

// Kamus
#include <stdio.h>
#include <stdlib.h>

void isiMatriks(int size, float* matriks){
    // Deskripsi: mengisi matriks dengan nilai fungsi rand
   srand(time(NULL));
   
   for (int i=0; i<size; i++){
       for (int j=0; j<size; j++){
           matriks[i][j] = rand() %100;
       }
   }
   
   printf("Generated matrix: \n");
   for (int i=0; i<size; i++){
       for (int j=0; j<size; j++){
           printf("%d ", matriks[i][j]);
       }
       printf("\n");
   }
}

void kaliBiasa(int mode, int size, float* matriks1, float* matriks2, float* matriks3){
    // Deskripsi: perkalian matrik1 dengan matriks2 menjadi matriks3
    //            dengan algoritma ...
}

// Program Utama
int main{
    int size, mode, i, j;
    
    // Memilih besar matriks
    printf("Masukan ukuran matriks persegi (10, 100, 1000, atau 10000): \n");
    scanf("%d", %size);
    
    // Memilih algoritma
    
    // Memilih mode akses
    printf("Masukan mode akses matriks (row: 1, column: 2): ");
    scanf("%d", %mode);
    
    // Membuat matriks
    float matriks1[size][size], matriks2[size][size], matriks3[size][size];
    
    // Mengisi matriks
    isiMatriks(size, matriks1);
    isiMatriks(size, matriks2);
    isiMatriks(size, matriks3);
    
    // Melakukan perkalian
    kaliBiasa(mode, size, matriks1, matriks2, matriks3);
    
    // Menampilkan hasil perkalian
    for(i=0; i<size; ++i){
        for(j=0; j<size; ++j){
            printf("%f "; matriks3[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}
