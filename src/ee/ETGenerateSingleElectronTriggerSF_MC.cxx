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
ROOT::RDF::RNode ETGenerateSingleElectronTriggerSF_MC_ee (ROOT::RDF::RNode df0, OnnxSessionManager &onnxSessionManager, CorrectionManager &correctionManager) {

        auto df1 = scalefactor::embedding::electron_sf(df0, correctionManager, "pt_1", "eta_1", "trg_wgt_single_ele32", "data/embedding/electron_2018UL.json.gz", "mc", "Trg32_Iso_pt_eta_bins" , 1.0);
    auto df2 = scalefactor::embedding::electron_sf(df1, correctionManager, "pt_1", "eta_1", "trg_wgt_single_ele35", "data/embedding/electron_2018UL.json.gz", "mc", "Trg35_Iso_pt_eta_bins" , 1.0);
    auto df3 = scalefactor::embedding::electron_sf(df2, correctionManager, "pt_1", "eta_1", "trg_wgt_single_ele32orele35", "data/embedding/electron_2018UL.json.gz", "mc", "Trg32_or_Trg35_Iso_pt_eta_bins" , 1.0);
    auto df4 = scalefactor::embedding::electron_sf(df3, correctionManager, "pt_1", "eta_1", "trg_wgt_single_ele27orele32orele35", "data/embedding/electron_2018UL.json.gz", "mc", "Trg_Iso_pt_eta_bins" , 1.0);
    auto df5 = scalefactor::embedding::electron_sf(df4, correctionManager, "pt_1__eleEsResoDown", "eta_1__eleEsResoDown", "trg_wgt_single_ele32__eleEsResoDown", "data/embedding/electron_2018UL.json.gz", "mc", "Trg32_Iso_pt_eta_bins" , 1.0);
    auto df6 = scalefactor::embedding::electron_sf(df5, correctionManager, "pt_1__eleEsResoDown", "eta_1__eleEsResoDown", "trg_wgt_single_ele35__eleEsResoDown", "data/embedding/electron_2018UL.json.gz", "mc", "Trg35_Iso_pt_eta_bins" , 1.0);
    auto df7 = scalefactor::embedding::electron_sf(df6, correctionManager, "pt_1__eleEsResoDown", "eta_1__eleEsResoDown", "trg_wgt_single_ele32orele35__eleEsResoDown", "data/embedding/electron_2018UL.json.gz", "mc", "Trg32_or_Trg35_Iso_pt_eta_bins" , 1.0);
    auto df8 = scalefactor::embedding::electron_sf(df7, correctionManager, "pt_1__eleEsResoDown", "eta_1__eleEsResoDown", "trg_wgt_single_ele27orele32orele35__eleEsResoDown", "data/embedding/electron_2018UL.json.gz", "mc", "Trg_Iso_pt_eta_bins" , 1.0);
    auto df9 = scalefactor::embedding::electron_sf(df8, correctionManager, "pt_1__eleEsScaleUp", "eta_1__eleEsScaleUp", "trg_wgt_single_ele32__eleEsScaleUp", "data/embedding/electron_2018UL.json.gz", "mc", "Trg32_Iso_pt_eta_bins" , 1.0);
    auto df10 = scalefactor::embedding::electron_sf(df9, correctionManager, "pt_1__eleEsScaleUp", "eta_1__eleEsScaleUp", "trg_wgt_single_ele35__eleEsScaleUp", "data/embedding/electron_2018UL.json.gz", "mc", "Trg35_Iso_pt_eta_bins" , 1.0);
    auto df11 = scalefactor::embedding::electron_sf(df10, correctionManager, "pt_1__eleEsScaleUp", "eta_1__eleEsScaleUp", "trg_wgt_single_ele32orele35__eleEsScaleUp", "data/embedding/electron_2018UL.json.gz", "mc", "Trg32_or_Trg35_Iso_pt_eta_bins" , 1.0);
    auto df12 = scalefactor::embedding::electron_sf(df11, correctionManager, "pt_1__eleEsScaleUp", "eta_1__eleEsScaleUp", "trg_wgt_single_ele27orele32orele35__eleEsScaleUp", "data/embedding/electron_2018UL.json.gz", "mc", "Trg_Iso_pt_eta_bins" , 1.0);
    auto df13 = scalefactor::embedding::electron_sf(df12, correctionManager, "pt_1__eleEsResoUp", "eta_1__eleEsResoUp", "trg_wgt_single_ele32__eleEsResoUp", "data/embedding/electron_2018UL.json.gz", "mc", "Trg32_Iso_pt_eta_bins" , 1.0);
    auto df14 = scalefactor::embedding::electron_sf(df13, correctionManager, "pt_1__eleEsResoUp", "eta_1__eleEsResoUp", "trg_wgt_single_ele35__eleEsResoUp", "data/embedding/electron_2018UL.json.gz", "mc", "Trg35_Iso_pt_eta_bins" , 1.0);
    auto df15 = scalefactor::embedding::electron_sf(df14, correctionManager, "pt_1__eleEsResoUp", "eta_1__eleEsResoUp", "trg_wgt_single_ele32orele35__eleEsResoUp", "data/embedding/electron_2018UL.json.gz", "mc", "Trg32_or_Trg35_Iso_pt_eta_bins" , 1.0);
    auto df16 = scalefactor::embedding::electron_sf(df15, correctionManager, "pt_1__eleEsResoUp", "eta_1__eleEsResoUp", "trg_wgt_single_ele27orele32orele35__eleEsResoUp", "data/embedding/electron_2018UL.json.gz", "mc", "Trg_Iso_pt_eta_bins" , 1.0);
    auto df17 = scalefactor::embedding::electron_sf(df16, correctionManager, "pt_1__eleEsScaleDown", "eta_1__eleEsScaleDown", "trg_wgt_single_ele32__eleEsScaleDown", "data/embedding/electron_2018UL.json.gz", "mc", "Trg32_Iso_pt_eta_bins" , 1.0);
    auto df18 = scalefactor::embedding::electron_sf(df17, correctionManager, "pt_1__eleEsScaleDown", "eta_1__eleEsScaleDown", "trg_wgt_single_ele35__eleEsScaleDown", "data/embedding/electron_2018UL.json.gz", "mc", "Trg35_Iso_pt_eta_bins" , 1.0);
    auto df19 = scalefactor::embedding::electron_sf(df18, correctionManager, "pt_1__eleEsScaleDown", "eta_1__eleEsScaleDown", "trg_wgt_single_ele32orele35__eleEsScaleDown", "data/embedding/electron_2018UL.json.gz", "mc", "Trg32_or_Trg35_Iso_pt_eta_bins" , 1.0);
    auto df20 = scalefactor::embedding::electron_sf(df19, correctionManager, "pt_1__eleEsScaleDown", "eta_1__eleEsScaleDown", "trg_wgt_single_ele27orele32orele35__eleEsScaleDown", "data/embedding/electron_2018UL.json.gz", "mc", "Trg_Iso_pt_eta_bins" , 1.0);
    return df20;

}
