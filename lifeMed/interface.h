#define preto textcolor(BLACK)
#define branco textcolor(WHITE)
#define azul textcolor(LIGHTCYAN)
#define bazul textbackground(LIGHTCYAN)
#define vermelho textcolor(LIGHTRED)
#define bpreto textbackground(BLACK)
#define bbranco textbackground(WHITE)
#define bvermelho textbackground(LIGHTRED)
#define nulo cout << '\0'
#include <conio2.h>
#include <stdio.h>

void limpaHelp()
{
    for(int i=0; i<28; i++)
    {
        for(int j=0; j<37; j++)
        {
            gotoxy(83+j,2+i);
            preto;
            printf("\xdb");
        }
    }
}

void tela()
{
    for(int i=0; i<29; i++)
    {
        for(int j=0; j<80; j++)
        {
            gotoxy(2+j,2+i);
            azul;
            printf("\xdb");
        }
    }

    for(int i=0; i<27; i++)
    {
        for(int j=0; j<45; j++)
        {
            gotoxy(16+j,3+i);
            preto;
            printf("\xdb");
        }
    }

    gotoxy(70,4);
    preto;
    bazul;
    system ( "date /t" );
}

void telaHelp()
{
    for(int i=0; i<28; i++)
    {
        for(int j=0; j<37; j++)
        {
            gotoxy(83+j,2+i);
            branco;
            printf("\xdb");
        }
    }
}
