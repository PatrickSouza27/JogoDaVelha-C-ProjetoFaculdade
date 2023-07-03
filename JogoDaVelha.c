#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h> //usando para usar o getch();
#include <locale.h>
#include <stdbool.h>

//Constantes
#define CLS system("cls");
#define LIN 3
#define COL 3
void carregamento();

//Variáveis globais
int num, contX = 0, contO = 0, contE = 0, contT = 0, lin = 0, col = 0 ;
char casas[LIN][COL] = { 
	{'1', '2', '3'},
	{'4', '5', '6'},
	{'7', '8', '9'},
};
  //enum é um tipo de dados definido pelo usuario, ele escolhe oq cada variavel vai receber,(um conjunto restrito de valores)
  //COR DA LETRA pelo prompt {color " "};
  enum{BLACK,                 //0 cmd
       BLUE,                  //1 cmd
       GREEN,                 //2 cmd
       CYAN,                  //3 cmd
       RED,                   //4 cmd
       MAGENTA,               //5 cmd
       BROWN,                 //6 cmd
       LIGHTGRAY,             //7 cmd
       DARKGRAY,              //8 cmd
       LIGHTBLUE,             //9 cmd
       LIGHTGREEN,            //10 cmd
       LIGHTCYAN,             //11 cmd
       LIGHTRED,              //12 cmd
       LIGHTMAGENTA,          //13 cmd
       YELLOW,                //14 cmd
       WHITE                  //15 cmd
       
       };  
  //COR DO FUNDO
  //aqui as variaveis esta recebendo o valor que começa as cores o background no cmd;
  //localizar mais facil
  enum{_BLACK=0,                 
       _BLUE=16,                  
       _GREEN=32,                 
       _CYAN=48,                  
       _RED=64,                   
       _MAGENTA=80,               
       _BROWN=96,                 
       _LIGHTGRAY=112,             
       _DARKGRAY=128,              
       _LIGHTBLUE=144,             
       _LIGHTGREEN=160,            
       _LIGHTCYAN=176,             
       _LIGHTRED=192,              
       _LIGHTMAGENTA=208,         
       _YELLOW=224,                
       _WHITE=240                        
       };  
       
//buffer é uma matriz bidimensional de caracteres e dados de cor para saidda em uma janela do console
void textColor(int letra, int fundo){
	//função(parametro)
     SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), letra + fundo);
//Define os atributos de caracteres gravados no buffer da tela do console;
	//identificador de entrada e saida do console(ele q chama o console)
	//voce escolhe se é saida ou entrada, nesse caso é saida,   entrada: input / saida: output;
		//parametro numero da cor da linha + cor do fundo
     }
     
