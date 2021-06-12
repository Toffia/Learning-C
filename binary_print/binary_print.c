#include <stdio.h>
#include <fcntl.h>

void binary_print(unsigned int value)
{
 unsigned int mask = 0xff000000;
 unsigned int shift = 256*256*256;
 unsigned int byte, byte_iterator, bit_iterator;

 for (byte_iterator=0; byte_iterator<4; byte_iterator++)
 {
  byte = (value & mask) / shift;
  printf(" ");

  for (bit_iterator=0; bit_iterator<8; bit_iterator++)
  { // 1 byte - 128 bit - 0x80
   if (byte & 0x80)
    printf("1");
   else
    printf("0");
   byte*=2;
  }
  mask /=256;
  shift /=256;
 }
}

int main()
{
 binary_print(1);
}

