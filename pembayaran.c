#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

#define MAX_PANJANG_NAMA 50
#define NAMA_FILE "barang.txt"

int pembelianBarang(char *namaBarang, int jumlahBarang) {
    FILE *file = fopen(NAMA_FILE, "r");
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

    char namaBarangFile[MAX_PANJANG_NAMA];
    int jumlahBarangFile;
    int hargaBarangFile;
    int found = 0;
    int totalHarga = 0;

    while (fscanf(file, "Nama Barang: %s\nHarga: %d\nJumlah: %d\n\n", namaBarangFile, &hargaBarangFile, &jumlahBarangFile) != EOF) {
        if (strcmp(namaBarangFile, namaBarang) == 0) {
            if (jumlahBarangFile >= jumlahBarang) {
                jumlahBarangFile -= jumlahBarang;
                totalHarga = jumlahBarang * hargaBarangFile;
                printf("Barang: %s   Jumlah: %d   Total Harga: %d\n", namaBarang, jumlahBarang, totalHarga);
                found = 1;
            } else {
                printf("Maaf, jumlah stok %s tidak cukup.\n", namaBarang);
                found = 1;
            }
        }
        fprintf(tempFile, "Nama Barang: %s\nHarga: %d\nJumlah: %d\n\n", namaBarangFile, hargaBarangFile, jumlahBarangFile);
    }

    if (!found) {
        printf("Maaf, %s tidak tersedia.\n", namaBarang);
    }

    fclose(file);
    fclose(tempFile);
    remove(NAMA_FILE);
    rename("temp.txt", NAMA_FILE);

    return totalHarga;
}

void pembayaran() {
    char namaBarang[MAX_PANJANG_NAMA];
    int jumlahBarang;
    int totalHarga = 0;
    int bayar, kembalian;
    char tambahLagi = 'y';

    while (tambahLagi == 'y' || tambahLagi == 'Y'){
        printf("Masukkan nama barang yang ingin dibeli: ");
        scanf("%s", namaBarang);
        printf("Masukkan jumlah barang yang ingin dibeli: ");
        scanf("%d", &jumlahBarang);

        int harga = pembelianBarang(namaBarang, jumlahBarang);
        if (harga > 0) {
            totalHarga += harga;
        }

        printf("Apakah Anda ingin menambah barang lagi? (y/n): ");
        scanf(" %c", &tambahLagi);

    }

    printf("Total harga yang harus dibayar: %d\n", totalHarga);

    while(1) {
        printf("Masukkan jumlah uang yang akan Anda bayar: ");
        scanf("%d", &bayar);

        if (bayar >= totalHarga) {
            kembalian = bayar - totalHarga;
            printf("Pembayaran berhasil.\nKembalian: %d\n", kembalian);
           
            break;

        } else {
            printf("Maaf, Anda tidak dapat membayar. Uang Anda tidak cukup.\n");
            printf("Pilih opsi:\n1. Bayar kembali\n2. Batalkan pembelian\n");
       
            int pilihan;
            printf("Masukkan pilihan Anda: ");
            scanf("%d", &pilihan);

            if (pilihan == 2) {
                printf("Pembelian dibatalkan.\n");
                return;
            
            } else if (pilihan != 1) {
                printf("Pilihan tidak valid. Silahkan mencoba kembali!\n");
                scanf("d", &pilihan);
            }
       
        }   
    }

}