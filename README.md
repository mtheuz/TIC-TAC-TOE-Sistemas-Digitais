
<div align="center">
<img src="https://github.com/mtheuz/Problema-1--Sistemas-Digitais/assets/77650601/6b86920f-36a2-4e48-81a5-c92a8f31be48">
</div>

#  Como rodar o projeto

1. Faça o clone do repositório
2. 

# 📖 Introdução

Os jogos eletrônicos desempenham um papel crucial na convergência entre tecnologia e entretenimento, impulsionando avanços em diversos setores. Mesmo em sua forma mais básica, como o jogo da velha, eles oferecem uma oportunidade cativante para explorar estratégias e desfrutar de momentos de diversão. Este projeto tem como objetivo desenvolver uma versão eletrônica do jogo da velha, utilizando a placa de desenvolvimento De1-SoC e seus periféricos. Ao integrar o movimento dos quadrantes do tabuleiro através de um mouse, o projeto ilustra de forma prática como a tecnologia pode ser aplicada em um ambiente familiar, destacando a versatilidade das plataformas de desenvolvimento e o potencial de inovação oferecido pela tecnologia moderna.

# 🎯 Requistos do sistema
- [x] Elaboração do código-fonte em C
- [x] O sistema só poderá utilizar os componentes disponíveis na placa.

# 📝 Descrição das ferramentas utilizadas 

- ### Nano:
    O GNU Nano é um editor de texto minimalista, integrado de forma nativa em sistemas operacionais Linux e operado diretamente no terminal do sistema. Este software foi um dos utilitários de edição de texto empregados durante a codificação do projeto.
    
- ### Linguagem C:
    Foi utilizado linguagem C para codificar o projeto devido à sua capacidade de ser executada em computadores com recursos limitados, que não suportam softwares mais robustos. Além disso, sua proximidade com a arquitetura de máquina e a disponibilidade de bibliotecas-padrão facilitam a interação com o sistema operacional, tornando mais eficiente a manipulação dos drivers dos dispositivos utilizados no sistema. 
    
- ### GNU
    O GNU Compiler Collection (GCC) é uma ferramenta de compilação de código aberto amplamente utilizada, oferecida gratuitamente para diversas linguagens de programação. Foi instalado e empregado no sistema operacional da plataforma De1-SoC para compilar os códigos escritos em C pelo grupo de desenvolvimento.

- ### Makefile 

    Um arquivo Makefile é um script especial usado em ambientes de desenvolvimento de software para automatizar o processo de compilação, vinculação e execução de programas. Ele define as regras e dependências entre os arquivos do seu projeto, facilitando a construção e a manutenção do software.

- ### SSH

    O SSH (Secure Shell) é um protocolo de rede usado para comunicação segura e controle remoto de dispositivos através de uma conexão criptografada. Ele é amplamente utilizado para acessar servidores e dispositivos remotos pela internet, garantindo a proteção das informações transmitidas por meio de criptografia forte.
# Kit de Desenvolvimento De1-Soc
A Plataforma De1-SoC é uma solução de hardware robusta que integra os poderosos núcleos Cortex-A9 com a flexibilidade de um FPGA. Isso permite aos usuários criar sistemas altamente adaptáveis, combinando desempenho de processamento com capacidade de personalização. Além disso, o SoC inclui um sistema de processador (HPS) baseado em ARM, conectado ao FPGA, facilitando a comunicação eficiente entre o processador e a lógica programável. Com recursos como memória DDR3, capacidades de vídeo e áudio e conectividade Ethernet, a placa DE1 SoC é ideal para uma variedade de aplicações.

</br>
<div align="center">
<img src="https://github.com/mtheuz/Problema-1--Sistemas-Digitais/assets/77650601/18d11607-03e9-4068-8bd0-31e46bd1895c" width="700">
</div>
</br>

