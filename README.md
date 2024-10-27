# Estrutura de Dados - Universidade Federal de Santa Maria (UFSM)

Bem-vindo ao repositório do curso de **Estrutura de Dados** oferecido pela Universidade Federal de Santa Maria (UFSM). Este repositório contém implementações, exercícios e projetos realizados ao longo da disciplina, abordando tópicos fundamentais e avançados de estruturas de dados com ênfase em aplicações práticas e desempenho.

## Índice

- [Descrição da Disciplina](#descrição-da-disciplina)
- [Objetivos de Aprendizagem](#objetivos-de-aprendizagem)
- [Conteúdo do Repositório](#conteúdo-do-repositório)
- [Tecnologias Utilizadas](#tecnologias-utilizadas)
- [Como Usar o Repositório](#como-usar-o-repositório)
- [Estrutura de Arquivos](#estrutura-de-arquivos)
- [Contribuições](#contribuições)
- [Contato](#contato)

---

## Descrição da Disciplina

A disciplina de **Estrutura de Dados** tem como foco o estudo e a implementação de estruturas de dados essenciais para a construção de algoritmos eficientes. São abordados desde tipos de dados abstratos básicos, como listas e filas, até estruturas complexas como árvores e grafos. A matéria enfatiza a análise de complexidade, uso de memória e otimização de código.

---

## Objetivos de Aprendizagem

Ao concluir este curso, espera-se que os estudantes sejam capazes de:

- Implementar e manipular diversas estruturas de dados, como listas, pilhas, filas, árvores e grafos.
- Analisar e otimizar o desempenho de algoritmos, entendendo a complexidade de tempo e espaço.
- Aplicar estruturas de dados na resolução de problemas práticos e complexos.
- Desenvolver habilidades em programação orientada a objetos e alocação dinâmica.

---

## Conteúdo do Repositório

O repositório é organizado por módulos correspondentes aos tópicos abordados durante a disciplina:

1. **Introdução às Estruturas de Dados**
   - Tipos de Dados Abstratos (TADs)
   - Listas Simplesmente e Duplamente Encadeadas
2. **Estruturas Lineares**
   - Pilhas (Stacks)
   - Filas (Queues) e Filas de Prioridade
3. **Árvores**
   - Árvores Binárias
   - Árvores AVL e Árvores Rubro-Negra
4. **Tabelas Hash**
   - Implementação de Tabelas Hash
   - Tratamento de Colisões
5. **Grafos**
   - Representação de Grafos (matriz de adjacência e listas de adjacência)
   - Algoritmos de Busca em Grafos (BFS, DFS)
   - Algoritmos de Caminho Mínimo (Dijkstra, Floyd-Warshall)
6. **Algoritmos de Ordenação**
   - Ordenação por Inserção, Seleção, e Merge Sort
   - Quick Sort e Ordenação Heapsort
7. **Aplicações Práticas e Projetos Finais**
   - Exercícios de Aplicação em Casos Reais
   - Projeto Final: Sistema de Cadastro com Árvores e Listas

---

## Tecnologias Utilizadas

- **Linguagem de Programação**: C e C++ para implementação das estruturas de dados.
- **Ambiente de Desenvolvimento**: Visual Studio Code, Code::Blocks, ou IDEs específicas para C e C++.
- **Ferramentas de Documentação**: Markdown para documentação, Doxygen para geração automática de documentação em C/C++.

---

## Como Usar o Repositório

Para compilar e testar os códigos:

1. Clone este repositório para seu ambiente local:
    ```bash
    git clone https://github.com/ODiogorocha/Estrutura-de-dados.git
    ```
2. Entre no diretório do projeto:
    ```bash
    cd estrutura-de-dados
    ```
3. Compile e execute o código desejado. Por exemplo, para compilar uma lista encadeada:
    ```bash
    gcc listas/lista_encadeada.c -o lista_encadeada
    ./lista_encadeada
    ```
4. Explore os diretórios de cada módulo para encontrar implementações e exercícios específicos.

---

## Estrutura de Arquivos

```plaintext
.
├── listas
│   ├── lista_encadeada.c           # Implementação de lista encadeada
│   ├── lista_duplamente_encadeada.c # Implementação de lista duplamente encadeada
│   └── lista_circular.c             # Implementação de lista circular
├── pilhas
│   ├── pilha.c                      # Implementação de pilha
│   └── pilha_com_lista.c            # Pilha implementada com lista encadeada
├── filas
│   ├── fila.c                       # Implementação de fila
│   └── fila_prioridade.c            # Fila de prioridade
├── arvores
│   ├── arvore_binaria.c             # Implementação de árvore binária
│   ├── arvore_avl.c                 # Implementação de árvore AVL
│   └── arvore_rb.c                  # Implementação de árvore rubro-negra
├── grafos
│   ├── grafo_matriz.c               # Grafo usando matriz de adjacência
│   └── grafo_lista.c                # Grafo usando lista de adjacência
├── README.md                        # Documentação do repositório
└── LICENSE                          # Licença do projeto
```

---

## Contribuições

Contribuições são bem-vindas! Caso encontre algum problema ou tenha sugestões para melhorias, por favor, abra uma [issue](https://github.com/seu-usuario/estrutura-de-dados/issues) ou envie um [pull request](https://github.com/seu-usuario/estrutura-de-dados/pulls).

Para contribuir:

1. Crie um fork do projeto.
2. Faça suas modificações em um branch separado:
   ```bash
   git checkout -b feature/sua-melhoria
   ```
3. Envie suas alterações:
   ```bash
   git push origin feature/sua-melhoria
   ```
4. Abra um pull request para o branch `main`.

---

## Contato

Para dúvidas e sugestões sobre o conteúdo ou uso do repositório, entre em contato:

- **Autor**: Diogo

---

