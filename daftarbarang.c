#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

#define MAKS_BARANG 100
#define MAKS_PANJANG_NAMA 50
#define NAMA_FILE "barang.txt"

// Fungsi untuk menampilkan daftar barang
void tampilkandaftarbarang() {
    FILE *file = fopen(NAMA_FILE, "r");
    if (file == NULL) {
        printf("Terjadi kesalahan! Gagal membuka file.\n");
        return;
    }

    Barang daftarBarang[MAKS_BARANG];
    int jumlahBarang = 0;
    char buffer[256];

    printf("\nDaftar Barang:\n");
    printf("-------------------------------------------------\n");
    printf("  Nama Barang        Harga       Jumlah\n");
    printf("-------------------------------------------------\n");

    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        if (strncmp(buffer, "Nama Barang:", 12) == 0) {
            sscanf(buffer, "Nama Barang: %s", daftarBarang[jumlahBarang].namaBarang);
            fgets(buffer, sizeof(buffer), file); // Baca "Harga:"
            sscanf(buffer, "Harga: %d", &daftarBarang[jumlahBarang].hargaBarang);
            fgets(buffer, sizeof(buffer), file); // Baca "Jumlah:"
            sscanf(buffer, "Jumlah: %d", &daftarBarang[jumlahBarang].jumlahBarang);
            printf("  %-20s %-10d %-10d\n", daftarBarang[jumlahBarang].namaBarang, daftarBarang[jumlahBarang].hargaBarang, daftarBarang[jumlahBarang].jumlahBarang);
            jumlahBarang++;
            fgets(buffer, sizeof(buffer), file); // Baca baris kosong
        }
    }

    printf("-------------------------------------------------\n");
    fclose(file);
}