void linhaCol(int lin, int col){
     SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),(COORD){col-1,lin-1});
     // metodo usado para definir a posição do cursor
     	//identificador de entrada e saida do console
     		//voce escolhe se é saida ou entrada, nesse caso é saida,   entrada: input / saida: output;
     			//COORD -> define as cordenadas de um comando de caracteres na tela do console(padrão 0,0)
     				//parametro
     
     //funcao para deixar o cursor invisivel
     HANDLE que_isso_meu_filho_calma = GetStdHandle(STD_OUTPUT_HANDLE);
     //HANDLE-->Qualquer coisa de um indice inteiro para um ponteiro
     	//que_isso_meu_filho_calma esta recebendo o identificador de entrada e saida com a sua opção que nesse caso é saida
     CONSOLE_CURSOR_INFO info;
     info.dwSize = 100; //aqui a info(nome qualquer)vai receber o tamanho 100
     info.bVisible = FALSE; // aqui é a opção q deixa o cursor invisivel, se for false(invisivel) true q vem de padrão(visivel)
     SetConsoleCursorInfo(que_isso_meu_filho_calma, &info); //aqui é a informação do cursor pegando as informações pro console
}
void box(int lin1, int col1, int lin2, int col2){
	//função caixa(parametro linha 1, coluna 1, linha 2, coluna 2);
     int i,j , tamlin, tamcol;
     //achar o tamanho do box (tamanho da linha) (tamanho da coluna)
     tamlin = lin2 - lin1;
     tamcol = col2 - col1;
     
     //aqui vou estar montando o tamanho da caixa;
     for (i=col1; i<=col2; i++){ // linhas    |						| enquanto o primeiro ponto for menor que o segundo
         linhaCol(lin1,i);  //ele adiciona linha
         printf("%c",196);//196 tabela ascii é a linha ------------
         linhaCol(lin2,i);
         printf("%c",196);
         }
        
     for (i=lin1; i<=lin2; i++){ //colunas     ------------------ enquanto o primeiro ponto for menor ele adiciona |   |
         linhaCol(i,col1);
         printf("%c",179); //179 na tabela ascii é as colunas |
         linhaCol(i,col2);
         printf("%c",179);
         }
     for (i=lin1+1;i<lin2;i++){ //aqui é par percorrer o fundo da caixa e deixar vazio, sem o desenho da caixa
         for(j=col1+1;j<col2;j++){
            linhaCol(i,j);printf(" ");//oque esta dentro fica em branco
         }
         }
     //Aqui é para adicionar as dobras nas ligações entre as colunas e linhas
     linhaCol(lin1,col1);
     printf("%c",218); //218 dobras dos cantos
     linhaCol(lin1,col2);
     printf("%c",191);
     linhaCol(lin2,col1);
     printf("%c",192);
     linhaCol(lin2,col2);
     printf("%c",217);       
     
     }
int menu(int lin1, int col1, int qtd, char lista[3][40]){
	//função menu/ parametros linha 1, coluna 1, quantidade e a listagem de itens(quantas opções sao);
     int opc=1, lin2, col2, linha,i,tamMaxItem, tecla;
     //opção recebe 1, linha 2, coluna 2, linhas, contador, tamanho maximo do item e a tecla que vai ser usada;
     
     //aqui eu to recebendo as coordenadas e calculando
     tamMaxItem = strlen(lista[0]);
    // o tamanho maximo do item ta recendo o comprimento da lista, ele vai começar na posição zero;
    	//STRLEN -> Ela retorna um inteiro que é o comprimento do string
    	
     //aqui vou achar o tamanho maximo do item
     for(i=1; i<qtd;i++){
       if(strlen(lista[i])>tamMaxItem){
       	//se a quantidade da lista[i] for maior que o tamanho maximo do item;
          tamMaxItem = strlen(lista[i]); 
          	//o tamanho maximo do item recebe o tamanho da palavra da lista[i];
       } 
     }
     lin2 = lin1+(qtd*2+2);
     col2 = col1+tamMaxItem+4;
     
     //aqui é para montar a tela, colocando as cores, e fazendo a caixa;
     textColor(WHITE, _BLACK);
     setlocale(LC_ALL,"C");
     box(lin1,col1,lin2,col2);
     //aqui é para alterar para portugues, ele muda a tabela ascii
     setlocale(LC_ALL,"");
     //laço das opcões
     while(1){
     	
        linha=lin1+2;
        for(i=0;i<qtd;i++){ 
		// o contador recebe 0 e enquanto ele for menor q a quantidade, ele incrementa          
           if(i+1==opc)textColor(BLACK, _LIGHTBLUE);
           	// 0 + 1, se a primeira opção estiver selecionada, ele fica o azulzin na palavra
           else textColor(WHITE, BLACK);
           //se nao fica branco e preto mesmo
        linhaCol(linha,col1+2);
        // aqui ele vai descer pra opção de baixo
        printf("%s",lista[i]);
        //aqui vai mostrar a opção da lista na posição i
        linha +=2;
        //linha recebe ela mais 2, tava 0, pula pro 2
        }
       
       //aqui fica aguardando a tecla
       linhaCol(1,1);
       tecla= getch();
       //a tecla recebe a tecla do usuario
       		//getch-->espera que o usuário digite uma tecla e retorna este caractere
       linhaCol(22,1);
       //printf(" tecla:  %d   ",tecla);  
       //Opção
       if(tecla==27){
       //Se a tecla for o ESC que na tabela ascii seria o 27, ele mata o codigo ali e a opção fica 0 mesmo.
       opc=0; break;
       }
       else if(tecla==13){
       	//se a tecla for ENTER ele encerra o menu com a opção 1 (opc = 1)
       break;
       }
       //Seta para cima
       else if(tecla==72){ //se a tecla for seta para cima, entao a opc fica com menos 1
            if(opc>1)opc--;  //aqui é uma verificação, se opcao for maior que 1, pode voltar, se nao fica no mesmo lugar 
       
       }
       else if(tecla==80 ){//se a tecla for seta para baixo, entao a opc recebe + 1
            if (opc<qtd)opc++; //aqui é a verificação se ja chegou na opção, se ja chegou ele n incrementa +1
                  
                           
       //printf("tecla: %d ",opc);     
       }
     }
     return opc;
}     

