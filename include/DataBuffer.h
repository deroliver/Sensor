#ifndef DATABUFFER_H_
#define DATABUFFER_H_

#include <map>
#include <iostring>
#include <iostream>
#include <time.h>

using namespace std;


// The data exchange interface
// Provides data which can be used by two software modules to exchange data
struct DataBuffer {
  // dateTime
  bool useDateTimes = false;
  struct tm startDateTime;
  struct tm endDateTime;

  // data-source
  string dataSource;
  bool useDataSource = false;

  // data-content
  map<string, double> data;

  // operators
  bool operator== (DataBuffer& other);
  friend ostream& operator<<(ostream& oStream, DataBuffer dataBuffer);

  // misc
  bool compareCTimeEqual(struct tm time1, struct tm time2);
};

// Provides information about the content within a data buffer
struct DataBufferProperties {
  double minValue;
  double maxValue;
  string unitOfMeasure;
};

// Stores info about the range and unit of measure of the values within the
// DataBuffer struct
const map<string, DataBufferProperties> possibleDataBufferValues = {
  {"Temperature",{   0,   10, "Degree Celsius"}},
  {"Airpressure",{ 800, 1200, "Hektopascale"  }}
};

#endif


