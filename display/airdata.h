#ifndef AIRBALL_AIRDATA_H
#define AIRBALL_AIRDATA_H

#include <string>
#include "interpolation_table.h"

namespace airball {

class Airdata {
public:
  Airdata();

  // Indicated air speed
  double ias() const {return ias_;}

  // True air speed
  double tas() const {return tas_;}

  // Angle of attack
  double alpha() const {return alpha_;}

  // Angle of yaw
  double beta() const {return beta_;}

  // Returns true if the data is valid. If not, display a red X indicating system failure.
  bool valid() const {return valid_;}

  // Commands this model to update its contents based on the given sensor data.
  void update_from_sentence(const std::string& sentence);

  // Commands this model to update its contents based on the given sensor data.
  void update_from_sentence(
      const double baro,
      const double temp,
      const double delta_p_0,
      const double delta_p_alpha,
      const double delta_p_beta);
private:
  InterpolationTable dpr_to_angle;
  double ias_;
  double tas_;
  double alpha_;
  double beta_;
  bool valid_;
};

} // namespace airball

#endif // AIRBALL_AIRDATA_H