int main()
{
	//aqui é o titulo no prompt
	system("Title JOGO DA VELHA -DOUGLAS/LUCAS/PATRICK");
	//aqui é a função chamando o carregamento la
	carregamento();
	//variaveis
    int opc, p;
    //aqui é a lista recebendo a quantidade de palavras e o tamanho
    char lista[5][40]={"  JOGADOR X JOGADOR", "   JOGADOR X COMP", "       SAIR"};
    setlocale(LC_ALL,"");
    //aqui é gambiarra
    while(p != 1){
	    linhaCol(11,25);
	    printf("JOGO DA VELHA");
		opc = menu(12,20,3,lista);
	    
	    if (opc==0){
	       break;
	    }
	  	system("cls");
	  	p = 1;

    }
    //se opc tecla for igual a 1, entao entra na primeira opção
    if (opc == 1){
   		sorteador();
   		// se opc tecla igual a 2, entao segunda opçao
    }else if(opc == 2){
    	sorteadorCPU();
    }
    // se for igual a 3, sair
  textColor(WHITE, _BLACK);
  linhaCol(24,1);
  printf("");
  
  return 0;
}
 
//Função correspondente as jogadas dos jogadores
int jogador(){
	
	char op;
	int cont_jogadas, lin, col, i , vez, j;	
	if(num == 0){
		vez = 0;
	}else{
		vez = 1;
	}
	do{
		cont_jogadas = 1;
		for(i = 0; i <= 2; i++){
			for(j = 0; j <= 2; j++){
				casas[i][j] = ' ';
			}
		}
		do{
			tabuleiro(casas);
			
			if(vez % 2 == 0){
				linhaCol(10,54);
				textColor(RED, _BLACK);
				printf("Jogador X");
			}else{
				textColor(BLUE, _BLACK);
				linhaCol(10,54);
				printf("Jogador O");
			}
		
			linhaCol(11,54);
			printf("Digite a linha: ");
			linhaCol(15,66);
			scanf("%d", &lin);
		
			linhaCol(11,54);
			printf("Digite a coluna: ");
			linhaCol(15,66);
			scanf("%d", &col);
			
			if((lin < 1) || (col < 1) || (lin > 3) || (col > 3)){
				lin = 0;
				col = 0;
			}else if(casas[lin - 1][col - 1] != ' '){
				lin = 0;
				col = 0;
			}else{
				if(vez % 2 == 0){
					casas[lin - 1][col - 1] = 'X';
				}else{
					casas[lin - 1][col - 1] = 'O';
				}
				vez++;
				cont_jogadas++;
			}
			//condição de vitoria para X
			if(casas[0][0] == 'X' && casas[0][1] == 'X' && casas[0][2] == 'X'){cont_jogadas = 11;}
			if(casas[1][0] == 'X' && casas[1][1] == 'X' && casas[1][2] == 'X'){cont_jogadas = 11;}
			if(casas[2][0] == 'X' && casas[2][1] == 'X' && casas[2][2] == 'X'){cont_jogadas = 11;}
			if(casas[0][0] == 'X' && casas[1][0] == 'X' && casas[2][0] == 'X'){cont_jogadas = 11;}
			if(casas[0][1] == 'X' && casas[1][1] == 'X' && casas[2][1] == 'X'){cont_jogadas = 11;}
			if(casas[0][2] == 'X' && casas[1][2] == 'X' && casas[2][2] == 'X'){cont_jogadas = 11;}
			if(casas[0][0] == 'X' && casas[1][1] == 'X' && casas[2][2] == 'X'){cont_jogadas = 11;}
			if(casas[0][2] == 'X' && casas[1][1] == 'X' && casas[2][0] == 'X'){cont_jogadas = 11;}
			
			//condição de vitoria para O
			if(casas[0][0] == 'O' && casas[0][1] == 'O' && casas[0][2] == 'O'){cont_jogadas = 12;}
			if(casas[1][0] == 'O' && casas[1][1] == 'O' && casas[1][2] == 'O'){cont_jogadas = 12;}
			if(casas[2][0] == 'O' && casas[2][1] == 'O' && casas[2][2] == 'O'){cont_jogadas = 12;}
			if(casas[0][0] == 'O' && casas[1][0] == 'O' && casas[2][0] == 'O'){cont_jogadas = 12;}
			if(casas[0][1] == 'O' && casas[1][1] == 'O' && casas[2][1] == 'O'){cont_jogadas = 12;}
			if(casas[0][2] == 'O' && casas[1][2] == 'O' && casas[2][2] == 'O'){cont_jogadas = 12;}
			if(casas[0][0] == 'O' && casas[1][1] == 'O' && casas[2][2] == 'O'){cont_jogadas = 12;}
			if(casas[0][2] == 'O' && casas[1][1] == 'O' && casas[2][0] == 'O'){cont_jogadas = 12;}
			
		}while(cont_jogadas <= 9);
			tabuleiro(casas);
			if(cont_jogadas == 10){
				linhaCol(13,54);
				printf("Jogo empatado ;D");
				contE = contE + 1;
				linhaCol(14,54);
				printf("Total de empates: %d", contE);
			}if(cont_jogadas == 11){
				linhaCol(13,54);
				printf("Vencedor!! Jogador X");
				contX = contX + 1;
				linhaCol(14,54);
				printf("Total de vitorias jogador X: %d", contX);
			}if(cont_jogadas == 12){
				linhaCol(13,54);
				printf("Vencedor!! Jogador O");
				contO = contO + 1;
				linhaCol(14,54);
				printf("Total de vitorias jogador O: %d", contO);
		}
		linhaCol(15,54);
		printf("DESEJA JOGAR NOVAMENTE? [S - N]:");
		linhaCol(15,86);
		scanf("%s", &op);
	}while(op == 's' || op == 'S');
	relatorio();
}

