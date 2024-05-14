#include "mbed.h"
// Include the Mbed library

InterruptIn buttn(PC_13);   // Define an InterruptIn object named buttn, connected to pin PC_13

volatile int myflag = 0;

void buttn_fall(){
    myflag = 1;
}

// main() runs in its own thread in the OS
int main()
{
    printf("This is mbed os v%d \r\n", MBED_VERSION); // Print the Mbed OS version
    buttn.fall(&buttn_fall);
    while (true) {
        // Infinite loop
        
        if(myflag == 1){
            printf("button pressed!!\r\n"); // Print a message indicating that the button has been pressed
            myflag = 0; // Reset the myflag variable to 0
        }

    }
}

