#include <mega16.h>
#include <delay.h>

#define r1 PINC.3
#define r2 PINC.4
#define r3 PINC.5
#define r4 PINC.6



unsigned char ssd[10]={0xfc,0x60,0xda,0xf2,0x66,0xb6,0xbe,0xe0,0xfe,0xf6};
unsigned char position = 0x00;
unsigned char cpositions[3] ={0x01,0x02,0x04};
int rcposition[4][3]={{1,2,3},
                      {4,5,6},
                      {7,8,9},
                      {11,0,22}};



int sh_i=0;
int bt_i=0;
int i=0;
int j=0;
bit ch = 0;
int number[10]={11,11,11,11,11,11,11,11,11,11};



   void show();
   int check();
void main()
{
DDRB=0x00;
DDRA=0x00;
DDRC=0x00;


delay_ms(10);

DDRB=0xff;
DDRA=0xff;
DDRC=0xff;



PORTC=0x00;

PORTB=0x00;

delay_ms(10);

    while(1)
    {
        
      
         for(i=0;i<10;i+=1)
         {
            number[i]=check();
            if(number[i]==11){for(j=0;j<10;j+=1){number[j]=11;i=-1;}}
            show(); 
            delay_ms(50);
         } 
         
     
    }
}

   void show()
   {  
        position=0x00;
        
        delay_ms(10);

        for(sh_i=0;sh_i<10;sh_i+=1)
        {   
        
            PORTA=position;  
            
            PORTB=ssd[number[sh_i]];

            position+=1;
            
             
            
        } 
       
   }
   int check()
   {
        ch=1;
        while(ch)
        {
            for(bt_i=0;bt_i<3;bt_i+=1)
            {
                  PORTC=cpositions[bt_i];
                  if(r1==1){ch=0;return rcposition[0][bt_i];}
                   if(r2==1){ch=0;return rcposition[1][bt_i];}
                    if(r3==1){ch=0;return rcposition[2][bt_i];}
                     if(r4==1){ch=0;return rcposition[3][bt_i];}
                       //delay_ms(100);
                  
            }
        }
        
   }