#include <iostream>
using namespace std;

const int MAXTAM = 100;

// Estrutura da pilha
struct Pilha {
    int itens[MAXTAM]; // Array para armazenar os elementos da pilha
    int topo; // Índice do topo da pilha
};

// Função para inicializar a pilha como vazia
void InicializaPilha(Pilha *pilha) {
    pilha->topo = -1; // Define o topo como -1, indicando pilha vazia
}

// Função para verificar se a pilha está cheia
bool PilhaCheia(Pilha pilha) {
    return pilha.topo == MAXTAM - 1;
}

// Função para verificar se a pilha está vazia
bool PilhaVazia(Pilha pilha) {
    return pilha.topo == -1;
}

// Função para empilhar um elemento
void Empilha(int valor, Pilha *pilha) {
    if (PilhaCheia(*pilha)) {
        cout << "Erro: a pilha está cheia!" << endl;
    } else {
        pilha->topo++; // Incrementa o índice do topo
        pilha->itens[pilha->topo] = valor; // Insere o valor no topo
        cout << "Valor " << valor << " empilhado." << endl;
    }
}

// Função para desempilhar um elemento
void Desempilha(Pilha *pilha, int *valor) {
    if (PilhaVazia(*pilha)) {
        cout << "Erro: a pilha está vazia!" << endl;
    } else {
        *valor = pilha->itens[pilha->topo]; // Recupera o valor do topo
        pilha->topo--; // Decrementa o índice do topo
        cout << "Valor " << *valor << " desempilhado." << endl;
    }
}

// Função para imprimir todos os elementos da pilha
void ImprimePilha(Pilha pilha) {
    if (PilhaVazia(pilha)) {
        cout << "A pilha está vazia." << endl;
    } else {
        cout << "Elementos na pilha: ";
        for (int i = 0; i <= pilha.topo; i++) {
            cout << pilha.itens[i] << " ";
        }
        cout << endl;
    }
}

// Função para buscar um elemento na pilha (desempilhando temporariamente)
bool BuscaDesempilhando(Pilha* pilha, int valor) {
    Pilha temp;
    InicializaPilha(&temp);
    bool encontrado = false;

    // Desempilha até encontrar o valor ou a pilha esvaziar
    while (!PilhaVazia(*pilha)) {
        int temp_valor;
        Desempilha(pilha, &temp_valor);
        if (temp_valor == valor) {
            encontrado = true;
            Empilha(temp_valor, &temp);
            break;
        } else {
            Empilha(temp_valor, &temp);
        }
    }

    // Restaura a pilha original
    while (!PilhaVazia(temp)) {
        int temp_valor;
        Desempilha(&temp, &temp_valor);
        Empilha(temp_valor, pilha);
    }

    return encontrado;
}

int main() {
    Pilha pilha;
    InicializaPilha(&pilha);

    int opcao, valor;
    do {
        cout << "1 - Empilhar" << endl;
        cout << "2 - Desempilhar" << endl;
        cout << "3 - Verificar se Pilha Vazia" << endl;
        cout << "4 - Verificar se Pilha Cheia" << endl;
        cout << "5 - Imprimir Pilha" << endl;
        cout << "6 - Buscar Elemento" << endl;
        cout << "0 - Sair" << endl;
        cout << "Escolha uma opcao: ";
        cin >> opcao;

        switch (opcao) {
            case 1:
                cout << "Digite um valor para empilhar: ";
                cin >> valor;
                Empilha(valor, &pilha);
                break;
            case 2:
                Desempilha(&pilha, &valor);
                break;
            case 3:
                cout << (PilhaVazia(pilha) ? "A pilha está vazia." : "A pilha não está vazia.") << endl;
                break;
            case 4:
                cout << (PilhaCheia(pilha) ? "A pilha está cheia." : "A pilha não está cheia.") << endl;
                break;
            case 5:
                ImprimePilha(pilha);
                break;
            case 6:
                cout << "Digite o valor a buscar: ";
                cin >> valor;
                cout << (BuscaDesempilhando(&pilha, valor) ? "Elemento encontrado!" : "Elemento não encontrado.") << endl;
                break;
            case 0:
                cout << "Saindo..." << endl;
                break;
            default:
                cout << "Opção inválida!" << endl;
        }
    } while (opcao != 0);

    return 0;
}
