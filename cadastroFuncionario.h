#include "cores.h"
#include <iostream>
#include <conio2.h>
#include "menu.h"

using namespace std;
struct funcionario
{
    int idfuncionario;
    char nome[30];
    char sobrenome[30];
    char sexo;
    char telefone[11];
    int dia,mes,ano;
    char cargo[20];
    char cpf[11];
    char rg[15];
    float valorConsulta;
};

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

funcionario cadF;    // struct de cadastro de funcionarios

void cadFuncionario()
{

    fstream cadastroF("funcionarios.txt", ios::out | ios::ate);

    tela();

    gotoxy(30,5);
    branco;

    cout << " CADASTRO DE FUNCIONARIOS ";

    gotoxy(23,8);
    branco;
    bpreto;
    cout << " NOME ";

    for (int i = 0; i < 20; i++)
    {
        gotoxy(35+i,8);
        bbranco;
        nulo;
    }
    gotoxy(36,8);
    preto;
    cin >> cadF.nome >> cadF.sobrenome;

    gotoxy(23,10);
    branco;
    bpreto;
    cout << " TELEFONE ";

    for (int i = 0; i < 20; i++)
    {
        gotoxy(35+i,10);
        bbranco;
        nulo;
    }
    gotoxy(36,10);
    preto;
    cin >> cadF.telefone;

    gotoxy(23,12);
    branco;
    bpreto;
    cout << " CARGO ";

    for (int i = 0; i < 20; i++)
    {
        gotoxy(35+i,12);
        bbranco;
        nulo;
    }
    gotoxy(36,12);
    preto;
    cin >> cadF.nome;

    gotoxy(23,14);
    branco;
    bpreto;
    cout << " SEXO ";

    for (int i = 0; i < 5; i++)
    {
        gotoxy(35+i,14);
        bbranco;
        nulo;
    }
    gotoxy(37,14);
    preto;
    cin >> cadF.sexo;

    gotoxy(23,16);
    branco;
    bpreto;
    cout << " DATA DE NASCIMENTO ";

    for (int i = 0; i < 4; i++)
    {
        gotoxy(43+i,16);
        bbranco;
        nulo;
    }
    gotoxy(44,16);
    preto;
    cin >> cadF.dia;

    for (int i = 0; i < 4; i++)
    {
        gotoxy(48+i,16);
        bbranco;
        nulo;
    }
    gotoxy(49,16);
    preto;
    cin >> cadF.mes;

    for (int i = 0; i < 6; i++)
    {
        gotoxy(54+i,16);
        bbranco;
        nulo;
    }
    gotoxy(55,16);
    preto;
    cin >> cadF.ano;

    gotoxy(23,18);
    branco;
    bpreto;
    cout << " CPF ";

    for (int i = 0; i < 15; i++)
    {
        gotoxy(35+i,18);
        bbranco;
        nulo;
    }
    gotoxy(37,18);
    preto;
    cin >> cadF.cpf;

    gotoxy(23,20);
    branco;
    bpreto;
    cout << " RG ";

    for (int i = 0; i < 15; i++)
    {
        gotoxy(35+i,20);
        bbranco;
        nulo;
    }
    gotoxy(37,20);
    preto;
    cin >> cadF.rg;

    gotoxy(23,22);
    branco;
    bpreto;
    cout << " VALOR DA CONSULTA ";

    for (int i = 0; i < 10; i++)
    {
        gotoxy(44+i,22);
        bbranco;
        nulo;
    }
    gotoxy(45,22);
    preto;
    cin >> cadF.valorConsulta;

}
