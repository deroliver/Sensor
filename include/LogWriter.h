#ifndef LOGWRITER_H_
#define LOGWRITER_H_

#include <fstream>
#include <string>
#include <ctime>
#include "SLevel.h"

using namespace std;

class LogWriter : public ostream {
public:
  // constructors
  LogWriter() {}; // default constructor
  LogWriter(string name, string path); // constructor
  LogWriter(const LogWriter& logWriter); // Copy constructor

  // operator
  LogWriter& operator=(const LogWriter& logWriter);
  bool operator==(const LogWriter& logWriter) const;
  bool operator!=(const LogWriter& logWriter) const;

  // misc
  string getName() { return name; };
  string getTimeAsString();

private:
  string name;
  string path;
}