O diagrama de blocos da placa mostra como os componentes estão interconectados. Todas as conexões são feitas por meio do dispositivo Cyclone V SoC FPGA para oferecer aos usuários a maior flexibilidade possível. Isso significa que os usuários têm a liberdade de configurar o FPGA de acordo com suas necessidades específicas, permitindo a implementação de uma ampla variedade de designs de sistemas.
</br>
<div align="center">
<img src="https://github.com/mtheuz/Problema-1--Sistemas-Digitais/assets/77650601/b623ebde-9feb-4b2f-a57f-4e8153df9faf" width="700">
</div>
</br>

# 🖥️ Arquitetura do processador Cortex-A9
O processador Cortex-A9 800MHz MPCore é um design de CPU baseado na arquitetura ARMv7 , seguindo a Instruction Set Architecture (ISA) específico dessa arquitetura. Com um clock de 800MHz, este processador é dual-core, significando que possui dois núcleos de CPU idênticos. Cada núcleo possui sua própria hierarquia de cache, incluindo caches L1 (instrução e dados) e um cache L2 compartilhado entre os núcleos. Além disso, o Cortex-A9 é projetado com uma pipeline moderadamente profunda, aproveitando unidades funcionais especializadas, como unidades de execução aritmética e lógica, unidades de acesso à memória e unidades de controle de fluxo, para otimizar a execução de instruções e maximizar o desempenho geral da CPU.

# ⛏️ Construção do tabuleiro
###  ➡️ Montagem do tabuleiro
O jogo da velha é configurado usando uma matriz de caracteres de dimensão 3x3. Cada célula na matriz foi designada com um número de 1 a 9. Essa técnica foi adotada para simplificar a percepção visual do jogador, permitindo uma identificação clara da posição das células.

<div align="center">
<img src="https://github.com/mtheuz/Problema-1--Sistemas-Digitais/assets/77650601/7f569e6f-136f-4912-87d9-d359715b5ca2" width="400">
</div>

### ➡️ Lógica do vencedor
Para determinar o vencedor, o código verifica as linhas, colunas e diagonais da matriz do jogo. Se encontrar um padrão de elementos iguais em uma linha, coluna ou diagonal, ele determina o vencedor de acordo com o jogador atual, caso o código não determine um vencedor o jogo é declarado em empate.
</br>
<div align="center">
<img src="https://github.com/mtheuz/Problema-1--Sistemas-Digitais/assets/77650601/d29b87b2-de34-4758-8d1b-2e6680184f3c" width="400">
</div>

### ➡️ Delimimitação do tabuleiro
Para garantir a precisão do funcionamento do tabuleiro, foi definida uma área delimitada para cada célula. Essa medida possibilita identificar, com base nas coordenadas x e y, qual célula está sendo selecionada em um dado momento.
</br>
<div align="center">
<img src="https://github.com/mtheuz/Problema-1--Sistemas-Digitais/assets/77650601/fe71d98d-cce4-434b-aab5-1b8621ddf74c" width="400">
</div>
</br>

**Delimitação das celulas:**
1. Célula (1,1): X( 0 á 100) e Y(0 á 100)
2. Célula (1,2): X( 101 á 200) e Y(0 á 100)
3. Célula (1,3): X( 201 á 300) e Y(0 á 100)
4. Célula (2,1): X( 0 á 100) e Y(101 á 200)
5. Célula (2,2): X( 101 á 200) e Y(101 á 200)
6. Célula (2,3): X( 201 á 300) e Y(101 á 200)
7. Célula (3,1): X( 0 á 100) e Y(201 á 300)
8. Célula (3,2): X( 101 á 200) e Y(201 á 300)
9. Célula (3,3): X( 201 á 300) e Y(201 á 300)

# 🎮 Interface de controle

### ➡️ Portas USB host
A placa possui duas portas USB tipo A 2.0, acompanhadas por um par de controladores que garantem seu funcionamento correto.

O controlador principal é o SMSC USB3300, um componente vital que gerencia o fluxo de dados dentro das portas USB. Ele é responsável por garantir a comunicação eficiente entre os dispositivos conectados e o sistema operacional da placa. Este controlador é conectado a um segundo componente, o controlador de hub USB2512B da SMSC, que amplia a capacidade de conexão, permitindo que mais dispositivos sejam conectados à placa.

