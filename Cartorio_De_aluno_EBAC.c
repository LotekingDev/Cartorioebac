#include <stdio.h> //Biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //Blibioteca de aloca��o de espa�o em m�moria
#include <locale.h>//Biblioteca de Aloca��o de texto por regi�o 
#include <string.h>//Biblioteca respons�vel por cuidar das string

int registrar()// Fun��o responsavel por cadastrar os usu�rios no sitema
{
	//inicio cria��a de variaveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final cria��a de variaveis/string
	
	printf("Digite o CPF a ser cadastrado: ");//coletando informa��o do usu�rio
	scanf("%s", cpf);//amazenando a variavel "CPF" ultilizando  a Fun��o string "%s"
	
	
	strcpy(arquivo, cpf); //Responsavel por copiar os valores das string
	
	FILE *file; //criar o arquivo	
	file = fopen(arquivo, "w"); //cria o arquivo e o "w" significa escrever
	fprintf(file,cpf); // alvo o valor da variavel 	
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a");// acessar o arquivo e "a" atualizar a informa��o
	fprintf(file,",");//salva o espao para separar a variavel por linha 
	fclose(file); //fechar o arquivo atualizado
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s",nome);//amazenando a variavel "nome" ultilizando  a Fun��o string "%s"
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o Sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome);//amazenando a variavel "sobrenome" ultilizando  a Fun��o string "%s"
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s",cargo);//amazenando a variavel "cargo" ultilizando  a Fun��o string "%s"
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");
	
}

int consultar()
{
	setlocale(LC_ALL, "Portuguese");//Defini��o da linguagem
	
	char cpf[40];
	char conteudo[200];
	char *token;
	
	
	printf("Digite o CPF a ser Consultado: ");
	scanf( "%s",cpf);//amazenando a variavel "CPF" ultilizando  a Fun��o string "%s"
	
	FILE *file;
	file = fopen(cpf,"r");//abre o arquivo CPF e "r" de Read (Ler) a Informa��o!
	
	if(file == NULL)// se a informa��o n�o existir traz a seguinte informa��o
	{
		printf("\nN�o foi Possivel consultar o CPF Cadastrado!.\n");// informa��o quando n�o tem nenhum CPF cadastrado no banco de dados
	}
	
	while(fgets(conteudo, 200, file)!= NULL)// while (enquanto) tiver informa��o , armazene a informa��o em conteudo se for diferente de NULL (nulo
	{
		printf("\nEssas s�o as informa��es do usu�rio:\n");//informa��o aparece antes dos dados 
		
		token = strtok(conteudo,",");//variavel ultilizado para dividir a string em linhas
		printf("CPF: %s\n", token);//informa��o aparece antes dos dado do CPF
		
		token = strtok(NULL,",");//variavel ultilizado para dividir a string em linhas
		printf("Nome: %s\n", token);//informa��o aparece antes dos dado do Nome
		
		token = strtok(NULL,",");//variavel ultilizado para dividir a string em linhas
		printf("Sobrenome: %s\n", token);//informa��o aparece antes dos dado do Sobrenome
		
		token = strtok(NULL,",");//variavel ultilizado para dividir a string em linhas
		printf("Cargo: %s\n", token);//informa��o aparece antes dos dado do Cargo
	}
	
	printf("\n");//Comando ultilizado para pular uma linha no final
	
	system("pause");
	
	
}

int deletar() //Fun��o responsavel por deletar usu�rios
{
	char cpf[40];

	printf("Digite o CPF do usu�rio a ser deletado: "); //Mensagem ao usu�rio
	scanf("%s",cpf); // CPF e o ponto chave do nosso cart�rio 
	 
	FILE *file; //Cria o arquivo 
	file = fopen(cpf,"r"); //Abre o arquivo, e o "r" � para ler o arquivo 
	fclose(file); // Obs: fechar arquivos
	
	if(file == NULL) // "E SE" o arquivo n�o for encontrado
	{
		printf("\nO usu�rio n�o se encontra no sistema!.\n"); //Mensagem ao usu�rio 
		system("pause"); //Pausa o sistema at� o usu�rio continuar 
	}
	
	remove(cpf); // Opcao que apaga arquivos
	
	if(file != NULL) // != significa "se for diferente de a coloque b"
	{
		printf("\nO usu�rio foi deletado com sucesso!\n\n"); //Mensagem ao usu�rio
		system("pause"); //Pausa o sitema at� o usu�rio continuar 
	}
	
}

int main()
{
    int opcao = 0;
    int laco = 1;
    char login[40] = "a";
    char senha[10] = "a";
    int comparacaologin, comparacaosenha;
    int tentativas = 0; // Vari�vel para controlar o n�mero de tentativas

    setlocale(LC_ALL, "Portuguese"); // Defini��o da linguagem

    printf("### Cart�rio da EBAC ###\n\n");

    for (tentativas = 0; tentativas < 3; tentativas++)// Loop para permitir at� 3 tentativas
    {
        printf("Login de administrador!\n\n");
        printf("Login: "); // Solicita o login (nome de usu�rio)
        scanf("%s", login);

        printf("Senha: "); // Solicita a senha
        scanf("%s", senha);

        comparacaologin = strcmp(login, "ebac"); // Compara login
        comparacaosenha = strcmp(senha, "admin"); // Compara senha

        if (comparacaologin == 0 && comparacaosenha == 0)
        {
            // Se o login e senha estiverem corretos, entra no sistema
            printf("Login bem-sucedido!\n");
            break; // Sai do loop se o login for bem-sucedido
        }
        else
        {
            // Se as credenciais estiverem incorretas
            printf("Login ou senha incorretos. ");
            printf("Tentativas restantes: %d\n", 2 - tentativas); // Informa o n�mero de tentativas restantes
            if (tentativas == 2) // Se for a �ltima tentativa
            {
                printf("Voc� excedeu o n�mero de tentativas. O programa ser� encerrado.\n");
                return 0; // Fecha o programa ap�s 3 tentativas
            }
        }
    }

    // Caso o login tenha sido bem-sucedido, segue o resto do c�digo
    while (1) // Inicia o loop principal do sistema
    {
        system("cls");

        setlocale(LC_ALL, "Portuguese"); // Defini��o da linguagem

        printf("### Cart�rio De Alunos Da EBAC ###\n\n");
        printf("Escolha as op��es:\n\n"); // Entrada para o menu
        printf("\t1 - Registrar um Novo Aluno\n");
        printf("\t2 - Consultar Nome do Aluno\n");
        printf("\t3 - Deletar um Aluno\n\n");
        printf("\t4 - Sair do Sistema\n\n");
        printf("Op��o: "); // Fim do menu

        scanf("%d", &opcao); // Armazena a escolha do usu�rio

        system("cls"); // Respons�vel por limpar a tela

        switch (opcao) // In�cio da escolha do usu�rio
        {
            case 1:
                registrar(); // Chama a fun��o registrar
                break;

            case 2:
                consultar(); // Chama a fun��o consultar
                break;

            case 3:
                deletar(); // Chama a fun��o deletar
                break;

            case 4:
                printf("Obrigado por utilizar o Sistema!\n");
                return 0; // Sai do programa
                break;

            default:
                printf("Essa op��o n�o est� dispon�vel!\n");
                system("pause");
                break;
        }
    }

    return 0; // Finaliza o programa
}

