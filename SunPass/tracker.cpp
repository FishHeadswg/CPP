/*
tracker.cpp
10-24-13
Trevor Richardson

SunPass tracker: Reads traffic segment data and produces summary
and detail reports.

*/

#include <vehicles.h>
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cstring>

void Output(Vehicle *); // Output prototype

int main()
{
  const size_t maxSegSize = 100; // 0-100 segment[100] = '\0'
  const int maxSn = 20;
  const int maxDot = 20;
  char sn[maxSn];
  char dot[maxDot];
  size_t segSize;
  Vehicle *segment[maxSegSize];
  VehicleType v; // to hold type of vehicle

  std::cout << "\nTracker started...\n";
  
  do
  {
    unsigned int pc;
    float d1, d2, d3;
    int badSnTotal = 0, vehicleTotal = 0, carTotal = 0, truckTotal = 0, 
      vanTotal = 0, tankerTotal = 0, flatbedTotal = 0;
    float tonnage = 0;
    float tolls = 0;
    std::cin >> segSize;
    if (segSize == 0)
      break;
    if (segSize > maxSegSize)
    {
      std::cerr << "Error: Maximum traffic segment exceeded.\n";
      break;
    }
    // read data and build Vehicle objects for segment
    for (size_t i = 0; i < segSize; ++i)
    {
      std::cin >> sn;
      v = Vehicle::SnDecode(sn);
      switch ( v )
      {
      case badSn:
        ++badSnTotal;
        std::cin >> pc;
        segment[i] = new Vehicle(sn, pc);
        break;
      case vehicle:
        ++vehicleTotal;
        std::cin >> pc;
        segment[i] = new Vehicle(sn, pc);
        break;
      case car:
        ++carTotal;
        std::cin >> pc;
        segment[i] = new Car(sn, pc);
        break;
      case truck:
        ++truckTotal;
        std::cin >> pc >> dot;
        segment[i] = new Truck(sn, pc, dot);
        break;
      case van:
        ++vanTotal;
        std::cin >> pc >> dot >> d1 >> d2 >> d3;
        segment[i] = new Van(sn, pc, dot, d1, d2, d3);
        break;
      case tanker:
        ++tankerTotal;
        std::cin >> pc >> dot >> d1 >> d2;
        segment[i] = new Tanker(sn, pc, dot, d1, d2);
        break;
      case flatbed:
        ++flatbedTotal;
        std::cin >> pc >> dot >> d1 >> d2;
        segment[i] = new Flatbed(sn, pc, dot, d1, d2);
        break;
      default:  // should never get here
        std::cerr << "** ERROR: bad serial number passed to decision logic\n";
        break;
      } // end switch
      if (segment[i] == 0)
      {
        std::cerr << "Memory allocation problem.";
        break;
      }
      tonnage += segment[i]->LoadCapacity();
      tolls += segment[i]->Toll();
    } //end for
    
    std::cout << "\nSegment Summary\n===============\n";
    std::cout << "\n  Cars:     " << carTotal;
    std::cout << "\n  Trucks:   " << truckTotal;
    std::cout << "\n  Vans:     " << vanTotal;
    std::cout << "\n  Tankers:  " << tankerTotal;
    std::cout << "\n  Flatbeds: " << flatbedTotal;
    std::cout << "\n  Unknowns: " << vehicleTotal;
    std::cout << "\n  Badsn:    " << badSnTotal;
    std::cout << std::setprecision(2) << std::fixed;
    std::cout << "\n  Tonnage:  " << tonnage;
    std::cout << "\n  Tolls:    $" << tolls << std::endl;

    std::cout << "\n\nSegment Details\n===============\n\n";
    std::cout << std::setw(6) << std::right << "Type" << std::setw(7) << "Toll"
      << std::setw(10) << "Pass Cap" << std::setw(10) << "Load Cap"
      << std::setw(13) << "DOT License" << std::setw(15) << "Serial Number"
      << std::endl;
    std::cout << std::setw(6) << std::right << "----" << std::setw(7) << "----"
      << std::setw(10) << "--------" << std::setw(10) << "--------"
      << std::setw(13) << "-----------" << std::setw(15) << "-------------"
      << std::endl;
    for (size_t i = 0; i < segSize; ++i) // write the segment report
    {
      Output (segment[i]);
      delete segment[i];
    }
  } while (segSize > 0);

  std::cout << "\n\n...Thank you for using SunPass Tracker.\n\n";

}

void Output(Vehicle *v)
{
  std::cout << std::setw(6) << std::setprecision(2) << std::fixed << std::right
    << std::showpoint << v->ShortName() << std::setw(7) << v->Toll()
    << std::setw(10) << v->PassengerCapacity() << std::setw(10)
    << v->LoadCapacity();
  if (truck <= Vehicle::SnDecode(v->SerialNumber()))
  {
    std::cout << std::setw(13) << (dynamic_cast<Truck*>(v))->DOTLicense();
  }
  else
    std::cout << std::setw(13) << "(NA)";
  std::cout << std::setw(15) << v->SerialNumber()
    << std::endl;
}