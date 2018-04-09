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

#ifndef AIRBALL_DATA_SOURCE_H
#define AIRBALL_DATA_SOURCE_H

#include <string>

namespace airball {

/**
 * A source of raw sensor data from an Airball sensor.
 */
class DataSource {
public:

  virtual ~DataSource() {};

  /**
   * Blocks until the next data sentence is available, then returns it.
   *
   * TODO: Document data sentence format.
   *
   * @return a data sentence in standard format.
   */
  virtual std::string next_data_sentence() = 0;

  /**
   * Creates a new DataSource that returns data from a given serial device.
   *
   * @param device a serial device name.
   *
   * @return a DataSource.
   */
  static DataSource* NewSerialDataSource(const std::string& device);

  /**
   * Creates a new DataSource that returns fake data.
   *
   * @return a DataSource.
   */
  static DataSource* NewFakeDataSource();

  /**
   * Creates a new DataSource that replays a given log file.
   *
   * @return a DataSource.
   */
  static DataSource* NewReplayDataSource(const std::string& file);
};

}  // namespace airball

#endif //AIRBALL_DATA_SOURCE_H