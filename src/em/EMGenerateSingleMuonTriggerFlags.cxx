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
ROOT::RDF::RNode EMGenerateSingleMuonTriggerFlags_em (ROOT::RDF::RNode df0, OnnxSessionManager &onnxSessionManager, CorrectionManager &correctionManager) {

        auto df1 = trigger::GenerateSingleTriggerFlag(df0, "trg_single_mu24", "p4_2", "TrigObj_filterBits", "TrigObj_id", "TrigObj_pt", "TrigObj_eta", "TrigObj_phi", "HLT_IsoMu24", 25, 2.5, 13, 3, 0.4 );
    auto df2 = trigger::GenerateSingleTriggerFlag(df1, "trg_single_mu27", "p4_2", "TrigObj_filterBits", "TrigObj_id", "TrigObj_pt", "TrigObj_eta", "TrigObj_phi", "HLT_IsoMu27", 28, 2.5, 13, 3, 0.4 );
    auto df3 = trigger::GenerateSingleTriggerFlag(df2, "trg_single_mu24__eleEsResoDown", "p4_2__eleEsResoDown", "TrigObj_filterBits", "TrigObj_id", "TrigObj_pt", "TrigObj_eta", "TrigObj_phi", "HLT_IsoMu24", 25, 2.5, 13, 3, 0.4 );
    auto df4 = trigger::GenerateSingleTriggerFlag(df3, "trg_single_mu27__eleEsResoDown", "p4_2__eleEsResoDown", "TrigObj_filterBits", "TrigObj_id", "TrigObj_pt", "TrigObj_eta", "TrigObj_phi", "HLT_IsoMu27", 28, 2.5, 13, 3, 0.4 );
    auto df5 = trigger::GenerateSingleTriggerFlag(df4, "trg_single_mu24__eleEsScaleUp", "p4_2__eleEsScaleUp", "TrigObj_filterBits", "TrigObj_id", "TrigObj_pt", "TrigObj_eta", "TrigObj_phi", "HLT_IsoMu24", 25, 2.5, 13, 3, 0.4 );
    auto df6 = trigger::GenerateSingleTriggerFlag(df5, "trg_single_mu27__eleEsScaleUp", "p4_2__eleEsScaleUp", "TrigObj_filterBits", "TrigObj_id", "TrigObj_pt", "TrigObj_eta", "TrigObj_phi", "HLT_IsoMu27", 28, 2.5, 13, 3, 0.4 );
    auto df7 = trigger::GenerateSingleTriggerFlag(df6, "trg_single_mu24__eleEsResoUp", "p4_2__eleEsResoUp", "TrigObj_filterBits", "TrigObj_id", "TrigObj_pt", "TrigObj_eta", "TrigObj_phi", "HLT_IsoMu24", 25, 2.5, 13, 3, 0.4 );
    auto df8 = trigger::GenerateSingleTriggerFlag(df7, "trg_single_mu27__eleEsResoUp", "p4_2__eleEsResoUp", "TrigObj_filterBits", "TrigObj_id", "TrigObj_pt", "TrigObj_eta", "TrigObj_phi", "HLT_IsoMu27", 28, 2.5, 13, 3, 0.4 );
    auto df9 = trigger::GenerateSingleTriggerFlag(df8, "trg_single_mu24__eleEsScaleDown", "p4_2__eleEsScaleDown", "TrigObj_filterBits", "TrigObj_id", "TrigObj_pt", "TrigObj_eta", "TrigObj_phi", "HLT_IsoMu24", 25, 2.5, 13, 3, 0.4 );
    auto df10 = trigger::GenerateSingleTriggerFlag(df9, "trg_single_mu27__eleEsScaleDown", "p4_2__eleEsScaleDown", "TrigObj_filterBits", "TrigObj_id", "TrigObj_pt", "TrigObj_eta", "TrigObj_phi", "HLT_IsoMu27", 28, 2.5, 13, 3, 0.4 );
    return df10;

}
