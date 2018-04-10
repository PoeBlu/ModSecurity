/*
 * ModSecurity, http://www.modsecurity.org/
 * Copyright (c) 2015 Trustwave Holdings, Inc. (http://www.trustwave.com/)
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

#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <utility>

#ifndef SRC_VARIABLES_MATCHED_VAR_H_
#define SRC_VARIABLES_MATCHED_VAR_H_

#include "src/variables/variable.h"

namespace modsecurity {

class Transaction;
namespace Variables {

class MatchedVar : public Variable {
    /** @ingroup ModSecurity_Variables ModSecurity_RefManual ModSecurity_RefManualVar */
    /**

    Description

    Name: MATCHED_VAR

    \verbatim
    This variable holds the value of the most-recently matched variable. It is
    similar to the TX:0, but it is automatically supported by all operators and
    there is no need to specify the capture action.

    = SecRule ARGS pattern chain,deny,id:25
    = SecRule MATCHED_VAR "further scrutiny"

    Note: Be aware that this variable holds data for the last operator match.
    This means that if there are more than one matches, only the last one will
    be populated. Use MATCHED_VARS variable if you want all matches.
    \endverbatim


    Details

    \verbatim
    \endverbatim

    */
 public:
    MatchedVar()
        : Variable("MATCHED_VAR") { }

    void evaluate(Transaction *transaction,
        Rule *rule,
        std::vector<const VariableValue *> *l) {
        transaction->m_variableMatchedVar.evaluate(l);
    }
};

}  // namespace Variables
}  // namespace modsecurity

#endif  // SRC_VARIABLES_MATCHED_VAR_H_
