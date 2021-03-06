#include <iostream>
#include <backward/strstream>
#include <fstream>

#include "format.h"
#include "xbee_telemetry_client.h"

void print_quantity(const long int value, const char symbol) {
  std::ostrstream s;
  for (int i = 0; i < value; i++) {
    if (i % 10 == 0) {
      s << "|";
    } else {
      s << symbol;
    }
  }
  s << std::ends;
  printf("%03ld %s\n", value, s.str());
}

int main(int argc, char **argv) {
  auto device = std::string(argv[1]);
  airball::XbeeTelemetryClient telemetry_client(device);

  std::map<std::string, std::ofstream *> files;

  auto log_time = std::chrono::system_clock::now();

  std::ofstream *file = new std::ofstream;
  std::string filename = airball::format_log_filename(log_time, "all");
  file->open(filename, std::ios::out);
  std::cout << "Logging data to " << filename << std::endl;

  #pragma clang diagnostic push
  #pragma clang diagnostic ignored "-Wmissing-noreturn"

  auto previous_loop_time = std::chrono::system_clock::now();

  for (int packet_number=0; ; packet_number++) {
    std::unique_ptr<sample> sample = telemetry_client.get();
    auto now = std::chrono::system_clock::now();
    std::chrono::system_clock::duration since_last =
        now.time_since_epoch() -
        previous_loop_time.time_since_epoch();
    auto since_last_mills =
        std::chrono::duration_cast<std::chrono::duration<unsigned int, std::milli>>(since_last);
    previous_loop_time = now;
    *file << sample->format().c_str() << std::endl;
    print_quantity(static_cast<int>(sample->get_rssi()), '+');
    print_quantity(since_last_mills.count(), '.');
  }

  #pragma clang diagnostic pop

  return 0;
}