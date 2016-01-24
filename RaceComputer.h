#ifndef RaceComputer_h
#define RaceComputer_h

#include <FifoStack.h>

#define PORT 0
#define STBD 1

#define DISPLAY_REFRESH  500 // Milliseconds
#define LOGGING_REFRESH 2000 // Milliseconds

#define SAMPLES 10

class RaceComputer {
 public:
  RaceComputer ();

  float getCurrentTack ();

  float getHeading ();

  float getHeelAngle ();

  float getTrimAngle ();

  float getWindAngle ();

  float getTackingAngle ();

  float getHeadingPort ();

  float getHeadingStbd ();

  float getLatitude ();

  float getLongitude ();

  float getSpeedOverGround ();

  float getCourseOverGround ();

  void updateHeading (float angle);

  void updateHeelAngle (float angle);

  void updateTrimAngle (float angle);

  void updateWindAngle (float angle);

  void updateTackingAngle (float angle);

  void updateLatitude (float _latitude_);

  void updateLongitude (float _longitude_);

  void updateSpeedOverGround (float speed);

  void updateCourseOverGround (float angle);

 protected:

  int currentTack = PORT;

  FifoStack<float, SAMPLES> heading;
  FifoStack<float, SAMPLES> heelAngle;
  FifoStack<float, SAMPLES> trimAngle;

  FifoStack<float, SAMPLES> windAngle;
  FifoStack<float, SAMPLES> tackingAngle;

  FifoStack<float, SAMPLES> latitude;
  FifoStack<float, SAMPLES> longitude;

  FifoStack<float, SAMPLES> speedOverGround;
  FifoStack<float, SAMPLES> courseOverGround;

  template<typename valueType, int stackSize>
  float get (FifoStack<valueType, stackSize> stack);

  template<typename valueType, int stackSize>
  void update (FifoStack<valueType, stackSize> &stack, valueType value);
};

#endif
