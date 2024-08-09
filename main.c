#include "ft_printf.h"
#include "stdio.h"

int main()
{
    void *ptr;
    ft_printf("\nfakePrint: characters printed = %i\n", ft_printf("fakePrint: %c, %s, pointer: %p, integer: %i, hexadec: %x, HEXADEC: %X", 'a', "string", ptr, 15, 15, 15));
    printf("\nrealPrint: characters printed = %i\n", printf("realPrint: %c, %s, pointer: %p, integer: %i, hexadec: %x, HEXADEC: %X", 'a', "string", ptr, 15, 15, 15));

    ft_printf("%%%%%%%%%%%%\n");
    printf("%%%%%%%%%%%%\n");
}
