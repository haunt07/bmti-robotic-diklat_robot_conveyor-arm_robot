#include <robot_conveyor.h>

ArmRobot arm;
void setup(){
    Serial.begin(115200);
    arm.begin(4,5,6,7,8,9);
    arm.moveInit(165,95,0,90,80,0);
    Serial.println("Inisialisasi sistem");
}

void loop(){
    Serial.println("Gerakan Siku");
    arm.moveAll(165,95,0,0,80,0,20);
    Serial.println("Gerakan Lurus");
    arm.moveAll(165,95,0,90,80,0,20);
    Serial.println("Gerakan Siku Bawah Lambat");
    arm.moveAll(165,95,90,90,80,0,50);
    Serial.println("Gerakan Lurus Bawah Lambat");
    arm.moveAll(165,95,0,90,80,0,50);
    Serial.println("Gerakan Kanan");
    arm.moveAll(120,95,0,0,80,0,20);
    Serial.println("Gerakan Kiri Lambat");
    arm.moveAll(165,95,0,90,80,0,50);
}