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
ROOT::RDF::RNode TTGenerateDoubleTriggerFlags_tt (ROOT::RDF::RNode df0, OnnxSessionManager &onnxSessionManager, CorrectionManager &correctionManager) {

        auto df1 = trigger::GenerateDoubleTriggerFlag(df0, "trg_double_tau35_mediumiso_hps", "p4_1", "p4_2", "TrigObj_filterBits", "TrigObj_id", "TrigObj_pt", "TrigObj_eta", "TrigObj_phi", "HLT_DoubleMediumChargedIsoPFTauHPS35_Trk1_eta2p1_Reg", 40, 40, 2.1, 2.1, 15, 15, -1, -1, 0.4);
    auto df2 = trigger::GenerateDoubleTriggerFlag(df1, "trg_double_tau40_tightiso", "p4_1", "p4_2", "TrigObj_filterBits", "TrigObj_id", "TrigObj_pt", "TrigObj_eta", "TrigObj_phi", "HLT_DoubleTightChargedIsoPFTau40_Trk1_eta2p1_Reg", 40, 40, 2.1, 2.1, 15, 15, -1, -1, 0.4);
    auto df3 = trigger::GenerateDoubleTriggerFlag(df2, "trg_double_tau40_mediumiso_tightid", "p4_1", "p4_2", "TrigObj_filterBits", "TrigObj_id", "TrigObj_pt", "TrigObj_eta", "TrigObj_phi", "HLT_DoubleMediumChargedIsoPFTau40_Trk1_TightID_eta2p1_Reg", 40, 40, 2.1, 2.1, 15, 15, -1, -1, 0.4);
    auto df4 = trigger::GenerateDoubleTriggerFlag(df3, "trg_double_tau35_tightiso_tightid", "p4_1", "p4_2", "TrigObj_filterBits", "TrigObj_id", "TrigObj_pt", "TrigObj_eta", "TrigObj_phi", "HLT_DoubleTightChargedIsoPFTau35_Trk1_TightID_eta2p1_Reg", 40, 40, 2.1, 2.1, 15, 15, 6, 6, 0.4);
    auto df5 = trigger::GenerateDoubleTriggerFlag(df4, "trg_double_tau35_mediumiso_hps__tauEs3prong1pizeroDown", "p4_1__tauEs3prong1pizeroDown", "p4_2__tauEs3prong1pizeroDown", "TrigObj_filterBits", "TrigObj_id", "TrigObj_pt", "TrigObj_eta", "TrigObj_phi", "HLT_DoubleMediumChargedIsoPFTauHPS35_Trk1_eta2p1_Reg", 40, 40, 2.1, 2.1, 15, 15, -1, -1, 0.4);
    auto df6 = trigger::GenerateDoubleTriggerFlag(df5, "trg_double_tau40_tightiso__tauEs3prong1pizeroDown", "p4_1__tauEs3prong1pizeroDown", "p4_2__tauEs3prong1pizeroDown", "TrigObj_filterBits", "TrigObj_id", "TrigObj_pt", "TrigObj_eta", "TrigObj_phi", "HLT_DoubleTightChargedIsoPFTau40_Trk1_eta2p1_Reg", 40, 40, 2.1, 2.1, 15, 15, -1, -1, 0.4);
    auto df7 = trigger::GenerateDoubleTriggerFlag(df6, "trg_double_tau40_mediumiso_tightid__tauEs3prong1pizeroDown", "p4_1__tauEs3prong1pizeroDown", "p4_2__tauEs3prong1pizeroDown", "TrigObj_filterBits", "TrigObj_id", "TrigObj_pt", "TrigObj_eta", "TrigObj_phi", "HLT_DoubleMediumChargedIsoPFTau40_Trk1_TightID_eta2p1_Reg", 40, 40, 2.1, 2.1, 15, 15, -1, -1, 0.4);
    auto df8 = trigger::GenerateDoubleTriggerFlag(df7, "trg_double_tau35_tightiso_tightid__tauEs3prong1pizeroDown", "p4_1__tauEs3prong1pizeroDown", "p4_2__tauEs3prong1pizeroDown", "TrigObj_filterBits", "TrigObj_id", "TrigObj_pt", "TrigObj_eta", "TrigObj_phi", "HLT_DoubleTightChargedIsoPFTau35_Trk1_TightID_eta2p1_Reg", 40, 40, 2.1, 2.1, 15, 15, 6, 6, 0.4);
    auto df9 = trigger::GenerateDoubleTriggerFlag(df8, "trg_double_tau35_mediumiso_hps__tauEs1prong0pizeroDown", "p4_1__tauEs1prong0pizeroDown", "p4_2__tauEs1prong0pizeroDown", "TrigObj_filterBits", "TrigObj_id", "TrigObj_pt", "TrigObj_eta", "TrigObj_phi", "HLT_DoubleMediumChargedIsoPFTauHPS35_Trk1_eta2p1_Reg", 40, 40, 2.1, 2.1, 15, 15, -1, -1, 0.4);
    auto df10 = trigger::GenerateDoubleTriggerFlag(df9, "trg_double_tau40_tightiso__tauEs1prong0pizeroDown", "p4_1__tauEs1prong0pizeroDown", "p4_2__tauEs1prong0pizeroDown", "TrigObj_filterBits", "TrigObj_id", "TrigObj_pt", "TrigObj_eta", "TrigObj_phi", "HLT_DoubleTightChargedIsoPFTau40_Trk1_eta2p1_Reg", 40, 40, 2.1, 2.1, 15, 15, -1, -1, 0.4);
    auto df11 = trigger::GenerateDoubleTriggerFlag(df10, "trg_double_tau40_mediumiso_tightid__tauEs1prong0pizeroDown", "p4_1__tauEs1prong0pizeroDown", "p4_2__tauEs1prong0pizeroDown", "TrigObj_filterBits", "TrigObj_id", "TrigObj_pt", "TrigObj_eta", "TrigObj_phi", "HLT_DoubleMediumChargedIsoPFTau40_Trk1_TightID_eta2p1_Reg", 40, 40, 2.1, 2.1, 15, 15, -1, -1, 0.4);
    auto df12 = trigger::GenerateDoubleTriggerFlag(df11, "trg_double_tau35_tightiso_tightid__tauEs1prong0pizeroDown", "p4_1__tauEs1prong0pizeroDown", "p4_2__tauEs1prong0pizeroDown", "TrigObj_filterBits", "TrigObj_id", "TrigObj_pt", "TrigObj_eta", "TrigObj_phi", "HLT_DoubleTightChargedIsoPFTau35_Trk1_TightID_eta2p1_Reg", 40, 40, 2.1, 2.1, 15, 15, 6, 6, 0.4);
    auto df13 = trigger::GenerateDoubleTriggerFlag(df12, "trg_double_tau35_mediumiso_hps__tauEs3prong1pizeroUp", "p4_1__tauEs3prong1pizeroUp", "p4_2__tauEs3prong1pizeroUp", "TrigObj_filterBits", "TrigObj_id", "TrigObj_pt", "TrigObj_eta", "TrigObj_phi", "HLT_DoubleMediumChargedIsoPFTauHPS35_Trk1_eta2p1_Reg", 40, 40, 2.1, 2.1, 15, 15, -1, -1, 0.4);
    auto df14 = trigger::GenerateDoubleTriggerFlag(df13, "trg_double_tau40_tightiso__tauEs3prong1pizeroUp", "p4_1__tauEs3prong1pizeroUp", "p4_2__tauEs3prong1pizeroUp", "TrigObj_filterBits", "TrigObj_id", "TrigObj_pt", "TrigObj_eta", "TrigObj_phi", "HLT_DoubleTightChargedIsoPFTau40_Trk1_eta2p1_Reg", 40, 40, 2.1, 2.1, 15, 15, -1, -1, 0.4);
    auto df15 = trigger::GenerateDoubleTriggerFlag(df14, "trg_double_tau40_mediumiso_tightid__tauEs3prong1pizeroUp", "p4_1__tauEs3prong1pizeroUp", "p4_2__tauEs3prong1pizeroUp", "TrigObj_filterBits", "TrigObj_id", "TrigObj_pt", "TrigObj_eta", "TrigObj_phi", "HLT_DoubleMediumChargedIsoPFTau40_Trk1_TightID_eta2p1_Reg", 40, 40, 2.1, 2.1, 15, 15, -1, -1, 0.4);
    auto df16 = trigger::GenerateDoubleTriggerFlag(df15, "trg_double_tau35_tightiso_tightid__tauEs3prong1pizeroUp", "p4_1__tauEs3prong1pizeroUp", "p4_2__tauEs3prong1pizeroUp", "TrigObj_filterBits", "TrigObj_id", "TrigObj_pt", "TrigObj_eta", "TrigObj_phi", "HLT_DoubleTightChargedIsoPFTau35_Trk1_TightID_eta2p1_Reg", 40, 40, 2.1, 2.1, 15, 15, 6, 6, 0.4);
    auto df17 = trigger::GenerateDoubleTriggerFlag(df16, "trg_double_tau35_mediumiso_hps__tauEs1prong1pizeroDown", "p4_1__tauEs1prong1pizeroDown", "p4_2__tauEs1prong1pizeroDown", "TrigObj_filterBits", "TrigObj_id", "TrigObj_pt", "TrigObj_eta", "TrigObj_phi", "HLT_DoubleMediumChargedIsoPFTauHPS35_Trk1_eta2p1_Reg", 40, 40, 2.1, 2.1, 15, 15, -1, -1, 0.4);
    auto df18 = trigger::GenerateDoubleTriggerFlag(df17, "trg_double_tau40_tightiso__tauEs1prong1pizeroDown", "p4_1__tauEs1prong1pizeroDown", "p4_2__tauEs1prong1pizeroDown", "TrigObj_filterBits", "TrigObj_id", "TrigObj_pt", "TrigObj_eta", "TrigObj_phi", "HLT_DoubleTightChargedIsoPFTau40_Trk1_eta2p1_Reg", 40, 40, 2.1, 2.1, 15, 15, -1, -1, 0.4);
    auto df19 = trigger::GenerateDoubleTriggerFlag(df18, "trg_double_tau40_mediumiso_tightid__tauEs1prong1pizeroDown", "p4_1__tauEs1prong1pizeroDown", "p4_2__tauEs1prong1pizeroDown", "TrigObj_filterBits", "TrigObj_id", "TrigObj_pt", "TrigObj_eta", "TrigObj_phi", "HLT_DoubleMediumChargedIsoPFTau40_Trk1_TightID_eta2p1_Reg", 40, 40, 2.1, 2.1, 15, 15, -1, -1, 0.4);
    auto df20 = trigger::GenerateDoubleTriggerFlag(df19, "trg_double_tau35_tightiso_tightid__tauEs1prong1pizeroDown", "p4_1__tauEs1prong1pizeroDown", "p4_2__tauEs1prong1pizeroDown", "TrigObj_filterBits", "TrigObj_id", "TrigObj_pt", "TrigObj_eta", "TrigObj_phi", "HLT_DoubleTightChargedIsoPFTau35_Trk1_TightID_eta2p1_Reg", 40, 40, 2.1, 2.1, 15, 15, 6, 6, 0.4);
    auto df21 = trigger::GenerateDoubleTriggerFlag(df20, "trg_double_tau35_mediumiso_hps__tauEs1prong1pizeroUp", "p4_1__tauEs1prong1pizeroUp", "p4_2__tauEs1prong1pizeroUp", "TrigObj_filterBits", "TrigObj_id", "TrigObj_pt", "TrigObj_eta", "TrigObj_phi", "HLT_DoubleMediumChargedIsoPFTauHPS35_Trk1_eta2p1_Reg", 40, 40, 2.1, 2.1, 15, 15, -1, -1, 0.4);
    auto df22 = trigger::GenerateDoubleTriggerFlag(df21, "trg_double_tau40_tightiso__tauEs1prong1pizeroUp", "p4_1__tauEs1prong1pizeroUp", "p4_2__tauEs1prong1pizeroUp", "TrigObj_filterBits", "TrigObj_id", "TrigObj_pt", "TrigObj_eta", "TrigObj_phi", "HLT_DoubleTightChargedIsoPFTau40_Trk1_eta2p1_Reg", 40, 40, 2.1, 2.1, 15, 15, -1, -1, 0.4);
    auto df23 = trigger::GenerateDoubleTriggerFlag(df22, "trg_double_tau40_mediumiso_tightid__tauEs1prong1pizeroUp", "p4_1__tauEs1prong1pizeroUp", "p4_2__tauEs1prong1pizeroUp", "TrigObj_filterBits", "TrigObj_id", "TrigObj_pt", "TrigObj_eta", "TrigObj_phi", "HLT_DoubleMediumChargedIsoPFTau40_Trk1_TightID_eta2p1_Reg", 40, 40, 2.1, 2.1, 15, 15, -1, -1, 0.4);
    auto df24 = trigger::GenerateDoubleTriggerFlag(df23, "trg_double_tau35_tightiso_tightid__tauEs1prong1pizeroUp", "p4_1__tauEs1prong1pizeroUp", "p4_2__tauEs1prong1pizeroUp", "TrigObj_filterBits", "TrigObj_id", "TrigObj_pt", "TrigObj_eta", "TrigObj_phi", "HLT_DoubleTightChargedIsoPFTau35_Trk1_TightID_eta2p1_Reg", 40, 40, 2.1, 2.1, 15, 15, 6, 6, 0.4);
    auto df25 = trigger::GenerateDoubleTriggerFlag(df24, "trg_double_tau35_mediumiso_hps__tauEs1prong0pizeroUp", "p4_1__tauEs1prong0pizeroUp", "p4_2__tauEs1prong0pizeroUp", "TrigObj_filterBits", "TrigObj_id", "TrigObj_pt", "TrigObj_eta", "TrigObj_phi", "HLT_DoubleMediumChargedIsoPFTauHPS35_Trk1_eta2p1_Reg", 40, 40, 2.1, 2.1, 15, 15, -1, -1, 0.4);
    auto df26 = trigger::GenerateDoubleTriggerFlag(df25, "trg_double_tau40_tightiso__tauEs1prong0pizeroUp", "p4_1__tauEs1prong0pizeroUp", "p4_2__tauEs1prong0pizeroUp", "TrigObj_filterBits", "TrigObj_id", "TrigObj_pt", "TrigObj_eta", "TrigObj_phi", "HLT_DoubleTightChargedIsoPFTau40_Trk1_eta2p1_Reg", 40, 40, 2.1, 2.1, 15, 15, -1, -1, 0.4);
    auto df27 = trigger::GenerateDoubleTriggerFlag(df26, "trg_double_tau40_mediumiso_tightid__tauEs1prong0pizeroUp", "p4_1__tauEs1prong0pizeroUp", "p4_2__tauEs1prong0pizeroUp", "TrigObj_filterBits", "TrigObj_id", "TrigObj_pt", "TrigObj_eta", "TrigObj_phi", "HLT_DoubleMediumChargedIsoPFTau40_Trk1_TightID_eta2p1_Reg", 40, 40, 2.1, 2.1, 15, 15, -1, -1, 0.4);
    auto df28 = trigger::GenerateDoubleTriggerFlag(df27, "trg_double_tau35_tightiso_tightid__tauEs1prong0pizeroUp", "p4_1__tauEs1prong0pizeroUp", "p4_2__tauEs1prong0pizeroUp", "TrigObj_filterBits", "TrigObj_id", "TrigObj_pt", "TrigObj_eta", "TrigObj_phi", "HLT_DoubleTightChargedIsoPFTau35_Trk1_TightID_eta2p1_Reg", 40, 40, 2.1, 2.1, 15, 15, 6, 6, 0.4);
    auto df29 = trigger::GenerateDoubleTriggerFlag(df28, "trg_double_tau35_mediumiso_hps__tauEs3prong0pizeroDown", "p4_1__tauEs3prong0pizeroDown", "p4_2__tauEs3prong0pizeroDown", "TrigObj_filterBits", "TrigObj_id", "TrigObj_pt", "TrigObj_eta", "TrigObj_phi", "HLT_DoubleMediumChargedIsoPFTauHPS35_Trk1_eta2p1_Reg", 40, 40, 2.1, 2.1, 15, 15, -1, -1, 0.4);
    auto df30 = trigger::GenerateDoubleTriggerFlag(df29, "trg_double_tau40_tightiso__tauEs3prong0pizeroDown", "p4_1__tauEs3prong0pizeroDown", "p4_2__tauEs3prong0pizeroDown", "TrigObj_filterBits", "TrigObj_id", "TrigObj_pt", "TrigObj_eta", "TrigObj_phi", "HLT_DoubleTightChargedIsoPFTau40_Trk1_eta2p1_Reg", 40, 40, 2.1, 2.1, 15, 15, -1, -1, 0.4);
    auto df31 = trigger::GenerateDoubleTriggerFlag(df30, "trg_double_tau40_mediumiso_tightid__tauEs3prong0pizeroDown", "p4_1__tauEs3prong0pizeroDown", "p4_2__tauEs3prong0pizeroDown", "TrigObj_filterBits", "TrigObj_id", "TrigObj_pt", "TrigObj_eta", "TrigObj_phi", "HLT_DoubleMediumChargedIsoPFTau40_Trk1_TightID_eta2p1_Reg", 40, 40, 2.1, 2.1, 15, 15, -1, -1, 0.4);
    auto df32 = trigger::GenerateDoubleTriggerFlag(df31, "trg_double_tau35_tightiso_tightid__tauEs3prong0pizeroDown", "p4_1__tauEs3prong0pizeroDown", "p4_2__tauEs3prong0pizeroDown", "TrigObj_filterBits", "TrigObj_id", "TrigObj_pt", "TrigObj_eta", "TrigObj_phi", "HLT_DoubleTightChargedIsoPFTau35_Trk1_TightID_eta2p1_Reg", 40, 40, 2.1, 2.1, 15, 15, 6, 6, 0.4);
    auto df33 = trigger::GenerateDoubleTriggerFlag(df32, "trg_double_tau35_mediumiso_hps__tauEs3prong0pizeroUp", "p4_1__tauEs3prong0pizeroUp", "p4_2__tauEs3prong0pizeroUp", "TrigObj_filterBits", "TrigObj_id", "TrigObj_pt", "TrigObj_eta", "TrigObj_phi", "HLT_DoubleMediumChargedIsoPFTauHPS35_Trk1_eta2p1_Reg", 40, 40, 2.1, 2.1, 15, 15, -1, -1, 0.4);
    auto df34 = trigger::GenerateDoubleTriggerFlag(df33, "trg_double_tau40_tightiso__tauEs3prong0pizeroUp", "p4_1__tauEs3prong0pizeroUp", "p4_2__tauEs3prong0pizeroUp", "TrigObj_filterBits", "TrigObj_id", "TrigObj_pt", "TrigObj_eta", "TrigObj_phi", "HLT_DoubleTightChargedIsoPFTau40_Trk1_eta2p1_Reg", 40, 40, 2.1, 2.1, 15, 15, -1, -1, 0.4);
    auto df35 = trigger::GenerateDoubleTriggerFlag(df34, "trg_double_tau40_mediumiso_tightid__tauEs3prong0pizeroUp", "p4_1__tauEs3prong0pizeroUp", "p4_2__tauEs3prong0pizeroUp", "TrigObj_filterBits", "TrigObj_id", "TrigObj_pt", "TrigObj_eta", "TrigObj_phi", "HLT_DoubleMediumChargedIsoPFTau40_Trk1_TightID_eta2p1_Reg", 40, 40, 2.1, 2.1, 15, 15, -1, -1, 0.4);
    auto df36 = trigger::GenerateDoubleTriggerFlag(df35, "trg_double_tau35_tightiso_tightid__tauEs3prong0pizeroUp", "p4_1__tauEs3prong0pizeroUp", "p4_2__tauEs3prong0pizeroUp", "TrigObj_filterBits", "TrigObj_id", "TrigObj_pt", "TrigObj_eta", "TrigObj_phi", "HLT_DoubleTightChargedIsoPFTau35_Trk1_TightID_eta2p1_Reg", 40, 40, 2.1, 2.1, 15, 15, 6, 6, 0.4);
    return df36;

}
