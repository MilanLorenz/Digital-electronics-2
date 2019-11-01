/*
 * ---------------------------------------------------------------------
 * Author:      Tomas Fryza
 *              Dept. of Radio Electronics, Brno Univ. of Technology
 * Created:     2018-09-27
 * Last update: 2019-09-26
 * Platform:    ATmega328P, AVR 8-bit Toolchain 3.6.2
 * ---------------------------------------------------------------------
 * Description: 
 * TODO: 
 * NOTE: 
 */

/* Includes ----------------------------------------------------------*/
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#define DATA   PB0
#define CLK    PD7
#define LATCH  PD4
uint8_t temp;



int main(void)
{
    uint8_t digit = 0b11000000;     //digit/number DP g f e d c b a
    uint8_t position = 0b00001000;  //7-segment display position x x x x 0 1 2 3
      
    /* Set output pin */
    DDRB |= _BV(DATA);
    DDRD |= _BV(CLK) | _BV(LATCH);

    for (uint8_t i=0; i<8; i++)
    {
      temp = digit & (1<<(7-i)); 

      if (temp == 0)
      
        PORTB &= ~_BV(DATA);
      else
        PORTB |= _BV(DATA);
      

      //set DATA value
      PORTD &= ~_BV(CLK);
      _delay_us(1);

      PORTD |= _BV(CLK);
      _delay_us(1);
      

      
    }

    for (uint8_t i=0; i<8; i++)
    {
      temp = position & (1<<(7-i)); 

      if (temp == 0)
      
        PORTB &= ~_BV(DATA);
      else
        PORTB |= _BV(DATA);
      

      
      PORTD &= ~_BV(CLK);
      _delay_us(1);

      PORTD |= _BV(CLK);
      _delay_us(1);
      

      
    }

    PORTD &= ~_BV(LATCH);
      _delay_us(1);

      PORTD |= _BV(LATCH);
      _delay_us(1);
    
}