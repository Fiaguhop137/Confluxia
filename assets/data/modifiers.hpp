#pragma once

#include <string_view>

namespace confluxed_assets{

inline constexpr std::string_view modifiers=R"JSON({
    "fire":["metal","wood"],
    "metal":["wood","earth"],
    "wood":["earth","water"],
    "earth":["water","fire"],
    "water":["fire","metal"],
    "nexus":["fire","metal","wood","earth","water"],
    "light":["dark"],
    "dark":["light"],
    "objectivity":["light","dark"],
    "space":["time"],
    "time":["space"],
    "axiom":["space","time"],
    "":[]
})JSON";

}
