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
ROOT::RDF::RNode BJetCollection_ee (ROOT::RDF::RNode df0, OnnxSessionManager &onnxSessionManager, CorrectionManager &correctionManager) {

        auto df1 = physicsobject::CombineMasks(df0, "PG_internal_quantity_31", "good_bjets_mask", "jet_overlap_veto_mask");
    auto df2 = physicsobject::CombineMasks(df1, "PG_internal_quantity_31__jesUncFlavorQCDUp", "good_bjets_mask__jesUncFlavorQCDUp", "jet_overlap_veto_mask");
    auto df3 = physicsobject::CombineMasks(df2, "PG_internal_quantity_31__jesUncHFDown", "good_bjets_mask__jesUncHFDown", "jet_overlap_veto_mask");
    auto df4 = physicsobject::CombineMasks(df3, "PG_internal_quantity_31__jesUncRelativeBalUp", "good_bjets_mask__jesUncRelativeBalUp", "jet_overlap_veto_mask");
    auto df5 = physicsobject::CombineMasks(df4, "PG_internal_quantity_31__jesUncTotalDown", "good_bjets_mask__jesUncTotalDown", "jet_overlap_veto_mask");
    auto df6 = physicsobject::CombineMasks(df5, "PG_internal_quantity_31__jesUncRelativeSampleYearUp", "good_bjets_mask__jesUncRelativeSampleYearUp", "jet_overlap_veto_mask");
    auto df7 = physicsobject::CombineMasks(df6, "PG_internal_quantity_31__jesUncAbsoluteDown", "good_bjets_mask__jesUncAbsoluteDown", "jet_overlap_veto_mask");
    auto df8 = physicsobject::CombineMasks(df7, "PG_internal_quantity_31__jerUncDown", "good_bjets_mask__jerUncDown", "jet_overlap_veto_mask");
    auto df9 = physicsobject::CombineMasks(df8, "PG_internal_quantity_31__jerUncUp", "good_bjets_mask__jerUncUp", "jet_overlap_veto_mask");
    auto df10 = physicsobject::CombineMasks(df9, "PG_internal_quantity_31__eleEsResoDown", "good_bjets_mask", "jet_overlap_veto_mask__eleEsResoDown");
    auto df11 = physicsobject::CombineMasks(df10, "PG_internal_quantity_31__jesUncEC2YearDown", "good_bjets_mask__jesUncEC2YearDown", "jet_overlap_veto_mask");
    auto df12 = physicsobject::CombineMasks(df11, "PG_internal_quantity_31__jesUncBBEC1Down", "good_bjets_mask__jesUncBBEC1Down", "jet_overlap_veto_mask");
    auto df13 = physicsobject::CombineMasks(df12, "PG_internal_quantity_31__eleEsResoUp", "good_bjets_mask", "jet_overlap_veto_mask__eleEsResoUp");
    auto df14 = physicsobject::CombineMasks(df13, "PG_internal_quantity_31__jesUncEC2Down", "good_bjets_mask__jesUncEC2Down", "jet_overlap_veto_mask");
    auto df15 = physicsobject::CombineMasks(df14, "PG_internal_quantity_31__jesUncAbsoluteYearDown", "good_bjets_mask__jesUncAbsoluteYearDown", "jet_overlap_veto_mask");
    auto df16 = physicsobject::CombineMasks(df15, "PG_internal_quantity_31__jesUncRelativeBalDown", "good_bjets_mask__jesUncRelativeBalDown", "jet_overlap_veto_mask");
    auto df17 = physicsobject::CombineMasks(df16, "PG_internal_quantity_31__jesUncTotalUp", "good_bjets_mask__jesUncTotalUp", "jet_overlap_veto_mask");
    auto df18 = physicsobject::CombineMasks(df17, "PG_internal_quantity_31__eleEsScaleUp", "good_bjets_mask", "jet_overlap_veto_mask__eleEsScaleUp");
    auto df19 = physicsobject::CombineMasks(df18, "PG_internal_quantity_31__jesUncBBEC1YearUp", "good_bjets_mask__jesUncBBEC1YearUp", "jet_overlap_veto_mask");
    auto df20 = physicsobject::CombineMasks(df19, "PG_internal_quantity_31__jesUncHEMIssueUp", "good_bjets_mask__jesUncHEMIssueUp", "jet_overlap_veto_mask");
    auto df21 = physicsobject::CombineMasks(df20, "PG_internal_quantity_31__jesUncRelativeSampleYearDown", "good_bjets_mask__jesUncRelativeSampleYearDown", "jet_overlap_veto_mask");
    auto df22 = physicsobject::CombineMasks(df21, "PG_internal_quantity_31__jesUncHFUp", "good_bjets_mask__jesUncHFUp", "jet_overlap_veto_mask");
    auto df23 = physicsobject::CombineMasks(df22, "PG_internal_quantity_31__jesUncFlavorQCDDown", "good_bjets_mask__jesUncFlavorQCDDown", "jet_overlap_veto_mask");
    auto df24 = physicsobject::CombineMasks(df23, "PG_internal_quantity_31__jesUncHEMIssueDown", "good_bjets_mask__jesUncHEMIssueDown", "jet_overlap_veto_mask");
    auto df25 = physicsobject::CombineMasks(df24, "PG_internal_quantity_31__jesUncAbsoluteUp", "good_bjets_mask__jesUncAbsoluteUp", "jet_overlap_veto_mask");
    auto df26 = physicsobject::CombineMasks(df25, "PG_internal_quantity_31__jesUncEC2YearUp", "good_bjets_mask__jesUncEC2YearUp", "jet_overlap_veto_mask");
    auto df27 = physicsobject::CombineMasks(df26, "PG_internal_quantity_31__eleEsScaleDown", "good_bjets_mask", "jet_overlap_veto_mask__eleEsScaleDown");
    auto df28 = physicsobject::CombineMasks(df27, "PG_internal_quantity_31__jesUncEC2Up", "good_bjets_mask__jesUncEC2Up", "jet_overlap_veto_mask");
    auto df29 = physicsobject::CombineMasks(df28, "PG_internal_quantity_31__jesUncBBEC1Up", "good_bjets_mask__jesUncBBEC1Up", "jet_overlap_veto_mask");
    auto df30 = physicsobject::CombineMasks(df29, "PG_internal_quantity_31__jesUncAbsoluteYearUp", "good_bjets_mask__jesUncAbsoluteYearUp", "jet_overlap_veto_mask");
    auto df31 = physicsobject::CombineMasks(df30, "PG_internal_quantity_31__jesUncHFYearUp", "good_bjets_mask__jesUncHFYearUp", "jet_overlap_veto_mask");
    auto df32 = physicsobject::CombineMasks(df31, "PG_internal_quantity_31__jesUncHFYearDown", "good_bjets_mask__jesUncHFYearDown", "jet_overlap_veto_mask");
    auto df33 = physicsobject::CombineMasks(df32, "PG_internal_quantity_31__jesUncBBEC1YearDown", "good_bjets_mask__jesUncBBEC1YearDown", "jet_overlap_veto_mask");
    auto df34 = jet::OrderJetsByPt(df33, "good_bjet_collection", "Jet_pt_corrected", "PG_internal_quantity_31");
    auto df35 = jet::OrderJetsByPt(df34, "good_bjet_collection__jesUncFlavorQCDUp", "Jet_pt_corrected__jesUncFlavorQCDUp", "PG_internal_quantity_31__jesUncFlavorQCDUp");
    auto df36 = jet::OrderJetsByPt(df35, "good_bjet_collection__jesUncHFDown", "Jet_pt_corrected__jesUncHFDown", "PG_internal_quantity_31__jesUncHFDown");
    auto df37 = jet::OrderJetsByPt(df36, "good_bjet_collection__jesUncRelativeBalUp", "Jet_pt_corrected__jesUncRelativeBalUp", "PG_internal_quantity_31__jesUncRelativeBalUp");
    auto df38 = jet::OrderJetsByPt(df37, "good_bjet_collection__jesUncTotalDown", "Jet_pt_corrected__jesUncTotalDown", "PG_internal_quantity_31__jesUncTotalDown");
    auto df39 = jet::OrderJetsByPt(df38, "good_bjet_collection__jesUncRelativeSampleYearUp", "Jet_pt_corrected__jesUncRelativeSampleYearUp", "PG_internal_quantity_31__jesUncRelativeSampleYearUp");
    auto df40 = jet::OrderJetsByPt(df39, "good_bjet_collection__jesUncAbsoluteDown", "Jet_pt_corrected__jesUncAbsoluteDown", "PG_internal_quantity_31__jesUncAbsoluteDown");
    auto df41 = jet::OrderJetsByPt(df40, "good_bjet_collection__jerUncDown", "Jet_pt_corrected__jerUncDown", "PG_internal_quantity_31__jerUncDown");
    auto df42 = jet::OrderJetsByPt(df41, "good_bjet_collection__jerUncUp", "Jet_pt_corrected__jerUncUp", "PG_internal_quantity_31__jerUncUp");
    auto df43 = jet::OrderJetsByPt(df42, "good_bjet_collection__eleEsResoDown", "Jet_pt_corrected", "PG_internal_quantity_31__eleEsResoDown");
    auto df44 = jet::OrderJetsByPt(df43, "good_bjet_collection__jesUncEC2YearDown", "Jet_pt_corrected__jesUncEC2YearDown", "PG_internal_quantity_31__jesUncEC2YearDown");
    auto df45 = jet::OrderJetsByPt(df44, "good_bjet_collection__jesUncBBEC1Down", "Jet_pt_corrected__jesUncBBEC1Down", "PG_internal_quantity_31__jesUncBBEC1Down");
    auto df46 = jet::OrderJetsByPt(df45, "good_bjet_collection__eleEsResoUp", "Jet_pt_corrected", "PG_internal_quantity_31__eleEsResoUp");
    auto df47 = jet::OrderJetsByPt(df46, "good_bjet_collection__jesUncEC2Down", "Jet_pt_corrected__jesUncEC2Down", "PG_internal_quantity_31__jesUncEC2Down");
    auto df48 = jet::OrderJetsByPt(df47, "good_bjet_collection__jesUncAbsoluteYearDown", "Jet_pt_corrected__jesUncAbsoluteYearDown", "PG_internal_quantity_31__jesUncAbsoluteYearDown");
    auto df49 = jet::OrderJetsByPt(df48, "good_bjet_collection__jesUncRelativeBalDown", "Jet_pt_corrected__jesUncRelativeBalDown", "PG_internal_quantity_31__jesUncRelativeBalDown");
    auto df50 = jet::OrderJetsByPt(df49, "good_bjet_collection__jesUncTotalUp", "Jet_pt_corrected__jesUncTotalUp", "PG_internal_quantity_31__jesUncTotalUp");
    auto df51 = jet::OrderJetsByPt(df50, "good_bjet_collection__eleEsScaleUp", "Jet_pt_corrected", "PG_internal_quantity_31__eleEsScaleUp");
    auto df52 = jet::OrderJetsByPt(df51, "good_bjet_collection__jesUncBBEC1YearUp", "Jet_pt_corrected__jesUncBBEC1YearUp", "PG_internal_quantity_31__jesUncBBEC1YearUp");
    auto df53 = jet::OrderJetsByPt(df52, "good_bjet_collection__jesUncHEMIssueUp", "Jet_pt_corrected__jesUncHEMIssueUp", "PG_internal_quantity_31__jesUncHEMIssueUp");
    auto df54 = jet::OrderJetsByPt(df53, "good_bjet_collection__jesUncRelativeSampleYearDown", "Jet_pt_corrected__jesUncRelativeSampleYearDown", "PG_internal_quantity_31__jesUncRelativeSampleYearDown");
    auto df55 = jet::OrderJetsByPt(df54, "good_bjet_collection__jesUncHFUp", "Jet_pt_corrected__jesUncHFUp", "PG_internal_quantity_31__jesUncHFUp");
    auto df56 = jet::OrderJetsByPt(df55, "good_bjet_collection__jesUncFlavorQCDDown", "Jet_pt_corrected__jesUncFlavorQCDDown", "PG_internal_quantity_31__jesUncFlavorQCDDown");
    auto df57 = jet::OrderJetsByPt(df56, "good_bjet_collection__jesUncHEMIssueDown", "Jet_pt_corrected__jesUncHEMIssueDown", "PG_internal_quantity_31__jesUncHEMIssueDown");
    auto df58 = jet::OrderJetsByPt(df57, "good_bjet_collection__jesUncAbsoluteUp", "Jet_pt_corrected__jesUncAbsoluteUp", "PG_internal_quantity_31__jesUncAbsoluteUp");
    auto df59 = jet::OrderJetsByPt(df58, "good_bjet_collection__jesUncEC2YearUp", "Jet_pt_corrected__jesUncEC2YearUp", "PG_internal_quantity_31__jesUncEC2YearUp");
    auto df60 = jet::OrderJetsByPt(df59, "good_bjet_collection__eleEsScaleDown", "Jet_pt_corrected", "PG_internal_quantity_31__eleEsScaleDown");
    auto df61 = jet::OrderJetsByPt(df60, "good_bjet_collection__jesUncEC2Up", "Jet_pt_corrected__jesUncEC2Up", "PG_internal_quantity_31__jesUncEC2Up");
    auto df62 = jet::OrderJetsByPt(df61, "good_bjet_collection__jesUncBBEC1Up", "Jet_pt_corrected__jesUncBBEC1Up", "PG_internal_quantity_31__jesUncBBEC1Up");
    auto df63 = jet::OrderJetsByPt(df62, "good_bjet_collection__jesUncAbsoluteYearUp", "Jet_pt_corrected__jesUncAbsoluteYearUp", "PG_internal_quantity_31__jesUncAbsoluteYearUp");
    auto df64 = jet::OrderJetsByPt(df63, "good_bjet_collection__jesUncHFYearUp", "Jet_pt_corrected__jesUncHFYearUp", "PG_internal_quantity_31__jesUncHFYearUp");
    auto df65 = jet::OrderJetsByPt(df64, "good_bjet_collection__jesUncHFYearDown", "Jet_pt_corrected__jesUncHFYearDown", "PG_internal_quantity_31__jesUncHFYearDown");
    auto df66 = jet::OrderJetsByPt(df65, "good_bjet_collection__jesUncBBEC1YearDown", "Jet_pt_corrected__jesUncBBEC1YearDown", "PG_internal_quantity_31__jesUncBBEC1YearDown");
    return df66;

}
