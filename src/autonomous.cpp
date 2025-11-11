#include "main.h"

// const double Autonomous::CLOCKWISE_CORRECTION = 360.0 / 357.0;  // Corrects for clockwise turns
// const double Autonomous::COUNTERCLOCKWISE_CORRECTION = 357.0 / 360.0; // Corrects for counterclockwise turns

// double Autonomous::previous_heading = 0.0;
// double Autonomous::corrected_heading = 0.0;



// // class DrivetrainGood : public lemlib::Drivetrain{
// //     DrivetrainGood(lemlib::Drivetrain drivetrain) : lemlib::Drivetrain(drivetrain){}
    
// // };

double currentAngle=0;

void move(int dist, int time){
    chassis.setPose(0,0,0);
    if(dist>0) chassis.moveToPoint(0,dist,time,{},false);
    else chassis.moveToPoint(0,dist,time,{.forwards=false},false);
    currentAngle-=chassis.getPose().theta;
}

void turn(int angle, int time){
    chassis.setPose(0,0,currentAngle);
    chassis.turnToHeading(currentAngle-angle,time,{},false);
    currentAngle-=chassis.getPose().theta;
}

// void Autonomous::initialize(){
//     // lemlib initialization
//     inertial.reset(true); // reset inertial sensor
//     chassis.calibrate(); // calibrate sensors
// }

// void Autonomous::debug(){
//     pros::screen::print(TEXT_MEDIUM,0,"%f", chassis.getPose().x); // x
//     pros::screen::print(TEXT_MEDIUM,1,"%f", chassis.getPose().y); // y
//     pros::screen::print(TEXT_MEDIUM,2,"%f", chassis.getPose().theta); // theta
//     pros::screen::print(TEXT_MEDIUM,3,"%f", previous_heading);
//     pros::screen::print(TEXT_MEDIUM,4,"%f", corrected_heading);
// }

// void Autonomous::PIDtune(){
//     // lemlib PID tuning
//     chassis.setPose(0,0,0); // set the robot's position to the origin
//     chassis.turnToHeading(90*357.0/360.0,1000);
//     // Autonomous::correctHeading();
//     chassis.turnToHeading(180*357.0/360.0,1000);
//     // Autonomous::correctHeading();
//     chassis.turnToHeading(270*357.0/360.0,1000);
//     // Autonomous::correctHeading();
//     chassis.turnToHeading(360*357.0/360.0,1000);
//     // Autonomous::correctHeading();
//     Autonomous::debug();
// }

// void Autonomous::lateralPIDtune(){
//     // lemlib lateral PID tuning
//     leftWheels.set_brake_mode_all(pros::E_MOTOR_BRAKE_HOLD);
// 	rightWheels.set_brake_mode_all(pros::E_MOTOR_BRAKE_HOLD);
//     chassis.setPose(0,0,0); // set the robot's position to the origin
//     chassis.moveToPoint(0,12,2000,{},false);
//     DriveTrain::stopLeft();
//     DriveTrain::stopRight();
//     // Autonomous::correctHeading();
//     chassis.turnToPoint(24,12,2000,{}, false);
//     chassis.moveToPoint(24,12,2000,{}, false);
//     DriveTrain::stopLeft();
//     DriveTrain::stopRight();
//     pros::lcd::print(8, "Driver control running");

//     while (true){
//         Autonomous::debug();
//     }

//     // // Autonomous::correctHeading();
//     // chassis.moveToPoint(12,0,2000);
//     // DriveTrain::stopLeft();
//     // DriveTrain::stopRight();
//     // // Autonomous::correctHeading();
//     // chassis.moveToPoint(0,0,2000);
//     // DriveTrain::stopLeft();
//     // DriveTrain::stopRight();
//     // // Autonomous::correctHeading();
// }

void Autonomous::test(){
    leftWheels.set_brake_mode_all(pros::E_MOTOR_BRAKE_HOLD);
	rightWheels.set_brake_mode_all(pros::E_MOTOR_BRAKE_HOLD);
    currentAngle=0;
    chassis.setPose(0,0,0);
    turn(180,1500);
}

