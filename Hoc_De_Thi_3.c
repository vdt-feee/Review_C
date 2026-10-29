#include <stdio.h>

// 1. Định nghĩa Struct (Nhớ dấu chấm phẩy ; ở cuối)
struct Hoadon {
    char name[50];
    int add;        // Đề giả định Quận chỉ nhập số
    int soluong;
    int thanhtoan;
}; // <--- Quên dấu ; này là rớt điểm toàn bài

int main() {
    int n, i;
    struct Hoadon ds[100]; // Khai báo mảng chứa danh sách hóa đơn

    printf("Nhap so luong khach hang: ");
    scanf("%d", &n);

    // 2. Vòng lặp Nhập và Tính tiền
    for (i = 0; i < n; i++) {
        printf("\nNhap ten KH %d: ", i + 1);
        fflush(stdin); // Hoặc dùng gets(tam) để xóa bộ đệm trước khi nhập chuỗi
        gets(ds[i].name);

        printf("Nhap quan (so): ");
        scanf("%d", &ds[i].add);

        printf("Nhap so luong hang: ");
        scanf("%d", &ds[i].soluong);

        // Logic tính tiền chiết khấu (25.000đ/đơn vị)
        int tienGoc = ds[i].soluong * 25000;

        if (ds[i].soluong >= 500) {
            ds[i].thanhtoan = tienGoc * 0.9;  // Chiết khấu 10%
        }
        else if (ds[i].soluong >= 100) {
            ds[i].thanhtoan = tienGoc * 0.95; // Chiết khấu 5%
        }
        else {
            ds[i].thanhtoan = tienGoc;        // 0%
        }

        printf("Tien phai tra: %d\n", ds[i].thanhtoan);
    }

    // 3. Lọc khách hàng (Ví dụ: Quận 1 VÀ Số lượng > 100)
    int demKH = 0;
    for (i = 0; i < n; i++) {
        if (ds[i].add == 1 && ds[i].soluong > 100) {
            demKH++;
        }
    }
    printf("\nSo KH o Quan 1 mua tren 100 hang la: %d", demKH);

    return 0;
}
