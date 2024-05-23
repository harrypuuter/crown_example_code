#include "ROOT/RDataFrame.hxx"
#include "ROOT/RDFHelpers.hxx"
#include "RooTrace.h"
#include "TStopwatch.h"
#include <ROOT/RLogger.hxx>
#include "include/utility/Logger.hxx"
#include <TFile.h>
#include <TMap.h>
#include <filesystem>
#include <TObjString.h>
#include <TTree.h>
#include <TVector.h>
#include "onnxruntime_cxx_api.h"
#include <regex>
#include <string>
#include "include/utility/OnnxSessionManager.hxx"
#include "include/utility/CorrectionManager.hxx"
#include "include/genparticles.hxx"
#include "include/htxs.hxx"
#include "include/jets.hxx"
#include "include/lorentzvectors.hxx"
#include "include/met.hxx"
#include "include/ml.hxx"
#include "include/metfilter.hxx"
#include "include/pairselection.hxx"
#include "include/tripleselection.hxx"
#include "include/physicsobjects.hxx"
#include "include/quantities.hxx"
#include "include/reweighting.hxx"
#include "include/scalefactors.hxx"
#include "include/topreco.hxx"
#include "include/triggers.hxx"
#include "include/fakefactors.hxx"
ROOT::RDF::RNode GoodTTPairFilter_tt (ROOT::RDF::RNode df0, OnnxSessionManager &onnxSessionManager, CorrectionManager &correctionManager) {

        auto df1 = ditau_pairselection::flagGoodPairs(df0, "PG_internal_quantity_36", "dileptonpair");
    auto df2 = ditau_pairselection::flagGoodPairs(df1, "PG_internal_quantity_36__tauEs3prong1pizeroDown", "dileptonpair__tauEs3prong1pizeroDown");
    auto df3 = ditau_pairselection::flagGoodPairs(df2, "PG_internal_quantity_36__tauEs1prong0pizeroDown", "dileptonpair__tauEs1prong0pizeroDown");
    auto df4 = ditau_pairselection::flagGoodPairs(df3, "PG_internal_quantity_36__tauEs3prong1pizeroUp", "dileptonpair__tauEs3prong1pizeroUp");
    auto df5 = ditau_pairselection::flagGoodPairs(df4, "PG_internal_quantity_36__tauEs1prong1pizeroDown", "dileptonpair__tauEs1prong1pizeroDown");
    auto df6 = ditau_pairselection::flagGoodPairs(df5, "PG_internal_quantity_36__tauEs1prong1pizeroUp", "dileptonpair__tauEs1prong1pizeroUp");
    auto df7 = ditau_pairselection::flagGoodPairs(df6, "PG_internal_quantity_36__tauEs1prong0pizeroUp", "dileptonpair__tauEs1prong0pizeroUp");
    auto df8 = ditau_pairselection::flagGoodPairs(df7, "PG_internal_quantity_36__tauEs3prong0pizeroDown", "dileptonpair__tauEs3prong0pizeroDown");
    auto df9 = ditau_pairselection::flagGoodPairs(df8, "PG_internal_quantity_36__tauEs3prong0pizeroUp", "dileptonpair__tauEs3prong0pizeroUp");
    auto df10 = basefunctions::FilterFlagsAny(df9, "GoodTauTauPairs", "PG_internal_quantity_36", "PG_internal_quantity_36__tauEs3prong1pizeroDown", "PG_internal_quantity_36__tauEs1prong0pizeroDown", "PG_internal_quantity_36__tauEs3prong1pizeroUp", "PG_internal_quantity_36__tauEs1prong1pizeroDown", "PG_internal_quantity_36__tauEs1prong1pizeroUp", "PG_internal_quantity_36__tauEs1prong0pizeroUp", "PG_internal_quantity_36__tauEs3prong0pizeroDown", "PG_internal_quantity_36__tauEs3prong0pizeroUp");
    return df10;

}
