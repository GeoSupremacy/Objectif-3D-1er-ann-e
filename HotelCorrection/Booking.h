#include "Object.h"


class Client;
class DateTime;
class Booking : public Object
{
private:
	Client* client = nullptr;
	DateTime arrivevalDate = DateTime();
	DateTime departeDate = DateTime();
public:
	Booking() = default;
	Booking(Client* _client, DateTime _arrival, DateTime _departeDate);
	Booking(Booking* _copy);
		~Booking() override;
public:
	Client* GetClient() const;
	DateTime Arrivate() const;
	DateTime Departe() const;
public:
	std::string ToString() const override;

};

