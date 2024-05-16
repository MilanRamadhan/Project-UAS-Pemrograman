#define MAX_USERNAME_LENGTH 20
#define MAX_PASSWORD_LENGTH 20
#define MAX_BARANG 100
#define MAX_PANJANG_NAMA 50
#define NAMA_FILE "barang.txt"

struct User {
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
};

typedef struct Barang {
    char namaBarang[MAX_PANJANG_NAMA];
    int hargaBarang;
    int jumlahBarang;
} Barang;

int pembelianBarang(char *namaBarang, int jumlahBarang);
void pembayaran();
void registerUser(struct User *users, int *userCount);
int loginUser(struct User *users, int userCount);
void tambahbarang();
void tambahJumlahBarang();
void tampilkandaftarbarang();
void bacadaftarBarang();
void kurangiJumlahBarang();
char namaBarangFile[MAX_PANJANG_NAMA];
char namaBarang[MAX_PANJANG_NAMA];











