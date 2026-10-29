#include <stdio.h>
#define N 3 // Đề yêu cầu N là hằng số định nghĩa trước thì bắt buộc xài #define

int main() {
    int a[N][N];
    int i, j;
    int tong = 0, dem = 0; // Để tính trung bình cộng, cần TỔNG và ĐẾM

    // 1. Nhập mảng 2 chiều (Cần 2 vòng for lồng nhau)
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            printf("Nhap a[%d][%d]: ", i, j);
            scanf("%d", &a[i][j]);
        }
    }

    // 2. Xử lý in số lẻ và Tính tổng
    printf("Cac so le trong mang la: ");
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            // Yêu cầu 1: Tìm số lẻ
            if (a[i][j] % 2 != 0) {
                printf("%d ", a[i][j]);
            }
            // Yêu cầu 2: Cộng dồn tất cả các phần tử để tính trung bình
            tong += a[i][j];
            dem++;
        }
    }

    // 3. Tính trung bình (Nhớ ép kiểu float)
    float trungBinh = (float)tong / dem;
    printf("\nGia tri trung binh cua mang: %.2f", trungBinh);

    return 0;
}
