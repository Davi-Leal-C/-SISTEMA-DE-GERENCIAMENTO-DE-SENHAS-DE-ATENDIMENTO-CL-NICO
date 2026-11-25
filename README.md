
#  Sistema de Controle de Senhas - Tia Karla Soluções

Um sistema simples desenvolvido em linguagem **C** para o gerenciamento de filas de atendimento utilizando a estrutura de dados **Fila (FIFO - *First In, First Out*)** e modularização de código.

##  Funcionalidades

O sistema conta com um menu interativo no terminal que permite:
* **Emitir senhas** divididas em três categorias:
  *  **Urgente (`U`)**
  *  **Preferencial (`P`)**
  *  **Normal (`N`)**
* **Chamar a próxima senha** seguindo a regra de prioridade (`Urgente` $\rightarrow$ `Preferencial` $\rightarrow$ `Normal`).
* **Consultar filas** para visualizar todas as senhas que ainda aguardam atendimento.
* **Mostrar quantidade** de pessoas na espera por categoria e o total geral.

##  Estrutura do Projeto

O código foi modularizado em três arquivos principais para facilitar a organização e manutenção:

```text
├── main.c      # Fluxo principal e menu de interação com o usuário
├── fila.h      # Arquivo de cabeçalho (struct Fila, constantes e protótipos)
└── fila.c      # Implementação das regras de negócio e manipulação das filas
```

##  Como compilar e executar

Certifique-se de ter um compilador C instalado em sua máquina (como o **GCC**).

1. **Clone este repositório** (ou baixe os arquivos para uma mesma pasta):
   ```bash
   git clone https://github.com/seu-usuario/nome-do-repositorio.git
   cd nome-do-repositorio
   ```

2. **Compile o projeto** unindo os arquivos `.c`:
   ```bash
   gcc main.c fila.c -o sistema_senhas
   ```

3. **Execute o programa**:
   * **Linux / macOS:**
     ```bash
     ./sistema_senhas
     ```
   * **Windows:**
     ```bash
     sistema_senhas.exe
     ```

## 🛠️ Tecnologias Utilizadas

* Linguagem **C**
* Biblioteca padrão (`stdio.h`, `stdlib.h`, `locale.h`)
