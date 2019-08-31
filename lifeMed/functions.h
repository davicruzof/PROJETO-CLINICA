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
using namespace data;
using namespace cadastros;
typedef cadastroDeFuncionarios* CadP;

void troco(int valor);
void pagamento(int acesso,char * nome,char * nomeMed, char * cargo, float valorConsulta);
void funcionarioCadastro(int acesso);
void menuAdmin(int acesso);
void valor();
void login(int acesso);
void menuAtendente(int acesso);
void valorAdmin(int acesso);
void valorAtendente(int acesso);
void help(int acesso);
void agendamento(int acesso);
void agendamentoPacientes(char * crm);
void cadastroClientes(int acesso);
void buscaPaciente(char* medico,char* crm,char* telefone,int acesso);
void receita(char* medico,char* crm,char* telefone,int acesso);
int idade(int dia,int mes, int ano);
void zero();
void Menualterar(int acesso);
void abreFecha(int acesso);
int number_func();
void ExibirFuncionario(int acesso);
void RemoverFunc(CadP cadastro,int acesso);

void cadastroDoAdmin(int acesso)
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

    for (int i = 0; i < 3; i++)
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
        funcionarioCadastro(acesso);
        break;

    case 2:
        gotoxy(20,12);
        branco;
        bvermelho;
        cout << " 2 - CADASTRAR CLIENTES ";
        Sleep(1500);
        cadastroClientes(acesso);
        break;
    case 3:
        gotoxy(20,14);
        branco;
        bvermelho;
        cout << " 3 - REMOVER CADASTRO DE FUNCIONARIOS ";
        ExibirFuncionario(acesso);
        Sleep(2000);
        break;
    case 4:
        gotoxy(20,16);
        branco;
        bvermelho;
        cout << " 4 - VOLTAR PARA O MENU ADMIN";
        Sleep(2000);
        menuAdmin(acesso);
        break;
    default:
        gotoxy(25,27);
        branco;
        bvermelho;
        cout << " OPCAO INVALIDA ";
        Sleep(2000);
        cadastroDoAdmin(acesso);
        break;
    }
    cadastroDoAdmin(acesso);
}

void menuAdmin(int acesso)
{
    int opc=0;

    tela();

    gotoxy(30,5);
    preto;
    bbranco;
    cout << " MENU ADMIN ";

    gotoxy(20,10);
    preto;
    bbranco;
    cout << " 1 - GERENCIAMENTO DOS CADASTROS ";

    gotoxy(20,12);
    preto;
    bbranco;
    cout << " 2 - OPCOES DO ATENDENTE ";

    gotoxy(20,14);
    preto;
    bbranco;
    cout << " 3 - FAZER LOGOFF ";

    gotoxy(20,16);
    preto;
    bbranco;
    cout << " 4 - ENCERRAR O SISTEMA ";

    for (int i = 0; i < 3; i++)
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
        cout << " 1 - GERECIAMENTO DOS CADASTROS ";
        Sleep(1500);
        cadastroDoAdmin(acesso);
        break;

    case 2:
        gotoxy(20,12);
        branco;
        bvermelho;
        cout << " 2 - OPCOES DO ATENDENTE ";
        Sleep(1500);
        menuAtendente(acesso);
        break;

    case 3:
        gotoxy(20,14);
        branco;
        bvermelho;
        cout << " 3 - FAZER LOGOFF ";
        Sleep(1500);
        login(acesso);
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
    default:
        gotoxy(25,27);
        branco;
        bvermelho;
        cout << " OPCAO INVALIDA ";
        Sleep(2000);
        menuAdmin(acesso);
        break;
    }
}

void menuMed(char* medico, char* crm,char* telefone,int acesso)
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
    cout << " 2 - BUSCAR RCEITAS DO PACIENTE ";

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
        agendamentoPacientes(crm);
        break;

    case 2:
        gotoxy(20,12);
        branco;
        bvermelho;
        cout << " 2 - BUSCAR RECEITAS DO PACIENTE ";
        buscaPaciente(medico,crm,telefone,acesso);
        Sleep(1500);
        break;

    case 3:
        gotoxy(20,14);
        branco;
        bvermelho;
        cout << " 3 - GERAR RECEITA ";
        Sleep(1500);
        receita(medico,crm,telefone,acesso);
        break;

    case 4:
        gotoxy(20,16);
        branco;
        bvermelho;
        cout << " 4 - FAZER LOGOFF  ";
        limpaHelp();
        Sleep(1500);
        limpaHelp();
        login(acesso);
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
        menuMed(medico,crm,telefone,acesso);
        break;
    }
    menuMed(medico,crm,telefone,acesso);
}

