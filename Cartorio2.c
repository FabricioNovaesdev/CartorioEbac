#include <stdio.h> // biblioteca de comunicaçao de usuário 
#include <stdlib.h>// biblioteca de alocaçao de espaço de memoria 
#include <locale.h>// biblioteca de alocaçao de texto por regiao 
#include <string.h>//biblioteca responsavel por cuidar das string

int registro()//funçao responsavel por cadastras os usuarios do sistema 
{	// Criaçao das variaveis / String
	char arquivo[40]; 
	char cpf[40]; //CHAR deve ser usado como texto , mas tambem pode ser usado para numeros na criaçao de uma string.
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//Final da criação de variavesis / String
	
	printf("Digite o CPF a ser cadastrado: "); //coletando info do usuario 
	scanf("%sc", cpf); // %s de refere-se a String
	
	
	strcpy(arquivo, cpf); // Responsavel por copiar os valores das string .
	
	FILE *file; // Para criar um arquivo EX: acessar o FILE - Criar um file.
	file = fopen(arquivo,"w"); // F open = Abrir um arquivo com o nome da variavel , no caso (Arquivo) . "W"escrever  para criar arquivo novo .
	fprintf(file,cpf); // Salvar o valor da variavel.
	fclose(file); // Fechar o arquivo .
	
	file = fopen(arquivo, "a"); // file para abrir o arquivo e acessar o que tem dentro dele com o "A" = acessar arquivo ja criado 
	fprintf(file,","); // Para colocar virgulas
	fclose(file); // para fechar arquivo 
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s",nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");
	
	
}
int consulta()
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a Linguagem , uma funcao nao encherga a outra . 
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o cpf a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("Não foi possivel abrir o arquivo, não localizado.\n");	
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas são as informações do usuário:\n ");
		printf("%s", conteudo);
		printf("\n\n");	
	}
	
	system("pause");
	
			
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do usuario a  ser deletado: ");
	scanf("%s",cpf); 	
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r"); 
	
	if(file == NULL)
	{
		printf("O usuarui foi deletado com sucesso!. \n");
	 	system("pause");
	} 
	
}


int main( )
	{ 
	int opcao=0; //Definindo as variaveis 
	int laco=1;
	
	for(laco=1;laco=1;)
	{
		system("cls");
	
		setlocale(LC_ALL, "Portuguese"); //Definindo a Linguagem
	
		printf("### Cartório da EBAC ### \n\n"); // Inicio do Menu
		printf("Escolha a opçao desejada do menu:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n"); 
		printf("Opção: ");// Fim do Menu
								

		scanf("%d", &opcao); // Inicio da seleção 
	
		system("cls"); // Responsavel por limpar a tela 
		 
		//inicio da selação do menu
		switch(opcao) // Melhor opção para menu , ajuda o progama a ficar mais leve .
		{
			case 1: 
			registro();// Chamada de função 
			break;
			
			case 2:
			consulta();
			break;
			
			case 3:
			deletar();
			break;
			
			default:
			printf("Essa opção não está disponivel!\n");
			system("pause");
			break;	
		}		
	
	}
}
