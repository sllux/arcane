#include "main.h"

modification::client::main::main() {
#ifdef VMP_DEBUG
  injection_ = std::make_shared<injection_in_game_logic>(
      "neovstan", "5e6ff6c601541e6c7cccac523647b79354f0e745894c3d4b94edc24a396211bc");
#else
  const std::string data{plugin::properties().data()};
  const auto separator = data.find(';');
  if (separator != std::string::npos) {
    const auto username = data.substr(0, separator);
    const auto password = data.substr(separator + 1);
    injection_ = std::make_shared<injection_in_game_logic>(username, password);
  }
#endif

  client_ = std::make_unique<class client>(injection_);
}

modification::client::main::~main() {
}
