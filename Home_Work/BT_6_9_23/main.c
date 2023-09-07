#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>

/*
Ý tưởng ta sẽ tách xử theo từng cụm 3 chữ số hàng trăm.
Ví dụ : 100 203 910 111 
        ___ ___ ___ ___
        |   |   |   |________ 111 -> Một trăm mười một          |
        |   |   |____________ 910 -> Chín trăm mười + nghìn     |_______ Một trăm tỷ hai trăm lẻ ba triệu chín trăm mười nghìn
        |   |________________ 203 -> Hai trăm lẻ ba + triệu     |        một trăm mười một
        |____________________ 100 -> Một trăm + tỷ              |

Một số trường hợp đặc biệt :
- Khi input > 1000 sẽ xuất hiện trường hợp 0 trăm. Vd : 1011-> Một nghìn không trăm mười một
- Khuyết hàng chục. Vd : 109 -> Một trăm lẻ chín
*/

const char* sCaseOne[] = {
    "Khong",
    "Mot",
    "Hai",
    "Ba",
    "Bon",
    "Nam",
    "Sau",
    "Bay",
    "Tam",
    "Chin",
};

const char* sCaseTwo[] = {
    "Mots",
    "Hai",
    "Ba",
    "Tu",
    "Lam",
    "Sau",
    "Bay",
    "Tam",
    "Chin"
};

const char* Muoif[] = {
    "Muoif",
    "Muoif Mot",
    "Muoif Hai",
    "Muoif Ba",
    "Muoif Bon",
    "Muoif Lam",
    "Muoif Sau",
    "Muoif Bay",
    "Muoif Tam",
    "Muoif Chin"
};

void donvi(uint8_t inputNumber){
    printf("%s",sCaseOne[inputNumber%10]);
}

void chuc(uint8_t inputNumber){
    if(inputNumber<10)   donvi(inputNumber%10);
    if(inputNumber>=10&&inputNumber<20)   printf("%s ",Muoif[inputNumber%10]);
    if(inputNumber>=20&&inputNumber<100&&inputNumber%10==0)    printf("%s Muoi ", sCaseOne[inputNumber/10]);
    if(inputNumber>=20&&inputNumber<100&&inputNumber%10!=0)    printf("%s Muoi %s ", sCaseOne[inputNumber/10], sCaseTwo[inputNumber%10-1]);
}

void tram(uint16_t inputNumber){
    if(inputNumber<100) chuc(inputNumber);
    if(inputNumber>=100&&inputNumber%100==0) 
    {
        chuc(inputNumber/100); printf(" Tram ");
    }
    if(inputNumber>=100&&inputNumber%100<10&&inputNumber%100!=0)  
    {
        chuc(inputNumber/100); 
        printf(" Tram Le "); 
        chuc(inputNumber%100);
    }
    if(inputNumber>=100&&inputNumber%100>=10&&inputNumber%100<100)  
    {
        chuc(inputNumber/100); 
        printf(" Tram "); 
        chuc(inputNumber%100);
    }
}

void kotram(uint8_t inputNumber){
    if(inputNumber<100&&inputNumber%100<10)  
    {
        chuc(inputNumber/100); 
        printf(" Tram Le "); 
        chuc(inputNumber%100);
    }
    if(inputNumber<100&&inputNumber%100>=10&&inputNumber%100<100)  
    {
        chuc(inputNumber/100); 
        printf(" Tram "); 
        chuc(inputNumber%100);
    }
}

void nghin(uint32_t inputNumber){
    if(inputNumber<1000) tram(inputNumber);
    if(inputNumber>=1000&&inputNumber%1000==0)
    {
        tram(inputNumber/1000);
        printf(" Nghin");
    } 
    if(inputNumber>=1000&&inputNumber%1000!=0&&inputNumber%1000>=100)
    {
        tram(inputNumber/1000);
        printf(" Nghin ");
        tram(inputNumber%1000);
    }
    if(inputNumber>=1000&&inputNumber%1000!=0&&inputNumber%1000<100)
    {
        tram(inputNumber/1000);
        printf(" Nghin ");
        kotram(inputNumber%1000);
    }
}

void trieu(uint32_t inputNumber){
    if(inputNumber<1000000) nghin(inputNumber);
    if(inputNumber>=1000000&&inputNumber%1000000==0)
    {
        tram(inputNumber/1000000);
        printf(" Trieu");
    } 
    if(inputNumber>=1000000&&inputNumber%1000000!=0&&inputNumber%1000000/1000>=100)
    {
        nghin(inputNumber/1000000);
        printf(" Trieu ");
        nghin(inputNumber%1000000);
    }
    if(inputNumber>=1000000&&inputNumber%1000000!=0&&inputNumber%1000000/1000<100)
    {
        nghin(inputNumber/1000000);
        printf(" Trieu ");
        kotram(inputNumber%1000000/1000);
        printf(" Nghin ");  
        nghin(inputNumber%1000);
    }
}

void ty(uint64_t inputNumber){
    if(inputNumber<1000000000) trieu(inputNumber);
    if(inputNumber>=1000000000&&inputNumber%1000000000==0)
    {
        trieu(inputNumber/1000000000);
        printf(" Ty");
    } 
    if(inputNumber>=1000000000&&inputNumber%1000000000!=0&&inputNumber%1000000000/1000000>=100)
    {
        trieu(inputNumber/1000000000);
        printf(" Ty ");
        trieu(inputNumber%1000000000);
    }
    if(inputNumber>=1000000000&&inputNumber%1000000000!=0&&inputNumber%100000000/1000000<100)
    {
        trieu(inputNumber/1000000000);
        printf(" Ty ");
        kotram(inputNumber%1000000000/1000000);
        printf(" Trieu "); 
        trieu(inputNumber%1000000);
    }
}

int main(){
    ty(100020542047);
    printf(" Dong");
    return 0;
}

