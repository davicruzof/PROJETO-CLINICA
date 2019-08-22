#include "functions.h"

using namespace std;

void login()
{
    const char usuario[50] = "admin";
    const char password[50] = "3284";
    const char usuario2[50] = "atendente";
    const char password2[50] = "8432";

    ifstream busca("funcionarios.txt");

    char senha[15];
    char user[50];

    tela();

    gotoxy(30,5);
    branco;
    bpreto;
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
    fflush(stdin);
    cin.getline(user,50);

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
        if(busca.is_open())
        {
            busca.read((char *)(&cadF),sizeof(cadastroDeFuncionarios));

            while(busca && !busca.eof())
            {
                if((strcmp(user,cadF.nome) == 0 ) && (strcmp(senha,cadF.rg) == 0)) // MEDICO
                {
                    busca.close();
                    menuMed();
                }
                busca.read((char *)(&cadF),sizeof(cadastroDeFuncionarios));
            }
        }

        if((strcmp(user,usuario) == 0 ) && (strcmp(senha,password) == 0))// ADMIN
        {
            menuAdmin();
        }
        if((strcmp(user,usuario2) == 0 ) && (strcmp(senha,password2) == 0)) //ATENDENTE
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
            login();
        }
    }
}

