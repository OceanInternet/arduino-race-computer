#include <RaceComputer.h>

float RaceComputer::getCurrentTack () {

  return currentTack;
}

float RaceComputer::getHeading () {

  return get(heading);
}

float RaceComputer::getHeelAngle () {

  return get(heelAngle);
}

float RaceComputer::getTrimAngle () {

  return get(trimAngle);
}

float RaceComputer::getWindAngle () {

  return get(windAngle);
}

float RaceComputer::getTackingAngle () {

  return get(tackingAngle);
}

float RaceComputer::getHeadingPort () {
  
  float heading = getHeading ();
  float tackingAngle = getTackingAngle ();

  return heading + (tackingAngle/2);
}

float RaceComputer::getHeadingStbd () {

  float heading = getHeading ();
  float tackingAngle = getTackingAngle ();

  return heading - (tackingAngle/2);
}

float RaceComputer::getLatitude () {

  return get(latitude);
}

float RaceComputer::getLongitude () {

  return get(longitude);
}

float RaceComputer::getSpeedOverGround () {

  return get(speedOverGround);
}

float RaceComputer::getCourseOverGround () {

  return get(courseOverGround);
}

void RaceComputer::updateHeading (float angle) {
  update (heading, angle);
}

void RaceComputer::updateHeelAngle (float angle) {
  update (heelAngle, angle);
}

void RaceComputer::updateTrimAngle (float angle) {
  update(trimAngle, angle);
}

void RaceComputer::updateWindAngle (float angle) {
  update(windAngle, angle);
}

void RaceComputer::updateTackingAngle (float angle) {
  update(tackingAngle, angle);
}

void RaceComputer::updateLatitude (float _latitude_) {
  update (latitude, _latitude_);
}

void RaceComputer::updateLongitude (float _longitude_) {
  update (longitude, _longitude_);
}

void RaceComputer::updateSpeedOverGround (float speed) {
  update(speedOverGround, speed);
}

void RaceComputer::updateCourseOverGround (float angle) {
  update(courseOverGround, angle);
}

template<typename valueType, int stackSize>
float RaceComputer::get (FifoStack<valueType, stackSize> stack) {

  return stack.getAverage ();
}

template<typename valueType, int stackSize>
void RaceComputer::update (FifoStack<valueType, stackSize> &stack, valueType value)
{
  stack.update (value);
}
