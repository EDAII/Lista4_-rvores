#include <bits/stdc++.h>

struct Node {
    int value;
    Node * left;
    Node * right;
};

class Tree {
public:
    Node * root;

    Tree() { root = NULL; }

    void insert(int element);
    void erase(int element);
    void clear();

    bool find(int element);

    bool empty();
    int size();
    int height();

    void print_preorder();
    void print_inorder();
    void print_postorder();

};

using namespace std;

void insert_recurssivo (Node *raiz,int element){

	if (raiz->value > element){
		if(raiz->left == NULL){
			raiz->left = (Node*)malloc(sizeof(Node));
			raiz->left->value = element;
			raiz->left->left = NULL;
			raiz->left->right = NULL;
		} else{
			insert_recurssivo(raiz->left,element);
		}
	} else if (raiz->value < element){
		if(raiz->right == NULL){
			raiz->right = (Node*)malloc(sizeof(Node));
			raiz->right->value = element;
			raiz->right->left = NULL;
			raiz->right->right= NULL;
		} else{
			insert_recurssivo(raiz->right,element);
		}
	}

}

void Tree::insert(int element)
{
    // Insere o elemento na posição correta da árvore
    // O(log n)
	  //Node *no;


	if (root == NULL){
		root = (Node*)malloc(sizeof(Node));
		root->value = element;
		root->left = NULL;
		root->right = NULL;
	} else
		insert_recurssivo(root,element);

}

void Tree::erase(int element)
{
    // Remove o elemento da árvore, se ele existir
    // O(log n)

    Node *no = root, *noRemocao = NULL, *noPai = NULL, *noAux= NULL,*novoPai=NULL;

    while (1){
  		if (no == NULL){
  			break;
  		} else if(no->value == element){
  			noRemocao = no;
  			break;
  		}
  		else if(no->value > element){
  			noPai = no;
  			no = no->left;
  		}
  		else if (no->value < element){
  			noPai = no;
  			no = no->right;
  		}
  	}
	  if (noRemocao){
  		if(noPai){
  			if(noRemocao->left == NULL && noRemocao->right == NULL){
  				if(noPai->value > noRemocao->value){
  					free(noRemocao);
  					noPai->left = NULL;
  				}
  				else if(noPai->value < noRemocao->value){
  					free(noRemocao);
  					noPai->right = NULL;
  				}
  			} else if (noRemocao->left != NULL && noRemocao->right == NULL){
  				if(noPai->value > noRemocao->value){
  					noPai->left = noRemocao->left;
  					free(noRemocao);
  				}
  				else if(noPai->value < noRemocao->value){
  					noPai->right = noRemocao->left;
  					free(noRemocao);
  				}
  			} else if (noRemocao->left == NULL && noRemocao->right != NULL){
  				if(noPai->value > noRemocao->value){
  					noPai->left = noRemocao->right;
  					free(noRemocao);
  				}
  				else if(noPai->value < noRemocao->value){
  					noPai->right = noRemocao-> right;
  					free(noRemocao);
  				}
  			} else if(noRemocao->left != NULL && noRemocao->left != NULL){
  				noPai = noRemocao;
  				noAux = noRemocao->right;
  				while(noAux->left){
  					noPai = noAux;
  					noAux = noAux->left;
  				}
			    noRemocao->value = noAux->value;
          if(noAux->left == NULL && noAux->right == NULL){
          	if(noPai->value > noAux->value){
          		free(noAux);
          		noPai->left = NULL;
          	}
          	else if(noPai->value < noAux->value){
          		free(noAux);
          		noPai->right = NULL;
          	}
          } else if (noAux->left != NULL && noAux->right == NULL){
          	if(noPai->value > noAux->value){
          		noPai->left = noAux->left;
          		free(noAux);
          	}
          	else if(noPai->value < noAux->value){
          		noPai->right = noAux->left;
          		free(noAux);
          	}
          } else if (noAux->left == NULL && noAux->right != NULL){
          	if(noPai->value > noAux->value){
          		noPai->left = noAux->right;
          		free(noAux);
          	}
          	else if(noPai->value < noAux->value){
          		noPai->right = noAux-> right;
          		free(noAux);
          	}
      		}
  			}
		}else if (noRemocao->left == NULL && noRemocao->right == NULL) {
			free (noRemocao);
			noRemocao = NULL;

		} else if (noRemocao == root){
			noPai = noRemocao;
			noAux = noRemocao->right;

			while(noAux->left){
				noPai = noAux;
				noAux = noAux->left;
			}
			novoPai = new Node();
			novoPai->value = noAux->value;

			if(noAux->left == NULL && noAux->right == NULL){
				if(noPai->value > noAux->value){
					free(noAux);
					noPai->left = NULL;
				}
				else if(noPai->value < noAux->value){
					free(noAux);
					noPai->right = NULL;
				}
			} else if (noAux->left != NULL && noAux->right == NULL){
				if(noPai->value > noAux->value){
					noPai->left = noAux->left;
					free(noAux);
				} else if(noPai->value < noAux->value){
					noPai->right = noAux->left;
					free(noAux);
				}

			} else if (noAux->left == NULL && noAux->right != NULL){
				if(noPai->value > noAux->value){
					noPai->left = noAux->right;
					free(noAux);
				} else if(noPai->value < noAux->value){
					noPai->right = noAux-> right;
					free(noAux);
				}

			}
			noPai->value = novoPai->value;
			free(novoPai);

		}

	}

}


