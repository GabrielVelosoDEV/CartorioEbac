#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> // biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��o de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das strings

int registro() //Fun��o respons�vel por cadastrar os usu�rios no sistema
{
	//inicio da cria��o de variaveis/strings
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da cria��o de variaveis/strings
	
	printf("Digite o CPF a ser cadastrado: "); //coletando as informa��es do usu�rio
	scanf("%s", cpf); //escaneia e armazena o dado em uma string, string = %s
	
	strcpy(arquivo, cpf); //Respons�vel por copiar o valor das strings
	
	FILE *file; //cria o arquivo 
	file = fopen(arquivo, "w"); //cria o arquivo e o "w" significa escrever
	fprintf(file,cpf); //salva o valor da variavel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //cria o arquivo e o "a" significa alterar
	fprintf(file,","); //adiciona a virgula na sequ�ncia
	fclose(file); //fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: "); //coletando as informa��es do usu�rio
	scanf("%s", nome); //escaneia e armazena o dado em uma string, string = %s
	
	file = fopen(arquivo, "a"); //cria o arquivo e o "a" significa alterar
	fprintf(file,nome); //salva o valor da variavel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //cria o arquivo e o "a" significa alterar
	fprintf(file,","); //adiciona a virgula na sequ�ncia
	fclose(file); //fecha o arquivo
	
	printf("Digite o sobrenome a ser cadastrado: "); //coletando as informa��es do usu�rio
	scanf("%s", sobrenome); //escaneia e armazena o dado em uma string, string = %s
	
	file = fopen(arquivo, "a"); //cria o arquivo e o "a" significa alterar
	fprintf(file, sobrenome); //salva o valor da variavel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //cria o arquivo e o "a" significa alterar
	fprintf(file,","); //adiciona a virgula na sequ�ncia
	fclose(file); //fecha o arquivo
	
	printf("Digite o cargo a ser cadastrado: "); //coletando as informa��es do usu�rio
	scanf("%s", cargo); //escaneia e armazena o dado em uma string, string = %s
	
	file = fopen(arquivo, "a"); //cria o arquivo e o "a" significa alterar
	fprintf(file, cargo); //salva o valor da variavel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //cria o arquivo e o "a" significa alterar
	fprintf(file,"."); //adiciona o ponto final na sequ�ncia
	fclose(file); //fecha o arquivo
	
	system("pause"); //pausa o sistema 
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
	 
	//inicio da cria��o de variaveis/strings
    char cpf[40]; 
    char conteudo[200];
    //fim da cria��o de variaveis/strings
    
    printf("Digite o CPF a ser consultado: "); //consultando as informa��es do usu�rio
    scanf("%s",cpf); //escaneia e armazena o dado em uma string, string = %s
    
    FILE *file; //cria o arquivo 
    file = fopen(cpf,"r"); //cria o arquivo e o "r" significa ler
    
    if(file == NULL) //se o arquivo for igual a "nenhum" ele apresentara a mensagem
    {
    	printf("N�o foi possivel abrir o arquivo, n�o localizado.\n"); //mensagem a ser exibida
	}
	
	while(fgets(conteudo, 200, file) != NULL); //Loop para ler o conte�do do arquivo linha por linha
	{
		printf("\nEssas s�o as informa��es do usu�rio: "); //mensagem a ser exibida
		printf("%s", conteudo); //Imprime a linha lida do arquivo
		printf("\n\n"); //adiciona duas linhas para separar visualmente
	}
	
	system("pause"); //pausa o sistema
}

int deletar()
{
	setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
	
	//inicio da cria��o de variaveis/strings
	char cpf[40];
	//fim da cria��o de variaveis/strings
	
	printf("Digite o CPF do usu�rio a ser deletado: "); //consultando as informa��es do usu�rio
	scanf("%s",cpf); //escaneia e armazena o dado em uma string, string = %s
	
	remove(cpf); //deleta o dado
	
    FILE *file; //cria o arquivo 
    file = fopen(cpf,"r"); //cria o arquivo e o "r" significa ler

    if(file == NULL) //se o arquivo for igual a "nenhum" ele apresentara a mensagem
    {
     printf("O usu�rio foi deletado com sucesso ou j� n�o se encontrava no sistema!.\n"); //mensagem a ser exibida
	}
	
	 system("pause"); //pausa o sistema
}

int main()
{
	int opcao=0;   //definindo vari�veis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
	      system("cls"); //respons�vel por limpar as informa��es da tela
	
	      setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
	
	      printf("## Cat�rio da EBAC ##\n\n"); //inicio do menu
	      printf("Escolha a op��o desejada do menu:\n\n");
       	  printf("\t1 - Registrar nomes\n");
	      printf("\t2 - Consultar nomes\n");
	      printf("\t3 - Deletar nomes\n\n"); 
	      printf("Op��o: "); //fim do menu

	      scanf("%d", &opcao); //armazenando a escolha do usuario
	
	      system("cls"); //respons�vel por limpar as informa��es da tela
	      
	      switch(opcao) //inicio da sele��o do menu
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
