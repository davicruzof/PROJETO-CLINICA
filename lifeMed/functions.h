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
void buscaPaciente(char* medico,char* crm,char* telefone);
void receita(char* medico,char* crm,char* telefone);
int idade(int dia,int mes, int ano);

struct Data
{
    int dia;
    int mes;
    int ano;
};

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
    case 3:
        gotoxy(20,14);
        branco;
        bvermelho;
        cout << " 3 - ALTERAR CADASTRO DE FUNCIONARIOS ";
        Sleep(1500);
        break;
    case 4:
        gotoxy(20,16);
        branco;
        bvermelho;
        cout << " 4 - VOLTAR PARA O MENU ADMIN";
        Sleep(1500);
        menuAdmin();
        break;
    default:
        gotoxy(25,27);
        branco;
        bvermelho;
        cout << " OPCAO INVALIDA ";
        Sleep(2000);
        cadastroDoAdmin();
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
    cout << " 4 - FAZER LOGOFF ";

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
        Sleep(1500);
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
        valorAdmin();
        break;

    case 4:
        gotoxy(25,14);
        branco;
        bvermelho;
        cout << " 4 - FAZER LOGOFF ";
        Sleep(1500);
        login();
        break;

    case 5:
        system("cls");
        exit(1);
        break;
    default:
        gotoxy(25,27);
        branco;
        bvermelho;
        cout << " OPCAO INVALIDA ";
        Sleep(2000);
        menuAdmin();
        break;
    }
}

void menuMed(char* medico, char* crm,char* telefone)
{
    int opc=0;

    tela();

    gotoxy(25,5);
    preto;
    bbranco;
    cout << " DR. " << medico;


    gotoxy(25,6);
    branco;
    bvermelho;
    cout << " CRM " << crm;

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
    cout << " 3 - GERAR RECEITA ";

    gotoxy(20,16);
    preto;
    bbranco;
    cout << " 4 - FAZER LOGOFF ";

    gotoxy(20,18);
    preto;
    bbranco;
    cout << " 5 - ENCERRAR O SISTEMA ";

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
        limpaHelp();
        Sleep(1500);
        break;

    case 2:
        gotoxy(20,12);
        branco;
        bvermelho;
        cout << " 2 - BUSCAR DADOS DO PACIENTE ";
        limpaHelp();
        buscaPaciente(medico,crm,telefone);
        Sleep(1500);
        break;

    case 3:
        gotoxy(20,14);
        branco;
        bvermelho;
        cout << " 3 - GERAR RECEITA ";
        limpaHelp();
        Sleep(1500);
        receita(medico,crm,telefone);
        break;

    case 4:
        gotoxy(20,16);
        branco;
        bvermelho;
        cout << " 4 - FAZER LOGOFF  ";
        limpaHelp();
        Sleep(1500);
        login();
        break;

    case 5:
        gotoxy(20,18);
        branco;
        bvermelho;
        cout << " 5 - ENCERRAR O SISTEMA ";
        limpaHelp();
        Sleep(1500);
        system("cls");
        exit(1);
        break;
    default:
        gotoxy(25,27);
        branco;
        bvermelho;
        cout << " OPCAO INVALIDA ";
        limpaHelp();
        Sleep(2000);
        menuMed(medico,crm,telefone);
        break;
    }
    menuMed(medico,crm,telefone);
}