void clear_recurssivo(Node *no){

	if (no->left)
		clear_recurssivo(no->left);
	if (no->right)
		clear_recurssivo(no->right);
	free(no);

}

void Tree::clear()
{
    // Remove todos os nós da árvore
    // O(n)

    if (root){
    	clear_recurssivo(root);
    	root = NULL;
    }
}



bool Tree::find(int element)
{
    // Procura o elemento na árvore
    // O(log n)

	Node *no = root;

	while (1){
		if (no == NULL){
			return false;
		} else if(no->value == element){
			return true;
		} else if(no->value > element){
			no = no->left;
		} else if (no->value < element){
			no = no->right;
		}
	}


    return true;
}

bool Tree::empty()
{
    // Diz se a árvore está vazia ou não
    // O(1)
    if (root)
    	return false;
    else
   		return true;
}



void size_recursivo(Node *no, int *contador){

	if(no->left)
		size_recursivo(no->left,contador);
	if(no->right)
		size_recursivo(no->right,contador);
	*contador+=1;

}

int Tree::size()
{
    // Diz o número de nós que a árvore possui
    // O(n)

    int contador = 0;

    if (!root){
    	return -1;
    } else {
    	size_recursivo(root,&contador);
    	return contador;
    }

    return -1;
}



void altura_recurssiva(Node *no, int *maior, int aux){

	if (no->left)
		altura_recurssiva(no->left, maior, aux+1);

	if (no->right)
		altura_recurssiva(no->right,maior,aux+1);

	if(aux > *maior)
		*maior = aux;

}

int Tree::height()
{
    // Diz a altura da árvore
    // O(n)
	int maior = 0;
	int aux = 0;

	if (!root)
		return -1;
	else{
		altura_recurssiva(root,&maior,aux);
		return maior;
	}

    return -1;
}


void preorder_recursiva(Node *no){

	cout << no->value << endl;
	if (no->left){
		preorder_recursiva(no->left);
	}
	if (no->right){
		preorder_recursiva(no->right);
	}


}

void Tree::print_preorder()
{
    // Faz a impressão Pre Order da árvore
    // O(n)

    if (root){
    	preorder_recursiva(root);
    }
}



void inorder_recursiva(Node *no){

	if(no->left != NULL){
		inorder_recursiva(no->left);
	}

	cout << no->value << endl;

	if(no->right != NULL){
			inorder_recursiva(no->right);
	}

}
void Tree::print_inorder()
{
    // Faz a impressão In Order da árvore
    // O(n)

	int valor;

	if (root){
		inorder_recursiva(root);
	}


}


void postorder_recursiva(Node *no){

	if (no->left){
		postorder_recursiva(no->left);
	}
	if (no->right){
		postorder_recursiva(no->right);
	}
	cout << no->value << endl;

}

void Tree::print_postorder()
{
    // Faz a impressão Post Order da árvore
    // O(n)

    if(root){
    	postorder_recursiva(root);
    }
}

int main() {
    Tree arvore;

    arvore.insert(42);
    arvore.insert(16);
    arvore.insert(57);
    arvore.insert(48);
    arvore.insert(63);
    arvore.insert(35);
    arvore.insert(8);
    arvore.insert(11);
    arvore.insert(5);

    arvore.print_preorder();
    arvore.print_inorder();
    arvore.print_postorder();

    cout << "Tamanho = " << arvore.size() << endl;
    cout << "Altura  = " << arvore.height() << endl;

    if (arvore.find(42)) cout << 42 << " encontrado!\n";
    if (arvore.find(63)) cout << 63 << " encontrado!\n";
    if (arvore.find( 8)) cout <<  8 << " encontrado!\n";
    if (arvore.find( 5)) cout <<  5 << " encontrado!\n";
    if (arvore.find( 7)) cout <<  7 << " encontrado!\n";

    arvore.erase(6);
    arvore.erase(48);

    arvore.print_preorder();
    arvore.print_inorder();
    arvore.print_postorder();

    arvore.erase(42);
    arvore.erase(57);
    arvore.erase(48);
    arvore.erase(35);

    arvore.print_preorder();
    arvore.print_inorder();
    arvore.print_postorder();

    cout << "Tamanho = " << arvore.size() << endl;
    cout << "Altura  = " << arvore.height() << endl;

    if (arvore.find(42)) cout << 42 << " encontrado!\n";
    if (arvore.find(63)) cout << 63 << " encontrado!\n";
    if (arvore.find(48)) cout << 48 << " encontrado!\n";
    if (arvore.find( 5)) cout <<  5 << " encontrado!\n";
    if (arvore.find(57)) cout << 57 << " encontrado!\n";

    if (arvore.empty()) cout << "Arvore vazia" << endl;

    arvore.clear();
    if (arvore.empty()) cout << "Arvore vazia" << endl;

    arvore.print_preorder();
    arvore.print_inorder();
    arvore.print_postorder();

    return 0;
}
