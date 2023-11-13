#include <stdio.h> //biblioteca de comunica��o do usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��o de texto por regi�o
#include <string.h> //bibliotca respons�vel por cuidar das string

int registro() //fun��o respons�vel por registrar os usu�rios no sistema
{
	//inicio da cria��o de vari�veis/strings do registro
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da cria��o de vari�veis/strings do registro
	
	printf("Digite o CPF a ser cadastrado: "); //coletando informa��o do usu�rio
	scanf("%s", cpf);
	
	strcpy(arquivo, cpf); //Respons�vel por copiar os valores das strings
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo
	fprintf(file,cpf); //salva o valor da variavel
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a"); 
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: "); //salva o nome a ser registrado
	scanf("%s",nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: "); //salva o sobrenome a ser registrado
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: "); //salva o cargo a ser registrado
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");
	//fim do sistema de registro
}

int consulta() //fun��o respons�vel por consultar um CPF j� registrado
{
	setlocale(LC_ALL, "Portuguese");
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: "); //recebe o cpf a ser consultado
	scanf("%s",cpf);
	
	FILE *file; //abrir 
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("N�o foi possivel abrir o arquivo, n�o localizado!.\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEstas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");	
	}
	fclose(file);
	system("pause");
	//fim do sistema de consulta
}


int deletar() //fun��o responsavel pela exclus�o do CPF j� registrado
{
	char cpf[40];
	
	printf("Digite o CPF a ser deletado: "); //coletando o CPF a ser deletado
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL) //fun��o para o caso de o usu�rio n�o estar registrado
	{
		fclose(file);
		printf("O usu�rio n�o se encontra registrado no sistema!.\n");
		system("pause");
	}
	
	else if (file != NULL)
	{
		fclose(file);
		printf("Usu�rio deletado com sucesso!\n");
		system("pause");
		remove (cpf);
	}
	
}



int main()
{
	int option=0; //Definido vari�veis
	int x=1; 
	
	for(x=1;x=1;)
	{
		
		system("cls");
		
		setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
		printf("### Cart�rio Ebac ###\n\n"); //inicio do menu
		printf("Escolha a op��o desejada listada no menu abaixo:\n\n");
		printf("\t1 - Registrar Aluno\n");
		printf("\t2 - Consultar Aluno Registrado \n");
		printf("\t3 - Deletar Aluno Registrado \n\n"); 
		printf("Op��o:");//final do menu

		scanf("%d", &option); //armazenar escolha do usu�rio
	
		system("cls"); //fun��o respons�vel por limpar a tela
	
	
		switch(option)
		{
			case 1:
			registro(); //chamada de fun��es
			break;
			
			case 2:
			consulta();
			break;
			
			case 3:
			deletar();
			break;
			
			default: 
			printf("Essa op��o n�o est� disponivel!\n");
			system("pause");
			break;
		}
		
	
		}
}

