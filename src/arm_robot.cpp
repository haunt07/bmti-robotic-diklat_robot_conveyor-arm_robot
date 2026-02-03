#include "arm_robot.h"

uint16_t ArmRobot::maxValue(uint16_t aDeg, uint16_t bDeg,uint16_t cDeg, uint16_t dDeg,uint16_t eDeg, uint16_t fDeg){
    uint16_t max = aDeg;
    if (bDeg > max){
        max = bDeg;
    }
    if (cDeg > max){
        max = cDeg;
    }
    if (dDeg > max){
        max = dDeg;
    }
    if (eDeg > max){
        max = eDeg;
    }
    if (fDeg > max){
        max = fDeg;
    }
    return max;
}

void ArmRobot::begin(uint8_t aPinServo,uint8_t bPinServo,uint8_t cPinServo,uint8_t dPinServo,uint8_t ePinServo,uint8_t fPinServo){
        aServo.attach(aPinServo,pMin,pMax);
        bServo.attach(bPinServo,pMin,pMax);
        cServo.attach(cPinServo,pMin,pMax);
        dServo.attach(dPinServo,pMin,pMax);
        eServo.attach(ePinServo,pMin,pMax);
        fServo.attach(fPinServo,pMin,pMax);
};
void ArmRobot::moveInit(uint16_t aDeg, uint16_t bDeg,uint16_t cDeg, uint16_t dDeg,uint16_t eDeg, uint16_t fDeg){
        aPos = aDeg;
        bPos = bDeg;
        cPos = cDeg;
        dPos = dDeg;
        ePos = eDeg;
        fPos = fDeg;
        moveAll(aPos,bPos,cPos,dPos,ePos,fPos,1);
}
void ArmRobot::moveAll(uint16_t aDeg, uint16_t bDeg,uint16_t cDeg, uint16_t dDeg,uint16_t eDeg, uint16_t fDeg, uint16_t speed){
    int16_t aDiff=aDeg - aPos;
    int16_t bDiff=bDeg - bPos;
    int16_t cDiff=cDeg - cPos;
    int16_t dDiff=dDeg - dPos;
    int16_t eDiff=eDeg - ePos;
    int16_t fDiff=fDeg - fPos;
    uint16_t maxVal =maxValue(abs(aDiff),abs(bDiff),abs(cDiff),abs(dDiff),abs(eDiff),abs(fDiff));
    int8_t aDir = aDiff < 0 ? -1 : 1;
    int8_t bDir = bDiff < 0 ? -1 : 1;
    int8_t cDir = cDiff < 0 ? -1 : 1;
    int8_t dDir = dDiff < 0 ? -1 : 1;
    int8_t eDir = eDiff < 0 ? -1 : 1;
    int8_t fDir = fDiff < 0 ? -1 : 1;
    uint16_t aMov = 0;
    float aStep = 65535;
    if (aDiff != 0) {
        aStep = float(maxVal) / float(abs(aDiff));
    }
    float aInc = aStep;

    uint16_t bMov = 0;
    float bStep = 65535;
    if (bDiff != 0) {
        bStep = float(maxVal) / float(abs(bDiff));
    }
    float bInc = bStep;

    uint16_t cMov = 0;
    float cStep = 65535;
    if (cDiff != 0) {
        cStep = float(maxVal) / float(abs(cDiff));
    }
    float cInc = cStep;

    uint16_t dMov = 0;
    float dStep = 65535;
    if (dDiff != 0) {
        dStep = float(maxVal) / float(abs(dDiff));
    }
    float dInc = dStep;

    uint16_t eMov = 0;
    float eStep = 65535;
    if (eDiff != 0) {
        eStep = float(maxVal) / float(abs(eDiff));
    }
    float eInc = eStep;

    uint16_t fMov = 0;
    float fStep = 65535;
    if (fDiff != 0) {
        fStep = float(maxVal) / float(abs(fDiff));
    }
    float fInc = fStep;
    
    for (uint16_t iter = 1; iter <= maxVal;iter++){
        if (aInc < iter){
            aInc += aStep;
            aMov += 1;
            moveCalibarated(aServo,(aDir*aMov)+aPos);
        }
        if (bInc < iter){
            bInc += bStep;
            bMov += 1;
            moveCalibarated(bServo,(bDir*bMov)+bPos);
        }
        if (cInc < iter){
            cInc += cStep;
            cMov += 1;
            moveCalibarated(cServo,(cDir*cMov)+cPos);
        }
        if (dInc < iter){
            dInc += dStep;
            dMov += 1;
            moveCalibarated(dServo,(dDir*dMov)+dPos);
        }
        if (eInc < iter){
            eInc += eStep;
            eMov += 1;
            moveCalibarated(eServo,(eDir*eMov)+ePos);
        }
        if (fInc < iter){
            fInc += fStep;
            fMov += 1;
            moveCalibarated(fServo,(fDir*fMov)+fPos);
        }
        delay(speed);
    }
    moveCalibarated(aServo,aDeg);
    moveCalibarated(bServo,bDeg);
    moveCalibarated(cServo,cDeg);
    moveCalibarated(dServo,dDeg);
    moveCalibarated(eServo,eDeg);
    moveCalibarated(fServo,fDeg);
    aPos = aDeg;
    bPos = bDeg;
    cPos = cDeg;
    dPos = dDeg;
    ePos = eDeg;
    fPos = fDeg;
}


void ArmRobot::moveCalibarated(Servo &servo, uint16_t degree){
    uint16_t calibratedValue = map(degree,dMin,dMax,0,180);
    servo.write(calibratedValue);
}