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


int main() {
    int day, month, year;

    // Nhập ngày, tháng và năm từ người dùng
    printf("Nhap ngay (1-31): ");
    scanf("%d", &day);
    printf("Nhap thang (1-12): ");
    scanf("%d", &month);
    printf("Nhap nam: ");
    scanf("%d", &year);

    // Kiểm tra xem ngày, tháng và năm có hợp lệ không
    if (day < 1 || day > 31 || month < 1 || month > 12) {
        printf("Ngay thang khong hop le.\n");
        return 1;
    }

    // Kiểm tra xem tháng 2 có bao nhiêu ngày
    int isLeapYear = (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
    int daysInFebruary = (isLeapYear) ? 29 : 28;

    // Mảng lưu số ngày trong mỗi tháng
    int daysInMonth[] = {0, 31, daysInFebruary, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    // Tính tổng số ngày tính từ 1/1/1 đến ngày nhập vào
    int totalDays = 0;
    for (int i = 1; i < year; i++) {
        if (i % 4 == 0 && (i % 100 != 0 || i % 400 == 0)) {
            totalDays += 366; // Năm nhuận
        } else {
            totalDays += 365; // Năm không nhuận
        }
    }

    for (int i = 1; i < month; i++) {
        totalDays += daysInMonth[i]; // Cộng thêm số ngày trong các tháng trước đó
    }

    totalDays += day; // Cộng thêm số ngày của tháng hiện tại

    // Tìm thứ của ngày nhập vào (0: Chủ Nhật, 1: Thứ Hai, 2: Thứ Ba, ..., 6: Thứ Bảy)
    int dayOfWeek = totalDays % 7;

    switch (dayOfWeek)
    {
    case T2:
        printf("Ngay %d/%d/%d la thu hai.\n", day, month, year);
        break;
    case T3:
        printf("Ngay %d/%d/%d la thu ba.\n", day, month, year);
        break;
    case T4:
        printf("Ngay %d/%d/%d la thu tu.\n", day, month, year);
        break;
    case T5:
        printf("Ngày %d/%d/%d là thứ năm.\n", day, month, year);
        break;
    case T6:
        printf("Ngay %d/%d/%d la thu sau.\n", day, month, year);
        break;
    case T7:
        printf("Ngay %d/%d/%d la thu bay.\n", day, month, year);
        break;
    case CN:
        printf("Ngay %d/%d/%d la chu nhat.\n", day, month, year);
        break;    
    }

    return 0;
}
