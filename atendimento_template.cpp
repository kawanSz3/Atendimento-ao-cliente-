#include <iostream>
#include <string>

using namespace std;

// O mesmo tipo de nó é usado pela fila, pela pilha e pela lista de médicos.
struct No {
    string nome;
    int urgencia;
    No* prox;
};

No* inicioFila = nullptr;
No* fimFila = nullptr;
No* topoHistorico = nullptr;
No* inicioMedicos = nullptr;
No* fimMedicos = nullptr;

// Adiciona um paciente no final da fila.
void enqueue(const string& nome, int urgencia) {
    if (urgencia < 1 || urgencia > 3) {
        cout << "Urgencia invalida. Use 1, 2 ou 3.\n";
        return;
    }

    No* novo = new No{nome, urgencia, nullptr};
    if (fimFila == nullptr) {
        inicioFila = novo;
        fimFila = novo;
    } else {
        fimFila->prox = novo;
        fimFila = novo;
    }
}

// Remove e devolve o primeiro paciente da fila.
No* dequeue() {
    if (inicioFila == nullptr) {
        cout << "A fila de pacientes esta vazia.\n";
        return nullptr;
    }

    No* removido = inicioFila;
    inicioFila = inicioFila->prox;
    if (inicioFila == nullptr) {
        fimFila = nullptr;
    }
    removido->prox = nullptr;
    return removido;
}

// Mostra o primeiro paciente sem removê-lo.
void frente_peak() {
    if (inicioFila == nullptr) {
        cout << "A fila de pacientes esta vazia.\n";
        return;
    }

    cout << "Primeiro paciente: " << inicioFila->nome
         << " (urgencia " << inicioFila->urgencia << ")\n";
}

// Conta os pacientes percorrendo a fila.
int tamanho() {
    int quantidade = 0;
    No* atual = inicioFila;
    while (atual != nullptr) {
        quantidade++;
        atual = atual->prox;
    }
    return quantidade;
}

// Registra um atendimento no topo da pilha.
void push(const string& nome) {
    No* novo = new No{nome, 0, topoHistorico};
    topoHistorico = novo;
}

// Remove e devolve o atendimento mais recente.
No* pop() {
    if (topoHistorico == nullptr) {
        cout << "O historico de atendimentos esta vazio.\n";
        return nullptr;
    }

    No* removido = topoHistorico;
    topoHistorico = topoHistorico->prox;
    removido->prox = nullptr;
    return removido;
}

// Mostra o atendimento mais recente sem removê-lo.
void peek() {
    if (topoHistorico == nullptr) {
        cout << "O historico de atendimentos esta vazio.\n";
        return;
    }

    cout << "Atendimento mais recente: " << topoHistorico->nome << '\n';
}

// Adiciona um médico ao final da lista de disponíveis.
void adicionarMedico(const string& nome) {
    No* novo = new No{nome, 0, nullptr};
    if (fimMedicos == nullptr) {
        inicioMedicos = novo;
        fimMedicos = novo;
    } else {
        fimMedicos->prox = novo;
        fimMedicos = novo;
    }
}

// Retira e devolve o primeiro médico disponível.
No* chamarMedico() {
    if (inicioMedicos == nullptr) {
        cout << "Nao ha medicos disponiveis.\n";
        return nullptr;
    }

    No* chamado = inicioMedicos;
    inicioMedicos = inicioMedicos->prox;
    if (inicioMedicos == nullptr) {
        fimMedicos = nullptr;
    }
    chamado->prox = nullptr;
    return chamado;
}

// Lista todos os médicos disponíveis.
void percorrer() {
    if (inicioMedicos == nullptr) {
        cout << "Nao ha medicos disponiveis.\n";
        return;
    }

    cout << "Medicos disponiveis:\n";
    No* atual = inicioMedicos;
    while (atual != nullptr) {
        cout << "- " << atual->nome << '\n';
        atual = atual->prox;
    }
}

int main() {
    int opcao = 0;
    while (opcao != 4) {
        cout << "\n=== Fila de pacientes ===\n"
             << "1. Cadastrar paciente\n"
             << "2. Chamar primeiro paciente\n"
             << "3. Mostrar primeiro e tamanho da fila\n"
             << "4. Sair\n"
             << "Opcao: ";
        if (!(cin >> opcao)) {
            break;
        }

        if (opcao == 1) {
            string nome;
            int urgencia;
            cout << "Nome do paciente: ";
            cin >> ws;
            getline(cin, nome);
            cout << "Urgencia (1=baixa, 2=media, 3=alta): ";
            if (cin >> urgencia) {
                enqueue(nome, urgencia);
            } else {
                break;
            }
        } else if (opcao == 2) {
            No* paciente = dequeue();
            if (paciente != nullptr) {
                cout << "Paciente chamado: " << paciente->nome << '\n';
                delete paciente;
            }
        } else if (opcao == 3) {
            frente_peak();
            cout << "Pacientes aguardando: " << tamanho() << '\n';
        } else if (opcao != 4) {
            cout << "Opcao invalida.\n";
        }
    }

    while (inicioFila != nullptr) {
        No* removido = inicioFila;
        inicioFila = inicioFila->prox;
        delete removido;
    }
    fimFila = nullptr;
    return 0;
}