// void blueNegativeAuton(){
//     chassis.setPose(0,0,90);
//     chassis.moveToPose(11,-3,0,800,{.forwards=false},false);
//     rampMotor.move_velocity(600);
//     pros::delay(1200);
//     chassis.moveToPoint(11,0,800,{},false);
//     chassis.turnToHeading(-45,1200,{},false);
//     chassis.moveToPoint(-35,35,1200,{},false);
//     chassis.turnToHeading(-90,800,{},false);
//     chassis.moveToPoint(-11,35,1200,{.forwards=false},false);
    
// }


void Autonomous::matchLeftAuton1(){
    currentAngle=0;
    chassis.setPose(0,0,0);
    leftWheels.set_brake_mode_all(pros::E_MOTOR_BRAKE_HOLD);
	rightWheels.set_brake_mode_all(pros::E_MOTOR_BRAKE_HOLD);
    intakeMotor.move_voltage(-3000);
    rampMotor.move_voltage(12000);
    midMotor.move_voltage(-3000);
    //pneumatic.set_value(true);
    move(-20,1500);
    turn(118,750);
    pros::delay(300);
    leftWheels.set_brake_mode_all(pros::E_MOTOR_BRAKE_BRAKE);
	rightWheels.set_brake_mode_all(pros::E_MOTOR_BRAKE_BRAKE);
    move(19,1000);
    leftWheels.set_brake_mode_all(pros::E_MOTOR_BRAKE_HOLD);
	rightWheels.set_brake_mode_all(pros::E_MOTOR_BRAKE_HOLD);
    intakeMotor.move_voltage(-10000);
    rampMotor.move_voltage(-12000);
    midMotor.move_voltage(0);
    pros::delay(450);
    intakeMotor.move_voltage(10000);
    rampMotor.move_voltage(12000);
    midMotor.move_voltage(10000);
    // pros::delay(2500);
    // chassis.turnToHeading(-90,750,{},false);
    // move(22,1250);
    // pneumatic.set_value(false);

    // pros::delay(1500);
    // move(-10,750);
    // turn(-45,1000);
    // move(40,1250);
    // intakeMotor.move_voltage(10000);
    //     rampMotor.move_voltage(12000);
    //     midMotor.move_voltage(-10000);
}

void Autonomous::matchLeftAuton2(){
    
    chassis.moveToPoint(-8,24,1250,{.forwards=false});
    chassis.moveToPose(4,35,45,1250,{});
    // pros::delay(2500);
    // chassis.turnToHeading(-90,750,{},false);
    // move(22,1250);
    // pneumatic.set_value(false);

    // pros::delay(1500);
    // move(-10,750);
    // turn(-45,1000);
    // move(40,1250);
    // intakeMotor.move_voltage(10000);
    //     rampMotor.move_voltage(12000);
    //     midMotor.move_voltage(-10000);
}

// void Autonomous::matchRightAuton(){
//         // chassis.setPose(0,0,0);
//     // chassis.moveToPoint(0,-24,2000);
//     // DriveTrain::move_velocity(-600,-600);
//     // pros::delay(400);
//     // DriveTrain::move_velocity(0,0);
//     // pros::delay(450);
//     // Control::grabberState = !Control::grabberState;
//     // clamp.set_value(Control::grabberState);
//     // pros::delay(275);
//     // DriveTrain::move_velocity(-600,-600);
//     // pros::delay(700);
//     // DriveTrain::move_velocity(0,0);
//     // intakeMotor.move_velocity(600);
//     // rampMotor.move_velocity(600);
//     // DriveTrain::move_velocity(0,0);
//     // intakeMotor.move_velocity(0);
//     chassis.setPose(0,4,90);
//     chassis.moveToPoint(0,0,1000,{.forwards = false},false);
//     chassis.turnToHeading(0,1000,{.direction = lemlib::AngularDirection::CCW_COUNTERCLOCKWISE},false);
//     chassis.moveToPoint(0,-2,1000,{.forwards = false},false);
//     intakeMotor.move_velocity(600);
//     rampMotor.move_velocity(600);
//     pros::delay(700);
//     intakeMotor.move_velocity(600);
//     rampMotor.move_velocity(0);
//     chassis.moveToPoint(48,30,2000,{},false);
//     chassis.moveToPoint(50,32,1000,{},false);
//     chassis.moveToPose(36,30,90,2000,{.forwards = false},false);
//     chassis.moveToPoint(33,30,1000,{.forwards = false},false);
//     clamp.set_value(true);
//     rampMotor.move_velocity(600);
//     return;
//     // discard the code below
//     currentAngle=0;
//     chassis.setPose(0,0,0);

