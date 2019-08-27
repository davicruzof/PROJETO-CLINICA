# PROJETO-CLINICA
void agendamento()
{
    ifstream ArqAgen("clientes.txt");

    /*if(ArqAgen.eof())
    {
        menuMed(medico, crm, telefone);
    }*/

    char nome[50],cpf[12],cargo[50];

    tela();

    gotoxy(30,5);
    preto;
    bbranco;
    cout << " DADOS DE PACIENTES ";

    gotoxy(23,8);
    preto;
    bbranco;
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
    fflush(stdin);
    cin.getline(cpf,12);

    ArqAgen.read((char *)(&cadC),sizeof(clientes));

            ifstream arqMedico ("funcionarios.txt");
    while(ArqAgen.eof())
    {
        if((strcmp(nome,cadC.nome) == 0 ) && (strcmp(cpf,cadC.cpf) == 0))
        {

            tela();
            gotoxy(30,5);
            branco;
            bpreto;
            cout << " DADOS PARA AGENDAMENTO ";

            gotoxy(23,8);
            branco;
            bpreto;
            cout<<" INFORME A ESPECIALIDADE ";

            for (int i = 0; i < 20; i++)
            {
                gotoxy(23+i,10);
                bbranco;
                nulo;
            }
            gotoxy(24,10);
            preto;
            fflush(stdin);
            cin.getline(cargo,50);

        }
    }
            arqMedico.read((char*)(&cadF), sizeof(cadastroDeFuncionarios));
            int op=0;
            while(arqMedico.eof())
            {
                cout << "CHEGUEI";
                if(strcmp(cargo,cadF.cargo) == 0 )
                {
                    system("cls");
                    tela();
                    bbranco;
                    preto;
                    cout << op+1 << "- " << cadF.nome << endl;
                    op++;
                }
                arqMedico.read((char*)(&cadF), sizeof(cadastroDeFuncionarios));
            }
            if(op==1)
            {
                ofstream arqpAgendar ("listadeconsultas.txt", ios::app);

                arqpAgendar.write((const char*)(&cadC), sizeof(clientes));           //PAREEEEIIII AQQUUUUUIIIIIIIIIII))
            }
            cout << " ESCOLHA O MEDICO DE SUA PREFERENCIA ";
        ArqAgen.read((char *)(&cadC),sizeof(clientes));
}
