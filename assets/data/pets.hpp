#pragma once
#include <string_view>
#include <array>
namespace confluxed_assets{
    struct pet_data{
        std::string_view id;
        std::string_view name;
        std::string_view type;
        std::string_view rarity;
        std::string_view buffed_stat;
        std::string_view move;
        std::string_view description;
    };
    constexpr pet_data pets[]={
        {"flickerkit","Flickerkit","fire","common","speed","flame_burst","A cute kitten made of flickering flames."},
        {"emberpaw","Emberpaw","fire","uncommon","attack","fireball","A fiery rabbit whose glowing paws leave embers in every footprint."},
        {"plasmeow","Plasmeow","fire","rare","attack","heat_wave","A proud flame-maned lion that can turn a battlefield into a shimmering heat haze."},
        {"ironpup","Ironpup","metal","common","defense","iron_spike","A mischievous little puppy with a body of polished iron."},
        {"shardhound","Shardhound","metal","uncommon","health","shard_spray","A loyal hound whose reflective coat sheds razor-sharp splinters."},
        {"steelmaw","Steelmaw","metal","rare","attack","knife_storm","A hulking wolf forged of blades and steel."},
        {"spriglet","Spriglet","wood","common","health","splinter","A shy dryad that leaves a trail of fresh green shoots."},
        {"vinelash","Vinelash","wood","uncommon","defense","vine_whip","An entity only seen with the trail of foliage that follows its every step."},
        {"verdantail","Verdantail","wood","rare","speed","leaf_storm","An ancient equine guardian whose flowing mane is a whirling canopy of leaves."},
        {"pebblit","Pebblit","earth","common","health","pebble_shot","A round little lamb that collects interesting stones in its fur pouch."},
        {"quakeling","Quakeling","earth","uncommon","defense","tremor","A sure-footed ram whose every stomp makes the ground hum."},
        {"cragodon","Cragodon","earth","rare","attack","boulder_crush","A mountain-backed taurus strong enough to split a cliff with one charge."},
        {"droplet","Droplet","water","common","defense","water_jet","A bubbly little fish that can dart through the air on a stream of water."},
        {"surgefin","Surgefin","water","uncommon","speed","tidal_wave","A swift dolphin whose fins carry the pull of the tide."},
        {"leviathan","Leviathan","water","rare","health","flood","A colossal deep-water serpent that follows the oldest ocean currents."},
        {"glimmerflap","Glimmerflap","light","common","speed","light_beam","A curious chick that shines brightest when someone needs guidance."},
        {"solavis","Solavis","light","uncommon","attack","solar_flare","A radiant fox with a warm glow that chases shadows from the wilds."},
        {"luminar","Luminar","light","rare","speed","radiant_burst","A winged guardian that scatters brilliant motes with every beat of its wings."},
        {"photonix","Photonix","light","epic","attack","photon_bolt","A blazing celestial bird that crosses the sky as a streak of living light."},
        {"shadelet","Shadelet","dark","common","defense","void_strike","A tiny feline shaped shadow with no feline casting it."},
        {"gloamclaw","Gloamclaw","dark","uncommon","speed","shadow_flux","A silent panther that melts into darkness if you look too closely."},
        {"dreadfur","Dreadfur","dark","rare","health","nightmare","A velvet-furred leopard whose shed furs have been said to cure insomnia."},
        {"umbrael","Umbrael","dark","epic","defense","eclipse","A midnight tiger that gathers every nearby shadow beneath its obsidian claws."},
        {"riftling","Riftling","space","common","speed","space_rift","A curious creature with no definable shape that pops in and out of reality."},
        {"orbiton","Orbiton","space","uncommon","health","gravity_well","A floating, pure black orb surrounded by floating pebbles pulled from distant worlds."},
        {"parsecwyrm","Parsecwyrm","space","rare","speed","space_wormhole","A starlit wyrm parsecs long that coils through wormholes between faraway places."},
        {"singularis","Singularis","space","epic","health","singularity","A dense, dark, winged creature with a tiny galaxy turning at its core."},
        {"galaxar","Galaxar","space","legendary","defense","galactic_strike","A cosmic dragon whose constellation-marked hide holds the light of vanished stars."},
        {"ticktail","Ticktail","time","common","speed","chronic_chakram","A quick little fox with a clock-face pattern at the tip of its tail."},
        {"chronohare","Chronohare","time","uncommon","defense","temporal_loop","A long-eared runner that seems to arrive just before it starts moving."},
        {"epochwyrm","Epochwyrm","time","rare","speed","time_wormhole","A serpentine dragon that slips through the seams between one moment and the next."},
        {"fatespinner","Fatespinner","time","epic","speed","fortune","A many-legged oracle that weaves glowing threads of possible futures."},
        {"destinarch","Destinarch","time","legendary","speed","destiny","An ageless guardian that watches the past and future unfold at once."},
    };
}
