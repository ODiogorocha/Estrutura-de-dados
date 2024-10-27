
```markdown
# Matrizes Especiais em C

Este repositório contém implementações em C para manipulação de matrizes especiais: **matriz diagonal**, **matriz esparsa**, **matriz identidade** e **matriz tridimensional**. O objetivo do projeto é explorar otimizações de armazenamento e processamento usando alocação dinâmica e estruturas de dados específicas.

## Índice
- [Descrição do Projeto](#descrição-do-projeto)
- [Estruturas de Dados](#estruturas-de-dados)
- [Funcionalidades](#funcionalidades)
- [Pré-requisitos](#pré-requisitos)
- [Instalação](#instalação)
- [Como Executar](#como-executar)
- [Uso](#uso)
- [Exemplos](#exemplos)
- [Estrutura de Arquivos](#estrutura-de-arquivos)
- [Autores](#autores)

---

## Descrição do Projeto

Este projeto implementa tipos específicos de matrizes, com o objetivo de otimizar o armazenamento de dados:
1. **Matriz Diagonal**: Armazena apenas os elementos da diagonal principal.
2. **Matriz Esparsa**: Usa listas encadeadas para armazenar somente valores não nulos.
3. **Matriz Identidade**: Verifica se a matriz é identidade e exibe valores que não atendem a essa condição.
4. **Matriz 3D**: Matriz tridimensional com funções de criação, preenchimento e impressão.

---

## Estruturas de Dados

### 1. Matriz Diagonal
- **Estrutura:** `Diagonal`
- **Descrição:** Armazena os valores da diagonal principal em um vetor, economizando espaço ao ignorar os valores nulos.
- **Campos:**
  - `int ordem`: Ordem da matriz.
  - `int* v`: Vetor para armazenar os elementos da diagonal.

### 2. Matriz Esparsa
- **Estruturas:** `Elemento` e `MatrizEsparsa`
- **Descrição:** Armazena valores não nulos em uma lista encadeada, economizando espaço.
- **Campos:**
  - `Elemento`: Guarda posição e valor de cada elemento não nulo.
  - `MatrizEsparsa`: Contém ponteiros para o início de cada linha.

### 3. Matriz Identidade
- **Estrutura:** `Identidade`
- **Descrição:** Matriz que armazena elementos da diagonal principal e verifica se a matriz é identidade.

### 4. Matriz Tridimensional
- **Estrutura:** `int***`
- **Descrição:** Usa ponteiros para representar uma matriz tridimensional.

---

## Funcionalidades

Para cada tipo de matriz, o projeto inclui:

- **Criação:** Inicializa a matriz com as dimensões especificadas.
- **Preenchimento:** Permite ao usuário inserir valores não nulos ou da diagonal.
- **Impressão:** Exibe a matriz completa, preenchendo com zeros onde necessário.
- **Consulta:** Acessa valores em posições específicas.
- **Funções adicionais para Matrizes Especiais:**
  - **Matriz Esparsa:** Cálculo do somatório de uma linha e percentual de elementos não nulos.
  - **Matriz Identidade:** Exibe elementos que violam a condição de identidade.

---

## Pré-requisitos

- GCC (GNU Compiler Collection)
- Ambiente de desenvolvimento C (Visual Studio Code, Code::Blocks, etc.)

---

## Instalação

Clone o repositório para seu ambiente local:

```bash
git clone https://github.com/ODiogorocha/Estrutura-de-dados.git
cd matrizes-especiais
```


## Uso

Cada programa solicitará os valores e a ordem da matriz específica. Abaixo estão as instruções básicas:

1. **Matriz Diagonal:** Informe a ordem e os valores da diagonal.
2. **Matriz Esparsa:** Informe dimensões e valores não nulos.
3. **Matriz Identidade:** Informe a ordem e os valores da matriz.
4. **Matriz 3D:** Informe dimensões e valores para cada posição.

---

## Exemplos

### Exemplo de Uso para Matriz Diagonal
Entrada:
```
Ordem da matriz: 3
Valores da diagonal: 1 2 3
```
Saída:
```
1 0 0
0 2 0
0 0 3
```

---

## Estrutura de Arquivos

```plaintext
.
├── exercicio1.c     # Código para a matriz diagonal
├── exercicio2.c      # Código para a matriz esparsa
├── exercicio3.c   # Código para a matriz identidade
├── exercicio4.c           # Código para a matriz tridimensional
├── documentacao.md             # Documentação do projeto
```

---

## Autores

- [Diogo](https://github.com/ODiogorocha)

---

## Licença

Este projeto está licenciado sob a Licença MIT. Consulte o arquivo LICENSE para mais informações.
```

Esse `README.md` serve como um guia completo para o repositório, facilitando o entendimento e o uso do projeto.