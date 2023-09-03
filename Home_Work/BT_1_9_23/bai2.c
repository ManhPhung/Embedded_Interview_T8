#include <stdio.h>

/*  Ý tưởng : Ta sẽ lấy ngày gốc 1/1/1 là thứ 2.    */

typedef enum{
    CN,
    T2,
    T3,
    T4,
    T5,
    T6,
    T7
}dayOfWeek;

typedef struct{
    int day, month, year;
}dayInput;

int main() {
    
    dayInput dayIn;

    // Nhập ngày, tháng và năm từ người dùng
    printf("Nhap ngay (1-31): ");
    scanf("%d", &dayIn.day);
    printf("Nhap thang (1-12): ");
    scanf("%d", &dayIn.month);
    printf("Nhap nam: ");
    scanf("%d", &dayIn.year);

    // Kiểm tra xem ngày, tháng và năm có hợp lệ không
    if (dayIn.day < 1 || dayIn.day > 31 || dayIn.month < 1 || dayIn.month > 12) {
        printf("Ngay thang khong hop le.\n");
        return 1;
    }

    // Kiểm tra xem tháng 2 có bao nhiêu ngày
    int isLeapYear = (dayIn.year % 4 == 0 && (dayIn.year % 100 != 0 || dayIn.year % 400 == 0));
    int daysInFebruary = (isLeapYear) ? 29 : 28;

    // Mảng lưu số ngày trong mỗi tháng
    int daysInMonth[] = {0, 31, daysInFebruary, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    // Tính tổng số ngày tính từ 1/1/1 đến ngày nhập vào
    int totalDays = 0;
    for (int i = 1; i < dayIn.year; i++) {
        if (i % 4 == 0 && (i % 100 != 0 || i % 400 == 0)) {
            totalDays += 366; // Năm nhuận
        } else {
            totalDays += 365; // Năm không nhuận
        }
    }

    for (int i = 1; i < dayIn.month; i++) {
        totalDays += daysInMonth[i]; // Cộng thêm số ngày trong các tháng trước đó
    }

    totalDays += dayIn.day; // Cộng thêm số ngày của tháng hiện tại
    printf("Tu ngay 1/1/1 den ngay %d/%d/%d da trai qua %d ngay.\n ", dayIn.day, dayIn.month, dayIn.year, totalDays);

    // Tìm thứ của ngày nhập vào (0: Chủ Nhật, 1: Thứ Hai, 2: Thứ Ba, ..., 6: Thứ Bảy)
    int dayOfWeek = totalDays % 7;

    switch (dayOfWeek)
    {
    case T2:
        printf("Ngay %d/%d/%d la thu hai.\n", dayIn.day, dayIn.month, dayIn.year);
        break;
    case T3:
        printf("Ngay %d/%d/%d la thu ba.\n", dayIn.day, dayIn.month, dayIn.year);
        break;
    case T4:
        printf("Ngay %d/%d/%d la thu tu.\n", dayIn.day, dayIn.month, dayIn.year);
        break;
    case T5:
        printf("Ngày %d/%d/%d là thứ năm.\n", dayIn.day, dayIn.month, dayIn.year);
        break;
    case T6:
        printf("Ngay %d/%d/%d la thu sau.\n", dayIn.day, dayIn.month, dayIn.year);
        break;
    case T7:
        printf("Ngay %d/%d/%d la thu bay.\n", dayIn.day, dayIn.month, dayIn.year);
        break;
    case CN:
        printf("Ngay %d/%d/%d la chu nhat.\n", dayIn.day, dayIn.month, dayIn.year);
        break;    
    }

    return 0;
}
