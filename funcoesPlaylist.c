#include "funcoesPlaylist.h"

/* episodio = aluno é só estrutura do que um epiosodio tem.
NO = NoEPISODIO o no tem o episodio e o ponteiro pro proximo.
CELULA = PODCAST
LISTA = PLAYLIST*/
//****************** INICIO FUNÇÕES *************************

//---------- FUNÇAO CRIA PODCAST ------
/*Recebe uma estrutura episodio para ser guardado no podcast.*/
Podcast novoPodcast(Episodio episodio)
{
  Podcast novo = (Podcast) malloc(sizeof(NoEpisodio));
  novo->proximo = NULL; 
  novo->episodio = episodio;
  return novo;
}
//---------- FUNÇAO CRIA PLAYLIST ------
/*Recebe uma estrutura podcast para ser guardado na Playlist.*/
Playlist* novaPlaylist()
{
  Playlist* newList = (Playlist*) malloc(sizeof(struct playlist));

  newList->inicio = NULL;
  newList->fim = NULL;
  return newList;
}

//---------- FUNÇAO INSERIR NO FINAL ------
/*Cria um podcast, e insere ele no final da Playlist. Recebe os parametros playlist onde o podcast vai ser inserido e o episodio a ser armazenado. */
void insereNoFinal(Playlist* playlist, Episodio episodio)
{
  Podcast newPodcast = novoPodcast(episodio);
  if(playlist->inicio == NULL)
  {
    playlist->inicio = newPodcast;
    playlist->fim = newPodcast;
    return;
  }
  playlist->fim->proximo = newPodcast;
  playlist->fim = newPodcast;
}

//---------- FUNÇAO REMOVE EPISODIO ------
/**/
/*Podcast removeEpisodio(Playlist * playlist, Episodio idEpisodio)
{
  //funçao de busca para procurar o episodio.
  Podcast episodioRemover = //ProcuraPodcast(Playlist, idEpisodio)
  
  if(episodioRemover != NULL)
  {
    
  }
  
}*/

//---------- FUNÇAO IMPRIMIR ------
/*Imprime todos os episodios de podcast da playlist. */
void imprime(Playlist * playlist)
{
  Podcast auxiliar = playlist->inicio;
  while(auxiliar != NULL)
  {
    printf("\nNome Podcast: %sId Podcast: %d\nNome Episodio: %sNumero Episodio:%d\n", auxiliar->episodio.nomePodcast, auxiliar->episodio.podcastId, auxiliar->episodio.nomeEpisodio, auxiliar->episodio.numeroEpisodio);
    if(auxiliar->proximo != NULL)
      printf("-----");
    auxiliar = auxiliar->proximo;
  }
  printf("\n");
}

//****************** FIM FUNÇÕES *************************