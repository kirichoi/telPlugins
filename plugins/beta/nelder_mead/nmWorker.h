#ifndef nmWorkerH
#define nmWorkerH
#include <vector>
#include "Poco/Thread.h"
#include "Poco/Runnable.h"
#include "rr/rrRoadRunner.h"
#include "nmUtils.h"
#include "telTelluriumData.h"
#include "telProperties.h"
//---------------------------------------------------------------------------

using std::vector;
using tlp::TelluriumData;
using tlp::Properties;

class NelderMead;

class nmWorker : public Poco::Runnable
{
    friend NelderMead;

    public:
                                    nmWorker(NelderMead& host);
        void                        start(bool runInThread = true);
        void                        run();
        bool                        isRunning() const;

    protected:
        rr::RoadRunner             *mRRI;
        Poco::Thread                mThread;

        NelderMead&                 mHost;

        bool                        setupRoadRunner();
        bool                        setup();
        void                        createModelData(TelluriumData* data);
        void                        createResidualsData(TelluriumData* data);
        void                        workerStarted();
        void                        workerFinished();

        void                        postFittingWork();
        void                        calculateChiSquare();
        void                        calculateHessian();
        void                        calculateCovariance();
        void                        calculateConfidenceLimits();
        double                      getChi(const Properties& parameters);

};

#endif
