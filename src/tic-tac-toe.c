    #include <stdio.h>
    #include <stdlib.h>
    #include <unistd.h>
    #include <fcntl.h>
    #include <intelfpgaup/SW.h>
    #include <stdint.h>
    
    // Verifica se houve um vencedor e qual dos jogadores que foi e tambem verifica se ocorreu um empate
    char verificar_vencedor (char matriz[3][3]){
        int i = 0;
        int j = 0;
        char vencedor = ' ';
        
        // Verifica linhas e colunas
        for (i; i < 3; i++) {
            if ((matriz[i][0] == matriz[i][1] && matriz[i][1] == matriz[i][2])) {
                vencedor = matriz[i][0];
            }
            if ((matriz[0][i] == matriz[1][i] && matriz[1][i] == matriz[2][i])){
                 vencedor = matriz[0][i];
            }
        }
    
        // Verifica diagonais
        if ((matriz[0][0] == matriz[1][1] && matriz[1][1] == matriz[2][2]) || (matriz[0][2] == matriz[1][1] && matriz[1][1] == matriz[2][0])) {
            vencedor = matriz[1][1];
        }
        return vencedor;
        
    }
    
    // Imprimindo o tabuleiro no console
    void imprimir_tabuleiro (char matriz[3][3]){
        int i = 0;
        int j = 0;
        for (i; i < 3; i++)
        {
            for (j; j < 3; j++)
            {
                printf("%c", matriz[i][j]);
                if (j != 2)
                {
                    printf (" | ");
                }
            }
            j = 0;
            if (i != 2){
                printf("\n---------\n");
            }
        }
        printf("\n\n======================================\n");
    }
    // Retorna o quadrante atual que o jogador esta selecionando
    int quadrante_atual(int coordenada_x, int coordenada_y) {
        // Definindo o tamanho de cada quadrante e quantas linhas e colunas tem o tabuleiro
        int tamanho_quadrante = 100; 
        int linhas = 3; 
        int colunas = 3; 
        
        // Calcula o número do quadrante atual
        int quadrantes_por_linha = 300 / tamanho_quadrante;
        int quadrantes_na_coluna = (coordenada_y -1) / tamanho_quadrante;
        int quadrantes_na_linha = (coordenada_x -1) / tamanho_quadrante;
        int quadrante_atual = quadrantes_na_coluna * quadrantes_por_linha + quadrantes_na_linha;
    
        return quadrante_atual;
    }
    
    // Função que com base no jogador e a coordenada atual marca a sua jogada no tabuleiro, e caso não consiga retorna 0 para avisar que não foi possivel realizar a jogada
    int realizar_jogada(int *jogador_atual, int quadrante, int coordenada_da_jogada[2], char tabuleiro[3][3], int *rodada){
        int linha_da_jogada = 0;
        int coluna_da_jogada = 0;
    
        // Definindo com base no numero do quadrante em que linha e coluna ele esta
        if (quadrante < 3){
            coluna_da_jogada = quadrante;
        } else if (quadrante >= 3 && quadrante < 6){
            linha_da_jogada = 1;
            coluna_da_jogada = quadrante - 3;
        } else if (quadrante >= 6 && quadrante < 9){
            linha_da_jogada = 2;
            coluna_da_jogada = quadrante - 6;
        }
    
        coordenada_da_jogada[0] = linha_da_jogada;
        coordenada_da_jogada[1] = coluna_da_jogada;
    
        // Tentativa de realizar a jogada, mudando o conteudo do quadrante selecionado para o simbolo que representa o jogador
        if (*jogador_atual == 0 && (tabuleiro[linha_da_jogada][coluna_da_jogada] != 'O' && tabuleiro[linha_da_jogada][coluna_da_jogada] != 'X')){
            tabuleiro[linha_da_jogada][coluna_da_jogada] = 'X';
            *jogador_atual = 1;
            *rodada += 1;
            return 1;
        } else if (*jogador_atual == 1 && (tabuleiro[linha_da_jogada][coluna_da_jogada] != 'X' && tabuleiro[linha_da_jogada][coluna_da_jogada] != 'O')){
            tabuleiro[linha_da_jogada][coluna_da_jogada] = 'O';
            *jogador_atual = 0;
            *rodada += 1;
            return 1;
        }
        return 0;
    }

    // Reinicia as variavevis do jogo como o jogador atual, a rodada atual, a coordenada x e y e o tabuleiro
    void resetar_jogo(int *jogador, int *rodada, int *coordenada_x, int *coordenada_y, char tabuleiro[3][3])
    {
        //Reiniciando para voltar o padrão das variaveis
        *jogador = 0;
        *rodada = 0;
        *coordenada_x = 0;
        *coordenada_y = 0;

        int i = 0;
        int j = 0;

        int representate_linha_atual = 0;

        // Reiniciando o tabuleiro que foi preenchido pelos jogadores, para voltar ao padrão do numero de cada quadrante sendo mostrado
        for (i; i < 3; i++)
        {
            for (j; j < 3; j++)
            {
                if (i == 1)
                    representate_linha_atual = 3;
                else if (i == 2)
                    representate_linha_atual = 6;
                printf("%c", (char)(representate_linha_atual + j));
                tabuleiro[i][j] = (representate_linha_atual + j) + '0';
            }
            j = 0;
        }
    }

    // Ler o arquivo MICE enviado para a função e consegue decodificar os bytes de input enviados pelo mouse, para assim manipular as coordenadas da jogada e verificar se o jogador decidiu realizar a jogada
    int movimento_mouse(int fd, int8_t data[3], int *coordenadas){
        int bytes = read(fd, data, sizeof(data)); // Abre o arquivo MICE para leitura dos eventos de input que o mouse esta enviando
    
        int left = 0 ;
        int middle = 0;
        int right = 0;
        int x = 0;
        int y = 0;
    
        
    
            if(bytes > 0)
            {
                left = data[0] & 0x1; // Lê o 1º LSB e se for igual a 1 significa que o botão esquerdo foi pressionado então left = 1 tambem
                right = data[0] & 0x2; // Lê o 2º LSB e se for igual a 1 significa que o botão direito foi pressionado então right = 1 tambem
                middle = data[0] & 0x4;// Lê o 4º LSB e se for igual a 1 significa que o botão do meio foi pressionado então middle = 1 tambem
    
                x = data[1]; // Lê o segundo pack que é responsavel por indicar a movimentação do mouse no eixo X
                y = data[2]; // Lê o terceiro pack que é responsavel por indicar a movimentação do mouse no eixo Y
                if (x > 0 && coordenadas[0] < 300){
                    coordenadas[0] += 1;
                }
                else if (x < 0 && coordenadas[0] > 0){
                    coordenadas[0] -= 1;
                }
    
                if (y > 0 && coordenadas[1] > 0){
                    coordenadas[1] -= 1;
                }
                else if (y < 0 && coordenadas[1] < 300){
                    coordenadas[1] += 1;
                }
                
                if (left == 1){
                    return 1;       
                }
                return 0;
            } 
        return 0;  
    }
    

    int main()
    {
        
        // Matriz com o Jogo
        char tabuleiro[3][3] = {{'0', '1', '2'}, 
                             {'3', '4', '5'}, 
                             {'6', '7', '8'}};
    
        int rodada = 0;
        
        //Variavel responsavel por controlar a vez de cada jogador, se for = 0 significa que o jogador atual é o X e se for = 1 significa que o jogador atual é o O
        int jogador_atual = 0;
        int coordenada_da_jogada_matriz[2] = {0, 0};
    
        const char *pDevice = "/dev/input/mice"; // Caminho para o arquivo MICE que contem os bytes de input do mouse
        int fd = open(pDevice, O_RDWR); // Abrindo o arquivo para leitura
        int8_t data[3]; // Definindo o array de bytes que serão preenchidos pelo conteudo do MICE
    
        // Caso não consiga abrir o arquivo MICE
        if(fd == -1)
        {
            printf("ERROR ao abrir arquivo %s\n", pDevice);
            return -1;
        }
        
        // Variavel para manter as coordenadas atuais que o jogador esta localizado no tabuleiro
        int coordenadas_atuais[2] = {0, 0};
    
        // Variavel que indica qual o quadrante do tabuleiro o jogador esta selecionando
        int quadrante_selecionado = 0;
    
        // Variavel que é alterada para 1 caso o jogador confirme a sua jogada
        int confirma_jogada = 0;
    
        // Breve introdução do funcionamento do do inicio e encerramento do programa
        printf("\nLembresse de como escolher cada uma das opcões:\n");
        printf("Chave SW0 Inicia novo jogo\n");
        printf("Chave SW1 sai do jogo por completo\n");

        // Ativação do drive das chaves para poder realizar a leitura das mesmas
        SW_open();

        printf("Ative a chave SW0 para iniciar!\n");
    
        int valor = 0;
        int *dados_sw = &valor;
    
        //Lendo o valor da chave mais da direita (SW0) e mantendo no loop até que ela estaja em nivel logico alto
        while (((*dados_sw >> 0) & 1) != 1){
            SW_read(dados_sw); // Lê os dados enviados pelas chaves, sendo um numero que podemos ver como binario e verificar o numero mais a direita ou seja a chave SW0
        }
    
        system("clear");
    
        printf("Iniciando sistema...\n\n");
    
        sleep(1);
        
        // Loop principal do jogo da velha
        while (1){
            
            SW_read(dados_sw);
            
            // Verificando se o usuario decidiu finalizar o programa com SW1 em nivel logico alto
            if (((*dados_sw >> 1) & 1) == 1){
                system("clear");
                printf("\n=====Sistema finalizado!=====\n");
                return 0;
            } 
            // Verificando se o usuario iniciou uma partida com a SW0 em nivel logico alto
            else if (((*dados_sw >> 0) & 1) == 1){
    
                // Limpando o console anterior e imprimindo o novo tabuleiro junto de algumas informações para os usuarios
                imprimir_tabuleiro(tabuleiro);
                quadrante_selecionado = quadrante_atual(coordenadas_atuais[0], coordenadas_atuais[1]);
                printf("\nRodada Atual: %d\n", rodada);
                printf("Se deseja realizar a jogada no quadrante atual clique com o botão esquerdo do mouse\n");
                printf("O quadrante que o jogador %d esta selecionando e: %d\n", jogador_atual + 1, quadrante_selecionado);
    
                // Leitura dos inputs do mouse junto da confirmação da jogada quando o botão esquerdo do mouse é pressionado
                confirma_jogada = movimento_mouse(fd, data, coordenadas_atuais);
    
                // Tenta realizar a jogada no local escolhido pelo usuario quando o botão esquedo é pressionado
                if (confirma_jogada == 1)  // Clique do mouse
                {
                    // Verifica o local escolhido e tenta realizar a jogada, no caso de sucesso retorna 1 e no caso de falha retorna 0
                    int confirmacao = realizar_jogada(&jogador_atual, quadrante_selecionado, coordenada_da_jogada_matriz, tabuleiro, &rodada);

                    // Indica onde a jogada foi feita com base nas linhas e colunas do tabuleiro
                    printf("Linha %d, Coluna %d", coordenada_da_jogada_matriz[0], coordenada_da_jogada_matriz[1]);

                    // Caso não for possivel realizar a jogadan o quadrante selecionado o jogador sera avisado
                    if (confirmacao == 0)
                    {
                        printf("\nO quadrante ja esta ocupado, tente realizar sua jogada em um quadrante vazio!\n");
                    }
                    else
                    {
                        printf("\nJogada realizada com sucesso!\n");
                    }

                    // Realiza uma verificação no fim da jogada para procurar um vencedor caso haja alguma trinca ou tenha acabado em empate
                    char resultado = verificar_vencedor(tabuleiro);
                    if (resultado == 'X') // Vencedor foi o jogador 1
                    {
                        system("clear");
                        imprimir_tabuleiro(tabuleiro);
                        printf("\nJogador 1 foi o vencedor!\n");
                        resetar_jogo(&jogador_atual, &rodada, &coordenadas_atuais[0], &coordenadas_atuais[1], tabuleiro);
                        jogos_ganhos_jogador_1 += 1;
                    }
                    else if (resultado == 'O') // Vencedor foi o jogador 2
                    {
                        system("clear");
                        imprimir_tabuleiro(tabuleiro);
                        printf("\nJogador 2 foi o vencedor!\n");
                        resetar_jogo(&jogador_atual, &rodada, &coordenadas_atuais[0], &coordenadas_atuais[1], tabuleiro);
                        jogos_ganhos_jogador_2 += 1;
                    }
                    else if (resultado != 'O' && resultado != 'X' && rodada == 9) // A partida chegou até a rodada nove não teve nenhum vencedor, logo um empate
                    {
                        system("clear");
                        imprimir_tabuleiro(tabuleiro);
                        printf("\nO jogo terminou em empate!\n");
                        resetar_jogo(&jogador_atual, &rodada, &coordenadas_atuais[0], &coordenadas_atuais[1], tabuleiro);
                    }
    
                    sleep(1);
                }
                // Limpando os dados para que o novo tabuleiro possa ser impresso sem poluição no terminal
                system("clear");

            } 
            // Verifica o inicio de um novo jogo, e caso nenhuma partida tenha sido iniciada (SW0 = 0) então reseta a partida atual para começar uma nova assim que o usuario quiser
            else if (((*dados_sw >> 0) & 1) == 0){
                resetar_jogo(&jogador_atual, &rodada, &coordenadas_atuais[0], &coordenadas_atuais[1], tabuleiro);
            }
            
    }
        // Encessa o drive reponsavel por ler as informações das chaves
        SW_close();
        return 0;
    }