O SMSC USB3300 é apresentado em um pacote QFN de 32 pinos, uma forma de encapsulamento comum em componentes eletrônicos. Ele é capaz de se comunicar com o controlador USB 2.0 presente no HPS (Sistema de Processador Híbrido), uma parte essencial do hardware da placa. Essa comunicação é feita através da Interface de Pino Baixo UTMI+ (ULPI), uma tecnologia que facilita a transmissão de dados de alta velocidade entre dispositivos USB.

Uma característica importante do SMSC USB3300 é sua capacidade de operar no modo Host. Isso significa que o dispositivo pode assumir o controle da comunicação USB, em vez de apenas responder a comandos de dispositivos conectados. Essa funcionalidade é ativada ao conectar o pino de identificação (ID) do USB3300 ao terra, indicando que ele deve operar como o principal controlador USB. Quando em modo Host, o dispositivo é alimentado pelas duas portas USB tipo A, garantindo seu funcionamento mesmo em condições de uso intensivo.

<div align="center">
<img src="https://github.com/mtheuz/Problema-1--Sistemas-Digitais/assets/77650601/900aa8d2-06c3-4685-97e1-8ab14dba6864" width="800">
</div>

### ➡️ Captura dos dados do mouse

O arquivo `/dev/input/mice` desempenha um papel crucial no registro de eventos do mouse no ambiente Linux. Funcionando como uma interface direta, ele permite que os programas acessem os dados brutos gerados pelos movimentos e cliques do mouse, sem precisar lidar diretamente com os drivers de dispositivo. Quando um usuário move o mouse ou clica em um botão, essas ações são traduzidas em dados brutos pelo driver do mouse e registradas na fila de eventos do sistema operacional. O arquivo `/dev/input/mice` fornece acesso direto a esses eventos. Para interagir com o arquivo `/dev/input/mice`, são utilizadas as funções `open()` e `read()`. Os dados lidos são armazenados em um vetor como bytes, onde cada byte representa um evento de mouse. O primeiro byte corresponde ao evento de clique do mouse, o segundo byte representa o deslocamento no eixo x, e o terceiro byte representa o deslocamento no eixo y.


### ➡️Função do mouse 
O mouse desempenha um papel central no jogo da velha, permitindo que os jogadores naveguem pelo tabuleiro e selecionem quadrantes de interesse através de cliques. Ele opera com movimentos relativos, representando mudanças nas coordenadas x e y em um plano cartesiano (R2). A lógica subjacente a esses movimentos é baseada na contínua alteração das coordenadas (x, y) à medida que o mouse é deslocado. Os dados relativos a esses movimentos não são transmitidos imediatamente, mas sim gradualmente, refletindo o deslocamento completo realizado.

### ➡️ Controle do jogos por chaves HH

No sistema, duas chaves HH do kit DE1-SoC foi usada para permitir que o usuário reinicie o jogo e finalize o jogo. Para ler os valores digitados nessas chaves, os recursos disponíveis na placa para o sistema operacional foram utilizados. A biblioteca intelfpgaup oferece acesso aos drivers dos dispositivos nativos da placa, com os cabeçalhos das funções disponibilizadas e documentadas em arquivos de extensão ".h". Para incluir essa biblioteca, responsavel pelo controle das chaves foi colocado `#include <intelfpgaup/SW.h>` no início do código. As chaves são ativadas por meio de nível lógico alto.

Funções das chaves:
- **SW0:** Iniciar o jogo
- **SW1:** Finalizar o jogo

#  📟 Interface do sistema