//Função que armazena os resultados da partidas
relatorio(){
	
	//limpa a tela
	system("cls");
	
	//o setlocale pega a tabela ascii para desenhar a box
	setlocale(LC_ALL,"C");
	
	//aqui desenha a caixa
	box(10,20,18,58);
	
	//para posicionar os printf dentro da box
	//linha 11 coluna 22
	linhaCol(11,22);
	printf("    ----#JOGO DA VELHA#----");
	//linha 12, coluna 22
	linhaCol(12,22);
	printf("       RESULTADO FINAL");
	
	if(contX == contO){//se o resultado do contador x for igual ao do O entao, deu empate no placar
		linhaCol(13,22);
		printf("NÃO HOUVE VENCEDOR");
	}if(contX > contO){//se o resultado do contador x for maior q o O entao o X venceu
		linhaCol(13,22);
		printf("VENCEDOR JOGADOR X");
	}if(contO > contX){//se o cont O for maior q o cont X entao o X venceu
		linhaCol(13,22);
		printf("VENCEDOR JOGADOR O");
	}
	
	linhaCol(14,22);
	printf("TOTAL DE EMPATES: %d", contE);//mostra o total de empates
	linhaCol(15,22);
	printf("TOTAL DE VITORIAS JOGADOR X: %d", contX);//mostra a quantidade de vitorias do x
	linhaCol(16,22);
	printf("TOTAL DE VITORIAS JOGADOR O: %d", contO);//mostra a quantidade de vitoria do O
	linhaCol(17,22);
	printf("\n\n\n\n\n\n");
}


