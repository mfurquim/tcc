%title: Big Points: Uma Análise Baseada na Teoria dos Jogos
%author: Mateus Medeiros Furquim Mendonça
%date: 2016-07-10






-> Big Points <-
================

-> Uma Análise Baseada na Teoria dos Jogos <-
---------------------------------------------






-> Autor: Mateus Medeiros Furquim Mendonça

-> Orientador: Prof. Dr. Edson Alves da Costa Júnior

--------------------------------------------------------------------------------


-> Introdução <-
================

-> Problema <-
--------------

^
* Encontrar balanceamento de jogos para _design_
    ^
    - Jogos Eletrônicos
    ^    
    - Jogos de Tabuleiro


--------------------------------------------------------------------------------

-> Introdução <-
================

-> Objetivos <-
---------------

^
* Realizar uma análise _Minimax_
^
* Verificar balanceamento do jogo _Big Points_
^
* Fornecer _insights_ para balanceamento em estruturas mais complexas

--------------------------------------------------------------------------------

-> Jogo Nim <-
==============

-> Regras Simplificadas <-
--------------------------

^
* Dois montes, com dois palitos em cada monte
^
* Escolhe um monte e retira quantos palitos quiser
^
* Jogador que retirar o último palito do jogo perde

--------------------------------------------------------------------------------

-> Jogo Nim <-
==============

-> Forma Extensa do Jogo Nim <-
-------------------------------

^
->                                                ┌───────┐                     <-
->    J₁ →                                       A│ ┃┃ ┃┃ │                     <-
->                                                └───────┘                     <-
^
->                                    ┌───────────────┴─────────────┐           <-
->                                ┌───────┐                     ┌───────┐       <-
->    J₂ →                       B│  ┃ ┃┃ │                    C│ ━━ ┃┃ │       <-
->                                └───────┘                     └───────┘       <-
^
->                   ┌────────────────┼──────────┐             ┌────┴─────┐     <-
->               ┌───────┐        ┌───────┐  ┌───────┐     ┌───────┐  ┌───────┐ <-
->    J₁ →      D│ ━━ ┃┃ │       E│  ┃ ┃  │ F│  ┃ ━━ │    G│ ━━ ┃  │ H│ ━━ ━━ │ <-
->               └───────┘        └───────┘  └───────┘     └───────┘  └───────┘ <-
^
->              ┌────┴─────┐          │          │             │                <-
->          ┌───────┐  ┌───────┐  ┌───────┐  ┌───────┐     ┌───────┐            <-
->    J₂ → I│ ━━ ┃  │ J│ ━━ ━━ │ K│  ┃ ━━ │ L│ ━━ ━━ │    M│ ━━ ━━ │            <-
->          └───────┘  └───────┘  └───────┘  └───────┘     └───────┘            <-
^
->              │                     │                                         <-
->          ┌───────┐             ┌───────┐                                     <-
->    J₁ → N│ ━━ ━━ │            O│ ━━ ━━ │                                     <-
->          └───────┘             └───────┘                                     <-
^
->            (J₁)       (J₂)       (J₁)       (J₂)          (J₂)       (J₁)    <-

--------------------------------------------------------------------------------

-> Jogo Nim <-
==============

-> Estratégias Puras (σi) do Jogador 1 para o jogo Nim <-
---------------------------------------------------------

-> ────────────────────────────────── <-
-> Estratégia   1º Turno   2º Turno   <-
-> ────────────────────────────────── <-
^
->     σ₁         (A,B)      (D,I)    <-
^
->     σ₂         (A,B)      (D,J)    <-
^
->     σ₃         (A,C)       ───     <-
-> ────────────────────────────────── <-

--------------------------------------------------------------------------------

-> Jogo Nim <-
==============

-> Estratégias Puras (τj) do Jogador 2 para o jogo Nim <-
---------------------------------------------------------

