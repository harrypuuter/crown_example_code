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
ROOT::RDF::RNode GoodBJets_global (ROOT::RDF::RNode df0, OnnxSessionManager &onnxSessionManager, CorrectionManager &correctionManager) {

        auto df1 = physicsobject::CutPt(df0, "Jet_pt_corrected", "PG_internal_quantity_27", 20);
    auto df2 = physicsobject::CutPt(df1, "Jet_pt_corrected__jesUncFlavorQCDUp", "PG_internal_quantity_27__jesUncFlavorQCDUp", 20);
    auto df3 = physicsobject::CutPt(df2, "Jet_pt_corrected__jesUncHFDown", "PG_internal_quantity_27__jesUncHFDown", 20);
    auto df4 = physicsobject::CutPt(df3, "Jet_pt_corrected__jesUncRelativeBalUp", "PG_internal_quantity_27__jesUncRelativeBalUp", 20);
    auto df5 = physicsobject::CutPt(df4, "Jet_pt_corrected__jesUncTotalDown", "PG_internal_quantity_27__jesUncTotalDown", 20);
    auto df6 = physicsobject::CutPt(df5, "Jet_pt_corrected__jesUncRelativeSampleYearUp", "PG_internal_quantity_27__jesUncRelativeSampleYearUp", 20);
    auto df7 = physicsobject::CutPt(df6, "Jet_pt_corrected__jesUncAbsoluteDown", "PG_internal_quantity_27__jesUncAbsoluteDown", 20);
    auto df8 = physicsobject::CutPt(df7, "Jet_pt_corrected__jerUncDown", "PG_internal_quantity_27__jerUncDown", 20);
    auto df9 = physicsobject::CutPt(df8, "Jet_pt_corrected__jerUncUp", "PG_internal_quantity_27__jerUncUp", 20);
    auto df10 = physicsobject::CutPt(df9, "Jet_pt_corrected__jesUncEC2YearDown", "PG_internal_quantity_27__jesUncEC2YearDown", 20);
    auto df11 = physicsobject::CutPt(df10, "Jet_pt_corrected__jesUncBBEC1Down", "PG_internal_quantity_27__jesUncBBEC1Down", 20);
    auto df12 = physicsobject::CutPt(df11, "Jet_pt_corrected__jesUncEC2Down", "PG_internal_quantity_27__jesUncEC2Down", 20);
    auto df13 = physicsobject::CutPt(df12, "Jet_pt_corrected__jesUncAbsoluteYearDown", "PG_internal_quantity_27__jesUncAbsoluteYearDown", 20);
    auto df14 = physicsobject::CutPt(df13, "Jet_pt_corrected__jesUncRelativeBalDown", "PG_internal_quantity_27__jesUncRelativeBalDown", 20);
    auto df15 = physicsobject::CutPt(df14, "Jet_pt_corrected__jesUncTotalUp", "PG_internal_quantity_27__jesUncTotalUp", 20);
    auto df16 = physicsobject::CutPt(df15, "Jet_pt_corrected__jesUncBBEC1YearUp", "PG_internal_quantity_27__jesUncBBEC1YearUp", 20);
    auto df17 = physicsobject::CutPt(df16, "Jet_pt_corrected__jesUncHEMIssueUp", "PG_internal_quantity_27__jesUncHEMIssueUp", 20);
    auto df18 = physicsobject::CutPt(df17, "Jet_pt_corrected__jesUncRelativeSampleYearDown", "PG_internal_quantity_27__jesUncRelativeSampleYearDown", 20);
    auto df19 = physicsobject::CutPt(df18, "Jet_pt_corrected__jesUncHFUp", "PG_internal_quantity_27__jesUncHFUp", 20);
    auto df20 = physicsobject::CutPt(df19, "Jet_pt_corrected__jesUncFlavorQCDDown", "PG_internal_quantity_27__jesUncFlavorQCDDown", 20);
    auto df21 = physicsobject::CutPt(df20, "Jet_pt_corrected__jesUncHEMIssueDown", "PG_internal_quantity_27__jesUncHEMIssueDown", 20);
    auto df22 = physicsobject::CutPt(df21, "Jet_pt_corrected__jesUncAbsoluteUp", "PG_internal_quantity_27__jesUncAbsoluteUp", 20);
    auto df23 = physicsobject::CutPt(df22, "Jet_pt_corrected__jesUncEC2YearUp", "PG_internal_quantity_27__jesUncEC2YearUp", 20);
    auto df24 = physicsobject::CutPt(df23, "Jet_pt_corrected__jesUncEC2Up", "PG_internal_quantity_27__jesUncEC2Up", 20);
    auto df25 = physicsobject::CutPt(df24, "Jet_pt_corrected__jesUncBBEC1Up", "PG_internal_quantity_27__jesUncBBEC1Up", 20);
    auto df26 = physicsobject::CutPt(df25, "Jet_pt_corrected__jesUncAbsoluteYearUp", "PG_internal_quantity_27__jesUncAbsoluteYearUp", 20);
    auto df27 = physicsobject::CutPt(df26, "Jet_pt_corrected__jesUncHFYearUp", "PG_internal_quantity_27__jesUncHFYearUp", 20);
    auto df28 = physicsobject::CutPt(df27, "Jet_pt_corrected__jesUncHFYearDown", "PG_internal_quantity_27__jesUncHFYearDown", 20);
    auto df29 = physicsobject::CutPt(df28, "Jet_pt_corrected__jesUncBBEC1YearDown", "PG_internal_quantity_27__jesUncBBEC1YearDown", 20);
    auto df30 = physicsobject::CutEta(df29, "Jet_eta", "PG_internal_quantity_28", 2.5);
    auto df31 = physicsobject::jet::CutRawID(df30, "Jet_btagDeepFlavB", "PG_internal_quantity_29", 0.2783);
    auto df32 = physicsobject::CombineMasks(df31, "good_bjets_mask", "jet_id_mask", "jet_puid_mask", "PG_internal_quantity_27", "PG_internal_quantity_28", "PG_internal_quantity_29");
    auto df33 = physicsobject::CombineMasks(df32, "good_bjets_mask__jesUncFlavorQCDUp", "jet_id_mask", "jet_puid_mask__jesUncFlavorQCDUp", "PG_internal_quantity_27__jesUncFlavorQCDUp", "PG_internal_quantity_28", "PG_internal_quantity_29");
    auto df34 = physicsobject::CombineMasks(df33, "good_bjets_mask__jesUncHFDown", "jet_id_mask", "jet_puid_mask__jesUncHFDown", "PG_internal_quantity_27__jesUncHFDown", "PG_internal_quantity_28", "PG_internal_quantity_29");
    auto df35 = physicsobject::CombineMasks(df34, "good_bjets_mask__jesUncRelativeBalUp", "jet_id_mask", "jet_puid_mask__jesUncRelativeBalUp", "PG_internal_quantity_27__jesUncRelativeBalUp", "PG_internal_quantity_28", "PG_internal_quantity_29");
    auto df36 = physicsobject::CombineMasks(df35, "good_bjets_mask__jesUncTotalDown", "jet_id_mask", "jet_puid_mask__jesUncTotalDown", "PG_internal_quantity_27__jesUncTotalDown", "PG_internal_quantity_28", "PG_internal_quantity_29");
    auto df37 = physicsobject::CombineMasks(df36, "good_bjets_mask__jesUncRelativeSampleYearUp", "jet_id_mask", "jet_puid_mask__jesUncRelativeSampleYearUp", "PG_internal_quantity_27__jesUncRelativeSampleYearUp", "PG_internal_quantity_28", "PG_internal_quantity_29");
    auto df38 = physicsobject::CombineMasks(df37, "good_bjets_mask__jesUncAbsoluteDown", "jet_id_mask", "jet_puid_mask__jesUncAbsoluteDown", "PG_internal_quantity_27__jesUncAbsoluteDown", "PG_internal_quantity_28", "PG_internal_quantity_29");
    auto df39 = physicsobject::CombineMasks(df38, "good_bjets_mask__jerUncDown", "jet_id_mask", "jet_puid_mask__jerUncDown", "PG_internal_quantity_27__jerUncDown", "PG_internal_quantity_28", "PG_internal_quantity_29");
    auto df40 = physicsobject::CombineMasks(df39, "good_bjets_mask__jerUncUp", "jet_id_mask", "jet_puid_mask__jerUncUp", "PG_internal_quantity_27__jerUncUp", "PG_internal_quantity_28", "PG_internal_quantity_29");
    auto df41 = physicsobject::CombineMasks(df40, "good_bjets_mask__jesUncEC2YearDown", "jet_id_mask", "jet_puid_mask__jesUncEC2YearDown", "PG_internal_quantity_27__jesUncEC2YearDown", "PG_internal_quantity_28", "PG_internal_quantity_29");
    auto df42 = physicsobject::CombineMasks(df41, "good_bjets_mask__jesUncBBEC1Down", "jet_id_mask", "jet_puid_mask__jesUncBBEC1Down", "PG_internal_quantity_27__jesUncBBEC1Down", "PG_internal_quantity_28", "PG_internal_quantity_29");
    auto df43 = physicsobject::CombineMasks(df42, "good_bjets_mask__jesUncEC2Down", "jet_id_mask", "jet_puid_mask__jesUncEC2Down", "PG_internal_quantity_27__jesUncEC2Down", "PG_internal_quantity_28", "PG_internal_quantity_29");
    auto df44 = physicsobject::CombineMasks(df43, "good_bjets_mask__jesUncAbsoluteYearDown", "jet_id_mask", "jet_puid_mask__jesUncAbsoluteYearDown", "PG_internal_quantity_27__jesUncAbsoluteYearDown", "PG_internal_quantity_28", "PG_internal_quantity_29");
    auto df45 = physicsobject::CombineMasks(df44, "good_bjets_mask__jesUncRelativeBalDown", "jet_id_mask", "jet_puid_mask__jesUncRelativeBalDown", "PG_internal_quantity_27__jesUncRelativeBalDown", "PG_internal_quantity_28", "PG_internal_quantity_29");
    auto df46 = physicsobject::CombineMasks(df45, "good_bjets_mask__jesUncTotalUp", "jet_id_mask", "jet_puid_mask__jesUncTotalUp", "PG_internal_quantity_27__jesUncTotalUp", "PG_internal_quantity_28", "PG_internal_quantity_29");
    auto df47 = physicsobject::CombineMasks(df46, "good_bjets_mask__jesUncBBEC1YearUp", "jet_id_mask", "jet_puid_mask__jesUncBBEC1YearUp", "PG_internal_quantity_27__jesUncBBEC1YearUp", "PG_internal_quantity_28", "PG_internal_quantity_29");
    auto df48 = physicsobject::CombineMasks(df47, "good_bjets_mask__jesUncHEMIssueUp", "jet_id_mask", "jet_puid_mask__jesUncHEMIssueUp", "PG_internal_quantity_27__jesUncHEMIssueUp", "PG_internal_quantity_28", "PG_internal_quantity_29");
    auto df49 = physicsobject::CombineMasks(df48, "good_bjets_mask__jesUncRelativeSampleYearDown", "jet_id_mask", "jet_puid_mask__jesUncRelativeSampleYearDown", "PG_internal_quantity_27__jesUncRelativeSampleYearDown", "PG_internal_quantity_28", "PG_internal_quantity_29");
    auto df50 = physicsobject::CombineMasks(df49, "good_bjets_mask__jesUncHFUp", "jet_id_mask", "jet_puid_mask__jesUncHFUp", "PG_internal_quantity_27__jesUncHFUp", "PG_internal_quantity_28", "PG_internal_quantity_29");
    auto df51 = physicsobject::CombineMasks(df50, "good_bjets_mask__jesUncFlavorQCDDown", "jet_id_mask", "jet_puid_mask__jesUncFlavorQCDDown", "PG_internal_quantity_27__jesUncFlavorQCDDown", "PG_internal_quantity_28", "PG_internal_quantity_29");
    auto df52 = physicsobject::CombineMasks(df51, "good_bjets_mask__jesUncHEMIssueDown", "jet_id_mask", "jet_puid_mask__jesUncHEMIssueDown", "PG_internal_quantity_27__jesUncHEMIssueDown", "PG_internal_quantity_28", "PG_internal_quantity_29");
    auto df53 = physicsobject::CombineMasks(df52, "good_bjets_mask__jesUncAbsoluteUp", "jet_id_mask", "jet_puid_mask__jesUncAbsoluteUp", "PG_internal_quantity_27__jesUncAbsoluteUp", "PG_internal_quantity_28", "PG_internal_quantity_29");
    auto df54 = physicsobject::CombineMasks(df53, "good_bjets_mask__jesUncEC2YearUp", "jet_id_mask", "jet_puid_mask__jesUncEC2YearUp", "PG_internal_quantity_27__jesUncEC2YearUp", "PG_internal_quantity_28", "PG_internal_quantity_29");
    auto df55 = physicsobject::CombineMasks(df54, "good_bjets_mask__jesUncEC2Up", "jet_id_mask", "jet_puid_mask__jesUncEC2Up", "PG_internal_quantity_27__jesUncEC2Up", "PG_internal_quantity_28", "PG_internal_quantity_29");
    auto df56 = physicsobject::CombineMasks(df55, "good_bjets_mask__jesUncBBEC1Up", "jet_id_mask", "jet_puid_mask__jesUncBBEC1Up", "PG_internal_quantity_27__jesUncBBEC1Up", "PG_internal_quantity_28", "PG_internal_quantity_29");
    auto df57 = physicsobject::CombineMasks(df56, "good_bjets_mask__jesUncAbsoluteYearUp", "jet_id_mask", "jet_puid_mask__jesUncAbsoluteYearUp", "PG_internal_quantity_27__jesUncAbsoluteYearUp", "PG_internal_quantity_28", "PG_internal_quantity_29");
    auto df58 = physicsobject::CombineMasks(df57, "good_bjets_mask__jesUncHFYearUp", "jet_id_mask", "jet_puid_mask__jesUncHFYearUp", "PG_internal_quantity_27__jesUncHFYearUp", "PG_internal_quantity_28", "PG_internal_quantity_29");
    auto df59 = physicsobject::CombineMasks(df58, "good_bjets_mask__jesUncHFYearDown", "jet_id_mask", "jet_puid_mask__jesUncHFYearDown", "PG_internal_quantity_27__jesUncHFYearDown", "PG_internal_quantity_28", "PG_internal_quantity_29");
    auto df60 = physicsobject::CombineMasks(df59, "good_bjets_mask__jesUncBBEC1YearDown", "jet_id_mask", "jet_puid_mask__jesUncBBEC1YearDown", "PG_internal_quantity_27__jesUncBBEC1YearDown", "PG_internal_quantity_28", "PG_internal_quantity_29");
    return df60;

}
