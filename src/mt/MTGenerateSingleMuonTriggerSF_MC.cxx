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
ROOT::RDF::RNode MTGenerateSingleMuonTriggerSF_MC_mt (ROOT::RDF::RNode df0, OnnxSessionManager &onnxSessionManager, CorrectionManager &correctionManager) {

        auto df1 = scalefactor::embedding::muon_sf(df0, correctionManager, "pt_1", "eta_1", "trg_wgt_single_mu24", "data/embedding/muon_2018UL.json.gz", "mc", "Trg_IsoMu24_pt_eta_bins", 1.0);
    auto df2 = scalefactor::embedding::muon_sf(df1, correctionManager, "pt_1", "eta_1", "trg_wgt_single_mu27", "data/embedding/muon_2018UL.json.gz", "mc", "Trg_IsoMu27_pt_eta_bins", 1.0);
    auto df3 = scalefactor::embedding::muon_sf(df2, correctionManager, "pt_1", "eta_1", "trg_wgt_single_mu24ormu27", "data/embedding/muon_2018UL.json.gz", "mc", "Trg_IsoMu27_or_IsoMu24_pt_eta_bins", 1.0);
    auto df4 = scalefactor::embedding::muon_sf(df3, correctionManager, "pt_1", "eta_1", "trg_wgt_single_mu24__singleMuonTriggerSFDown", "data/embedding/muon_2018UL.json.gz", "mc", "Trg_IsoMu24_pt_eta_bins", 0.98);
    auto df5 = scalefactor::embedding::muon_sf(df4, correctionManager, "pt_1", "eta_1", "trg_wgt_single_mu27__singleMuonTriggerSFDown", "data/embedding/muon_2018UL.json.gz", "mc", "Trg_IsoMu27_pt_eta_bins", 0.98);
    auto df6 = scalefactor::embedding::muon_sf(df5, correctionManager, "pt_1", "eta_1", "trg_wgt_single_mu24ormu27__singleMuonTriggerSFDown", "data/embedding/muon_2018UL.json.gz", "mc", "Trg_IsoMu27_or_IsoMu24_pt_eta_bins", 0.98);
    auto df7 = scalefactor::embedding::muon_sf(df6, correctionManager, "pt_1", "eta_1", "trg_wgt_single_mu24__singleMuonTriggerSFUp", "data/embedding/muon_2018UL.json.gz", "mc", "Trg_IsoMu24_pt_eta_bins", 1.02);
    auto df8 = scalefactor::embedding::muon_sf(df7, correctionManager, "pt_1", "eta_1", "trg_wgt_single_mu27__singleMuonTriggerSFUp", "data/embedding/muon_2018UL.json.gz", "mc", "Trg_IsoMu27_pt_eta_bins", 1.02);
    auto df9 = scalefactor::embedding::muon_sf(df8, correctionManager, "pt_1", "eta_1", "trg_wgt_single_mu24ormu27__singleMuonTriggerSFUp", "data/embedding/muon_2018UL.json.gz", "mc", "Trg_IsoMu27_or_IsoMu24_pt_eta_bins", 1.02);
    return df9;

}
