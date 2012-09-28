// Jubatus: Online machine learning framework for distributed environment
// Copyright (C) 2011 Preferred Infrastructure and Nippon Telegraph and Telephone Corporation.
//
// This library is free software; you can redistribute it and/or
// modify it under the terms of the GNU Lesser General Public
// License as published by the Free Software Foundation; either
// version 2.1 of the License, or (at your option) any later version.
//
// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public
// License along with this library; if not, write to the Free Software
// Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA

#ifndef PA1_HPP_
#define PA1_HPP_

#include "classifier_base.hpp"

#include <pficommon/data/serialization.h>

namespace jubatus{

struct PA1_config {
  float max_update_ratio;

  template <class Ar>
  void serialize(Ar& ar) {
    ar & MEMBER(max_update_ratio);
  }
};

class PA1 : public classifier_base {
public:
  PA1(storage::storage_base* storage, const PA1_config& conf);
  void train(const sfv_t& fv, const std::string& label);
  std::string name() const;
private:
  float C_;
};

}

#endif // PA1_HPP_
