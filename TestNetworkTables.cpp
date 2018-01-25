#include <iostream>
#include <string>
#include "ntcore.h"

int main()
{
	auto inst = nt::GetDefaultInstance();

	nt::NetworkTableInstance::StartClient(inst, "VisionServer", kDefaultPort);
	nt::NetworkTableInstance::GetTable("SmartDashboard");

	while(true)
	{
		String response;
		cin<<"Give Permission to Drive?"<<response<<end;
		
		if(response == "yes"){
			nt::NetworkTableInstance::putString("Permission", "Yes");
		}
		
		if(response == "no") {
			nt::NetworkTableInstance::putString("Permission", "No");
		}
	}
}