-> ────────────────────── <-
-> Estratégia   1º Turno  <-
-> ────────────────────── <-
^
->     τ₁         (B,D)   <-
->                (C,G)   <-
^
->                        <-
->     τ₂         (B,E)   <-
->                (C,G)   <-
^
->                        <-
->     τ₃         (B,F)   <-
->                (C,G)   <-
^
->                        <-
->     τ₄         (B,D)   <-
->                (C,H)   <-
^
->                        <-
->     τ₅         (B,E)   <-
->                (C,H)   <-
^
->                        <-
->     τ₆         (B,F)   <-
->                (C,H)   <-
-> ────────────────────── <-

--------------------------------------------------------------------------------

-> Jogo Nim <-
==============

-> Diferentes Jogos dependendo das estratégias σi e τj <-
---------------------------------------------------------

^
-> σ₁ e τ₁ resultam no jogo A→B→D→I→N <-
^
-> σ₂ e τ₁ resultam no jogo A→B→D→J   <-
^
-> σ₃ e τ₂ resultam no jogo A→C→G→M   <-

--------------------------------------------------------------------------------

-> Jogo Nim <-
==============

-> Forma Normal para o jogo Nim <-
----------------------------------

-> ─────────────────────────── <-
->                 *J₂*          <-
->          _τ₁_ _τ₂_ _τ₃_ _τ₄_ _τ₅_ _τ₆_  <-
-> ─────────────────────────── <-
->      _σ₁_   N  O  L  N  O  L   <-
->  *J₁*  _σ₂_   J  O  L  J  O  L   <-
->      _σ₃_   M  M  M  H  H  H   <-
-> ─────────────────────────── <-

--------------------------------------------------------------------------------

-> Jogo Nim <-
==============

-> Matriz de Ganho <-
---------------------

-> ─────────────────────────── <-
->                 *J₂*          <-
->          _τ₁_ _τ₂_ _τ₃_ _τ₄_ _τ₅_ _τ₆_  <-
-> ─────────────────────────── <-
->      _σ₁_   1  1 -1  1  1 -1   <-
->  *J₁*  _σ₂_  -1  1 -1 -1  1 -1   <-
->      _σ₃_  -1 -1 -1  1  1  1   <-
-> ─────────────────────────── <-


--------------------------------------------------------------------------------

-> Jogo Nim <-
==============

-> Análise Minimax <-
---------------------

-> ─────────────────────────────── <-
->                 *J₂*              <-
->          _τ₁_ _τ₂_ _τ₃_ _τ₄_ _τ₅_ _τ₆_ _min_  <-
-> ─────────────────────────────── <-
->     _σ₁_    1  1 -1  1  1 -1 *-1*   <-
->  *J₁* _σ₂_   -1  1 -1 -1  1 -1 *-1*   <-
->     _σ₃_   -1 -1 -1  1  1  1 *-1*   <-
^
->     _max_   *1*  *1* *-1*  *1*  *1*  *1*      <-
-> ─────────────────────────────── <-


--------------------------------------------------------------------------------

-> Programação Dinâmica <-
==========================

-> Conceito <-
--------------

^
- *Técnica* de programação
^
- Reduz o *tempo* de processamento quando há *estados repetidos*
^
- Alcança isso através da *memorização*

--------------------------------------------------------------------------------

-> Programação Dinâmica <-
==========================

-> Comparação: Código <-
------------------------

 1|int fibonacci(int n)
 2|{
 3|    int fib_number = 0;
 4|    
 5|    if (n<=2) {
 6|        fib_number = 1;
 7|    }
 8|    else {
 9|        fib_number = fibonacci(n-1) + fibonacci(n-2);
10|    }
11|
12|    return fib_number;
13|}

--------------------------------------------------------------------------------

-> Programação Dinâmica <-
==========================

-> Árvore de Fibonacci <-
-------------------------

