#include <mega16.h>
#include <delay.h>

#define BUTTON_PIN1 PIND.0
#define BUTTON_PIN2 PIND.7


unsigned char ssd[10]={0xfc,0x60,0xda,0xf2,0x66,0xb6,0xbe,0xe0,0xfe,0xf6};

int i=0;
bit bt1=1;
bit bt2=1;

void main()
{
DDRB=0x00;
DDRA=0x00;

DDRD=0x00;

delay_ms(10);

DDRB=0xff;
DDRA=0xff;

DDRD=0x81;
PORTD.0=1;
PORTD.7=1;

PORTB=0x00;
PORTA=0x00;

    while(1)
    {
          int n1=0;
          int n2=10;       
          if (BUTTON_PIN1==0&&i!=99){
            delay_ms(2);
            if(BUTTON_PIN1==0&&bt1){
                  i+=1;
                  bt1=0;
            }
          }
          if(BUTTON_PIN1==1){bt1=1;}  
          
          if (BUTTON_PIN2==0&&i!=0){
            delay_ms(2);
            if(BUTTON_PIN2==0&&bt2){
                  i-=1;
                  bt2=0;
            }
          } 
           if(BUTTON_PIN2==1){bt2=1;}
          
          n1=i/10;
          n2=i%10;
          PORTB=ssd[n1];   
          PORTA=ssd[n2];
          delay_ms(1);
         
     
    }
}