void funcionarioCadastro(int acesso)
{
    char novoCad;

    char auz[50],cpf2[12],rg2[15],crm2[7];

    int n=1,x=0;

    ofstream cadastroFuncionario ("funcionarios.txt", ios::ate | ios::app);

    ifstream funcCadsatrados("funcionarios.txt");

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

            sprintf(auz,cadF.nome);

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
            if(cadF.dia < 1 || cadF.dia > 31)
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
            if(cadF.mes == 2 && cadF.dia > 29 )
            {
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
                }
                while(cadF.dia > 29);

            }
            else
            {
                if(cadF.mes < 1 || cadF.mes > 12 )
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

            if((( 2019 - cadF.ano) < 18) || (( 2019 - cadF.ano) > 80))
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

            sprintf(cpf2,cadF.cpf);

            x = 0;

            x = strlen(cadF.cpf);

            if(x < 11 || x > 11 )
            {
                n++;
            }
            n--;
        }
        while(n>0);

        funcCadsatrados.read((char *)(&cadF),sizeof(cadastroDeFuncionarios));

        while(!funcCadsatrados.eof())
        {
            if(strcmp(auz,cadF.nome)== 0 &&  strcmp(cpf2,cadF.cpf) == 0)
            {
                gotoxy(18,20);
                branco;
                bpreto;
                cout << " FUNCIONARIO JA POSSUI CADASTRO ";
                funcCadsatrados.close();
                Sleep(2500);
                menuAdmin(acesso);
            }
            funcCadsatrados.read((char *)(&cadF),sizeof(cadastroDeFuncionarios));
        }

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

            sprintf(rg2,cadF.rg);

            x = 0;

            x = strlen(cadF.rg);

            if(x < 4 || x > 15)
            {
                n++;
            }
            n--;
        }
        while(n>0);

        funcCadsatrados.open("funcionarios.txt");

        funcCadsatrados.read((char *)(&cadF),sizeof(cadastroDeFuncionarios));

        while(!funcCadsatrados.eof())
        {
            if(strcmp(rg2,cadF.rg) == 0)
            {
                gotoxy(18,22);
                branco;
                bpreto;
                cout << " FUNCIONARIO JA POSSUI CADASTRO ";
                funcCadsatrados.close();
                Sleep(2500);
                menuAdmin(acesso);
            }
            funcCadsatrados.read((char *)(&cadF),sizeof(cadastroDeFuncionarios));
        }

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

        funcCadsatrados.open("funcionarios.txt");

        funcCadsatrados.read((char *)(&cadF),sizeof(cadastroDeFuncionarios));

        while(!funcCadsatrados.eof())
        {
            if(strcmp(crm2,cadF.crm) == 0)
            {
                gotoxy(18,20);
                branco;
                bpreto;
                cout << " FUNCIONARIO JA POSSUI CADASTRO ";
                funcCadsatrados.close();
                Sleep(2500);
                menuAdmin(acesso);
            }
            funcCadsatrados.read((char *)(&cadF),sizeof(cadastroDeFuncionarios));
        }

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

    menuAdmin(acesso);


}

void valorAdmin(int acesso)
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

    menuAdmin(acesso);

}

void valorAtendente(int acesso)
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

    menuAtendente(acesso);

}

void menuAtendente(int acesso)
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
    cout << " 3 - VALOR DA CONSULTA ";

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
    cout << "6 - ENCERRAR O SISTEMA";

    for (int i = 0; i < 3; i++)
    {
        gotoxy(35+i,24);
        bbranco;
        nulo;
    }

    gotoxy(36,24);
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
        cadastroClientes(acesso);
        break;

    case 2:
        gotoxy(25,12);
        branco;
        bvermelho;
        cout << " 2 - AGENDAMENTO ";
        Sleep(1500);
        limpaHelp();
        agendamento(acesso);
        break;

    case 3:
        gotoxy(25,14);
        branco;
        bvermelho;
        cout << " 3 - VALOR DA CONSULTA ";
        Sleep(1500);
        limpaHelp();
        valorAtendente(acesso);
        break;

    case 4:
        gotoxy(25,16);
        branco;
        bvermelho;
        cout << " 4 - Help | AJUDA ";
        Sleep(1500);
        telaHelp();
        help(acesso);
        break;

    case 5:
        gotoxy(25,18);
        branco;
        bvermelho;
        cout << " 5 - FAZER LOGOUT ";
        Sleep(1500);
        login(acesso);
        break;
    case 6:
        gotoxy(25,20);
        branco;
        bvermelho;
        cout << " 6 - ENCERRAR O SISTEMA ";
        Sleep(1500);
        exit(1);
        break;
    }
    menuAtendente(acesso);
}

void help(int acesso)
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
    menuAtendente(acesso);
}