//     turn(-90,1500);
//     move(-20,1500);
//     turn(0,1500);
//     move(-3,750);
//     rampMotor.move_velocity(600);
//     pros::delay(1500);
//     turn(140,1500);
//     move(-35,3000);
//     move(-4,750);
//     move(-4,750);
//     clamp.set_value(true);
//     intakeMotor.move_velocity(600);
//     rampMotor.move_velocity(600);
//     turn(260,1500);
//     move(15,800);
//     leftWheels.move_velocity(100);
//     rightWheels.move_velocity(100);
//     pros::delay(500);
//     intakeMotor.move_velocity(600);
//     leftWheels.move_velocity(-100);
//     rightWheels.move_velocity(-100);
//     pros::delay(2000);
//     //rampMotor.move_velocity(0);
//     //intakeMotor.move_velocity(0);
//     leftWheels.move_velocity(100);
//     rightWheels.move_velocity(100);
//     pros::delay(2000);
//     leftWheels.move_velocity(0);
//     rightWheels.move_velocity(0);

// }

// void Autonomous::skillsAuton(){
//     currentAngle=0;
//     chassis.setPose(0,0,0);

//     //------------------------------------------------------------------
//     //===Phase 0: initial wall stake acoring===
//     rampMotor.move_velocity(600);
//     pros::delay(1300);
//     rampMotor.move_velocity(0);
    
//     //------------------------------------------------------------------
//     //===Phase 1: first mobile goal===
//     //chassis.moveToPoint(0,12,1200,{},false);
//     // move(12,1200);
//     //chassis.turnToHeading(-90,1200, {.direction = lemlib::AngularDirection::CCW_COUNTERCLOCKWISE},false);
//     // turn(90,1200);
//     //chassis.moveToPoint(14,12, 1500,{.forwards = false}, false);
//     chassis.moveToPose(24,12,-90,2500,{.forwards=false},false);
//     // move(-14,1500);
//     clamp.set_value(true);
//     rampMotor.move_velocity(-600);
//     pros::delay(500);
//     //chassis.moveToPoint(22,12,1200,{.forwards = false}, false);
//     // move(-8,1200);
//     //chassis.turnToHeading(0,1200,{},false);
//     // turn(0,1200);
//     intakeMotor.move_velocity(600);
//     rampMotor.move_velocity(600);
//     chassis.moveToPose(32,36,60,3000,{},false);
//     chassis.moveToPoint(54,36,3000,{},false);
//     chassis.moveToPoint(60,60,3000,{},false);
//     chassis.moveToPoint(60,10,3000,{},false);
//     chassis.moveToPoint(52,10,1500,{}, false);
//     chassis.moveToPoint(52,2,1500,{}, false);
//     chassis.moveToPoint(63,-2,1500,{.forwards=false}, false);
//     // move(22,3000);
//     //chassis.turnToHeading(90,1200,{},false);
//     // turn(-90,1200);
//     //chassis.moveToPoint(37,36,2500,{},false);
//     // move(15,2500);
//     //chassis.moveToPoint(44,36,2500,{},false);
//     // move(7,1200);
//     //chassis.turnToHeading(180,1200,{},false);
//     // turn(-180,1200);
//     //chassis.moveToPoint(44,1,2500,{},false);
//     // move(35,2500);
//     //chassis.moveToPoint(44,4,1000,{.forwards = false}, false);
//     // move(-3,1000);
//     //chassis.turnToHeading(250,1200,{},false);
//     // turn(70,1200);
//     //chassis.moveToPoint(50,-2,1200,{.forwards = false}, false);
//     // move(-12,1200);

