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
ROOT::RDF::RNode GoodElElPairFilter_ee (ROOT::RDF::RNode df0, OnnxSessionManager &onnxSessionManager, CorrectionManager &correctionManager) {

        auto df1 = ditau_pairselection::flagGoodPairs(df0, "PG_internal_quantity_34", "dileptonpair");
    auto df2 = ditau_pairselection::flagGoodPairs(df1, "PG_internal_quantity_34__eleEsResoDown", "dileptonpair__eleEsResoDown");
    auto df3 = ditau_pairselection::flagGoodPairs(df2, "PG_internal_quantity_34__eleEsScaleUp", "dileptonpair__eleEsScaleUp");
    auto df4 = ditau_pairselection::flagGoodPairs(df3, "PG_internal_quantity_34__eleEsResoUp", "dileptonpair__eleEsResoUp");
    auto df5 = ditau_pairselection::flagGoodPairs(df4, "PG_internal_quantity_34__eleEsScaleDown", "dileptonpair__eleEsScaleDown");
    auto df6 = basefunctions::FilterFlagsAny(df5, "GoodElElPairs", "PG_internal_quantity_34", "PG_internal_quantity_34__eleEsResoDown", "PG_internal_quantity_34__eleEsScaleUp", "PG_internal_quantity_34__eleEsResoUp", "PG_internal_quantity_34__eleEsScaleDown");
    return df6;

}
