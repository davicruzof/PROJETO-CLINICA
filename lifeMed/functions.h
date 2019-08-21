#include "interface.h"
#include <iostream>
#include <fstream>
#include <conio2.h>
#include <cstring>
#include <cstdlib>
#include <windows.h>
#include <stdio.h>
#include <time.h>

using namespace std;

void funcionarioCadastro();
void menuAdmin();
void valor();
void login();
void menuAtendente();
void valorAdmin();
void valorAtendente();
void help();
void cadastroClientes();
void buscaPaciente();
int idade(int dia,int mes, int ano);

struct cadastroDeFuncionarios
{
    char nome[50];
    char sexo;
    char telefone[11];
    int dia,mes,ano;
    char cargo[50];
    char cpf[11];
    char rg[15];
    float valorConsulta;
} cadF;

struct clientes
{
    char nome[50];
    char cpf[12];
    int dia;
    int mes;
    int ano;
    char sexo;
    char telefone[11];
} cadC;

void cadastroDoAdmin()
{
    int opc=0;

    tela();

    gotoxy(30,5);
    preto;
    bbranco;
    cout << " MENU CADASTRAR ";

    gotoxy(20,10);
    preto;
    bbranco;
    cout << " 1 - CADASTRAR FUNCIONARIOS ";

    gotoxy(20,12);
    preto;
    bbranco;
    cout << " 2 - CADASTRAR CLIENTES ";

    gotoxy(20,14);
    preto;
    bbranco;
    cout << " 3 - ALTERAR CADASTRO DE FUNCIONARIOS ";

    gotoxy(20,16);
    preto;
    bbranco;
    cout << " 4 - VOLTAR PARA O MENU ADMIN";

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
        gotoxy(20,10);
        branco;
        bvermelho;
        cout << " 1 - CADASTRAR FUNCIONARIOS ";
        Sleep(1500);
        funcionarioCadastro();
        break;

    case 2:
        gotoxy(20,12);
        branco;
        bvermelho;
        cout << " 2 - CADASTRAR CLIENTES ";
        Sleep(1500);
        cadastroClientes();
        break;
    case 4:
        gotoxy(20,10);
        branco;
        bvermelho;
        cout << " 4 - VOLTAR PARA O MENU ADMIN";
        Sleep(1500);
        menuAdmin();
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
    cout << " 4 - FAZER LOGOUT ";

    gotoxy(25,18);
    preto;
    bbranco;
    cout << " 5 - ENCERRAR O SISTEMA ";

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
        gotoxy(25,10);
        branco;
        bvermelho;
        cout << " 1 - CADASTRAR ";
        Sleep(2000);
        cadastroDoAdmin();
        break;

    case 2:
        gotoxy(25,12);
        branco;
        bvermelho;
        cout << " 2 - AGENDAMENTO ";
        Sleep(1500);
//      agendamento();
        break;

    case 3:
        gotoxy(25,14);
        branco;
        bvermelho;
        cout << " 3 - BUSCAR VALOR ";
        Sleep(1500);
        valorAtendente();
        break;

    case 4:
        login();
        break;

    case 5:
        exit(1);
        break;
    }
}

void menuMed()
{
    int opc=0;

    tela();

    gotoxy(30,5);
    preto;
    bbranco;
    cout << " MENU MEDICOS ";

    gotoxy(20,10);
    preto;
    bbranco;
    cout << " 1 - AGENDADOS ";

    gotoxy(20,12);
    preto;
    bbranco;
    cout << " 2 - BUSCAR DADOS DO PACIENTE ";

    gotoxy(20,14);
    preto;
    bbranco;
    cout << " 3 - FAZER LOGOUT ";

    gotoxy(20,16);
    preto;
    bbranco;
    cout << " 4 - ENCERRAR O SISTEMA ";

    for (int i = 0; i < 5; i++)
    {
        gotoxy(30+i,22);
        bbranco;
        nulo;
    }

    gotoxy(32,22);
    preto;
    cin >> opc;

    switch(opc)
    {
    case 1:
        gotoxy(20,10);
        branco;
        bvermelho;
        cout << " 1 - AGENDADOS ";
        Sleep(2000);
        cadastroDoAdmin();
        break;

    case 2:
        gotoxy(20,12);
        branco;
        bvermelho;
        cout << " 2 - BUSCAR DADOS DO PACIENTE ";
        buscaPaciente();
        Sleep(2000);

        break;

    case 3:
        login();
        break;

    case 4:
        gotoxy(20,16);
        branco;
        bvermelho;
        cout << " 4 - ENCERRAR O SISTEMA ";
        Sleep(1500);
        system("cls");
        exit(1);
        break;
    }
}

