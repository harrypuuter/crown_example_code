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
ROOT::RDF::RNode SampleFlags_global (ROOT::RDF::RNode df0, OnnxSessionManager &onnxSessionManager, CorrectionManager &correctionManager) {

        auto df1 = basefunctions::DefineQuantity(df0, "is_data", false);
    auto df2 = basefunctions::DefineQuantity(df1, "is_embedding", false);
    auto df3 = basefunctions::DefineQuantity(df2, "is_ttbar", true);
    auto df4 = basefunctions::DefineQuantity(df3, "is_dyjets", false);
    auto df5 = basefunctions::DefineQuantity(df4, "is_wjets", false);
    auto df6 = basefunctions::DefineQuantity(df5, "is_ggh_htautau", false);
    auto df7 = basefunctions::DefineQuantity(df6, "is_vbf_htautau", false);
    auto df8 = basefunctions::DefineQuantity(df7, "is_diboson", false);
    auto df9 = basefunctions::DefineQuantity(df8, "is_ggh_hbb", false);
    auto df10 = basefunctions::DefineQuantity(df9, "is_vbf_hbb", false);
    auto df11 = basefunctions::DefineQuantity(df10, "is_rem_hbb", false);
    auto df12 = basefunctions::DefineQuantity(df11, "is_embedding_mc", false);
    auto df13 = basefunctions::DefineQuantity(df12, "is_singletop", false);
    auto df14 = basefunctions::DefineQuantity(df13, "is_rem_htautau", false);
    auto df15 = basefunctions::DefineQuantity(df14, "is_electroweak_boson", false);
    return df15;

}
