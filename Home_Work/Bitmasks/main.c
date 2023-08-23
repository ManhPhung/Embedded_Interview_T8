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
} ITEM;

void COMPARE(int check)
{
    switch (check)
    {
    case AO:
        printf("        AO      ");
        break;
    case QUAN:
        printf("        QUAN    ");
        break;
    case VAY:
        printf("        VAY     ");
        break;
    case DAM:
        printf("        DAM     ");
        break;
    case NHAN:
        printf("        NHAN    ");
        break;
    case VONG_TAY:
        printf("        VONG TAY");
        break;
    case GIAY:
        printf("        GIAY    ");
        break;
    case TUI:
        printf("        TUI     ");
        break;
    default:
        break;
    }
}
void ADD(uint8_t *gio_hang, ITEM do_dung_da_them)
{
    *gio_hang |= do_dung_da_them;
}

void CHECK(uint8_t *gio_hang, ITEM do_dung_can_check)
{   
    int check = *gio_hang;
    check &= do_dung_can_check;
    printf("Kiem tra : \n");
    for(int i=0; i<8;i++)
    {   
        int temp = do_dung_can_check;
        temp &= (1<<i);
        COMPARE(temp);
        if(temp != 0)
        {
            temp &= *gio_hang;
            (temp==0)   ?   printf("   : chua co\n")
                        :   printf("   : da co\n");            
        }      
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
        if(temp!=0) printf(" \n");
        
    }
}

int main()
{
    ADD(&GIO_HANG, TUI|NHAN|VONG_TAY|DAM);
    CHECK(&GIO_HANG, AO|TUI|DAM);
    SHOW(&GIO_HANG);
    
    return 0;
}