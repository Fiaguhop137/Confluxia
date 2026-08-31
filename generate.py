
#!/usr/bin/env python3

import json
import re
from pathlib import Path


ROOT = Path("/home/firebot/git/Confluxia")
ASSET_DIR = ROOT / "assets" / "data"
OUTPUT_DIR = ASSET_DIR / "generated"


def extract_json(path: Path) -> dict:
    text = path.read_text(encoding="utf-8")

    match = re.search(
        r'R"JSON\((.*?)\)JSON"',
        text,
        re.DOTALL,
    )

    if not match:
        raise RuntimeError(f"Could not find embedded JSON in {path}")

    return json.loads(match.group(1))


def cpp_string(value: str) -> str:
    # JSON strings are decoded by Python first, then safely escaped
    # for use as C++ string literals.
    return (
        value
        .replace("\\", "\\\\")
        .replace('"', '\\"')
        .replace("\n", "\\n")
        .replace("\r", "\\r")
        .replace("\t", "\\t")
    )


def generate_moves(data: dict) -> str:
    lines = [
        "#pragma once",
        "#include <string_view>",
        "",
        "namespace confluxed_assets {",
        "",
        "struct move_data {",
        "    std::string_view id;",
        "    std::string_view name;",
        "    int damage;",
        "    int cooldown;",
        "    std::string_view type;",
        "    std::string_view level;",
        "};",
        "",
        "inline constexpr move_data moves[] = {",
    ]

    for move_id, move in data.items():
        lines.append(
            f'    {{"{cpp_string(move_id)}", '
            f'"{cpp_string(move["name"])}", '
            f'{move["damage"]}, '
            f'{move["cooldown"]}, '
            f'"{cpp_string(move["type"])}", '
            f'"{cpp_string(move["level"])}"}},'
        )

    lines += [
        "};",
        "",
        "}",
        "",
    ]

    return "\n".join(lines)


def generate_pets(data: dict) -> str:
    lines = [
        "#pragma once",
        "#include <string_view>",
        "",
        "namespace confluxed_assets {",
        "",
        "struct pet_data {",
        "    std::string_view id;",
        "    std::string_view name;",
        "    std::string_view type;",
        "    std::string_view rarity;",
        "    int buffed_stat;",
        "    std::string_view move;",
        "    std::string_view description;",
        "};",
        "",
        "inline constexpr pet_data pets[] = {",
    ]

    for pet_id, pet in data.items():
        lines.append(
            f'    {{"{cpp_string(pet_id)}", '
            f'"{cpp_string(pet["name"])}", '
            f'"{cpp_string(pet["type"])}", '
            f'"{cpp_string(pet["rarity"])}", '
            f'{pet["buffed_stat"]}, '
            f'"{cpp_string(pet["move"])}", '
            f'"{cpp_string(pet["description"])}"}},'
        )

    lines += [
        "};",
        "",
        "}",
        "",
    ]

    return "\n".join(lines)


def generate_lore(data: dict) -> str:
    lines = [
        "#pragma once",
        "#include <string_view>",
        "",
        "namespace confluxed_assets {",
        "",
        "struct lore_data {",
        "    std::string_view id;",
        "    std::string_view text;",
        "};",
        "",
        "inline constexpr lore_data lore[] = {",
    ]

    for lore_id, text in data.items():
        lines.append(
            f'    {{"{cpp_string(lore_id)}", '
            f'"{cpp_string(text)}"}},'
        )

    lines += [
        "};",
        "",
        "}",
        "",
    ]

    return "\n".join(lines)


def generate_modifiers(data: dict) -> str:
    lines = [
        "#pragma once",
        "#include <string_view>",
        "",
        "namespace confluxed_assets {",
        "",
        "struct modifier_data {",
        "    std::string_view id;",
        "    std::string_view target;",
        "};",
        "",
        "inline constexpr modifier_data modifiers[] = {",
    ]

    for modifier_id, targets in data.items():
        for target in targets:
            lines.append(
                f'    {{"{cpp_string(modifier_id)}", '
                f'"{cpp_string(target)}"}},'
            )

    lines += [
        "};",
        "",
        "}",
        "",
    ]

    return "\n".join(lines)


def generate():
    OUTPUT_DIR.mkdir(parents=True, exist_ok=True)

    generators = {
        "moves.hpp": generate_moves,
        "pets.hpp": generate_pets,
        "lore.hpp": generate_lore,
        "modifiers.hpp": generate_modifiers,
    }

    for filename, generator in generators.items():
        source = ASSET_DIR / filename

        if not source.exists():
            raise FileNotFoundError(f"Missing asset: {source}")

        data = extract_json(source)
        output = generator(data)

        destination = OUTPUT_DIR / filename
        destination.write_text(output, encoding="utf-8")

        print(f"Generated {destination.relative_to(ROOT)}")


if __name__ == "__main__":
    generate()

