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
ROOT::RDF::RNode LVTau2Uncorrected_et (ROOT::RDF::RNode df0, OnnxSessionManager &onnxSessionManager, CorrectionManager &correctionManager) {

        auto df1 = lorentzvectors::build(df0, {"dileptonpair","Tau_pt","Tau_eta","Tau_phi","Tau_mass"}, 1, "p4_2_uncorrected");
    auto df2 = lorentzvectors::build(df1, {"dileptonpair__tauEs3prong1pizeroDown","Tau_pt","Tau_eta","Tau_phi","Tau_mass"}, 1, "p4_2_uncorrected__tauEs3prong1pizeroDown");
    auto df3 = lorentzvectors::build(df2, {"dileptonpair__eleEsResoUp","Tau_pt","Tau_eta","Tau_phi","Tau_mass"}, 1, "p4_2_uncorrected__eleEsResoUp");
    auto df4 = lorentzvectors::build(df3, {"dileptonpair__tauEs3prong0pizeroDown","Tau_pt","Tau_eta","Tau_phi","Tau_mass"}, 1, "p4_2_uncorrected__tauEs3prong0pizeroDown");
    auto df5 = lorentzvectors::build(df4, {"dileptonpair__tauEs1prong0pizeroDown","Tau_pt","Tau_eta","Tau_phi","Tau_mass"}, 1, "p4_2_uncorrected__tauEs1prong0pizeroDown");
    auto df6 = lorentzvectors::build(df5, {"dileptonpair__tauEs3prong1pizeroUp","Tau_pt","Tau_eta","Tau_phi","Tau_mass"}, 1, "p4_2_uncorrected__tauEs3prong1pizeroUp");
    auto df7 = lorentzvectors::build(df6, {"dileptonpair__tauEs1prong1pizeroDown","Tau_pt","Tau_eta","Tau_phi","Tau_mass"}, 1, "p4_2_uncorrected__tauEs1prong1pizeroDown");
    auto df8 = lorentzvectors::build(df7, {"dileptonpair__tauEs1prong1pizeroUp","Tau_pt","Tau_eta","Tau_phi","Tau_mass"}, 1, "p4_2_uncorrected__tauEs1prong1pizeroUp");
    auto df9 = lorentzvectors::build(df8, {"dileptonpair__eleEsResoDown","Tau_pt","Tau_eta","Tau_phi","Tau_mass"}, 1, "p4_2_uncorrected__eleEsResoDown");
    auto df10 = lorentzvectors::build(df9, {"dileptonpair__tauEs1prong0pizeroUp","Tau_pt","Tau_eta","Tau_phi","Tau_mass"}, 1, "p4_2_uncorrected__tauEs1prong0pizeroUp");
    auto df11 = lorentzvectors::build(df10, {"dileptonpair__eleEsScaleDown","Tau_pt","Tau_eta","Tau_phi","Tau_mass"}, 1, "p4_2_uncorrected__eleEsScaleDown");
    auto df12 = lorentzvectors::build(df11, {"dileptonpair__tauEs3prong0pizeroUp","Tau_pt","Tau_eta","Tau_phi","Tau_mass"}, 1, "p4_2_uncorrected__tauEs3prong0pizeroUp");
    auto df13 = lorentzvectors::build(df12, {"dileptonpair__eleEsScaleUp","Tau_pt","Tau_eta","Tau_phi","Tau_mass"}, 1, "p4_2_uncorrected__eleEsScaleUp");
    return df13;

}
