#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100
#define MAX_LENGTH 100

typedef struct
{
    char npm[MAX_LENGTH];
    char nama[MAX_LENGTH];
    char tempat_lahir[MAX_LENGTH];
    char tanggal_lahir[MAX_LENGTH];
    char prodi[MAX_LENGTH];
} Record;

Record records[MAX_RECORDS];
int record_count = 0;

// Fungsi untuk menambahkan record
void add_record()
{
    if (record_count >= MAX_RECORDS)
    {
        printf("Database penuh, tidak dapat menambah record baru.\n");
        return;
    }

    Record new_record;
    printf("Masukkan NPM: ");
    scanf("%s", new_record.npm);
    printf("Masukkan Nama: ");
    scanf(" %[^\n]s", new_record.nama); // Membaca string dengan spasi
    printf("Masukkan Tempat Lahir: ");
    scanf(" %[^\n]s", new_record.tempat_lahir);
    printf("Masukkan Tanggal Lahir (DD/MM/YYYY): ");
    scanf("%s", new_record.tanggal_lahir);
    printf("Masukkan Prodi: ");
    scanf(" %[^\n]s", new_record.prodi);

    records[record_count++] = new_record;
    printf("Record berhasil ditambahkan.\n");
}

// Fungsi untuk menampilkan semua record
void display_records()
{
    if (record_count == 0)
    {
        printf("Tidak ada record untuk ditampilkan.\n");
        return;
    }

    for (int i = 0; i < record_count; i++)
    {
        printf("\nRecord %d:\n", i + 1);
        printf("NPM: %s\n", records[i].npm);
        printf("Nama: %s\n", records[i].nama);
        printf("Tempat Lahir: %s\n", records[i].tempat_lahir);
        printf("Tanggal Lahir: %s\n", records[i].tanggal_lahir);
        printf("Prodi: %s\n", records[i].prodi);
    }
}

// Fungsi untuk menghapus record berdasarkan NPM
void delete_record()
{
    char npm_to_delete[MAX_LENGTH];
    printf("Masukkan NPM record yang ingin dihapus: ");
    scanf("%s", npm_to_delete);

    int i, found = 0;
    for (i = 0; i < record_count; i++)
    {
        if (strcmp(records[i].npm, npm_to_delete) == 0)
        {
            found = 1;
            break;
        }
    }

    if (!found)
    {
        printf("Record dengan NPM %s tidak ditemukan.\n", npm_to_delete);
        return;
    }

    for (int j = i; j < record_count - 1; j++)
    {
        records[j] = records[j + 1];
    }
    record_count--;
    printf("Record dengan NPM %s berhasil dihapus.\n", npm_to_delete);
}

// Fungsi utama
int main()
{
    int choice;

    do
    {
        printf("\nMenu:\n");
        printf("1. Tambah Record\n");
        printf("2. Tampilkan Semua Record\n");
        printf("3. Hapus Record\n");
        printf("4. Keluar\n");
        printf("Pilih opsi (1-4): ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            add_record();
            break;
        case 2:
            display_records();
            break;
        case 3:
            delete_record();
            break;
        case 4:
            printf("Keluar dari program.\n");
            break;
        default:
            printf("Opsi tidak valid.\n");
            break;
        }
    } while (choice != 4);

    return 0;
}
