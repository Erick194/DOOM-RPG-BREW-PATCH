#include "funciones.h"

#define CLAMP(value, min, max) (((value) >(max)) ? (max) : (((value) <(min)) ? (min) : (value)))


HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

void setcolor (int color)
{
     SetConsoleTextAttribute(hConsole, color);
}

int Swap16(unsigned int src) {
    return (
        ((src & 0xff00) >> 8) |
        ((src & 0x00ff) << 8)
    );
}

int Swap32(unsigned int x)
{
    return(((x & 0xff) << 24) |
    (((x >> 8) & 0xff) << 16) |
    (((x >> 16) & 0xff) << 8) |
    ((x >> 24) & 0xff));
}

void PrintfPorcentaje(int count,int Prc, bool draw, int ypos, const char *s, ...)
{
    //HANDLE hConsoleOutput;      hConsoleOutput=GetStdHandle(STD_OUTPUT_HANDLE);
    
    COORD coord;
     
	char msg[1024];
	va_list v;

	va_start(v, s);
	vsprintf_s(msg, s, v);
	va_end(v);

    coord.X=0;coord.Y=ypos;
    SetConsoleCursorPosition(hConsole,coord);
    
    float prc =CLAMP(((float)((count))) /(Prc), 0.0, 1.0);
    //if(draw) printf("%s(%%%.2f)        \n", msg,prc*100);
    if(draw)
    {
       setcolor(0x07);
       printf("%s", msg,prc*100);
       setcolor(0x0A);
       printf("(%%%.2f)        \n", prc*100);
    }
    setcolor(0x07);
}

void Printf(bool draw, int ypos, const char *s, ...)
{
    COORD coord;
     
	char msg[1024];
	va_list v;

	va_start(v, s);
	vsprintf_s(msg, s, v);
	va_end(v);

    coord.X=0;coord.Y=ypos;
    SetConsoleCursorPosition(hConsole,coord);
    
    //setcolor(0x07);
    if(draw) printf("%s\n", msg);
}

void error(const char *s,...)
{
     setcolor(0x0C);
     va_list args;
     va_start(args,s);
     vfprintf(stderr,s,args);
     fprintf(stderr,"\n");
     va_end(args);
     setcolor(0x07);
     system("PAUSE");
     exit(0);
}

byte ReadByte(FILE *f) {
    byte a;
    fread (&a, sizeof(byte), 1, f);
    return a;
}

uint ReadUint(FILE *f) {
    uint a;
    fread (&a, sizeof(uint), 1, f);
    return a;
}

word ReadWord(FILE *f) {
    word a;
    fread (&a, sizeof(word), 1, f);
    return a;
}

sword ReadSword(FILE *f) {
    sword a;
    fread (&a, sizeof(sword), 1, f);
    return a;
}
