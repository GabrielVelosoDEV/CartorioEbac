#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> // biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocação de texto por região
#include <string.h> //biblioteca responsável por cuidar das strings

int registro() //Função responsável por cadastrar os usuários no sistema
{
	//inicio da criação de variaveis/strings
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da criação de variaveis/strings
	
	printf("Digite o CPF a ser cadastrado: "); //coletando as informações do usuário
	scanf("%s", cpf); //escaneia e armazena o dado em uma string, string = %s
	
	strcpy(arquivo, cpf); //Responsável por copiar o valor das strings
	
	FILE *file; //cria o arquivo 
	file = fopen(arquivo, "w"); //cria o arquivo e o "w" significa escrever
	fprintf(file,cpf); //salva o valor da variavel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //cria o arquivo e o "a" significa alterar
	fprintf(file,","); //adiciona a virgula na sequência
	fclose(file); //fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: "); //coletando as informações do usuário
	scanf("%s", nome); //escaneia e armazena o dado em uma string, string = %s
	
	file = fopen(arquivo, "a"); //cria o arquivo e o "a" significa alterar
	fprintf(file,nome); //salva o valor da variavel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //cria o arquivo e o "a" significa alterar
	fprintf(file,","); //adiciona a virgula na sequência
	fclose(file); //fecha o arquivo
	
	printf("Digite o sobrenome a ser cadastrado: "); //coletando as informações do usuário
	scanf("%s", sobrenome); //escaneia e armazena o dado em uma string, string = %s
	
	file = fopen(arquivo, "a"); //cria o arquivo e o "a" significa alterar
	fprintf(file, sobrenome); //salva o valor da variavel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //cria o arquivo e o "a" significa alterar
	fprintf(file,","); //adiciona a virgula na sequência
	fclose(file); //fecha o arquivo
	
	printf("Digite o cargo a ser cadastrado: "); //coletando as informações do usuário
	scanf("%s", cargo); //escaneia e armazena o dado em uma string, string = %s
	
	file = fopen(arquivo, "a"); //cria o arquivo e o "a" significa alterar
	fprintf(file, cargo); //salva o valor da variavel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //cria o arquivo e o "a" significa alterar
	fprintf(file,"."); //adiciona o ponto final na sequência
	fclose(file); //fecha o arquivo
	
	system("pause"); //pausa o sistema 
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
	 
	//inicio da criação de variaveis/strings
    char cpf[40]; 
    char conteudo[200];
    //fim da criação de variaveis/strings
    
    printf("Digite o CPF a ser consultado: "); //consultando as informações do usuário
    scanf("%s",cpf); //escaneia e armazena o dado em uma string, string = %s
    
    FILE *file; //cria o arquivo 
    file = fopen(cpf,"r"); //cria o arquivo e o "r" significa ler
    
    if(file == NULL) //se o arquivo for igual a "nenhum" ele apresentara a mensagem
    {
    	printf("Não foi possivel abrir o arquivo, não localizado.\n"); //mensagem a ser exibida
	}
	
	while(fgets(conteudo, 200, file) != NULL); //Loop para ler o conteúdo do arquivo linha por linha
	{
		printf("\nEssas são as informações do usuário: "); //mensagem a ser exibida
		printf("%s", conteudo); //Imprime a linha lida do arquivo
		printf("\n\n"); //adiciona duas linhas para separar visualmente
	}
	
	system("pause"); //pausa o sistema
}

int deletar()
{
	setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
	
	//inicio da criação de variaveis/strings
	char cpf[40];
	//fim da criação de variaveis/strings
	
	printf("Digite o CPF do usuário a ser deletado: "); //consultando as informações do usuário
	scanf("%s",cpf); //escaneia e armazena o dado em uma string, string = %s
	
	remove(cpf); //deleta o dado
	
    FILE *file; //cria o arquivo 
    file = fopen(cpf,"r"); //cria o arquivo e o "r" significa ler

    if(file == NULL) //se o arquivo for igual a "nenhum" ele apresentara a mensagem
    {
     printf("O usuário foi deletado com sucesso ou já não se encontrava no sistema!.\n"); //mensagem a ser exibida
	}
	
	 system("pause"); //pausa o sistema
}

int main()
{
	int opcao=0;   //definindo variáveis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
	      system("cls"); //responsável por limpar as informações da tela
	
	      setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
	
	      printf("## Catório da EBAC ##\n\n"); //inicio do menu
	      printf("Escolha a opção desejada do menu:\n\n");
       	  printf("\t1 - Registrar nomes\n");
	      printf("\t2 - Consultar nomes\n");
	      printf("\t3 - Deletar nomes\n\n"); 
	      printf("Opção: "); //fim do menu

	      scanf("%d", &opcao); //armazenando a escolha do usuario
	
	      system("cls"); //responsável por limpar as informações da tela
	      
	      switch(opcao) //inicio da seleção do menu
		   {
	      	case 1:
	        registro(); //chamada de funções
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
