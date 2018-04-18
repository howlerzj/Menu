//  NOTES TO SELF
// Need to make a value to represent the number so that you can put it into the switch function to call next menu.
#include "Libraries.h";




#define inputs GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_6|GPIO_PIN_7

/*Pin Connections:
 * PE4 [pin 5]  -> RS
 * PE5 [pin 6]  -> EN
 * PD0 [pin 23] -> D4
 * PD1 [pin 24] -> D5
 * PD2 [pin 25] -> D6
 * PD3 [pin 26] -> D7
 */

/* Input pins:
 Keypad       Tiva
 2            PC4
 7            PC5
 6            PC6
 4            PC7
 
 Output pins:
 Keypad       Tiva
 3            PB4
 1            PB0
 5            PB1
 */

// Function Declarations
int CheckRow();
int CheckColumn();
void initKeypad();
int BaseMenu();
void MainMenuChoice();
int GetKeyPress();

static int keys[4][3] = {
    {1,2,3},
    {4,5,6},
    {7,8,9},
    {10,0,12}
};
uint32_t prevNum = 20;

// ******Setting passwords for service
int passAdmin = 1234;
int passTech = 4567;
int passClean = 9876;

void main(void)
{
    //80Mhz, 16Mhz crystal
    //  SysCtlClockSet(SYSCTL_SYSDIV_2_5 | SYSCTL_USE_PLL | SYSCTL_OSC_MAIN | SYSCTL_XTAL_16MHZ);
    SysCtlClockSet(SYSCTL_SYSDIV_8|SYSCTL_USE_PLL|SYSCTL_XTAL_16MHZ|SYSCTL_OSC_MAIN);
    initLCD();
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOC);  // enable ports
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOB);
    
    GPIOPinTypeGPIOOutput(GPIO_PORTB_BASE, GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_4); //Set output pins
    
    
    
    GPIOPinTypeGPIOInput(GPIO_PORTC_BASE, GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_6|GPIO_PIN_7); //Set input pins
    
    GPIOPadConfigSet(GPIO_PORTC_BASE,GPIO_PIN_4,GPIO_STRENGTH_2MA,GPIO_PIN_TYPE_STD_WPD);
    GPIOPadConfigSet(GPIO_PORTC_BASE,GPIO_PIN_5,GPIO_STRENGTH_2MA,GPIO_PIN_TYPE_STD_WPD);
    GPIOPadConfigSet(GPIO_PORTC_BASE,GPIO_PIN_6,GPIO_STRENGTH_2MA,GPIO_PIN_TYPE_STD_WPD);
    GPIOPadConfigSet(GPIO_PORTC_BASE,GPIO_PIN_7,GPIO_STRENGTH_2MA,GPIO_PIN_TYPE_STD_WPD);//Turn on pull up resistor of PB4
    GPIOPinWrite(GPIO_PORTB_BASE,GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_4, GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_4); // Write outputs high PartB
    
    
    
    SysCtlDelay(10000000);
    
    
    
    while(1)
    {
        GPIOPinWrite(GPIO_PORTB_BASE,GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_4, GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_4);
        
        
        BaseMenu();
        
        
    }
    
}

/****************************   Functions *******************************/

int BaseMenu()
{
    setCursorPositionLCD(0,0);
    printLCD("1) Administration");
    setCursorPositionLCD(1,0);
    printLCD("2) Technician");
    setCursorPositionLCD(2,0);
    printLCD("3) Cleaner");
    setCursorPositionLCD(3,0);
    
    
    SysCtlDelay(10000000);
    
    
    while (1) {
        if (GetKeyPress) {
            if (GetKeyPress, "1") == 0) Admin();
            else if (GetKeyPress, "2") == 0) Technician();
            else if (GetKeyPress, "3") == 0) Cleaner();
            else k.isPressed = false;
        }
  
        
        

//********************Key Press functions****************************************

