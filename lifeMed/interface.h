#include <conio2.h>
#include <stdio.h>
#include<windows.h>
#define preto textcolor(BLACK)
#define branco textcolor(WHITE)
#define azul textcolor(LIGHTCYAN)
#define bcyan textbackground(LIGHTCYAN)
#define vermelho textcolor(LIGHTRED)
#define bpreto textbackground(BLACK)
#define bbranco textbackground(WHITE)
#define bazul textbackground(BLUE)
#define bvermelho textbackground(LIGHTRED)
#define nulo cout << '\0'

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
    bcyan;
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

namespace data
{
struct Data
{
    int dia;
    int mes;
    int ano;
};

void ParseData(char str[9], Data *Alvo)
{
    char _dia[3] =
    {
        str[3],
        str[4],
        0
    };
    char _mes[3] =
    {
        str[0],
        str[1],
        0
    };
    char _ano[3] =
    {
        str[6],
        str[7],
        0
    };
    Alvo->dia = atoi(_dia);
    Alvo->mes = atoi(_mes);
    Alvo->ano = atoi(_ano);
    return;
}
}

namespace cadastros
{
struct cadastroDeFuncionarios
{
    char nome[50];
    char sexo[20];
    char telefone[11];
    int dia,mes,ano;
    char cargo[50];
    char cpf[12];
    char rg[15];
    char crm[7];
    int codigo;
    float valorConsulta;
} cadF;

struct clientes
{
    char nome[50];
    char cpf[12];
    int dia;
    int mes;
    int ano;
    char sexo[20];
    char telefone[11];
} cadC;
}


