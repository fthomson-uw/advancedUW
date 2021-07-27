//
//  Chrono Examples
//

#include <iostream>
#include <iomanip>
#include <vector>
#include <numeric>
#include <chrono>



using std::cout;
using std::endl;

int main(int argc, char** argv)
{
  // cout << "You have entered " << argc
  //      << " arguments:" << "\n";
  // for (int i = 0; i < argc; ++i)
  //     cout << argv[i] << "\n";


  //
  // Get the current time in UTC
  //
  // auto utcNow{ std::chrono::utc_clock::now() };
  // auto gpsNow{ std::chrono::gps_clock::now() };
  // auto taiNow{ std::chrono::tai_clock::now() };

  using namespace std::literals::chrono_literals;
  // using namespace std::literals; // enables the usage of 24h, 1ms, 1s instead of
  //                              // e.g. std::chrono::hours(24), accordingly

  auto hrcNow{ std::chrono::high_resolution_clock::now() };

  const std::time_t t_c{ std::chrono::system_clock::to_time_t(hrcNow - 0h) };
  std::cout << "The time is "
                << std::put_time(std::localtime(&t_c), "%F %T.\n") << std::flush;

  //
  //
  //


  return 0;

}
