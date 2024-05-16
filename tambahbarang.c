#include <stdio.h>
#include <string.h>
#include "header.h"
#include <stdlib.h>

#define MAX_BARANG 100
#define MAX_PANJANG_NAMA 50
#define NAMA_FILE "barang.txt"

void tambahbarang() {
    FILE *file = fopen("barang.txt", "a");
    if (file == NULL) {
        printf("Terjadi kesalahan! Gagal membuka file.\n");
        exit(1);
    }

    Barang daftarBarang[MAX_BARANG];
    int jumlahBarang = 0;
    char tambahLagi = 'y';

    while (tambahLagi == 'y' || tambahLagi == 'Y') {
        if (jumlahBarang >= MAX_BARANG) {
            printf("Maaf, daftar barang sudah penuh.\n");
            break;
        }

        printf("\nMasukkan nama barang: \n");
        getchar();
        if (fgets(daftarBarang[jumlahBarang].namaBarang, MAX_PANJANG_NAMA, stdin) == NULL) {
            printf("Terjadi kesalahan saat membaca input.\n");
            break;
        }
        daftarBarang[jumlahBarang].namaBarang[strcspn(daftarBarang[jumlahBarang].namaBarang, "\n")] = '\0';

        printf("Masukkan harga barang: \n");
        if (scanf("%d", &daftarBarang[jumlahBarang].hargaBarang) != 1) {
            printf("Terjadi kesalahan saat membaca input harga.\n");
            break;
        }

        printf("Masukkan jumlah barang: \n");
        if (scanf("%d", &daftarBarang[jumlahBarang].jumlahBarang) != 1) {
            printf("Terjadi kesalahan saat membaca input jumlah.\n");
            break;
        }

        fprintf(file, "Nama Barang: %s\nHarga: %d\nJumlah: %d\n\n", daftarBarang[jumlahBarang].namaBarang,
                daftarBarang[jumlahBarang].hargaBarang, daftarBarang[jumlahBarang].jumlahBarang);

        jumlahBarang++;
        printf("\nTambahkan barang lagi? (y/n): ");
        scanf(" %c", &tambahLagi);
    }

    fclose(file);
}