->                         ┏━━━━┓                    <-
->                         ┃ Fₙ ┃                    <-
->                         ┗━━━━┛                    <-
->                 ┌─────────┴──────────┐            <-
->             ┏━━━━━━┓             ┌──────┐         <-
->             ┃ Fₙ₋₁ ┃             │ Fₙ₋₂ │         <-
->             ┗━━━━━━┛             └──────┘         <-
->          ┌──────┴─────┐         ┌────┴────┐       <-
->      ┏━━━━━━┓     ┌──────┐  ┌──────┐  ┌──────┐    <-
->      ┃ Fₙ₋₂ ┃     │ Fₙ₋₃ │  │ Fₙ₋₃ │  │ Fₙ₋₄ │    <-
->      ┗━━━━━━┛     └──────┘  └──────┘  └──────┘    <-
->     ┌────┴────┐                                   <-
-> ┏━━━━━━┓  ┏━━━━━━┓                                <-
-> ┃ Fₙ₋₃ ┃  ┃ Fₙ₋₄ ┃                                <-
-> ┗━━━━━━┛  ┗━━━━━━┛                                <-

--------------------------------------------------------------------------------

-> Programação Dinâmica <-
==========================

-> Comparação: Código <-
------------------------

 1|std::map<int,int> memoization;
 2|
 3|int fibonacci(int n)
 4|{
 5|    auto it = memoization.find(n)
 6|    if (it != memoization.end()) {
 7|        return memoization.at(n);
 8|    }
 9|
10|    int fib_number = 0;
11|    
12|    if (n<=2) {
13|        fib_number = 1;
14|    }
15|    else {
16|        fib_number = fibonacci(n-1) + fibonacci(n-2);
17|    }
18|    
19|    memoization[n] = fib_number;
20|
21|    return fib_number;
22|}

--------------------------------------------------------------------------------

-> Programação Dinâmica <-
==========================

-> Comparação: Tabela <-
------------------------

-> ────────────────────────────────── <-
->  _n_-ésimo     Tempo (microsegundo)  <-
->            *Recursivo*  *Memorização*  <-
-> ────────────────────────────────── <-
->      1        1.0        0.9      <-
->      2        0.6        5.2      <-
->      3        0.2        2.2      <-
->      4        0.4        2.0      <-
->      5        0.4        2.1      <-
->      6        0.6        2.5      <-
->      7        0.8        2.4      <-
->      8        1.0        2.5      <-
->      9        1.2        2.4      <-
->     10        2.0        2.4      <-
->     11        2.4        2.4      <-
->     12        3.6        2.6      <-
->     13        5.5        2.8      <-
->     14        8.8        2.9      <-
->     15       14.0        2.7      <-
-> ────────────────────────────────── <-

--------------------------------------------------------------------------------

-> Regra do Jogo Big Points <-
==============================

-> Conteúdo <-
--------------

^
- 5 Peões
^
- 60 Discos
^
    - 10 Discos das cores: Vermelha, Verde, Azul, Amarela e roxa
^
    - 5 Discos das cores: Branca e Preta
^
- 1 Escada com 5 degraus
^


-> Organização <-
-----------------

^
- Retire um peão de cada cor comum e coloque ao lado da escada
^
- Embaralhe os discos restantes e forme uma fila
^
- Coloque os peões em uma ponta e a escada na ponta oposta
^

--------------------------------------------------------------------------------

-> Regra do Jogo Big Points <-
==============================

-> Mecânica <-
--------------

^
- Escolha o primeiro jogador
^
- Na sua vez, o jogador deve escolher uma cor de peão
^
- Mova aquele peão para o próximo disco da cor dele em direção à escada
^
    - Se não houver mais discos da sua cor na sua frente, mova-o para a escada
^
- Pegue o próximo disco disponível à frente ou atrás do peão
^
- Se tiver uma peça preta, pode utilizá-la para realizar uma segunda jogada
^
    - Esta jogada pode ser com qualquer cor e pode ser para trás
^
    - Após mover o peão, pegue um disco à frente ou atrás do peão
^
- Passe a vez para o próximo jogador
^
- O jogo termina quando todos os peões estiverem na escada
^


