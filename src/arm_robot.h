#ifndef ARM_ROBOT_H
#define ARM_ROBOT_H
#include <Arduino.h>
#include <Servo.h>

class ArmRobot{
    protected:
    uint16_t aPos=0;
    uint16_t bPos=0;
    uint16_t cPos=0;
    uint16_t dPos=0;
    uint16_t ePos=0;
    uint16_t fPos=0;
    uint16_t dMin = 0;
    uint16_t dMax = 165;
    uint16_t pMin = 550;
    uint16_t pMax = 2400;
    Servo aServo;
    Servo bServo;
    Servo cServo;
    Servo dServo;
    Servo eServo;
    Servo fServo;
    
    uint16_t maxValue(uint16_t aDeg, uint16_t bDeg,uint16_t cDeg, uint16_t dDeg,uint16_t eDeg, uint16_t fDeg);
    void moveCalibarated(Servo &servo, uint16_t degree);
    
    public:
    void begin(uint8_t aPinServo,uint8_t bPinServo,uint8_t cPinServo,uint8_t dPinServo,uint8_t ePinServo,uint8_t fPinServo);
    void moveAll(uint16_t aDeg, uint16_t bDeg,uint16_t cDeg, uint16_t dDeg,uint16_t eDeg, uint16_t fDeg, uint16_t speed);
    void moveInit(uint16_t aDeg, uint16_t bDeg,uint16_t cDeg, uint16_t dDeg,uint16_t eDeg, uint16_t fDeg);
};

#endif