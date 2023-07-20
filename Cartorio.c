#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��o de texto po regi�o
#include <string.h> //biblioteca das strings


int cadastro()//Fun��o respons�vel por cadastrar usu�rios
{
	//Inicio da cria��o de variaveis/string
	char arquivo[40];
    char cpf[40];
    char nome[40];
    char sobrenome[40];
    char cargo[40];
    //Fim da cria��o de variaveis
    
    printf("Digite o CPF a ser cadastrado: ");//Coletando informa��o do usu�rio
    scanf("%s", &cpf); //%s - refere-se a string
      
    strcpy(arquivo, cpf); //responsavel por copiar os valores das strings - est� dizendo que arquivo � igual ao CPF (o nome do arquivo ser� o CPF).
    FILE *file; //cria o arquivo no computador
   
    file = fopen(arquivo, "w"); //cria o arquivo no computador
    fprintf(file, "CPF: ");
   	fprintf(file, cpf); //salva o valor do CPF no arquivo
    fclose(file); //fecha o arquivo
    
    file = fopen(arquivo, "a"); //"a" - Adiciona novas informa��es no arquivo
    fprintf(file, "\nNOME: ");
    fclose(file);
    
    printf("Digite o nome a ser cadastrado: ");
    scanf("%s", &nome);
    
    file = fopen(arquivo, "a");
    fprintf(file, nome);//salva o valor do nome no arquivo
    fclose(file);
    
    file = fopen(arquivo, "a");
    fprintf(file, "\nSOBRENOME: ");
    fclose(file);
	    
    printf("Digite o sobrenome a ser cadastrado: ");
    scanf("%s", &sobrenome);
    
    file = fopen(arquivo, "a");
    fprintf(file, sobrenome);//salva o valor do sobrenome no arquivo
    fclose(file);
    
    file = fopen(arquivo, "a");
    fprintf(file, "\nCARGO: ");
    fclose(file);
    
    printf("Digite o cargo: ");
    scanf("%s", &cargo);
    printf("\n");
    
    file = fopen(arquivo, "a");
	fprintf(file, cargo);//salva o valor do cargo no arquivo
	fprintf(file, "\n\n");
	fclose(file);
	
	system("pause"); //Para o sistema pausar para o usu�rio conseguir ler a mensagem
	
    
}


int consultar()
{
	
	setlocale(LC_ALL, "Portuguese"); //Definindo o idioma do pa�s
	
    char cpf[40];
    char conteudo[200];
    
    printf("Digite o CPF a ser consultado: ");
    scanf("%s", cpf);
    
    FILE *file; //significa que precisamos consultar um arquivo no computador
	file = fopen(cpf, "r");
	
	if(file == NULL)//caso o CPF n�o esteja cadastrado, retorna mensagem informando
	{
		printf("CPF n�o cadastrado em nosso banco de dados! \n\n");
	}
    
    printf("\nEssas s�o as informa��es do usu�rio: \n\n");
    
    while(fgets(conteudo, 200, file)!= NULL)//pesquisa o arquivo do CPF solicitado e retorna com as informa��es
    {
    	printf("%s", conteudo);
    }
    fclose(file);
    
    system("pause");
    
}


int deletar()
{
	char cpf[40];
	int resposta;
    
    
	printf("Digite o CPF do usu�rio a ser deletado: ");
	scanf("%s", &cpf);
	
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)//caso o CPF n�o esteja cadastrado, retorna mensagem informando
	{
		fclose(file);
		printf("\nO usu�rio n�o est� cadastrado!\n\n");
		system("pause");
		fclose(file);
			
		main();//retorna ao menu inicial
		
	}
	
	else
	{
	printf("\nVoc� realmente deseja deletar este usu�rio?\n\n");//questiona se o usu�rio quer deletar o aquivo
	printf("1 - Sim\n");
	printf("2 - N�o\n\n");
    printf("Digite sua op��o: ");
    scanf("%d", &resposta);//faz analise do questionamento
    }
    
    if(resposta == 1) //caso a analise confirme a inten��o, deleta o CPF solicitado
	{		
	    fclose(file);
	    remove(cpf);
	    printf("\nUsu�rio foi deletado com sucesso!\n\n");
	    system("pause");
	}
	    
    if(resposta == 2) //caso o usu�rio n�o queira deletar, retorna essa mensagem
	{
		fclose(file);
	    printf("\nO usu�rio n�o foi deletado!\n\n");
	    system("pause");
    }
    if(resposta >=3 || resposta <=0) //caso o usu�rio escolha uma op��o fora das 2 disponiveis
    {
    	fclose(file);
    	printf("\nEsta op��o n�o est� disponivel!");
    	printf("\nO usu�rio n�o foi deletado!\n\n");
    	system("pause");
	}
	
	
	fclose(file);
	
	
	
	
	
}

