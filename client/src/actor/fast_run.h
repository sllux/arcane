#ifndef ARCANE_CLIENT_SRC_ACTOR_FAST_RUN_H
#define ARCANE_CLIENT_SRC_ACTOR_FAST_RUN_H

#include <configuration/configuration.hpp>

namespace modification::client::actor {
class fast_run {
  using data = configuration::actor::fast_run_data;

 public:
  void process(const data& settings, double& out_run_speed);
};
}  // namespace modification::client::actor

#endif  // ARCANE_CLIENT_SRC_ACTOR_FAST_RUN_H