#include <iostream>
#include<locale.h>
#include<conio.h>
#include<iomanip>
#include<cmath>
#include<fstream>
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
//#include "menu.h"
#define MAXFCLIENTES 100
using namespace std;
void cadastroC();
struct clientes{
        char nome[20];
        char cpf[12];
        int dia;
        int mes;
        int ano;
        char sexo;
        char endereco[50];
        char telefone[11];
    };
    struct clientes C;

// CADASTRAR CLIENTES
void cadastroC()
{
    char op;
    ofstream cadastro;
    cadastro.open("database.txt", ios::out | ios::app);
    if(!cadastro.is_open()){
        cout<<"ERRO AO ABRIR ARQUIVO"<<endl;
        exit(1);
    }

        cout<<"Informe o Nome do Cliente:"<<endl;
        cin>>C.nome;
        cout<<"Informe o CPF:"<<endl;
        cin>>C.cpf;
        cout<<"Informe a Data:";
        cin>>C.dia>>C.mes>>C.ano;
        cout<<"Informe o Sexo (M/F):"<<endl;
        cin>>C.sexo;
        cout<<"Informe o Endereço:"<<endl;
        cin>>C.endereco;
        cout<<"Informe o telefone:";
        cin>>C.telefone;
        cadastro.write((const char*)(&C),sizeof(clientes));
        cadastro.close();
        cout<<"DESEJA CADASTRAR OUTRO CLIENTE? (S/N)"<<endl<<">>";
        cin>>op;
        if(op=='S' || op=='s'){
            cadastroC();
        }
        else{
           // menu2();
        }

}
