#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PANJANG_NAMA 50
#define NAMA_FILE "barang.txt"

// Fungsi untuk mengurangi barang
void kurangiJumlahBarang() {
    char namaBarang[MAX_PANJANG_NAMA];
    int jumlahBarang;

    printf("Nama Barang yang ingin dikurangi: ");
    scanf("%s", namaBarang);
    printf("Jumlah Barang yang ingin dikurangi: ");
    scanf("%d", &jumlahBarang);

    FILE *file = fopen(NAMA_FILE, "r+");
    if (file == NULL) {
        printf("Terjadi kesalahan! Gagal membuka file.\n");
        exit(1);
    }

    FILE *tempFile = fopen("temp.txt", "w");
    if (tempFile == NULL) {
        printf("Terjadi kesalahan! Gagal membuka file.\n");
        fclose(file);
        exit(1);
    }

    // Struktur data untuk barang
    char namaBarangFile[MAX_PANJANG_NAMA];
    int jumlahBarangFile;
    int hargaBarangFile;
    int found = 0;

    while (fscanf(file, "Nama Barang: %s\nHarga: %d\nJumlah: %d\n\n", namaBarangFile, &hargaBarangFile, &jumlahBarangFile) != EOF) {
        if (strcmp(namaBarangFile, namaBarang) == 0) {
            if (jumlahBarangFile >= jumlahBarang) {
                jumlahBarangFile -= jumlahBarang;
                fprintf(tempFile, "Nama Barang: %s\nHarga: %d\nJumlah: %d\n\n", namaBarangFile, hargaBarangFile, jumlahBarangFile);
                printf("Jumlah %s berkurang %d.\n", namaBarang, jumlahBarang);
                found = 1;
            } else {
                printf("Jumlah stok %s tidak cukup.\n", namaBarang);
                fprintf(tempFile, "Nama Barang: %s\nHarga: %d\nJumlah: %d\n\n", namaBarangFile, hargaBarangFile, jumlahBarangFile);
            }
        } else {
            fprintf(tempFile, "Nama Barang: %s\nHarga: %d\nJumlah: %d\n\n", namaBarangFile, hargaBarangFile, jumlahBarangFile);
        }
    }

    if (!found) {
        printf("%s tidak ditemukan.\n", namaBarang);
    }

    fclose(file);
    fclose(tempFile);
    remove(NAMA_FILE);
    rename("temp.txt", NAMA_FILE);
}