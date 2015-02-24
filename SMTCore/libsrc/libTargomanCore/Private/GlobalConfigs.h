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

#ifndef TARGOMAN_CORE_PRIVATE_GLOBALCONFIGS_H
#define TARGOMAN_CORE_PRIVATE_GLOBALCONFIGS_H

#include "libTargomanCommon/exTargomanBase.h"
#include "libTargomanCommon/Configuration/tmplConfigurable.h"
#include "libTargomanCommon/Configuration/clsModuleConfig.hpp"
#include "libTargomanCore/clsTranslator.h"
#include "libTargomanCommon/Types.h"

namespace Targoman {
namespace Core {
namespace Private {

//TODO move this to core common
inline QString bitArray2Str(const QBitArray& _bits){
    QString Output;
    for(int i=0;i<_bits.size(); ++i)
        Output+=_bits.testBit(i) ? '1' : '0';
    return Output;
}


namespace FeatureFunction{
class intfFeatureFunction;
}

namespace LanguageModel {
class intfLMSentenceScorer;
}

struct stuGlobalConfigs{
    static Targoman::Common::Configuration::tmplConfigurable<QString> Separator;
    static Targoman::Common::Configuration::tmplConfigurable<QString> SourceLanguage;
    static Targoman::Common::Configuration::tmplConfigurable<QString> TargetLanguage;



    static Targoman::Common::Configuration::clsModuleConfig          LM;
    static Targoman::Common::Configuration::clsModuleConfig          RuleTable;

    static QScopedPointer<Targoman::Core::Private::LanguageModel::intfLMSentenceScorer>  EmptyLMScorer;
    static QHash<QString, Common::WordIndex_t>                            SourceVocab;

    static QMap<QString, FeatureFunction::intfFeatureFunction*>       ActiveFeatureFunctions;
};

extern stuGlobalConfigs gConfigs;

}
}
}
#endif // TARGOMAN_CORE_PRIVATE_GLOBALCONFIGS_H
