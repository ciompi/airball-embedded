/**
 * The MIT License (MIT)
 *
 * Copyright (c) 2017-2018, Ihab A.B. Awad
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

#ifndef AIRBALL_AIRDATA_H
#define AIRBALL_AIRDATA_H

#include <string>
#include "interpolation_table.h"
#include "../airball_probe_telemetry/airdata_sample.h"

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

  // Free stream dynamic pressure
  double free_stream_q() const {return free_stream_q_;}

  // Returns true if the data is valid. If not, display a red X indicating system failure.
  bool valid() const {return valid_;}

  // Commands this model to update its contents based on the given sensor data.
  void update(const airdata_sample* d);
private:
  InterpolationTable dpr_to_angle;
  double ias_;
  double tas_;
  double alpha_;
  double beta_;
  double free_stream_q_;
  bool valid_;
};

} // namespace airball

#endif // AIRBALL_AIRDATA_H
