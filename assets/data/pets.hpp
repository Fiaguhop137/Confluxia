#pragma once
#include <string_view>
#include <array>
namespace confluxed_assets{
    struct pet_data{
        std::string_view id;
        std::string_view name;
        std::string_view type;
        std::string_view rarity;
        int buffed_stat;
        std::string_view move;
        std::string_view description;
    };
    inline constexpr pet_data pets[]={
        {"flickerkit","Flickerkit","fire","common",0,"flame_burst","A cute kitten made of flickering flames."},
        {"emberpaw","Emberpaw","fire","uncommon",1,"fireball","A fiery rabbit whose glowing paws leave embers in every footprint."},
        {"plasmeow","Plasmeow","fire","rare",1,"heat_wave","A proud flame-maned lion that can turn a battlefield into a shimmering heat haze."},
        {"ironpup","Ironpup","metal","common",2,"iron_spike","A mischievous little puppy with a body of polished iron."},
        {"shardhound","Shardhound","metal","uncommon",3,"shard_spray","A loyal hound whose reflective coat sheds razor-sharp splinters."},
        {"steelmaw","Steelmaw","metal","rare",1,"knife_storm","A hulking wolf forged of blades and steel."},
        {"spriglet","Spriglet","wood","common",3,"splinter","A shy dryad that leaves a trail of fresh green shoots."},
        {"vinelash","Vinelash","wood","uncommon",2,"vine_whip","An entity only seen with the trail of foliage that follows its every step."},
        {"verdantail","Verdantail","wood","rare",0,"leaf_storm","An ancient equine guardian whose flowing mane is a whirling canopy of leaves."},
        {"pebblit","Pebblit","earth","common",3,"pebble_shot","A round little lamb that collects interesting stones in its fur pouch."},
        {"quakeling","Quakeling","earth","uncommon",2,"tremor","A sure-footed ram whose every stomp makes the ground hum."},
        {"cragodon","Cragodon","earth","rare",1,"boulder_crush","A mountain-backed taurus strong enough to split a cliff with one charge."},
        {"droplet","Droplet","water","common",2,"water_jet","A bubbly little fish that can dart through the air on a stream of water."},
        {"surgefin","Surgefin","water","uncommon",0,"tidal_wave","A swift dolphin whose fins carry the pull of the tide."},
        {"leviathan","Leviathan","water","rare",3,"flood","A colossal deep-water serpent that follows the oldest ocean currents."},
        {"glimmerflap","Glimmerflap","light","common",0,"light_beam","A curious chick that shines brightest when someone needs guidance."},
        {"solavis","Solavis","light","uncommon",1,"solar_flare","A radiant fox with a warm glow that chases shadows from the wilds."},
        {"luminar","Luminar","light","rare",0,"radiant_burst","A winged guardian that scatters brilliant motes with every beat of its wings."},
        {"photonix","Photonix","light","epic",1,"photon_bolt","A blazing celestial bird that crosses the sky as a streak of living light."},
        {"shadelet","Shadelet","dark","common",2,"void_strike","A tiny feline shaped shadow with no feline casting it."},
        {"gloamclaw","Gloamclaw","dark","uncommon",0,"shadow_flux","A silent panther that melts into darkness if you look too closely."},
        {"dreadfur","Dreadfur","dark","rare",3,"nightmare","A velvet-furred leopard whose shed furs have been said to cure insomnia."},
        {"umbrael","Umbrael","dark","epic",2,"eclipse","A midnight tiger that gathers every nearby shadow beneath its obsidian claws."},
        {"riftling","Riftling","space","common",0,"space_rift","A curious creature with no definable shape that pops in and out of reality."},
        {"orbiton","Orbiton","space","uncommon",3,"gravity_well","A floating, pure black orb surrounded by floating pebbles pulled from distant worlds."},
        {"parsecwyrm","Parsecwyrm","space","rare",0,"space_wormhole","A starlit wyrm parsecs long that coils through wormholes between faraway places."},
        {"singularis","Singularis","space","epic",3,"singularity","A dense, dark, winged creature with a tiny galaxy turning at its core."},
        {"galaxar","Galaxar","space","legendary",2,"galactic_strike","A cosmic dragon whose constellation-marked hide holds the light of vanished stars."},
        {"ticktail","Ticktail","time","common",0,"chronic_chakram","A quick little fox with a clock-face pattern at the tip of its tail."},
        {"chronohare","Chronohare","time","uncommon",2,"temporal_loop","A long-eared runner that seems to arrive just before it starts moving."},
        {"epochwyrm","Epochwyrm","time","rare",0,"time_wormhole","A serpentine dragon that slips through the seams between one moment and the next."},
        {"fatespinner","Fatespinner","time","epic",0,"fortune","A many-legged oracle that weaves glowing threads of possible futures."},
        {"destinarch","Destinarch","time","legendary",0,"destiny","An ageless guardian that watches the past and future unfold at once."},
    };
    inline constexpr std::array<std::string_view,4> stat_types={"speed","attack","defense","health"};
}
