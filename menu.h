#include <iostream>
#include <conio2.h>
#include <windows.h>
#include <cstring>
#include "cores.h"
using namespace std;

const string usuario = "admin";
const int password = 3284;

void menu();

void tela()
{
    // tela

    for(int i=0; i<29; i++)
    {
        for(int j=0; j<80; j++)
        {
            gotoxy(2+j,1+i);
            azul;
            printf("\xdb");
        }
    }

    //BARRA PRETA

    for(int i=0; i<29; i++)
    {
        for(int j=0; j<45; j++)
        {
            gotoxy(16+j,1+i);
            preto;
            printf("\xdb");
        }
    }
}

void login()
{
    int senha;
    char salvar;
    string user;

    tela();

    gotoxy(23,15);
    branco;
    bpreto;
    cout << " USUARIO ";

    for (int i = 0; i < 20; i++)
    {
        gotoxy(35+i,15);
        bbranco;
        nulo;
    }
    gotoxy(36,15);
    preto;
    cin >> user;

    gotoxy(23,18);
    branco;
    bpreto;
    cout << " SENHA ";

    for (int i = 0; i < 20; i++)
    {
        gotoxy(35+i,18);
        bbranco;
        nulo;
    }

    gotoxy(36,18);
    preto;
    cin >> senha;

    gotoxy(40,29);
    vermelho;
    if (cin.get() == '\n')
    {
        if(user == usuario && password == senha)
        {
            menu();
        }
        else
        {
            gotoxy(23,25);
            branco;
            bpreto;
            cout << " USUARIO OU SENHA INCORRETO ";
            getchar();
            login();
        }
    }
}

void menu()
{
    int opc;

    tela();

    gotoxy(35,3);
    preto;
    bbranco;
    cout << " MENU ";

    gotoxy(25,10);
    preto;
    bbranco;
    cout << " 1 - CADASTRAR CLIENTES ";

    gotoxy(25,12);
    preto;
    bbranco;
    cout << " 2 - AGENDAMENTO ";

    gotoxy(25,14);
    preto;
    bbranco;
    cout << " 3 - BUSCAR VALOR ";

    gotoxy(25,16);
    preto;
    bbranco;
    cout << " 5 - SAIR ";

    getchar();

}