No modo texto do Linux, o jogo da velha é exibido diretamente no terminal, permitindo que os jogadores interajam com ele através do mouse e das chaves HH. O tabuleiro é representado graficamente com caracteres ASCII simples, e os jogadores selecionam as posições desejadas através mouse. O jogo continua até que um jogador vença ou ocorra um empate, com mensagens indicativas exibidas no terminal para informar o resultado. Essa abordagem oferece uma forma simples e acessível de desfrutar do jogo da velha em sistemas Linux, sem a necessidade de interfaces gráficas complexas. A figura abaixo representa a exibição do sitema no terminal.
### output
```text
1 | 2 | 3
---------
4 | 5 | 6
---------
7 | 8 | 9

============================================
Rodada Atual: 1
Se deseja realizar a jogada no quadrante atual clique com o botão esquerdo do mouse
O quadrante que o jogador está selecionando é: 5
```


# 🕹️ Funcionamento do jogo

Para iniciar o jogo, é necessário colocar a chave SW0 em nível lógico alto. Se a chave estiver ativada, o tabuleiro será automaticamente gerado. Com o tabuleiro pronto, o jogo pode ser iniciado. O primeiro jogador realiza sua jogada e, após a confirmação com o click no botão direito do mouse, o caractere "X" é inserido na célula escolhida. Em seguida, é a vez do segundo jogador, representado por "O", realizar sua jogada. Esse padrão de alternância continua até que o número máximo de jogadas (n=9) seja alcançado. Ao atingir esse limite, é feita uma verificação para determinar se há um vencedor ou se o jogo termina em empate, sendo o resultado exibido no console. A qualquer momento durante o jogo, os jogadores podem optar por encerrá-lo, colocando a chave SW1 em nível lógico alto. 

1. Inicio do jogo, acionando a chave SW0.
```text
0 | 1 | 2
---------
3 | 4 | 5
---------
6 | 7 | 8

============================================
Rodada Atual: 1
Se deseja realizar a jogada no quadrante atual clique com o botão esquerdo do mouse
O quadrante que o jogador está selecionando é: 1
```


2. Após um jogador efeturar uma jogada.
```text
X | 1 | 2
---------
3 | 4 | 5
---------
6 | 7 | 8

============================================
Rodada Atual: 2
Se deseja realizar a jogada no quadrante atual clique com o botão esquerdo do mouse
O quadrante que o jogador está selecionando é: 0
Linha 1, Coluna 1
Jogada realiazda com sucesso
```

3. Caso for feito uma jogada em um célula já ocupada.
```text
X | 2 | 3
---------
4 | 5 | 6
---------
7 | 8 | 9

============================================
Rodada Atual: 2
Se deseja realizar a jogada no quadrante atual clique com o botão esquerdo do mouse
O quadrante que o jogador está selecionando é: 0
Linha 1, Coluna 1
O quadrante já está ocupado, tente realizar sua jogada em um quadrante vazio
```

4. Caso um dos jogadores vença.
```text
X | X | O
---------
O | X | O
---------
X | O | X

============================================
Jogador 1 foi o vencedor!
```
5. Caso de empate.
```text
O | X | O
---------
O | X | X
---------
X | O | X

============================================
O jogo terminou em empate!
```
6. Se o jogo for encerrado, ativando a chave SW1.
```text
===========Sistema finalizado===========
root@de1soclinux:/home/aluno/TEC499/TP02/G04

```
- Desse modo o fluxograma fica dessa maneira:
<div align="center">
<img src="https://github.com/mtheuz/Problema-1--Sistemas-Digitais/assets/77650601/4c9f96d7-9ac9-4a26-b9ec-2024be71ad49" width="800">
</div>
<div align="center">
<img src="https://github.com/mtheuz/Problema-1--Sistemas-Digitais/assets/77650601/71997eb1-7eeb-4404-9a3b-2218af44eb94" width="800">
</div>
<div align="center">
<img src="https://github.com/mtheuz/Problema-1--Sistemas-Digitais/assets/77650601/42aac2a0-d0b1-45d9-b2a8-9336b41dac2c" width="800">
</div>

# Autores

- Matheus Mota Santos 
- Pedro Henrique Araujo
- Dermeval Neves de Oliveira Filho