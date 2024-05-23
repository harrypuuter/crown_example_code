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
ROOT::RDF::RNode ElElGenerateSingleElectronTriggerFlags_ee (ROOT::RDF::RNode df0, OnnxSessionManager &onnxSessionManager, CorrectionManager &correctionManager) {

        auto df1 = trigger::GenerateSingleTriggerFlag(df0, "trg_single_ele27", "p4_1", "TrigObj_filterBits", "TrigObj_id", "TrigObj_pt", "TrigObj_eta", "TrigObj_phi", "HLT_Ele27_WPTight_Gsf", 28, 2.1, 11, 1, 0.4 );
    auto df2 = trigger::GenerateSingleTriggerFlag(df1, "trg_single_ele32", "p4_1", "TrigObj_filterBits", "TrigObj_id", "TrigObj_pt", "TrigObj_eta", "TrigObj_phi", "HLT_Ele32_WPTight_Gsf", 33, 2.1, 11, 1, 0.4 );
    auto df3 = trigger::GenerateSingleTriggerFlag(df2, "trg_single_ele35", "p4_1", "TrigObj_filterBits", "TrigObj_id", "TrigObj_pt", "TrigObj_eta", "TrigObj_phi", "HLT_Ele35_WPTight_Gsf", 36, 2.1, 11, 1, 0.4 );
    auto df4 = trigger::GenerateSingleTriggerFlag(df3, "trg_single_ele27__eleEsResoDown", "p4_1__eleEsResoDown", "TrigObj_filterBits", "TrigObj_id", "TrigObj_pt", "TrigObj_eta", "TrigObj_phi", "HLT_Ele27_WPTight_Gsf", 28, 2.1, 11, 1, 0.4 );
    auto df5 = trigger::GenerateSingleTriggerFlag(df4, "trg_single_ele32__eleEsResoDown", "p4_1__eleEsResoDown", "TrigObj_filterBits", "TrigObj_id", "TrigObj_pt", "TrigObj_eta", "TrigObj_phi", "HLT_Ele32_WPTight_Gsf", 33, 2.1, 11, 1, 0.4 );
    auto df6 = trigger::GenerateSingleTriggerFlag(df5, "trg_single_ele35__eleEsResoDown", "p4_1__eleEsResoDown", "TrigObj_filterBits", "TrigObj_id", "TrigObj_pt", "TrigObj_eta", "TrigObj_phi", "HLT_Ele35_WPTight_Gsf", 36, 2.1, 11, 1, 0.4 );
    auto df7 = trigger::GenerateSingleTriggerFlag(df6, "trg_single_ele27__eleEsScaleUp", "p4_1__eleEsScaleUp", "TrigObj_filterBits", "TrigObj_id", "TrigObj_pt", "TrigObj_eta", "TrigObj_phi", "HLT_Ele27_WPTight_Gsf", 28, 2.1, 11, 1, 0.4 );
    auto df8 = trigger::GenerateSingleTriggerFlag(df7, "trg_single_ele32__eleEsScaleUp", "p4_1__eleEsScaleUp", "TrigObj_filterBits", "TrigObj_id", "TrigObj_pt", "TrigObj_eta", "TrigObj_phi", "HLT_Ele32_WPTight_Gsf", 33, 2.1, 11, 1, 0.4 );
    auto df9 = trigger::GenerateSingleTriggerFlag(df8, "trg_single_ele35__eleEsScaleUp", "p4_1__eleEsScaleUp", "TrigObj_filterBits", "TrigObj_id", "TrigObj_pt", "TrigObj_eta", "TrigObj_phi", "HLT_Ele35_WPTight_Gsf", 36, 2.1, 11, 1, 0.4 );
    auto df10 = trigger::GenerateSingleTriggerFlag(df9, "trg_single_ele27__eleEsResoUp", "p4_1__eleEsResoUp", "TrigObj_filterBits", "TrigObj_id", "TrigObj_pt", "TrigObj_eta", "TrigObj_phi", "HLT_Ele27_WPTight_Gsf", 28, 2.1, 11, 1, 0.4 );
    auto df11 = trigger::GenerateSingleTriggerFlag(df10, "trg_single_ele32__eleEsResoUp", "p4_1__eleEsResoUp", "TrigObj_filterBits", "TrigObj_id", "TrigObj_pt", "TrigObj_eta", "TrigObj_phi", "HLT_Ele32_WPTight_Gsf", 33, 2.1, 11, 1, 0.4 );
    auto df12 = trigger::GenerateSingleTriggerFlag(df11, "trg_single_ele35__eleEsResoUp", "p4_1__eleEsResoUp", "TrigObj_filterBits", "TrigObj_id", "TrigObj_pt", "TrigObj_eta", "TrigObj_phi", "HLT_Ele35_WPTight_Gsf", 36, 2.1, 11, 1, 0.4 );
    auto df13 = trigger::GenerateSingleTriggerFlag(df12, "trg_single_ele27__eleEsScaleDown", "p4_1__eleEsScaleDown", "TrigObj_filterBits", "TrigObj_id", "TrigObj_pt", "TrigObj_eta", "TrigObj_phi", "HLT_Ele27_WPTight_Gsf", 28, 2.1, 11, 1, 0.4 );
    auto df14 = trigger::GenerateSingleTriggerFlag(df13, "trg_single_ele32__eleEsScaleDown", "p4_1__eleEsScaleDown", "TrigObj_filterBits", "TrigObj_id", "TrigObj_pt", "TrigObj_eta", "TrigObj_phi", "HLT_Ele32_WPTight_Gsf", 33, 2.1, 11, 1, 0.4 );
    auto df15 = trigger::GenerateSingleTriggerFlag(df14, "trg_single_ele35__eleEsScaleDown", "p4_1__eleEsScaleDown", "TrigObj_filterBits", "TrigObj_id", "TrigObj_pt", "TrigObj_eta", "TrigObj_phi", "HLT_Ele35_WPTight_Gsf", 36, 2.1, 11, 1, 0.4 );
    return df15;

}
