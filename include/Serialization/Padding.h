// Copyright 2021 the Drakhtar authors. All rights reserved. MIT license.

#pragma once
#include <string>

struct Padding {
  std::string outter{};
  std::string inner{};

  Padding() : outter(""), inner("  ") {}
  Padding(size_t padding)
      : outter(std::string(padding, ' ')),
        inner(std::string(padding + 2, ' ')) {}
  Padding(std::string padding) : outter(padding), inner(padding + "  ") {}
};
