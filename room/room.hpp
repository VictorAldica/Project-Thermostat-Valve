#pragma once
#include <iostream>
#include <vector>
#include "../thermostat/thermostat.hpp"
#include "../valve/valve.hpp"
using std::string;
using std::vector;

class Room
{
private:
    string m_room_name;
    Thermostat m_thermostat;
    vector<Valve> m_valves;

public:
    Room();
    Room(string,float);
    //~Room();
    void whereami();
};