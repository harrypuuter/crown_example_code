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
ROOT::RDF::RNode DiLeptonVeto_global (ROOT::RDF::RNode df0, OnnxSessionManager &onnxSessionManager, CorrectionManager &correctionManager) {

        auto df1 = physicsobject::CutPt(df0, "Electron_pt_corrected", "PG_internal_quantity_10", 15.0);
    auto df2 = physicsobject::CutPt(df1, "Electron_pt_corrected__eleEsResoDown", "PG_internal_quantity_10__eleEsResoDown", 15.0);
    auto df3 = physicsobject::CutPt(df2, "Electron_pt_corrected__eleEsScaleUp", "PG_internal_quantity_10__eleEsScaleUp", 15.0);
    auto df4 = physicsobject::CutPt(df3, "Electron_pt_corrected__eleEsResoUp", "PG_internal_quantity_10__eleEsResoUp", 15.0);
    auto df5 = physicsobject::CutPt(df4, "Electron_pt_corrected__eleEsScaleDown", "PG_internal_quantity_10__eleEsScaleDown", 15.0);
    auto df6 = physicsobject::electron::CutCBID(df5, "PG_internal_quantity_11", "Electron_cutBased", 1);
    auto df7 = physicsobject::CombineMasks(df6, "PG_internal_quantity_12", "PG_internal_quantity_2", "PG_internal_quantity_3", "PG_internal_quantity_4", "PG_internal_quantity_6", "PG_internal_quantity_10", "PG_internal_quantity_11");
    auto df8 = physicsobject::CombineMasks(df7, "PG_internal_quantity_12__eleEsResoDown", "PG_internal_quantity_2", "PG_internal_quantity_3", "PG_internal_quantity_4", "PG_internal_quantity_6", "PG_internal_quantity_10__eleEsResoDown", "PG_internal_quantity_11");
    auto df9 = physicsobject::CombineMasks(df8, "PG_internal_quantity_12__eleEsScaleUp", "PG_internal_quantity_2", "PG_internal_quantity_3", "PG_internal_quantity_4", "PG_internal_quantity_6", "PG_internal_quantity_10__eleEsScaleUp", "PG_internal_quantity_11");
    auto df10 = physicsobject::CombineMasks(df9, "PG_internal_quantity_12__eleEsResoUp", "PG_internal_quantity_2", "PG_internal_quantity_3", "PG_internal_quantity_4", "PG_internal_quantity_6", "PG_internal_quantity_10__eleEsResoUp", "PG_internal_quantity_11");
    auto df11 = physicsobject::CombineMasks(df10, "PG_internal_quantity_12__eleEsScaleDown", "PG_internal_quantity_2", "PG_internal_quantity_3", "PG_internal_quantity_4", "PG_internal_quantity_6", "PG_internal_quantity_10__eleEsScaleDown", "PG_internal_quantity_11");
    auto df12 = physicsobject::CheckForDiLeptonPairs(df11, "dielectron_veto", "Electron_pt_corrected", "Electron_eta", "Electron_phi", "Electron_mass", "Electron_charge", "PG_internal_quantity_12", 0.15);
    auto df13 = physicsobject::CheckForDiLeptonPairs(df12, "dielectron_veto__eleEsResoDown", "Electron_pt_corrected__eleEsResoDown", "Electron_eta", "Electron_phi", "Electron_mass", "Electron_charge", "PG_internal_quantity_12__eleEsResoDown", 0.15);
    auto df14 = physicsobject::CheckForDiLeptonPairs(df13, "dielectron_veto__eleEsScaleUp", "Electron_pt_corrected__eleEsScaleUp", "Electron_eta", "Electron_phi", "Electron_mass", "Electron_charge", "PG_internal_quantity_12__eleEsScaleUp", 0.15);
    auto df15 = physicsobject::CheckForDiLeptonPairs(df14, "dielectron_veto__eleEsResoUp", "Electron_pt_corrected__eleEsResoUp", "Electron_eta", "Electron_phi", "Electron_mass", "Electron_charge", "PG_internal_quantity_12__eleEsResoUp", 0.15);
    auto df16 = physicsobject::CheckForDiLeptonPairs(df15, "dielectron_veto__eleEsScaleDown", "Electron_pt_corrected__eleEsScaleDown", "Electron_eta", "Electron_phi", "Electron_mass", "Electron_charge", "PG_internal_quantity_12__eleEsScaleDown", 0.15);
    auto df17 = physicsobject::CutPt(df16, "Muon_pt", "PG_internal_quantity_22", 15.0);
    auto df18 = physicsobject::muon::CutID(df17, "PG_internal_quantity_23", "Muon_looseId");
    auto df19 = physicsobject::CombineMasks(df18, "PG_internal_quantity_24", "PG_internal_quantity_14", "PG_internal_quantity_15", "PG_internal_quantity_16", "PG_internal_quantity_18", "PG_internal_quantity_22", "PG_internal_quantity_23");
    auto df20 = physicsobject::CheckForDiLeptonPairs(df19, "dimuon_veto", "Muon_pt", "Muon_eta", "Muon_phi", "Muon_mass", "Muon_charge", "PG_internal_quantity_24", 0.15);
    auto df21 = basefunctions::CombineFlagsAny(df20, "dilepton_veto", "dielectron_veto", "dimuon_veto");
    auto df22 = basefunctions::CombineFlagsAny(df21, "dilepton_veto__eleEsResoDown", "dielectron_veto__eleEsResoDown", "dimuon_veto");
    auto df23 = basefunctions::CombineFlagsAny(df22, "dilepton_veto__eleEsScaleUp", "dielectron_veto__eleEsScaleUp", "dimuon_veto");
    auto df24 = basefunctions::CombineFlagsAny(df23, "dilepton_veto__eleEsResoUp", "dielectron_veto__eleEsResoUp", "dimuon_veto");
    auto df25 = basefunctions::CombineFlagsAny(df24, "dilepton_veto__eleEsScaleDown", "dielectron_veto__eleEsScaleDown", "dimuon_veto");
    return df25;

}
