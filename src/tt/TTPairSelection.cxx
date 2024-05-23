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
ROOT::RDF::RNode TTPairSelection_tt (ROOT::RDF::RNode df0, OnnxSessionManager &onnxSessionManager, CorrectionManager &correctionManager) {

        auto df1 = ditau_pairselection::tautau::PairSelection(df0, {"Tau_pt_corrected","Tau_eta","Tau_phi","Tau_mass","Tau_rawDeepTau2017v2p1VSjet","good_taus_mask"}, "dileptonpair", 0.5);
    auto df2 = ditau_pairselection::tautau::PairSelection(df1, {"Tau_pt_corrected__tauEs3prong1pizeroDown","Tau_eta","Tau_phi","Tau_mass","Tau_rawDeepTau2017v2p1VSjet","good_taus_mask__tauEs3prong1pizeroDown"}, "dileptonpair__tauEs3prong1pizeroDown", 0.5);
    auto df3 = ditau_pairselection::tautau::PairSelection(df2, {"Tau_pt_corrected__tauEs1prong0pizeroDown","Tau_eta","Tau_phi","Tau_mass","Tau_rawDeepTau2017v2p1VSjet","good_taus_mask__tauEs1prong0pizeroDown"}, "dileptonpair__tauEs1prong0pizeroDown", 0.5);
    auto df4 = ditau_pairselection::tautau::PairSelection(df3, {"Tau_pt_corrected__tauEs3prong1pizeroUp","Tau_eta","Tau_phi","Tau_mass","Tau_rawDeepTau2017v2p1VSjet","good_taus_mask__tauEs3prong1pizeroUp"}, "dileptonpair__tauEs3prong1pizeroUp", 0.5);
    auto df5 = ditau_pairselection::tautau::PairSelection(df4, {"Tau_pt_corrected__tauEs1prong1pizeroDown","Tau_eta","Tau_phi","Tau_mass","Tau_rawDeepTau2017v2p1VSjet","good_taus_mask__tauEs1prong1pizeroDown"}, "dileptonpair__tauEs1prong1pizeroDown", 0.5);
    auto df6 = ditau_pairselection::tautau::PairSelection(df5, {"Tau_pt_corrected__tauEs1prong1pizeroUp","Tau_eta","Tau_phi","Tau_mass","Tau_rawDeepTau2017v2p1VSjet","good_taus_mask__tauEs1prong1pizeroUp"}, "dileptonpair__tauEs1prong1pizeroUp", 0.5);
    auto df7 = ditau_pairselection::tautau::PairSelection(df6, {"Tau_pt_corrected__tauEs1prong0pizeroUp","Tau_eta","Tau_phi","Tau_mass","Tau_rawDeepTau2017v2p1VSjet","good_taus_mask__tauEs1prong0pizeroUp"}, "dileptonpair__tauEs1prong0pizeroUp", 0.5);
    auto df8 = ditau_pairselection::tautau::PairSelection(df7, {"Tau_pt_corrected__tauEs3prong0pizeroDown","Tau_eta","Tau_phi","Tau_mass","Tau_rawDeepTau2017v2p1VSjet","good_taus_mask__tauEs3prong0pizeroDown"}, "dileptonpair__tauEs3prong0pizeroDown", 0.5);
    auto df9 = ditau_pairselection::tautau::PairSelection(df8, {"Tau_pt_corrected__tauEs3prong0pizeroUp","Tau_eta","Tau_phi","Tau_mass","Tau_rawDeepTau2017v2p1VSjet","good_taus_mask__tauEs3prong0pizeroUp"}, "dileptonpair__tauEs3prong0pizeroUp", 0.5);
    return df9;

}
