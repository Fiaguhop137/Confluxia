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
        {"flickerkit","Flickerkit","fire","common","speed","flame_burst","kitten made of flickering flames. It zooms around, leaving a trail of sparks in its wake."},
        {"emberpaw","Emberpaw","fire","uncommon","attack","fireball","rabbit whose glowing paws leave embers in every footprint. It's powerful hind legs leave a trail of burning pawprints."},
        {"plasmeow","Plasmeow","fire","rare","attack","heat_wave","lion, flame-maned and proud, that can turn an entire battlefield into a shimmering heat haze with its fiery breath."},
        {"ironpup","Ironpup","metal","common","defense","iron_spike","puppy with a body of polished iron. The mischievous little creature is nearly bulletproof, but its shiny coat is a bit of a giveaway."},
        {"shardhound","Shardhound","metal","uncommon","health","shard_spray","hound whose reflective coat sheds razor-sharp splinters. It will loyally protect its master, even if it means getting a few dents itself."},
        {"steelmaw","Steelmaw","metal","rare","attack","knife_storm","wolf forged of blades and steel. It's hulking frame is covered in jagged edges, and its jaws are a whirling storm of serrated knives."},
        {"spriglet","Spriglet","wood","common","health","splinter","dryad that leaves a trail of fresh green shoots. While shy at first, it will grow to trust its master and protect them with it's own life force."},
        {"vinelash","Vinelash","wood","uncommon","defense","vine_whip","pet. This entity is only seen with the trail of foliage that follows its every step. It camouflages so well nobody truly knows what they look like."},
        {"verdantail","Verdantail","wood","rare","speed","leaf_storm","equine guardian, whose flowing mane is a whirling canopy of leaves. While plantlike and ancient in appearance, it can gallop at speeds that rival the wind."},
        {"pebblit","Pebblit","earth","common","health","pebble_shot","lamb that collects interesting stones in its fur pouch. Its round, soft, body, and gentle, generous nature make it a favorite among children and elderly."},
        {"quakeling","Quakeling","earth","uncommon","defense","tremor","ram whose every stomp makes the ground hum. Sure-footed and strong, it's rock hard hooves can withstand the most violent of earthquakes without faltering."},
        {"cragodon","Cragodon","earth","rare","attack","boulder_crush","crocodile strong enough to split a cliff with swing of its tail. Its atlas like jaws can crush boulders with ease."},
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
