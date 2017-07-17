#ifndef SENSOR_H_
#define SENSOR_H_

#include "SensorType.h"
#include "DataBuffer.h"

class Sensor {
public:
  // default constructor
  Sensor() {}

  // getter and setter
  void setSensorType(SensorType *value) { _sensorType = value; };
  SensorType* getSensorType() { return _sensorType; };

  // measuring
  DataBuffer readSensor();

private:
  SensorType *_sensorType
};

#endif