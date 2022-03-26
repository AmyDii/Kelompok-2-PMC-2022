/*EL2008 Pemecahan Masalah dengan C 2021/2022
*Kelas            : 1
*Tugas            : 5
*Kelompok         : 2
*Hari dan Tanggal : Kamis, 17 Maret 2022
*Nama (NIM)       : Eraraya Morenzo Muten (18320003)
                    Michelle Angelina (18320007)
                    Shadrina Syahla Vidyana (18320031)
*Nama File        : tugas.c
*Deskripsi        : Program perkalian dua matriks persegi yang sama.
*/

// Kamus
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void isiMatriks(unsigned int size, unsigned int* matriks){
    // Deskripsi: mengisi matriks dengan nilai fungsi rand
    
    // Memilih seed fungsi rand
    srand(1);
    
    // Mengisi tiap elemen matriks dengan fungsi random
    for (int i=0; i<size; i++){
       for (int j=0; j<size; j++){
           matriks[i*size+j] = rand() % 100;
       }
    }
    
    return;
}

void kaliBiasa(int mode, int size, unsigned int* matriks1, unsigned int* matriks2){
    // Deskripsi: perkalian matrik1 dengan matriks1 menjadi matriks2
    //            dengan algoritma perkalian tiap elemen
    int i, j, k, sum;
    
    // Mengakses kolom kemudian baris
    if(mode==1){
        for(i=0; i<size; ++i){
            for(j=0; j<size; ++j){
                sum = 0;
                for(k=0; k<size; ++k){
                    // Mengalikan tiap elemen pada lokasi yang sama
                    sum += matriks1[i*size+k] * matriks1[j+size*k];
                }
            matriks2[i*size+j] = sum;
            }
        }
        
        
    // Mengakses baris kemudian kolom
    } else if(mode==2){
        for(j=0; j<size; ++j){
            for(i=0; i<size; ++i){
                sum = 0;
                for(k=0; k<size; ++k){
                    // Mengalikan tiap elemen pada lokasi yang sama
                    sum += matriks1[j+size*k] * matriks1[i*size+k];
                }
            matriks2[j+size*i] = sum;
            }
        }
    }
    
    return;
}

// Program Utama
int main() {
    int size, algo, mode, i, j;
    double exec_time = 0.0;
    clock_t t;
    
    // Memilih besar matriks
    printf("Masukan ukuran matriks persegi (10, 100, 1000, atau 10000): ");
    scanf("%d", &size);
    
    // Memilih algoritma
    printf("Pilihan Algoritma:\n");
    printf("1. Perkalian tiap elemen\n");
    printf("Masukan nomor algoritma yang diinginkan: ");
    scanf("%d", &algo);
    
    // Memilih mode akses
    printf("Masukan mode akses matriks (baris: 1, kolom: 2): ");
    scanf("%d", &mode);
    
    // Membuat matriks
    //unsigned int matriks1[size * size], matriks2[size * size];
    unsigned int *matriks1 = (unsigned int*)malloc(size*size*sizeof(unsigned int));
    unsigned int *matriks2 = (unsigned int*)malloc(size*size*sizeof(unsigned int));
    
    // Mengisi matriks
    isiMatriks(size, matriks1);
    
    
    // Melakukan perkalian
    if(algo==1){
        // Memulai pengukuran waktu perhitungan
        t = clock();
        kaliBiasa(mode, size, matriks1, matriks2);
    }
    // Mengakhiri pengukuran waktu perhitungan
    t = clock() - t;
    exec_time = ((double)t)/CLOCKS_PER_SEC;
    
    // Menampilkan matriks awal
    printf("Matriks Asli\n");
    for(i=0; i<size; ++i){
        for(j=0; j<size; ++j){
            printf("%u\t", matriks1[i*size+j]);
        }
        printf("\n");
    }
    
    // Menampilkan hasil perkalian
    printf("Matriks Hasil Perkalian\n");
    for(i=0; i<size; ++i){
        for(j=0; j<size; ++j){
            printf("%u\t", matriks2[i*size+j]);
        }
        printf("\n");
    }
    
    // Menampilkan waktu perhitungan
    printf("Waktu perhitungan: %f", exec_time);
    
    return 0;
}