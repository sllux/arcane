#ifndef ARCANE_CLIENT_SRC_SHOOTING_VECTOR_AIMBOT_H
#define ARCANE_CLIENT_SRC_SHOOTING_VECTOR_AIMBOT_H

#include <psdk_utils/psdk_utils.h>

#include <arcane_packets/configuration.hpp>
#include <nlohmann/json.hpp>
#include <unordered_map>

#include "enemy_finder.h"

namespace modification::client::shooting {
class vector_aimbot {
 public:
  vector_aimbot();

  void process();
  enemy_finder::settings get_settings(psdk_utils::weapon::mode number);

 public:
  std::vector<packets::configuration::model_group> model_groups;
  std::vector<std::string> friendly_nicknames;
  std::unordered_map<psdk_utils::weapon::mode, packets::configuration::vector_aimbot> settings;

 private:
  std::unordered_map<psdk_utils::weapon::mode, enemy_finder> finder_;
  bool use_target_range_instead_of_weapons_;
};

}  // namespace modification::client::shooting

#endif  // ARCANE_CLIENT_SRC_SHOOTING_VECTOR_AIMBOT_H
