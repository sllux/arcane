#include "vehicle.h"

using namespace modification::client::vehicle;

void vehicle::process() {
}

infinite_nitro::order vehicle::process_infinite_nitro() {
  return infinite_nitro.process(settings.infinite_nitro);
}