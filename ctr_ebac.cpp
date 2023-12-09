#include <stdio.h> //Blibiot�ca de Comunica��o com o Usu�rio
#include <stdlib.h> //Blibiot�ca de Loca��o de Espa�o em Mem�ria
#include <locale.h> //Blibioteca de Loca��es de Texto por Regi�o
#include <string.h> //Blibioteca respons�vel por cuidar da string

int registro() //Fun��o respons�vel por cadastrar os usu�rios no sistema
{
	//in�cio de cria��o de vari�veis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//Fim da cria��o de vari�veis/string
	
	printf("Digite o CPF a ser cadastrado: "); //coletando infoma��o do usu�rio
	scanf("%s", cpf); //%s refere-se a string
	
	strcpy(arquivo, cpf); //Respos�vel por copiar os valores das string
	
	FILE *file; // cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo e o "w" significa escrever
	fprintf(file, "CPF: "); //coleta infoma��o do usu�rio
	fprintf(file, cpf); // salvo o valor da vari�vel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //cria o arquivo e o "a" significa atualizar
	fprintf(file,",\nNome: "); //coletando infoma��o do usu�rio
	fclose(file); //fecha o arquivo
	
	printf("Digite o nome cadastrado: "); //coleta infoma��o do usu�rio
	scanf("%s",nome); //%s refere-se a string
	
    file = fopen(arquivo, "a"); //cria o arquivo e o "a" significa atualizar
	fprintf(file, nome); //coletando infoma��o do usu�rio
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //cria o arquivo e o "a" significa atualizar
	fprintf(file,",\nSobrenome: "); //coleta infoma��o do usu�rio
	fclose(file); //fecha o arquivo
	
	printf("Digite o sobrenome cadastrado: "); //coletando infoma��o do usu�rio
	scanf("%s", sobrenome); //%s refere-se a string
	
	file = fopen(arquivo, "a"); //cria o arquivo e o "a" significa atualizar
	fprintf(file,sobrenome); //coletando infoma��o do usu�rio
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //cria o arquivo e o "a" significa atualizar
	fprintf(file,",\nCargo: "); //coletando infoma��o do usu�rio
	fclose(file); //fecha o arquivo
	
	printf("Digite o cargo cadastrado: "); //coletando infoma��o do usu�rio
	scanf("%s", cargo); //%s refere-se a string
	
	file = fopen(arquivo, "a"); //cria o arquivo e o "a" significa atualizar
	fprintf(file,cargo); //coletando infoma��o do usu�rio
	fprintf(file, ".\n\n");
	fclose(file); // fecha o arquivo
	
	system("pause"); //pausar a tela
	
}

int consultar() //Fun��o respons�vel por consultar os usu�rios no sistema
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	char cpf[40]; //armazena um conjunto de caracteres
	char conteudo[200]; //armazena um conjunto de caracteres
	
	printf("Digite o CPF a ser consultado:"); //coletando infoma��o do usu�rio
	scanf("%s",cpf); //%s refere-se a string
	
	FILE *file; // cria o arquivo
	file = fopen(cpf,"r"); // abre o arquivo e o "r" significa acessar dados
	
	if (file == NULL) //Arquivo inexistente, ou nulo at� o momento do acesso
	{
		printf("\nN�o foi poss�vel abrir o arquivo, n�o localizado.\n");
	}
	
	printf("\n\nEssas s�o as infoma��es do usu�rio \n\n"); //coletando infoma��o do usu�rio
	
	while(fgets(conteudo, 200, file) != NULL) //Fun��o de execultar o limite da repeti��o
	{
		printf("%s", conteudo); //%s refere-se a string
		
	}
	
	fclose(file); // fecha o arquivo
	system("pause"); //pausar a tela
}

int deletar() //Fun��o respons�vel por deletar os usu�rios no sistema
{
	char cpf[40]; //armazena um conjunto de caracteres
	
	printf("Digite o CPF do usu�rio a ser deletado:"); //coletando infoma��o do usu�rio
	scanf("%s",cpf); //%s refere-se a string
	
	remove(cpf); //Apaga o registro do CPF
	
	FILE *file; // cria o arquivo
	file = fopen(cpf,"r"); // abre o arquivo e o "r" significa acessar dados
	
	if (file == NULL) //Arquivo inexistente, ou nulo at� o momento do acesso
	{
		printf("\nUsu�rio deletado com sucesso!.\n\n"); //coletando infoma��o do usu�rio
		system("pause"); //pausar a tela
	}
	
	fclose(file); // fecha o arquivo    
	
}


int main() //Ponto de partida para execu��o do programa
{
	int opcao=0; //Definindo vari�veis
	int laco=1; //� a repeti��o da chamada de intera��o
	char senhadigitada[10]="a";
	int comparacao;
	
	printf("### Cart�rio da EBAC ###\n\n");
	printf("Login de administrador!\n\n Digite a sua senha: ");
	scanf("%s",senhadigitada);
	
	comparacao = strcmp(senhadigitada, "admin");
	
	if(comparacao == 0)
	{
	
	
		for(laco=1;laco=1;) //In�cio de repetic�es e limite
		{
		
			system("cls"); //respons�vel por limpar a tela
	
        	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
			
    		printf("\t\t\t\t    ### Cart�rio da EBAC ###\n\n"); //In�cio do menu
    		printf("\tEscolha a op��o desejada no Menu\n\n"); //acesso ao menu
    		printf("\t1 - Registrar Nomes\n"); //coletando infoma��o do usu�rio
    		printf("\t2 - Consultar Nomes\n"); //acessando infoma��o do usu�rio
    		printf("\t3 - Deletar Nomes\n\n\n"); //deletando infoma��o do usu�rio    		
    		printf("\t4 - Para sair\n\n\n"); //deletando infoma��o do usu�rio
    		printf("\tEsse Softare � de livre uso dos Alunos, Colaboradores e Professores nossos da EBAC!\n\n"); //descris��o a quem pode utiliza-lo
    		printf("\t\t\t\t\t Seja Bem Vindo!\n\n\n "); //Sauda��es ao usu�rio
    		printf("\tSelecione sua Op��o: "); //Final do menu
	
	    	scanf("%d", &opcao); //Armazenando a escolha do usu�rio
	
    		system("cls"); //respons�vel por limpar a tela
    	
    	
    		switch(opcao) //in�cio da sele��o do menu
    		{
           		case 1: //Compara��o de sequ�ncia de valores
            	registro();
            	break; //Fim do precesso
            	
            	case 2: //Compara��o de sequ�ncia de valores
            	consultar();
            	break; //Fim do precesso
            
            	case 3: //Compara��o de sequ�ncia de valores
            	deletar();
            	break; //Fim do precesso
            	
            	case 4: //Compara��o de sequ�ncia de valores
            	printf("Obrigado por utilizar o sistema!\n");
            	return 0;
            	break; //Fim do precesso
            
            	default:
            	printf("essa op��o n�o est� dispon�vel, por favor retorne ao in�cio do menu, e escolha umas das op��es mostradas!\n");
    			system("pause"); //pausar a tela
            	break; //Fim do precesso
            
    		} //Fim da sele��o
		}
	
	}
	
	else
		printf("Senha incorreta!");

}


