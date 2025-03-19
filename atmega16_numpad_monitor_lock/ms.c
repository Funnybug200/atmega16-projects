#include <mega16.h>
#include <delay.h>

#define r1 PINC.3
#define r2 PINC.4
#define r3 PINC.5
#define r4 PINC.6



unsigned char ssd[10]={0xfc,0x60,0xda,0xf2,0x66,0xb6,0xbe,0xe0,0xfe,0xf6};
unsigned char position = 0x00;
unsigned char cpositions[3] ={0x01,0x02,0x04};
unsigned char tryes[4]={0x00,0x01,0x03,0x07};
int rcposition[4][3]={{1,2,3},
                      {4,5,6},
                      {7,8,9},
                      {11,0,22}};



int sh_i=0;
int bt_i=0;
int i=0;
int j=0;
int k=0;
bit ch = 0;
bit l_check=1;
int temp;
int number[10]={11,11,11,11,11,11,11,11,11,11};
int password[10]={4,0,1,6,2,1,3,1,3,5};
int try=0;



   void show();
   int check();
void main()
{
DDRB=0x00;
DDRA=0x00;
DDRC=0x00;
DDRD=0x00;


delay_ms(10);

DDRB=0xff;
DDRA=0xff;
DDRC=0xff;
DDRD=0xff;


PORTC=0x00;

PORTB=0x00;


delay_ms(10);
    show();
    while(1)
    {
        
      
         for(i=0;i<10;i+=1)
         {
              temp=check();
              switch (temp)
              {
                case 11:
                    for (j=0;j<10;j+=1){number[j]=11;}
                    i=-1;
                    show();
                    break;
                case 22:
                    l_check=1;
                    for (j=0;j<10;j+=1){
                        if(number[j]!=password[j])
                        {
                             try+=1;
                             l_check=0;
                             if(try==4)
                             {
                                
                                for(k=0;k<10;k+=1)
                                {
                                    number[k]=11;
                                }                
                                i=-1;
                                show();
                                while(1)
                                {
                                    PORTD=0x0f;
                                    delay_ms(50);
                                    PORTD=0x00;
                                    delay_ms(50);
                                }
                                
                               
                                  
                             }
                             else{
                                PORTD=tryes[try];
                                
                                for(k=0;k<10;k+=1)
                                {
                                    number[k]=11;
                                }
                                i=-1;                
                                show();
                                break;
                               } 
                        }
                        
                    }
                     if(l_check){
                     while(1)
                            {
                            PORTD=0x30;
                            if(PIND.5==0)
                            {
                                PORTD=0x00;
                                
                                for(k=0;k<10;k+=1)
                                {
                                    number[k]=11;
                                }                
                                i=-1;
                                show();
                                show();
                                break;
                            } 
                            
                            }
                     }
                    break;
                    
                default:
                    number[i]=temp;
                    show();
              }
            delay_ms(50);
         } 
         
     
    }
}

   void show()
   {    
       // position=0xff;
        //PORTA=position;
        position=0x00;
        
        delay_ms(10);

        for(sh_i=0;sh_i<10;sh_i+=1)
        {   
        
              
            
            PORTB=ssd[number[sh_i]];
            PORTA=position;
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