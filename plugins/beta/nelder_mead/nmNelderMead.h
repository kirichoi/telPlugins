#ifndef nmNelderMeadH
#define nmNelderMeadH
#include <vector>
#include "rr-libstruct/lsMatrix.h"
#include "lib/nmsimplex.h"
#include "telProperty.h"
#include "telCPPPlugin.h"
#include "nmWorker.h"
//---------------------------------------------------------------------------

using rr::RoadRunner;
using std::string;
using namespace tlp;

class NelderMead : public CPPPlugin
{
    friend class nmWorker;

    public:
        Property<string>                        mSBML;                          //This is the model
        Property<TelluriumData>				    mExperimentalData;
        Property<TelluriumData>			        mModelData;

        Property<Properties>                    mInputParameterList;            //Parameters to fit
        Property<Properties>                    mOutputParameterList;           //Parameters that was fitted
        Property<Properties>                    mConfidenceLimits;              //Confidence limits for each parameter

        Property<tlp::StringList>               mExperimentalDataSelectionList; //Species selection list for observed data
        Property<tlp::StringList>               mModelDataSelectionList;        //Species selection list for observed data
        Property<int>                           mNrOfIter;                      //Part of minimization result

        //LMFIT Tuning parameters
//        Property<double>                        ftol;                           /* relative error desired in the sum of squares. */
//        Property<double>                        xtol;                           /* relative error between last two approximations. */
//        Property<double>                        gtol;                           /* orthogonality desired between fvec and its derivs. */
//        Property<double>                        epsilon;                        /* step used to calculate the jacobian. */
//        Property<double>                        stepbound;                      /* initial bound to steps in the outer loop. */
//        Property<int>                           patience;                       /* maximum number of iterations. */

        //Output data
        Property<string>                        mStatusMessage;                 //Message regarding the status of the fit
        Property<double>                        mNorm;                          //Part of minimization result
        Property<TelluriumData>                 mNorms;                         //Norm values from the fitting
        TelluriumData&                          rNormsData;                     //Setup a reference to Norms Data

        Property<TelluriumData>			        mResidualsData;                 //Residuals from the fitting
        Property<TelluriumData>			        mStandardizedResiduals;         //Standardized Residuals from the fitting
        Property<TelluriumData>			        mNormalProbabilityOfResiduals;  //Normal probability of residuals, Q-Q plot
        Property<double>			            mChiSquare;                     //Chi square for the fitting
        Property<double>			            mReducedChiSquare;              //Reduced Chi Square

        Property< ls::Matrix<double> >          mHessian;                       //Hessian
        Property< ls::Matrix<double> >          mCovarianceMatrix;              //Covariance Matrix

		//Utility functions for the thread
        string                                  getTempFolder();
        string                                  getSBML();

//		nmDataStructure							&mLMData;        //LevenbergMarq.. data structure

    protected:
        //The worker is doing the work
        nmWorker                                mWorker;

    public:
                                                NelderMead(PluginManager* manager);
                                               ~NelderMead();

        bool                                    execute(bool inThread = false);
        string                                  getResult();
        bool                                    resetPlugin();
        string                                  getImplementationLanguage();
        string                                  getStatus();
        bool                                    isWorking() const;

        unsigned char*                          getManualAsPDF() const;
        unsigned int                            getPDFManualByteSize();
        tlp::StringList                         getExperimentalDataSelectionList();
        void                                    assignPropertyDescriptions();
};

extern "C"
{
RR_PLUGIN_DECLSPEC NelderMead* plugins_cc       createPlugin(void* manager);
RR_PLUGIN_DECLSPEC const char* plugins_cc       getImplementationLanguage();
}

#endif
