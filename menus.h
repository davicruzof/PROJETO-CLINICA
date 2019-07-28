#include <iostream>
#include <fstream>
#include <conio2.h>
#include <cstring>
#include <cstdlib>
#include <stdio.h>
#include "cores.h"

using namespace std;

void cadastroClientes();

struct cadastroDeFuncionarios
{
    char nome[80];
    char sexo;
    char telefone[11];
    int dia,mes,ano;
    char cargo[50];
    char cpf[11];
    char rg[15];
    float valorConsulta;
};


struct clientes
{
    char nome[80];
    char cpf[12];
    int dia;
    int mes;
    int ano;
    char sexo;
    char endereco[100];
    char telefone[11];
};

clientes cadC;

cadastroDeFuncionarios cadF;

void funcionarioCadastro();

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

void agendamento();

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
        agendamento();
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

        for (int i = 0; i < 20; i++)
        {
            gotoxy(35+i,8);
            bbranco;
            nulo;
        }
        gotoxy(36,8);
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

    }
    while(novoCad == 'S' || novoCad == 's');

    menuAdmin();

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

    gotoxy(25,18);
    preto;
    bbranco;
    cout << " 5 - Help | AJUDA ";

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
        limpaHelp();
        cadastroClientes();
        break;

    case 2:
        break;

    case 3:
        break;

    case 4:
        exit(1);
        break;
    case 5:
        string ajuda;
        int i=0;
        telaHelp();
        ifstream help("helpAtendente.txt");
        while(!help.eof())
        {
            while(getline(help,ajuda))
            {
                gotoxy(84,2+i);
                preto;
                bbranco;
                cout << ajuda;
                i++;
            }
        }
        getchar();
        menuAtendente();
        help.close();
        break;
    }
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
        fflush(stdin);
        cin.getline(cadC.nome,80);

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
        gotoxy(58,20);
        preto;
        cin >> op;

    }
    while( op == 'S' || op == 's');

    cadastro.close();

    menuAtendente();

}


//void agendamento()
//{
//
//    char nome[80],nomeMed[80];
//
//    ifstream lercad("clientes.txt");
//    ifstream lercadF("funcionarios.txt");
//
//
//    if(lercad.fail())
//    {
//        exit(1);
//    }
//
//    if(lercadF.fail())
//    {
//        exit(1);
//    }
//
//    tela();
//
//    gotoxy(30,5);
//    branco;
//    bpreto;
//    cout << " AGENDAMENTO DE CONSULTA ";
//
//    gotoxy(23,8);
//    branco;
//    bpreto;
//    cout << " NOME ";
//
//    for (int i = 0; i < 20; i++)
//    {
//        gotoxy(35+i,8);
//        bbranco;
//        nulo;
//    }
//    gotoxy(36,8);
//    preto;
//    fflush(stdin);
//    cin.getline(nome,80);
//
//    int tam=0;
//
//    tam = strlen(nome);
//
//    lercad.read((char *)(&cadC),sizeof(clientes));
//
//    while(!lercad.eof())
//    {
//        if(strcmp(nome,cadC.nome))
//        {
//            gotoxy(23,10);
//            branco;
//            bpreto;
//            cout << " NOME DO MEDICO ";
//
//            for (int i = 0; i < 20; i++)
//            {
//                gotoxy(50+i,10);
//                bbranco;
//                nulo;
//            }
//            gotoxy(51,10);
//            preto;
//            fflush(stdin);
//            cin.getline(nomeMed,80);
//
//            lercadF.read((char *)(&cadF),sizeof(cadastroDeFuncionarios));
//
//            while(!lercadF.eof())
//            {
//                if(strcmp(nomeMed,cadF.nome))
//                {
//
//                    ofstream agenda("DR.txt",ios::app);
//
//                    agenda << "=====================================================\n";
//                    agenda << "|\t\t\t\t\t\t|\n";
//                    agenda << "|\t\t CLIN MED + |\n";
//                    agenda << "|\t\t\t\t\t\t|\n";
//                    agenda << "=====================================================\n";
//                    agenda << "| CLIENTE : " << nome << '\n';
//                    agenda << "| SEXO : " << cadC.sexo << '\n';
//                    agenda << "| IDADE : 32 " << '\n';
//                    agenda << "| SERVICO : CONSULTA " << '\n';
//                    agenda << "| MEDICO : DR. " << nomeMed << '\n';
//                    agenda << "| DATA DA CONSULTA : 24 | 02 | 2019 " << '\n';
//
//                    menuAdmin;
//
//                    agenda.close();
//                    lercad.close();
//                    lercadF.close();
//
//                }
//                lercadF.read((char *)(&cadC),sizeof(clientes));
//            }
//            menuAdmin();
//        }
//        lercad.read((char *)(&cadC),sizeof(clientes));
//    }
//
//}
