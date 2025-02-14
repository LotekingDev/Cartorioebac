#include <stdio.h> //Biblioteca de comunicação com o usuário
#include <stdlib.h> //Blibioteca de alocação de espaço em mémoria
#include <locale.h>//Biblioteca de Alocação de texto por região 
#include <string.h>//Biblioteca responsável por cuidar das string

int registrar()// Função responsavel por cadastrar os usuários no sitema
{
	//inicio criaçõa de variaveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final criaçõa de variaveis/string
	
	printf("Digite o CPF a ser cadastrado: ");//coletando informação do usuário
	scanf("%s", cpf);//amazenando a variavel "CPF" ultilizando  a Função string "%s"
	
	
	strcpy(arquivo, cpf); //Responsavel por copiar os valores das string
	
	FILE *file; //criar o arquivo	
	file = fopen(arquivo, "w"); //cria o arquivo e o "w" significa escrever
	fprintf(file,cpf); // alvo o valor da variavel 	
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a");// acessar o arquivo e "a" atualizar a informação
	fprintf(file,",");//salva o espao para separar a variavel por linha 
	fclose(file); //fechar o arquivo atualizado
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s",nome);//amazenando a variavel "nome" ultilizando  a Função string "%s"
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o Sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome);//amazenando a variavel "sobrenome" ultilizando  a Função string "%s"
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s",cargo);//amazenando a variavel "cargo" ultilizando  a Função string "%s"
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");
	
}

int consultar()
{
	setlocale(LC_ALL, "Portuguese");//Definição da linguagem
	
	char cpf[40];
	char conteudo[200];
	char *token;
	
	
	printf("Digite o CPF a ser Consultado: ");
	scanf( "%s",cpf);//amazenando a variavel "CPF" ultilizando  a Função string "%s"
	
	FILE *file;
	file = fopen(cpf,"r");//abre o arquivo CPF e "r" de Read (Ler) a Informação!
	
	if(file == NULL)// se a informação não existir traz a seguinte informação
	{
		printf("\nNão foi Possivel consultar o CPF Cadastrado!.\n");// informação quando não tem nenhum CPF cadastrado no banco de dados
	}
	
	while(fgets(conteudo, 200, file)!= NULL)// while (enquanto) tiver informação , armazene a informação em conteudo se for diferente de NULL (nulo
	{
		printf("\nEssas são as informações do usuário:\n");//informação aparece antes dos dados 
		
		token = strtok(conteudo,",");//variavel ultilizado para dividir a string em linhas
		printf("CPF: %s\n", token);//informação aparece antes dos dado do CPF
		
		token = strtok(NULL,",");//variavel ultilizado para dividir a string em linhas
		printf("Nome: %s\n", token);//informação aparece antes dos dado do Nome
		
		token = strtok(NULL,",");//variavel ultilizado para dividir a string em linhas
		printf("Sobrenome: %s\n", token);//informação aparece antes dos dado do Sobrenome
		
		token = strtok(NULL,",");//variavel ultilizado para dividir a string em linhas
		printf("Cargo: %s\n", token);//informação aparece antes dos dado do Cargo
	}
	
	printf("\n");//Comando ultilizado para pular uma linha no final
	
	system("pause");
	
	
}

int deletar() //Função responsavel por deletar usuários
{
	char cpf[40];

	printf("Digite o CPF do usuário a ser deletado: "); //Mensagem ao usuário
	scanf("%s",cpf); // CPF e o ponto chave do nosso cartório 
	 
	FILE *file; //Cria o arquivo 
	file = fopen(cpf,"r"); //Abre o arquivo, e o "r" é para ler o arquivo 
	fclose(file); // Obs: fechar arquivos
	
	if(file == NULL) // "E SE" o arquivo não for encontrado
	{
		printf("\nO usuário não se encontra no sistema!.\n"); //Mensagem ao usuário 
		system("pause"); //Pausa o sistema até o usuário continuar 
	}
	
	remove(cpf); // Opcao que apaga arquivos
	
	if(file != NULL) // != significa "se for diferente de a coloque b"
	{
		printf("\nO usuário foi deletado com sucesso!\n\n"); //Mensagem ao usuário
		system("pause"); //Pausa o sitema até o usuário continuar 
	}
	
}

int main()
{
    int opcao = 0;
    int laco = 1;
    char login[40] = "a";
    char senha[10] = "a";
    int comparacaologin, comparacaosenha;
    int tentativas = 0; // Variável para controlar o número de tentativas

    setlocale(LC_ALL, "Portuguese"); // Definição da linguagem

    printf("### Cartório da EBAC ###\n\n");

    for (tentativas = 0; tentativas < 3; tentativas++)// Loop para permitir até 3 tentativas
    {
        printf("Login de administrador!\n\n");
        printf("Login: "); // Solicita o login (nome de usuário)
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
            printf("Tentativas restantes: %d\n", 2 - tentativas); // Informa o número de tentativas restantes
            if (tentativas == 2) // Se for a última tentativa
            {
                printf("Você excedeu o número de tentativas. O programa será encerrado.\n");
                return 0; // Fecha o programa após 3 tentativas
            }
        }
    }

    // Caso o login tenha sido bem-sucedido, segue o resto do código
    while (1) // Inicia o loop principal do sistema
    {
        system("cls");

        setlocale(LC_ALL, "Portuguese"); // Definição da linguagem

        printf("### Cartório De Alunos Da EBAC ###\n\n");
        printf("Escolha as opções:\n\n"); // Entrada para o menu
        printf("\t1 - Registrar um Novo Aluno\n");
        printf("\t2 - Consultar Nome do Aluno\n");
        printf("\t3 - Deletar um Aluno\n\n");
        printf("\t4 - Sair do Sistema\n\n");
        printf("Opção: "); // Fim do menu

        scanf("%d", &opcao); // Armazena a escolha do usuário

        system("cls"); // Responsável por limpar a tela

        switch (opcao) // Início da escolha do usuário
        {
            case 1:
                registrar(); // Chama a função registrar
                break;

            case 2:
                consultar(); // Chama a função consultar
                break;

            case 3:
                deletar(); // Chama a função deletar
                break;

            case 4:
                printf("Obrigado por utilizar o Sistema!\n");
                return 0; // Sai do programa
                break;

            default:
                printf("Essa opção não está disponível!\n");
                system("pause");
                break;
        }
    }

    return 0; // Finaliza o programa
}

