// Jubatus: Online machine learning framework for distributed environment
// Copyright (C) 2011 Preferred Infrastructure and Nippon Telegraph and Telephone Corporation.
//
// This library is free software; you can redistribute it and/or
// modify it under the terms of the GNU Lesser General Public
// License version 2.1 as published by the Free Software Foundation.
//
// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public
// License along with this library; if not, write to the Free Software
// Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA

#pragma once

#include <sstream>
#include <cmath>
#include "num_feature.hpp"

namespace jubatus {
namespace fv_converter {

class num_value_feature : public num_feature {
public:
  void add_feature(const std::string& key, double value, sfv_t& ret_fv) const {
    ret_fv.push_back(make_pair(key, value));
  }
};

class num_string_feature : public num_feature {
public:
  void add_feature(const std::string& key, double value, sfv_t& ret_fv) const {
    std::stringstream ss;
    ss << key << "$" << value;
    ret_fv.push_back(make_pair(ss.str(), 1.0));
  }
};

class num_log_feature : public num_feature {
public:
  void add_feature(const std::string& key, double value, sfv_t& ret_fv) const {
    ret_fv.push_back(make_pair(key, std::log(std::max(1.0, value))));
  }
};

}
}
