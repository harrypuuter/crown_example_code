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
ROOT::RDF::RNode TauEmbeddingElectronIsoSF_2_MC_ee (ROOT::RDF::RNode df0, OnnxSessionManager &onnxSessionManager, CorrectionManager &correctionManager) {

        auto df1 = scalefactor::embedding::electron_sf(df0, correctionManager, "pt_2", "eta_2", "iso_wgt_ele_2", "data/embedding/electron_2018UL.json.gz", "mc", "Iso_pt_eta_bins");
    auto df2 = scalefactor::embedding::electron_sf(df1, correctionManager, "pt_2__eleEsResoDown", "eta_2__eleEsResoDown", "iso_wgt_ele_2__eleEsResoDown", "data/embedding/electron_2018UL.json.gz", "mc", "Iso_pt_eta_bins");
    auto df3 = scalefactor::embedding::electron_sf(df2, correctionManager, "pt_2__eleEsScaleUp", "eta_2__eleEsScaleUp", "iso_wgt_ele_2__eleEsScaleUp", "data/embedding/electron_2018UL.json.gz", "mc", "Iso_pt_eta_bins");
    auto df4 = scalefactor::embedding::electron_sf(df3, correctionManager, "pt_2__eleEsResoUp", "eta_2__eleEsResoUp", "iso_wgt_ele_2__eleEsResoUp", "data/embedding/electron_2018UL.json.gz", "mc", "Iso_pt_eta_bins");
    auto df5 = scalefactor::embedding::electron_sf(df4, correctionManager, "pt_2__eleEsScaleDown", "eta_2__eleEsScaleDown", "iso_wgt_ele_2__eleEsScaleDown", "data/embedding/electron_2018UL.json.gz", "mc", "Iso_pt_eta_bins");
    return df5;

}
