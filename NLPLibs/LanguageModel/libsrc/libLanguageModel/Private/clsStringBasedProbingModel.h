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

#ifndef TARGOMAN_NLPLIBS_PRIVATE_CLSSTRINGBASEDPROBINGMODEL_H
#define TARGOMAN_NLPLIBS_PRIVATE_CLSSTRINGBASEDPROBINGMODEL_H

#include "clsAbstractProbingModel.h"

namespace Targoman {
namespace NLPLibs {
namespace Private {

class clsStringBasedProbingModel : public clsAbstractProbingModel
{
public:
    clsStringBasedProbingModel(){;}
    Common::LogP_t lookupNGram(const QStringList &_ngram, quint8 &_foundedGram) const;
    Common::LogP_t lookupNGram(const QList<Common::WordIndex_t> &_ngram, quint8 &_foundedGram) const
    {
        throw Common::exTargomanNotImplemented("NgramLookup by WordIndex not implemented yet");
    }
};

}
}
}

#endif // TARGOMAN_NLPLIBS_PRIVATE_CLSSTRINGBASEDPROBINGMODEL_H
