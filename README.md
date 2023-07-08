# JogoDaVelha-C-ProjetoFaculdade
Projeto Jogo da Velha feito em C no meu Primeiro Semestre da faculdade(SENAC), 20/06/2022

## Regras
No modo básico do jogo, participam duas pessoas, que jogam alternadamente, preenchendo cada um dos espaços vazios. Cada participante poderá usar um símbolo (X ou O). Vence o jogador que conseguir formar primeiro uma linha com três símbolos iguais, seja ela na horizontal, vertical ou diagonal.


![ezgif com-video-to-gif](https://github.com/PatrickSouza27/JogoDaVelha-C-ProjetoFaculdade/assets/77933748/da3fd505-bb9a-45c6-97ce-07a7e1ed2a16)



## Enumeração de Cores Terminal
```C
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

```