//função que sortea quem inicia jogando
sorteador(){
	char opc;
	CLS;
	srand(time(NULL));
	fflush(stdin);
	num = (rand() % 2);
	
	if(num != 0){
		textColor(BLUE, _BLACK);
		linhaCol(14,30);
		printf("Inicia jogando {O}! ");
		system("pause");
	}else{
		textColor(RED, _BLACK);
		linhaCol(14,30);
		printf("Inicia jogando {X}! ");
		system("pause");
	}
	textColor(WHITE, _BLACK);	
	jogador();		
}

//função que sortea quem inicia jogando vs CPU
sorteadorCPU(){
	char opc;
	CLS;
	srand(time(NULL));
	fflush(stdin);
	num = (rand() % 2);
	
	if(num != 0){
		linhaCol(14,30);
		textColor(BLUE, _BLACK);
		printf("Inicia jogando {O}!   ");
		system("pause");
	}else{
		textColor(RED, _BLACK);
		linhaCol(14,30);
		printf("Inicia jogando {X}!  ");
		system("pause");
	}
	computador();
}

//Função correspondente as jogadas dos jogadores
int computador(){
	char op;
	int cont_jogadas, lin, col, i , vez, j;
	bool fim = false;
	
	
	if(num == 0){
		vez = 0;
	}else{
		vez = 1;
	}
	
	do{
		cont_jogadas = 1;
		for(i = 0; i <= 2; i++){
			for(j = 0; j <= 2; j++){
				casas[i][j] = ' ';
			}
		}do{
			tabuleiro(casas);			
			if(vez % 2 == 0){
				linhaCol(11,54);
				printf("Jogador X Digite a linha: ");
				linhaCol(15,66);
				scanf("%d", &lin);
				linhaCol(11,54);
				printf("Digite a coluna: ");
				linhaCol(15,66);
				scanf("%d", &col);
			}else{
				linhaCol(11,54);
				printf("Computador O");
				//Prioriza a vitoria
				//linhas
				//validação da primeira linha
				
					 if(casas[0][0] == ' ' && casas[0][1] == 'O' && casas[0][2] == 'O'){casas[0][0] = 'O'; fim = true;}
				else if(casas[0][0] == 'O' && casas[0][1] == ' ' && casas[0][2] == 'O'){casas[0][1] = 'O'; fim = true;}
				else if(casas[0][0] == 'O' && casas[0][1] == 'O' && casas[0][2] == ' '){casas[0][2] = 'O'; fim = true;}
				
				//validação da segunda linha
				else if(casas[1][0] == ' ' && casas[1][1] == 'O' && casas[1][2] == 'O'){casas[1][0] = 'O'; fim = true;}
				else if(casas[1][0] == 'O' && casas[1][1] == ' ' && casas[1][2] == 'O'){casas[1][1] = 'O'; fim = true;}
				else if(casas[1][0] == 'O' && casas[1][1] == 'O' && casas[1][2] == ' '){casas[1][2] = 'O'; fim = true;}
				
				//Validação da terceira linha
				else if(casas[2][0] == ' ' && casas[2][1] == 'O' && casas[2][2] == 'O'){casas[2][0] = 'O'; fim = true;}
				else if(casas[2][0] == 'O' && casas[2][1] == ' ' && casas[2][2] == 'O'){casas[2][1] = 'O'; fim = true; }
				else if(casas[2][0] == 'O' && casas[2][1] == 'O' && casas[2][2] == ' '){casas[2][2] = 'O'; fim = true;}
				
				//Colunas
				//Validação da primeira coluna
				else if(casas[0][0] == ' ' && casas[1][0] == 'O' && casas[2][0] == 'O'){casas[0][0] = 'O'; fim = true;}
				else if(casas[0][0] == 'O' && casas[1][0] == ' ' && casas[2][0] == 'O'){casas[1][0] = 'O'; fim = true;}
				else if(casas[0][0] == 'O' && casas[1][0] == 'O' && casas[2][0] == ' '){casas[2][0] = 'O'; fim = true;}
				
				//Validação da segunda coluna
				else if(casas[0][1] == ' ' && casas[1][1] == 'O' && casas[2][1] == 'O'){casas[0][1] = 'O'; fim = true;}
				else if(casas[0][1] == 'O' && casas[1][1] == ' ' && casas[2][1] == 'O'){casas[1][1] = 'O'; fim = true;}
				else if(casas[0][1] == 'O' && casas[1][1] == 'O' && casas[2][1] == ' '){casas[2][1] = 'O'; fim = true;}
				
				//Validação da tereceira coluna
				else if(casas[0][2] == ' ' && casas[1][2] == 'O' && casas[2][2] == 'O'){casas[0][2] = 'O'; fim = true;}
				else if(casas[0][2] == 'O' && casas[1][2] == ' ' && casas[2][2] == 'O'){casas[1][2] = 'O'; fim = true;}
				else if(casas[0][2] == 'O' && casas[1][2] == 'O' && casas[2][2] == ' '){casas[2][2] = 'O'; fim = true;}
				
				//Diagonais
				//Validação da Diagonal principal
				else if(casas[0][0] == ' ' && casas[1][1] == 'O' && casas[2][2] == 'O'){casas[0][0] = 'O'; fim = true;}
				else if(casas[0][0] == 'O' && casas[1][1] == ' ' && casas[2][2] == 'O'){casas[1][1] = 'O'; fim = true;}
				else if(casas[0][0] == 'O' && casas[1][1] == 'O' && casas[2][2] == ' '){casas[2][2] = 'O'; fim = true;}
				
				//Validação da Diagonal Segundária
				else if(casas[0][2] == ' ' && casas[1][1] == 'O' && casas[2][0] == 'O'){casas[0][2] = 'O'; fim = true;}
				else if(casas[0][2] == 'O' && casas[1][1] == ' ' && casas[2][0] == 'O'){casas[1][1] = 'O'; fim = true;}
				else if(casas[0][2] == 'O' && casas[1][1] == 'O' && casas[2][0] == ' '){casas[2][0] = 'O'; fim = true;}
				
				//Prioriza a jogada
				//linhas
				//validação da primeira linha
				else if(casas[0][0] == ' ' && casas[0][1] == 'X' && casas[0][2] == 'X'){casas[0][0] = 'O'; break;}
				else if(casas[0][0] == 'X' && casas[0][1] == ' ' && casas[0][2] == 'X'){casas[0][1] = 'O'; break;}
				else if(casas[0][0] == 'X' && casas[0][1] == 'X' && casas[0][2] == ' '){casas[0][2] = 'O'; break;}
				
				//validação da segunda linha
				else if(casas[1][0] == ' ' && casas[1][1] == 'X' && casas[1][2] == 'X'){casas[1][0] = 'O'; break;}
				else if(casas[1][0] == 'X' && casas[1][1] == ' ' && casas[1][2] == 'X'){casas[1][1] = 'O'; break;}
				else if(casas[1][0] == 'X' && casas[1][1] == 'X' && casas[1][2] == ' '){casas[1][2] = 'O'; break;}
				
				//Validação da terceira linha
				else if(casas[2][0] == ' ' && casas[2][1] == 'X' && casas[2][2] == 'X'){casas[2][0] = 'O'; break;}
				else if(casas[2][0] == 'X' && casas[2][1] == ' ' && casas[2][2] == 'X'){casas[2][1] = 'O'; break;}
				else if(casas[2][0] == 'X' && casas[2][1] == 'X' && casas[2][2] == ' '){casas[2][2] = 'O'; break;}
				
				//Colunas
				//Validação da primeira coluna
				else if(casas[0][0] == ' ' && casas[1][0] == 'X' && casas[2][0] == 'X'){casas[0][0] = 'O'; break;}
				else if(casas[0][0] == 'X' && casas[1][0] == ' ' && casas[2][0] == 'X'){casas[1][0] = 'O'; break;}
				else if(casas[0][0] == 'X' && casas[1][0] == 'X' && casas[2][0] == ' '){casas[2][0] = 'O'; break;}
				
				//Validação da segunda coluna
				else if(casas[0][1] == ' ' && casas[1][1] == 'X' && casas[2][1] == 'X'){casas[0][1] = 'O'; break;}
				else if(casas[0][1] == 'X' && casas[1][1] == ' ' && casas[2][1] == 'X'){casas[1][1] = 'O'; break;}
				else if(casas[0][1] == 'X' && casas[1][1] == 'X' && casas[2][1] == ' '){casas[2][1] = 'O'; break;}
				
				//Validação da tereceira coluna
				else if(casas[0][2] == ' ' && casas[1][2] == 'X' && casas[2][2] == 'X'){casas[0][2] = 'O'; break;}
				else if(casas[0][2] == 'X' && casas[1][2] == ' ' && casas[2][2] == 'X'){casas[1][2] = 'O'; break;}
				else if(casas[0][2] == 'X' && casas[1][2] == 'X' && casas[2][2] == ' '){casas[2][2] = 'O'; break;}
				
				//Diagonais
				//Validação da Diagonal principal
				else if(casas[0][0] == ' ' && casas[1][1] == 'X' && casas[2][2] == 'X'){casas[0][0] = 'O'; break;}
				else if(casas[0][0] == 'X' && casas[1][1] == ' ' && casas[2][2] == 'X'){casas[1][1] = 'O'; break;}
				else if(casas[0][0] == 'X' && casas[1][1] == 'X' && casas[2][2] == ' '){casas[2][2] = 'O'; break;}
				
				//Validação da Diagonal Segundária
				else if(casas[0][2] == ' ' && casas[1][1] == 'X' && casas[2][0] == 'X'){casas[0][2] = 'O'; break;}
				else if(casas[0][2] == 'X' && casas[1][1] == ' ' && casas[2][0] == 'X'){casas[1][1] = 'O'; break;}
				else if(casas[0][2] == 'X' && casas[1][1] == 'X' && casas[2][0] == ' '){casas[2][0] = 'O'; break;}
				else{
					do{
						srand((unsigned) time(NULL));
						lin = ( 1 + rand() % 3);
						col = ( 1 + rand() % 3);	
					}while(casas[lin -1][col - 1] != ' ');
				}
			}
				
			if((lin < 1) || (col < 1) || (lin > 3) || (col > 3)){
				lin = 0;
				col = 0;
			}else if(casas[lin - 1][col - 1] != ' '){
				lin = 0;
				col = 0;
			}else{
				if(vez % 2 == 0){
					casas[lin - 1][col - 1] = 'X';
				}else{
					casas[lin - 1][col - 1] = 'O';
				}
				vez++;
				cont_jogadas++;
			}
			
			//condição de vitoria para X
			if(casas[0][0] == 'X' && casas[0][1] == 'X' && casas[0][2] == 'X'){cont_jogadas = 11;}
			if(casas[1][0] == 'X' && casas[1][1] == 'X' && casas[1][2] == 'X'){cont_jogadas = 11;}
			if(casas[2][0] == 'X' && casas[2][1] == 'X' && casas[2][2] == 'X'){cont_jogadas = 11;}
			if(casas[0][0] == 'X' && casas[1][0] == 'X' && casas[2][0] == 'X'){cont_jogadas = 11;}
			if(casas[0][1] == 'X' && casas[1][1] == 'X' && casas[2][1] == 'X'){cont_jogadas = 11;}
			if(casas[0][2] == 'X' && casas[1][2] == 'X' && casas[2][2] == 'X'){cont_jogadas = 11;}
			if(casas[0][0] == 'X' && casas[1][1] == 'X' && casas[2][2] == 'X'){cont_jogadas = 11;}
			if(casas[0][2] == 'X' && casas[1][1] == 'X' && casas[2][0] == 'X'){cont_jogadas = 11;}
			
			//condição de vitoria para O
			if(casas[0][0] == 'O' && casas[0][1] == 'O' && casas[0][2] == 'O'){cont_jogadas = 12;}
			if(casas[1][0] == 'O' && casas[1][1] == 'O' && casas[1][2] == 'O'){cont_jogadas = 12;}
			if(casas[2][0] == 'O' && casas[2][1] == 'O' && casas[2][2] == 'O'){cont_jogadas = 12;}
			if(casas[0][0] == 'O' && casas[1][0] == 'O' && casas[2][0] == 'O'){cont_jogadas = 12;}
			if(casas[0][1] == 'O' && casas[1][1] == 'O' && casas[2][1] == 'O'){cont_jogadas = 12;}
			if(casas[0][2] == 'O' && casas[1][2] == 'O' && casas[2][2] == 'O'){cont_jogadas = 12;}
			if(casas[0][0] == 'O' && casas[1][1] == 'O' && casas[2][2] == 'O'){cont_jogadas = 12;}
			if(casas[0][2] == 'O' && casas[1][1] == 'O' && casas[2][0] == 'O'){cont_jogadas = 12;}	
			
		}while(cont_jogadas <= 9 && (!fim));
		
			if(cont_jogadas == 10){
				linhaCol(13,54);
				printf("Jogo empatado ;D");
				contE = contE + 1;
				linhaCol(14,54);
				printf("Total de empates: %d", contE);
			}if(cont_jogadas == 11){
				linhaCol(13,54);
				printf("Vencedor!! Jogador X");
				contX = contX + 1;
				linhaCol(14,54);
				printf("Total de vitorias jogador X: %d", contX);
			}if(cont_jogadas == 12){
				linhaCol(13,54);
				printf("Vencedor!! Jogador O");
				contO = contO + 1;
				linhaCol(14,54);
				printf("Total de vitorias jogador O: %d", contO);
		}
		linhaCol(15,54);
		printf("DESEJA JOGAR NOVAMENTE? [S - N]:");
		linhaCol(15,86);
		scanf("%s", &op);
	}while(op == 's' || op == 'S');
	relatorio();
}

