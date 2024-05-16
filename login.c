#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

void registerUser(struct User *users, int *userCount) {
    if (*userCount >= 10) {
        printf("Kuota pendaftaran pengguna telah terpenuhi.\n");
        return;
    }

    struct User newUser;

    printf("===== Registrasi Pengguna Baru =====\n");

    printf("Masukkan username (maksimal %d karakter): ", MAX_USERNAME_LENGTH - 1);
    scanf("%s", newUser.username);

    printf("Masukkan password (maksimal %d karakter): ", MAX_PASSWORD_LENGTH - 1);
    scanf("%s", newUser.password);

    users[*userCount] = newUser;
    (*userCount)++;

    printf("Registrasi berhasil.\n");
}

int loginUser(struct User *users, int userCount) {
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];

    printf("===== Login =====\n");

    printf("Username: ");
    scanf("%s", username);

    printf("Password: ");
    scanf("%s", password);

    for (int i = 0; i < userCount; i++) {
        if (strcmp(username, users[i].username) == 0 && strcmp(password, users[i].password) == 0) {
            printf("Login berhasil. Anda telah masuk ke kasir.\n");
            return 1;
        }
    }

    printf("Login gagal. Username atau password salah.\n");
    return 0;
}