void funcionarioCadastro()
{
    char novoCad;

    ofstream cadastroFuncionario ("funcionarios.txt", ios::ate | ios::app);
    if(cadastroFuncionario.fail())
    {
        cout << " ERRO AO ABRIR ARQUIVO";
        exit(1);
    }

    do
    {
        tela();

        gotoxy(30,5);
        branco;
        bpreto;
        cout << " CADASTRO DE FUNCIONARIOS ";

        gotoxy(23,8);
        branco;
        bpreto;
        cout << " NOME ";

        for (int i = 0; i < 25; i++)
        {
            gotoxy(30+i,8);
            bbranco;
            nulo;
        }
        gotoxy(32,8);
        preto;
        fflush(stdin);
        cin.getline(cadF.nome,80);

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
        fflush(stdin);
        cin.getline(cadF.cargo,50);

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

        if(cadF.dia > 0)
        {
            for (int i = 0; i < 4; i++)
            {
                gotoxy(48+i,16);
                bbranco;
                nulo;
            }
            gotoxy(49,16);
            preto;
            cin >> cadF.mes;

            if(cadF.mes)
            {
                for (int i = 0; i < 6; i++)
                {
                    gotoxy(54+i,16);
                    bbranco;
                    nulo;
                }
                gotoxy(55,16);
                preto;
                cin >> cadF.ano;
            }
        }

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

    }
    while(novoCad == 'S' || novoCad == 's');

    cadastroFuncionario.close();

    menuAdmin();


}

void valorAdmin()
{

    char especialidade[50];
    int i;
    char opc;

    ifstream busca("funcionarios.txt");

    if(busca.fail())
    {
        exit(1);
    }


    do
    {

        tela();

        gotoxy(30,5);
        preto;
        bbranco;
        cout << " BUSCAR VALOR ";

        gotoxy(17,10);
        preto;
        bbranco;
        cout << " INFORME ESPECIALIDADE OU NOME DO MEDICO ";

        for (i = 0; i < 25; i++)
        {
            gotoxy(17+i,12);
            bbranco;
            nulo;
        }

        gotoxy(19,12);
        preto;
        fflush(stdin);
        cin.getline(especialidade,50);

        busca.read((char *)(&cadF),sizeof(cadastroDeFuncionarios));

        i=0;
        int j=0;

        while(busca && !busca.eof())
        {
            if((strcmp(especialidade,cadF.cargo) == 0 ) || (strcmp(especialidade,cadF.nome) == 0))
            {
                gotoxy(20,14+j);
                preto;
                bbranco;
                cout << " DR. " << cadF.nome << " | " << cadF.cargo ;
                if(i==0)
                {
                    gotoxy(20,15+i);
                    preto;
                    bbranco;
                    cout << " VALOR DA CONSULTA -  " << cadF.valorConsulta ;
                    i++;
                }
                else
                {
                    gotoxy(20,15+j);
                    preto;
                    bbranco;
                    cout << " VALOR DA CONSULTA -  " << cadF.valorConsulta ;
                }
                j+=2;
            }
            busca.read((char *)(&cadF),sizeof(cadastroDeFuncionarios));
        }

        busca.close();

        gotoxy(18,26);
        preto;
        bbranco;
        cout << " DESEJA REALIZAR OUTRA CONSULTA (S/N) ";

        for (i = 0; i < 4; i++)
        {
            gotoxy(56+i,26);
            bbranco;
            nulo;
        }

        gotoxy(58,26);
        preto;
        fflush(stdin);
        cin >> opc;

    }
    while(opc == 's' || opc == 'S');

    menuAdmin();

}

