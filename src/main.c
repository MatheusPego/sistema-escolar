#include <stdio.h>
#include <locale.h>
#include <menu.h>

int main(void)
{
    setlocale(LC_ALL, "Portuguese"); //Estabelece por padrão as acentuações da lingua portuguesa;
    menu();
    return 0;
}
