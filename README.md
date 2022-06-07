# tic-tac-toe

- ### Tipos do jogo
  - Jogo entre 2 jogadores humanos
  - Jogo entre um humano e um jogador automático
- ### Gestão de informação
  - O jogo deve ser mantido num array dinâmico
  - A sucessão de jogadas realizadas deve ser mantida numa lista ligada simples.
    - Informação correspondente a jogada, respetivo jogador e board.
  - Antes de cada jogada, um jogador poderá solicitar a visualização das K jogadas anteriores
    (K varia entre 1 e 10, sendo o valor indicado pelo jogador que efetua o pedido).
    - Deve apenas mostrar as jogadas efetuadas (por exemplo, o jogador X efetuou a jogada Y),
      não sendo necessário mostrar os tabuleiros completos.
- ### Interrupção do Jogo
  - O programa deve guardar num ficheiro binário, com nome “jogo.bin”, a lista das jogadas que
    está armazenada na lista ligada e outra informação essencial para retomar o jogo mais tarde.
  - Quando a aplicação é reiniciada deverá ser verificada a existência do ficheiro e, caso exista, o utilizador deverá ser questionado sobre
    se pretende continuar o jogo anterior.
- ### Exportação para Ficheiro
  - No final do jogo, a sucessão completa das jogadas realizadas deve ser exportada para um
    ficheiro de texto, cujo nome é pedido ao utilizador
    - Neste ficheiro ficará informação detalhada e completa das jogadas que foram efetuadas
    - O ficheiro deve ser criado e escrito apenas no final do jogo, com base na informação armazenada na lista ligada que mantém
      as jogadas realizadas.



# Relatório
: 