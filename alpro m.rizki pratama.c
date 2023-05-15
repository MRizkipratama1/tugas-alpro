#include <stdio.h>
#include <stdlib.h>

int main() {
    // Inisialisasi PIN awal
    int pin = 223344;
    // Inisialisasi saldo awal
    float balance = 1233000;
    // Inisialisasi variabel-variabel lain yang dibutuhkan
    int choice, login_attempt = 0;
    int transfer_account_number;
    float transfer_amount, top_up_dana, top_up_gopay, withdrawal_amount;
	
    printf("   ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
    printf("\n\n      ----------SELAMAT DATANG DI ATM INDONESIA--------\n");
    printf("\n\n      ===========      MASUKKAN ATM ANDA      ===========\n");
    printf("\n\n      ===========     MASUKKAN KARTU ANDA     ===========\n");
    printf("        ---------------------------------------------------\n");
    getch();

    // Loop while untuk mengulang login hingga maksimal 3 kali percobaan
    while (login_attempt < 3) {
        // Meminta pengguna memasukkan PIN
        int input_pin;
        printf("Enter PIN: ");
        scanf("%d", &input_pin);
        
        // Jika PIN benar, tampilkan menu opsi
        if (input_pin == pin) {
            printf("Login successful!\n");
            while (1) {
                printf("\nATM Menu\n");
                printf("1. Lihat Saldo\n");
                printf("2. Deposit\n");
                printf("3. Tarik tunai\n");
                printf("4. Transfer\n");
                printf("5. Top Up\n");
                printf("6. Logout\n");
                printf("Enter your choice: ");
                scanf("%d", &choice);
                
                // Switch case untuk setiap opsi pada menu
                switch (choice) {
                    case 1:
                        printf("Saldo anda saat ini: %.2f\n", balance);
                        break;
                    case 2:
                        printf("Masukkan jumlah deposit: ");
                        float deposit_amount;
                        scanf("%f", &deposit_amount);
                        balance += deposit_amount;
                        printf("Deposit berhasil. Saldo baru anda : %.2f\n", balance);
                        break;
                    case 3:
                        printf("Masukkan jumlah tunai yang ingin ditarik: ");
                        scanf("%f", &withdrawal_amount);
                        if (withdrawal_amount > balance) {
                            printf("Dana tidak mencukupi.\n");
                        } else {
                            balance -= withdrawal_amount;
                            printf("Penarikan berhasil. Saldo anda saat ini: %.2f\n", balance);
                        }
                        break;
                    case 4:
                        printf("Masukkan nomor rekening yang ingin di transfer: ");
                        scanf("%d", &transfer_account_number);
                        printf("Masukkan jumlah yang ingin di transfer : ");
                        scanf("%f", &transfer_amount);
                        if (transfer_amount > balance) {
                            printf("Saldo tidak mencukupi.\n");
                        } else {
                            balance -= transfer_amount;
                            printf("Transfer berhasil. Saldo anda saat ini: %.2f\n", balance);
                        }
                        break;
                    case 5:
                        printf("Top up menu\n");
                        printf("1. Top up Dana\n");
                        printf("2. Top up Gopay\n");
                        printf("Enter your choice: ");
                        int top_up_choice;
                        scanf("%d", &top_up_choice);
                        switch (top_up_choice) {
                            case 1:
                                printf("Masukkan jumlah top up: ");
                                scanf("%f", &top_up_dana);
                                printf("Masukkan PIN: ");
                                scanf("%d", &pin);
                                printf("Top up berhasil. Saldo baru anda: %.2f\n", balance + top_up_dana);
                                break;
                            case 2:
                                printf("Masukkan jumlah untuk top up: ");
                                scanf("%f", &top_up_gopay);
                                printf("Enter PIN: ");
                                scanf("%d", &pin);
                                printf("Top up berhasil. Saldo anda saat ini: %.2f", balance -= top_up_gopay);
                                printf("Top up berhasil. Saldo anda saat ini: %.2f\n", balance);
                                break;
                            default:
                                printf("Opsi tidak valid.\n");
                                break;
                        }
                        break;
                    case 6:
                        // Keluar dari menu dan kembali ke menu login
                        printf("Logout successful.\n");
                        login_attempt = 3;
                        break;
                    default:
                        printf("Invalid option.\n");
                        break;
                }
            }
        } else {
            // Jika PIN salah, tampilkan pesan error dan tingkatkan jumlah percobaan
            printf("Invalid PIN. Please try again.\n");
            login_attempt++;
        }
    }
    // Jika sudah 3 kali percobaan login dan masih gagal, keluar dari program
    if (login_attempt == 3) {
        printf("Too many failed attempts. ATM locked.\n");
    }
    return 0;
}
