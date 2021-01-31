#ifndef _FUNCIONES_H_
#define _FUNCIONES_H_

#include <windows.h>
#include <stdio.h>

typedef unsigned char   byte;
typedef char            sbyte;
typedef unsigned short  word;
typedef short           sword;
typedef unsigned long   dword;
typedef unsigned int    uint;

int Swap16(unsigned int src);
int Swap32(unsigned int x);

void setcolor (int color);
void PrintfPorcentaje(int count,int Prc, bool draw, int ypos, const char *s, ...);
void Printf(bool draw,int ypos,const char *s, ...);
void error(const char *s,...);

byte ReadByte(FILE *f);
uint ReadUint(FILE *f);
word ReadWord(FILE *f);
sword ReadSword(FILE *f);

#endif
