#ifndef SENSORTYPE_H
#define SENSORTYPE_H_

#include "DataBuffer.h"


// An interface that outsources the readSensor function from Sensor
class SensorType {
public:
  SensorType() {};
  virtual DataBuffer readSensor() = 0;
};

#endif