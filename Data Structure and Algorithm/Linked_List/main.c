#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>

struct sinhvien{
	uint8_t ID ;
	char* name ;
	uint8_t age ;
	char* class ;
};

typedef struct{
	char name[20];
	uint8_t age;
	char class[20];
}SinhVien;

void nhapThongTinSinhVien(SinhVien *sv) {
    printf("Nhap ten sinh vien: ");
    scanf("%s", sv->name);

    printf("Nhap tuoi sinh vien: ");
    scanf("%d", &sv->age);

    printf("Nhap lop sinh vien: ");
    scanf("%s", sv->class);
}


int main(){
	SinhVien sv1;

//	enterData(&sv1);
//	push(&sv1,sv1.name, sv1.age, sv1.class);
	nhapThongTinSinhVien(&sv1);


    // In thông tin sinh viên đã nhập
    printf("Thong tin SinhVien:\n");
    printf("Ten: %s\n", sv1.name);
    printf("Tuoi: %d\n", sv1.age);
    printf("Lop: %s\n", sv1.class);

	return 0;
}