void cadastroClientes(int acesso)
{
    char op;

    int n=1,x=0;

    char dateStr[9];



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

            if(cadC.dia < 1 || cadC.dia > 31)
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
                    cin >> cadC.dia;
                }
                while(cadC.dia > 29);
            }
            else
            {
                if(cadC.mes < 1 || cadC.mes > 12)
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
                if(cadC.mes > atual.mes && cadC.ano > 2019)
                {
                    n++;
                }
                else
                {
                    if(cadC.dia > atual.dia && cadC.mes == atual.mes && cadC.ano > 2019)
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

    menuAtendente(acesso);


}

void buscaPaciente(char* medico, char* crm,char* telefone,int acesso)
{
    ifstream buscaCliente("clientes.txt");

    char nome[50],cpf[12];
    int n=1,x=0,t=0;

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
            char arq[15];
            sprintf(arq,"%s.txt",cpf);

            ifstream arquivo(arq);
            if(arquivo.is_open())
            {
                system(arq);
                t++;
            }
        }
        buscaCliente.read((char *)(&cadC),sizeof(clientes));
    }

    if(t == 0)
    {

    }
    gotoxy(18,18);
    branco;
    bpreto;
    cout << nome << " NAO POSSSUI RECEITAS ANTIGAS ";
    getchar();
    menuMed(medico,crm,telefone,acesso);

}

int idade(int dia,int mes, int ano)
{
    char dateStr[9];

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

void receita(char* medico,char* crm,char* telefone,int acesso)
{
    ifstream paciente("clientes.txt");

    char nome[50],cpf[12],remedio[50];
    int n=1,x=0,f=0;

    char dateStr[9];

    _strdate(dateStr);

    Data atual;

    ParseData(dateStr, &atual);

    int a = atual.ano + 2000;
    int d = atual.dia;
    int m = atual.mes;

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
        if((strcmp(nome,cadC.nome) == 0 ) && (strcmp(cpf,cadC.cpf) == 0) && f<3)
        {
            char arq[15];
            sprintf(arq,"%s.txt",cpf);

            ofstream receituario(arq,ios::app);

            receituario << "\n\n\t\t LIFEMED \n"
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
                        << " DATA DA CONSULTA: " << d << " / 0" << m << " / " << a;
            receituario.close();

            system(arq);

        }
        paciente.read((char *)(&cadC),sizeof(clientes));
        f++;
    }
    menuMed(medico,crm,telefone,acesso);
}

int number_func()
{
    ifstream directory("funcionarios.txt", ios::in);
    int counter=0;
    cadastroDeFuncionarios aux;
    directory.read((char*)(&aux), sizeof(cadastroDeFuncionarios));
    while(!directory.eof())
    {
        gotoxy(84,4+counter);
        preto;
        bbranco;
        directory.read((char*)(&aux), sizeof(cadastroDeFuncionarios));
        counter++;
    }
    directory.close();
    return counter;

}

void ExibirFuncionario(int acesso)
{
    int qtd = number_func();
    ifstream directory("funcionarios.txt", ios::in);
    int i=0;

    telaHelp();
    gotoxy(84,2+i);
    preto;
    bbranco;
    cout << "MEDICOS CADASTRADOS: " << endl << endl;
    CadP cadastro =  new cadastroDeFuncionarios[qtd];
    directory.read((char*)(&*(cadastro+i)), sizeof(cadastroDeFuncionarios));
    while(!directory.eof())
    {
        gotoxy(84,4+i);
        preto;
        bbranco;
        cout << cadastro[i].nome << endl;
        i++;
        directory.read((char*)(&*(cadastro+i)), sizeof(cadastroDeFuncionarios));
    }
    directory.close();
    RemoverFunc(cadastro,acesso);
}

void abreFecha(int acesso)
{
    ofstream directory("funcionarios.txt");
    directory.close();
}

void RemoverFunc(CadP cadastro,int acesso)
{
    int opcao,px=0;
    char nome[50];
    tela();
    gotoxy(30,5);
    branco;
    bpreto;
    cout << "REMOCAO DE CADASTRO";
    gotoxy(23,8);
    preto;
    bbranco;
    cout << "NOME DO FUNCIONARIO";
    for (int i=0; i<20; i++)
    {
        gotoxy(39+i,8);
        bbranco;
        nulo;
    }
    gotoxy(40,8);
    preto;
    fflush(stdin);
    cin.getline(nome, 50);

    for (int i=0; i<number_func(); i++)
    {
        if (strcmp(nome,cadastro[i].nome)==0)
        {
            gotoxy(26,11);
            preto;
            bbranco;
            cout << "DESEJA REALMENTE REMOVER?";
            gotoxy(28,13);
            preto;
            bbranco;
            cout << "1 - SIM";
            gotoxy(41,13);
            preto;
            bbranco;
            cout << "2 - NAO";
            for (int k=0; k<3; k++)
            {
                gotoxy(35+k,15);
                bbranco;
                nulo;
            }
            gotoxy(36,15);
            preto;
            cin >> opcao;
            if(opcao == 1)
            {
                cadastro[i].codigo = 1;
                int recebe = number_func();
                abreFecha(acesso);

                ofstream directory("funcionarios.txt", ios::out | ios::app);

                for(int j = 0; j<recebe; j++)
                {
                    if(cadastro[j].codigo!= 1)
                    {
                        directory.write((const char*)(&cadastro[j]), sizeof(cadastroDeFuncionarios));
                        px++;
                    }
                }
                directory.close();
                break;
            }
        }
    }
    if(px == 0)
    {
        gotoxy(23,10);
        preto;
        bbranco;
        cout << " FUNCIONARIO NAO CADASTRADO ";
        getch();
        RemoverFunc(cadastro,acesso);
    }
    else
    {
        gotoxy(23,10);
        preto;
        bbranco;
        cout << " FUNCIONARIO REMOVIDO COM SUCESSO ";
        getch();
    }
}

