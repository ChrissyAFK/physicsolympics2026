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
vex::motor motor1 = vex::motor(vex::PORT9, vex::ratio18_1, false);
vex::motor motor2 = vex::motor(vex::PORT10, vex::ratio18_1, false);
vex::bumper buttonSense = bumper(Brain.ThreeWirePort.A);
vex::limit Limit = limit(Brain.ThreeWirePort.B);

bool motor1Clockwise = true;
bool hasSwitchedDirection = false;

int speed = 30;

void UpdateMotors() {
  motor1.spin(motor1Clockwise ? vex::directionType::fwd : vex::directionType::rev,
              speed,
              rpm);
  motor2.spin(motor1Clockwise ? vex::directionType::rev : vex::directionType::fwd,
              speed,
              rpm);
}

void Released() {
  // The Brain will print that the Bumper Switch was pressed on the
  // Brain's screen.
  Brain.Screen.printAt( 10, 50, "pressed         " );
  if (!hasSwitchedDirection) {
    motor1Clockwise = !motor1Clockwise;
    hasSwitchedDirection = true;
    UpdateMotors();
  }
}
int main() {
    Brain.Screen.printAt( 10, 50, "Poleclimber Physics Olympics 2026" );
    UpdateMotors();
    buttonSense.released(Released);
    Limit.released(Released);
    while(1) {
        // Keep running; motors are controlled by UpdateMotors().
        // Allow other tasks to run
        this_thread::sleep_for(10);
    }
}