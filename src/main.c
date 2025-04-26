
#include <genesis.h>

// Definindo a estrutura para o jogador
typedef struct {
    fix16 x, y; // Posição do jogador
    fix16 width, height; // Largura e altura do jogador
} Player;

typedef struct {
    fix16 x, y; // Posição do objeto
    fix16 width, height; // Largura e altura do objeto
} GameObject;

// Função para detectar colisão entre jogador e objeto
int isCollision(Player *player, GameObject *object) {
    fix16 player_left = player->x;
    fix16 player_right = player->x + player->width;
    fix16 player_top = player->y;
    fix16 player_bottom = player->y + player->height;

    fix16 object_left = object->x;
    fix16 object_right = object->x + object->width;  // Corrigido para object->width
    fix16 object_top = object->y;
    fix16 object_bottom = object->y + object->height;  // Corrigido para object->height

    // Verifica se as bordas dos retângulos se sobrepõem
    if (player_right > object_left && player_left < object_right && 
        player_bottom > object_top && player_top < object_bottom) {
        return 1; // Colisão detectada
    }
    return 0; // Sem colisão
}

int main() {
    VDP_init();

    Player player = { FIX16(100), FIX16(100), FIX16(16), FIX16(16) };
    GameObject object = { FIX16(120), FIX16(120), FIX16(16), FIX16(16) };

    // Loop principal do jogo
    while (1) {
        // Lógica do jogo...
        // Verificar colisão a cada frame
        if (isCollision(&player, &object)) {
            VDP_drawText("COLISAO!", 10, 10);
        } else {
            VDP_clearText(10, 10, 8); // Limpa a mensagem de colisão
        }
        
        // Processa o próximo frame
       // SYS_doVBlankProcess();
    }
    
    return 0;
}
/*

### Ajustes:
1. **Correção nos cálculos das bordas do objeto**: O cálculo de `object_right` e `object_bottom` agora usa `object->width` e `object->height`, respectivamente, em vez de `player->width` e `player->height`.
2. **Lógica de limpeza do texto**: Adicionei a função `VDP_clearText()` para limpar a mensagem de colisão quando não houver colisão.

Esse código deve funcionar corretamente para detectar colisões retangulares entre o jogador e um objeto no SGDK.*/