int sair ()
{
	int resposta=0;
	
	printf("Voce tem certeza que deseja sair do sistema?\n\n"); //Faz a valida��o se o usu�rio quer sair do sistema
    printf("1 - Sair\n");
	printf("2 - Voltar ao menu\n\n");
	printf("Digite uma op��o: ");
	scanf("%d", &resposta); //guarda a resposta do usu�rio
	
	switch(resposta) //faz a analise da resposta do usu�rio
	{
		case 1:
		system("cls"); //limpa a tela
		printf("\nObrigado por utilizar o sistema!\n");
	    printf("\n\n\n*** Software desenvolvido por Vinicius Baptista ***\n\n");
	    system("pause");
	    exit(0);//retorna 0 para o sistema, e o encerra
	    break;
	    
		case 2:
		main(); //retorna ao menu principal
		break;
	
	    default:
    	printf("\nOp��o invalida, o sistema ir� retornar ao menu inicial!\n\n"); //retorna mensagem, e ap�s retorna o sistema ao menu principal
    	system("pause");
    	break;
	}
}

int main ()
{
	int opcao=0;//Definindo variaveis
	int repetir=1;
	char senhadigitada[10]="a";
	int comparacao;
	
	setlocale(LC_ALL, "Portuguese"); //Definindo o idioma do pa�s
	
	printf("### Cart�rio da EBAC ###\n\n");
	printf("Login de administrador\n\nDigite a sua senha: ");
	scanf("%s", senhadigitada); //salva a senha digitada
	
	comparacao = strcmp(senhadigitada, "admin"); //faz a compara��o da senha digitada com a variavel
	
	if(comparacao == 0) //caso a senha esteja certa segue o codigo
	{
		system("cls");	
		for(repetir=1;repetir=1;) // la�o de repeti��o
		{
	
		    system("cls");
		
		    setlocale(LC_ALL, "Portuguese"); //Definindo o idioma do pa�s
	
		    printf("### Cart�rio da EBAC ###\n\n"); //Inicio do menu
		    printf("Escolha a op��o desejada do menu:\n\n");
		    printf("\t1 - Registrar nomes\n");
		    printf("\t2 - Consultar nomes\n");
		    printf("\t3 - Deletar nomes\n\n");
		    printf("\t4 - Sair do sistema\n\n");
		    printf("Op��o:"); //Fim do menu
	   		   	
		    scanf("%d", &opcao); //Armazenando a escolha do usu�rio
	 	
	 
		    system("cls"); //Limpar a tela ap�s escolha do usu�rio
	    
		    switch(opcao) //Inicio da sele��o
		    {
		    	case 1:
		    	cadastro();	//chamada de fun��o cadastro
			    break;
		    
			    case 2:
			    consultar(); //chamada de fun��o consultar
		     	break;
	     	
		     	case 3:
		     	deletar(); //chamada de fun��o deletar
		    	break;
	    	
		    	case 4:
		    	sair();
		        break;
	     		     	
		     	default:
		     	printf("Esta op��o n�o est� disponivel!\n\n"); //caso o usu�rio escolha uma op��o fora das 4 disponiveis
				system("pause"); 
				break; //Fim da sele��o
			
			
			
			}
	    }
  	  
	}
	
	else
		printf("\nSenha incorreta!\n\n"); // caso a senha do login esteja errada
		system("pause");
		system("cls");
		main();
}