-> Pontuação <-
---------------

^
- A pontuação é igual à quantidade de discos de cada cor e multiplicado pelo seu valor
^
    - Os peões na escada indicam o valor das cores, de forma que o primeiro a chegar vale quatro, e o úlimo, zero
^
    - O branco vale o número de cores distintas (sem contar com o branco)
^
    - O preto vale zero pontos

--------------------------------------------------------------------------------

-> Análise do Jogo Big Points <-
================================

-> Quantidade de Partidas <-
----------------------------

^
-> P = (J-1)⎛Dt⎞⎛D1⎞⎛D2⎞⎛D3⎞⎛D4⎞⎛D5⎞⎛D6⎞                       <-
->          ⎝Nw⎠⎝Nk⎠⎝Nr⎠⎝Ng⎠⎝Nb⎠⎝Ny⎠⎝Np⎠                       <-

^
-> P = (5-1)⎛55⎞⎛50⎞⎛45⎞⎛36⎞⎛27⎞⎛18⎞⎛9⎞                        <-
->          ⎝5 ⎠⎝5 ⎠⎝9 ⎠⎝9 ⎠⎝9 ⎠⎝9 ⎠⎝9⎠                        <-

^
-> P = 560.483.776.167.774.018.942.304.261.616.685.408.000.000 <-

^
-> P = 5x10⁴¹                                                  <-

^
-> Quantidade de Estados <-
---------------------------

^
-> E = ∑ʰₙ₌₀𝑓ⁿ ≈ 341,    𝑓=4,  h=4  <-

^
-> E = ∑ʰₙ₌₀𝑓ⁿ ≈ 3x10⁷¹, 𝑓=20, h=55 <-


^
-> Para Resolver Todos as Partidas <-
-------------------------------------

^
-> T ≈ P⋅E ≈ 5x10⁴¹⋅3x10⁷¹ ≈ 1x10¹¹³ <-


--------------------------------------------------------------------------------

-> Análise do Jogo Big Points <-
================================

-> Quantidade de Estados <-
---------------------------

->      ┌───────┐                               <-
-> J₁ → │1221 00│                               <-
->      │00   00│                               <-
->      └───────┘                               <-
^      
->          ├─────────┬─────────┐               <-
->      ┌───────┐ ┌───────┐ ┌───────┐           <-
-> J₂ → │R021 00│ │1G01 00│ │0G21 00│           <-
->      │01   00│ │01   00│ │10   00│           <-
->      └───────┘ └───────┘ └───────┘           <-
^
->          ├───────────────────┐               <-
->      ┌───────┐           ┌───────┐           <-
-> J₁ → │100R 00│           │R0G0 00│           <-
->      │01   01│           │01   10│           <-
->      └───────┘           └───────┘           <-
^      
->          ├─────────┐         ├─────────┐     <-
->      ┌───────┐ ┌───────┐ ┌───────┐ ┌───────┐ <-
-> J₂ → │1001 10│ │100R 01│ │10G0 10│ │R020 01│ <-
->      │11   01│ │02   01│ │11   10│ │02   10│ <-
->      └───────┘ └───────┘ └───────┘ └───────┘ <-
^
->          │         │         │         │     <-
->      ┌───────┐ ┌───────┐ ┌───────┐ ┌───────┐ <-
-> J₁ → │1001 12│ │1001 21│ │1020 12│ │1020 21│ <-
->      │11   02│ │02   11│ │11   11│ │02   20│ <-
->      └───────┘ └───────┘ └───────┘ └───────┘ <-
^      
->        (1,0)     (2,1)     (1,1)     (2,0)   <-
       
--------------------------------------------------------------------------------

-> Estrutura de Armazenamento <-
================================

^
-> Tabuleiro <-
---------------

^
-> tabuleiro = nc⋅nd              <- 
^
-> tabuleiro = 5⋅4                <- 
^
-> tabuleiro = 20 bits            <- 

^
-> Peao <-
----------

