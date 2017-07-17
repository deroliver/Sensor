#ifndef CONFIG_H
#define CONFIG_H_

#include <string>
#include <float.h>

using namespace std;

const string URL_OF_DATABASE  = "http://localhost:8086";
const string NAME_OF_DATABASE = "WeatherData2";
const string PATH_OF_LOGFILE  = "LogFile.txt";
const double INFLUXDB_MAX     = 1.79769e+308;
const double INFLUXDB_MIN     = -1.79769e+308;
const int    PIN_OF_DS18B20   = 21;

#endif