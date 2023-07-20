#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocação de texto po região
#include <string.h> //biblioteca das strings


int cadastro()//Função responsável por cadastrar usuários
{
	//Inicio da criação de variaveis/string
	char arquivo[40];
    char cpf[40];
    char nome[40];
    char sobrenome[40];
    char cargo[40];
    //Fim da criação de variaveis
    
    printf("Digite o CPF a ser cadastrado: ");//Coletando informação do usuário
    scanf("%s", &cpf); //%s - refere-se a string
      
    strcpy(arquivo, cpf); //responsavel por copiar os valores das strings - está dizendo que arquivo é igual ao CPF (o nome do arquivo será o CPF).
    FILE *file; //cria o arquivo no computador
   
    file = fopen(arquivo, "w"); //cria o arquivo no computador
    fprintf(file, "CPF: ");
   	fprintf(file, cpf); //salva o valor do CPF no arquivo
    fclose(file); //fecha o arquivo
    
    file = fopen(arquivo, "a"); //"a" - Adiciona novas informações no arquivo
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
	
	system("pause"); //Para o sistema pausar para o usuário conseguir ler a mensagem
	
    
}


int consultar()
{
	
	setlocale(LC_ALL, "Portuguese"); //Definindo o idioma do país
	
    char cpf[40];
    char conteudo[200];
    
    printf("Digite o CPF a ser consultado: ");
    scanf("%s", cpf);
    
    FILE *file; //significa que precisamos consultar um arquivo no computador
	file = fopen(cpf, "r");
	
	if(file == NULL)//caso o CPF não esteja cadastrado, retorna mensagem informando
	{
		printf("CPF não cadastrado em nosso banco de dados! \n\n");
	}
    
    printf("\nEssas são as informações do usuário: \n\n");
    
    while(fgets(conteudo, 200, file)!= NULL)//pesquisa o arquivo do CPF solicitado e retorna com as informações
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
    
    
	printf("Digite o CPF do usuário a ser deletado: ");
	scanf("%s", &cpf);
	
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)//caso o CPF não esteja cadastrado, retorna mensagem informando
	{
		fclose(file);
		printf("\nO usuário não está cadastrado!\n\n");
		system("pause");
		fclose(file);
			
		main();//retorna ao menu inicial
		
	}
	
	else
	{
	printf("\nVocê realmente deseja deletar este usuário?\n\n");//questiona se o usuário quer deletar o aquivo
	printf("1 - Sim\n");
	printf("2 - Não\n\n");
    printf("Digite sua opção: ");
    scanf("%d", &resposta);//faz analise do questionamento
    }
    
    if(resposta == 1) //caso a analise confirme a intenção, deleta o CPF solicitado
	{		
	    fclose(file);
	    remove(cpf);
	    printf("\nUsuário foi deletado com sucesso!\n\n");
	    system("pause");
	}
	    
    if(resposta == 2) //caso o usuário não queira deletar, retorna essa mensagem
	{
		fclose(file);
	    printf("\nO usuário não foi deletado!\n\n");
	    system("pause");
    }
    if(resposta >=3 || resposta <=0) //caso o usuário escolha uma opção fora das 2 disponiveis
    {
    	fclose(file);
    	printf("\nEsta opção não está disponivel!");
    	printf("\nO usuário não foi deletado!\n\n");
    	system("pause");
	}
	
	
	fclose(file);
	
	
	
	
	
}

int sair ()
{
	int resposta=0;
	
	printf("Voce tem certeza que deseja sair do sistema?\n\n"); //Faz a validação se o usuário quer sair do sistema
    printf("1 - Sair\n");
	printf("2 - Voltar ao menu\n\n");
	printf("Digite uma opção: ");
	scanf("%d", &resposta); //guarda a resposta do usuário
	
	switch(resposta) //faz a analise da resposta do usuário
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
    	printf("\nOpção invalida, o sistema irá retornar ao menu inicial!\n\n"); //retorna mensagem, e após retorna o sistema ao menu principal
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
	
	setlocale(LC_ALL, "Portuguese"); //Definindo o idioma do país
	
	printf("### Cartório da EBAC ###\n\n");
	printf("Login de administrador\n\nDigite a sua senha: ");
	scanf("%s", senhadigitada); //salva a senha digitada
	
	comparacao = strcmp(senhadigitada, "admin"); //faz a comparação da senha digitada com a variavel
	
	if(comparacao == 0) //caso a senha esteja certa segue o codigo
	{
		system("cls");	
		for(repetir=1;repetir=1;) // laço de repetição
		{
	
		    system("cls");
		
		    setlocale(LC_ALL, "Portuguese"); //Definindo o idioma do país
	
		    printf("### Cartório da EBAC ###\n\n"); //Inicio do menu
		    printf("Escolha a opção desejada do menu:\n\n");
		    printf("\t1 - Registrar nomes\n");
		    printf("\t2 - Consultar nomes\n");
		    printf("\t3 - Deletar nomes\n\n");
		    printf("\t4 - Sair do sistema\n\n");
		    printf("Opção:"); //Fim do menu
	   		   	
		    scanf("%d", &opcao); //Armazenando a escolha do usuário
	 	
	 
		    system("cls"); //Limpar a tela após escolha do usuário
	    
		    switch(opcao) //Inicio da seleção
		    {
		    	case 1:
		    	cadastro();	//chamada de função cadastro
			    break;
		    
			    case 2:
			    consultar(); //chamada de função consultar
		     	break;
	     	
		     	case 3:
		     	deletar(); //chamada de função deletar
		    	break;
	    	
		    	case 4:
		    	sair();
		        break;
	     		     	
		     	default:
		     	printf("Esta opção não está disponivel!\n\n"); //caso o usuário escolha uma opção fora das 4 disponiveis
				system("pause"); 
				break; //Fim da seleção
			
			
			
			}
	    }
  	  
	}
	
	else
		printf("\nSenha incorreta!\n\n"); // caso a senha do login esteja errada
		system("pause");
		system("cls");
		main();
}