^
-> peao = ⌈log₂(nd+1)⌉⋅nc         <- 
^
-> peao = ⌈log₂(4+1)⌉⋅5           <- 
^
-> peao = 3⋅5                     <- 
^
-> peao = 15 bits                 <- 

^
-> Escada <-
------------

^
-> escada = ⌈log₂(np)⌉⋅np       <- 
^
-> escada = ⌈log₂(5)⌉⋅5           <- 
^
-> escada = 15 bits               <- 

^
-> Jogadores <-
---------------

^
-> jogadores = ⌈log₂(nd+1)⌉⋅nc⋅nj <- 
^
-> jogadores = ⌈log₂(4+1)⌉⋅5⋅2    <- 
^
-> jogadores = 3⋅5⋅2              <- 
^
-> jogadores = 30 bits            <- 

^
-> Jogador Atual <-
-------------------

^
-> jogadores = ⌈log₂(2)⌉          <- 
^
-> tabuleiro = 1 bits             <- 

--------------------------------------------------------------------------------

-> Estrutura de Armazenamento <-
================================

-> Implementação <-
-------------------

 1|using namespace std;                                            
 2|                                                                
 3|using ll = unsigned long long;                                  
 4|                                                                
 5|struct State                                                    
 6|{                                                               
 7|    struct {                                                    
 8|        ll \_tabuleiro :20;                                      
 9|        ll \_peao :15;                                           
10|        ll \_escada :15;                                         
11|    };                                                          
12|                                                                
13|    struct {                                                    
14|        ll \_jogadores :30;                                      
15|        ll \_atual :1;                                           
16|    };                                                          
17|   State(int mtabuleiro = (1<<20)-1, int mpeao = 0, int mescada = 0,
18|       int mjogadores = 0, int matual = 0)    : \_tabuleiro(mtabuleiro),
19|       \_peao(mpeao), \_escada(mescada),    \_jogadores(mjogadores),
20|       \_atual(matual)
21|   {
22|   }

--------------------------------------------------------------------------------

-> Estrutura de Armazenamento <-
================================

-> Implementação <-
-------------------

1|
2|   int tabuleiro (int pos) const {
3|       return (\_tabuleiro & (1<<pos))>>pos;
4|   }
5|   
6|   void settabuleiro (int pos, int available) {
7|       \_tabuleiro = (\_tabuleiro & ~(1<<pos)) | ((available&1)<<pos);
8|   }

--------------------------------------------------------------------------------

-> Estrutura de Armazenamento <-
================================

-> Implementação <-
-------------------

 1|    int peao (int cor) const {
 2|        return (\_peao & (7<<(3\*cor)))>>(3\*cor);
 3|    }
 4|    
 5|    void setpeao (int cor, int pos) {
 6|        \_peao = (\_peao&~(7<<(3\*cor)))|((pos&7)<<(3\*cor));
 7|    }
 8|    
 9|    void movepeao (int cor) {
10|        setpeao(cor,peao(cor)+1);
11|    }

--------------------------------------------------------------------------------

-> Estrutura de Armazenamento <-
================================

-> Implementação <-
-------------------

1|    int escada (int cor) const {
2|        return (\_escada & (7<<(3\*cor)))>>(3\*cor);
3|    }
4|   
5|   void setescada (int cor, int pos) {
6|       \_escada = (\_escada&~(7<<(3\*cor)))|((pos&7)<<(3\*cor));
7|   }

--------------------------------------------------------------------------------

-> Estrutura de Armazenamento <-
================================

-> Implementação <-
-------------------

 1|   int jogador (int jogador, int cor) const {
 2|       return ((\_jogadores>>(15\*jogador)) & (7<<(3\*cor)))>>(3\*cor);
 3|   }
 4|   
 5|   void setjogador (int jogador, int cor, int qtd) {
 6|       \_jogadores = (\_jogadores & ~(7<<(3\*cor + 15\*jogador) ))
 7|           | ((qtd & 7) << (3\*cor + 15\*jogador));
 8|   }
 9|   
10|   void updatejogador (int player, int cor) {
11|       setjogador(player, cor, jogador(player, cor)+1);
12|   }

--------------------------------------------------------------------------------

-> Estrutura de Armazenamento <-
================================

-> Implementação <-
-------------------

1|   int atual () const {
2|       return \_atual;
3|   }
4|   
5|   void updateatual () {
6|       \_atual ^= 1;
7|   }

--------------------------------------------------------------------------------

-> Estrutura de Armazenamento <-
================================

-> Implementação <-
-------------------

1|   bool operator<(const struct State& s) const {
2|       if (\_tabuleiro != s.\_tabuleiro) return \_tabuleiro < s.\_tabuleiro;
3|       if (\_peao != s.\_peao) return \_peao < s.\_peao;
4|       if (\_escada != s.\_escada) return \_escada < s.\_escada;
5|       if (\_jogadores != s.\_jogadores) return \_jogadores < s.\_jogadores;
6|       return \_atual < s.\_atual;
7|   }

--------------------------------------------------------------------------------

-> Programação Dinâmica <-
==========================

-> Implementação <-
-------------------

 1|ii dp(map<struct State,ii>& dp\_states, struct Game game, struct State state)
 2|{
 3|    // If all pawns are in the stair
 4|    if (is\_pawns\_stair(game, state)) {
 5|        return calculate\_score(game, state);
 6|    }
 7|
 8|    auto it = dp\_states.find(state);
 9|    if (it != dp\_states.end()) {
10|        return dp\_states[state];
11|    }
12|
13|    vector<ii> results;
14|    for (short pawn = 0; pawn < game.num\_cores; pawn++) {
15|        struct Turn right(state.atual(), pawn, true);
16|        struct Turn left(state.atual(), pawn, false);
17|
18|        // DP após jogadas
19|        game\_res result = play(dp\_states, game, state, left);
20|        if (result.first) {
21|            results.push\_back(result.second);
22|       }
23|
24|       result = play(dp\_states, game, state, right);
25|       if (result.first) {
26|           results.push\_back(result.second);
27|       }
28|   }

--------------------------------------------------------------------------------

-> Minimax <-
=============

-> Implementação: Jogador 1 <-
------------------------------

 1|    auto p1\_order = (const ii& a, const ii& b){
 2|        if (a.first > a.second) {
 3|            if (b.first > b.second) {
 4|                return a.first > b.first ? true : false;
 5|            }
 6|            else {
 7|                return true;
 8|            }
 9|        }
10|        else if (a.first == a.second) {
11|            if (b.first > b.second) {
12|                return false;
13|            }
14|            else if (b.first == b.second) {
15|                return a.first > b.first ? true : false;
16|            }
17|            else {
18|                return true;
19|            }
20|        }
21|        else {
22|            if (b.first >= b.second) {
23|                return false;
24|            }
25|            else {
26|                return a.second < b.second ? true : false;
27|            }
28|        }
29|      };

--------------------------------------------------------------------------------

-> Minimax <-
=============

-> Implementação: Jogador 2 <-
------------------------------

30|  
31|      auto p2\_order = (const ii& a, const ii& b){
32|          if (a.second > a.first) {
33|              if (b.second > b.first) {
34|                  return a.second > b.second ? true : false;
35|              }
36|              else {
37|                  return true;
38|              }
39|          }
40|          else if (a.second == a.first) {
41|              if (b.second > b.first) {
42|                  return false;
43|              }
44|              else if (b.second == b.first) {
45|                  return a.second > b.second ? true : false;
46|              }
47|              else {
48|                  return true;
49|              }
50|          }
51|          else {
52|              if (b.second >= b.first) {
53|                  return false;
54|              }
55|              else {
56|                  return a.first < b.first ? true : false;
57|              }
58|          }
59|      };

--------------------------------------------------------------------------------

-> Resultados <-
================

