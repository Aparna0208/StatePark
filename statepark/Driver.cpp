#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include "Database.h"

using std::cout, std::cin, std::endl, std::string, std::ifstream,
      std::istringstream, std::vector;

int get_selection();
void task1(Database&);
void task2(Database&);
void task3(Database&);

int main() {
    Database db;

   try {
        task1(db); 
    } catch (std::runtime_error const& err) {
        cout << err.what() << endl;
        return 1;
    }

    int selection = 0;


    switch(selection) {
        // TODO(student): uncomment after completing Task 2
        // case 1: task2(db); break;

        // TODO(student): uncomment after completing Task 3
        // case 2: task3(db); break;
    }

    return 0;
}

int get_selection() {
    cout << "Welcome to the State Park Passport Database!\n";
    cout << "Please select from the following options:\n";
    cout << "1: Get all parks with revenue in range.\n";
    cout << "2: Get all hikers at or above a certain level.\n";
    cout << "Your Selection: ";
    int selection = 0;
    cin >> selection;
    return selection;
}

void task1(Database& db) {
    ifstream ifs_parks("park_data.txt");

    if (!ifs_parks.is_open()) {
        throw std::runtime_error("Error: could not open park data file");
    }

    while (!ifs_parks.eof()) {
        string line = "";
        getline(ifs_parks, line, '\n');
        if (line == "") break;
        string park_name = "";
        string s_fee = "";
        string s_miles = "";
        istringstream iss_line(line);
        getline(iss_line, park_name, ',');
        getline(iss_line, s_fee, ',');
        getline(iss_line, s_miles, '\n');
        
        if (s_fee.size() > 0 && s_fee.at(0) == ' ') s_fee.erase(0, 1);
        if (s_miles.size() > 0 && s_miles.at(0) == ' ') s_miles.erase(0, 1);

        double fee = stod(s_fee);
        double miles = stod(s_miles);
        db.addStatePark(park_name, fee, miles);
    }

    ifstream ifs_campers("camper_data.txt");
    if (!ifs_campers.is_open()) {
        throw std::runtime_error("Error: could not open camper data file");
    }

    while (!ifs_campers.eof()) {
        string line = "";
        getline(ifs_campers, line, '\n');
        if (line == "") break;
        
        string camper_name = "";
        string s_junior = "";
        istringstream iss_line(line);
        
        getline(iss_line, camper_name, ',');
        getline(iss_line, s_junior, ',');
        
        bool junior = static_cast<bool>(stoi(s_junior));
        db.addPassport(camper_name, junior);
        
        string park = "";
        while (getline(iss_line, park, ',')) { 
            if (park.size() > 0 && park.at(0) == ' ') park.erase(0, 1);
            if (park.size() > 0) { 
                db.addParkToPassport(camper_name, park);
            }
        }
    }
}

void task2(Database& db) {
    double lower_bound = 0, upper_bound = 0;
    cout << "Enter Lower Bound then Upper bound: ";
    cin >> lower_bound >> upper_bound;
    vector<string> park_result = db.getParksInRevenueRange(lower_bound, upper_bound);

    cout << "These are all the parks with revenue in the range given" << endl;
    for (unsigned int i = 0; i < park_result.size(); ++i) {
        cout << park_result.at(i) << endl;
    }
}

void task3(Database& db) {
    int hiking_level = 0;
    cout << "Enter Hiking Level: ";
    cin >> hiking_level;
    vector<string> hiker_result = db.getHikersAtLeastLevel(hiking_level);

    cout << "These are all the hikers at or above the level given" << endl;
    for (unsigned int i = 0; i < hiker_result.size(); ++i) {
        cout << hiker_result.at(i) << endl;
    }
}