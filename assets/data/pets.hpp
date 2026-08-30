#pragma once
#include <string_view>
namespace confluxed_assets{inline constexpr std::string_view pets=R"JSON({
    "flickerkit": {
        "name": "Flickerkit",
        "type": "fire",
        "rarity": "common",
        "buffed_stat": 0,
        "move": "flame_burst",
        "description": "A cute kitten made of flickering flames."
    },
    "emberpaw": {
        "name": "Emberpaw",
        "type": "fire",
        "rarity": "uncommon",
        "buffed_stat": 1,
        "move": "fireball",
        "description": "A fiery rabbit whose glowing paws leave embers in every footprint."
    },
    "plasmeow": {
        "name": "Plasmeow",
        "type": "fire",
        "rarity": "rare",
        "buffed_stat": 1,
        "move": "heat_wave",
        "description": "A proud flame-maned lion that can turn a battlefield into a shimmering heat haze."
    },
    "ironpup": {
        "name": "Ironpup",
        "type": "metal",
        "rarity": "common",
        "buffed_stat": 2,
        "move": "iron_spike",
        "description": "A mischievous little puppy with a body of polished iron."
    },
    "shardhound": {
        "name": "Shardhound",
        "type": "metal",
        "rarity": "uncommon",
        "buffed_stat": 3,
        "move": "shard_spray",
        "description": "A loyal hound whose reflective coat sheds razor-sharp splinters."
    },
    "steelmaw": {
        "name": "Steelmaw",
        "type": "metal",
        "rarity": "rare",
        "buffed_stat": 1,
        "move": "knife_storm",
        "description": "A hulking wolf forged of blades and steel."
    },
    "spriglet": {
        "name": "Spriglet",
        "type": "wood",
        "rarity": "common",
        "buffed_stat": 3,
        "move": "splinter",
        "description": "A shy dryad that leaves a trail of fresh green shoots."
    },
    "vinelash": {
        "name": "Vinelash",
        "type": "wood",
        "rarity": "uncommon",
        "buffed_stat": 2,
        "move": "vine_whip",
        "description": "An entity only seen with the trail of foliage that follows its every step."
    },
    "verdantail": {
        "name": "Verdantail",
        "type": "wood",
        "rarity": "rare",
        "buffed_stat": 0,
        "move": "leaf_storm",
        "description": "An ancient equine guardian whose flowing mane is a whirling canopy of leaves."
    },
    "pebblit": {
        "name": "Pebblit",
        "type": "earth",
        "rarity": "common",
        "buffed_stat": 3,
        "move": "pebble_shot",
        "description": "A round little lamb that collects interesting stones in its fur pouch."
    },
    "quakeling": {
        "name": "Quakeling",
        "type": "earth",
        "rarity": "uncommon",
        "buffed_stat": 2,
        "move": "tremor",
        "description": "A sure-footed ram whose every stomp makes the ground hum."
    },
    "cragodon": {
        "name": "Cragodon",
        "type": "earth",
        "rarity": "rare",
        "buffed_stat": 1,
        "move": "boulder_crush",
        "description": "A mountain-backed taurus strong enough to split a cliff with one charge."
    },
    "droplet": {
        "name": "Droplet",
        "type": "water",
        "rarity": "common",
        "buffed_stat": 2,
        "move": "water_jet",
        "description": "A bubbly little fish that can dart through the air on a stream of water."
    },
    "surgefin": {
        "name": "Surgefin",
        "type": "water",
        "rarity": "uncommon",
        "buffed_stat": 0,
        "move": "tidal_wave",
        "description": "A swift dolphin whose fins carry the pull of the tide."
    },
    "leviathan": {
        "name": "Leviathan",
        "type": "water",
        "rarity": "rare",
        "buffed_stat": 3,
        "move": "flood",
        "description": "A colossal deep-water serpent that follows the oldest ocean currents."
    },
    "glimmerflap": {
        "name": "Glimmerflap",
        "type": "light",
        "rarity": "common",
        "buffed_stat": 0,
        "move": "light_beam",
        "description": "A curious chick that shines brightest when someone needs guidance."
    },
    "solavis": {
        "name": "Solavis",
        "type": "light",
        "rarity": "uncommon",
        "buffed_stat": 1,
        "move": "solar_flare",
        "description": "A radiant fox with a warm glow that chases shadows from the wilds."
    },
    "luminar": {
        "name": "Luminar",
        "type": "light",
        "rarity": "rare",
        "buffed_stat": 0,
        "move": "radiant_burst",
        "description": "A winged guardian that scatters brilliant motes with every beat of its wings."
    },
    "photonix": {
        "name": "Photonix",
        "type": "light",
        "rarity": "epic",
        "buffed_stat": 1,
        "move": "photon_bolt",
        "description": "A blazing celestial bird that crosses the sky as a streak of living light."
    },
    "shadelet": {
        "name": "Shadelet",
        "type": "dark",
        "rarity": "common",
        "buffed_stat": 2,
        "move": "void_strike",
        "description": "A tiny feline shaped shadow with no feline casting it."
    },
    "gloamclaw": {
        "name": "Gloamclaw",
        "type": "dark",
        "rarity": "uncommon",
        "buffed_stat": 0,
        "move": "shadow_flux",
        "description": "A silent panther that melts into darkness if you look too closely."
    },
    "dreadfur": {
        "name": "Dreadfur",
        "type": "dark",
        "rarity": "rare",
        "buffed_stat": 3,
        "move": "nightmare",
        "description": "A velvet-furred leopard whose shed furs have been said to cure insomnia."
    },
    "umbrael": {
        "name": "Umbrael",
        "type": "dark",
        "rarity": "epic",
        "buffed_stat": 2,
        "move": "eclipse",
        "description": "A midnight tiger that gathers every nearby shadow beneath its obsidian claws."
    },
    "riftling": {
        "name": "Riftling",
        "type": "space",
        "rarity": "common",
        "buffed_stat": 0,
        "move": "space_rift",
        "description": "A curious creature with no definable shape that pops in and out of reality."
    },
    "orbiton": {
        "name": "Orbiton",
        "type": "space",
        "rarity": "uncommon",
        "buffed_stat": 3,
        "move": "gravity_well",
        "description": "A floating, pure black orb surrounded by floating pebbles pulled from distant worlds."
    },
    "parsecf": {
        "name": "Parsecwyrm",
        "type": "space",
        "rarity": "rare",
        "buffed_stat": 0,
        "move": "space_wormhole",
        "description": "A starlit wyrm parsecs long that coils through wormholes between faraway places."
    },
    "singularis": {
        "name": "Singularis",
        "type": "space",
        "rarity": "epic",
        "buffed_stat": 3,
        "move": "singularity",
        "description": "A dense, dark, winged creature with a tiny galaxy turning at its core."
    },
    "galaxar": {
        "name": "Galaxar",
        "type": "space",
        "rarity": "legendary",
        "buffed_stat": 2,
        "move": "galactic_strike",
        "description": "A cosmic dragon whose constellation-marked hide holds the light of vanished stars."
    },
    "ticktail": {
        "name": "Ticktail",
        "type": "time",
        "rarity": "common",
        "buffed_stat": 0,
        "move": "chronic_chakram",
        "description": "A quick little fox with a clock-face pattern at the tip of its tail."
    },
    "chronohare": {
        "name": "Chronohare",
        "type": "time",
        "rarity": "uncommon",
        "buffed_stat": 2,
        "move": "temporal_loop",
        "description": "A long-eared runner that seems to arrive just before it starts moving."
    },
    "epochwyrm": {
        "name": "Epochwyrm",
        "type": "time",
        "rarity": "rare",
        "buffed_stat": 0,
        "move": "time_wormhole",
        "description": "A serpentine dragon that slips through the seams between one moment and the next."
    },
    "fatespinner": {
        "name": "Fatespinner",
        "type": "time",
        "rarity": "epic",
        "buffed_stat": 0,
        "move": "fortune",
        "description": "A many-legged oracle that weaves glowing threads of possible futures."
    },
    "destinarch": {
        "name": "Destinarch",
        "type": "time",
        "rarity": "legendary",
        "buffed_stat": 0,
        "move": "destiny",
        "description": "An ageless guardian that watches the past and future unfold at once."
    }
}
)JSON";}