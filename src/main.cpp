/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       pengwuin                                                  */
/*    Created:      2/11/2026, 2:35:58 PM                                     */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/
#include "vex.h"

using namespace vex;

// A global instance of vex::brain used for printing to the V5 brain screen
vex::brain       Brain;

// define your global instances of motors and other devices here
vex::motor motor1 = vex::motor(vex::PORT9, vex::ratio6_1, false);
vex::motor motor2 = vex::motor(vex::PORT10, vex::ratio6_1, false);
vex::motor_group allMotors = vex::motor_group(motor1, motor2);
vex::bumper buttonSense = bumper(Brain.ThreeWirePort.A);
vex::limit Limit = limit(Brain.ThreeWirePort.B);

int speed = 30;

void Pressed() {
  // The Brain will print that the Bumper Switch was pressed on the
  // Brain's screen.
  Brain.Screen.printAt( 10, 50, "pressed         " );
  motor1.setVelocity(-speed, rpm);
  motor2.setVelocity(speed, rpm);
}
int main() {
    Brain.Screen.printAt( 10, 50, "Hello V5" );
    motor1.setVelocity(speed, rpm);
    motor2.setVelocity(-speed, rpm);
    buttonSense.released(Pressed);
    Limit.released(Pressed);
    while(1) {
        
        allMotors.spin(vex::directionType::fwd);
        
        // Allow other tasks to run
        //this_thread::sleep_for(10);
    }
}
