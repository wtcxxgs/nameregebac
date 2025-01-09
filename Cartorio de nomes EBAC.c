#include <stdio.h> //biblioteca de comunicação com o usuário 
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //bilbioteca de alocação de texto por região 
#include <string.h> //biblioteca responsável por cuidas das strings

	 int registro()  //Função responsável por cadastrar ps usuários no sistema
	 {
	 	char arquivo[40]; //Início da criação de variáveis/string
		char cpf[40];
	 	char nome[40];
	 	char sobrenome[40];
	 	char cargo[40];  //Final da criação de variáveis
	 	
	 	printf("Digite o CPF a ser cadastrado. "); //Coletando informação do usuário
	 	scanf("%s", cpf);  //%s refere-se a strings
	 	
	 	strcpy(arquivo, cpf); //Responsável por copiar os valores das strings
	 	
	 	FILE *file; //cria o arquivo no banco de dados
	 	file = fopen(arquivo, "w"); //"w" significa escrever
	 	fprintf(file,cpf); //salvar o valor da variável
	 	fclose(file); //fechar o arquivo
	 	
	 	file = fopen(arquivo, "a"); //Abre o arquivo, "a" significa atualizar
	 	fprintf(file, ","); //Adiciona vírgula ao arquivo
	 	fclose(file); //Fechar o arquivo
	 	
	 	printf("Digite o nome a ser cadastrado. "); //Coletando informações do usuário
	 	scanf("%s",nome); //"%s" refere-se a strings
	 	
	 	file = fopen(arquivo, "a"); //Abre o arquivo, "a" significa atualizar
	 	fprintf(file, nome); //Salva a variável nome
	 	fclose(file); //Fechar o arquivo
	 	
	 	file = fopen(arquivo, "a"); //Abre o arquivo, "a" significa atualizar
	 	fprintf(file, ","); //Adiciona vírgula ao arquivo 
	 	fclose(file); //Fechar o arquivo
	 	
	 	printf("Digite o sobrenome a ser cadastrado. "); //Coletando informaçoes do usuário
	 	scanf("%s", sobrenome); //"%s" refere-se a strings
	 	
	 	file = fopen(arquivo, "a"); //Abre o arquivo, "a" significa atualizar
	 	fprintf(file, sobrenome); //Salva a variável sobrenome
	 	fclose(file); //Fechar o arquivo
	 	
	 	file = fopen(arquivo, "a"); //Abre o arquivi, "a" significa atualizar
	 	fprintf(file, ","); //Adiciona vírgula ao arquivo
	 	fclose(file); //Fechar o arquivo
	 	
	 	printf("Digite o cargo a ser cadastrado. "); //Coletando informações do usuário
	 	scanf("%s", cargo); //"%s" refere-se a strings
	 	
	 	file = fopen(arquivo, "a"); //Abre o arquivo, "a" significa atualizar
	 	fprintf(file, cargo); //Salva a variável cargo
	 	fclose(file); //Fechar o arquivo
	 	
	 	system("pause");
	 		
	 	
	 }
	 
	 int consulta()
	 {
	 	setlocale(LC_ALL, "Portuguese"); //Definindo linguagem
		 
		char cpf[40]; //Início da criação de variáveis/string
	 	char conteudo[200]; //Final da criação de variáveis
		
		printf("Digite o CPF a ser consultado. "); //Coletando informações do usuário
		scanf("%s", cpf); //"%s"refere-se a strings
		
		FILE *file; //Cria o arquivo no banco de dados
		file = fopen(cpf, "r"); //Abe o arquivo, "r" significa ler
		
		if(file == NULL) //Delimitar que se o CPF não existir no banco de dados o usuário seja notificado
		{
			printf("CPF não cadstrado. \n");
		} 	 	
	 	
	 	while(fgets(conteudo, 200, file) != NULL) //Buscar a variável conteúdo no arquivo aberto, quando existir
	 	{
	 		printf("\nEssas são as informações do usuário: ");
	 		printf("%s", conteudo);
	 		printf("\n\n");
	 		
		}
	 	
	 	system("pause");
	 	
	 	fclose(file); //Fechar o arquivo
	 	
	 }
	 
	 int deletar()
	 {
	 	char cpf[40]; //Criação da variável a ser utilizada
	 	
	 	printf("Digite o CPF a ser deletado. "); //Coletando informaçõs do usuário
	 	scanf("%s", cpf); //"%s"refere-se a strings
	 	
	 	remove(cpf); //Comando para deletar arquivo referente a variável
	 	
	 	FILE *file; //Cria arquivo no banco de dados
	 	file = fopen(cpf, "r"); //Abre o arquivo, "r" significa ler
	 	
	 	if(file == NULL) //Delimitar que se o CPF nao existir no banco de dados o usuário seja notificado
	 	{
	 		printf("CPF não cadastrado. \n");
	 		system("pause");
		}
	
		fclose(file); 	//Fechar o arquivo
	 	
	 }

     int main()
               {
               	int opcao=0;  //Definindo variáveis
               	int laco=1;
               	
               	for(laco=1;laco=1;)
               	        {
				          
						   system("cls");  
               	
            	setlocale(LC_ALL, "Portuguese");  //Definindo linguagens                                          
            	
	            printf("\tCartório da EBAC \t\n\n\n");   //Início do Menu    
				                            
	            printf("Escolha a opção desejada no menu:\n\n\n");                            
	            
	            printf("\t1- Registrar nome\n");
	            printf("\t2- Consultar nome\n");
	            printf("\t3- Deletar nome\n\n\n");  
				
				printf("Opção:\t");    //Fim do menu
	            
	            
	            scanf("%d", &opcao);  //Armazenando a escolha do usuário
	            
	            system("cls"); //Responsável por limpar a tela
	            
	            switch(opcao)
	                         {
	            	           
	            	           case 1:
	            	            registro(); //Chamada de funções
	                        	break;
	                        	
	                        	case 2:
	                        	consulta();
								break;
								
								case 3:
								deletar();
				            	break;
				            	
				            	
				            	default:
				            	printf("\n\n\tEssa opção não está disponível.\n\n\n");
	                        	system("pause");
				            	break;
									
	                        		
				             }
	            
	            
				        }
	            
               }

