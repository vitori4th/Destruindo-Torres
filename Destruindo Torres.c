#include <stdio.h>
#include <stdlib.h>
#define MAX 5000

//torre/itens
typedef struct torre{
  int id;
  int vida;//diz a prioridade, menor vida + prioridade(chav
} torre;

typedef torre * aTorre;

//fila de prioridade
typedef struct fp{
  torre v;
  int n;//n é o numero atual
} FP;

typedef FP * p_fp;

//função cria fila de prioridade
p_fp criar_fila_prio(int tamanho){
  p_fp fprio = (p_fp) malloc(tamanho * sizeof(FP)); 
  fprio->n = 0;//n= quantidade de elementos que tenho agora
  return fprio;
}

// função troca
void troca(aTorre a, aTorre b){
  torre t = *b;
  *b = *a;
  *a = t;
}

//função sobe estrutura de dados(heap)
void sobe(p_fp fprio, int posicao){
  if(posicao == 0){
    //RAIZ NAO SOBE 
    return;
  }

  int pai = (posicao-1) / 2;

  if (fprio[pai].v.vida == fprio[posicao].v.vida){
    // vida igual 
    if (fprio[pai].v.id > fprio[posicao].v.id){ 
      // qual id é menor
      troca(&(fprio[posicao].v), &(fprio[pai].v));
      sobe(fprio, pai);
    } else{
      troca(&(fprio[posicao].v), &(fprio[pai].v));
      sobe(fprio, posicao);
    }
  }

   if(fprio[pai].v.vida > fprio[posicao].v.vida){
     //menos vida
      troca(&(fprio[posicao].v), &(fprio[pai].v));
      sobe(fprio, pai);
  }
}

//fução para inserir torre 
void insere (p_fp fprio, int idd, int vidaa){
  fprio[fprio->n].v.vida = vidaa;
  fprio[fprio->n].v.id = idd;
  fprio->n = fprio->n + 1;
  sobe(fprio, fprio->n - 1);
}

//função desce estutura de dados(heap)
void desce(p_fp fprio, int posicao){ 
  int esquerdo = 2 * posicao + 1;
  int direito = 2 * posicao + 2;
  int menor_filho = -1;
  
  if(esquerdo >= fprio->n){
    //ja sou uma folha
    return;
  }else{
    //esquerdo é menor
    menor_filho = esquerdo;
  }
  
  if(direito < fprio->n && fprio[direito].v.vida < fprio[esquerdo].v.vida){
    //direito é menor
    menor_filho = direito;
  }

  if (fprio[direito].v.vida == fprio[esquerdo].v.vida){
    //vida igual
    if (fprio[direito].v.id < fprio[esquerdo].v.id){
      //qual id é menor
      menor_filho = direito;//direiro menor id
    }else{
      
      menor_filho = esquerdo;//esquerdo menor id
    }
  }

  //comparar e trocar com o menor
  if(fprio[posicao].v.vida > fprio[menor_filho].v.vida){
    //menos vida
      troca(&(fprio[menor_filho].v), &(fprio[posicao].v));
      desce(fprio, menor_filho);
  }
  
  if (fprio[posicao].v.vida == fprio[menor_filho].v.vida){
    //vida igual
    if (fprio[posicao].v.id > fprio[menor_filho].v.id){ 
      //qual menor id
      troca(&(fprio[menor_filho].v), &(fprio[posicao].v));
      desce(fprio, menor_filho);
    } else{
      troca(&(fprio[menor_filho].v), &(fprio[posicao].v));
      desce(fprio,posicao);
    }
  }
}

//funçao tira do menor, torre alvo
torre extrai_minimo(p_fp fprio){
  if (fprio==NULL){
    exit (-1);
  }  

  torre alvo; 
  alvo.vida = fprio[0].v.vida;
  alvo.id = fprio[0].v.id;
  troca(&(fprio[0].v), &(fprio[fprio->n-1].v));
  fprio->n = fprio->n - 1;
  desce(fprio, 0);
  return alvo;
}

//funçao tamanho da fila
int tamanho_fila (p_fp fprio){
  return fprio->n;
}

int main(int argc, char * argv[]){
  
  p_fp f = criar_fila_prio(MAX);
  int torre_id = 0;
  int turnos = 0;
  int dano_jogador = 0;
  
  //lendo a quantidade de turnos
  scanf("%d", & turnos);
  
  //semente para o gerador de numeros aleatorios
  srand(turnos);

  //enquanto houverem turnos
  while(turnos > 0){
    //Nasce uma nova torre com vida sorteada aleatoriamente 
    //entre 1 e 20
    if(tamanho_fila(f) < MAX){
      int vida = (rand() % 20) + 1;
      printf("Nova torre %d: %d\n", torre_id, vida);
      insere(f, torre_id, vida);
      torre_id++;
    }
    
    //Encontrando o proximo alvo e atacando (remove 10 de vida)
    torre torre_alvo = extrai_minimo(f);
    printf("Atk %d: %d -> %d\n", torre_alvo.id, torre_alvo.vida, torre_alvo.vida - 10);
    torre_alvo.vida = torre_alvo.vida - 10;
    if(torre_alvo.vida > 0){
      //Torre nao caiu, volta para fila
      insere(f, torre_alvo.id, torre_alvo.vida);
    }else{
      printf("t%d caiu\n", torre_alvo.id);
    }
    
    //cada torre vida causa 1 de dado no jogador
    int num_torres_vivas = tamanho_fila(f);
    printf("%d dano\n\n", num_torres_vivas);
    dano_jogador = dano_jogador + num_torres_vivas;
    turnos--;
  }
  
  printf("\nFINAL:\n");
  printf("Jogador tomou %d dano\n", dano_jogador);

  return 0;
}