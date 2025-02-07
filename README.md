
<h1 align="center">Embarcatec | Atividade dos Semáforos</h1>

## Objetivo

Com o emprego da função add_repeating_timer_ms(), presente na ferramenta Pico SDK, projete um semáforo com temporização de 3 segundos para cada alteração de sinal. Nesta prática, será necessário simular os seguintes componentes: 
1) 03 Resistores de 330 Ω.
2) 03 LEDs (vermelho, amarelo e verde).
3) Microcontrolador Raspberry Pi Pico W. 

## Requisitos:

** O acionamento dos LEDs (sinais do semáforo) deve iniciar na cor vermelha, conforme orientação presente na Figura 1, alterando para amarela e, em seguida, verde.
** O temporizador deve ser ajustado para um atraso de 3 segundos(3.000ms).
** A mudança de estado dos LEDs deve ser implementa na função de call-back do temporizador, a exemplo da rotina trabalhada na aula síncrona - repeating_timer_callback().
** Com o emprego da Ferramenta Educacional BitDogLab, faça um experimento com o código deste exercício utilizando o LED RGB – GPIOs 11, 12 e 13.

## Observação do projeto
No esquema do simulador eu utilizei corretamente os leds nas cores amarelo, vermlho e verde, porém na placa, como não temos o led amarelo, optei por usar as cores padrão do LED RGB da placa que seria vermelho, azul e verde. Assim, na placa a cor mais próxima para representar o amarelo foi a mistura entre todas as 3 cores, que resultou na branca, que na placa ela representaria a cor amarela. 
Para fazer com que o código funcione na placa, você precisa sinalizar no código que está utilizando o código feito na placa, assim você precisa colocar a váriavel global "placa" como valor true e compilar novamente o código. 

## Tecnologias Usadas

1. Git e Github;
2. VScode;
3. Linguagem C;
4. Simulador Wokwi;


## Desenvolvedora
 
<table>
  <tr>
    <td align="center"> <sub><b> Sara Souza Ferreira </b></td>
    </tr>
</table>

Simulação na web: https://wokwi.com/projects/421978711006516225
    

   
