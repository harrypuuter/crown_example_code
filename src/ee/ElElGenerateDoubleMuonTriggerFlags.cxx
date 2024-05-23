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
ROOT::RDF::RNode ElElGenerateDoubleMuonTriggerFlags_ee (ROOT::RDF::RNode df0, OnnxSessionManager &onnxSessionManager, CorrectionManager &correctionManager) {

        auto df1 = trigger::GenerateDoubleTriggerFlag(df0, "trg_double_ele24", "p4_1", "p4_2", "TrigObj_filterBits", "TrigObj_id", "TrigObj_pt", "TrigObj_eta", "TrigObj_phi", "HLT_DoubleEle24_eta2p1_WPTight_Gsf", 24, 24, 2.1, 2.1, 11, 11, 4, 4, 0.4);
    auto df2 = trigger::GenerateDoubleTriggerFlag(df1, "trg_double_ele24__eleEsResoDown", "p4_1__eleEsResoDown", "p4_2__eleEsResoDown", "TrigObj_filterBits", "TrigObj_id", "TrigObj_pt", "TrigObj_eta", "TrigObj_phi", "HLT_DoubleEle24_eta2p1_WPTight_Gsf", 24, 24, 2.1, 2.1, 11, 11, 4, 4, 0.4);
    auto df3 = trigger::GenerateDoubleTriggerFlag(df2, "trg_double_ele24__eleEsScaleUp", "p4_1__eleEsScaleUp", "p4_2__eleEsScaleUp", "TrigObj_filterBits", "TrigObj_id", "TrigObj_pt", "TrigObj_eta", "TrigObj_phi", "HLT_DoubleEle24_eta2p1_WPTight_Gsf", 24, 24, 2.1, 2.1, 11, 11, 4, 4, 0.4);
    auto df4 = trigger::GenerateDoubleTriggerFlag(df3, "trg_double_ele24__eleEsResoUp", "p4_1__eleEsResoUp", "p4_2__eleEsResoUp", "TrigObj_filterBits", "TrigObj_id", "TrigObj_pt", "TrigObj_eta", "TrigObj_phi", "HLT_DoubleEle24_eta2p1_WPTight_Gsf", 24, 24, 2.1, 2.1, 11, 11, 4, 4, 0.4);
    auto df5 = trigger::GenerateDoubleTriggerFlag(df4, "trg_double_ele24__eleEsScaleDown", "p4_1__eleEsScaleDown", "p4_2__eleEsScaleDown", "TrigObj_filterBits", "TrigObj_id", "TrigObj_pt", "TrigObj_eta", "TrigObj_phi", "HLT_DoubleEle24_eta2p1_WPTight_Gsf", 24, 24, 2.1, 2.1, 11, 11, 4, 4, 0.4);
    return df5;

}
