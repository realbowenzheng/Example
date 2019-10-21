#ifndef ITEM_H
#define ITEM_H

// TODO: copy your Item.h file from assignment 1 over this file
#include <iostream>
#include <string>
using std::ostream;
using std::string;
#include <cmath>

class Item {

private:
    double latitude;
    double longitude;
    string id;
    int time;
    const double PI = 3.14;

public:

    Item() {}

    Item(double latitudeIn, double longitudeIn, string idIn, int timeIn)
        : latitude(latitudeIn), longitude(longitudeIn), id(idIn), time(timeIn) {
    }

    Item(const Item & other)
        : latitude(other.latitude), longitude(other.longitude), id(other.id), time(other.time) {
    }

    Item & operator=(const Item & other)
    {
        latitude = other.latitude;
        longitude = other.longitude;
        id = other.id;
        time = other.time;
        return *this;
    }

    double getLatitude() const {
        return latitude;
    }

    double getLongitude() const {
        return longitude;
    }

    string getID() const {
        return id;
    }

    int getTime() const {
        return time;
    }

    double distanceTo(const Item & other) const {
        double lon2 = fromDegreeToRadians(longitude);
        double lon1 = fromDegreeToRadians(other.getLongitude());
        double lat2 = fromDegreeToRadians(latitude);
        double lat1 = fromDegreeToRadians(other.getLatitude());
        const int R = 6373000;  // radius of the Earth

        double dlon = lon2 - lon1;
        double dlat = lat2 - lat1;
        double a = pow((sin(dlat/2)), 2) + cos(lat1) * cos(lat2) * pow((sin(dlon/2)), 2);
        double c = 2 * atan2( sqrt(a), sqrt(1-a) );
        double distance = R * c;

        return distance;
    }

private:
    double fromDegreeToRadians(double d) const {
        return d / 180 * PI;
    }

};

ostream & operator<<(ostream & o, const Item & item) {
    o << "{" << item.getLatitude() << ", " << item.getLongitude() << ", " << "\""
      << item.getID() << "\", " << item.getTime() << "}";
    return o;
}

#endif