int GetKeyPress()
{
    GPIOPinWrite(GPIO_PORTB_BASE,GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_4, GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_4);
    
    int col = CheckColumn();
    int row = CheckRow();
    if (row != -1 && col != -1) return keys[row][col];
    else return -1;
    
}

//************** Admin Functions****************************************
int Admin()
        {
            GetKeyPress = false;
            clearLCD();
            
            
            setCursorPositionLCD(0,0);
            printLCD("1) Password");
            setCursorPositionLCD(1,0);
            printLCD("2) Company");
            setCursorPositionLCD(2,0);
            printLCD("*) Back");
            setCursorPositionLCD(3,0);
            
            
            SysCtlDelay(10000000);
            
            
            while (1) {
                if (GetKeyPress) {
                    if (GetKeyPress, "1") == 0) Password();
                    else if (GetKeyPress, "2") == 0) Technician();

                    else GetKeyPress = false;
    return;
                }
              
 int Password()
    {
     GetKeyPress = false;
      clearLCD();
      setCursorPositionLCD(0,0);
      printLCD("You have reached password.");
      setCursorPositionLCD(2,0);
       printLCD("*) Back");
        setCursorPositionLCD(3,0);
                    
      while (1) {
      if (GetKeyPress) {
         if (GetKeyPress, "1") == 0) GetKeyPress = false;
          else if (GetKeyPress, "2") == 0) GetKeyPress = false;
          else if (GetKeyPress, "2") == 0) GetKeyPress = false;
       else GetKeyPress = false;
   return;
                    
     }

 int Company()
    {
        GetKeyPress = false;
        clearLCD();
                    
                    
         setCursorPositionLCD(0,0);
         printLCD("Jeremy Karsikas");
         setCursorPositionLCD(1,0);
         printLCD("Nicole Edwards");
         setCursorPositionLCD(2,0);
         printLCD("James Sherry");
         setCursorPositionLCD(3,0);
         printLCD("*) Back");
         setCursorPositionLCD(4,0);
                    
          while (1) {
                  if (GetKeyPress) {
                   if (GetKeyPress, "1") == 0) GetKeyPress = false;
                      else if (GetKeyPress, "2") == 0) GetKeyPress = false;
                       else GetKeyPress = false;
                            return;
                    
                    return;
                    
                }
                        
//*********************************Tech Selection
int Technician()
      {
        GetKeyPress = false;
        clearLCD();
                            
                            
        setCursorPositionLCD(0,0);
        printLCD("1) Motor Control");
        setCursorPositionLCD(1,0);
        printLCD("2) Company");
        setCursorPositionLCD(2,0);
        printLCD("*) Back");
        setCursorPositionLCD(3,0);
                            
                            
         SysCtlDelay(10000000);
                            
                            
          while (1) {
          if (GetKeyPress) {
                              if (GetKeyPress, "1") == 0) MotorControl();
                                    else if (GetKeyPress, "2") == 0) Technician();
                                    
                                    else GetKeyPress = false;
                                    return;
                            }
          }





//************************* Joint Functions***************
          
void motorControl() {
              GetKeyPress = false;
              clearLCD();
              
              setCursorPositionLCD(0, 0);
              printLCD("1. New Position");
              setCursorPositionLCD(0, 1);
              printLCD("2. Rotate Manually");
              setCursorPositionLCD(0, 2);
              printLCD("3. Change RPM");
              setCursorPositionLCD(0, 3);
              printCharLCD(0);
              printCharLCD(2);
              printLCD("*");
              
              while (1) {
                  if (GetKeyPress) {
                      if (GetKeyPress, "1") == 0) newPosition();
                      else if (GetKeyPress, "2") == 0) rotateManually();
                      else if (GetKeyPress, "3") == 0) changeRPM();
                      else if (GetKeyPress, "*") == 0) menu();
                      else GetKeyPress = false;
                  }
              }
          }
