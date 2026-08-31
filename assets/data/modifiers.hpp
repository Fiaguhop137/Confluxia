#pragma once
#include <string>
#include <vector>

namespace confluxed_assets {

struct modifier_data {
    std::string id;
    std::vector<std::string> targets;
};

inline const std::vector<modifier_data> modifiers = {
    {"fire", {"metal", "wood", "nexus"}},
    {"metal", {"wood", "earth", "nexus"}},
    {"wood", {"earth", "water", "nexus"}},
    {"earth", {"water", "fire", "nexus"}},
    {"water", {"fire", "metal", "nexus"}},
    {"nexus", {"fire", "metal", "wood", "earth", "water"}},
    {"light", {"dark", "objectivity"}},
    {"dark", {"light", "objectivity"}},
    {"objectivity", {"light", "dark"}},
    {"space", {"time", "axiom"}},
    {"time", {"space", "axiom"}},
    {"axiom", {"space", "time"}},
};

}