#include <stdio.h>
#include <stdlib.h>

struct elemento{
  char infor;
  struct elemento *ant;
  struct elemento *prox;
};

typedef struct elemento Elemento;

struct arv{
    char info;
    struct arv *esq;
    struct arv *dir;
};

typedef struct arv Tree;

Elemento *lst_cria(){
  return NULL;
}
Elemento *push(Elemento *l, char valior){
  Elemento *novo = (Elemento *)malloc(sizeof(Elemento));
  Elemento *p;
  p=l;
  if(l==NULL){
    novo->infor = valior;
    novo->ant = NULL;
    novo->prox = l;
    return (novo);
  }
  else{
  while(p->prox!=NULL){
    p = p->prox;
  }
  if(p->prox==NULL){
    p->prox = novo;
    novo->infor = valior;
    novo->ant = p;
    novo->prox = NULL;
  }
  return (l);
  }
}

Elemento *pop(struct elemento *l){
  Elemento *ant = NULL;
  Elemento *p;
  p=l;
  if(l==NULL){
    return l;
  }
  else{
    l = p->prox;
  }
  free(p);
  return l;
}

Tree *plantar_nada(){
  return NULL;
}

Tree *plantar(char sem, Tree *l, Tree *r){
  Tree *p;
  p = (Tree *)malloc(sizeof(Tree));
  p->info = sem;
  p->esq = l;
  p->dir = r;
  return p;
};

int tem_nada(Tree *t){
  return t==NULL;
}

int busca(Tree *t,char i){
  if(tem_nada(t)){
    return 0;
  }
  else{
    return t->info==i || busca(t->esq,i) || busca(t->dir,i);
  }
}

Tree *motosserra(Tree *morta){
  if(!tem_nada(morta)){
    motosserra(morta->esq);
    motosserra(morta->dir);
    free(morta);
  }
  return NULL;
}

void papel_pre_ordem(Tree *planta){
  if(!tem_nada(planta)){
    printf("%c\n",planta->info);
    papel_pre_ordem(planta->esq);
    papel_pre_ordem(planta->dir);
  }
}

void papel_in_ordem(Tree *planta){
  if(!tem_nada(planta)){
    papel_in_ordem(planta->esq);
    printf("%c\n",planta->info);
    papel_in_ordem(planta->dir);

  }
}

void papel_pos_ordem(Tree *planta){
  if(!tem_nada(planta)){
    papel_pos_ordem(planta->esq);
    papel_pos_ordem(planta->dir);
    printf("%c\n",planta->info);

  }
}

void papel_largo(Elemento *l,Elemento *p,Tree *planta){
  if(!tem_nada(planta)){
    papel_largo(l,p,planta->esq);
    papel_largo(l,p,planta->dir);
    if(planta->esq ==NULL && planta->dir ==NULL){
      l = push(l,planta->info);
    }
  }
    while(l!=NULL){
    p = pop(l);
    printf("%c\n",p->infor);
  }
}

int main(){
  Elemento *l;
  Elemento *p;
  Tree *arvf7,*arvf2,*arvf3,*arvf4,*arvf5,*arvf6,*arvf8,*arvf9,*arvf10,*arvf11,*arvm;
  int opcao;
  char amostra;
  arvm = plantar_nada();
  do{
    printf("\n\t\t\t>>MENU<<\n\n");
    printf("0 - Sair\n");
    printf("1 - Inserir árvore(pré-definida)\n");
    printf("2 - Destrói árvore\n");
    printf("3 - Busca\n");
    printf("4 - Impressão pré-ordem\n");
    printf("5 - Impressão in-ordem\n");
    printf("6 - Impressão pos-ordem\n");
    printf("7 - Impressão por largura\n\n");
    printf("Escolha uma opção: ");
    scanf("%d",&opcao);

    while(opcao<0 || opcao>7){
      printf("\nEscolha uma opção válida: ");
      scanf("%d",&opcao);
    }
    if(opcao==1){
      arvf11 = plantar('B',plantar_nada(),plantar_nada());
      arvf10 = plantar('A',plantar_nada(),plantar_nada());
      arvf9 = plantar('C',plantar_nada(),plantar_nada());
      arvf8 = plantar('+',arvf10,arvf11);
      arvf7 = plantar('C',plantar_nada(),plantar_nada());
      arvf6 = plantar('B',plantar_nada(),plantar_nada());
      arvf5 = plantar('*', arvf8, arvf9);
      arvf4 = plantar('*', arvf6, arvf7);
      arvf3 = plantar('A', plantar_nada(), plantar_nada());
      arvf2 = plantar('+', arvf3, arvf4);
      arvm = plantar('/', arvf2, arvf5);
    }

    if(opcao==2){
      arvm = motosserra(arvm);
      printf("\nÁrvore destruída\n");
    }
    if(opcao==3){
      printf("\nEscolha a árvore a ser pesquisada: ");
      scanf("%c",&amostra);
      if(busca(arvm,amostra)){
        printf("\nÁrvore encontrada\n");
      }
      else{
        printf("\nÁrvore não encontrada\n");
      }
    }

    if(opcao==4){
      if(tem_nada(arvm)){
        printf("\nÁrvore vazia\n");
      }
      else{
      papel_pre_ordem(arvm);
      }
    }

    if(opcao==5){
      if(tem_nada(arvm)){
        printf("\nÁrvore vazia\n");
      }
      else{
      papel_in_ordem(arvm);
      }
    }

    if(opcao==6){
      if(tem_nada(arvm)){
        printf("\nÁrvore vazia\n");
      }
      else{
      papel_pos_ordem(arvm);
      }
    }


    if(opcao==7){
      l = lst_cria();
      if(tem_nada(arvm)){
        printf("\nÁrvore vazia\n");
      }
      else{
      papel_largo(l,p,arvm);
      }
    }

  }while(opcao);


  return 0;
}
