#include <stdio.h>
#include <stdlib.h>

/* episodio = aluno é só estrutura do que um epiosodio tem.
NO = NoEPISODIO o no tem o episodio e o ponteiro pro proximo.
CELULA = PODCAST
LISTA = PLAYLIST*/

//****************** INICIO STRUCTS *************************
/*Declaração da estrutura Episodio, possui as infos: nome do podcast, um ID que identifica o podcast, nome do episodio, numero do episodio.*/
typedef struct episodio 
{
  char nomePodcast[64];
  int podcastId;
  char nomeEpisodio[64];
  int numeroEpisodio;
} Episodio;

//Estrutura do No do episodio, guarda um episodio e um ponteiro para o proximo.
typedef struct noEpisodio
{
  Episodio episodio;
  struct episodio * proximo;
} NoEpisodio;

//Declarando Podcast: um apontamento para um no de Episódio. Não entendi bem como funciona, acho que tá errado.
typedef NoEpisodio * Podcast;

//Declarando Playlist: estrutura que mantem o rastreamento do inicio e final da playlist de podcasts, a propria lista ligada.
typedef struct playlist
{
  Podcast inicio;
  Podcast fim;
} Playlist;
//****************** FIM STRUCTS *************************

Podcast novoPodcast(Episodio episodio);

Playlist* novaPlaylist();

void insereNoFinal(Playlist* playlist, Episodio episodio);

void imprime(Playlist * playlist);

