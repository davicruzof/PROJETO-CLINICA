#include <iostream>
#include <fstream>
#include <conio2.h>
#include <cstdlib>
#include <stdio.h>
#include "cores.h"

using namespace std;

void cadastroClientes();

struct cadastroDeFuncionarios
{
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


struct clientes
{
    char nome[30];
    char sobrenome[30];
    char cpf[12];
    int dia;
    int mes;
    int ano;
    char sexo;
    char endereco[50];
    char telefone[11];
};

clientes cadC;

cadastroDeFuncionarios cadF;

void funcionarioCadastro();

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
}


void cadastroDoAdmin()
{
    int opc=0;

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

    gotoxy(25,14);
    preto;
    bbranco;
    cout << " 3 - ALTERAR CADASTRO DE FUNCIONARIOS ";

    gotoxy(25,16);
    preto;
    bbranco;
    cout << " 4 - VOLTAR PARA O MENU ";

    for (int i = 0; i < 5; i++)
    {
        gotoxy(35+i,22);
        bbranco;
        nulo;
    }

    gotoxy(36,22);
    preto;
    cin >> opc;

    switch(opc)
    {
    case 1:
        funcionarioCadastro();
        break;

    case 2:
        cadastroClientes();
        break;

    }
}


void menuAdmin()
{
    int opc=0;

    tela();

    gotoxy(30,5);
    preto;
    bbranco;
    cout << " MENU ADMIN ";

    gotoxy(25,10);
    preto;
    bbranco;
    cout << " 1 - CADASTRAR ";

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
    cout << " 4 - RELATÓRIO DE ATENDIMENTOS ";

    gotoxy(25,18);
    preto;
    bbranco;
    cout << " 5 - SAIR ";

    for (int i = 0; i < 5; i++)
    {
        gotoxy(35+i,22);
        bbranco;
        nulo;
    }

    gotoxy(37,22);
    preto;
    cin >> opc;

    switch(opc)
    {
    case 1:
        cadastroDoAdmin();
        break;

    case 2:
        break;

    case 3:
        break;

    case 4:
        break;

    case 5:
        exit(1);
        break;
    }
}


void funcionarioCadastro()
{
    char novoCad;

    ofstream cadastroFuncionario ("funcionarios.txt", ios::app);

    if(cadastroFuncionario.fail())
    {
        cout << " ERRO AO ABRIR ARQUIVO";
        exit(1);
    }


    tela();

    gotoxy(30,5);
    branco;
    bpreto;
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
    cout << " SEXO (M/F) ";

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

    cadastroFuncionario.write((const char*)(&cadF),sizeof(cadastroDeFuncionarios));

    gotoxy(16,24);
    branco;
    bpreto;
    cout << " DESEJA CADASTRAR NOVO FUNCIONARIO (S/N) ";

    for (int i = 0; i < 3; i++)
    {
        gotoxy(57+i,24);
        bbranco;
        nulo;
    }
    gotoxy(59,24);
    preto;
    cin >> novoCad;

    if(novoCad == 'S' || novoCad == 's')
    {
        funcionarioCadastro();
    }
    else
    {
        menuAdmin();
    }

    cadastroFuncionario.close();
}


void menuAtendente()
{

    int opc=0;

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
        gotoxy(35+i,22);
        bbranco;
        nulo;
    }

    gotoxy(36,22);
    preto;
    cin >> opc;

    switch(opc)
    {
    case 1:
        cadastroClientes();
        break;

    case 2:
        break;

    case 3:
        break;

    case 4:
        exit(1);
        break;
    }
}



void cadastroClientes()
{
    char op;

    ofstream cadastro("database.txt", ios::out | ios::app);

    if(!cadastro.is_open())
    {
        cout<<"ERRO AO ABRIR ARQUIVO"<<endl;
        exit(1);
    }

    tela();

    gotoxy(30,5);
    branco;
    bpreto;
    cout << " CADASTRO DE FUNCIONARIOS ";

    gotoxy(23,8);
    branco;
    bpreto;
    cout<<" NOME ";

    for (int i = 0; i < 20; i++)
    {
        gotoxy(35+i,8);
        bbranco;
        nulo;
    }
    gotoxy(36,8);
    preto;
    cin >> cadC.nome >> cadC.sobrenome;

    gotoxy(23,10);
    branco;
    bpreto;
    cout<<" CPF ";

    for (int i = 0; i < 20; i++)
    {
        gotoxy(35+i,10);
        bbranco;
        nulo;
    }
    gotoxy(36,10);
    preto;
    cin>>cadC.cpf;

    gotoxy(23,12);
    branco;
    bpreto;
    cout<<" DATA DE NASCIMENTO ";

    for (int i = 0; i < 4; i++)
    {
        gotoxy(43+i,12);
        bbranco;
        nulo;
    }
    gotoxy(44,12);
    preto;
    cin>>cadC.dia ;

    for (int i = 0; i < 4; i++)
    {
        gotoxy(48+i,12);
        bbranco;
        nulo;
    }
    gotoxy(49,12);
    preto;
    cin >> cadC.mes;

    for (int i = 0; i < 4; i++)
    {
        gotoxy(53+i,12);
        bbranco;
        nulo;
    }
    gotoxy(54,12);
    preto;
    cin >> cadC.ano;

    gotoxy(23,14);
    branco;
    bpreto;
    cout<<" SEXO ";

    for (int i = 0; i < 5; i++)
    {
        gotoxy(35+i,14);
        bbranco;
        nulo;
    }
    gotoxy(36,14);
    preto;
    cin>>cadC.sexo;

    gotoxy(23,16);
    branco;
    bpreto;
    cout<<" TELEFONE ";

    for (int i = 0; i < 15; i++)
    {
        gotoxy(35+i,16);
        bbranco;
        nulo;
    }
    gotoxy(36,16);
    preto;
    cin >> cadC.telefone;

    cadastro.write((const char*)(&cadC),sizeof(clientes));

    gotoxy(16,20);
    branco;
    bpreto;
    cout << " DESEJA CADASTRAR OUTRO CLIENTE (S/N) ";

    for (int i = 0; i < 3; i++)
    {
        gotoxy(56+i,20);
        bbranco;
        nulo;
    }
    gotoxy(58,16);
    preto;
    cin >> op;

    if( op == 'S' || op == 's')
    {
        cadastroClientes();
    }
    else
    {
        menuAtendente();
    }

    cadastro.close();

}

