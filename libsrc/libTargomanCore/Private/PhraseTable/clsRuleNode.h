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
 */

#ifndef TARGOMAN_CORE_PRIVATE_PHRASETABLE_RULENODE_H
#define TARGOMAN_CORE_PRIVATE_PHRASETABLE_RULENODE_H

#include <QList>
#include "clsTargetRule.h"
#include "libTargomanCommon/Configuration.h"

namespace Targoman {
namespace Core {
namespace Private {
namespace PhraseTable{

class clsRuleNode
{
public:
    clsRuleNode();


    // Following functions are needed for the binary input/output
    void readBinary(std::istream &input);
    void writeBinary(std::ostream &output) const;

private:
    QList<QSharedDataPointer<clsTargetRule> > TargetRules;
    static Common::clsConfigurable<QList<quint8> > WhichCosts;
};

}
}
}
}

#endif // TARGOMAN_CORE_PRIVATE_PHRASETABLE_RULENODE_H
