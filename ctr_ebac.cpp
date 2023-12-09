#include <stdio.h> //Blibiotéca de Comunicação com o Usuário
#include <stdlib.h> //Blibiotéca de Locação de Espaço em Memória
#include <locale.h> //Blibioteca de Locações de Texto por Região
#include <string.h> //Blibioteca responsável por cuidar da string

int registro() //Função responsável por cadastrar os usuários no sistema
{
	//início de criação de variáveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//Fim da criação de variáveis/string
	
	printf("Digite o CPF a ser cadastrado: "); //coletando infomação do usuário
	scanf("%s", cpf); //%s refere-se a string
	
	strcpy(arquivo, cpf); //Resposável por copiar os valores das string
	
	FILE *file; // cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo e o "w" significa escrever
	fprintf(file, "CPF: "); //coleta infomação do usuário
	fprintf(file, cpf); // salvo o valor da variável
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //cria o arquivo e o "a" significa atualizar
	fprintf(file,",\nNome: "); //coletando infomação do usuário
	fclose(file); //fecha o arquivo
	
	printf("Digite o nome cadastrado: "); //coleta infomação do usuário
	scanf("%s",nome); //%s refere-se a string
	
    file = fopen(arquivo, "a"); //cria o arquivo e o "a" significa atualizar
	fprintf(file, nome); //coletando infomação do usuário
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //cria o arquivo e o "a" significa atualizar
	fprintf(file,",\nSobrenome: "); //coleta infomação do usuário
	fclose(file); //fecha o arquivo
	
	printf("Digite o sobrenome cadastrado: "); //coletando infomação do usuário
	scanf("%s", sobrenome); //%s refere-se a string
	
	file = fopen(arquivo, "a"); //cria o arquivo e o "a" significa atualizar
	fprintf(file,sobrenome); //coletando infomação do usuário
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //cria o arquivo e o "a" significa atualizar
	fprintf(file,",\nCargo: "); //coletando infomação do usuário
	fclose(file); //fecha o arquivo
	
	printf("Digite o cargo cadastrado: "); //coletando infomação do usuário
	scanf("%s", cargo); //%s refere-se a string
	
	file = fopen(arquivo, "a"); //cria o arquivo e o "a" significa atualizar
	fprintf(file,cargo); //coletando infomação do usuário
	fprintf(file, ".\n\n");
	fclose(file); // fecha o arquivo
	
	system("pause"); //pausar a tela
	
}

int consultar() //Função responsável por consultar os usuários no sistema
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	char cpf[40]; //armazena um conjunto de caracteres
	char conteudo[200]; //armazena um conjunto de caracteres
	
	printf("Digite o CPF a ser consultado:"); //coletando infomação do usuário
	scanf("%s",cpf); //%s refere-se a string
	
	FILE *file; // cria o arquivo
	file = fopen(cpf,"r"); // abre o arquivo e o "r" significa acessar dados
	
	if (file == NULL) //Arquivo inexistente, ou nulo até o momento do acesso
	{
		printf("\nNão foi possível abrir o arquivo, não localizado.\n");
	}
	
	printf("\n\nEssas são as infomações do usuário \n\n"); //coletando infomação do usuário
	
	while(fgets(conteudo, 200, file) != NULL) //Função de execultar o limite da repetição
	{
		printf("%s", conteudo); //%s refere-se a string
		
	}
	
	fclose(file); // fecha o arquivo
	system("pause"); //pausar a tela
}

int deletar() //Função responsável por deletar os usuários no sistema
{
	char cpf[40]; //armazena um conjunto de caracteres
	
	printf("Digite o CPF do usuário a ser deletado:"); //coletando infomação do usuário
	scanf("%s",cpf); //%s refere-se a string
	
	remove(cpf); //Apaga o registro do CPF
	
	FILE *file; // cria o arquivo
	file = fopen(cpf,"r"); // abre o arquivo e o "r" significa acessar dados
	
	if (file == NULL) //Arquivo inexistente, ou nulo até o momento do acesso
	{
		printf("\nUsuário deletado com sucesso!.\n\n"); //coletando infomação do usuário
		system("pause"); //pausar a tela
	}
	
	fclose(file); // fecha o arquivo    
	
}


int main() //Ponto de partida para execução do programa
{
	int opcao=0; //Definindo variáveis
	int laco=1; //É a repetição da chamada de interação
	char senhadigitada[10]="a";
	int comparacao;
	
	printf("### Cartório da EBAC ###\n\n");
	printf("Login de administrador!\n\n Digite a sua senha: ");
	scanf("%s",senhadigitada);
	
	comparacao = strcmp(senhadigitada, "admin");
	
	if(comparacao == 0)
	{
	
	
		for(laco=1;laco=1;) //Início de repeticões e limite
		{
		
			system("cls"); //responsável por limpar a tela
	
        	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
			
    		printf("\t\t\t\t    ### Cartório da EBAC ###\n\n"); //Início do menu
    		printf("\tEscolha a opção desejada no Menu\n\n"); //acesso ao menu
    		printf("\t1 - Registrar Nomes\n"); //coletando infomação do usuário
    		printf("\t2 - Consultar Nomes\n"); //acessando infomação do usuário
    		printf("\t3 - Deletar Nomes\n\n\n"); //deletando infomação do usuário    		
    		printf("\t4 - Para sair\n\n\n"); //deletando infomação do usuário
    		printf("\tEsse Softare é de livre uso dos Alunos, Colaboradores e Professores nossos da EBAC!\n\n"); //descrisção a quem pode utiliza-lo
    		printf("\t\t\t\t\t Seja Bem Vindo!\n\n\n "); //Saudações ao usuário
    		printf("\tSelecione sua Opção: "); //Final do menu
	
	    	scanf("%d", &opcao); //Armazenando a escolha do usuário
	
    		system("cls"); //responsável por limpar a tela
    	
    	
    		switch(opcao) //início da seleção do menu
    		{
           		case 1: //Comparação de sequência de valores
            	registro();
            	break; //Fim do precesso
            	
            	case 2: //Comparação de sequência de valores
            	consultar();
            	break; //Fim do precesso
            
            	case 3: //Comparação de sequência de valores
            	deletar();
            	break; //Fim do precesso
            	
            	case 4: //Comparação de sequência de valores
            	printf("Obrigado por utilizar o sistema!\n");
            	return 0;
            	break; //Fim do precesso
            
            	default:
            	printf("essa opção não está disponível, por favor retorne ao início do menu, e escolha umas das opções mostradas!\n");
    			system("pause"); //pausar a tela
            	break; //Fim do precesso
            
    		} //Fim da seleção
		}
	
	}
	
	else
		printf("Senha incorreta!");

}