void funcionarioCadastro()
{
    char novoCad;
    int n=1,x=0;

    char dateStr[9];

    _strdate(dateStr);

    Data atual;

    ParseData(dateStr, &atual);

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

        gotoxy(18,8);
        branco;
        bpreto;
        cout << " NOME ";

        do
        {
            for (int i = 0; i < 30; i++)
            {
                gotoxy(26+i,8);
                bbranco;
                nulo;
            }
            gotoxy(27,8);
            preto;
            fflush(stdin);
            cin.getline(cadF.nome,50);

            x = strlen(cadF.nome);

            if(x > 50)
            {
                n++;
            }
            n--;
        }
        while(n>0);

        gotoxy(18,10);
        branco;
        bpreto;
        cout << " TELEFONE ";

        n=1;
        do
        {
            for (int i = 0; i < 15; i++)
            {
                gotoxy(30+i,10);
                bbranco;
                nulo;
            }
            gotoxy(31,10);
            preto;
            cin >> cadF.telefone;

            x = 0;

            x = strlen(cadF.telefone);

            if(x > 11 || x < 11)
            {
                n++;
            }
            n--;
        }
        while(n>0);

        gotoxy(18,12);
        branco;
        bpreto;
        cout << " ESPECIALIDADE ";

        n=1;
        do
        {
            for (int i = 0; i < 25; i++)
            {
                gotoxy(35+i,12);
                bbranco;
                nulo;
            }
            gotoxy(36,12);
            preto;
            fflush(stdin);
            cin.getline(cadF.cargo,50);

            x = 0;

            x = strlen(cadF.cargo);

            if(x > 50)
            {
                n++;
            }
            n--;
        }
        while(n>0);

        gotoxy(18,14);
        branco;
        bpreto;
        cout << " SEXO ";


        for (int i = 0; i < 15; i++)
        {
            gotoxy(26+i,14);
            bbranco;
            nulo;
        }
        gotoxy(27,14);
        preto;
        fflush(stdin);
        cin.getline(cadF.sexo,20);

        if(strcmp(cadF.sexo,"masculino") == 0 || strcmp(cadF.sexo,"M") == 0 || strcmp(cadF.sexo,"m") == 0 )
        {
            gotoxy(43,14);
            branco;
            bazul;
            cout << " \xb ";
        }

        if(strcmp(cadF.sexo,"feminino") == 0 || strcmp(cadF.sexo,"F") == 0 || strcmp(cadF.sexo,"f") == 0 )
        {
            gotoxy(43,14);
            branco;
            bvermelho;
            cout << " \xc ";
        }

        gotoxy(18,16);
        branco;
        bpreto;
        cout << " DATA DE NASCIMENTO ";

        n=1;
        do
        {
            for (int i = 0; i < 4; i++)
            {
                gotoxy(40+i,16);
                bbranco;
                nulo;
            }
            gotoxy(41,16);
            preto;
            cin >> cadF.dia;
            if(cadF.dia<0 || cadF.dia >31)
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
                gotoxy(45+i,16);
                bbranco;
                nulo;
            }
            gotoxy(46,16);
            preto;
            cin >> cadF.mes;
            if(cadF.mes == 2 && cadF.dia > 28 )
            {
                for (int i = 0; i < 4; i++)
                {
                    gotoxy(40+i,16);
                    bbranco;
                    nulo;
                }
                gotoxy(41,16);
                preto;
                cin >> cadF.dia;
            }
            else
            {
                if(cadF.mes < 0 || cadF.mes > 12 )
                {
                    n++;
                }
            }
            n--;
        }
        while(n>0);
        n=1;

        do
        {
            for (int i = 0; i < 6; i++)
            {
                gotoxy(50+i,16);
                bbranco;
                nulo;
            }
            gotoxy(51,16);
            preto;
            cin >> cadF.ano;

            if((((atual.ano + 2000) - cadF.ano) < 18) || (((atual.ano + 2000) - cadF.ano) > 80))
            {
                n++;
            }
            n--;
        }
        while(n>0);

        gotoxy(18,18);
        branco;
        bpreto;
        cout << " CPF ";

        n=1;

        do
        {
            for (int i = 0; i < 15; i++)
            {
                gotoxy(25+i,18);
                bbranco;
                nulo;
            }
            gotoxy(26,18);
            preto;
            cin >> cadF.cpf;

            x = 0;

            x = strlen(cadF.cpf);

            if(x < 11 || x > 11 )
            {
                n++;
            }
            n--;
        }
        while(n>0);

        gotoxy(18,20);
        branco;
        bpreto;
        cout << " RG ";

        n=1;

        do
        {
            for (int i = 0; i < 15; i++)
            {
                gotoxy(25+i,20);
                bbranco;
                nulo;
            }
            gotoxy(26,20);
            preto;
            cin >> cadF.rg;

            x = 0;

            x = strlen(cadF.rg);

            if(x < 4 || x > 15)
            {
                n++;
            }
            n--;
        }
        while(n>0);

        gotoxy(18,22);
        branco;
        bpreto;
        cout << " CRM ";

        n=1;

        do
        {
            for (int i = 0; i < 10; i++)
            {
                gotoxy(25+i,22);
                bbranco;
                nulo;
            }
            gotoxy(26,22);
            preto;
            cin >> cadF.crm;

            x = 0;

            x = strlen(cadF.crm);

            if(x > 7 || x < 3)
            {
                n++;
            }
            n--;
        }
        while(n>0);

        gotoxy(18,24);
        branco;
        bpreto;
        cout << " VALOR DA CONSULTA ";

        n=1;

        do
        {
            for (int i = 0; i < 10; i++)
            {
                gotoxy(39+i,24);
                bbranco;
                nulo;
            }
            gotoxy(40,24);
            preto;
            cin >> cadF.valorConsulta;
            if(cadF.valorConsulta < 50)
            {
                n++;
            }
            n--;
        }
        while(n>0);

        cadastroFuncionario.write((const char*)(&cadF),sizeof(cadastroDeFuncionarios));

        gotoxy(16,26);
        branco;
        bpreto;
        cout << " DESEJA CADASTRAR NOVO FUNCIONARIO (S/N) ";

        for (int i = 0; i < 3; i++)
        {
            gotoxy(57+i,26);
            bbranco;
            nulo;
        }
        gotoxy(58,26);
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

    do
    {
        ifstream busca("funcionarios.txt");

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
                    cout << " VALOR DA CONSULTA - R\x24 " << cadF.valorConsulta ;
                    i++;
                }
                else
                {
                    gotoxy(20,15+j);
                    preto;
                    bbranco;
                    cout << " VALOR DA CONSULTA - R\x24 " << cadF.valorConsulta ;
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

    do
    {

        ifstream busca("funcionarios.txt");

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
                    cout << " VALOR DA CONSULTA - R\x24: " << cadF.valorConsulta ;
                    i++;
                }
                else
                {
                    gotoxy(20,15+j);
                    preto;
                    bbranco;
                    cout << " VALOR DA CONSULTA - R\x24: " << cadF.valorConsulta ;
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
    menuAtendente();
}

void help()
{

    string aux;
    int i=0;

    ifstream help("helpAtendente.txt");

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

    int n=1,x=0;

    char dateStr[9];

    _strdate(dateStr);

    Data atual;

    ParseData(dateStr, &atual);

    ofstream cadastro("clientes.txt", ios::out | ios::app);

    do
    {
        tela();

        gotoxy(30,5);
        branco;
        bpreto;
        cout << " CADASTRO DE PACIENTES ";

        gotoxy(18,8);
        branco;
        bpreto;
        cout<<" NOME ";

        do
        {
            for (int i = 0; i < 30; i++)
            {
                gotoxy(26+i,8);
                bbranco;
                nulo;
            }
            gotoxy(27,8);
            preto;
            fflush(stdin);
            cin.getline(cadC.nome,50);

            x = strlen(cadC.nome);

            if(x > 50)
            {
                n++;
            }
            n--;
        }
        while(n>0);

        gotoxy(18,10);
        branco;
        bpreto;
        cout<<" CPF ";

        n=1;
        do
        {
            for (int i = 0; i < 20; i++)
            {
                gotoxy(25+i,10);
                bbranco;
                nulo;
            }
            gotoxy(26,10);
            preto;
            cin.getline(cadC.cpf,12);

            x = 0;

            x = strlen(cadC.cpf);

            if(x > 11 || x < 11)
            {
                n++;
            }
            n--;
        }
        while(n>0);

        gotoxy(18,12);
        branco;
        bpreto;
        cout<<" DATA DE NASCIMENTO ";

        int n=1;
        do
        {
            for (int i = 0; i < 4; i++)
            {
                gotoxy(40+i,12);
                bbranco;
                nulo;
            }
            gotoxy(41,12);
            preto;
            cin>>cadC.dia ;

            if(cadC.dia < 0 || cadC.dia > 31)
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
                gotoxy(45+i,12);
                bbranco;
                nulo;
            }
            gotoxy(46,12);
            preto;
            cin >> cadC.mes;

            if(cadC.mes == 2 && cadC.dia > 28 )
            {
                for (int i = 0; i < 4; i++)
                {
                    gotoxy(40+i,12);
                    bbranco;
                    nulo;
                }
                gotoxy(41,12);
                preto;
                cin>>cadC.dia ;
            }
            else
            {
                if(cadC.mes < 0 || cadC.mes > 12)
                {
                    n++;
                }
            }
            n--;
        }
        while(n>0);

        n=1;

        do
        {
            for (int i = 0; i < 6; i++)
            {
                gotoxy(50+i,12);
                bbranco;
                nulo;
            }
            gotoxy(51,12);
            preto;
            cin >> cadC.ano;
            if(cadC.ano < 1900)
            {
                n++;
            }
            else
            {
                if(cadC.mes > atual.mes && cadC.ano > (atual.ano + 2000))
                {
                    n++;
                }
                else
                {
                    if(cadC.dia > atual.dia && cadC.mes == atual.mes && cadC.ano > (atual.ano + 2000))
                    {
                        n++;
                    }
                }
            }
            n--;
        }
        while(n>0);

        gotoxy(18,14);
        branco;
        bpreto;
        cout<<" SEXO ";

        for (int i = 0; i < 20; i++)
        {
            gotoxy(26+i,14);
            bbranco;
            nulo;
        }
        gotoxy(27,14);
        preto;
        fflush(stdin);
        cin.getline(cadC.sexo,20);

        if(strcmp(cadC.sexo,"masculino") == 0 || strcmp(cadC.sexo,"M") == 0 || strcmp(cadC.sexo,"m") == 0 )
        {
            gotoxy(43,14);
            branco;
            bazul;
            cout << " \xb ";
        }

        if(strcmp(cadC.sexo,"feminino") == 0 || strcmp(cadC.sexo,"F") == 0 || strcmp(cadC.sexo,"f") == 0 )
        {
            gotoxy(43,14);
            branco;
            bvermelho;
            cout << " \xc ";
        }

        gotoxy(18,16);
        branco;
        bpreto;
        cout<<" TELEFONE ";

        n=1;
        do
        {
            for (int i = 0; i < 15; i++)
            {
                gotoxy(30+i,16);
                bbranco;
                nulo;
            }
            gotoxy(31,16);
            preto;
            cin >> cadC.telefone;

            x = 0;

            x = strlen(cadC.telefone);

            if(x > 11 || x < 11)
            {
                n++;
            }
            n--;
        }
        while(n>0);

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

void buscaPaciente(char* medico, char* crm,char* telefone)
{
    ifstream buscaCliente("clientes.txt");

    char nome[50],cpf[12];
    int n=1,x=0;

    tela();

    gotoxy(30,5);
    branco;
    bpreto;
    cout << " DADOS DE PACIENTES ";

    gotoxy(18,8);
    branco;
    bpreto;
    cout<<" INFORME O NOME DO PACIENTE ";

    do
    {
        for (int i = 0; i < 30; i++)
        {
            gotoxy(18+i,10);
            bbranco;
            nulo;
        }
        gotoxy(19,10);
        preto;
        fflush(stdin);
        cin.getline(nome,50);

        x = strlen(nome);

        if(x > 50)
        {
            n++;
        }
        n--;
    }
    while(n>0);

    gotoxy(18,12);
    branco;
    bpreto;
    cout<<" INFORME O CPF ";

    n=1;
    do
    {
        for (int i = 0; i < 15; i++)
        {
            gotoxy(18+i,14);
            bbranco;
            nulo;
        }
        gotoxy(19,14);
        preto;
        cin >> cpf;
        x = 0;

        x = strlen(cpf);

        if(x > 11 || x < 11)
        {
            n++;
        }
        n--;
    }
    while(n>0);

    buscaCliente.read((char *)(&cadC),sizeof(clientes));

    while(!buscaCliente.eof())
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
            if(strcmp(cadC.sexo,"masculino") == 0 || strcmp(cadC.sexo,"M") == 0 || strcmp(cadC.sexo,"m") == 0 )
            {
                gotoxy(43,14);
                branco;
                bazul;
                cout << " \xb ";
            }

            if(strcmp(cadC.sexo,"feminino") == 0 || strcmp(cadC.sexo,"F") == 0 || strcmp(cadC.sexo,"f") == 0 )
            {
                gotoxy(43,14);
                branco;
                bvermelho;
                cout << " \xc ";
            }
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
    menuMed(medico,crm,telefone);

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

void receita(char* medico,char* crm,char* telefone)
{
    ifstream paciente("clientes.txt");

    char nome[50],cpf[12],remedio[50];
    int n=1,x=0;

    char dateStr[9];

    _strdate(dateStr);

    Data atual;

    ParseData(dateStr, &atual);

    tela();

    gotoxy(30,5);
    branco;
    bpreto;
    cout << " GERAR RECEITUARIO ";

    gotoxy(18,8);
    branco;
    bpreto;
    cout<<" INFORME O NOME DO PACIENTE ";

    do
    {
        for (int i = 0; i < 30; i++)
        {
            gotoxy(18+i,10);
            bbranco;
            nulo;
        }
        gotoxy(19,10);
        preto;
        fflush(stdin);
        cin.getline(nome,50);

        x = strlen(nome);

        if(x > 50)
        {
            n++;
        }
        n--;
    }
    while(n>0);

    gotoxy(18,12);
    branco;
    bpreto;
    cout<<" INFORME O CPF ";

    n=1;
    do
    {
        for (int i = 0; i < 15; i++)
        {
            gotoxy(18+i,14);
            bbranco;
            nulo;
        }
        gotoxy(19,14);
        preto;
        cin >> cpf;
        x = 0;

        x = strlen(cpf);

        if(x > 11 || x < 11)
        {
            n++;
        }
        n--;
    }
    while(n>0);

    paciente.read((char *)(&cadC),sizeof(clientes));

    while(!paciente.eof())
    {
        if((strcmp(nome,cadC.nome) == 0 ) && (strcmp(cpf,cadC.cpf) == 0))
        {
            char arq[15];
            sprintf(arq,"%s.txt",cpf);

            ofstream receituario(arq,ios::app);

            receituario << "\n\t\t LIFEMED \n"
                        << "\t\t RECEITUARIO \n\n"
                        << "\t PACIENTE: " << cadC.nome << "\n"
                        << "\t SEXO: " << cadC.sexo << "\t" << " IDADE: " << idade(cadC.dia,cadC.mes,cadC.ano) << "\n\n\n\n\n\n";

            int z;
            gotoxy(18,16);
            preto;
            bbranco;
            cout << " INFORME A QUANTIDADE DE MEDICAMENTOS ";
            for (int i = 0; i < 3; i++)
            {
                gotoxy(58+i,16);
                bbranco;
                nulo;
            }
            gotoxy(59,16);
            preto;
            cin >> z;
            gotoxy(18,18);
            preto;
            bbranco;
            cout << " INFORME OS MEDICAMENTOS ";
            for(int j=1; j<=z; j++)
            {
                for (int i = 0; i < 15; i++)
                {
                    gotoxy(18+i,19+j);
                    bbranco;
                    nulo;
                }
                gotoxy(19,19+j);
                preto;
                fflush(stdin);
                cin.getline(remedio,50);
                receituario << " - " << remedio << "\n";
            }
            receituario << "\n\n\n\n\n Dr. " << medico << "\n"
                        << " CRM: " << crm << "\n"
                        << " TELEFONE: " << telefone << "\n"
                        << " DATA: " << atual.dia << " / " << atual.mes << " / " << atual.ano;
            receituario.close();

            string aux;
            int i=0;
            ifstream receita(arq);
            telaHelp();
            while(!receita.eof())
            {
                getline(receita,aux);
                gotoxy(84,2+i);
                preto;
                bbranco;
                cout << aux;
                i++;

            }
            system(arq);
        }
        paciente.read((char *)(&cadC),sizeof(clientes));
    }
    menuMed(medico,crm,telefone);
}
