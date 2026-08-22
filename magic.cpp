#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <random>
#include <cctype>
#include <fstream>
#include <json.hpp>
using json=nlohmann::json;
using std::cin;
using std::cout;
using std::string;
using std::vector;
using std::unordered_map;
std::random_device rd;
std::mt19937 gen(rd());
const vector<string> basic_powers={"fire","metal","wood","earth","water"};
const vector<string> alignments={"light","dark"};
const vector<string> cosmic_powers={"space","time"};
const vector<string> stat_types={"speed","attack","defense","health"};
struct move {
    string name;
    int damage;
    int cooldown;
    string type;
    string level;
};
unordered_map<string,move>moves;
unordered_map<string,string>power_definitions;
void load_jsons() {
    std::ifstream moves_file("assets/data/moves.json");
    json moves_data=json::parse(moves_file);
    for (const auto& [id,value]:moves_data.items()){moves[id]={value["name"],value["damage"],value["cooldown"],value["type"],value["level"]};}
    std::ifstream power_definitions_file("assets/data/power_definitions.json");
    json power_definitions_data=json::parse(power_definitions_file);
    for (const auto& [id,value]:power_definitions_data.items()){power_definitions[id]=value;}
}
string user_input(string prompt,vector<string>valid_options={}) {
    while(true){
        string response;
        cout<<prompt<<" ";
        if(!valid_options.empty()){
            cout<<"(";
            for(size_t i=0;i<valid_options.size()-1;i++) {
                cout<<valid_options[i];
                if(i<valid_options.size()-2) {
                    cout<<", ";
                }
            }
            cout<<" or "<<valid_options.back()<<") ";
        }
        std::getline(cin, response);
        if(!valid_options.empty()&&find(valid_options.begin(),valid_options.end(),response)==valid_options.end()){
            cout<<"Invalid input. Please choose ";
            for(size_t i=0;i<valid_options.size()-1;i++) {
                cout<<valid_options[i];
                if(i<valid_options.size()-2) {
                    cout<<", ";
                }
            }
            cout<<" or "<<valid_options.back()<<". ";
        }else{
            return(response);
        }
    }
}
struct stat_block {
    int speed;
    int attack;
    int defense;
    int health;
};
struct power_construct {
    string basic;
    string alignment;
    string cosmic;
};
struct enemy {
    string name;
    stat_block stats;
    power_construct powers;
    vector<string> known_moves;
    vector<string> pets;
    unordered_map<string,int>cooldown_times={};
};
struct player {
    string name;
    int rare_traits=0;
    unordered_map<string,int>cooldown_times={};
    vector<string> known_moves;
    vector<string> pets;
    stat_block stats{10,10,10,100};
    power_construct powers;
    player() {
        name=user_input("What would you like to name your character?");
        bool randomize=user_input("Would you like to randomize your character's stats and powers?",{"yes","no"})=="yes";
        if (randomize) {
            vector<string> basic_options={"fire","metal","wood","earth","water","fire","metal","wood","earth","water","nexus"};
            std::uniform_int_distribution<size_t> basic_dist(0,basic_options.size()-1);
            powers.basic=basic_options[basic_dist(gen)];
            vector<string> alignment_options={"light","light","light","light","dark","dark","dark","dark","objectivity"};
            std::uniform_int_distribution<size_t> alignment_dist(0,alignment_options.size()-1);
            powers.alignment=alignment_options[alignment_dist(gen)];
            vector<string> cosmic_options={"space","space","space","space","space","time","time","time","time","time","axiom"};
            std::uniform_int_distribution<size_t> cosmic_dist(0,cosmic_options.size()-1);
            powers.cosmic=cosmic_options[cosmic_dist(gen)];
        }else{
            powers.basic=user_input("What would you like your character's basic power to be?",basic_powers);
            powers.alignment=user_input("What would you like your character's alignment to be?",alignments);
            powers.cosmic=user_input("What would you like your character's cosmic power to be?",cosmic_powers);
        }
        std::vector<std::string> basic_starter_moves={"flame_burst", "iron_spike", "splinter", "pebble_shot", "water_jet"};
        auto basic_it=std::find(basic_powers.begin(),basic_powers.end(),powers.basic);
        size_t index=basic_it-basic_powers.begin();
        if(index<basic_starter_moves.size()){known_moves.push_back(basic_starter_moves[index]);} 
        else{known_moves.insert(known_moves.end(),basic_starter_moves.begin(),basic_starter_moves.end());}
        std::vector<std::string> alignment_starter_moves={"light_beam", "void_strike"};
        auto alignment_it=std::find(alignments.begin(),alignments.end(),powers.alignment);
        index=alignment_it-alignments.begin();
        if(index<alignment_starter_moves.size()){known_moves.push_back(alignment_starter_moves[index]);} 
        else{known_moves.insert(known_moves.end(),alignment_starter_moves.begin(),alignment_starter_moves.end());}
        std::vector<std::string> cosmic_starter_moves={"space_rift", "chronic_chakram"};
        auto cosmic_it=std::find(cosmic_powers.begin(),cosmic_powers.end(),powers.cosmic);
        index=cosmic_it-cosmic_powers.begin();
        if(index<cosmic_starter_moves.size()){known_moves.push_back(cosmic_starter_moves[index]);} 
        else{known_moves.insert(known_moves.end(),cosmic_starter_moves.begin(),cosmic_starter_moves.end());}
        if (powers.basic=="nexus"){rare_traits++;}
        if (powers.alignment=="objectivity"){rare_traits++;}
        if (powers.cosmic=="axiom"){rare_traits++;}
    }
};
string get_lore(const player&player){
    string lore="";
    string basic_power_upper=player.powers.basic;
    basic_power_upper[0]=std::toupper(basic_power_upper[0]);
    string alignment_power_upper=player.powers.alignment;
    alignment_power_upper[0]=std::toupper(alignment_power_upper[0]);
    string cosmic_power_upper=player.powers.cosmic;
    cosmic_power_upper[0]=std::toupper(cosmic_power_upper[0]);
    if(player.rare_traits==0){
        lore+="You have the power of "+player.powers.basic+". "+basic_power_upper+" is "+power_definitions.at(player.powers.basic)+" \n";
        lore+="You have the power of "+player.powers.alignment+". "+alignment_power_upper+" is "+power_definitions.at(player.powers.alignment)+" \n";
        lore+="You have the power of "+player.powers.cosmic+". "+cosmic_power_upper+" is "+power_definitions.at(player.powers.cosmic)+" ";
    }else if(player.rare_traits==1){
        if(player.powers.basic=="nexus"){
            lore+="You are the Nexus. You are a rare convergence of every elemental force, a being born with the power to command fire, metal, wood, earth, water, and forces beyond the natural world. Legends speak of the Nexus as a chosen one destined to appear when the balance of the elements is threatened, wielding powers that no ordinary warrior could ever hope to master. You stand at the center of every elemental conflict, capable of turning the strengths of one element against the weaknesses of another. With such power comes an equally great responsibility, for the fate of the land may rest upon your choices. Whether you become its greatest protector or its greatest threat is yours to decide. \n";
            lore+="You have the power of "+player.powers.alignment+". "+alignment_power_upper+" is "+power_definitions.at(player.powers.alignment)+" \n";
            lore+="You have the power of "+player.powers.cosmic+". "+cosmic_power_upper+" is "+power_definitions.at(player.powers.cosmic)+" ";
        }
        else if(player.powers.alignment=="objectivity"){
            lore+="You have the power of "+player.powers.basic+". "+basic_power_upper+" is "+power_definitions.at(player.powers.basic)+" \n";
            lore+="You are Objectivity. You have transcended the opposing forces of light and darkness, standing beyond the endless struggle between them. Where others see good and evil, you see only what is, and your mind is untouched by the illusions and biases that cloud the judgment of ordinary beings. Ancient legends tell of those who achieve Objectivity becoming impartial arbiters of the world, able to perceive truths hidden from even the most powerful beings. You are not bound to light, nor are you consumed by darkness. You exist between them, observing the world with perfect clarity and wielding the power to determine its fate without being swayed by either side. The world may call you a savior, a monster, or something beyond either, but your judgment alone will decide what you become. \n";
            lore+="You have the power of "+player.powers.cosmic+". "+cosmic_power_upper+" is "+power_definitions.at(player.powers.cosmic)+" ";
    }
        else{
            lore+="You have the power of "+player.powers.basic+". "+basic_power_upper+" is "+power_definitions.at(player.powers.basic)+" \n";
            lore+="You have the power of "+player.powers.alignment+". "+alignment_power_upper+" is "+power_definitions.at(player.powers.alignment)+" \n";
            lore+="You are the Axiom. You possess a power that exists beyond space, beyond time, and beyond the limits of ordinary reality. While others manipulate the laws of the universe, you possess the ability to perceive and influence the fundamental principles upon which those laws are built. Ancient scholars believed that the Axiom was not merely a being who could control reality, but a living embodiment of the truths that govern existence itself. Space bends, time yields, and the impossible becomes possible in your presence. Yet such power comes with a terrifying realization: if the laws of reality can be changed, then nothing is truly permanent. You have been given the power to rewrite the rules by which the world exists, and whether you use that power to preserve creation, reshape it, or bring about something entirely new is a choice that only you can make. ";
        }
    }else if(player.rare_traits==2){
        if(player.powers.basic=="nexus"){
            if(player.powers.alignment=="objectivity"){
                lore+="You are the Nexus of Objectivity. You command every elemental force while remaining untouched by the conflict between light and darkness. You see every element not as opposing forces, but as pieces of a greater whole, allowing you to wield them with unparalleled precision. Those who encounter you speak of a being who cannot be deceived by either side, for you understand the world without judgment and command its elements without limitation. You are not merely the master of the elements. You are the balance between them. \n";
                lore+="You have the power of "+player.powers.cosmic+". "+cosmic_power_upper+" is "+power_definitions.at(player.powers.cosmic)+" ";
            }else{
                lore+="You have the power of "+player.powers.alignment+". "+alignment_power_upper+" is "+power_definitions.at(player.powers.alignment)+" \n";
                lore+="You are the Nexus of Axiom. Every element answers to your will, but your power extends beyond the elements themselves. You perceive the fundamental rules that govern reality and possess the ability to bend them to your purpose. Fire, earth, water, metal, and every force between them become mere expressions of a deeper power that you alone can command. Legends once claimed that no being could master both the elements and the laws of existence, but you have proven those legends wrong. You do not merely control the world. You understand how it works. ";
            }
        }else{
            lore+="You have the power of "+player.powers.basic+". "+basic_power_upper+" is "+power_definitions.at(player.powers.basic)+" \n";
            lore+="You are the Axiom of Objectivity. You stand beyond the struggle between light and darkness and possess the ability to perceive reality exactly as it is. Your mind is untouched by illusion, bias, or deception, allowing you to comprehend truths that would shatter the minds of ordinary beings. Beyond this perfect perception lies an even greater power: the ability to influence the fundamental laws of reality itself. You do not choose between opposing forces, nor do you obey the rules that bind them. You simply observe the truth, understand it, and decide what the truth should become. ";
        }
    }else{lore+="Legend has it that one in a thousand people are born as the Absolute. You are one of them. You possess the power of the Nexus, the clarity of Objectivity, and the authority of the Axiom. Every element lies within your command, neither light nor darkness can sway your judgment, and the fundamental laws of reality are open to your understanding. You are not bound by the forces that govern ordinary beings because you stand above them, able to command the elements, perceive the truth, and reshape reality itself. Ancient civilizations could only speculate about such a being, believing that the convergence of these powers was impossible. Yet you exist, and the world now faces a question that has never had an answer: what does a being with no limits choose to do with them? ";}
    return lore;
}
void attack(player& attacker,enemy& attackee,string attacking_move){
    attacker.cooldown_times[attacking_move]=moves.at(attacking_move).cooldown;
    attackee.stats.health-=moves.at(attacking_move).damage*attacker.stats.attack/attackee.stats.defense;
}
void attack(enemy& attacker,player& attackee,string attacking_move){
    attacker.cooldown_times[attacking_move]=moves.at(attacking_move).cooldown;
    attackee.stats.health-=moves.at(attacking_move).damage*attacker.stats.attack/attackee.stats.defense;
}
bool battle_loop(bool turn,player& player,enemy& enemy){
    if(turn){
        string action="see moves";
        while(action=="see moves"){
            action=user_input(string("You have "+std::to_string(player.stats.speed)+" SPD, "+std::to_string(player.stats.attack)+" ATK, "+std::to_string(player.stats.defense)+" DFN, "+std::to_string(player.stats.health)+" HLT\nWhat would you like to do?"),{"use move", "see moves"});
            vector<string> available_moves;
            for(size_t i=0;i<player.known_moves.size();++i){if (player.cooldown_times.find(player.known_moves[i])==player.cooldown_times.end()){available_moves.push_back(player.known_moves[i]);}}
            if(action=="see moves"){
                cout<<"You can use the following moves: \n";
                for (size_t i=0;i<available_moves.size();++i){
                    string cooldown;
                    if(moves.at(available_moves[i]).cooldown==1){cooldown="no";}
                    else{cooldown=std::to_string(moves.at(available_moves[i]).cooldown-1)+"-turn";}
                    cout<<moves.at(available_moves[i]).name<<": "<<moves.at(available_moves[i]).damage<<" damage, "<<cooldown<<" cooldown \n";
                }
            }else{
                unordered_map<string,string> move_lookup;
                for(const auto& move_id:available_moves){move_lookup[moves.at(move_id).name]=move_id;}
                vector<string> available_move_names;
                for(const auto& pair:move_lookup){available_move_names.push_back(pair.first);}
                string move_to_use=user_input("What move would you like to use?",{available_move_names});
                attack(player,enemy,move_lookup[move_to_use]);
            }
        }
        for (auto it=player.cooldown_times.begin();it!=player.cooldown_times.end();){
            it->second--;
            if (it->second<=0) {
                it=player.cooldown_times.erase(it);
            }else{
                ++it;
            }
        }
    }else{
        //enemy logic or something idk
    }
    return !turn;
}
int main() {
    load_jsons();
    cout<<"Welcome to the game! You are a player in a world of magic and adventure. You will be able to choose your character's stats and powers, and then embark on a journey to defeat the evil forces that threaten the land. \n";
    player player;
    cout<<player.name<<" has been created with the following stats: \n";
    cout<<"Attack: "<<player.stats.attack<<" \n";
    cout<<"Speed: "<<player.stats.speed<<" \n";
    cout<<"Defense: "<<player.stats.defense<<" \n";
    cout<<"Health: "<<player.stats.health<<" \n";
    cout<<get_lore(player)<<"\n";
    cout<<"You are now ready to embark on your journey. Good luck, and may the forces of magic be with you! \n";
    enemy bob{"bob",{10,10,10,100},{},{},{},{}};
    std::uniform_int_distribution<size_t> basic_dist(0,basic_powers.size()-1);
    bob.powers.basic=basic_powers[basic_dist(gen)];
    std::uniform_int_distribution<size_t> alignment_dist(0,alignments.size()-1);
    bob.powers.alignment=alignments[alignment_dist(gen)];
    std::uniform_int_distribution<size_t> cosmic_dist(0,cosmic_powers.size()-1);
    bob.powers.cosmic=cosmic_powers[cosmic_dist(gen)];
    std::bernoulli_distribution randbool(0.5);
    for (const auto& [id,val]:moves) {
        if(val.type==bob.powers.basic||val.type==bob.powers.alignment||val.type==bob.powers.cosmic){
            if(randbool(gen)){
                bob.known_moves.push_back(id);
            }
        }
    }
    if(bob.known_moves.empty()){
        for (const auto& [id,val]:moves) {
            if(val.type==bob.powers.basic||val.type==bob.powers.alignment||val.type==bob.powers.cosmic){
                bob.known_moves.push_back(id);
            }
        }
    }
    battle_loop(true,player,bob);
    return 0;
}