#ifndef SLEVEL_H_
#define SLEVEL_H_

// Declare in order to avoid include problems
class LogWriter;

#include <string>
#include "LogWriter.h"

using namespace std;

enum SeverityLevel { EMERGENCY, CRITICAL, ERROR, WARNING, NOTICE, INFO, DEBUG };

class SLevel {
public:
  SLevel(SeverityLevel severityLevel) { _severityLevel = severityLevel; }

  // getters
  SeverityLevel getSeverityLevel () const { return severityLevel; }
  string getSeverityLevelAsString() const { return severityLevelToString(getSeverityLevel()); }

  friend LogWriter& operator<<(LogWriter& logWriter, const SLevel severityLevel);

private:
  SeverityLevel severityLevel;
  sring severityLevelToString(SeverityLevel severityLevel) const;
};

#endif