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
ROOT::RDF::RNode NumberOfGoodTaus_et (ROOT::RDF::RNode df0, OnnxSessionManager &onnxSessionManager, CorrectionManager &correctionManager) {

        auto df1 = quantities::NumberOfGoodLeptons(df0, "ntaus", "good_taus_mask");
    auto df2 = quantities::NumberOfGoodLeptons(df1, "ntaus__tauEs3prong1pizeroDown", "good_taus_mask__tauEs3prong1pizeroDown");
    auto df3 = quantities::NumberOfGoodLeptons(df2, "ntaus__tauEs1prong0pizeroDown", "good_taus_mask__tauEs1prong0pizeroDown");
    auto df4 = quantities::NumberOfGoodLeptons(df3, "ntaus__tauEs3prong1pizeroUp", "good_taus_mask__tauEs3prong1pizeroUp");
    auto df5 = quantities::NumberOfGoodLeptons(df4, "ntaus__tauEs1prong1pizeroDown", "good_taus_mask__tauEs1prong1pizeroDown");
    auto df6 = quantities::NumberOfGoodLeptons(df5, "ntaus__tauEs1prong1pizeroUp", "good_taus_mask__tauEs1prong1pizeroUp");
    auto df7 = quantities::NumberOfGoodLeptons(df6, "ntaus__tauEs1prong0pizeroUp", "good_taus_mask__tauEs1prong0pizeroUp");
    auto df8 = quantities::NumberOfGoodLeptons(df7, "ntaus__tauEs3prong0pizeroDown", "good_taus_mask__tauEs3prong0pizeroDown");
    auto df9 = quantities::NumberOfGoodLeptons(df8, "ntaus__tauEs3prong0pizeroUp", "good_taus_mask__tauEs3prong0pizeroUp");
    return df9;

}