//Função que exibr mensagem Loading
void carregamento(){
	char x = 219;
	int i;
	printf("\n\n\n\n\n\n\n\n");
	printf("\t\t\t\tLoading ");
	textColor(9, 0);
	for(i = 0; i < 35; i++){
		printf("%c", x);
		if(i < 10){
			Sleep(200);
		};
		if(i >= 10 && i < 20){
			Sleep(100);
		};
		if(i >= 10){
			Sleep(25);
		};
	
	}
	system("cls");
	printf("\n\n\n\n\n\n\n\n");
	printf("\t\t\t\t");

}

//Função para exibir o tabuleiro
tabuleiro (char casas2[LIN][COL]){
	//LIMPA A TELA
	CLS;
	int i;
	setlocale(LC_ALL,"C");
	box(12,20,18,41);
	linhaCol(11,24);
	printf("\t 1    2    3 \n");
	linhaCol(13,19);
	printf("1\n\n\t\t  2\n\n\t\t  3");
	linhaCol(13,24);
	printf("\t%c  |  %c  |  %c \n", casas2[0][0], casas2[0][1], casas2[0][2] );
	linhaCol(14,21);
	for (i = 14; (i < 34); i++){
		printf("%c", 196);
	}
	linhaCol(15,24);
	printf("\t%c  |  %c  | %c \n", casas2[1][0], casas2[1][1], casas2[1][2] );
	linhaCol(16,21);
		for (i = 14; (i < 34); i++){
		printf("%c", 196);
	}
	linhaCol(17,21);
	printf("\t%c  |  %c  | %c \n", casas2[2][0], casas2[2][1], casas2[2][2] );
}
	                                                        
