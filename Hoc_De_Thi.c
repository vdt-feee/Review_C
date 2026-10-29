#include <stdio.h>
#include <malloc.h> // Thuộc lòng: Phải có thư viện này cho malloc/free

int main() {
    int n, i;
    int *a;
    int dem = 0, tong = 0; // Biến đếm và tính tổng luôn khởi tạo = 0

    // 1. Nhập và kiểm tra số nguyên dương N
    do {
        printf("Nhap N (>0): ");
        scanf("%d", &n);
    } while (n <= 0);

    // 2. Cấp phát động & Kiểm tra bộ nhớ
    a = (int *)malloc(n * sizeof(int));
    if (a == NULL) {
        printf("Khong cap phat duoc bo nho");
    }
    else {
        // 3. Nhập mảng
        for (i = 0; i < n; i++) {
            printf("Nhap a[%d]: ", i);
            scanf("%d", (a + i)); // Dùng (a + i) thay vì &a[i] cho đúng chuẩn con trỏ
        }

        // 4. Xử lý logic (VD: Đếm, tổng, vị trí SỐ CHẴN)
        printf("Vi tri cac so chan la: ");
        for (i = 0; i < n; i++) {
            if (*(a + i) % 2 == 0) {    // Đổi điều kiện ở đây tùy đề (VD: *(a+i) == 9)
                printf("%d ", i);       // In vị trí
                dem++;                  // Tăng biến đếm
                tong += *(a + i);       // Cộng dồn vào tổng
            }
        }

        // 5. Kết luận dựa vào biến Đếm
        if (dem == 0) {
            printf("\nKhong ton tai so chan");
        } else {
            printf("\nCo %d so chan, Tong = %d", dem, tong);
        }
    }

    // 6. Trả lại bộ nhớ
    free(a);
    return 0;
}
