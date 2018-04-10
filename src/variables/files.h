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

#ifndef SRC_VARIABLES_FILES_H_
#define SRC_VARIABLES_FILES_H_

#include "src/variables/variable.h"

namespace modsecurity {

class Transaction;
namespace Variables {

class Files_DictElement : public Variable {
    /** @ingroup ModSecurity_Variables ModSecurity_RefManual ModSecurity_RefManualVar */
    /**

    Description

    Name: FILES

    \verbatim
    Contains a collection of original file names (as they were called on the
    remote user’s filesys- tem). Available only on inspected
    multipart/form-data requests.

    = SecRule FILES "@rx \.conf$" "id:17"
    \endverbatim


    Details

    \verbatim
    \endverbatim

    */
 public:
    explicit Files_DictElement(std::string dictElement)
        : Variable("FILES" + std::string(":") +
            std::string(dictElement)),
        m_dictElement(dictElement) { }

    void evaluate(Transaction *transaction,
        Rule *rule,
        std::vector<const VariableValue *> *l) override {
        transaction->m_variableFiles.resolve(m_dictElement, l);
    }

    std::string m_dictElement;
};


class Files_NoDictElement : public Variable {
 public:
    Files_NoDictElement()
        : Variable("FILES") { }

    void evaluate(Transaction *transaction,
        Rule *rule,
        std::vector<const VariableValue *> *l) override {
        transaction->m_variableFiles.resolve(l);
    }
};


class Files_DictElementRegexp : public Variable {
 public:
    explicit Files_DictElementRegexp(std::string dictElement)
        : Variable("FILES:regex(" + dictElement + ")"),
        m_r(dictElement) { }

    void evaluate(Transaction *transaction,
        Rule *rule,
        std::vector<const VariableValue *> *l) override {
        transaction->m_variableFiles.resolveRegularExpression(
            &m_r, l);
    }

    Utils::Regex m_r;
};


}  // namespace Variables
}  // namespace modsecurity

#endif  // SRC_VARIABLES_FILES_H_

