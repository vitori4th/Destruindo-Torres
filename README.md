# Destruindo-Torres

## Sobre o programa

A ideia é:

Tower Attack 3000 é um jogo de “tower attack” em que você vai atacar torres que o inimigo
está conjurando para te atacar. O jogo se dá em turnos, e o número de turnos é definido no
início do jogo. No campo de batalha o inimigo pode conjurar até 5000 torres. Cada turno é
composto das seguintes ações:
1. Se couber no campo de batalha, o inimigo conjura uma nova torre. A quantidade de
pontos de vida (hit points - hp) da torre é sorteado aleatóriamente entre 1 e 20. Cada
torre gerada tem um id sequencial, ou seja, a primeira torre tem id 0, a segunda tem
id 1 e assim por diante.
2. O Jogador pode atacar uma torre, tirando 10 pontos de vida dela. De a torre ficar
com 0 ou menos de vida ela cai e sai do jogo.
3. As torres que permanecem vivas no final do turno atacam o jogador, cada torre
causa 1 de dano.

O objetivo do jogador é minimizar o seu dano. Para isso, uma estratégia interessante é
atacar sempre a torre com a menor quantidade de vida, se houverem duas torres com a
mesma quantidade de vida, o jogador decidiu que vai atacar aquela a mais tempo no jogo,
ou seja, aquela com id menor.
## Porque?

Este programa foi proposto pelo professor Hokama durante a aula de algoritmo e estrutura de dados, do curso Sistemas da Informação, para praticar a implementação de fila de prioridade. 

## Algumas observações sobre o programa
1 - Foi dado, pelo professor, um código com a função main que poderá ser usada.
2 - Será preciso implementar a fila deprioridades que vai guardar as torres e indicar qual será a próxima a ser atacada.

## Começando

### Pré requisitos

Para rodar esse programa você precisa de um compilador C.

### Instalando

**Clonando o Repositório**

```
$ git clone git@github.com:vitori4th/Destruindo-Torres.git

$ cd Destruindo-Torres
```

### Rodando

Com o compilador instalado, você pode rodar o programa:

```
Pressionando f11, para salvar e compilar o código.

```

## Feito com

- C

## Contribuindo

Ficarei feliz em receber qualquer feedback sobre alguma coisa que eu tenha que refazer. Se tiver alguma dúvida...

Você também pode me encontrar em: vitoriathdasilva@gmail.com

Obrigada!
