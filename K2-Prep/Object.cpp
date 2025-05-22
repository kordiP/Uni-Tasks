class Object
{
private:
	double latitude;
	double longitude;
public:
	Object(double lat, double lon)
	{
		latitude = lat;
		longitude = lon;
	}

	double getLatitude() const
	{
		return latitude;
	}
	double getLongitude() const
	{
		return longitude;
	}

	Object& setLatitude(double lat)
	{
		latitude = lat;
	}
	Object& setLongitude(double lon)
	{
		longitude = lon;
	}
};