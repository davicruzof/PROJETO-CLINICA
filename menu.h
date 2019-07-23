#include <iostream>
#include <conio2.h>
#include <windows.h>
#include <cstring>
#include "cores.h"
#include "cadastroFuncionario.h"
using namespace std;

void menu();
void menu2();

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

    //BARRA PRETA

    for(int i=0; i<27; i++)
    {
        for(int j=0; j<45; j++)
        {
            gotoxy(16+j,3+i);
            preto;
            printf("\xdb");
        }
    }
}

void login()
{
    const string usuario = "admin";
    const int password = 3284;
    const string usuario2 = "atendente";
    const int password2 = 8432;
    int senha;
//    char salvar;
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
            menu2();
        }
        if(user == usuario2 && password2 == senha) //ATENDENTE
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

void cadastroDoAdmin()
{
    tela();

        gotoxy(30,5);
        preto;
        bbranco;
        cout << " MENU CADASTRAR ";

        gotoxy(25,10);
        preto;
        bbranco;
        cout << " 1 - CADASTRAR FUNCIONARIOS ";

        gotoxy(25,12);
        preto;
        bbranco;
        cout << " 2 - CADASTRAR CLIENTES ";

        cin >> opc;

        switch(opc)
        {
        case 1:
            cadFuncionario();
            break;

        case 2:
            //cadastrarClientes();
            break;

        default:
            cout << "NUMERO DIGITADO NAO ESTA COMPREENDIDO ENTRE AS OPCOES" << endl
             << "TENTE NOVAMENTE" << endl;
             cadastroDoAdmin();
            }
}

void menu()
{
    int opc;

    tela();

    gotoxy(30,5);
    preto;
    bbranco;
    cout << " MENU ATENDENTE ";

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
    cout << " 4 - SAIR ";

    for (int i = 0; i < 5; i++)
    {
        gotoxy(35+i,18);
        bbranco;
        nulo;
    }
    gotoxy(36,18);
    preto;

    cin >> opc;

    switch(opc)
    {
    case 1:
        //cadastraClientes();
        break;

    case 2:
        //agendamento();
        break;

    case 3:
        //buscaValor();
        break;

    case 4:
        return 0;
        break;

    default:
        cout << "NUMERO DIGITADO NAO ESTA COMPREENDIDO ENTRE AS OPCOES" << endl
             << "TENTE NOVAMENTE" << endl;

        menu();

    }

}

void menu2()
{
    int opc;

    tela();

    gotoxy(30,5);
    preto;
    bbranco;
    cout << " MENU ADMIN ";

    gotoxy(25,10);
    preto;
    bbranco;
    cout << " 1 - CRIAR BASE DE DADOS ";

    gotoxy(25,12);
    preto;
    bbranco;
    cout << " 2 - CADASTRAR ";

    gotoxy(25,14);
    preto;
    bbranco;
    cout << " 3 - AGENDAMENTO ";

    gotoxy(25,16);
    preto;
    bbranco;
    cout << " 4 - BUSCAR VALOR ";

    gotoxy(25,18);
    preto;
    bbranco;
    cout << " 5 - RELATÓRIO DE ATENDIMENTOS "

         gotoxy(25,20);
    preto;
    bbranco;
    cout << " 6 - SAIR ";

    cin >> opc;

    switch(opc)
    {
    case 1:
        Cadastros();
        break;

    case 2:
        cadastroDoAdmin();
        break;

    case 3:
        //agendamento();
        break;

    case 4:
        //buscaValor();
        break;

    case 5:
        //relatorioAtendimento();
        break;

    default:
        cout << "NUMERO DIGITADO NAO ESTA COMPREENDIDO ENTRE AS OPCOES" << endl
             << "TENTE NOVAMENTE" << endl;

        menu2();

    }

}
