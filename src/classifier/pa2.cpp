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

#include <algorithm>
#include "pa2.hpp"

using namespace std;

namespace jubatus{

PA2::PA2(storage::storage_base* storage,
         const PA2_config& conf)
    : classifier_base(storage),
      C_(conf.update_weight)
{
}

void PA2::train(const sfv_t& sfv, const string& label){
  string incorrect_label;
  float margin = calc_margin(sfv, label, incorrect_label);
  float loss = 1.f + margin;

  if (loss < 0.f){
    return;
  }
  float sfv_norm = squared_norm(sfv);
  if (sfv_norm == 0.f) {
    return;
  }
  update_weight(sfv, loss / (sfv_norm + 1/(2 * C_)), label, incorrect_label);
}

string PA2::name() const {
  return string("PA2"); 
}

  
}
