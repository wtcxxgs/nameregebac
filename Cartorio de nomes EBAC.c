#include <stdio.h> //biblioteca de comunica��o com o usu�rio 
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //bilbioteca de aloca��o de texto por regi�o 
#include <string.h> //biblioteca respons�vel por cuidas das strings

	 int registro()  //Fun��o respons�vel por cadastrar ps usu�rios no sistema
	 {
	 	char arquivo[40]; //In�cio da cria��o de vari�veis/string
		char cpf[40];
	 	char nome[40];
	 	char sobrenome[40];
	 	char cargo[40];  //Final da cria��o de vari�veis
	 	
	 	printf("Digite o CPF a ser cadastrado. "); //Coletando informa��o do usu�rio
	 	scanf("%s", cpf);  //%s refere-se a strings
	 	
	 	strcpy(arquivo, cpf); //Respons�vel por copiar os valores das strings
	 	
	 	FILE *file; //cria o arquivo no banco de dados
	 	file = fopen(arquivo, "w"); //"w" significa escrever
	 	fprintf(file,cpf); //salvar o valor da vari�vel
	 	fclose(file); //fechar o arquivo
	 	
	 	file = fopen(arquivo, "a"); //Abre o arquivo, "a" significa atualizar
	 	fprintf(file, ","); //Adiciona v�rgula ao arquivo
	 	fclose(file); //Fechar o arquivo
	 	
	 	printf("Digite o nome a ser cadastrado. "); //Coletando informa��es do usu�rio
	 	scanf("%s",nome); //"%s" refere-se a strings
	 	
	 	file = fopen(arquivo, "a"); //Abre o arquivo, "a" significa atualizar
	 	fprintf(file, nome); //Salva a vari�vel nome
	 	fclose(file); //Fechar o arquivo
	 	
	 	file = fopen(arquivo, "a"); //Abre o arquivo, "a" significa atualizar
	 	fprintf(file, ","); //Adiciona v�rgula ao arquivo 
	 	fclose(file); //Fechar o arquivo
	 	
	 	printf("Digite o sobrenome a ser cadastrado. "); //Coletando informa�oes do usu�rio
	 	scanf("%s", sobrenome); //"%s" refere-se a strings
	 	
	 	file = fopen(arquivo, "a"); //Abre o arquivo, "a" significa atualizar
	 	fprintf(file, sobrenome); //Salva a vari�vel sobrenome
	 	fclose(file); //Fechar o arquivo
	 	
	 	file = fopen(arquivo, "a"); //Abre o arquivi, "a" significa atualizar
	 	fprintf(file, ","); //Adiciona v�rgula ao arquivo
	 	fclose(file); //Fechar o arquivo
	 	
	 	printf("Digite o cargo a ser cadastrado. "); //Coletando informa��es do usu�rio
	 	scanf("%s", cargo); //"%s" refere-se a strings
	 	
	 	file = fopen(arquivo, "a"); //Abre o arquivo, "a" significa atualizar
	 	fprintf(file, cargo); //Salva a vari�vel cargo
	 	fclose(file); //Fechar o arquivo
	 	
	 	system("pause");
	 		
	 	
	 }
	 
	 int consulta()
	 {
	 	setlocale(LC_ALL, "Portuguese"); //Definindo linguagem
		 
		char cpf[40]; //In�cio da cria��o de vari�veis/string
	 	char conteudo[200]; //Final da cria��o de vari�veis
		
		printf("Digite o CPF a ser consultado. "); //Coletando informa��es do usu�rio
		scanf("%s", cpf); //"%s"refere-se a strings
		
		FILE *file; //Cria o arquivo no banco de dados
		file = fopen(cpf, "r"); //Abe o arquivo, "r" significa ler
		
		if(file == NULL) //Delimitar que se o CPF n�o existir no banco de dados o usu�rio seja notificado
		{
			printf("CPF n�o cadstrado. \n");
		} 	 	
	 	
	 	while(fgets(conteudo, 200, file) != NULL) //Buscar a vari�vel conte�do no arquivo aberto, quando existir
	 	{
	 		printf("\nEssas s�o as informa��es do usu�rio: ");
	 		printf("%s", conteudo);
	 		printf("\n\n");
	 		
		}
	 	
	 	system("pause");
	 	
	 	fclose(file); //Fechar o arquivo
	 	
	 }
	 
	 int deletar()
	 {
	 	char cpf[40]; //Cria��o da vari�vel a ser utilizada
	 	
	 	printf("Digite o CPF a ser deletado. "); //Coletando informa��s do usu�rio
	 	scanf("%s", cpf); //"%s"refere-se a strings
	 	
	 	remove(cpf); //Comando para deletar arquivo referente a vari�vel
	 	
	 	FILE *file; //Cria arquivo no banco de dados
	 	file = fopen(cpf, "r"); //Abre o arquivo, "r" significa ler
	 	
	 	if(file == NULL) //Delimitar que se o CPF nao existir no banco de dados o usu�rio seja notificado
	 	{
	 		printf("CPF n�o cadastrado. \n");
	 		system("pause");
		}
	
		fclose(file); 	//Fechar o arquivo
	 	
	 }

     int main()
               {
               	int opcao=0;  //Definindo vari�veis
               	int laco=1;
               	
               	for(laco=1;laco=1;)
               	        {
				          
						   system("cls");  
               	
            	setlocale(LC_ALL, "Portuguese");  //Definindo linguagens                                          
            	
	            printf("\tCart�rio da EBAC \t\n\n\n");   //In�cio do Menu    
				                            
	            printf("Escolha a op��o desejada no menu:\n\n\n");                            
	            
	            printf("\t1- Registrar nome\n");
	            printf("\t2- Consultar nome\n");
	            printf("\t3- Deletar nome\n\n\n");  
				
				printf("Op��o:\t");    //Fim do menu
	            
	            
	            scanf("%d", &opcao);  //Armazenando a escolha do usu�rio
	            
	            system("cls"); //Respons�vel por limpar a tela
	            
	            switch(opcao)
	                         {
	            	           
	            	           case 1:
	            	            registro(); //Chamada de fun��es
	                        	break;
	                        	
	                        	case 2:
	                        	consulta();
								break;
								
								case 3:
								deletar();
				            	break;
				            	
				            	
				            	default:
				            	printf("\n\n\tEssa op��o n�o est� dispon�vel.\n\n\n");
	                        	system("pause");
				            	break;
									
	                        		
				             }
	            
	            
				        }
	            
               }

