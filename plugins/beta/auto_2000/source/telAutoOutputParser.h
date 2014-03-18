#ifndef telAutoOutputParserH
#define telAutoOutputParserH
#include <vector>
#include "rr/rrRoadRunner.h"
#include "../rrAutoInterface/rrAutoData.h"
#include "../rrAutoInterface/rrRRAuto.h"
#include "telProperty.h"
#include "telStringList.h"
//---------------------------------------------------------------------------

class AutoOutputParser
{
    public:
                                                AutoOutputParser();
                                               ~AutoOutputParser();
        //Data input
        bool                                    setInputData(const string& data);

    protected:
        string                                  mBiFurcationDiagram; //This is the input
        tlp::StringList                         mLabeledSolutionPoints;
        tlp::TelluriumData                      mBiFurcationData;

};

namespace tlp
{
//template<>
//inline std::string Property< rrauto::ScanDirection >::getType() const
//{
//    return "ScanDirection";
//}
//
//template<>
//inline string Property< rrauto::ScanDirection >::getValueAsString() const
//{
//    return mValue == rrauto::sdPositive ? "Positive" : "Negative";
//}
//
//template<>
//inline void Property< rrauto::ScanDirection >::setValueFromString(const string& val)
//{
//    mValue = compareNoCase(val, "Positive") == 0 ? rrauto::sdPositive : rrauto::sdNegative;
//}
//
//template<>
//inline void Property< rrauto::ScanDirection >::setValue(const rrauto::ScanDirection& val)
//{
//    mValue = (val);
//}
}



#endif