#include "functions.h"

using namespace std;

void login(int acesso)
{
    const char usuario[50] = "admin";
    const char password[50] = "3284";
    const char usuario2[50] = "atendente";
    const char password2[50] = "8432";

    ifstream busca("funcionarios.txt");

    char senha[15];
    char user[50];
    char ch;
    int pos=0;

    if(acesso >= 0)
    {
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

        while(true)
        {
            ch=getch();
            if(pos>=15)
            {
                cout<<'\a';    /* beep if password is too long */
                continue;
            }

            if(ch==13)
                break;  /* User have pressed ENTER*/

            else if(ch==8)  /* BACKSPACE was pressed*/
            {
                cout <<"\b \b";
                senha[--pos]='\0';
            }
            else/* A..Z a...z  BUG: I forgot what... */
            {
                cout <<"*";
                senha[pos++]=ch;
                senha[pos]='\0';
            }
            if(pos<=0)
                pos=0;
        }

            if(busca.is_open())
            {
                busca.read((char *)(&cadF),sizeof(cadastroDeFuncionarios));

                while(busca && !busca.eof())
                {
                    if((strcmp(user,cadF.nome) == 0 ) && (strcmp(senha,cadF.rg) == 0)) // MEDICO
                    {
                        busca.close();
                        acesso = 2;
                        menuMed(user,cadF.crm,cadF.telefone,acesso);
                    }
                    busca.read((char *)(&cadF),sizeof(cadastroDeFuncionarios));
                }
            }

            if((strcmp(user,usuario) == 0 ) && (strcmp(senha,password) == 0))// ADMIN
            {
                acesso = 2;
                menuAdmin(acesso);
            }
            if((strcmp(user,usuario2) == 0 ) && (strcmp(senha,password2) == 0)) //ATENDENTE
            {
                acesso = 2;
                menuAtendente(acesso);
            }
            else
            {
                gotoxy(25,22);
                branco;
                bpreto;
                cout << " USUARIO OU SENHA INCORRETO ";
                gotoxy(20,25);
                branco;
                bpreto;
                cout << " VOCE TEM + " << acesso << " TENTATIVAS  RESTANTES" ;
                gotoxy(20,27);
                branco;
                bpreto;
                cout << " PESSIONE ENTER PARA TENTAR NOVAMENTE " ;
                getchar();
                login(acesso-1);
            }

    }
    else
    {
        tela();
        gotoxy(23,15);
        branco;
        bpreto;
        cout << " VOCE ATINGIU O MAXINO DE TENTATIVAS ";
        gotoxy(23,17);
        branco;
        bpreto;
        cout << " ENCERRANDO O SISTEMA ... ";
        Sleep(3500);
        system("cls");
        exit(1);
    }

}