void agendamento(int acesso)
{
    ifstream arqMedico ("funcionarios.txt");

    char cargo[50],nomeMed[50],nome[50],cpf[12],opc;
    int n=1,x=0,NX=0,NXK=0,i=0;
    int hj=0,u=0;
    string aux;

    tela();

    gotoxy(30,5);
    branco;
    bpreto;
    cout << " DADOS PARA AGENDAMENTO ";

    gotoxy(23,8);
    branco;
    bpreto;
    cout<<" INFORME A ESPECIALIDADE ";

    gotoxy(20,20);
    branco;
    bpreto;
    cout<<" DIGITE 1 PARA VOLTAR PARA O MENU ";

    do
    {
        for (int i = 0; i < 30; i++)
        {
            gotoxy(24+i,10);
            bbranco;
            nulo;
        }
        gotoxy(25,10);
        preto;
        fflush(stdin);
        cin.getline(cargo,50);

        x = strlen(cargo);

        if(x > 50)
        {
            n++;
        }
        n--;
    }
    while(n>0);

    arqMedico.read((char*)(&cadF), sizeof(cadastroDeFuncionarios));

    telaHelp();

    gotoxy(90,3);
    preto;
    bbranco;
    cout << " MEDICOS DISPONIVEIS ";

    while(!arqMedico.eof())
    {
        if(strcmp(cargo,cadF.cargo) == 0 )
        {
            NX++;

            gotoxy(86,5+i);
            preto;
            bbranco;
            cout << " - " << cadF.nome ;
            i++;

        }
        arqMedico.read((char*)(&cadF), sizeof(cadastroDeFuncionarios));
    }

    if(strcmp(cargo,"1") == 0)
    {
        limpaHelp();
        menuAtendente(acesso);
    }

    arqMedico.close();

    i = 1;
    do
    {
        arqMedico.open("funcionarios.txt");
        if(NX > 0)
        {
            gotoxy(18,12);
            branco;
            bpreto;
            cout<<" INFORME O NOME MEDICO QUE DESEJA AGENDAR ";

            n = 1;

            do
            {
                for (int i = 0; i < 30; i++)
                {
                    gotoxy(24+i,14);
                    bbranco;
                    nulo;
                }
                gotoxy(25,14);
                preto;
                fflush(stdin);
                cin.getline(nomeMed,50);

                x = 0;

                x = strlen(cargo);

                if(x > 50)
                {
                    n++;
                }
                n--;
            }
            while(n>0);

            arqMedico.read((char*)(&cadF), sizeof(cadastroDeFuncionarios));

            while(!arqMedico.eof())
            {
                if(strcmp(nomeMed,cadF.nome) == 0)
                {
                    char p[11];

                    sprintf(p,"%s.txt",cadF.crm);

                    do
                    {
                        tela();
                        gotoxy(30,5);
                        preto;
                        bbranco;
                        cout << " DADOS DE PACIENTES ";

                        gotoxy(23,8);
                        preto;
                        bbranco;
                        cout<<" INFORME O NOME DO PACIENTE ";

                        do
                        {
                            for (int i = 0; i < 30; i++)
                            {
                                gotoxy(23+i,10);
                                bbranco;
                                nulo;
                            }
                            gotoxy(25,10);
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

                        gotoxy(23,12);
                        branco;
                        bpreto;
                        cout<<" INFORME O CPF ";

                        n=1;
                        do
                        {
                            for (int i = 0; i < 15; i++)
                            {
                                gotoxy(23+i,14);
                                bbranco;
                                nulo;
                            }
                            gotoxy(24,14);
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

                        ifstream Bclientes("clientes.txt");

                        if(Bclientes.is_open())
                        {
                            Bclientes.read((char *)(&cadC),sizeof(clientes));

                            while(!Bclientes.eof())
                            {
                                if((strcmp(nome,cadC.nome) == 0 ) && (strcmp(cpf,cadC.cpf) == 0) )
                                {
                                    pagamento(acesso,nome,cadF.nome,cadF.cargo,cadF.valorConsulta);

                                    ofstream agendado(p,ios::app);

                                    agendado << nome << "\n";

                                    tela();

                                    gotoxy(23,16);
                                    branco;
                                    bpreto;
                                    cout<<" AGENDADO COM SUCESSO ";

                                    Sleep(2000);

                                    u = 0;

                                    agendado.close();

                                    ifstream agendados(p);

                                    telaHelp();
                                    gotoxy(90,2+i);
                                    preto;
                                    bbranco;
                                    cout << " AGENDADOS ";

                                    while(!agendados.eof())
                                    {
                                        getline(agendados,aux);
                                        gotoxy(84,5+u);
                                        preto;
                                        bbranco;
                                        cout << " - " << aux ;
                                        u++;
                                    }

                                    agendados.close();

                                    i++;

                                }
                                Bclientes.read((char *)(&cadC),sizeof(clientes));
                            }
                        }

                        if(i == 1)
                        {
                            gotoxy(20,16);
                            branco;
                            bpreto;
                            cout<<" PACIENTE NAO ENCONTRADO TENTE NOVAMENTE ";

                            char n;

                            gotoxy(23,18);
                            branco;
                            bpreto;
                            cout<<" REALIZAR NOVO CADASTRO (S/N) ";

                            for (int i = 0; i < 3; i++)
                            {
                                gotoxy(55+i,18);
                                bbranco;
                                nulo;
                            }
                            gotoxy(56,18);
                            preto;
                            cin >> n;

                            if(n == 's' || n == 'S')
                            {
                                cadastroClientes(acesso);
                            }
                            else
                            {
                                menuAtendente(acesso);
                            }
                        }

                        gotoxy(18,18);
                        branco;
                        bpreto;
                        cout<<" REALIZAR NOVO AGENDAMENTO (S/N) ";

                        for (int i = 0; i < 3; i++)
                        {
                            gotoxy(55+i,18);
                            bbranco;
                            nulo;
                        }
                        gotoxy(56,18);
                        preto;
                        cin >> opc;
                    }
                    while(opc == 's' || opc == 'S');
                    NXK++;
                }
                arqMedico.read((char*)(&cadF), sizeof(cadastroDeFuncionarios));
            }
            if(NXK == 0)
            {
                gotoxy(20,18);
                branco;
                bpreto;
                cout<<" MEDICO NAO CADASTRADO TENTE NOVAMENTE ";
                hj++;
                Sleep(1500);
            }
        }
        arqMedico.close();
    }
    while(hj != 0);


    if(NX == 0)
    {
        gotoxy(20,18);
        branco;
        bpreto;
        cout<<" ESPECIALIDADE NAO DISPONIVEL ";
        Sleep(1500);
        agendamento(acesso);
    }

    limpaHelp();
    arqMedico.close();
    menuAtendente(acesso);

}

void agendamentoPacientes(char * crm)
{
    char p[11];

    int i=0;

    sprintf(p,"%s.txt",crm);

    ifstream agendados(p);

    string aux;

    telaHelp();

    gotoxy(90,3);
    preto;
    bbranco;
    cout << " AGENDADOS ";

    while(!agendados.eof())
    {
        if(i <= 10 && agendados.is_open())
        {
            getline(agendados,aux);
            gotoxy(86,5+i);
            preto;
            bbranco;
            cout << " - " << aux;
            i++;
        }
    }

}

void pagamento(int acesso,char * nome,char * nomeMed, char * cargo, float valorConsulta)
{
    char titular[50],numCard[17],cvc[3],cx;
    int opc,n=1,Numparcelas;
    float total;
    int valorRecebido,ValorTroco;

    tela();

    gotoxy(30,5);
    preto;
    bbranco;
    cout << " REALIZACAO DO PAGAMENTO ";

    gotoxy(20,10);
    preto;
    bbranco;
    cout << " PACIENTE : " << nome;

    gotoxy(20,12);
    preto;
    bbranco;
    cout << " DR. " << nomeMed << " | " << cargo ;

    gotoxy(20,14);
    preto;
    bbranco;
    cout << " VALOR DA CONSULTA - R\x24:  " << valorConsulta ;

    gotoxy(20,16);
    preto;
    bbranco;
    cout << " QUAL A FORMA DE PAGAMENTO ";

    gotoxy(16,18);
    preto;
    bbranco;
    cout << " DIGITE 1 PARA CARTAO E 2 PARA DINHEIRO ";
    do
    {
        for (int i = 0; i < 3; i++)
        {
            gotoxy(58+i,18);
            bbranco;
            nulo;
        }
        gotoxy(59,18);
        preto;
        cin >> opc;
        if(opc < 0 || opc > 2)
        {
            n++;
        }
        n--;
    }
    while(n > 0);
    if(opc == 1)
    {
        tela();

        gotoxy(20,5);
        preto;
        bbranco;
        cout << " PAGAMENTO COM CARTAO DE CREDITO ";

        if(valorConsulta < 300)
        {
            gotoxy(20,10);
            preto;
            bbranco;
            cout << " INFORME O NOME DO TITULAR DO CARTAO ";

            for (int i = 0; i < 30; i++)
            {
                gotoxy(20+i,12);
                bbranco;
                nulo;
            }
            gotoxy(21,12);
            preto;
            fflush(stdin);
            cin.getline(titular,50);

            gotoxy(20,14);
            preto;
            bbranco;
            cout << " DIGITE O NUMERO DO CARTAO ";

            for (int i = 0; i < 18; i++)
            {
                gotoxy(20+i,16);
                bbranco;
                nulo;
            }
            gotoxy(21,16);
            preto;
            fflush(stdin);
            cin.getline(numCard,17);

            if(numCard[0] == '5' || numCard[0] == '2')
            {
                gotoxy(20,18);
                preto;
                bbranco;
                cout << " CARTAO MASTERCARD DETECTADO ";

                gotoxy(18,20);
                preto;
                bbranco;
                cout << " DIGITE O CVC QUE SAO OS 3 NUMEROS ";
                gotoxy(18,21);
                preto;
                bbranco;
                cout << " LOCALIZADO NA PARTE DE TRAS DO SEU CARTAO ";

                for (int i = 0; i < 5; i++)
                {
                    gotoxy(56+i,20);
                    bbranco;
                    nulo;
                }
                gotoxy(57,20);
                preto;
                cin >> cvc;

                gotoxy(20,23);
                preto;
                bbranco;
                cout << " PROCESSANDO PAGAMENTO ... ";

                Sleep(2000);

                gotoxy(20,25);
                preto;
                bbranco;
                cout << " PAGAMENTO EFETUADO COM SUCESSO ";
                Sleep(2000);
            }
            if(numCard[0] == '4')
            {

                gotoxy(20,18);
                preto;
                bbranco;
                cout << " CARTAO VISA DETECTADO ";

                gotoxy(18,20);
                preto;
                bbranco;
                cout << " DIGITE O CVC QUE SAO OS 3 NUMEROS ";
                gotoxy(18,21);
                preto;
                bbranco;
                cout << " LOCALIZADO NA PARTE DE TRAS DO SEU CARTAO ";

                for (int i = 0; i < 5; i++)
                {
                    gotoxy(56+i,20);
                    bbranco;
                    nulo;
                }
                gotoxy(57,20);
                preto;
                cin >> cvc;

                gotoxy(20,23);
                preto;
                bbranco;
                cout << " PROCESSANDO PAGAMENTO ... ";

                Sleep(2000);

                gotoxy(20,25);
                preto;
                bbranco;
                cout << " PAGAMENTO EFETUADO COM SUCESSO ";
                Sleep(2000);
            }
            if(numCard[0] == '3')
            {

                gotoxy(20,18);
                preto;
                bbranco;
                cout << " CARTAO AMERICAN EXPRESS DETECTADO ";

                gotoxy(18,20);
                preto;
                bbranco;
                cout << " DIGITE O CVC QUE SAO OS 3 NUMEROS ";
                gotoxy(18,21);
                preto;
                bbranco;
                cout << " LOCALIZADO NA PARTE DE TRAS DO SEU CARTAO ";

                for (int i = 0; i < 5; i++)
                {
                    gotoxy(56+i,20);
                    bbranco;
                    nulo;
                }
                gotoxy(57,20);
                preto;
                cin >> cvc;

                gotoxy(20,23);
                preto;
                bbranco;
                cout << " PROCESSANDO PAGAMENTO ... ";

                Sleep(2000);

                gotoxy(20,25);
                preto;
                bbranco;
                cout << " PAGAMENTO EFETUADO COM SUCESSO ";
                Sleep(2000);
            }
            else
            {
                if(numCard[0] == '1' && numCard[0] != '6' && numCard[0] != '7' && numCard[0] != '8' && numCard[0] != '9')
                {
                    gotoxy(20,18);
                    preto;
                    bbranco;
                    cout << " CARTAO COM BANDEIRA DESCONHECIDA ";

                    gotoxy(20,20);
                    preto;
                    bbranco;
                    cout << " DESEJA CONFIRMAR O PAGAMENTO (S/N) ";

                    for (int i = 0; i < 3; i++)
                    {
                        gotoxy(57+i,20);
                        bbranco;
                        nulo;
                    }
                    gotoxy(58,20);
                    preto;
                    cin >> cx;
                    if(cx == 's' || cx == 'S')
                    {
                        gotoxy(16,22);
                        preto;
                        bbranco;
                        cout << " DIGITE O CVC QUE SAO OS 3 NUMEROS ";
                        gotoxy(16,23);
                        preto;
                        bbranco;
                        cout << " LOCALIZADO NA PARTE DE TRAS DO CARTAO ";

                        for (int i = 0; i < 5; i++)
                        {
                            gotoxy(55+i,23);
                            bbranco;
                            nulo;
                        }
                        gotoxy(56,23);
                        preto;
                        cin >> cvc;

                        gotoxy(20,25);
                        preto;
                        bbranco;
                        cout << " PROCESSANDO PAGAMENTO ... ";

                        Sleep(2000);

                        gotoxy(20,27);
                        preto;
                        bbranco;
                        cout << " PAGAMENTO EFETUADO COM SUCESSO ";
                        Sleep(2000);


                    }
                    else
                    {
                        gotoxy(20,20);
                        preto;
                        bbranco;
                        cout << " TRANSACAO NAO AUTORIZADA ";
                        menuAtendente(acesso);
                    }
                }
            }
        }
        else
        {
            if(valorConsulta >= 300)
            {
                tela();

                gotoxy(20,10);
                preto;
                bbranco;
                cout << " DIGITE O TOTAL DE PARCELAS ";

                for (int i = 0; i < 3; i++)
                {
                    gotoxy(50+i,10);
                    bbranco;
                    nulo;
                }
                gotoxy(51,10);
                preto;
                cin >> Numparcelas;

                total = valorConsulta / Numparcelas;

                gotoxy(20,12);
                preto;
                bbranco;
                cout << Numparcelas << " X  DE : " << total;

                Sleep(3500);

                tela();

                gotoxy(20,5);
                preto;
                bbranco;
                cout << " PAGAMENTO COM CARTAO DE CREDITO ";

                gotoxy(20,10);
                preto;
                bbranco;
                cout << " INFORME O NOME DO TITULAR DO CARTAO ";

                for (int i = 0; i < 30; i++)
                {
                    gotoxy(20+i,12);
                    bbranco;
                    nulo;
                }
                gotoxy(21,12);
                preto;
                fflush(stdin);
                cin.getline(titular,50);

                gotoxy(20,14);
                preto;
                bbranco;
                cout << " DIGITE O NUMERO DO CARTAO ";

                for (int i = 0; i < 18; i++)
                {
                    gotoxy(20+i,16);
                    bbranco;
                    nulo;
                }
                gotoxy(21,16);
                preto;
                fflush(stdin);
                cin.getline(numCard,16);

                if(numCard[0] == '5' || numCard[0] == '2')
                {
                    gotoxy(20,18);
                    preto;
                    bbranco;
                    cout << " CARTAO MASTERCARD DETECTADO ";

                    gotoxy(20,20);
                    preto;
                    bbranco;
                    cout << " DIGITE O CVC QUE SAO OS 3 NUMEROS ";
                    gotoxy(20,21);
                    preto;
                    bbranco;
                    cout << " LOCALIZADO NA PARTE DE TRAS DO SEU CARTAO ";

                    for (int i = 0; i < 5; i++)
                    {
                        gotoxy(57+i,20);
                        bbranco;
                        nulo;
                    }
                    gotoxy(58,20);
                    preto;
                    cin >> cvc;

                    gotoxy(20,23);
                    preto;
                    bbranco;
                    cout << " PROCESSANDO PAGAMENTO ... ";

                    Sleep(2000);

                    gotoxy(20,25);
                    preto;
                    bbranco;
                    cout << " PAGAMENTO EFETUADO COM SUCESSO ";
                    Sleep(2000);
                }
                if(numCard[0] == '4')
                {

                    gotoxy(20,18);
                    preto;
                    bbranco;
                    cout << " CARTAO VISA DETECTADO ";

                    gotoxy(20,20);
                    preto;
                    bbranco;
                    cout << " DIGITE O CVC QUE SAO OS 3 NUMEROS ";
                    gotoxy(20,21);
                    preto;
                    bbranco;
                    cout << " LOCALIZADO NA PARTE DE TRAS DO SEU CARTAO ";

                    for (int i = 0; i < 5; i++)
                    {
                        gotoxy(57+i,20);
                        bbranco;
                        nulo;
                    }
                    gotoxy(58,20);
                    preto;
                    cin >> cvc;

                    gotoxy(20,23);
                    preto;
                    bbranco;
                    cout << " PROCESSANDO PAGAMENTO ... ";

                    Sleep(2000);

                    gotoxy(20,25);
                    preto;
                    bbranco;
                    cout << " PAGAMENTO EFETUADO COM SUCESSO ";
                    Sleep(2000);
                }
                if(numCard[0] == '3')
                {
                    gotoxy(20,18);
                    preto;
                    bbranco;
                    cout << " CARTAO AMERICAN EXPRESS DETECTADO ";

                    gotoxy(18,20);
                    preto;
                    bbranco;
                    cout << " DIGITE O CVC QUE SAO OS 3 NUMEROS ";
                    gotoxy(18,21);
                    preto;
                    bbranco;
                    cout << " LOCALIZADO NA PARTE DE TRAS DO SEU CARTAO ";

                    for (int i = 0; i < 5; i++)
                    {
                        gotoxy(57+i,20);
                        bbranco;
                        nulo;
                    }
                    gotoxy(58,20);
                    preto;
                    cin >> cvc;

                    gotoxy(20,23);
                    preto;
                    bbranco;
                    cout << " PROCESSANDO PAGAMENTO ... ";

                    Sleep(2000);

                    gotoxy(20,25);
                    preto;
                    bbranco;
                    cout << " PAGAMENTO EFETUADO COM SUCESSO ";
                    Sleep(2000);
                }
                else
                {
                    if(numCard[0] != '5' && numCard[0] != '2' && numCard[0] != '4' && numCard[0] != '3')
                    {
                        gotoxy(20,18);
                        preto;
                        bbranco;
                        cout << " CARTAO COM BANDEIRA DESCONHECIDA ";

                        gotoxy(20,20);
                        preto;
                        bbranco;
                        cout << " DESEJA CONFIRMAR O PAGAMENTO (S/N) ";

                        for (int i = 0; i < 3; i++)
                        {
                            gotoxy(56+i,20);
                            bbranco;
                            nulo;
                        }
                        gotoxy(57,20);
                        preto;
                        cin >> cx;
                        if(cx == 's' || cx == 'S')
                        {
                            gotoxy(16,22);
                            preto;
                            bbranco;
                            cout << " DIGITE O CVC QUE SAO OS 3 NUMEROS ";
                            gotoxy(16,23);
                            preto;
                            bbranco;
                            cout << " LOCALIZADO NA PARTE DE TRAS DO CARTAO ";

                            for (int i = 0; i < 5; i++)
                            {
                                gotoxy(55+i,23);
                                bbranco;
                                nulo;
                            }
                            gotoxy(56,23);
                            preto;
                            cin >> cvc;

                            gotoxy(20,25);
                            preto;
                            bbranco;
                            cout << " PROCESSANDO PAGAMENTO ... ";

                            Sleep(2000);

                            gotoxy(20,27);
                            preto;
                            bbranco;
                            cout << " PAGAMENTO EFETUADO COM SUCESSO ";
                            Sleep(2000);


                        }
                        else
                        {
                            gotoxy(20,20);
                            preto;
                            bbranco;
                            cout << " TRANSACAO NAO AUTORIZADA ";
                            menuAtendente(acesso);
                        }
                    }
                }
            }
        }
    }

    if(opc == 2)
    {
        tela();

        gotoxy(20,5);
        preto;
        bbranco;
        cout << " PAGAMENTO A VISTA ";

        gotoxy(20,10);
        preto;
        bbranco;
        cout << " INFORME O VALOR RECEBIDO ";

        int n=1;

        do
        {
            for (int i = 0; i < 10; i++)
            {
                gotoxy(20+i,12);
                bbranco;
                nulo;
            }
            gotoxy(21,12);
            preto;
            cin >> valorRecebido;

            if(valorRecebido <= valorConsulta)
            {
                n++;
            }
            n--;
        }
        while(n>0);


        ValorTroco = valorRecebido - valorConsulta;

        troco(ValorTroco);

        Sleep(5000);
    }
}

void troco(int valor)
{
    int numero=0, quantiarestante=0;
    numero=valor;
    // calculando notas de 50
    quantiarestante=numero/50;
    numero=numero % 50;

    gotoxy(20,18);
    preto;
    bbranco;
    cout << " NOTAS DE 50: " << quantiarestante;
    //calculando notas de 20
    quantiarestante=numero/20;
    numero=numero % 20;

    gotoxy(20,19);
    preto;
    bbranco;
    cout << " NOTAS DE 20: " << quantiarestante;
    //calculando notas de 10
    quantiarestante=numero/10;
    numero=numero % 10;

    gotoxy(20,20);
    preto;
    bbranco;
    cout << " NOTAS DE 10: " << quantiarestante;
    // calculando notas de 5
    quantiarestante=numero/5;
    numero=numero % 5;

    gotoxy(20,21);
    preto;
    bbranco;
    cout << " NOTAS DE 5: " << quantiarestante;
    // calculando notaS DE 2
    quantiarestante=numero/2;
    numero=numero % 2;

    gotoxy(20,22);
    preto;
    bbranco;
    cout << " NOTAS DE 2: " << quantiarestante;
    // calculando notas de 1

    quantiarestante=numero/1;
    numero=numero % 1;
    gotoxy(20,23);
    preto;
    bbranco;
    cout << " MOEDAS DE 1: " << quantiarestante<<endl;
}
