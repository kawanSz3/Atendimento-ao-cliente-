# Triagem Digital do Hospital Campo Real

## Descricao

Programa de terminal para organizar a fila de pacientes, os médicos disponíveis
e o histórico dos atendimentos do Hospital Campo Real.

## Estruturas de dados

- **Fila FIFO:** pacientes são atendidos na ordem de chegada. A urgência é
  registrada e exibida, mas não altera essa ordem.
- **Pilha LIFO:** guarda os pacientes atendidos, do mais recente ao mais antigo.
- **Lista encadeada:** mantém os médicos disponíveis; o médico chamado retorna
  ao final da lista após o atendimento.

As três estruturas usam nós ligados por ponteiros, alocados com `new` e
liberados com `delete`.

## Compilacao

No terminal, na pasta do projeto, execute:

```sh
g++ -std=c++17 -Wall -o atendimento atendimento_template.cpp
```

## Execucao

No Windows PowerShell:

```powershell
.\atendimento.exe
```

O menu permite cadastrar pacientes e médicos, consultar a fila e os médicos,
realizar atendimentos e consultar ou remover o atendimento mais recente. A
opção de relatório mostra o histórico sem apagar seus dados.

## Exemplo de saida

```text
=== Triagem Digital do Hospital Campo Real ===
1. Cadastrar paciente
2. Cadastrar medico
3. Mostrar pacientes aguardando
4. Realizar atendimento
5. Mostrar medicos disponiveis
6. Imprimir historico
7. Ver atendimento mais recente
8. Remover atendimento mais recente
9. Sair
Opcao: 4
Atendimento realizado: Ana Silva atendido(a) pelo(a) Dr(a). Joao Costa.

Historico (do mais recente ao mais antigo):
- Ana Silva
```
