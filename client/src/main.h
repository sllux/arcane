#ifndef ARCANE_CLIENT_SRC_CLIENT_H
#define ARCANE_CLIENT_SRC_CLIENT_H

#include "plugin.h"
#include "injection_in_game_logic.h"

namespace modification::client {
class main : public singleton<main> {
  friend class singleton<main>;

  main();
  ~main();

  injection_in_game_logic injection_;

 public:
  std::tuple<bool, shooting::enemy_finder::settings> vector_aimbot_finder_settings(
      const psdk_utils::weapon::mode mode) {
    return {injection_.vector_aimbot.settings[mode].enable,
            injection_.vector_aimbot.get_settings(mode)};
  }
  std::tuple<bool, shooting::enemy_finder::settings> silent_aimbot_finder_settings(
      const psdk_utils::weapon::mode mode) {
    return {injection_.silent_aimbot.settings[mode].enable,
            injection_.silent_aimbot.get_settings(mode)};
  }
};
}  // namespace modification::client

#endif  // ARCANE_CLIENT_SRC_CLIENT_H
