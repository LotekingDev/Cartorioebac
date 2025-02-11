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
	
	printf("Digite o cargo a ser cadastrado; ");
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

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do usuário a ser deletado: ");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("O usuário não se encontra no sistema.\n");
		system("pause");
		
	}
}

int main()
 {
	int opcao=0;
	int laco=1;
	char login[40]="a";
	char senha[10]="a";
	int comparacaologin, comparacaosenha;
	
	setlocale(LC_ALL, "Portuguese");//Definição da linguagems

	printf("###Cartório da EBAC ###\n\n");
	printf("login de adminstrador!\n\nLogin: "); // Solicita o login (nome de usuário)
	scanf("%s",login);
	
	
	printf("Senha: "); // Solicita a senha
	scanf("%s",senha);
	
	comparacaologin = strcmp(login, "ebac");// Compara login
	
	comparacaosenha = strcmp(senha, "admin");// Compara senha
	
	if(comparacaologin == 0 && comparacaosenha == 0)
	{
	
	
	   for(laco=1;laco=1;)//repetição do sistema 
	 { 
	
	    system("cls");
	   
	    setlocale(LC_ALL, "Portuguese");//Definição da linguagems
	
	    printf("###Cartório De Alunos Da EBAC###\n\n");
	    printf("Escolha As Opções\n\n");//entrada para o menu
   	    printf("\t1 - Registra Um Novo Aluno\n");
	    printf("\t2 - Consutar Nome Do Aluno\n");
	    printf("\t3 - Deletar Um Aluno\n\n");
	    printf("\t4 - Sair do Sistema\n\n");
	    printf("Opçâo: ");//Fim do menu
	
	    scanf("%d", &opcao);//amazenando a escolha do usuário
	
	    system("cls");//responsavel por limpar a tela
	
	    switch(opcao)//inicio de escolha do usuário
	    {
	  	  case 1:
	  	  registrar();//chama de funções
		  break;
		
		  case 2:
		  consultar();
		  break;
		
		  case 3:
		  deletar();
		  break;
		
		  case 4:
		  printf("Obrigado por ultilizar o Sistema!\n");
		  return 0;
		  break;
		
		  default:
		  printf("Essa Opçâo Não Está Disponivel!\n");
		  system("pause");
		  break;	
	    }//fim da escolha do usuário
     }
   }
  
  else
        printf("Senha incorreta!");
 }

