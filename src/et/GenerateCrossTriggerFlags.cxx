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
ROOT::RDF::RNode GenerateCrossTriggerFlags_et (ROOT::RDF::RNode df0, OnnxSessionManager &onnxSessionManager, CorrectionManager &correctionManager) {

        auto df1 = trigger::GenerateDoubleTriggerFlag(df0, "trg_cross_ele24tau30_hps", "p4_1", "p4_2", "TrigObj_filterBits", "TrigObj_id", "TrigObj_pt", "TrigObj_eta", "TrigObj_phi", "HLT_Ele24_eta2p1_WPTight_Gsf_LooseChargedIsoPFTauHPS30_eta2p1_CrossL1", 25, 32, 2.5, 2.1, 11, 15, 1, -1, 0.4);
    auto df2 = trigger::GenerateDoubleTriggerFlag(df1, "trg_cross_ele24tau30", "p4_1", "p4_2", "TrigObj_filterBits", "TrigObj_id", "TrigObj_pt", "TrigObj_eta", "TrigObj_phi", "HLT_Ele24_eta2p1_WPTight_Gsf_LooseChargedIsoPFTau30_eta2p1_CrossL1", 25, 32, 2.5, 2.1, 11, 15, 1, 4, 0.4);
    auto df3 = trigger::GenerateDoubleTriggerFlag(df2, "trg_cross_ele24tau30_hps__tauEs3prong1pizeroDown", "p4_1", "p4_2__tauEs3prong1pizeroDown", "TrigObj_filterBits", "TrigObj_id", "TrigObj_pt", "TrigObj_eta", "TrigObj_phi", "HLT_Ele24_eta2p1_WPTight_Gsf_LooseChargedIsoPFTauHPS30_eta2p1_CrossL1", 25, 32, 2.5, 2.1, 11, 15, 1, -1, 0.4);
    auto df4 = trigger::GenerateDoubleTriggerFlag(df3, "trg_cross_ele24tau30__tauEs3prong1pizeroDown", "p4_1", "p4_2__tauEs3prong1pizeroDown", "TrigObj_filterBits", "TrigObj_id", "TrigObj_pt", "TrigObj_eta", "TrigObj_phi", "HLT_Ele24_eta2p1_WPTight_Gsf_LooseChargedIsoPFTau30_eta2p1_CrossL1", 25, 32, 2.5, 2.1, 11, 15, 1, 4, 0.4);
    auto df5 = trigger::GenerateDoubleTriggerFlag(df4, "trg_cross_ele24tau30_hps__eleEsResoUp", "p4_1__eleEsResoUp", "p4_2__eleEsResoUp", "TrigObj_filterBits", "TrigObj_id", "TrigObj_pt", "TrigObj_eta", "TrigObj_phi", "HLT_Ele24_eta2p1_WPTight_Gsf_LooseChargedIsoPFTauHPS30_eta2p1_CrossL1", 25, 32, 2.5, 2.1, 11, 15, 1, -1, 0.4);
    auto df6 = trigger::GenerateDoubleTriggerFlag(df5, "trg_cross_ele24tau30__eleEsResoUp", "p4_1__eleEsResoUp", "p4_2__eleEsResoUp", "TrigObj_filterBits", "TrigObj_id", "TrigObj_pt", "TrigObj_eta", "TrigObj_phi", "HLT_Ele24_eta2p1_WPTight_Gsf_LooseChargedIsoPFTau30_eta2p1_CrossL1", 25, 32, 2.5, 2.1, 11, 15, 1, 4, 0.4);
    auto df7 = trigger::GenerateDoubleTriggerFlag(df6, "trg_cross_ele24tau30_hps__tauEs3prong0pizeroDown", "p4_1", "p4_2__tauEs3prong0pizeroDown", "TrigObj_filterBits", "TrigObj_id", "TrigObj_pt", "TrigObj_eta", "TrigObj_phi", "HLT_Ele24_eta2p1_WPTight_Gsf_LooseChargedIsoPFTauHPS30_eta2p1_CrossL1", 25, 32, 2.5, 2.1, 11, 15, 1, -1, 0.4);
    auto df8 = trigger::GenerateDoubleTriggerFlag(df7, "trg_cross_ele24tau30__tauEs3prong0pizeroDown", "p4_1", "p4_2__tauEs3prong0pizeroDown", "TrigObj_filterBits", "TrigObj_id", "TrigObj_pt", "TrigObj_eta", "TrigObj_phi", "HLT_Ele24_eta2p1_WPTight_Gsf_LooseChargedIsoPFTau30_eta2p1_CrossL1", 25, 32, 2.5, 2.1, 11, 15, 1, 4, 0.4);
    auto df9 = trigger::GenerateDoubleTriggerFlag(df8, "trg_cross_ele24tau30_hps__tauEs1prong0pizeroDown", "p4_1", "p4_2__tauEs1prong0pizeroDown", "TrigObj_filterBits", "TrigObj_id", "TrigObj_pt", "TrigObj_eta", "TrigObj_phi", "HLT_Ele24_eta2p1_WPTight_Gsf_LooseChargedIsoPFTauHPS30_eta2p1_CrossL1", 25, 32, 2.5, 2.1, 11, 15, 1, -1, 0.4);
    auto df10 = trigger::GenerateDoubleTriggerFlag(df9, "trg_cross_ele24tau30__tauEs1prong0pizeroDown", "p4_1", "p4_2__tauEs1prong0pizeroDown", "TrigObj_filterBits", "TrigObj_id", "TrigObj_pt", "TrigObj_eta", "TrigObj_phi", "HLT_Ele24_eta2p1_WPTight_Gsf_LooseChargedIsoPFTau30_eta2p1_CrossL1", 25, 32, 2.5, 2.1, 11, 15, 1, 4, 0.4);
    auto df11 = trigger::GenerateDoubleTriggerFlag(df10, "trg_cross_ele24tau30_hps__tauEs3prong1pizeroUp", "p4_1", "p4_2__tauEs3prong1pizeroUp", "TrigObj_filterBits", "TrigObj_id", "TrigObj_pt", "TrigObj_eta", "TrigObj_phi", "HLT_Ele24_eta2p1_WPTight_Gsf_LooseChargedIsoPFTauHPS30_eta2p1_CrossL1", 25, 32, 2.5, 2.1, 11, 15, 1, -1, 0.4);
    auto df12 = trigger::GenerateDoubleTriggerFlag(df11, "trg_cross_ele24tau30__tauEs3prong1pizeroUp", "p4_1", "p4_2__tauEs3prong1pizeroUp", "TrigObj_filterBits", "TrigObj_id", "TrigObj_pt", "TrigObj_eta", "TrigObj_phi", "HLT_Ele24_eta2p1_WPTight_Gsf_LooseChargedIsoPFTau30_eta2p1_CrossL1", 25, 32, 2.5, 2.1, 11, 15, 1, 4, 0.4);
    auto df13 = trigger::GenerateDoubleTriggerFlag(df12, "trg_cross_ele24tau30_hps__tauEs1prong1pizeroDown", "p4_1", "p4_2__tauEs1prong1pizeroDown", "TrigObj_filterBits", "TrigObj_id", "TrigObj_pt", "TrigObj_eta", "TrigObj_phi", "HLT_Ele24_eta2p1_WPTight_Gsf_LooseChargedIsoPFTauHPS30_eta2p1_CrossL1", 25, 32, 2.5, 2.1, 11, 15, 1, -1, 0.4);
    auto df14 = trigger::GenerateDoubleTriggerFlag(df13, "trg_cross_ele24tau30__tauEs1prong1pizeroDown", "p4_1", "p4_2__tauEs1prong1pizeroDown", "TrigObj_filterBits", "TrigObj_id", "TrigObj_pt", "TrigObj_eta", "TrigObj_phi", "HLT_Ele24_eta2p1_WPTight_Gsf_LooseChargedIsoPFTau30_eta2p1_CrossL1", 25, 32, 2.5, 2.1, 11, 15, 1, 4, 0.4);
    auto df15 = trigger::GenerateDoubleTriggerFlag(df14, "trg_cross_ele24tau30_hps__tauEs1prong1pizeroUp", "p4_1", "p4_2__tauEs1prong1pizeroUp", "TrigObj_filterBits", "TrigObj_id", "TrigObj_pt", "TrigObj_eta", "TrigObj_phi", "HLT_Ele24_eta2p1_WPTight_Gsf_LooseChargedIsoPFTauHPS30_eta2p1_CrossL1", 25, 32, 2.5, 2.1, 11, 15, 1, -1, 0.4);
    auto df16 = trigger::GenerateDoubleTriggerFlag(df15, "trg_cross_ele24tau30__tauEs1prong1pizeroUp", "p4_1", "p4_2__tauEs1prong1pizeroUp", "TrigObj_filterBits", "TrigObj_id", "TrigObj_pt", "TrigObj_eta", "TrigObj_phi", "HLT_Ele24_eta2p1_WPTight_Gsf_LooseChargedIsoPFTau30_eta2p1_CrossL1", 25, 32, 2.5, 2.1, 11, 15, 1, 4, 0.4);
    auto df17 = trigger::GenerateDoubleTriggerFlag(df16, "trg_cross_ele24tau30_hps__eleEsResoDown", "p4_1__eleEsResoDown", "p4_2__eleEsResoDown", "TrigObj_filterBits", "TrigObj_id", "TrigObj_pt", "TrigObj_eta", "TrigObj_phi", "HLT_Ele24_eta2p1_WPTight_Gsf_LooseChargedIsoPFTauHPS30_eta2p1_CrossL1", 25, 32, 2.5, 2.1, 11, 15, 1, -1, 0.4);
    auto df18 = trigger::GenerateDoubleTriggerFlag(df17, "trg_cross_ele24tau30__eleEsResoDown", "p4_1__eleEsResoDown", "p4_2__eleEsResoDown", "TrigObj_filterBits", "TrigObj_id", "TrigObj_pt", "TrigObj_eta", "TrigObj_phi", "HLT_Ele24_eta2p1_WPTight_Gsf_LooseChargedIsoPFTau30_eta2p1_CrossL1", 25, 32, 2.5, 2.1, 11, 15, 1, 4, 0.4);
    auto df19 = trigger::GenerateDoubleTriggerFlag(df18, "trg_cross_ele24tau30_hps__tauEs1prong0pizeroUp", "p4_1", "p4_2__tauEs1prong0pizeroUp", "TrigObj_filterBits", "TrigObj_id", "TrigObj_pt", "TrigObj_eta", "TrigObj_phi", "HLT_Ele24_eta2p1_WPTight_Gsf_LooseChargedIsoPFTauHPS30_eta2p1_CrossL1", 25, 32, 2.5, 2.1, 11, 15, 1, -1, 0.4);
    auto df20 = trigger::GenerateDoubleTriggerFlag(df19, "trg_cross_ele24tau30__tauEs1prong0pizeroUp", "p4_1", "p4_2__tauEs1prong0pizeroUp", "TrigObj_filterBits", "TrigObj_id", "TrigObj_pt", "TrigObj_eta", "TrigObj_phi", "HLT_Ele24_eta2p1_WPTight_Gsf_LooseChargedIsoPFTau30_eta2p1_CrossL1", 25, 32, 2.5, 2.1, 11, 15, 1, 4, 0.4);
    auto df21 = trigger::GenerateDoubleTriggerFlag(df20, "trg_cross_ele24tau30_hps__eleEsScaleDown", "p4_1__eleEsScaleDown", "p4_2__eleEsScaleDown", "TrigObj_filterBits", "TrigObj_id", "TrigObj_pt", "TrigObj_eta", "TrigObj_phi", "HLT_Ele24_eta2p1_WPTight_Gsf_LooseChargedIsoPFTauHPS30_eta2p1_CrossL1", 25, 32, 2.5, 2.1, 11, 15, 1, -1, 0.4);
    auto df22 = trigger::GenerateDoubleTriggerFlag(df21, "trg_cross_ele24tau30__eleEsScaleDown", "p4_1__eleEsScaleDown", "p4_2__eleEsScaleDown", "TrigObj_filterBits", "TrigObj_id", "TrigObj_pt", "TrigObj_eta", "TrigObj_phi", "HLT_Ele24_eta2p1_WPTight_Gsf_LooseChargedIsoPFTau30_eta2p1_CrossL1", 25, 32, 2.5, 2.1, 11, 15, 1, 4, 0.4);
    auto df23 = trigger::GenerateDoubleTriggerFlag(df22, "trg_cross_ele24tau30_hps__tauEs3prong0pizeroUp", "p4_1", "p4_2__tauEs3prong0pizeroUp", "TrigObj_filterBits", "TrigObj_id", "TrigObj_pt", "TrigObj_eta", "TrigObj_phi", "HLT_Ele24_eta2p1_WPTight_Gsf_LooseChargedIsoPFTauHPS30_eta2p1_CrossL1", 25, 32, 2.5, 2.1, 11, 15, 1, -1, 0.4);
    auto df24 = trigger::GenerateDoubleTriggerFlag(df23, "trg_cross_ele24tau30__tauEs3prong0pizeroUp", "p4_1", "p4_2__tauEs3prong0pizeroUp", "TrigObj_filterBits", "TrigObj_id", "TrigObj_pt", "TrigObj_eta", "TrigObj_phi", "HLT_Ele24_eta2p1_WPTight_Gsf_LooseChargedIsoPFTau30_eta2p1_CrossL1", 25, 32, 2.5, 2.1, 11, 15, 1, 4, 0.4);
    auto df25 = trigger::GenerateDoubleTriggerFlag(df24, "trg_cross_ele24tau30_hps__eleEsScaleUp", "p4_1__eleEsScaleUp", "p4_2__eleEsScaleUp", "TrigObj_filterBits", "TrigObj_id", "TrigObj_pt", "TrigObj_eta", "TrigObj_phi", "HLT_Ele24_eta2p1_WPTight_Gsf_LooseChargedIsoPFTauHPS30_eta2p1_CrossL1", 25, 32, 2.5, 2.1, 11, 15, 1, -1, 0.4);
    auto df26 = trigger::GenerateDoubleTriggerFlag(df25, "trg_cross_ele24tau30__eleEsScaleUp", "p4_1__eleEsScaleUp", "p4_2__eleEsScaleUp", "TrigObj_filterBits", "TrigObj_id", "TrigObj_pt", "TrigObj_eta", "TrigObj_phi", "HLT_Ele24_eta2p1_WPTight_Gsf_LooseChargedIsoPFTau30_eta2p1_CrossL1", 25, 32, 2.5, 2.1, 11, 15, 1, 4, 0.4);
    return df26;

}
