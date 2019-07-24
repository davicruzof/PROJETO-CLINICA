#include "menus.h"

using namespace std;

void telalogin()
{
    const string usuario = "admin";
    const int password = 3284;
    const string usuario2 = "atendente";
    const int password2 = 8432;

    int senha;
    string user;

    tela();

    gotoxy(30,5);
    branco;
    cout << " SEJA BEM VINDO ";

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
        if(user == usuario && password == senha) // ADMIN
        {
            menuAdmin();
        }
        if(user == usuario2 && password2 == senha) //ATENDENTE
        {
            menuAtendente();
        }
        else
        {
            gotoxy(23,25);
            branco;
            bpreto;
            cout << " USUARIO OU SENHA INCORRETO ";
            getchar();
            telalogin();
        }
    }
}
