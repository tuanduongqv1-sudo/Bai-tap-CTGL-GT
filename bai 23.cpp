#include <stdio.h>
#include <string.h>

struct Ngay {
    int ngay;
    int thang;
    int nam;
};

struct HangHoa {
    int maHang;
    char tenHang[50];
    struct Ngay ngayXuat;
    float giaXuat;
};

void nhapHangHoa(struct HangHoa a[], int n) {
    for (int i = 0; i < n; i++) {
        printf("\n--- Nhap hang hoa thu %d ---\n", i + 1);

        printf("Ma hang hoa: ");
        scanf("%d", &a[i].maHang);

        getchar(); 

        printf("Ten hang hoa: ");
        fgets(a[i].tenHang, sizeof(a[i].tenHang), stdin);

       
        a[i].tenHang[strcspn(a[i].tenHang, "\n")] = '\0';

        printf("Ngay xuat (ngay thang nam): ");
        scanf("%d %d %d",
              &a[i].ngayXuat.ngay,
              &a[i].ngayXuat.thang,
              &a[i].ngayXuat.nam);

        printf("Gia xuat hang (trieu dong): ");
        scanf("%f", &a[i].giaXuat);
    }
}


void xuatHangHoa(struct HangHoa a[], int n) {
    printf("\n================ DANH SACH HANG HOA ================\n");

    for (int i = 0; i < n; i++) {
        printf("\nHang hoa thu %d:\n", i + 1);
        printf("Ma hang: %d\n", a[i].maHang);
        printf("Ten hang: %s\n", a[i].tenHang);

        printf("Ngay xuat: %02d/%02d/%04d\n",
               a[i].ngayXuat.ngay,
               a[i].ngayXuat.thang,
               a[i].ngayXuat.nam);

        printf("Gia xuat: %.2f trieu dong\n", a[i].giaXuat);
    }
}


void hoanDoi(struct HangHoa *a, struct HangHoa *b) {
    struct HangHoa temp = *a;
    *a = *b;
    *b = temp;
}


void selectionSort(struct HangHoa a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int viTriMin = i;

        for (int j = i + 1; j < n; j++) {
            if (a[j].giaXuat < a[viTriMin].giaXuat) {
                viTriMin = j;
            }
        }

        if (viTriMin != i) {
            hoanDoi(&a[i], &a[viTriMin]);
        }
    }
}

void timKiemNhiPhan(struct HangHoa a[], int n, float X) {
    int left = 0;
    int right = n - 1;
    int timThay = 0;

    while (left <= right) {
        int mid = (left + right) / 2;

        if (a[mid].giaXuat == X) {
            printf("\n=== HANG HOA CO GIA XUAT BANG %.2f ===\n", X);

            int i = mid;
            while (i >= 0 && a[i].giaXuat == X) {
                i--;
            }
            i++;

            while (i < n && a[i].giaXuat == X) {
                printf("\nMa hang: %d", a[i].maHang);
                printf("\nTen hang: %s", a[i].tenHang);
                printf("\nNgay xuat: %02d/%02d/%04d",
                       a[i].ngayXuat.ngay,
                       a[i].ngayXuat.thang,
                       a[i].ngayXuat.nam);
                printf("\nGia xuat: %.2f trieu dong\n", a[i].giaXuat);

                i++;
            }

            timThay = 1;
            break;
        }
        else if (a[mid].giaXuat < X) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }

    if (timThay == 0) {
        printf("\nKhong tim thay hang hoa co gia xuat bang %.2f!\n", X);
    }
}


int main() {
    int n;
    float X;

    struct HangHoa a[100];

    printf("Nhap so luong hang hoa n = ");
    scanf("%d", &n);


    if (n <= 0 || n > 100) {
        printf("So luong hang hoa khong hop le!\n");
        return 0;
    }

    nhapHangHoa(a, n);

    printf("\n\nDANH SACH HANG HOA VUA NHAP:");
    xuatHangHoa(a, n);

    selectionSort(a, n);

    printf("\n\nDANH SACH SAU KHI SAP XEP TANG DAN THEO GIA:");
    xuatHangHoa(a, n);

    printf("\nNhap gia xuat hang X can tim (trieu dong): ");
    scanf("%f", &X);

    timKiemNhiPhan(a, n, X);

    return 0;
}