void valorAtendente()
{

    char especialidade[50];
    int i;
    char opc;

    ifstream busca("funcionarios.txt");

    if(busca.fail())
    {
        exit(1);
    }


    do
    {

        tela();

        gotoxy(30,5);
        preto;
        bbranco;
        cout << " BUSCAR VALOR ";

        gotoxy(17,10);
        preto;
        bbranco;
        cout << " INFORME ESPECIALIDADE OU NOME DO MEDICO ";

        for (i = 0; i < 25; i++)
        {
            gotoxy(17+i,12);
            bbranco;
            nulo;
        }

        gotoxy(19,12);
        preto;
        fflush(stdin);
        cin.getline(especialidade,50);

        busca.read((char *)(&cadF),sizeof(cadastroDeFuncionarios));

        i=0;
        int j=0;

        while(busca && !busca.eof())
        {
            if((strcmp(especialidade,cadF.cargo) == 0 ) || (strcmp(especialidade,cadF.nome) == 0))
            {
                gotoxy(20,14+j);
                preto;
                bbranco;
                cout << " DR. " << cadF.nome << " | " << cadF.cargo ;
                if(i==0)
                {
                    gotoxy(20,15+i);
                    preto;
                    bbranco;
                    cout << " VALOR DA CONSULTA -  " << cadF.valorConsulta ;
                    i++;
                }
                else
                {
                    gotoxy(20,15+j);
                    preto;
                    bbranco;
                    cout << " VALOR DA CONSULTA -  " << cadF.valorConsulta ;
                }
                j+=2;
            }
            busca.read((char *)(&cadF),sizeof(cadastroDeFuncionarios));
        }

        busca.close();

        gotoxy(18,26);
        preto;
        bbranco;
        cout << " DESEJA REALIZAR OUTRA CONSULTA (S/N) ";

        for (i = 0; i < 4; i++)
        {
            gotoxy(56+i,26);
            bbranco;
            nulo;
        }

        gotoxy(58,26);
        preto;
        fflush(stdin);
        cin >> opc;

    }
    while(opc == 's' || opc == 'S');

    menuAtendente();

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
    cout << " 4 - Help | AJUDA ";

    gotoxy(25,18);
    preto;
    bbranco;
    cout << " 5 - FAZER LOGOUT ";

    gotoxy(25,20);
    preto;
    bbranco;
    cout << " 6 - ENCERRAR O SISTEMA ";

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
        gotoxy(25,10);
        branco;
        bvermelho;
        cout << " 1 - CADASTRAR CLIENTES ";
        Sleep(1500);
        limpaHelp();
        cadastroClientes();
        break;

    case 2:
        gotoxy(25,12);
        branco;
        bvermelho;
        cout << " 2 - AGENDAMENTO ";
        Sleep(1500);
        limpaHelp();
        break;

    case 3:
        gotoxy(25,14);
        branco;
        bvermelho;
        cout << " 3 - BUSCAR VALOR ";
        Sleep(1500);
        limpaHelp();
        valorAtendente();
        break;

    case 4:
        gotoxy(25,16);
        branco;
        bvermelho;
        cout << " 4 - Help | AJUDA ";
        Sleep(1500);
        telaHelp();
        help();
        break;

    case 5:
        gotoxy(25,18);
        branco;
        bvermelho;
        cout << " 5 - FAZER LOGOUT ";
        Sleep(1500);
        limpaHelp();
        login();
        break;
    case 6:
        gotoxy(25,20);
        branco;
        bvermelho;
        cout << " 6 - ENCERRAR O SISTEMA ";
        Sleep(1500);
        system("cls");
        exit(1);
        break;
    }
}

void help()
{

    string aux;
    int i=0;

    ifstream help("helpAtendente.txt");

    if(help.fail())
    {
        menuAtendente();
    }

    while(!help.eof())
    {
        getline(help,aux);
        gotoxy(84,2+i);
        preto;
        bbranco;
        cout << aux;
        i++;

    }
    help.close();
    getchar();
    menuAtendente();
}


