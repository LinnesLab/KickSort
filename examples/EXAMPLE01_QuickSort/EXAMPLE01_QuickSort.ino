#include "KickSort.h"

#if defined(ARDUINO_ARCH_SAMD)
  #define SerialDebugger SerialUSB
#else
  #define SerialDebugger Serial
#endif


const uint16_t samples = 100;
uint16_t input[samples] = { 3, 53, 70, 56, 18, 85, 27, 14, 37, 94, 9, 55, 40, 60, 52, 61, 15, 65, 13, 8, 57, 97, 69, 4, 35, 82, 22, 73, 59, 68, 78, 24, 21, 36, 71, 80, 74, 39, 17, 12, 29, 76, 49, 51, 30, 90, 88, 2, 84, 50, 62, 28, 77, 43, 5, 16, 58, 26, 32, 34, 1, 75, 66, 95, 38, 89, 67, 87, 100, 54, 92, 81, 25, 83, 46, 33, 23, 45, 96, 99, 79, 48, 11, 31, 7, 6, 19, 91, 93, 44, 47, 98, 86, 41, 63, 20, 72, 10, 42, 64 };


void setup()
{
  SerialDebugger.begin(9600);
  while(!SerialDebugger);


  SerialDebugger.println("QuickSort Descending");
  KickSort<uint16_t>::quickSort(input, samples, KickSort_Dir::DESCENDING);
  for(uint16_t i = 0; i < samples; i++)
  {
    SerialDebugger.print(i);
    SerialDebugger.print(": ");
    SerialDebugger.println(input[i]);
  }
  SerialDebugger.println();
  SerialDebugger.println();
  

  SerialDebugger.println("QuickSort Ascending");
  KickSort<uint16_t>::quickSort(input, samples);
  for(uint16_t i = 0; i < samples; i++)
  {
    SerialDebugger.print(i);
    SerialDebugger.print(": ");
    SerialDebugger.println(input[i]);
  }
  SerialDebugger.println();
  SerialDebugger.println();
  
}

void loop()
{
}
