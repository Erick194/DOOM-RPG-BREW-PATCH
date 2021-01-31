#include <windows.h>
#include <conio.h>
#include <stdio.h>
#include "funciones.h" 

using namespace std;

void ShowInfo()
{
    setcolor(0x07);printf("     ################");
    setcolor(0x0A);printf("(ERICK194)");
    setcolor(0x07);printf("###############\n");   
    printf("     #                                       #\n");
    printf("     #        DOOM RPG BREW MOD PATCH        #\n");
    printf("     #    Creado Por ERICK VASQUEZ GARCIA    #\n");
    printf("     #               31/1/2021               #\n");
    printf("     #                                       #\n");
    printf("     #   Soluciona el error en la corrupcion #\n");
    printf("     #     de datos en texturas y sprites    #\n");
    printf("     #                                       #\n");
    printf("     #    It solves the error in the data    #\n");
    printf("     #   corruption in textures and sprites  #\n");
    printf("     #                                       #\n");
    printf("     #########################################\n");
    printf("\n");
}

int main(int argc, char *argv[])
{
    int file_size;
    int namegame;
    
    ShowInfo();
    
    FILE *f1, *f2;
    
    // open file
    f1 = fopen("doomrpg.mod","rb");
    
    if(!f1)
        error("doomrpg.mod no found");
    
    // check file
    fseek(f1, 0x24ee8, SEEK_SET);
    
    namegame = ReadUint(f1);
    if(namegame != 0x6d6f6f64)
        error("error file: not the correct file");
    
    fseek(f1, 0, SEEK_END);
    file_size = ftell(f1);
    fseek(f1, 0, SEEK_SET);
    
    // copy file
    f2 = fopen("doomrpg_fix.mod","wb");
    for(int i = 0; i < file_size; i++)
    {
        byte data = ReadByte(f1);
        fwrite(&data, sizeof(byte), 1, f2);
    }
    
    // apply changes for wtexels
    fseek(f2, 0x151fc, SEEK_SET);
    fputc(0x01,f2);fputc(0x90,f2);
    
    fseek(f2, 0x1520c, SEEK_SET);
    fputc(0x01,f2);fputc(0x20,f2);
    
    fseek(f2, 0x15280, SEEK_SET);
    fputc(0x01,f2);fputc(0x10,f2);
    
    fseek(f2, 0x15294, SEEK_SET);
    fputc(0x01,f2);fputc(0x80,f2);
    
    // apply changes for stexels
    fseek(f2, 0x15444, SEEK_SET);
    fputc(0x01,f2);fputc(0xA0,f2);
    
    fseek(f2, 0x15454, SEEK_SET);
    fputc(0x01,f2);fputc(0x20,f2);
    
    fseek(f2, 0x154dc, SEEK_SET);
    fputc(0x01,f2);fputc(0x10,f2);
    
    fseek(f2, 0x154f0, SEEK_SET);
    fputc(0x01,f2);fputc(0xA0,f2);
    
    fclose(f1);
    fclose(f2);
    
    setcolor(0x0A);
    Printf(true, 14, "Parche Completado");
    Printf(true, 15, "Patch Completed");
    setcolor(0x07);
    
    system("PAUSE");
    return EXIT_SUCCESS;
}