//     rampMotor.move_velocity(0);

//     clamp.set_value(false);
//     return;
//     //------------------------------------------------------------------
//     //===Phase 2: second mobile goal===
//     currentAngle-=10;
//     move(23,1200);
//     turn(-90,1200);
//     move(-50,3000);
    
//     move(-4,750);
//     move(-5,750);
//     clamp.set_value(true);
//     rampMotor.move_velocity(600); 
//     // turn(-60,1200);
//     // move(-50,2000);
//     // clamp.set_value(false);
//     // return;
//     turn(80,1700);
//     move(30,2500);
//     turn(-30,1500);
//     move(-12,1200);
//     clamp.set_value(false);
// }





// void Autonomous::skillsAuton2(){
//     currentAngle=0;
//     chassis.setPose(0,0,0);

//     //------------------------------------------------------------------
//     //===Phase 0: initial wall stake acoring===
//     rampMotor.move_velocity(600);
//     pros::delay(1300);
//     rampMotor.move_velocity(0);
    
//     //------------------------------------------------------------------
//     //===Phase 1: first mobile goal===
    
//     move(12,1200);
//     turn(90,1200);

//     move(-14,1500);
//     clamp.set_value(true);
//     rampMotor.move_velocity(-600);
//     pros::delay(500);
//     move(-8,1200);
//     turn(0,1200);
//     intakeMotor.move_velocity(600);
//     rampMotor.move_velocity(600);
    
//     move(22,3000);
//     turn(-90,1200);
//     move(15,2500);
//     move(7,1200);
//     turn(-180,1200);
//     move(35,2500);

//     move(-3,1000);
//     turn(70,1200);
//     move(-12,1200);

//     rampMotor.move_velocity(0);

//     clamp.set_value(false);

//     //------------------------------------------------------------------
//     //===Phase 2: second mobile goal===
//     currentAngle-=10;
//     move(23,1200);
//     turn(-90,1200);
//     move(-50,3000);
    
//     move(-4,750);
//     move(-5,750);
//     clamp.set_value(true);
//     rampMotor.move_velocity(600); 
//     // turn(-60,1200);
//     // move(-50,2000);
//     // clamp.set_value(false);
//     // return;
//     turn(80,1700);
//     move(30,2500);
//     turn(-30,1500);
//     move(-12,1200);
//     clamp.set_value(false);

//     //------------------------------------------------------------------
//     //===Phase 3: third and forth mobile goal===
//     rampMotor.move_velocity(50);
//     move(5,750);
//     turn(-20,1200);
//     move(75,4000);
//     turn(165,2000);
//     move(-25,2500);
//     move(-4,750);
//     move(-4,750);
//     clamp.set_value(true);
//     rampMotor.move_velocity(600);    turn(255,1700);
//     move(-35,3000);
//     clamp.set_value(false);
//     move(16,1700);
//     turn(90,1200);
//     move(-50,1200);
//     move(-5,750);
//     move(-4,750);
//     clamp.set_value(true);
//     turn(120,1200);
//     move(-35,3000);
//     clamp.set_value(false);
//     move(10,1700);










//     // pros::delay(4000);
//     // chassis.setPose(0,0,0);
//     // chassis.turnToHeading(-80,1500,{},f
    
//     // leftWheels.move_velocity(-600);
//     // rightWheels.move_velocity(-600);
//     // pros::delay(3000);
//     // clamp.set_value(false);
//     // pros::delay(400);
//     // leftWheels.move_velocity(300);
//     // rightWheels.move_velocity(300);
//     // pros::delay(4000);
//     // leftWheels.move_velocity(0);
//     // rightWheels.move_velocity(0);
// }