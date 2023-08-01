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
    int resposta=0;
    //Fim da criação de variaveis
    
    setlocale(LC_ALL, "Portuguese"); //Definindo o idioma do país
    
    printf("REGISTRO DE NOMES\n\n");
    
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
	
	printf("Cadastro finalizado com sucesso!\n\n");
		
	printf("----------------------------------------\n\n");
	printf("Voce deseja realizar outro cadastro?\n\n");
	printf("1 - Novo cadastro");
	printf("\n2 - Voltar ao menu inicial\n");
	printf("\nDigite a opção desejada: ");
	scanf("%d", &resposta);//faz a analise da resposta do usuario e salva na variavel
	
	switch(resposta)
	{
		case 1:
		system("cls");
		cadastro(); // recomeça a função cadastro
		break;
		
		case 2:
		return; // retorna ao menu inicial
		break;
		
		default:
		printf("\nOpção invalida, o sistema irá retornar ao menu inicial!\n\n"); //retorna mensagem, e após retorna o sistema ao menu principal
    	system("pause");//pause o sistema para o usuario ler a mensagem
    	break;
	}
	
}


int consultar()
{
	
	setlocale(LC_ALL, "Portuguese"); //Definindo o idioma do país
	
    char cpf[40];
    char conteudo[200];
    char resposta=0;
    
    printf("Digite o CPF a ser consultado: ");
    scanf("%s", cpf);//recebe o numero do CPF a ser consultado e salva na variavel
    
    FILE *file; //significa que precisamos consultar um arquivo no computador
	file = fopen(cpf, "r");//vai ler o arquivo solicitado
	
	if(file == NULL)//caso o CPF não esteja cadastrado, retorna mensagem informando
	{
		printf("\nCPF não cadastrado em nosso banco de dados! \n\n");
	}
    
    else
    {
		printf("\nEssas são as informações do usuário: \n\n");
    
   		while(fgets(conteudo, 200, file)!= NULL)//pesquisa o arquivo do CPF solicitado e retorna com as informações
    	{
    		printf("%s", conteudo);
    	}
	}
    
	fclose(file);
    
    system("pause");
    
    printf("\n----------------------------------------\n\n");
	printf("Voce deseja realizar outra consulta?\n\n");
	printf("1 - Nova consulta");
	printf("\n2 - Voltar ao menu inicial\n");
	printf("\nDigite a opção desejada: ");
	scanf("%d", &resposta);
	
	switch(resposta)
	{
		case 1:
		system("cls");
		consultar(); // recomeça a função consulta
		break;
		
		case 2:
		return; // retorna ao menu inicial
		break;
		
		default:
		printf("\nOpção invalida, o sistema irá retornar ao menu inicial!\n\n"); //retorna mensagem, e após retorna o sistema ao menu principal
    	system("pause");
    	break;
	}
    
}


