#ifndef PROJECT1_GPS_H
#define PROJECT1_GPS_H

#include <iostream>

using namespace std;

class LatInvalida : std::exception{
    int lat;
public:
    LatInvalida(int l){lat = l;}
    const char* what() const throw()
    {
        return "Latitude must be between -90 and 90 degrees";
    }
};

class LongInvalida : std::exception{
    int longe;
public:
    LongInvalida(int l){longe = l;}
    const char* what() const throw()
    {
        return "Longitude must be between -90 and 90 degrees";
    }
};

///GPS
class GPS{
    float latitude,
            longitude;
public:
    ///implementacao do construtor
    GPS()
    {
        latitude = 0;
        longitude = 0;
    }

    ///implementacao do construtor com parametros
    ///@param lat
    ///@param longi
    GPS(float lat, float longi)
    {
        if(lat > 90 || lat < -90)
        {
            throw LatInvalida(lat);
        }

        if(longi > 180 || longi < -180)
        {
            throw LongInvalida(longi);
        }
        this->latitude = lat;
        this->longitude = longi;
    }

    ///getter da latitude
    float getLatitude() const {
        return latitude;
    }

    ///setter da latitude
    ///@param latitude
    void setLatitude(float latitude) {
        if(latitude > 90 || latitude < -90)
        {
            throw runtime_error("Latitude must be between -90 and 90 degrees");
        }
        GPS::latitude = latitude;
    }

    ///getter da longitude
    float getLongitude() const {
        return longitude;
    }

    ///setter de longitude
    ///@param longitude
    void setLongitude(float longitude) {
        if(longitude > 180 || longitude < -180)
        {
            throw runtime_error("Latitude must be between -90 and 90 degrees");
        }
        GPS::longitude = longitude;
    }

    ///implementcao do operator <<
    ///@param os
    ///@param gps
    friend ostream& operator<<(ostream& os, const GPS& gps){
        os << "(" << gps.latitude << ", " << gps.longitude << ")";
        return os;
    }
};


#endif //PROJECT1_GPS_H