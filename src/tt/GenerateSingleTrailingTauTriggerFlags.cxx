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
ROOT::RDF::RNode GenerateSingleTrailingTauTriggerFlags_tt (ROOT::RDF::RNode df0, OnnxSessionManager &onnxSessionManager, CorrectionManager &correctionManager) {

        auto df1 = trigger::GenerateSingleTriggerFlag(df0, "trg_single_tau180_2", "p4_2", "TrigObj_filterBits", "TrigObj_id", "TrigObj_pt", "TrigObj_eta", "TrigObj_phi", "HLT_MediumChargedIsoPFTau180HighPtRelaxedIso_Trk50_eta2p1", 180, 2.1, 15, 5, 0.4 );
    auto df2 = trigger::GenerateSingleTriggerFlag(df1, "trg_single_tau180_2__tauEs3prong1pizeroDown", "p4_2__tauEs3prong1pizeroDown", "TrigObj_filterBits", "TrigObj_id", "TrigObj_pt", "TrigObj_eta", "TrigObj_phi", "HLT_MediumChargedIsoPFTau180HighPtRelaxedIso_Trk50_eta2p1", 180, 2.1, 15, 5, 0.4 );
    auto df3 = trigger::GenerateSingleTriggerFlag(df2, "trg_single_tau180_2__tauEs1prong0pizeroDown", "p4_2__tauEs1prong0pizeroDown", "TrigObj_filterBits", "TrigObj_id", "TrigObj_pt", "TrigObj_eta", "TrigObj_phi", "HLT_MediumChargedIsoPFTau180HighPtRelaxedIso_Trk50_eta2p1", 180, 2.1, 15, 5, 0.4 );
    auto df4 = trigger::GenerateSingleTriggerFlag(df3, "trg_single_tau180_2__tauEs3prong1pizeroUp", "p4_2__tauEs3prong1pizeroUp", "TrigObj_filterBits", "TrigObj_id", "TrigObj_pt", "TrigObj_eta", "TrigObj_phi", "HLT_MediumChargedIsoPFTau180HighPtRelaxedIso_Trk50_eta2p1", 180, 2.1, 15, 5, 0.4 );
    auto df5 = trigger::GenerateSingleTriggerFlag(df4, "trg_single_tau180_2__tauEs1prong1pizeroDown", "p4_2__tauEs1prong1pizeroDown", "TrigObj_filterBits", "TrigObj_id", "TrigObj_pt", "TrigObj_eta", "TrigObj_phi", "HLT_MediumChargedIsoPFTau180HighPtRelaxedIso_Trk50_eta2p1", 180, 2.1, 15, 5, 0.4 );
    auto df6 = trigger::GenerateSingleTriggerFlag(df5, "trg_single_tau180_2__tauEs1prong1pizeroUp", "p4_2__tauEs1prong1pizeroUp", "TrigObj_filterBits", "TrigObj_id", "TrigObj_pt", "TrigObj_eta", "TrigObj_phi", "HLT_MediumChargedIsoPFTau180HighPtRelaxedIso_Trk50_eta2p1", 180, 2.1, 15, 5, 0.4 );
    auto df7 = trigger::GenerateSingleTriggerFlag(df6, "trg_single_tau180_2__tauEs1prong0pizeroUp", "p4_2__tauEs1prong0pizeroUp", "TrigObj_filterBits", "TrigObj_id", "TrigObj_pt", "TrigObj_eta", "TrigObj_phi", "HLT_MediumChargedIsoPFTau180HighPtRelaxedIso_Trk50_eta2p1", 180, 2.1, 15, 5, 0.4 );
    auto df8 = trigger::GenerateSingleTriggerFlag(df7, "trg_single_tau180_2__tauEs3prong0pizeroDown", "p4_2__tauEs3prong0pizeroDown", "TrigObj_filterBits", "TrigObj_id", "TrigObj_pt", "TrigObj_eta", "TrigObj_phi", "HLT_MediumChargedIsoPFTau180HighPtRelaxedIso_Trk50_eta2p1", 180, 2.1, 15, 5, 0.4 );
    auto df9 = trigger::GenerateSingleTriggerFlag(df8, "trg_single_tau180_2__tauEs3prong0pizeroUp", "p4_2__tauEs3prong0pizeroUp", "TrigObj_filterBits", "TrigObj_id", "TrigObj_pt", "TrigObj_eta", "TrigObj_phi", "HLT_MediumChargedIsoPFTau180HighPtRelaxedIso_Trk50_eta2p1", 180, 2.1, 15, 5, 0.4 );
    return df9;

}
