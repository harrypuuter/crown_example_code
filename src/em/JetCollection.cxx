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
ROOT::RDF::RNode JetCollection_em (ROOT::RDF::RNode df0, OnnxSessionManager &onnxSessionManager, CorrectionManager &correctionManager) {

        auto df1 = jet::VetoOverlappingJets(df0, "jet_overlap_veto_mask", "Jet_eta", "Jet_phi", "p4_1", "p4_2", 0.5);
    auto df2 = jet::VetoOverlappingJets(df1, "jet_overlap_veto_mask__eleEsResoDown", "Jet_eta", "Jet_phi", "p4_1__eleEsResoDown", "p4_2__eleEsResoDown", 0.5);
    auto df3 = jet::VetoOverlappingJets(df2, "jet_overlap_veto_mask__eleEsScaleUp", "Jet_eta", "Jet_phi", "p4_1__eleEsScaleUp", "p4_2__eleEsScaleUp", 0.5);
    auto df4 = jet::VetoOverlappingJets(df3, "jet_overlap_veto_mask__eleEsResoUp", "Jet_eta", "Jet_phi", "p4_1__eleEsResoUp", "p4_2__eleEsResoUp", 0.5);
    auto df5 = jet::VetoOverlappingJets(df4, "jet_overlap_veto_mask__eleEsScaleDown", "Jet_eta", "Jet_phi", "p4_1__eleEsScaleDown", "p4_2__eleEsScaleDown", 0.5);
    auto df6 = physicsobject::CombineMasks(df5, "PG_internal_quantity_30", "good_jets_mask", "jet_overlap_veto_mask");
    auto df7 = physicsobject::CombineMasks(df6, "PG_internal_quantity_30__jesUncFlavorQCDUp", "good_jets_mask__jesUncFlavorQCDUp", "jet_overlap_veto_mask");
    auto df8 = physicsobject::CombineMasks(df7, "PG_internal_quantity_30__jesUncHFDown", "good_jets_mask__jesUncHFDown", "jet_overlap_veto_mask");
    auto df9 = physicsobject::CombineMasks(df8, "PG_internal_quantity_30__jesUncRelativeBalUp", "good_jets_mask__jesUncRelativeBalUp", "jet_overlap_veto_mask");
    auto df10 = physicsobject::CombineMasks(df9, "PG_internal_quantity_30__jesUncTotalDown", "good_jets_mask__jesUncTotalDown", "jet_overlap_veto_mask");
    auto df11 = physicsobject::CombineMasks(df10, "PG_internal_quantity_30__jesUncRelativeSampleYearUp", "good_jets_mask__jesUncRelativeSampleYearUp", "jet_overlap_veto_mask");
    auto df12 = physicsobject::CombineMasks(df11, "PG_internal_quantity_30__jesUncAbsoluteDown", "good_jets_mask__jesUncAbsoluteDown", "jet_overlap_veto_mask");
    auto df13 = physicsobject::CombineMasks(df12, "PG_internal_quantity_30__jerUncDown", "good_jets_mask__jerUncDown", "jet_overlap_veto_mask");
    auto df14 = physicsobject::CombineMasks(df13, "PG_internal_quantity_30__jerUncUp", "good_jets_mask__jerUncUp", "jet_overlap_veto_mask");
    auto df15 = physicsobject::CombineMasks(df14, "PG_internal_quantity_30__eleEsResoDown", "good_jets_mask", "jet_overlap_veto_mask__eleEsResoDown");
    auto df16 = physicsobject::CombineMasks(df15, "PG_internal_quantity_30__jesUncEC2YearDown", "good_jets_mask__jesUncEC2YearDown", "jet_overlap_veto_mask");
    auto df17 = physicsobject::CombineMasks(df16, "PG_internal_quantity_30__jesUncBBEC1Down", "good_jets_mask__jesUncBBEC1Down", "jet_overlap_veto_mask");
    auto df18 = physicsobject::CombineMasks(df17, "PG_internal_quantity_30__eleEsResoUp", "good_jets_mask", "jet_overlap_veto_mask__eleEsResoUp");
    auto df19 = physicsobject::CombineMasks(df18, "PG_internal_quantity_30__jesUncEC2Down", "good_jets_mask__jesUncEC2Down", "jet_overlap_veto_mask");
    auto df20 = physicsobject::CombineMasks(df19, "PG_internal_quantity_30__jesUncAbsoluteYearDown", "good_jets_mask__jesUncAbsoluteYearDown", "jet_overlap_veto_mask");
    auto df21 = physicsobject::CombineMasks(df20, "PG_internal_quantity_30__jesUncRelativeBalDown", "good_jets_mask__jesUncRelativeBalDown", "jet_overlap_veto_mask");
    auto df22 = physicsobject::CombineMasks(df21, "PG_internal_quantity_30__jesUncTotalUp", "good_jets_mask__jesUncTotalUp", "jet_overlap_veto_mask");
    auto df23 = physicsobject::CombineMasks(df22, "PG_internal_quantity_30__eleEsScaleUp", "good_jets_mask", "jet_overlap_veto_mask__eleEsScaleUp");
    auto df24 = physicsobject::CombineMasks(df23, "PG_internal_quantity_30__jesUncBBEC1YearUp", "good_jets_mask__jesUncBBEC1YearUp", "jet_overlap_veto_mask");
    auto df25 = physicsobject::CombineMasks(df24, "PG_internal_quantity_30__jesUncHEMIssueUp", "good_jets_mask__jesUncHEMIssueUp", "jet_overlap_veto_mask");
    auto df26 = physicsobject::CombineMasks(df25, "PG_internal_quantity_30__jesUncRelativeSampleYearDown", "good_jets_mask__jesUncRelativeSampleYearDown", "jet_overlap_veto_mask");
    auto df27 = physicsobject::CombineMasks(df26, "PG_internal_quantity_30__jesUncHFUp", "good_jets_mask__jesUncHFUp", "jet_overlap_veto_mask");
    auto df28 = physicsobject::CombineMasks(df27, "PG_internal_quantity_30__jesUncFlavorQCDDown", "good_jets_mask__jesUncFlavorQCDDown", "jet_overlap_veto_mask");
    auto df29 = physicsobject::CombineMasks(df28, "PG_internal_quantity_30__jesUncHEMIssueDown", "good_jets_mask__jesUncHEMIssueDown", "jet_overlap_veto_mask");
    auto df30 = physicsobject::CombineMasks(df29, "PG_internal_quantity_30__jesUncAbsoluteUp", "good_jets_mask__jesUncAbsoluteUp", "jet_overlap_veto_mask");
    auto df31 = physicsobject::CombineMasks(df30, "PG_internal_quantity_30__jesUncEC2YearUp", "good_jets_mask__jesUncEC2YearUp", "jet_overlap_veto_mask");
    auto df32 = physicsobject::CombineMasks(df31, "PG_internal_quantity_30__eleEsScaleDown", "good_jets_mask", "jet_overlap_veto_mask__eleEsScaleDown");
    auto df33 = physicsobject::CombineMasks(df32, "PG_internal_quantity_30__jesUncEC2Up", "good_jets_mask__jesUncEC2Up", "jet_overlap_veto_mask");
    auto df34 = physicsobject::CombineMasks(df33, "PG_internal_quantity_30__jesUncBBEC1Up", "good_jets_mask__jesUncBBEC1Up", "jet_overlap_veto_mask");
    auto df35 = physicsobject::CombineMasks(df34, "PG_internal_quantity_30__jesUncAbsoluteYearUp", "good_jets_mask__jesUncAbsoluteYearUp", "jet_overlap_veto_mask");
    auto df36 = physicsobject::CombineMasks(df35, "PG_internal_quantity_30__jesUncHFYearUp", "good_jets_mask__jesUncHFYearUp", "jet_overlap_veto_mask");
    auto df37 = physicsobject::CombineMasks(df36, "PG_internal_quantity_30__jesUncHFYearDown", "good_jets_mask__jesUncHFYearDown", "jet_overlap_veto_mask");
    auto df38 = physicsobject::CombineMasks(df37, "PG_internal_quantity_30__jesUncBBEC1YearDown", "good_jets_mask__jesUncBBEC1YearDown", "jet_overlap_veto_mask");
    auto df39 = jet::OrderJetsByPt(df38, "good_jet_collection", "Jet_pt_corrected", "PG_internal_quantity_30");
    auto df40 = jet::OrderJetsByPt(df39, "good_jet_collection__jesUncFlavorQCDUp", "Jet_pt_corrected__jesUncFlavorQCDUp", "PG_internal_quantity_30__jesUncFlavorQCDUp");
    auto df41 = jet::OrderJetsByPt(df40, "good_jet_collection__jesUncHFDown", "Jet_pt_corrected__jesUncHFDown", "PG_internal_quantity_30__jesUncHFDown");
    auto df42 = jet::OrderJetsByPt(df41, "good_jet_collection__jesUncRelativeBalUp", "Jet_pt_corrected__jesUncRelativeBalUp", "PG_internal_quantity_30__jesUncRelativeBalUp");
    auto df43 = jet::OrderJetsByPt(df42, "good_jet_collection__jesUncTotalDown", "Jet_pt_corrected__jesUncTotalDown", "PG_internal_quantity_30__jesUncTotalDown");
    auto df44 = jet::OrderJetsByPt(df43, "good_jet_collection__jesUncRelativeSampleYearUp", "Jet_pt_corrected__jesUncRelativeSampleYearUp", "PG_internal_quantity_30__jesUncRelativeSampleYearUp");
    auto df45 = jet::OrderJetsByPt(df44, "good_jet_collection__jesUncAbsoluteDown", "Jet_pt_corrected__jesUncAbsoluteDown", "PG_internal_quantity_30__jesUncAbsoluteDown");
    auto df46 = jet::OrderJetsByPt(df45, "good_jet_collection__jerUncDown", "Jet_pt_corrected__jerUncDown", "PG_internal_quantity_30__jerUncDown");
    auto df47 = jet::OrderJetsByPt(df46, "good_jet_collection__jerUncUp", "Jet_pt_corrected__jerUncUp", "PG_internal_quantity_30__jerUncUp");
    auto df48 = jet::OrderJetsByPt(df47, "good_jet_collection__eleEsResoDown", "Jet_pt_corrected", "PG_internal_quantity_30__eleEsResoDown");
    auto df49 = jet::OrderJetsByPt(df48, "good_jet_collection__jesUncEC2YearDown", "Jet_pt_corrected__jesUncEC2YearDown", "PG_internal_quantity_30__jesUncEC2YearDown");
    auto df50 = jet::OrderJetsByPt(df49, "good_jet_collection__jesUncBBEC1Down", "Jet_pt_corrected__jesUncBBEC1Down", "PG_internal_quantity_30__jesUncBBEC1Down");
    auto df51 = jet::OrderJetsByPt(df50, "good_jet_collection__eleEsResoUp", "Jet_pt_corrected", "PG_internal_quantity_30__eleEsResoUp");
    auto df52 = jet::OrderJetsByPt(df51, "good_jet_collection__jesUncEC2Down", "Jet_pt_corrected__jesUncEC2Down", "PG_internal_quantity_30__jesUncEC2Down");
    auto df53 = jet::OrderJetsByPt(df52, "good_jet_collection__jesUncAbsoluteYearDown", "Jet_pt_corrected__jesUncAbsoluteYearDown", "PG_internal_quantity_30__jesUncAbsoluteYearDown");
    auto df54 = jet::OrderJetsByPt(df53, "good_jet_collection__jesUncRelativeBalDown", "Jet_pt_corrected__jesUncRelativeBalDown", "PG_internal_quantity_30__jesUncRelativeBalDown");
    auto df55 = jet::OrderJetsByPt(df54, "good_jet_collection__jesUncTotalUp", "Jet_pt_corrected__jesUncTotalUp", "PG_internal_quantity_30__jesUncTotalUp");
    auto df56 = jet::OrderJetsByPt(df55, "good_jet_collection__eleEsScaleUp", "Jet_pt_corrected", "PG_internal_quantity_30__eleEsScaleUp");
    auto df57 = jet::OrderJetsByPt(df56, "good_jet_collection__jesUncBBEC1YearUp", "Jet_pt_corrected__jesUncBBEC1YearUp", "PG_internal_quantity_30__jesUncBBEC1YearUp");
    auto df58 = jet::OrderJetsByPt(df57, "good_jet_collection__jesUncHEMIssueUp", "Jet_pt_corrected__jesUncHEMIssueUp", "PG_internal_quantity_30__jesUncHEMIssueUp");
    auto df59 = jet::OrderJetsByPt(df58, "good_jet_collection__jesUncRelativeSampleYearDown", "Jet_pt_corrected__jesUncRelativeSampleYearDown", "PG_internal_quantity_30__jesUncRelativeSampleYearDown");
    auto df60 = jet::OrderJetsByPt(df59, "good_jet_collection__jesUncHFUp", "Jet_pt_corrected__jesUncHFUp", "PG_internal_quantity_30__jesUncHFUp");
    auto df61 = jet::OrderJetsByPt(df60, "good_jet_collection__jesUncFlavorQCDDown", "Jet_pt_corrected__jesUncFlavorQCDDown", "PG_internal_quantity_30__jesUncFlavorQCDDown");
    auto df62 = jet::OrderJetsByPt(df61, "good_jet_collection__jesUncHEMIssueDown", "Jet_pt_corrected__jesUncHEMIssueDown", "PG_internal_quantity_30__jesUncHEMIssueDown");
    auto df63 = jet::OrderJetsByPt(df62, "good_jet_collection__jesUncAbsoluteUp", "Jet_pt_corrected__jesUncAbsoluteUp", "PG_internal_quantity_30__jesUncAbsoluteUp");
    auto df64 = jet::OrderJetsByPt(df63, "good_jet_collection__jesUncEC2YearUp", "Jet_pt_corrected__jesUncEC2YearUp", "PG_internal_quantity_30__jesUncEC2YearUp");
    auto df65 = jet::OrderJetsByPt(df64, "good_jet_collection__eleEsScaleDown", "Jet_pt_corrected", "PG_internal_quantity_30__eleEsScaleDown");
    auto df66 = jet::OrderJetsByPt(df65, "good_jet_collection__jesUncEC2Up", "Jet_pt_corrected__jesUncEC2Up", "PG_internal_quantity_30__jesUncEC2Up");
    auto df67 = jet::OrderJetsByPt(df66, "good_jet_collection__jesUncBBEC1Up", "Jet_pt_corrected__jesUncBBEC1Up", "PG_internal_quantity_30__jesUncBBEC1Up");
    auto df68 = jet::OrderJetsByPt(df67, "good_jet_collection__jesUncAbsoluteYearUp", "Jet_pt_corrected__jesUncAbsoluteYearUp", "PG_internal_quantity_30__jesUncAbsoluteYearUp");
    auto df69 = jet::OrderJetsByPt(df68, "good_jet_collection__jesUncHFYearUp", "Jet_pt_corrected__jesUncHFYearUp", "PG_internal_quantity_30__jesUncHFYearUp");
    auto df70 = jet::OrderJetsByPt(df69, "good_jet_collection__jesUncHFYearDown", "Jet_pt_corrected__jesUncHFYearDown", "PG_internal_quantity_30__jesUncHFYearDown");
    auto df71 = jet::OrderJetsByPt(df70, "good_jet_collection__jesUncBBEC1YearDown", "Jet_pt_corrected__jesUncBBEC1YearDown", "PG_internal_quantity_30__jesUncBBEC1YearDown");
    return df71;

}
