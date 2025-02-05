// Atividade EMBACATECH
// Aluna: Sara Souza Ferreira
// Data de Entrega: 04/02/2025

#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/timer.h"

#define LED_PIN_GREEN 13 
#define LED_PIN_YELLOW 12
#define LED_PIN_RED 11

// estado do semáforo
int estado_semaforo = 0;
bool placa = false;

// Função de callback do temporizador
bool repeating_timer_callback(struct repeating_timer *t) {
    printf("Mudança de semáforo\n");

    // Alterna entre os estados do semáforo
    switch (estado_semaforo) {
        case 0: // Vermelho
            if(!placa){
                gpio_put(LED_PIN_RED, 1);
                gpio_put(LED_PIN_YELLOW, 0);
                gpio_put(LED_PIN_GREEN, 0);
            }
            else {
                gpio_put(LED_PIN_RED, 0);
                gpio_put(LED_PIN_YELLOW, 0);
                gpio_put(LED_PIN_GREEN, 1);
            }
            break;

        case 1: // Amarelo
            if(!placa){
                gpio_put(LED_PIN_RED, 0);
                gpio_put(LED_PIN_YELLOW, 1);
                gpio_put(LED_PIN_GREEN, 0);
            }else{ //o mais prox de amarelo que pude chegar foi o branco
                gpio_put(LED_PIN_RED, 1);
                gpio_put(LED_PIN_YELLOW, 1);
                gpio_put(LED_PIN_GREEN, 1);
            }
            break;

        case 2: // Verde
            if(!placa){
                gpio_put(LED_PIN_RED, 0);
                gpio_put(LED_PIN_YELLOW, 0);
                gpio_put(LED_PIN_GREEN, 1);
            } else {
                gpio_put(LED_PIN_RED, 1);
                gpio_put(LED_PIN_YELLOW, 0);
                gpio_put(LED_PIN_GREEN, 0);
            }
            break;
    }

    // Avança para o próximo estado (0 → 1 → 2 → 0)
    estado_semaforo = (estado_semaforo + 1) % 3;

    return true; // Mantém o temporizador rodando
}

// Função principal
int main() {
    stdio_init_all();
    gpio_init(LED_PIN_RED);
    gpio_set_dir(LED_PIN_RED, GPIO_OUT);

    gpio_init(LED_PIN_YELLOW);
    gpio_set_dir(LED_PIN_YELLOW, GPIO_OUT);

    gpio_init(LED_PIN_GREEN);
    gpio_set_dir(LED_PIN_GREEN, GPIO_OUT);

    struct repeating_timer timer;

    // Configura o temporizador para mudar o semáforo a cada 3 segundos
    add_repeating_timer_ms(3000, repeating_timer_callback, NULL, &timer);

    // Loop principal para exibir mensagens a cada segundo
    while (true) {
        printf("Semáforo rodando...\n");
        sleep_ms(1000);
    }

    return 0;
}
