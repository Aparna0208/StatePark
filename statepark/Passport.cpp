#include <string>
#include "Passport.h"
#include "StatePark.h"

using std::string, std::vector;

Passport::Passport(string camperName, bool isJuniorPassport)
    : camperName(camperName), 
    isJuniorPassport(isJuniorPassport),
    parksVisited() {}

string Passport::getCamperName() const {
    // TODO(student): implement getter

    return camperName;
}

bool Passport::checkJuniorPassport() const {
    // TODO(student): implement getter

    return isJuniorPassport;
}

void Passport::addParkVisited(StatePark* park) {
    INFO(park)
    parksVisited.push_back(park);
    park->addCamper(this);
}

double Passport::getMilesHiked() const {
    double totalMiles = 0.0;
    for (StatePark* park : parksVisited) {
        double trailMiles = park->getTrailMiles();
        if (isJuniorPassport) {
            totalMiles += trailMiles * 2.0;
        } else {
            totalMiles += trailMiles;
        }
    }
    return totalMiles;
}

int Passport::getHikerLevel() const {
    double miles = getMilesHiked();
    return static_cast<int>(miles / 100.0);
}