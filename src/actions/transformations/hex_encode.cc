/*
 * ModSecurity, http://www.modsecurity.org/
 * Copyright (c) 2015 - 2020 Trustwave Holdings, Inc. (http://www.trustwave.com/)
 *
 * You may not use this file except in compliance with
 * the License.  You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * If any of the files related to licensing are missing or if you have any
 * other questions related to licensing please contact Trustwave Holdings, Inc.
 * directly using the email address security@modsecurity.org.
 *
 */


#include "src/actions/transformations/hex_encode.h"

#include <string>

#include "modsecurity/modsecurity.h"
#include "modsecurity/transaction.h"


namespace modsecurity {
namespace actions {
namespace transformations {


void HexEncode::execute(const Transaction *t,
    const ModSecString &in,
    ModSecString &out) noexcept {
    std::stringstream result;
    for (std::size_t i=0; i < in.length(); i++) {
        int ii = reinterpret_cast<char>(in[i]);
        result << std::setw(2) << std::setfill('0') << std::hex << ii;
    }

    out.assign(result.str().c_str());
}


}  // namespace transformations
}  // namespace actions
}  // namespace modsecurity
