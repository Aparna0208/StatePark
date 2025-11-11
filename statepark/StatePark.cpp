#include <string>
#include "StatePark.h"
#include "Passport.h"

using std::string, std::vector;

StatePark::StatePark(string parkName, double entranceFee, double trailMiles): 
 parkName(parkName), 
 entranceFee(entranceFee), 
 trailMiles(trailMiles),
 camperLog() {}



std::string StatePark::getParkName() const {
     return parkName;

}

double StatePark::getEntranceFee() const {
    // TODO(student): implement getter

    return entranceFee;
}

double StatePark::getTrailMiles() const {
    // TODO(student): implement getter

    return trailMiles;
}

void StatePark::addCamper(Passport* camper) {
    INFO(camper)

    camperLog.push_back(camper);
}

double StatePark::getRevenue() const {
     double totalRevenue = 0.0;
    for (Passport* camper : camperLog) {
        if (camper->checkJuniorPassport()) {
            totalRevenue += entranceFee / 2.0;
        } else {
            totalRevenue += entranceFee;
        }
    }
    return totalRevenue;

}
