/*************************************************************************
 * Copyright © 2012-2015, Targoman.com
 *
 * Published under the terms of TCRL(Targoman Community Research License)
 * You can find a copy of the license file with distributed source or
 * download it from http://targoman.com/License.txt
 *
 *************************************************************************/
/**
 @author S. Mohammad M. Ziabary <smm@ziabary.com>
 @author Behrooz Vedadian <vedadian@gmail.com>
 */

#ifndef TARGOMAN_CORE_PRIVATE_RULETABLE_CLSJANERULETABLE_H
#define TARGOMAN_CORE_PRIVATE_RULETABLE_CLSJANERULETABLE_H

#include "libTargomanCommon/Configuration/tmplConfigurable.h"
#include "libTargomanCommon/PrefixTree/tmplFullVectorFilePrefixTree.hpp"
#include "intfRuleTable.hpp"
#include "clsRuleNode.h"

namespace Targoman {
namespace Core {
namespace Private {
namespace RuleTable {

TARGOMAN_ADD_EXCEPTION_HANDLER(exJanePhraseTable, exRuleTable);

class clsJanePlainRuleTable : intfRuleTable
{
public:
    clsJanePlainRuleTable();
    ~clsJanePlainRuleTable();

    virtual void init();

private:
    void addRule(const QStringList &_phraseCosts,
                 const QStringList &_fields,
                 const QList<size_t> &_acceptedAdditionalFields,
                 size_t _ruleNumber);

private:
    static Targoman::Common::Configuration::tmplConfigurable<QString> FileName;
    static Targoman::Common::Configuration::tmplConfigurable<QString> PhraseCostNames;
    static Targoman::Common::Configuration::tmplConfigurable<QString> AdditionalModels;
    static QList<Targoman::Common::Configuration::tmplConfigurable<QString>> FeatureFunctions;

    TARGOMAN_DEFINE_MODULE("JanePTPlain", clsJanePlainRuleTable)
};

}
}
}
}
#endif // TARGOMAN_CORE_PRIVATE_RULETABLE_CLSJANERULETABLE_H