int deletar()
{
	char cpf[40];
	char nome[100];
	char sobrenome[100];
	int resposta;
	
	setlocale(LC_ALL, "Portuguese"); //Definindo o idioma do país   
    
	printf("Digite o CPF do usuário a ser deletado: ");//recebe o CPF do usuario
	scanf("%s", cpf);//salva na variavel o CPF digitado
	
	
	FILE *file;
	file = fopen(cpf, "r");//vai ler o arquivo do CPF digitado
	
	if(file == NULL)//caso o CPF não esteja cadastrado, retorna mensagem informando
	{
		fclose(file);
		printf("\nO usuário não está cadastrado!\n");
		printf("O sistema irá retornar ao menu inicial!\n\n");
		system("pause");
		return;//retorna ao menu inicial
		
	}
	
	else
	{
		fscanf(file, "CPF: %s", cpf); //le o CPF do usuario no arquivo novamente
		fscanf(file, "\nNOME: %99[^\n]", nome); // vai ler o nome até encontrar uma quebra de linha
		fscanf(file, "\nSOBRENOME: %99[^\n]", sobrenome); //vai ler o sobrenome até encontrar uma quabra de linha		
		printf("\nVocê realmente deseja deletar este usuário?\n\n");//questiona se o usuário quer deletar o aquivo
		printf("CPF: %s", cpf); // mostra o CPF do usuario a ser deletado
		printf("\nNome: %s", nome); // mostra o nome do usuario a ser deletado
		printf("\x20 %s", sobrenome); // mostra o sobrenome do usuario a ser deletado
		printf("\n\n1 - Sim\n");
		printf("2 - Não\n\n");
    	printf("Digite a opção desejada: ");
    	scanf("%d", &resposta);//faz analise do questionamento
    }
    
    if(resposta == 1) //caso a analise confirme a intenção, deleta o CPF solicitado
	{		
	    fclose(file);
	    remove(cpf);
	    printf("\nUsuário foi deletado com sucesso!\n");
	    printf("O sistema irá retornar ao menu inicial!\n\n");
	    system("pause");
	}
	    
    if(resposta == 2) //caso o usuário não queira deletar, retorna essa mensagem
	{
		fclose(file);
	    printf("\nO usuário não foi deletado!\n");
	    printf("O sistema irá retornar ao menu inicial!\n\n");
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
    printf("1 - Encerrar\n");
	printf("2 - Voltar ao menu inicial\n\n");
	printf("Digite a opção desejada: ");//recebe a resposta do usuário
	scanf("%d", &resposta); //salva a resposta do usuário
	
	switch(resposta) //faz a analise da resposta do usuário
	{
		case 1:
		system("cls"); //limpa a tela
		printf("\nObrigado por utilizar o sistema!\n");
	    printf("\n\n\n*** Software desenvolvido por Vinicius Baptista ***\n\n\n\n");
	    system("pause");
	    exit(0);//encerra o sistema
	    break;
	    
		case 2:
		return; //retorna ao menu principal
		break;
	
	    default:
    	printf("\nOpção invalida, o sistema irá retornar ao menu inicial!\n\n"); //retorna mensagem, e após retorna o sistema ao menu principal
    	system("pause");
    	break;
	}
}

int cadastrologin ()
{
	char arquivologin[40];
	char cpfusuario[40];
	char usuario[40];
	char senha[40];
	int resposta=0;
	
	setlocale(LC_ALL, "Portuguese"); //Definindo o idioma do país
	
	printf("CADASTRO DE LOGIN\n\n");
	
	printf("Digite o novo usuario: ");//recebe o nome de usuario para acessar o sistema
	scanf("%s", &usuario); // salvando o usuario digitado
	
	strcpy(arquivologin, usuario); //responsavel por copiar os valores das strings - está dizendo que arquivo é igual ao usuario (o nome do arquivo será o USUARIO).
	FILE *file;

	file = fopen(arquivologin, "w"); //criando o arquivo 
	fprintf(file, usuario); //salvando o usuario digitado no arquivo
	fclose(file);
	
	file = fopen(arquivologin, "a");// adiciona algo no arquivo
	fprintf(file, "\n");//adicionando uma quebra de linha no arquivo
	fclose(file);
	
	printf("Digite a nova senha: ");//recebe a senha digitada pelo usuario
	scanf("%s", &senha); // salvando a senha digitada
		
	file = fopen(arquivologin, "a");
	fprintf(file, senha); //salvando a senha digitada no arquivo
	fclose(file);
	
	file = fopen(arquivologin, "a");
	fprintf(file, "\n");
	fclose(file);
	
	printf("Digite o CPF do novo usuario: ");
	scanf("%s", &cpfusuario); // salvando o CPF do usuario digitado na variavel
	
	file = fopen(arquivologin, "a");
	fprintf(file, cpfusuario); //salvando o CPF do usuario no arquivo
	fclose(file);
		
	printf("\nLogin cadastrado com sucesso!\n\n");
	printf("----------------------------------------\n\n");
	printf("Deseja cadastrar outro login?\n\n");
	printf("1 - Cadastrar novo usuário e senha\n");
	printf("2 - Voltar ao menu inicial\n");
	printf("\nDigite a opção desejada: ");
	scanf("%d", &resposta);//salva a resposta do usuario na variavel
	
	switch(resposta)
	{
		case 1:
		system("cls");
		cadastrologin(); // recomeça a função cadastrologin
		break;
		
		case 2:
		return; // retorna ao menu inicial
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
	char usuariodigitado[40]="a";
	char senhadigitada[40]="a";
	char usuariovalidacao[40];
	char senhavalidacao[40];
	int comparacaousuario;
	int comparacaosenha;
	int usuadmin;
	int senadmin;
		
	setlocale(LC_ALL, "Portuguese"); //Definindo o idioma do país
	
	printf("------------ Cartório da EBAC ------------\n\n");
	printf("Faça o login para acessar o sistema\n\n");
	printf("Digite o usuário: ");
	scanf("%s", &usuariodigitado);//salva o usuario digitado na string
	printf("Digite a sua senha: ");
	scanf("%s", &senhadigitada); //salva a senha digitada na string
	
	usuadmin = strcmp(usuariodigitado, "admin"); //faz a comparação se o usuario digitado é "admin"
	senadmin = strcmp(senhadigitada, "admin"); //faz a comparação se a senha digitada é "admin"
		
	FILE *file;
		
	file = fopen(usuariodigitado, "r");
	fscanf(file, "%s %s", usuariovalidacao, senhavalidacao);// vai buscar no arquivo os usuarios e senhas cadastrados
	fclose(file);
	
	comparacaousuario = strcmp(usuariodigitado, usuariovalidacao);// faz a comparação do usuario digitado e do cadastrado
    comparacaosenha = strcmp(senhadigitada, senhavalidacao);// faz a comparação da senha digitada e da cadastrada
    
	if((comparacaousuario == 0 && comparacaosenha == 0) || (usuadmin == 0 && senadmin == 0)) //caso o usuario e senha esteja certo, ou seja "admin" segue o codigo
	{
		system("cls");	
		for(repetir=1;repetir=1;) // laço de repetição
		{
	
		    system("cls"); //limpa a tela
		
		    setlocale(LC_ALL, "Portuguese"); //Definindo o idioma do país
	
		    printf("------------ Cartório da EBAC ------------\n\n"); //Inicio do menu
		    printf("Escolha a opção desejada no menu:\n\n");
		    printf("\t1 - Registrar nomes\n");
		    printf("\t2 - Consultar nomes\n");
		    printf("\t3 - Deletar nomes\n\n");
		    printf("\t4 - Cadastrar novo login e senha\n");
		    printf("\t5 - Encerrar o sistema\n\n");
		    printf("Opção desejada: "); //Fim do menu
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
	    		cadastrologin(); //chamada de função cadastrologin
	    		break;
	    		
		    	case 5:
		    	sair(); //chamada de função sair
		        break;
	     		     	
		     	default:
		     	printf("Esta opção não está disponivel!\n\n"); //caso o usuário escolha uma opção fora das 5 disponiveis
				system("pause"); 
				break; //Fim da seleção
			
			
			
			}
	    }
  	  
	}
	
	else
		printf("\nUsuário ou senha incorreto!\n"); // caso a senha do login esteja errada
		printf("Tente novamente!\n\n");
		system("pause");
		system("cls");
		main();
}

