#pragma once

/*
The clock handles timing. All methods return in microseconds
*/
namespace df {
  class Clock {
    public:
      Clock(); // ctor, sets previous_time to current time
      long int delta(); // returns microseconds since last call, saving result
      long int split() const; // returns microseconds since last call, not saving result

    private:
      long int previous_time;
      long int getCurrentTime() const;
  };
}
