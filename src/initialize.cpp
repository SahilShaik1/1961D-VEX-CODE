#include "main.h"
//basic functions 
static pros::Motor intakeMotor (12, pros::E_MOTOR_GEARSET_36, false);
static pros::Motor liftMotor (16, pros::E_MOTOR_GEARSET_06, false);
static pros::ADIDigitalOut leftWing('B');
static pros::ADIDigitalOut blocker('A');

static bool shotl = false;
static bool shotr = false;
static bool buttonL1State = false;
static bool buttonR1State = false;
static bool intaking = false;

static void setWing () {
  shotl = !shotl;

}
static void setBlocker () {
  shotr = !shotr;
}
static void intakeMove (bool outtake = false) {
    intakeMotor.move_velocity((outtake) ? 100 : -100);
}

static void intakeStop () {
  intakeMotor.move_velocity(0);
}

static void liftMove(bool reverse = false){
    liftMotor.move_velocity((!reverse) ? 600 : -600);
}


static void liftStop () {
    liftMotor.move_velocity(0);
}

static void wingDeploy(bool in = false){
    leftWing.set_value((!in) ? 1 : 0);
}

static void blockerDeploy(bool in = false){
    blocker.set_value((!in) ? 1 : 0);
}