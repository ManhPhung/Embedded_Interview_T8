#include <stdio.h>
#include <stdint.h>

uint8_t GIO_HANG = 0;   //00000000

typedef enum
{
    AO          = 1 << 0,   //00000001
    QUAN        = 1 << 1,   //00000010
    VAY         = 1 << 2,   //00000100   
    DAM         = 1 << 3,   //00001000
    NHAN        = 1 << 4,   //00010000
    VONG_TAY    = 1 << 5,   //00100000
    GIAY        = 1 << 6,   //01000000
    TUI         = 1 << 7,   //10000000
} DO_DUNG_CA_NHAN;

void COMPARE(int check)
{
    switch (check)
    {
    case AO:
        printf("        AO\n");
        break;
    case QUAN:
        printf("        QUAN\n");
        break;
    case VAY:
        printf("        VAY\n");
        break;
    case DAM:
        printf("        DAM\n");
        break;
    case NHAN:
        printf("        NHAN\n");
        break;
    case VONG_TAY:
        printf("        VONG TAY\n");
        break;
    case GIAY:
        printf("        GIAY\n");
        break;
    case TUI:
        printf("        TUI\n");
        break;
    default:
        break;
    }
}
void ADD(uint8_t *gio_hang, DO_DUNG_CA_NHAN do_dung_da_them)
{
    *gio_hang |= do_dung_da_them;
}

void CHECK(uint8_t *gio_hang, DO_DUNG_CA_NHAN do_dung_can_check)
{   
    int check = *gio_hang;
    check &= do_dung_can_check;
    printf("Trong gio hang co : \n");

    for(int i=0; i<8;i++)
    {
        int temp = check;
        temp &= (1<<i);
        COMPARE(temp);
    }
}

void SHOW(uint8_t *gio_hang)
{  
    int check = *gio_hang;
    printf("Trong gio hang gom co : \n");
    for(int i=0; i<8;i++)
    {
        int temp = check;
        temp &= (1<<i);
        COMPARE(temp);
    }
}

int main()
{
    ADD(&GIO_HANG, TUI|NHAN|VONG_TAY|DAM);
    CHECK(&GIO_HANG, AO|TUI|DAM);
    SHOW(&GIO_HANG);
    
    return 0;
}