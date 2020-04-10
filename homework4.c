#include <ti/devices/msp432p4xx/driverlib/driverlib.h>
#include "homework4.h"

int main(void)
{
    char rChar;
    char *response = "\n\n\r2534 is the best course in the curriculum!\r\n\n";

    // TODO: Declare the variables that main uses to interact with your state machine.
    bool finished = false;

    // Stops the Watchdog timer.
    initBoard();
    // TODO: Declare a UART config struct as defined in uart.h.
    //       To begin, configure the UART for 9600 baud, 8-bit payload (LSB first), no parity, 1 stop bit.
    eUSCI_UART_ConfigV1 uartConfig =
    {
         EUSCI_A_UART_CLOCKSOURCE_SMCLK,
         // Clock source = 3MHz
         19,
         // UCBR = 19
         8,
         // UCBRF = 8
         0x55,
         // UCBRS = 0x55
         EUSCI_A_UART_NO_PARITY,
         // No parity bit/bits
         EUSCI_A_UART_LSB_FIRST,
         // LSB first, HSB last (read right to left)
         EUSCI_A_UART_ONE_STOP_BIT,
         // stop bit x 1
         EUSCI_A_UART_MODE,
         // UART mode
         EUSCI_A_UART_OVERSAMPLING_BAUDRATE_GENERATION,
         // oversampling
         EUSCI_A_UART_8_BIT_LEN,
         // payload length = 8 bit
    };

    // TODO: Make sure Tx AND Rx pins of EUSCI_A0 work for UART and not as regular GPIO pins.
    GPIO_setAsPeripheralModuleFunctionInputPin(GPIO_PORT_P1, GPIO_PIN2, GPIO_PRIMARY_MODULE_FUNCTION);
    GPIO_setAsPeripheralModuleFunctionOutputPin(GPIO_PORT_P1, GPIO_PIN3, GPIO_PRIMARY_MODULE_FUNCTION);

    // TODO: Initialize EUSCI_A0
    UART_initModule(EUSCI_A0_BASE , &uartConfig);

    // TODO: Enable EUSCI_A0
    UART_enableModule(EUSCI_A0_BASE);

    while(1)
    {
        // TODO: Check the receive interrupt flag to see if a received character is available.
        //       Return 0xFF if no character is available.


        // TODO: If an actual character was received, echo the character to the terminal AND use it to update the FSM.
        //       Check the transmit interrupt flag prior to transmitting the character.



        // TODO: If the FSM indicates a successful string entry, transmit the response string.
        //       Check the transmit interrupt flag prior to transmitting each character and moving on to the next one.
        //       Make sure to reset the success variable after transmission.


    }
}

void initBoard()
{
    WDT_A_hold(WDT_A_BASE);
}

// TODO: FSM for detecting character sequence.
bool charFSM(char rChar)
{
    bool finished = false;


    return finished;
}
