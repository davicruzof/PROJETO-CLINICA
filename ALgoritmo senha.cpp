#include<stdio.h>
#include<windows.h>
#include<stdlib.h>
#include<ctype.h>
#include<conio.h>
#include<string.h> //Biblioteca para usar a funçao strcmp
/*Autor: Ruben Alves do Nascimento
  Contato: rubenanapu@hotmail.com
*/
main(){
       char c,cadastro_login[50],cadastro_senha[50],acesso_login[50],acesso_senha[50];
       int a=0,b=1,d=3;// d controlará a quantidade de erros ao logar no sistema
       printf("\n\t\t\tCADASTRO\n\nDigite o login: ");
       fflush(stdin);                     //Limpando o buffer do teclado
       gets(cadastro_login);
       printf("\nDigite a senha: ");
       do{
           c=getch();
           if(isprint(c)){       //Analisa se o valor da variável c é imprimivel
           cadastro_senha[a]=c;  //Se for, armazena o caractere
           a++;
           printf("*");          //imprime o * Anterisco
           }
           else if(c==8&&a){     //8 é o caractere BackSpace na tabela ASCII, && a analisa se a é diferente de 0
           cadastro_senha[a]='\0';
           a--;
           printf("\b \b");       //Apagando o caractere digitado
           }
       }while(c!=13);             //13 é o valor de ENTER na tabela ASCII
       cadastro_senha[a]='\0';
       system("cls");
       printf("\n\nCadastro efetuado com sucesso...\n\n");
       do{
           printf("\nEntre com o login: ");
           fflush(stdin);      //Limpando o buffer do teclado
           gets(acesso_login);
           printf("\nEntre com a senha: ");
           a=0;
               do{
                   c=getch();
                   if(isprint(c)){      //Analisa se o valor de c é imprimível
                   acesso_senha[a]=c;
                   a++;
                   printf("*");      //Imprimindo apenas o asterisco *
                   }
                   else if(c==8&&a){
                   acesso_senha[a]='\0';
                   a--;
                   printf("\b \b");     //Apagando os caracteres digitados
                   }
               }while(c!=13);           //13 é o valor de ENTER na tabela ASCII
               acesso_senha[a]='\0';

               if(!strcmp(cadastro_login,acesso_login)&&!strcmp(cadastro_senha,acesso_senha)){
               //strcmp retorna 0 se as variáveis forem iguais. !strcmp é o mesmo que strcmp==0
               printf("\n\n\t\t\tLOGADO COM SUCESSO...\n\n");
               b=0;
               }
               else {
               system("cls");
               d--;          //Quando d for iguala a 0, o sistema bloqueia por 3 erros consecutivos
               if (d)printf("\n\n\t\a\tSENHA INVALIDA - TENTE NOVAMENTE...\n\n");
               }
       }while(b&&d);                      //Enquanto b e d forem diferente de zero 0
       if(!d)printf("\a\n\n\t\tCONTA BLOQUEADA - VOCE ERROU 3 VEZES CONSECUTIVAS...\n\n");
       //Analisa se a pessoa errou 3 vezes a senha. !d é o mesmo que d==0
system("pause");
}
