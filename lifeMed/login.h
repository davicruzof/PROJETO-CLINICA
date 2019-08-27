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

    tela();

    gotoxy(30,5);
    branco;
    bpreto;
    cout << " SEJA BEM VINDO ";

    if(acesso >= 0){

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
                gotoxy(23,22);
                branco;
                bpreto;
                cout << " USUARIO OU SENHA INCORRETO ";
                gotoxy(23,25);
                branco;
                bpreto;
                cout << " VOCE TEM + " << acesso << " TENTATIVAS  RESTANTES" ;
                getchar();
                login(acesso-1);
            }
        }

    }
    else{
        system("cls");
        exit(1);
    }

}
//
//char c;
//    int a=0,j=0;
//
//    do{
//           c=getch();
//           if(isprint(c)){       //Analisa se o valor da variável c é imprimivel
//           senha[a]=c;  //Se for, armazena o caractere
//           a++;
//           gotoxy(36+a,18);
//           j = 36+a;
//           preto;
//           printf("*");          //imprime o * Anterisco
//           }
//           else if(c==8&&a){     //8 é o caractere BackSpace na tabela ASCII, && a analisa se a é diferente de 0
//           senha[a]='\0';
//           a--;
//           gotoxy(j--,18);
//           preto;
//           printf("\b \b");       //Apagando o caractere digitado
//           }
//       }while(c!='\n');
