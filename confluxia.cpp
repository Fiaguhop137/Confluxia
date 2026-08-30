#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <random>
#include <cctype>
#include <cmath>
#include <fstream>
#include <thread>
#include <chrono>
#include "assets/json.hpp"
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
unordered_map<string,move> load_moves() {
    unordered_map<string,move>result;
    std::ifstream file("assets/data/moves.json");
    json data=json::parse(file);
    for (const auto& [id,value]:data.items()){result[id]={value["name"],value["damage"],value["cooldown"],value["type"],value["level"]};}
    return(result);
}
unordered_map<string,string> load_lore() {
    unordered_map<string,string>result;
    std::ifstream file("assets/data/lore.json");
    json data=json::parse(file);
    for (const auto& [id,value]:data.items()){result[id]=value;}
    return(result);
}
unordered_map<string,vector<string>> load_modifiers() {
    unordered_map<string,vector<string>>result;
    std::ifstream file("assets/data/modifiers.json");
    json data=json::parse(file);
    for (const auto& [id,value]:data.items()){result[id]=value;}
    return(result);
}
const unordered_map<string,move>moves=load_moves();
const unordered_map<string,string>lore_defs=load_lore();
const unordered_map<string,vector<string>> modifiers=load_modifiers();
void print(string text){
    for(int i=0;i<text.size();i++){
        cout<<text[i];
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }
}
string user_input(string prompt,vector<string>valid_options={}){
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
        string response_lower=response;
        std::transform(response_lower.begin(),response_lower.end(),response_lower.begin(),[](unsigned char c){return std::tolower(c);});
        if(!valid_options.empty()){
            bool valid=false;
            for(const auto& option:valid_options){
                string option_lower=option;
                std::transform(option_lower.begin(),option_lower.end(),option_lower.begin(),[](unsigned char c){return std::tolower(c);});
                if(response_lower==option_lower){
                    valid=true;
                    response=option;
                    break;
                }
            }
            if(!valid){
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
    power_construct memory;
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
    basic_power_upper[0]=static_cast<char>(std::toupper(static_cast<unsigned char>(basic_power_upper[0])));
    string alignment_power_upper=player.powers.alignment;
    alignment_power_upper[0]=static_cast<char>(std::toupper(static_cast<unsigned char>(alignment_power_upper[0])));
    string cosmic_power_upper=player.powers.cosmic;
    cosmic_power_upper[0]=static_cast<char>(std::toupper(static_cast<unsigned char>(cosmic_power_upper[0])));
    if(player.rare_traits==0){
        lore+="You have the power of "+player.powers.basic+". "+basic_power_upper+" is "+lore_defs.at(player.powers.basic)+" \n";
        lore+="You have the power of "+player.powers.alignment+". "+alignment_power_upper+" is "+lore_defs.at(player.powers.alignment)+" \n";
        lore+="You have the power of "+player.powers.cosmic+". "+cosmic_power_upper+" is "+lore_defs.at(player.powers.cosmic)+" ";
    }else if(player.rare_traits==1){
        if(player.powers.basic=="nexus"){
            lore+="You are the Nexus. "+lore_defs.at("nexus")+"\n";
            lore+="You have the power of "+player.powers.alignment+". "+alignment_power_upper+" is "+lore_defs.at(player.powers.alignment)+" \n";
            lore+="You have the power of "+player.powers.cosmic+". "+cosmic_power_upper+" is "+lore_defs.at(player.powers.cosmic)+" ";
        }
        else if(player.powers.alignment=="objectivity"){
            lore+="You have the power of "+player.powers.basic+". "+basic_power_upper+" is "+lore_defs.at(player.powers.basic)+" \n";
            lore+="You are the Objective. "+lore_defs.at("objectivity")+"\n";
            lore+="You have the power of "+player.powers.cosmic+". "+cosmic_power_upper+" is "+lore_defs.at(player.powers.cosmic)+" ";
    }
        else{
            lore+="You have the power of "+player.powers.basic+". "+basic_power_upper+" is "+lore_defs.at(player.powers.basic)+" \n";
            lore+="You have the power of "+player.powers.alignment+". "+alignment_power_upper+" is "+lore_defs.at(player.powers.alignment)+" \n";
            lore+="You are the Axiom. "+lore_defs.at("axiom");
        }
    }else if(player.rare_traits==2){
        if(player.powers.basic=="nexus"){
            if(player.powers.alignment=="objectivity"){
                lore+="You are the Nexus of Objectivity. "+lore_defs.at("nexus_objectivity")+"\n";
                lore+="You have the power of "+player.powers.cosmic+". "+cosmic_power_upper+" is "+lore_defs.at(player.powers.cosmic)+" ";
            }else{
                lore+="You have the power of "+player.powers.alignment+". "+alignment_power_upper+" is "+lore_defs.at(player.powers.alignment)+" \n";
                lore+="You are the Nexus of Axiom. "+lore_defs.at("nexus_axiom");
            }
        }else{
            lore+="You have the power of "+player.powers.basic+". "+basic_power_upper+" is "+lore_defs.at(player.powers.basic)+" \n";
            lore+="You are the Axiom of Objectivity. "+lore_defs.at("objectivity_axiom");
        }
    }else{lore+=lore_defs.at("absolute");}
    return lore;
}
int get_damage(const bool apply_cooldown,unordered_map<string,int>& attacker_cooldown_times,const stat_block& attacker_stats,const stat_block& attackee_stats,const power_construct& attackee_types,string attacking_move){
    const string attack_type=moves.at(attacking_move).type;
    string defender_type;
    if(find(basic_powers.begin(),basic_powers.end(),attack_type)!=basic_powers.end()){defender_type=attackee_types.basic;}
    else if(find(alignments.begin(),alignments.end(),attack_type)!=alignments.end()){defender_type=attackee_types.alignment;}
    else if(find(cosmic_powers.begin(),cosmic_powers.end(),attack_type)!=cosmic_powers.end()){defender_type=attackee_types.cosmic;}
    else{defender_type="";}
    int damage_multipliernum=1;
    int damage_multiplierden=1;
    if (find(modifiers.at(attack_type).begin(),modifiers.at(attack_type).end(),defender_type)!=modifiers.at(attack_type).end()){damage_multipliernum=2;}
    else if(find(modifiers.at(defender_type).begin(),modifiers.at(defender_type).end(),attack_type)!=modifiers.at(defender_type).end()){damage_multiplierden=2;}
    if(apply_cooldown){attacker_cooldown_times[attacking_move]=moves.at(attacking_move).cooldown;}
    return(static_cast<int>(std::round(static_cast<double>(moves.at(attacking_move).damage)*static_cast<double>(attacker_stats.attack)/static_cast<double>(attackee_stats.defense)*static_cast<double>(damage_multipliernum)/static_cast<double>(damage_multiplierden))));
}
bool battle_loop(bool turn,player& player,enemy& enemy){
    vector<string> available_moves;
    if(turn){
        string action="see moves";
        while(action=="see moves"){
            action=user_input(string("What would you like to do?"),{"use move", "see moves"});
            available_moves.clear();
            for(size_t i=0;i<player.known_moves.size();++i){if(player.cooldown_times.find(player.known_moves[i])==player.cooldown_times.end()){available_moves.push_back(player.known_moves[i]);}}
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
                string move_to_use_id=move_lookup[move_to_use];
                enemy.stats.health-=get_damage(true,player.cooldown_times,player.stats,enemy.stats,enemy.powers,move_to_use_id);
                if(moves.at(move_to_use_id).level=="basic"){
                    if(enemy.memory.basic!=moves.at(move_to_use_id).type&&enemy.memory.basic!="nexus"){
                        if(enemy.memory.basic==""){enemy.memory.basic=moves.at(move_to_use_id).type;}
                        else{enemy.memory.basic="nexus";}
                    }
                }else if(moves.at(move_to_use_id).level=="alignment"){
                    if(enemy.memory.alignment!=moves.at(move_to_use_id).type&&enemy.memory.alignment!="objectivity"){
                        if(enemy.memory.alignment==""){enemy.memory.alignment=moves.at(move_to_use_id).type;}
                        else{enemy.memory.alignment="objectivity";}
                    }
                }else if(moves.at(move_to_use_id).level=="cosmic"){
                    if(enemy.memory.cosmic!=moves.at(move_to_use_id).type&&enemy.memory.cosmic!="axiom"){
                        if(enemy.memory.cosmic==""){enemy.memory.cosmic=moves.at(move_to_use_id).type;}
                        else{enemy.memory.cosmic="axiom";}
                    }
                }
                cout<<"You used "<<moves.at(move_to_use_id).name<<" and dealt "<<moves.at(move_to_use_id).damage<<" damage to Bob! \n";
            }
        }
        for (auto it=player.cooldown_times.begin();it!=player.cooldown_times.end();){
            it->second--;
            if (it->second<=0){it=player.cooldown_times.erase(it);}
            else{it++;}
        }
    }else{
        for(size_t i=0;i<enemy.known_moves.size();++i){if(enemy.cooldown_times.find(enemy.known_moves[i])==enemy.cooldown_times.end()){available_moves.push_back(enemy.known_moves[i]);}}
        string best_move=available_moves[0];
        int best_damage=0;
        for(const auto& move_id:available_moves){
            int damage=get_damage(false,enemy.cooldown_times,enemy.stats,player.stats,enemy.memory,move_id);
            if(damage>best_damage){
                best_damage=damage;
                best_move=move_id;
            }
        }
        player.stats.health-=get_damage(true,enemy.cooldown_times,enemy.stats,player.stats,player.powers,best_move);
        const int actual_damage=get_damage(false,enemy.cooldown_times,enemy.stats,player.stats,player.powers,best_move);
        const int expected_damage=get_damage(false,enemy.cooldown_times,enemy.stats,player.stats,enemy.memory,best_move);
        cout<<"Bob used "<<moves.at(best_move).name<<" and dealt "<<actual_damage<<" damage to you! \n"<<"You have "+std::to_string(player.stats.health)+" health remaining. \n";
        if(actual_damage!=expected_damage){
            if(moves.at(best_move).level=="basic"){enemy.memory.basic=player.powers.basic;}
            else if(moves.at(best_move).level=="alignment"){enemy.memory.alignment=player.powers.alignment;}
            else if(moves.at(best_move).level=="cosmic"){enemy.memory.cosmic=player.powers.cosmic;}
        }
        for (auto it=enemy.cooldown_times.begin();it!=enemy.cooldown_times.end();){
            it->second--;
            if (it->second<=0){it=enemy.cooldown_times.erase(it);}
            else{it++;}
        }
    }
    return !turn;
}
int main() {
    print("Welcome to the game! You are a player in a world of magic and adventure. You will be able to choose your character's stats and powers, and then embark on a journey to defeat the evil forces that threaten the land. \n");
    player player;
    cout<<player.name<<" has been created with the following stats: \n";
    cout<<"Attack: "<<player.stats.attack<<" \n";
    cout<<"Speed: "<<player.stats.speed<<" \n";
    cout<<"Defense: "<<player.stats.defense<<" \n";
    cout<<"Health: "<<player.stats.health<<" \n";
    cout<<get_lore(player)<<"\n";
    cout<<"You are now ready to embark on your journey. Good luck, and may the forces of magic be with you! \n";
    enemy bob{"bob",{10,10,10,100},{},{},{},{},{}};
    std::uniform_int_distribution<size_t> basic_dist(0,basic_powers.size()-1);
    bob.powers.basic=basic_powers[basic_dist(gen)];
    std::uniform_int_distribution<size_t> alignment_dist(0,alignments.size()-1);
    bob.powers.alignment=alignments[alignment_dist(gen)];
    std::uniform_int_distribution<size_t> cosmic_dist(0,cosmic_powers.size()-1);
    bob.powers.cosmic=cosmic_powers[cosmic_dist(gen)];
    std::bernoulli_distribution randbool(0.5);
    for (const auto& [id,val]:moves){
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
    bool turn=true;
    cout<<"You have encountered Bob! Prepare for battle!\nYou have "+std::to_string(player.stats.speed)+" SPD, "+std::to_string(player.stats.attack)+" ATK, "+std::to_string(player.stats.defense)+" DFN, "+std::to_string(player.stats.health)+" HLT\n";
    while(player.stats.health>0&&bob.stats.health>0){
        turn=battle_loop(turn,player,bob);
        if(bob.stats.health<=0){cout<<"You have defeated Bob! \n";}
        else if(player.stats.health<=0){cout<<"You have been defeated by Bob. \n";}
        else{
            if(static_cast<double>(bob.stats.health-player.stats.health)/player.stats.health>0.0){
                cout<<"Bob has "<<std::round((static_cast<double>(bob.stats.health-player.stats.health)/player.stats.health)*10000)/100<<"% more health than you. \n";
            }else if(static_cast<double>(bob.stats.health-player.stats.health)/player.stats.health<0.0){
                cout<<"Bob has "<<-std::round((static_cast<double>(bob.stats.health-player.stats.health)/player.stats.health)*10000)/100<<"% less health than you. \n";
            }else{
                cout<<"Bob has the same health as you. \n";
            }
        }
    }
}