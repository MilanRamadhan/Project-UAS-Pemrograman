#include <stdio.h>
#include "header.h"
#include <stdlib.h>

int main() {
    struct User users[10];
    int userCount = 0;
    int loggedIn = 0;

    while (1) {
        int choice;

        if (!loggedIn) {
            printf("===== Kasir Sederhana =====\n");
            printf("1. Registrasi\n");
            printf("2. Login\n");
            printf("3. Keluar\n");
            printf("Pilihan: ");
            scanf("%d", &choice);

            switch (choice) {
                case 1:
                    registerUser(users, &userCount);
                    break;
                case 2:
                    loggedIn = loginUser(users, userCount);
                    if (loggedIn) {
                        printf("Login berhasil!\n");
                    } else {
                        printf("Login gagal. Silahkan coba lagi.\n");
                    }
                    break;
                case 3:
                    printf("Terima kasih. Sampai jumpa!\n");
                    exit(0);
                default:
                    printf("Pilihan tidak valid.\n");
                    break;
            }
        } else {
            printf("===== Menu Utama =====\n");
            printf("1. Tambah Barang\n");
            printf("2. Lihat Daftar Barang\n");
            printf("3. Kurangi Daftar Barang\n");
            printf("4. Pembayaran\n");
            printf("5. Keluar\n");
            printf("Pilihan: ");
            scanf("%d", &choice);

            switch (choice) {
                case 1:
                    tambahbarang();
                    break;
                case 2:
                    tampilkandaftarbarang();
                    break;
                case 3:
                    kurangiJumlahBarang(0, 5);
                    break;
                case 4:
                    pembayaran();
                    break;
                case 5:
                    printf("Terima kasih. Sampai jumpa!\n");
                    exit(0);
                default:
                    printf("Pilihan tidak valid.\n");
                    break;
            }
        }

        printf("\n");
    }

    return 0;
}