void cadastroClientes()
{
    char op;

    ofstream cadastro("clientes.txt", ios::out | ios::app);

    if(!cadastro.is_open())
    {
        cout<<"ERRO AO ABRIR ARQUIVO"<<endl;
        exit(1);
    }

    do
    {
        tela();

        gotoxy(30,5);
        branco;
        bpreto;
        cout << " CADASTRO DE PACIENTES ";

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
        fflush(stdin);
        cin.getline(cadC.nome,50);

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
        cin.getline(cadC.cpf,11);

        gotoxy(23,12);
        branco;
        bpreto;
        cout<<" DATA DE NASCIMENTO ";

        int n=1;
        do
        {
            for (int i = 0; i < 4; i++)
            {
                gotoxy(43+i,12);
                bbranco;
                nulo;
            }
            gotoxy(44,12);
            preto;
            cin>>cadC.dia ;

            if(cadC.dia<0 || cadC.dia >31)
            {
                n++;
            }
            n--;
        }
        while(n>0);

        n=1;

        do
        {
            for (int i = 0; i < 4; i++)
            {
                gotoxy(48+i,12);
                bbranco;
                nulo;
            }
            gotoxy(49,12);
            preto;
            cin >> cadC.mes;

            if(cadC.mes<0 || cadC.mes > 12)
            {
                n++;
            }
            n--;
        }
        while(n>0);

        n=1;

        do
        {
            for (int i = 0; i < 4; i++)
        {
            gotoxy(53+i,12);
            bbranco;
            nulo;
        }
        gotoxy(54,12);
        preto;
        cin >> cadC.ano;

            if(cadC.ano<0 || cadC.ano < 1870)
            {
                n++;
            }
            n--;
        }
        while(n>0);

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
        cout << " DESEJA CADASTRAR OUTRO PACIENTES (S/N) ";

        for (int i = 0; i < 3; i++)
        {
            gotoxy(56+i,20);
            bbranco;
            nulo;
        }
        gotoxy(58,20);
        preto;
        cin >> op;

    }
    while( op == 'S' || op == 's');

    cadastro.close();

    menuAtendente();

}


void buscaPaciente()
{
    ifstream buscaCliente("clientes.txt");

    if(buscaCliente.eof())
    {
        menuMed();
    }

    char nome[50],cpf[11];

    tela();

    gotoxy(30,5);
    branco;
    bpreto;
    cout << " DADOS DE PACIENTES ";

    gotoxy(23,8);
    branco;
    bpreto;
    cout<<" INFORME O NOME DO PACIENTE ";

    for (int i = 0; i < 20; i++)
    {
        gotoxy(23+i,10);
        bbranco;
        nulo;
    }
    gotoxy(24,10);
    preto;
    fflush(stdin);
    cin.getline(nome,50);

    gotoxy(23,12);
    branco;
    bpreto;
    cout<<" INFORME O CPF ";

    for (int i = 0; i < 20; i++)
    {
        gotoxy(23+i,14);
        bbranco;
        nulo;
    }
    gotoxy(24,14);
    preto;
    cin.getline(cpf,11);

    buscaCliente.read((char *)(&cadC),sizeof(clientes));

    while(buscaCliente && !buscaCliente.eof())
    {
        if((strcmp(nome,cadC.nome) == 0 ) && (strcmp(cpf,cadC.cpf) == 0))
        {
            tela();
            gotoxy(30,5);
            branco;
            bpreto;
            cout << " DADOS DE PACIENTES ";
            gotoxy(23,12);
            branco;
            bpreto;
            cout <<" NOME DO PACIENTE ";
            gotoxy(43,12);
            preto;
            bbranco;
            cout << cadC.nome;
            gotoxy(23,14);
            branco;
            bpreto;
            cout <<" SEXO ";
            gotoxy(31,14);
            preto;
            bbranco;
            cout << cadC.sexo;
            gotoxy(23,16);
            branco;
            bpreto;
            cout<<" IDADE " ;
            gotoxy(32,16);
            preto;
            bbranco;
            cout << idade(cadC.dia,cadC.mes,cadC.ano);
            gotoxy(23,18);
            branco;
            bpreto;
            cout <<" TELEFONE " ;
            gotoxy(35,18);
            preto;
            bbranco;
            cout << cadC.telefone;

        }
        buscaCliente.read((char *)(&cadC),sizeof(clientes));
    }

    getchar();
    menuMed();

}

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

int idade(int dia,int mes, int ano)
{

    char dateStr[9];

    _strdate(dateStr);

    Data atual;

    ParseData(dateStr, &atual);

    int a = atual.ano + 2000;
    int b = atual.dia;
    int c = atual.mes;

    if(mes == c)
    {
        if(dia == b)
        {
            return (a-ano);
        }
        else
        {
            return ((a-1)-ano);
        }
    }
    else
    {
        if(mes > c)
        {
            return ((a-1)-ano);
        }
        else
        {
            return (a-ano);
        }
    }

}
