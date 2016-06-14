// FirstProject.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <locale>       // Для setlocale()
using namespace std;

#define U8  unsigned char
#define U16 unsigned short
#define U32 unsigned long

#define LOU8(_u16)          ((U8)((_u16) & 0xff))
#define HIU8(_u16)          ((U8)(((_u16) >> 8) & 0xff))
#define LOU16(_u32)         ((U16)((_u32) & 0xffff))
#define HIU16(_u32)         ((U16)(((_u32) >> 16) & 0xffff))
#define MAKEU16(hi8, lo8)   (((((U16)(hi8)) & 0xff) << 8) | (((U16)(lo8)) & 0xff))
#define MAKEU32(hi16, lo16) (((((U32)(hi16)) & 0xffff) << 16) | (((U32)(lo16)) & 0xffff))


int main()
{
   setlocale(LC_ALL, "Rus");  // Для корректного вывода кириллицы

   cout << "\nПеревод велечин разного типа\n";
   U32 l32 = 0x12345678;
   cout << hex << showbase << endl << "U32  - " << l32 << endl;
   cout.unsetf(ios::dec);
   cout.setf(ios::hex|ios::showbase);
   cout << "HI16 - " << HIU16(l32) << ", LO16 - " << LOU16(l32) << endl;
   cout << "HIHI - " << (int)HIU8(HIU16(l32))  << ", HILO - " << (int)LOU8(HIU16(l32)) << ", ";
   cout << "LOHI - " << (int)HIU8(LOU16(l32))  << ", LOLO - " << (int)LOU8(LOU16(l32)) << endl;
   U8 hihi = 0x12, hilo = 0x34, lohi = 0x56, lolo = 0x78;
   cout << endl;
   cout << "HIHI - " << (int)hihi  << ", HILO - " << (int)hilo << ", ";
   cout << "LOHI - " << (int)lohi  << ", LOLO - " << (int)lolo << endl;
   cout << "HI16 - " << MAKEU16(hihi,hilo) << ", LO16 - " << MAKEU16(lohi,lolo) << endl;
   l32 = MAKEU32(MAKEU16(hihi,hilo), MAKEU16(lohi,lolo));
   cout << "U32  - " << l32 << endl;

   cout << endl;
   system("pause");
	return 0;
}

