#include <string>
#include <vector>
#include "Database.h"

using std::string, std::vector;

// TODO(student): implement constructor using member initializer list
Database::Database() : 
stateParkList(), 
camperList(){}

Database::~Database() {
    for (StatePark* park : stateParkList) {
        delete park;
    }
    for (Passport* camper : camperList) {
        delete camper;
    }
}

void Database::addStatePark(string parkName, double entranceFee, double trailMiles) {
    INFO(parkName)
    INFO(entranceFee)
    INFO(trailMiles)
    StatePark* newPark = new StatePark(parkName, entranceFee, trailMiles);
    stateParkList.push_back(newPark);
}

void Database::addPassport(string camperName, bool isJuniorPassport) {
    INFO(camperName)
    INFO(isJuniorPassport)
     Passport* newCamper = new Passport(camperName, isJuniorPassport);
    camperList.push_back(newCamper);
}

void Database::addParkToPassport(string const& camperName, string const& parkName) {
    INFO(camperName)
    INFO(parkName)
    Passport* camper = nullptr;
    for (Passport* c : camperList) {
        if (c->getCamperName() == camperName) {
            camper = c;
            break;
        }
    }
    if (camper == nullptr) {
        return; 
    }

    StatePark* park = nullptr;
    for (StatePark* p : stateParkList) {
        if (p->getParkName() == parkName) {
            park = p;
            break;
        }
    }
    if (park == nullptr) {
        return; 
    }

    camper->addParkVisited(park);
}

vector<string> Database::getParksInRevenueRange(double lowerBound, double upperBound) const {
    INFO(lowerBound)
    INFO(upperBound)

    vector<string> result;
    for (StatePark* park : stateParkList) {
        double revenue = park->getRevenue();
        if (revenue >= lowerBound && revenue <= upperBound) {
            result.push_back(park->getParkName());
        }
    }

    return result;
}

vector<string> Database::getHikersAtLeastLevel(int level) const {
    INFO(level)

    vector<string> result;
    for (Passport* camper : camperList) {
        if (camper->getHikerLevel() >= level) {
            result.push_back(camper->getCamperName());
        }
    }

    return result;
}