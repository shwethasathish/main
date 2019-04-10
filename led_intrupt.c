#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

volatile int Flag=0;
int main(void)
{
    DDRD&=~(1<<2);
    PORTD|=(1<<2);

    DDRB|=(1<<PB0);
    EICRA|=(1<<ISC00);
    EIMSK|=(1<<INT0);
    sei();
    while(1)
    {
        if(Flag==1)
        {
            PORTB|=(1<<0);
            _delay_ms(2000);
            Flag=0;
        }
        else{
            PORTB&=~(1<<0);

        }
        return 0;
    }
}
    ISR(INT0_vect)
    {
        Flag=1;
    }

