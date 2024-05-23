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
ROOT::RDF::RNode TauEmbeddingMuonIsoSF_1_MC_mt (ROOT::RDF::RNode df0, OnnxSessionManager &onnxSessionManager, CorrectionManager &correctionManager) {

        auto df1 = scalefactor::embedding::muon_sf(df0, correctionManager, "pt_1", "eta_1", "iso_wgt_mu_1", "data/embedding/muon_2018UL.json.gz", "mc", "Iso_pt_eta_bins");
    auto df2 = scalefactor::embedding::muon_sf(df1, correctionManager, "pt_1", "eta_1", "iso_wgt_mu_1__tauEs3prong1pizeroDown", "data/embedding/muon_2018UL.json.gz", "mc", "Iso_pt_eta_bins");
    auto df3 = scalefactor::embedding::muon_sf(df2, correctionManager, "pt_1", "eta_1", "iso_wgt_mu_1__tauEs1prong0pizeroDown", "data/embedding/muon_2018UL.json.gz", "mc", "Iso_pt_eta_bins");
    auto df4 = scalefactor::embedding::muon_sf(df3, correctionManager, "pt_1", "eta_1", "iso_wgt_mu_1__tauEs3prong1pizeroUp", "data/embedding/muon_2018UL.json.gz", "mc", "Iso_pt_eta_bins");
    auto df5 = scalefactor::embedding::muon_sf(df4, correctionManager, "pt_1", "eta_1", "iso_wgt_mu_1__tauEs1prong1pizeroDown", "data/embedding/muon_2018UL.json.gz", "mc", "Iso_pt_eta_bins");
    auto df6 = scalefactor::embedding::muon_sf(df5, correctionManager, "pt_1", "eta_1", "iso_wgt_mu_1__tauEs1prong1pizeroUp", "data/embedding/muon_2018UL.json.gz", "mc", "Iso_pt_eta_bins");
    auto df7 = scalefactor::embedding::muon_sf(df6, correctionManager, "pt_1", "eta_1", "iso_wgt_mu_1__tauEs1prong0pizeroUp", "data/embedding/muon_2018UL.json.gz", "mc", "Iso_pt_eta_bins");
    auto df8 = scalefactor::embedding::muon_sf(df7, correctionManager, "pt_1", "eta_1", "iso_wgt_mu_1__tauEs3prong0pizeroDown", "data/embedding/muon_2018UL.json.gz", "mc", "Iso_pt_eta_bins");
    auto df9 = scalefactor::embedding::muon_sf(df8, correctionManager, "pt_1", "eta_1", "iso_wgt_mu_1__tauEs3prong0pizeroUp", "data/embedding/muon_2018UL.json.gz", "mc", "Iso_pt_eta_bins");
    return df9;

}
