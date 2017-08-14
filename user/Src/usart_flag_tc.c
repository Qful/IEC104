/*
 * usart_flag_tc.c
 *
 *  Created on: 16.01.2017
 *      Author: sagok
 */
/*
#define USART_FLAG_TC                        ((uint16_t)0x0040)

static __INLINE void ITM_SendChar_My (uint32_t ch)
{
  while( (USART1->ISR & USART_FLAG_TC ) == 0 )
  {
    ;
  }

  USART1->TDR = (ch & (uint16_t)0x01FF);
}

void printErrorMsg(const char * errMsg)
{
   while( *errMsg != 0 )
   {
      ITM_SendChar_My(*errMsg);
      ++errMsg;
   }
}

void printUsageErrorMsg( uint32_t CFSRValue )
{
    printErrorMsg( "Usage fault: " );
    CFSRValue >>= 16;                  // right shift to lsb
    if( ( CFSRValue & ( 1 << 9 ) ) != 0 )
    {
        printErrorMsg( "Divide by zero\n" );
    }
    if( ( CFSRValue & ( 1 << 8 ) ) != 0 )
    {
        printErrorMsg( "Unaligned acc\n" );
    }
    if( ( CFSRValue & ( 1 << 3 ) ) != 0 )
    {
        printErrorMsg( "NO CP\n" );
    }
    if( ( CFSRValue & ( 1 << 2 ) ) != 0 )
    {
        printErrorMsg( "INV PC\n" );
    }
    if( ( CFSRValue & ( 1 << 1 ) ) != 0 )
    {
        printErrorMsg( "INV STATE\n" );
    }
    if( ( CFSRValue & ( 1 << 0) ) != 0 )
    {
        printErrorMsg( "UNDEF Instr\n" );
    }
}
static char msg[256];

void printBusMemErrorMsg( uint32_t CFSRValue, uint32_t regVal )
{
    if( ( CFSRValue & ( 1 << 7 ) ) != 0 )
    {
      sprintf(msg, "Addr Reg valid: 0x%08x\n", (unsigned int)regVal);
      printErrorMsg( msg );
    }
    if( ( CFSRValue & ( 1 << 5 ) ) != 0 )
    {
        printErrorMsg( "Float Point Lazy State Preserv\n" );
    }
    if( ( CFSRValue & ( 1 << 4 ) ) != 0 )
    {
        printErrorMsg( "Stacking Fault\n" );
    }
    if( ( CFSRValue & ( 1 << 3 ) ) != 0 )
    {
        printErrorMsg( "UNStacking Fault\n" );
    }
    if( ( CFSRValue & ( 1 << 1 ) ) != 0 )
    {
        printErrorMsg( "Data Acc viol\n" );
    }
    if( ( CFSRValue & ( 1 << 0) ) != 0 )
    {
        printErrorMsg( "Instr Acc viol\n" );
    }
}

void prvGetRegistersFromStack( uint32_t * pulFaultStackAddress, u32 faultSrc )
{
    // These are volatile to try and prevent the compiler/linker optimising them
    //away as the variables never actually get used.  If the debugger won't show the
    //values of the variables, make them global my moving their declaration outside
    //of this function.
    volatile uint32_t r0 __attribute__((unused));
    volatile uint32_t r1 __attribute__((unused));
    volatile uint32_t r2 __attribute__((unused));
    volatile uint32_t r3 __attribute__((unused));
    volatile uint32_t r12 __attribute__((unused));
    volatile uint32_t lr __attribute__((unused)); // Link register.
    volatile uint32_t pc __attribute__((unused)); // Program counter.
    volatile uint32_t psr __attribute__((unused));// Program status register.
    volatile uint32_t psp __attribute__((unused));
    volatile uint32_t msp __attribute__((unused));
    volatile uint32_t _CFSR __attribute__((unused));
    volatile uint32_t _HFSR __attribute__((unused));
    volatile uint32_t _DFSR __attribute__((unused));
    volatile uint32_t _AFSR __attribute__((unused));
    volatile uint32_t _BFAR __attribute__((unused));
    volatile uint32_t _MMAR __attribute__((unused));

    r0 = pulFaultStackAddress[ 0 ];
    r1 = pulFaultStackAddress[ 1 ];
    r2 = pulFaultStackAddress[ 2 ];
    r3 = pulFaultStackAddress[ 3 ];

    r12 = pulFaultStackAddress[ 4 ];
    lr = pulFaultStackAddress[ 5 ];
    pc = pulFaultStackAddress[ 6 ];
    psr = pulFaultStackAddress[ 7 ];

    msp = __get_MSP();
    psp = __get_PSP();

    // Configurable Fault Status Register
    // Consists of MMSR, BFSR and UFSR
    _CFSR = (*((volatile unsigned long *)(0xE000ED28))) ;

    // Hard Fault Status Register
    _HFSR = (*((volatile unsigned long *)(0xE000ED2C))) ;

    // Debug Fault Status Register
    _DFSR = (*((volatile unsigned long *)(0xE000ED30))) ;

    // Auxiliary Fault Status Register
    _AFSR = (*((volatile unsigned long *)(0xE000ED3C))) ;

    // Read the Fault Address Registers. These may not contain valid values.
    // Check BFARVALID/MMARVALID to see if they are valid values
    // MemManage Fault Address Register
    _MMAR = (*((volatile unsigned long *)(0xE000ED34))) ;
    // Bus Fault Address Register
    _BFAR = (*((volatile unsigned long *)(0xE000ED38))) ;

    USART1->CR1 &= ~(0x1F0); // Disable Interrupts

    if( faultSrc == 1 )
    {
      printErrorMsg("\nIn Hard Fault Handler\n");
    }
    else if( faultSrc == 2 )
    {
      printErrorMsg("\nIn Memory Managament Fault Handler\n");
    }
    else
    {
      printErrorMsg("\nIn Unknown Fault Handler\n");
    }

    sprintf(msg, "MSP = 0x%08x\n", (unsigned int)msp);          printErrorMsg(msg);
    sprintf(msg, "PSP = 0x%08x\n", (unsigned int)psp);          printErrorMsg(msg);

    sprintf(msg, "SCB->CFSR = 0x%08x\n", (unsigned int)_CFSR);  printErrorMsg( msg );
    sprintf(msg, "SCB->DFSR = 0x%08x\n", (unsigned int)_DFSR);  printErrorMsg(msg);
    sprintf(msg, "SCB->AFSR = 0x%08x\n", (unsigned int)_AFSR);  printErrorMsg(msg);
    sprintf(msg, "SCB->MMAR = 0x%08x\n", (unsigned int)_MMAR);  printErrorMsg(msg);
    sprintf(msg, "SCB->BFAR = 0x%08x\n", (unsigned int)_BFAR);  printErrorMsg(msg);
    sprintf(msg, "SCB->HFSR = 0x%08x\n", (unsigned int)_HFSR);  printErrorMsg(msg);

    if ( ( SCB->HFSR & ( 1 << 30 ) ) != 0 )
    {
        printErrorMsg( "Forced Hard Fault\n" );
    }

    if( ( _CFSR & 0xFFFF0000 ) != 0 )
    {
        printErrorMsg( "Hard Fault:\n" );
        printUsageErrorMsg( _CFSR );
    }

    if( ( _CFSR & 0x0000FFFF ) != 0 )
    {
      if( ( _CFSR & 0x000000FF ) != 0 )
      {
        printErrorMsg("Mem Mgmt Fault:\n");
        printBusMemErrorMsg( _CFSR, _MMAR );
      }
      else
      {
        printErrorMsg("Bus Fault:\n");
        printBusMemErrorMsg( _CFSR >> 8, _BFAR );
      }
    }


   sprintf(msg, "\nr0  = 0x%08x\n", (unsigned int)pulFaultStackAddress[0]);  printErrorMsg(msg);
   sprintf(msg, "r1  = 0x%08x\n", (unsigned int)pulFaultStackAddress[1]);  printErrorMsg(msg);
   sprintf(msg, "r2  = 0x%08x\n", (unsigned int)pulFaultStackAddress[2]);  printErrorMsg(msg);
   sprintf(msg, "r3  = 0x%08x\n", (unsigned int)pulFaultStackAddress[3]);  printErrorMsg(msg);
   sprintf(msg, "r12 = 0x%08x\n", (unsigned int)pulFaultStackAddress[4]);  printErrorMsg(msg);
   sprintf(msg, "lr  = 0x%08x\n", (unsigned int)pulFaultStackAddress[5]);  printErrorMsg(msg);
   sprintf(msg, "pc  = 0x%08x\n", (unsigned int)pulFaultStackAddress[6]);  printErrorMsg(msg);
   sprintf(msg, "psr = 0x%08x\n", (unsigned int)pulFaultStackAddress[7]);  printErrorMsg(msg);

   __asm("BKPT #0\n") ; // Break into the debugger


    // When the following line is hit, the variables contain the register values.
    volatile int a = 1;
    while ( a ) ;
}


void HardFault_Handler( void ) //__attribute__ (( naked ))
{
    __asm volatile
    (
        " tst lr, #4                                                \n"
        " ite eq                                                    \n"
        " mrseq r0, msp                                             \n"
        " mrsne r0, psp                                             \n"
        " ldr r1, [r0, #24]                                         \n"
        " mov r1, 1     \n" // Fault source
        " ldr r3, handler1_address_const                            \n"
        " bx r3                                                     \n"
        " handler1_address_const: .word prvGetRegistersFromStack    \n"
    );

    while ( 1 )
    {
        ;
    }
}

void MemManage_Handler( void )
{
    __asm volatile
    (
        " tst lr, #4                                                \n"
        " ite eq                                                    \n"
        " mrseq r0, msp                                             \n"
        " mrsne r0, psp                                             \n"
        " ldr r1, [r0, #24]                                         \n"
        " mov r1, 2     \n" // Fault source
        " ldr r3, handler2_address_const                            \n"
        " bx r3                                                     \n"
        " handler2_address_const: .word prvGetRegistersFromStack    \n"
    );

    while ( 1 )
    {
       __asm("BKPT #0\n") ; // Break into the debugger
        ;
    }
}

*/
