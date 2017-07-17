#ifndef DBINTERFACE_H_
#define DBINTERFACE_H_

#include <QStringList>

#include <QString>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

#include <sstream>
#include <algorithm>
#include <iomanip>

#include "DataBuffer.h"
#include "Config.h"
#include "LogWriter.h"
#include "HTTPRequest.h"


class DBInterface {
public:
  static DBInterface& getInstance() {
    static DBInterface _instance;
    return _instance;
  }
  ~DBInterface() {}

  void               init ();
  void               writeToDataBase  ( DataBuffer &dataBuffer );
  vector<DataBuffer> readFromDataBase ( DataBuffer& dataBuffer );
  void               writeStatusOK    ( bool statusOK );
  bool               readStatusOK     ();
  bool               getDBFailure     ();

private:
  DBInterface() {};

  DBInterface(const DBInterface& dbInterface);
  DBInterface& operator=(const DBInterface& dbInterface);

  void createIfNotCreatedDataBase();
  void setDBFailure(bool val) { dbFailure = val; };
  bool dbFailure = false;
  LogWriter log;

  string cleanString(const string& stringToClean);
  double cutValueToInfluxDBRange(doube val);
  string deletePaddingZeros(const string& stringWithPaddingZeros);
  string cTimeToString(struct tm datetime, bool inUnixTime);
  struct tm stringToCTime(const string& dateTimeString);
  struct tm getCurrentDateTime(bool cutToHours = true);
  int getCurrentDateTimeAsUnixTime(bool cutToHours = true);
  vector<DataBuffer> jsonToDataBufferVector(const string& json, const string &dataSource);
};

#endif