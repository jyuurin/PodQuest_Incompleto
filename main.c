#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcoesPlaylist.h"

/* episodio = elemento, é só estrutura do que um epiosodio tem.
NO = NoEPISODIO o no tem o episodio e o ponteiro pro proximo.
CELULA = PODCAST
LISTA = PLAYLIST*/

//****************** INICIO FUNÇÕES *************************
//Inserir novo episódio na playlist de podcasts.
void novoEpisodio(Playlist * playlist)
{
  //OBS: função >fgets< é uma maneira segura de trabalhar com strings, uma vez que ao contrario do scanf, ela não para mesmo depois de encontrar um espaço.
  Episodio episodio;
  printf("Nome do podcast: ");
  fgets(episodio.nomePodcast, 64, stdin);
    
  printf("Id do Podcast: ");
  scanf("%d", &episodio.podcastId);
  getchar();
  
  printf("Nome do Episódio: ");
  fgets(episodio.nomeEpisodio, 64, stdin);
  
  printf("Numero do Episódio: ");
  scanf("%d", &episodio.numeroEpisodio);
  getchar();
  
  //getchar() 
  insereNoFinal(playlist, episodio);
}


//****************** FIM FUNÇÕES *************************

int main() 
{
  Playlist * playlist = novaPlaylist();
  int opcao = 0;
  int executar = 1;  
  printf("Playlist de Podcasts! Digite a opção desejada.\n---------------------------\n");

  while(executar)
  {
    printf("1 - Adicionar um Episodio; \n2 - Imprimir;\n3 - Desligar\n---------------------------\n");
    scanf("%d", &opcao);
    getchar();
    //TALVEZ PRECISE COLOCAR GETCHAR PRA ALGUMA COISA QUE EU NAO SEI (Y)
    
    switch(opcao)
    {
      //1 - Adicionar um Episodio: executa a função de incluir episodio.
      case 1:
      {
        novoEpisodio(playlist);
        break;
      }
      case 2:
      {
        printf("Episodios até agora:");
        imprime(playlist);
        printf("---------------------------\n");
        break;
      }
      //2 - Remover um Episodio: Executa a função de excluir episodio.
      /*case 2: 
      {
        //ADDNOVOEP();
        break;
      }*/
      //3 - Tocar um Episodio: Executa a função de tocar episodio.  
     /* case 3: 
      {
        //TocarEpisodio();
        break;
      }
      //4 - Modo Aleatório: Ativa e desativa função do suffle.
      case 4: 
      {
        //modoAleatorio();
        break;
      }*/
      //5 - Desligar: Executar igual a 0 e encerra o looping.
      case 3:
      {
        printf("Playlist encerrada!\n");
        executar = 0;
        break;
      }
    }
  }
  
  


  
  return 0;
}